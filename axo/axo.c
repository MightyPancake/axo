#include "axo/axo.h"
char* fmtstr(const char fmt[], ...){
    char* ret;
    va_list args;
    va_start(args, fmt);
    vasprintf(&ret, fmt, args);
    va_end(args);
    return ret;
}

char* axo_file_to_str(char* path){
    char* str;
    long len;
    FILE* file = fopen (path, "rb");
    if (file){
        fseek (file, 0, SEEK_END);
        len = ftell (file);
        fseek (file, 0, SEEK_SET);
        str = (char*)malloc((len+1)*sizeof(char));
        if (str){
            fread(str, sizeof(char), len, file);
        }
        fclose(file);
    }
    str[len] = '\0';
    if (!(str && file)) return (char*)NULL;
    return str;
}

axo_state* axo_new_state(){
    new_ptr_one(st, axo_state);
    st->filepath = "";
    st->global_scope = axo_new_scope(NULL);
    st->types_def = new_map(axo_typ_def, map_hash_typ_def, map_cmp_typ_def);
    st->decls=NULL;
    st->decls_len=0;
    st->config = (axo_compiler_config){
        .cc = axo_gcc_cc_kind,
        .output_name=NULL,
        .measure_time=false,
        .bug_hunter=false
    };
    st->int_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="int", .typ=(axo_typ){.kind=axo_simple_kind, .simple="int", .def="0"}});
    axo_set_typ_def(NULL, st, (axo_typ_def){.name="bool", .typ=(axo_typ){.kind=axo_simple_kind, .simple="bool", .def="0"}});
    axo_set_typ_def(NULL, st, (axo_typ_def){.name="float", .typ=(axo_typ){.kind=axo_simple_kind, .simple="float", .def="0.0"}});
    axo_set_typ_def(NULL, st, (axo_typ_def){.name="char", .typ=(axo_typ){.kind=axo_simple_kind, .simple="char", .def="'\0'"}});
    return st;
}

axo_typ_def* axo_set_typ_def(YYLTYPE* loc, axo_state* st, axo_typ_def td){
    if (hashmap_get(st->types_def, &td) == NULL){
        new_ptr_one(ptr, axo_typ_def);
        *ptr = td;
        hashmap_set(st->types_def, ptr);
        return ptr;
    }else
        yyerror(loc, "'%s' already defined as '%s'", "typ1", "typ2"); //FIX!!!
    return NULL;
}

axo_typ_def* axo_get_typ_def(axo_state* st, char* name){
    axo_typ_def placeholder = (axo_typ_def){.name=name};
    return hashmap_get(st->types_def, &placeholder);
}

axo_scope* axo_new_scope(axo_scope* parent){
    new_ptr_one(sc, axo_scope);
    sc->parent = parent;
    sc->variables = new_map(axo_var, map_hash_vars, map_cmp_vars);
    sc->ret_typ = axo_no_typ;
    sc->def_iter = (parent==NULL ? 0 : parent->def_iter);
    return sc;
}

const char* axo_identifier_kind_to_str(axo_identifier_kind kind){
    switch(kind){
        case axo_identifier_var_kind: return "variable"; break;
        case axo_identifier_module_kind: return "module"; break;
        case axo_identifier_typ_kind: return "type"; break;
        default: return "unknown"; break;
    }
}

void axo_add_decl(axo_state* st, axo_decl d){
    if (st->decls_len % axo_decls_cap == 0)
        st->decls = (axo_decl*)realloc(st->decls, (st->decls_len+axo_decls_cap)*sizeof(axo_decl));
    st->decls[st->decls_len] = d;
    st->decls_len++;
}

void axo_add_statement(axo_scope* sc, axo_statement s){
    if (sc->statements_len % axo_statements_cap == 0)
        sc->statements = (axo_statement*)realloc(sc->statements, (sc->statements_len+axo_statements_cap)*sizeof(axo_statement));
    sc->statements[sc->statements_len] = s;
    sc->statements_len++;
}

void axo_set_var(axo_scope* sc, axo_var var){
    new_ptr_one(ptr, axo_var);
    *ptr = var;
    hashmap_set(sc->variables, ptr);
}

axo_var* axo_get_var(axo_scope* sc, char* name){
    if (sc==NULL || sc->variables==NULL) return NULL;
    axo_var placeholder = (axo_var){.name = name};
    axo_var* var = (axo_var*)(hashmap_get(sc->variables, &placeholder));
    if (var) return var;
    return axo_get_var(sc->parent, name);
}

axo_var* axo_del_var(axo_scope* sc, char* name){
    return (axo_var*)hashmap_delete(sc->variables, &((axo_var){.name=name}));
}

void axo_set_func(axo_state* st, axo_func fn){
    //FIX: Add error of re-declaration!
    //FIX: Function should just be a variable
    new_ptr_one(fnt, axo_func_typ);
    *fnt = fn.f_typ;
    axo_var var = (axo_var){
        .name=fn.name,
        .typ=(axo_typ){
            .kind=axo_func_kind,
            .func_typ=fnt,
            .def=alloc_str("FUNC_DEFAULT")
        },
        .is_const=true
    };
    new_ptr_one(ptr, axo_var);
    *ptr = var;
    hashmap_set(st->global_scope->variables, ptr);
}

axo_statement axo_scope_to_statement(axo_scope* sc){
    axo_statement ret = (axo_statement){.kind=axo_scope_statement_kind};
    ret.val = alloc_str("{");
    for (int i = 0; i<sc->statements_len; i++){
        asprintf(&(ret.val), "%s\n%s", ret.val, sc->statements[i].val);
    }
    strapnd(&(ret.val), "\n}");
    return ret;
}

char* axo_func_to_typ_str(axo_func* fn){
    //Fix this! Later on this should be implemented. It wasn't a priority.
    return alloc_str("func_typ");
}

char* axo_typ_to_str(axo_typ typ){
    switch (typ.kind){
        case axo_simple_kind:
            return typ.simple;
            break;
        case axo_func_kind:
            return axo_func_to_typ_str((axo_func*)(typ.func_typ)); 
            break;
        case axo_c_arg_list_kind:
            return "c_arg_list_typ";
            break;
        case axo_no_kind:
            return "no_type";
            break;
        case axo_arr_kind:
            return fmtstr("%s[]", axo_typ_to_str(*axo_subtyp(typ)));
            break;
        case axo_struct_kind:
            return ((axo_struct*)typ.structure)->name;
            break;
        case axo_ptr_kind:
            return alloc_str("ptr_type");
            break;
        default:
            return fmtstr("TYPE KIND %d", typ.kind);
            break;
    }
}

axo_decl axo_func_def_to_decl(axo_func func){
    int sz = strlen(axo_typ_to_str(func.f_typ.ret_typ))+strlen(func.name)-(func.f_typ.args_len>0?1:0) + 4;    
    for (int i = 0; i<func.f_typ.args_len; i++)
        sz = sz + strlen(axo_typ_to_str(func.f_typ.args_types[i])) + strlen(func.args_names[i]) + 2;
    char* str = (char*)malloc(sz*sizeof(char));
    strcpy(str, axo_typ_to_str(func.f_typ.ret_typ));
    strcat(str, " ");
    strcat(str, func.name);
    strcat(str, "(");
    for (int i = 0; i<func.f_typ.args_len; i++){
        if (i!=0) strcat(str, ",");
        strcat(str, axo_typ_to_c_str(func.f_typ.args_types[i], ""));
        strcat(str, " ");
        strcat(str, func.args_names[i]);
    }
    strcat(str, ")");
    for (int i = 0; i<func.f_typ.args_len; i++)
        axo_del_var(func.body, func.args_names[i]);
    strapnd(&str, axo_scope_to_statement(func.body).val);
    return (axo_decl){.kind=axo_func_decl_kind, .val=str};
}

char* axo_typ_def_val(axo_typ typ){
    //Fix: Add default function value
    switch (typ.kind){
        case axo_func_kind: return "default_function_value"; break;
        default: return (char*)(typ.def); break;
    }
}

axo_typ axo_clean_typ(axo_typ typ){
    switch(typ.kind){
        case axo_func_kind:
            axo_typ new_typ = typ;
            new_typ.func_typ = alloc_one(axo_func_typ);
            memcpy(new_typ.func_typ, typ.func_typ, sizeof(axo_func_typ));
            axo_func_typ* fnt = (axo_func_typ*)(new_typ.func_typ);
            fnt->args_defs = (char**)malloc(fnt->args_len*sizeof(char*));
            for (int i=0; i<fnt->args_len; i++){
                fnt->args_defs[i] = axo_typ_def_val(fnt->args_types[i]);
            }
            return new_typ;
            break;
        default: return typ; break;
    }
}

char* axo_get_code(axo_state* st){
    char* ret = empty_str;
    for (int i = 0; i<st->decls_len; i++){
        strapnd(&ret, st->decls[i].val);
        strapnd(&ret, "\n");
    }
    return ret;
}

void* axo_safe_malloc(size_t n){
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        abort();
    }
    return p;
}

char* axo_get_ret_assign(axo_scope* sc){
    if (sc==NULL) return NULL;
    if (sc->ret_assign==NULL) return axo_get_ret_assign(sc->parent);
    if (sc->parent==NULL) return NULL;
    return sc->ret_assign;
}

int axo_get_struct_field_index(axo_struct* structure, char* name){
    int i;
    for (i = 0; i<structure->fields_len; i++){
        if (strcmp(structure->fields[i].name, name)==0) return i;
    }
    return -1;
}

axo_expr axo_call_to_expr(axo_func_call cl){
    axo_typ typ = cl.typ;
    axo_func_typ* fnt = (axo_func_typ*)(typ.func_typ);
    //Space for name, 2 brackets, space for each comma  and one null terminator
    int sz = strlen(cl.called_val)+(cl.params_len==0 ? 0 : cl.params_len-1)+3;
    for (int i = 0; i<cl.params_len; i++){
        sz = sz + strlen(cl.params[i].val);
    }
    char* str = (char*)axo_safe_malloc(sz*sizeof(char));
    strcpy(str, cl.called_val);
    strcat(str, "(");
    for (int i = 0; i<cl.params_len; i++){
        if (i>0) strcat(str, ",");
        strcat(str, cl.params[i].val);
    }
    strcat(str, ")");
    axo_expr ret = (axo_expr){
        .typ=fnt->ret_typ,
        .val=str,
        .kind=axo_expr_normal_kind,
        .lval_kind=axo_not_lval_kind
    };
    return ret;
}


char* axo_typ_to_ctyp_str(axo_typ t){
    axo_typ cur_typ = t;
    switch(t.kind){
        case axo_simple_kind:
            return alloc_str(t.simple);
            break;
        case axo_ptr_kind:
        case axo_arr_kind:
            int dims=0;
            while (cur_typ.kind==axo_arr_kind||cur_typ.kind==axo_ptr_kind){
                cur_typ = *axo_subtyp(cur_typ);
                dims++;
            }
            char* stars = (char*)malloc((dims+1)*sizeof(char));
            for (int i=0; i<dims; i++) stars[i] = '*';
            stars[dims] = '\0';
            return fmtstr("%s[]");
            free(stars);
            break;
        default:
            return alloc_str("error in axo_typ_to_ctyp_str");
    }
}

//Change this!!! Name not needed, I was stupid
char* axo_typ_to_c_str(axo_typ t, char* name){
    axo_typ cur_typ = t;
    switch(t.kind){
        case axo_simple_kind:
            return alloc_str(t.simple);
            break;
        case axo_func_kind:        //ret_typ(*name)(typ0, typ1, typ2)
            axo_func_typ fnt = *((axo_func_typ*)(t.func_typ));
            char* ret;
            char* ret_typ_str = axo_typ_to_c_str(fnt.ret_typ, "r");
            int ret_len = strlen(ret_typ_str)+strlen(name)+7;
            char param_name[12];
            char** params = (char**)malloc(fnt.args_len*sizeof(char*));
            for (int i = 0; i<fnt.args_len; i++){
                sprintf(param_name, "p%d", i);
                params[i] = axo_typ_to_c_str(fnt.args_types[i], param_name);
                ret_len = ret_len+strlen(params[i])+1;
            }
            ret = (char*)malloc(ret_len);
            sprintf(ret, "%s(*%s)(", ret_typ_str, name);
            for (int i=0; i<fnt.args_len; i++){
                if (i > 0) strcat(ret, ",");
                strcat(ret, params[i]);
                free(params[i]);
            }
            strcat(ret, ")");
            free(params);
            free(ret_typ_str);
            return ret;
            break;
        case axo_arr_kind:
            return alloc_str("axo__arr"); break;
        case axo_ptr_kind:
            int ptr_lvl = 0;
            while(cur_typ.kind==axo_ptr_kind){
                ptr_lvl++;
                cur_typ = *axo_subtyp(cur_typ);
            }
            char* stars = (char*)malloc(ptr_lvl+1);
            for(int i=0; i<ptr_lvl; i++) stars[i] = '*';
            stars[ptr_lvl] = '\0';
            switch(cur_typ.kind){
                case axo_simple_kind:
                    asprintf(&ret, "%s%s %s", cur_typ.simple, stars, name);
                    return ret;
                    break;
                case axo_func_kind:
                    char* fn_name=fmtstr("%s%s", stars, name);
                    ret = axo_typ_to_c_str(cur_typ, fn_name);
                    free(fn_name);
                    return ret;
                    break;
                default:
                    yyerror(NULL, "Couldn't create a string for pointer of that kind!");
            }
            break;
        default: break;
    }
    return NULL;
}

char* axo_get_arr_name_typ_decl(axo_typ typ, char* name, int sz){
    switch(typ.kind){
        case axo_simple_kind:
            return (sz ? fmtstr("%s %s[%d]", (char*)(typ.simple), name, sz) : fmtstr("%s* %s", (char*)(typ.simple), name));
            break;
        case axo_arr_kind:
            return (sz ? fmtstr("axo__arr %s[%d]", name, sz) : fmtstr("axo__arr* %s", name));
            break;
        default:
            return alloc_str("Arr type declaration no supported yet.");
    }
}

char* axo_name_typ_decl(char* name, axo_typ typ){
    switch(typ.kind){
        case axo_simple_kind: return fmtstr("%s %s", typ.simple, name); break;
        case axo_struct_kind: return fmtstr("%s %s", ((axo_struct*)(typ.structure))->name, name); break;
        case axo_enum_kind: return fmtstr("%s %s", ((axo_enum*)(typ.enumerate))->name, name); break;
        case axo_arr_kind: return fmtstr("axo__arr %s", name); break;
        case axo_ptr_kind: return axo_typ_to_c_str(typ, name); break;
        case axo_func_kind: return axo_typ_to_c_str(typ, name); break;
        default: break;
    }
    return alloc_str("typ name decl");
}

char* axo_for_loop_to_str(axo_for_loop lp){
    return fmtstr("for(%s %s; %s)%s", lp.start, lp.condition, lp.iteration, lp.body);
}

char* axo_get_var_decl_assign(YYLTYPE* loc, char* name, axo_expr expr){
    axo_typ typ = expr.typ;
    switch(typ.kind){
        case axo_enum_kind:
            return fmtstr("%s %s=%s", ((axo_enum*)(typ.enumerate))->name, name, expr.val); break;
        case axo_simple_kind:
            return fmtstr("%s %s=%s", typ.simple, name, expr.val); break;
        case axo_struct_kind:
            return fmtstr("%s %s=%s", ((axo_struct*)(typ.structure))->name, name, expr.val); break;
        case axo_func_kind:
        case axo_arr_kind:
            return fmtstr("axo__arr %s = %s", name, expr.val); break;
        default:
            yyerror(loc,"Type assign declaration not yet supported for this (%d) kind!", typ.kind);
            return fmtstr("typ %s = %s", name, expr.val);
            break;
    }
}

char* axo_typ_kind_to_str(axo_typ_kind tk){
    switch(tk){
        case axo_simple_kind: return "simple"; break;
        case axo_func_kind: return "function"; break;
        case axo_c_arg_list_kind: return "C arg list"; break;
        case axo_arr_kind: return "array"; break;
        case axo_ptr_kind: return "pointer"; break;
        case axo_enum_kind: return "enum";
        case axo_no_kind: return "no type"; break;
        case axo_struct_kind: return "struct"; break;
        case axo_module_kind: return "module"; break;
    }
    return "undefined kind";
}


bool axo_typ_eq(axo_typ t1, axo_typ t2){ //FIX!
    if (t1.kind != t2.kind) return false;
    switch(t1.kind){
        case axo_simple_kind: return !(strcmp(t1.simple, t2.simple)); break;
        case axo_enum_kind: return t1.enumerate == t2.enumerate; break;
        case axo_struct_kind: return t1.structure == t2.structure; break;
        case axo_ptr_kind:
        case axo_arr_kind: return axo_typ_eq(*axo_subtyp(t1), *axo_subtyp(t2)); break;
        case axo_func_kind:
            axo_func_typ* fnt1 = (axo_func_typ*)(t1.func_typ);
            axo_func_typ* fnt2 = (axo_func_typ*)(t2.func_typ);
            if (!axo_typ_eq(fnt1->ret_typ, fnt2->ret_typ)) return false;
            if (fnt1->args_len != fnt2->args_len) return false;
            for (int i=0; i<fnt1->args_len; i++){
                if (!axo_typ_eq(fnt1->args_types[i], fnt2->args_types[i])) return false;   
            }
            return true;
            break;
        default: break;
    }
    yyerror(NULL, "Couldn't tell if type kinds '%s' and '%s' are equal or not", axo_typ_kind_to_str(t1.kind), axo_typ_kind_to_str(t2.kind));
    return true;
}

bool axo_is_no_typ(axo_typ typ){
    return typ.kind == axo_no_kind;
}

bool is_simple_typ_eq(axo_typ t1, char* t2){
    return (t1.kind == axo_simple_kind) && (strcmp(t1.simple, t2) == 0);
}

void parse_operator(YYLTYPE* loc, axo_expr* dest, axo_expr val1, char* op, axo_expr val2){
    if (!axo_typ_eq(val1.typ, val2.typ)){
        yyerror(loc, "The '%s' operator cannot be used with %s and %s!", op, axo_typ_to_str(val1.typ), axo_typ_to_str(val2.typ));
        return;
    }
    if (is_simple_typ_eq(val1.typ, "int") || is_simple_typ_eq(val1.typ, "float")){
        dest->typ = val1.typ;
        asprintf(&(dest->val), "%s%s%s", val1.val, op, val2.val);
        dest->kind = axo_expr_normal_kind;
    }else{
        yyerror(loc, "The '%s' operator cannot be used with %s and %s!", op, axo_typ_to_str(val1.typ), axo_typ_to_str(val2.typ));
        return;
    }
}

void set_val(axo_expr* dest, axo_typ typ, char* val){
    dest->typ = typ;
    asprintf(&(dest->val), "%s", val);
}

axo_scope* axo_scopes_top(axo_scopes* scopes){
    return scopes->scopes[scopes->len-1];
}

void axo_push_scope(axo_scopes* scopes, axo_scope* sc){
    if (scopes->len % axo_scopes_table_cap == 0)
        scopes->scopes = (axo_scope**)realloc(scopes->scopes, (scopes->len+axo_scopes_table_cap)*sizeof(axo_scope*));
    scopes->scopes[scopes->len] = sc;
    scopes->len++;
}

char* itoa_spaced(int a){
    const int len = 4;
    char* ret = alloc_str("     ");
    int b = a;
    int c = 0;
    while (b>0){
        b=b/10;
        c++;
    }
    sprintf(&(ret[len-c]), "%d", a);
    return ret;
}

char* axo_error_with_loc(axo_state* st, YYLTYPE *loc, char* msg){
    //Produce the error string from fmt and args
    char* line_num;
    //Add position and context to the error message
    char* code = axo_file_to_str(st->filepath);
    int up_lines = 2;
    int down_lines = 2;
    int i = 0;
    int line = 1;
    while (line < loc->first_line-up_lines){
        if (code[i] == '\0') break;
        if (code[i] == '\n') line++;
        i++;
    }
    int last_i = i;
    int col = 1;
    i = last_i;
    col = 1;
    line = loc->first_line-up_lines;
    line = line > 1 ? line : 1;
    char* ret;
    char website[] = "https://github.com/MightyPancake/axl/blob/main/errors/error_1.md";
    char* full_filepath = axo_get_full_file_path(st->filepath);
    asprintf(&ret, axo_green_fgs axo_terminal_link("file://%s","%s") axo_reset_style axo_cyan_fgs " %c" axo_blue_fgs " %u:%u" axo_cyan_fgs " -> " axo_red_fgs axo_terminal_link("%s","ERROR: %s") "\n" axo_reset_style, full_filepath, st->filepath, 175, loc->first_line, loc->first_column, website, msg);
    while (line<=loc->last_line+down_lines){
      if (code[i] == '\0') break;
      else if (col == loc->first_column && line == loc->first_line){
        char c = code[i];
        code[i] = '\0';
        line_num = itoa_spaced(line);
        asprintf(&ret, "%s" axo_red_fgs axo_terminal_blink("->%s") axo_cyan_fg " %c" axo_white_fg " %s", ret, line_num, 179, &(code[last_i]));
        last_i = i;
        code[i] = c;
        while (!(col==loc->last_column && line==loc->last_line)){
          if (code[i] == '\0') break;
          if (code[i] == '\n'){
            line++;
            col=1;
          }else{
            col++;
          }
          i++;
        }
        c = code[i];
        code[i] = '\0';
        asprintf(&ret, "%s" axo_red_bg axo_black_fg "%s" axo_reset_style, ret, &(code[last_i]));
        code[i] = c;
        last_i = i;
      }else if (code[i] == '\n'){
        code[i] = '\0';
        if (line == loc->first_line)
            asprintf(&ret, "%s" "%s\n", ret, &(code[last_i]));
        else{
            line_num=itoa_spaced(line);
            asprintf(&ret, "%s" axo_yellow_fgs "  %s" axo_cyan_fgs " %c" axo_white_fgs " %s\n", ret, line_num, 179, &(code[last_i]));   
            free(line_num);
        }
        last_i = i+1;
        line++;
        col = 1;
      }else col++;
      i++;
    }
    free(msg);
    strapnd(&ret, axo_reset_style);
    return ret;
}

char* axo_strip_file_extension(char* filename){
    int len = strlen(filename);
    int i;
    bool dot_found = false;
    for (i=len; i>0; i--){
        if (filename[i] == '.'){
            dot_found = true;
            break;
        }
    }
    if (!dot_found) return alloc_str(filename);
    char* res = (char*)malloc(i*sizeof(char));
    for (int j=0; j<i; j++){
        res[j] = filename[j];
    }
    res[i]='\0';
    return res;
}

char* axo_add_file_extension(char* filename, char* ext){
    int stripped_len = strlen(filename);
    int ext_len = strlen(ext);
    filename=realloc(filename, strlen(filename)+strlen(ext)+2);
    filename[stripped_len] = '.';
    memcpy(&(filename[stripped_len+1]), ext, ext_len+1);
    return filename;
}

char* axo_swap_file_extension(char* filename, char* new_ext){
    char* new_filename = axo_strip_file_extension(filename);
    int stripped_len = strlen(new_filename);
    int ext_len = strlen(new_ext);
    new_filename=realloc(new_filename, strlen(new_filename)+strlen(new_ext)+2);
    new_filename[stripped_len] = '.';
    memcpy(&(new_filename[stripped_len+1]), new_ext, ext_len+1);
    return new_filename;
}

#ifdef _WIN32
    char* axo_get_full_file_path(char* filename){//FIX
        char buffer[MAX_PATH];
        char *lppPart={NULL};
        GetFullPathName("test.axl", MAX_PATH, buffer, &lppPart);
        return alloc_str(buffer);
    }
#else
    char* axo_get_full_file_path(char* filename){ //FIX!
        return alloc_str("full_path_to_file");
    }
#endif
