#define AXO_VERSION "0.0.0"

#include "./utils/utils.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include "./axo.h"
#include "../lex.yy.h"
#include "./asciiart.h" //ASCII art for the mascot!

long long int axo_easter_msg1[] = {2334956330867777876, 2338060278192697204, 8243113893085146979, 8297728800164421695, 7237125614924164640, 2339460887010487854, 7594793506165449313, 8030798189137847406, 7954880256880436589, 7310595013176488804, 2188385};

//Maps
int map_cmp_vars(const void* a, const void* b, void *udata){return strcmp(((axo_var*)(a))->name, ((axo_var*)(b))->name); }
uint64_t map_hash_vars(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_var*)item)->name, strlen(((axo_var*)item)->name), seed0, seed1);}

int map_cmp_func(const void* a, const void* b, void *udata){return strcmp(((axo_func*)(a))->name, ((axo_func*)(b))->name); }
uint64_t map_hash_func(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_func*)item)->name, strlen(((axo_func*)item)->name), seed0, seed1);}

int map_cmp_module(const void* a, const void* b, void *udata){return strcmp(((axo_module*)(a))->name, ((axo_module*)(b))->name); }
uint64_t map_hash_module(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_module*)item)->name, strlen(((axo_module*)item)->name), seed0, seed1);}

int map_cmp_str(const void* a, const void* b, void *udata){return strcmp(*(char**)a, *(char**)b); }
uint64_t map_hash_str(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(*(char**)item, strlen(*(char**)item), seed0, seed1);}

int map_cmp_typ_def(const void* a, const void* b, void *udata){return strcmp(((axo_typ_def*)(a))->name, ((axo_typ_def*)(b))->name); }
uint64_t map_hash_typ_def(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_typ_def*)item)->name, strlen(((axo_typ_def*)item)->name), seed0, seed1);}

int (*axo_printf)(const char* fmt, ...);

char* fmt_str(char* dest, const char fmt[], ...){
    va_list args;
    va_start(args, fmt);
    vsprintf(dest, fmt, args);
    va_end(args);
    return dest;
}

char* fmtstr(const char fmt[], ...){
    char* ret = NULL;
    va_list args;
    va_start(args, fmt);
    int r = vasprintf(&ret, fmt, args);
    va_end(args);
    if (r<0)
        printf("fmtstr error! Returned '%d'!\n", r);
    return ret;
}

char* axo_get_typ_default(axo_typ typ){
    axo_typ err_t;
    if (typ.def != NULL) return (char*)(typ.def);
    switch(typ.kind){
        case axo_none_kind:
            return "none_defult";
            break;
        case axo_simple_kind:
            return "0";
            break;
        case axo_arr_kind:
            return "AXO_NULL_ARR";
            break;
        case axo_func_kind:
            return "NULL";
            break;
        case axo_ptr_kind:
            err_t = (axo_typ){.kind=axo_struct_kind, .structure=&(axo_struct){.name="error"}};
            return (axo_typ_eq(err_t, *axo_subtyp(typ))) ? "errptr" : "NULL";
            break;
        case axo_c_arg_list_kind:
            return "";
        default:
            axo_yyerror(NULL, "Couldn't get default type for kind %s.", axo_typ_kind_to_str(typ.kind));
            break;
    }
    return "";
}

char* axo_file_to_str(char* path){
    char* str = "";
    long len = 0;
    FILE* file = fopen(path, "rb");
    if (file){
        fseek (file, 0, SEEK_END);
        len = ftell (file);
        fseek (file, 0, SEEK_SET);
        str = (char*)malloc((len+1)*sizeof(char));
        if (str){
            if (fread(str, sizeof(char), len, file) < len)
                fprintf(stderr, "Error at %s:%d\n", __FILE__, __LINE__);
        }
        fclose(file);
    }
    str[len] = '\0';
    if (!(str && file)) return (char*)NULL;
    return str;
}

axo_state* axo_new_state(char* root_path){
    new_ptr_one(st, axo_state);
    st->global_scope = axo_new_scope(NULL);
    st->types_def = new_map(axo_typ_def, map_hash_typ_def, map_cmp_typ_def);
    st->decls=NULL;
    st->decls_len=0;
    st->config = (axo_compiler_config){
        .cc = axo_gcc_cc_kind,
        .timer=false,
        .bug_hunter=false,
        .keep_c=false,
        .color_support=axo_limited_color_support_kind,
        .extended_ascii=false
    };
    //Load types
    st->int_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="int", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="int", .cname="int"}, .def="0"}});
    st->u32_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="u32", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="u32", .cname="unsigned"}, .def="0"}});
    st->bool_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="bool", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="bool", .cname="bool"}, .def="false"}});
    st->f32_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="f32", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="f32", .cname="float"}, .def="0.0"}});
    st->byte_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="byte", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="byte", .cname="char"}, .def="((char)0)"}});
    // st->str_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="AXO_STRING_TYP", .typ=(axo_typ){.kind=axo_arr_kind, .arr=new_struct_lit_ptr(axo_arr_typ, axo_arr_typ*, ((axo_arr_typ){.subtyp=axo_byte_typ(st), .dim_count=1})), .def="\"\""}});
    st->str_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="AXO_STRING_TYP", .typ=(axo_typ){.kind=axo_ptr_kind, .def="\"\""}});
    st->str_def->typ.subtyp = &axo_byte_typ(st);
    //Other types
    axo_new_numeric_typ(st, "f64", "double", "0.0");
    axo_new_numeric_typ(st, "i16", "int16_t", "0");
    axo_new_numeric_typ(st, "i64", "int64_t", "0");
    axo_new_numeric_typ(st, "u16", "uint16_t", "0");
    axo_new_numeric_typ(st, "u64", "uint64_t", "0");
    axo_new_numeric_typ(st, "size_t", "size_t", "0");
    //File related
    st->root_path = root_path;
    st->sources = NULL;
    st->sources_len = 0;
    st->entry_file = NULL;
    st->entry_point = NULL;
    st->output_file = NULL;
    st->output_c_file = NULL;
    st->extra_c_sources = (char**)malloc(axo_c_sources_cap*sizeof(char*));
    st->extra_c_sources_len = 0;
    st->input_str = NULL;
    st->input_str_index = 0;
    st->included_files = new_map(char*, map_hash_str, map_cmp_str);
    //Modules
    st->modules = new_map(axo_module, map_hash_module, map_cmp_module);
    st->module_names = NULL;
    st->modules_len = 0;
    //Misc
    st->silenced = false;
    st->run = false;
    st->cc_flags = NULL;
    st->cc_flags_len = 0;
    //Lua
    st->lua_state = luaL_newstate();
    luaL_openlibs(st->lua_state);
    //Scanner
    yylex_init(&(st->scanner));
    return st;
}

void axo_free_state(axo_state* st){
    for (int i=0; i<st->decls_len; i++)
        free(st->decls[i].val);
    //TODO: Free underlying types?
    hashmap_free(st->types_def);
    // free(st->orig_cwd);
    // free(st->root_path);
    for (int i=0; i<st->sources_len; i++){
        axo_free_source(st->sources[i]);
    }
    free(st->sources);
    free(st->entry_file);
    free(st->entry_point);
    free(st->output_file);
    free(st->output_c_file);
    for (int i=0; i<st->extra_c_sources_len; i++)
        free(st->extra_c_sources[i]);
    free(st->extra_c_sources);
    if (st->input_str) free(st->input_str);
    hashmap_free(st->modules);
    for (int i=0; i<st->cc_flags_len; i++)
        free(st->cc_flags[i]);
    free(st->cc_flags);
    axo_free_scope(st->global_scope);

    size_t iter = 0;
    void* item;
    while (hashmap_iter(st->included_files, &iter, &item)) {
        char** path = (char**)item;
        // printf("Freeing path: %s\n", *path);
        free(*path);
    }
    hashmap_free(st->included_files);
    
    free(st);
}

void axo_free_str_map(map hashmap){
    
}

void axo_load_cfg(axo_state* st){
    #ifdef __EMSCRIPTEN__
        st->config = (axo_compiler_config){
            .cc=axo_gcc_cc_kind,
            .keep_c=false,
            .timer=false,
            .bug_hunter=false,
            .color_support=axo_no_color_support_kind,
            .extended_ascii=false
        };
    #else
        size_t cfg_sz;
        axo_compiler_config* cfg = (axo_compiler_config*)axo_file_to_bytes(fmt_str((char[axo_max_path_len]){}, "%s"axo_dir_sep"axo.config", st->root_path), &cfg_sz);
        st->config = *cfg;
    #endif
}

#define skip_arg ({ \
    arg_num++; \
    if (arg_num>=argc){ \
        arg = NULL; \
    }else{ \
        arg = argv[arg_num]; \
    } \
})
#define next_arg ({ \
    skip_arg; \
    if (arg==NULL){ \
        axo_yyerror(NULL, "Expected at least one more argument after: %s", argv[arg_num-1]); \
        return; \
    } \
    arg; \
})

void axo_handle_args(axo_state* st, int argc, char** argv, int init_arg){
    int arg_num = init_arg;
    char* arg = argv[init_arg];
    while (arg != NULL){
        // printf("Got arg #%d/%d: %s\n", arg_num, argc, arg);
        if (strcmp(arg, "-e")==0){ //Set entry point
            next_arg;
            if (st->entry_point == NULL)
                st->entry_point = alloc_str(arg);
            else
                axo_yyerror(NULL, "Cannot set entry point to '%s' after it was already set to '%s'.", arg, st->entry_point);
        }else if (strcmp(arg, "-r")==0 || strcmp(arg, "run") == 0){ //Silence compiler's printfs
            st->run = true;
        }else if (strcmp(arg, "-s")==0){ //Silence compiler's printfs
            st->silenced = true;
        }else if (strcmp(arg, "-o")==0){ //Set output file name
            next_arg;
            if (st->output_file == NULL)
                st->output_file = alloc_str(arg);
            else
                axo_yyerror(NULL, "Cannot set output file name to '%s' after it was already set to '%s'.", arg, st->output_file);
        }else if (strcmp(arg, "-i")==0){ //Get input from argument
            next_arg;
            if (st->input_str == NULL){
                st->input_str = alloc_str(arg);
            }else{
                axo_yyerror(NULL, "Multiple string inputs.");
            }
        }else if (strcmp(arg, "-oc")==0){ //Set output c file name
            next_arg;
            if (st->output_c_file == NULL)
                st->output_c_file = alloc_str(arg);
            else
                axo_yyerror(NULL, "Cannot set output c file name to '%s' after it was already set to '%s'.", arg, st->output_c_file);
        }else{//Set entry file
            if (st->entry_file == NULL)
                st->entry_file = alloc_str(arg);
            else
                axo_yyerror(NULL, "Cannot set entry file to '%s' after it was already set to '%s'.", arg, st->entry_file);
        }
        skip_arg;
    }
}
#undef skip_arg
#undef next_arg

char* axo_bool_to_str(bool a, axo_color_support_kind col_sup){
    if (col_sup == axo_no_color_support_kind)
        return a ? "true" : "false";
    return a ? axo_green_fg"true"axo_reset_style : axo_red_fg"false"axo_reset_style;
}

char* axo_cc_to_str(axo_cc_kind cc){
    switch(cc){
        case axo_gcc_cc_kind: return "gcc"; break;
        default: return "other cc"; break;
    }
    return "invalid cc";
}

char* axo_color_support_to_str(axo_color_support_kind col_sup){
    switch(col_sup){
        case axo_full_color_support_kind: return "full"; break;
        case axo_limited_color_support_kind: return "limited"; break;
        default: return "no"; break;
    }
    return "invalid color support";
}

int axo_color_count(axo_color_support_kind col_sup){
    switch(col_sup){
        case axo_no_color_support_kind: return 1; break;
        case axo_limited_color_support_kind: return 30; break;
        case axo_full_color_support_kind: return 255*255*255; break;
    }
    return 0;
}

char* axo_get_color_esc(int index, axo_color_support_kind col_sup){
    static char cols[30][16] = {
        "\033[38;5;196m",
        "\033[38;5;202m",
        "\033[38;5;208m",
        "\033[38;5;214m",
        "\033[38;5;220m",
        "\033[38;5;226m",
        "\033[38;5;190m",
        "\033[38;5;154m",
        "\033[38;5;118m",
        "\033[38;5;82m",
        "\033[38;5;46m",
        "\033[38;5;47m",
        "\033[38;5;48m",
        "\033[38;5;49m",
        "\033[38;5;50m",
        "\033[38;5;51m",
        "\033[38;5;45m",
        "\033[38;5;39m",
        "\033[38;5;33m",
        "\033[38;5;27m",
        "\033[38;5;21m",
        "\033[38;5;57m",
        "\033[38;5;93m",
        "\033[38;5;129m",
        "\033[38;5;165m",
        "\033[38;5;201m",
        "\033[38;5;200m",
        "\033[38;5;199m",
        "\033[38;5;198m",
        "\033[38;5;197m"
    };
    switch(col_sup){
        case axo_no_color_support_kind: return ""; break;
        case axo_full_color_support_kind:
        case axo_limited_color_support_kind:
            return cols[index];
            break;
    }
    return "";
}

axo_expr axo_get_array_field(axo_state* st, YYLTYPE* expr_loc, YYLTYPE* field_loc, axo_expr expr, char* field){
    axo_arr_typ arr_typ = axo_get_arr_typ(expr.typ);
    if (strcmp("len", field)==0){
      axo_typ typ = (axo_typ){
        .kind = axo_ptr_kind,
        .subtyp=malloc(sizeof(axo_typ))
      };
      *axo_subtyp(typ) = axo_int_typ(st);
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ = typ,
        .val=fmtstr("(%s).len", expr.val),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("empty", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ = axo_bool_typ(st),
        .val=fmtstr("((%s).len[0] == 0)", expr.val),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("dims", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ=axo_int_typ(st),
        .val=fmtstr("%d", axo_get_arr_typ(expr.typ).dim_count),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("data_len", field)==0){
        switch(arr_typ.dim_count){
            case 1:
            case 2:
            case 3:
                return (axo_expr){
                    .kind=axo_expr_normal_kind,
                    .typ=axo_u32_typ(st),
                    .val=fmtstr("axo_arr_data_len_%dd(%s)", arr_typ.dim_count, expr.val),
                    .lval_kind = axo_not_lval_kind
                };
                break;
            default:
                axo_yyerror(expr_loc, "Field not supported for %dd arays yet.");
                break;
        }
    }else if (strcmp("cap", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ=axo_u32_typ(st),
        .val=fmtstr("axo_arr_get_cap(%s)", expr.val),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("data", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ=(axo_typ){
            .kind = axo_ptr_kind,
            .subtyp = &(axo_get_arr_typ(expr.typ).subtyp),
        },
        .val=fmtstr("%s.data", expr.val),
        .lval_kind = axo_other_lval_kind
      };
    }else if (strcmp("dynamic", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ=axo_bool_typ(st),
        .val=fmtstr("axo_arr_is_dynamic(%s)", expr.val),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("static", field)==0){
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ=axo_bool_typ(st),
        .val=fmtstr("axo_arr_is_static(%s)", expr.val),
        .lval_kind = axo_not_lval_kind
      };
    }else if (strcmp("first", field)==0){
      axo_typ typ = (axo_typ){
        .kind = axo_ptr_kind,
        .subtyp=malloc(sizeof(axo_typ))
      };
      *axo_subtyp(typ) = axo_get_arr_typ(expr.typ).subtyp;
      return (axo_expr){
        .kind=axo_expr_normal_kind,
        .typ = axo_get_arr_typ(expr.typ).subtyp,
        .val=fmtstr("axo_arr_1d_at(%s, %s, 0)", axo_typ_to_c_str(typ), expr.val),
        .lval_kind = axo_other_lval_kind
      };
      free(typ.subtyp);
    }else if (strcmp("last", field)==0){
        axo_typ typ = (axo_typ){
            .kind = axo_ptr_kind,
            .subtyp=malloc(sizeof(axo_typ))
        };
        *axo_subtyp(typ) = axo_get_arr_typ(expr.typ).subtyp;
        return (axo_expr){
            .kind=axo_expr_normal_kind,
            .typ = arr_typ.subtyp,
            .val=fmtstr("axo_arr_at(%s, %s, axo_arr_data_len_%dd(%s)-1)", axo_typ_to_c_str(typ), expr.val, arr_typ.dim_count, expr.val),
            .lval_kind = axo_other_lval_kind
        };
        free(typ.subtyp);
        if (arr_typ.dim_count>3)
            axo_yyerror(field_loc, "Field not yet supported for %dd arrays!");
    }else{
        axo_yyerror(field_loc, "Invalid array pseudo-field.");
    }
    return (axo_expr){};
}

axo_expr axo_expr_dot_field(axo_state* st,YYLTYPE* pos, YYLTYPE* expr_pos, YYLTYPE* field_pos, axo_expr expr, char* field){
    axo_expr ret = (axo_expr){};
    axo_enum* enumerate;
    axo_struct* structure;
    while(expr.typ.kind==axo_ptr_kind){
        char* new_val = fmtstr("(*%s)", expr.val);
        expr = (axo_expr){
            .kind=axo_expr_normal_kind,
            .lval_kind=false,
            .typ=*axo_subtyp(expr.typ)
        };
        free(expr.val);
        expr.val = new_val;
    }
    switch(expr.kind){
      case axo_expr_enum_typ_kind:
        enumerate = (axo_enum*)(expr.typ.enumerate);
        int index = -1;
        for (int i=0; i<enumerate->len; i++){
          if (strcmp(enumerate->names[i], field)==0){
            index = i;
            break;
          }
        }
        if (index<0)
         axo_yyerror(pos, "Enum '%s' doesn't have a field named '%s'.", enumerate->name, field);
        else{
          ret = (axo_expr){
            .kind=axo_expr_normal_kind,
            .typ=expr.typ,
            .val=fmtstr("%s$%s", enumerate->name, enumerate->names[index])
          };
        }
        break;
      default:
        switch(expr.typ.kind){
          case axo_struct_kind:
            structure = (axo_struct*)(expr.typ.structure);
            int index = -1;
            for (int i=0;i<structure->fields_len; i++){
              if (strcmp(structure->fields[i].name, field)==0){
                index = i;
                break;
              }
            }
            if (index<0){
                axo_yyerror(pos, "Struct '%s' doesn't have a field named '%s'.", structure->name, field);
            }else{
              ret = (axo_expr){
                .kind=axo_expr_normal_kind,
                .val=fmtstr("%s.%s", expr.val, field),
                .typ=structure->fields[index].typ
              };
            }
            break;
          case axo_arr_kind: //.len, .data, .dims
            ret = axo_get_array_field(st, expr_pos, field_pos, expr, field);
            break;
          default:
            axo_yyerror(expr_pos, "Cannot get field of type '%s'", axo_typ_to_str(expr.typ));
          break;
        }
        break;
    }
    free(field);
    return ret;
}

axo_func_call axo_method_call(axo_state* st, axo_scope* sc, YYLTYPE* pos, YYLTYPE* expr_pos, YYLTYPE* name_pos, axo_expr expr, char* name, bool rval_now){
    axo_func_call ret;
    axo_expr passed_expr;
    axo_expr self_expr = expr;
    while(self_expr.typ.kind==axo_ptr_kind){
        char* new_val = fmtstr("(*%s)", self_expr.val);
        self_expr = (axo_expr){
            .kind=axo_expr_normal_kind,
            .lval_kind=false,
            .typ=*axo_subtyp(self_expr.typ)
        };
        free(self_expr.val);
        self_expr.val = new_val;
    }
    switch(self_expr.typ.kind){
      case axo_enum_kind:
      case axo_simple_kind:
      case axo_struct_kind:
        if (self_expr.lval_kind == axo_not_lval_kind){
          axo_yyerror(expr_pos, "Cannot reference a non-lvalue expression to call a method.");
        }else{
          char* fn_name = fmtstr("met_%s_%s", axo_typ_to_str(self_expr.typ), name);
          axo_var* var = axo_get_var(sc, fn_name);
          if (!var)
            axo_yyerror(name_pos, "Method '%s' undefined before usage.", name);
          else{
            if (var->typ.kind != axo_func_kind){
              axo_yyerror(name_pos, "Attempted to call a non-function method. (Naming clash?)");  
            }else{
              passed_expr = (axo_expr){
                .kind=axo_expr_normal_kind,
                .lval_kind=axo_not_lval_kind,
                .val=fmtstr("(&(%s))", self_expr.val),
                .typ=(axo_typ){
                  .kind=axo_ptr_kind,
                  .subtyp=alloc_one(axo_typ)
                }
              };
              *axo_subtyp(passed_expr.typ) = self_expr.typ;
              ret = (axo_func_call){
                .typ = var->typ,
                .called_val = fn_name,
                .params_len=1,
                .params=(axo_expr*)malloc(axo_func_args_cap*sizeof(axo_expr))
              };
              ret.params[0] = passed_expr;
            }
          }
        }        
        break;
        case axo_arr_kind:
          passed_expr = (axo_expr){
            .kind=axo_expr_normal_kind,
            .lval_kind=axo_not_lval_kind,
            .val=fmtstr("(&(%s))", self_expr.val),
            .typ=(axo_typ){
              .kind=axo_ptr_kind,
              .subtyp=alloc_one(axo_typ)
            }
          };
          *axo_subtyp(passed_expr.typ) = self_expr.typ;
          ret = axo_get_array_method(st, expr_pos, name_pos, passed_expr, name);
          break;
      default:
        axo_yyerror(expr_pos, "Methods can only operate on simple types (primitives, enums or structures), not '%s'.", axo_typ_to_str(self_expr.typ));
        break;
    }
    return ret;
}

axo_func_call axo_get_array_method(axo_state* st, YYLTYPE* expr_loc, YYLTYPE* name_loc, axo_expr expr, char* name){
    //FIX! This is huge
    axo_typ deref_typ = *axo_subtyp(expr.typ);
    axo_arr_typ arr_typ = axo_get_arr_typ(deref_typ);
    axo_func_call ret;
    axo_func_typ* f_typ = alloc_one(axo_func_typ);
    if (strcmp("push", name) == 0){
        *f_typ = (axo_func_typ){
            .args_len = 3,
            .args_types = malloc(3*sizeof(axo_typ)),
            .args_defs=malloc(3*sizeof(axo_typ)),
            .ret_typ=expr.typ
        };
        f_typ->args_types[0] = expr.typ;
        f_typ->args_types[1] = expr.typ;
        axo_typ subtyp = *axo_subtyp(expr.typ);
        f_typ->args_types[2] = axo_get_arr_typ(subtyp).subtyp;
        ret = (axo_func_call){
            .called_val = alloc_str("axo_arr_1d_append"),
            .typ = (axo_typ){
                .kind=axo_func_kind,
                .func_typ=f_typ
            },
            .params_len=2,
            .params=(axo_expr*)malloc(3*sizeof(axo_expr))
        };
        axo_typ* t = alloc_one(axo_typ);
        *t = axo_get_arr_typ(expr.typ).subtyp;
        ret.params[0] = (axo_expr){
            .typ=expr.typ,
            .val=fmtstr("%s, %s",
            axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=&(axo_get_arr_typ(deref_typ).subtyp)}), axo_typ_to_c_str(axo_get_arr_typ(deref_typ).subtyp))
        };
        ret.params[1] = (axo_expr){
            .typ=expr.typ,
            .val=fmtstr("%s", expr.val)
        };
        free(t);
        return ret;
    }else if (strcmp("pop", name) == 0){
        *f_typ = (axo_func_typ){
            .args_len = 1,
            .args_types = malloc(sizeof(axo_typ)),
            .args_defs=malloc(sizeof(axo_typ)),
            .ret_typ=expr.typ
        };
        f_typ->args_types[0] = expr.typ;
        ret = (axo_func_call){
            .called_val = fmtstr("axo_arr_pop_%dd", arr_typ.dim_count),
            .typ = (axo_typ){
                .kind=axo_func_kind,
                .func_typ=f_typ
            },
            .params_len=1,
            .params=(axo_expr*)malloc(sizeof(axo_expr))
        };
        ret.params[0] = expr;
        ret.params[0].val = fmtstr("%s, %s", axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=&(arr_typ.subtyp)}), expr.val);
        if (arr_typ.dim_count>1)
            axo_yyerror(name_loc, "Method not yet supported for %dd arrays!", arr_typ.dim_count);
        return ret;
    }else if (strcmp("cap", name) == 0){
        *f_typ = (axo_func_typ){
            .args_len = 2,
            .args_types = malloc(2*sizeof(axo_typ)),
            .args_defs=malloc(2*sizeof(axo_typ)),
            .ret_typ=expr.typ
        };
        f_typ->args_types[0] = expr.typ;
        f_typ->args_types[1] = axo_byte_typ(st);
        ret = (axo_func_call){
            .called_val = alloc_str("axo_arr_set_cap"),
            .typ = (axo_typ){
                .kind=axo_func_kind,
                .func_typ=f_typ
            },
            .params_len=1,
            .params=(axo_expr*)malloc(2*sizeof(axo_expr))
        };
        ret.params[0] = expr;
        return ret;
    }else if (strcmp("free", name) == 0){
        *f_typ = (axo_func_typ){
            .args_len = 1,
            .args_types = malloc(sizeof(axo_typ)),
            .args_defs=malloc(sizeof(axo_typ)),
            .ret_typ=expr.typ
        };
        f_typ->args_types[0] = expr.typ;
        ret = (axo_func_call){
            .called_val = alloc_str("axo_arr_free"),
            .typ = (axo_typ){
                .kind=axo_func_kind,
                .func_typ=f_typ
            },
            .params_len=1,
            .params=(axo_expr*)malloc(sizeof(axo_expr))
        };
        ret.params[0] = expr;
        return ret;
    }else if (strcmp("shrink", name) == 0){
        *f_typ = (axo_func_typ){
            .args_len = 1,
            .args_types = malloc(sizeof(axo_typ)),
            .args_defs=malloc(sizeof(axo_typ)),
            .ret_typ=axo_u32_typ(st)
        };
        f_typ->args_types[0] = expr.typ;
        ret = (axo_func_call){
            .called_val = fmtstr("axo_arr_shrink_%dd", arr_typ.dim_count),
            .typ = (axo_typ){
                .kind=axo_func_kind,
                .func_typ=f_typ
            },
            .params_len=1,
            .params=(axo_expr*)malloc(1*sizeof(axo_expr))
        };
        ret.params[0] = expr;
        ret.params[0].val = fmtstr("%s, (*%s)", axo_typ_to_c_str(arr_typ.subtyp), expr.val);
        if (arr_typ.dim_count>3)
            axo_yyerror(expr_loc, "Method unsupported for %dd arrays yet!", arr_typ.dim_count);
        return ret;
    }else{
        axo_yyerror(name_loc, "Undefined array method.");
    }
    return (axo_func_call){};
}

void axo_lolprintf(axo_color_support_kind col_sup, int seed, const char* fmt, ...){
    char* str = NULL;
    va_list args;
    int len;
    int col_count;
    int c;
    switch(col_sup){
        case axo_no_color_support_kind:
            va_start(args, fmt);
            vprintf(fmt, args);
            va_end(args);
            break;
        case axo_full_color_support_kind:
        case axo_limited_color_support_kind:
            va_start(args, fmt);
            if (vasprintf(&str, fmt, args)<0) fprintf(stderr, "vasprintf error at %s:%d\n", __FILE__, __LINE__);
            va_end(args);
            len = strlen(str);
            col_count = axo_color_count(col_sup);
            c = seed % col_count;
            for (int i = 0; i<len; i++){
                c = (c+1) % col_count;
                printf("%s%c", axo_get_color_esc(c, col_sup), str[i]);
            }
            printf(axo_reset_style);
            break;
    }
}

char* axo_lolsprintf(axo_color_support_kind col_sup, int seed, char* dest, const char* fmt, ...){
    char* str = NULL;
    va_list args;
    int len;
    int col_count;
    int c;
    switch(col_sup){
        case axo_no_color_support_kind:
            va_start(args, fmt);
            vsprintf(dest, fmt, args);
            va_end(args);
            return dest;
            break;
        case axo_full_color_support_kind:
        case axo_limited_color_support_kind:
            va_start(args, fmt);
            if (vasprintf(&str, fmt, args) < 0){
                fprintf(stderr, "error in vasprintf %s:%d\n", __FILE__, __LINE__);
            }
            va_end(args);
            len = strlen(str);
            col_count = axo_color_count(col_sup);
            c = seed % col_count;
            char hlpr[2] = " ";
            for (int i = 0; i<len; i++){
                c = (c+1) % col_count;
                strcat(dest, axo_get_color_esc(c, col_sup));
                hlpr[0] = str[i];
                strcat(dest, hlpr);
            }
            strcat(dest, axo_reset_style);
            return dest;
            break;
    }
    return dest;
}


void axo_color_printf(int index, axo_color_support_kind col_sup, const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    if (col_sup == axo_no_color_support_kind){
        vprintf(fmt, args);
        va_end(args);
        return;
    }
    printf("%s", axo_get_color_esc(index, col_sup));
    vprintf(fmt, args);
    printf(axo_reset_style);
    va_end(args);
}

void axo_print_config(axo_state* st){
    axo_compiler_config cfg = st->config;
    axo_color_support_kind col_sup = axo_col_sup(st);
    int col_count = axo_color_count(col_sup);
    int seed = rand() % col_count;
    printf("%s", axo_get_color_esc(28, col_sup));
    int axo_moji_res;
    if (col_sup == axo_no_color_support_kind)
        axo_moji_res = system(fmt_str((char[axo_max_path_len]){},"%s"axo_dir_sep"printmoji"AXO_BIN_EXT, st->root_path));
    else
        axo_moji_res = system(fmt_str((char[axo_max_path_len]){},"%s"axo_dir_sep"printcolmoji"AXO_BIN_EXT, st->root_path));
    if (axo_moji_res != 0) printf("Error printing cfg\n");
    printf("  v.%s\n", AXO_VERSION);
    printf(axo_reset_style"cc: %s\n", axo_lolsprintf(col_sup, seed, (char[64]){}, axo_cc_to_str(cfg.cc)));
    printf("keep_c: %s\n", axo_bool_to_str(cfg.keep_c, col_sup));
    printf("timer: %s\n", axo_bool_to_str(cfg.timer, col_sup));
    printf("color_support: %s\n", axo_lolsprintf(col_sup, (seed+10)%col_count, (char[64]){}, axo_color_support_to_str(col_sup)));
    printf("extended_ascii: %s\n", axo_bool_to_str(cfg.extended_ascii, col_sup));
}

int axo_info_cmd(axo_state* st, int argc, char** argv){
    axo_print_config(st);
    return 0;
}

int axo_set_cmd(axo_state* st, int argc, char** argv){
    if (argc < 4){
        printf("Not enough arguments. Usage:\naxo set <setting> <value>\n");
        return 1;
    }
    bool valid = true;
    char* setting = argv[2];
    char* val = argv[3];
    if (strcmp(setting, "cc") == 0){
        if (strcmp(val, "gcc")==0){
            st->config.cc = axo_gcc_cc_kind;
        }else{
            printf("Invalid C compiler.\n");
            valid = false;
        }
    }else if (strcmp(setting, "keep_c") == 0){
        if (strcmp(val, "true")==0){
            st->config.keep_c = true;
        }else if (strcmp(val, "false")==0) {
            st->config.keep_c = false;
        }else{
            printf("Setting 'keep_c' can only be set to false/true.\n");
            valid = false;
        }
    }else if (strcmp(setting, "color_support") == 0){
        if (strcmp(val, "limited")==0){
            st->config.color_support = axo_limited_color_support_kind;
        }else if (strcmp(val, "full")==0) {
            st->config.color_support = axo_full_color_support_kind;
        }else if (strcmp(val, "no")==0) {
            st->config.color_support = axo_no_color_support_kind;
        }else{
            printf("Setting 'color_support' can only be set to full/limited/no.\n");
            valid = false;
        }
    }else if (strcmp(setting, "timer") == 0){
        if (strcmp(val, "true")==0){
            st->config.timer = true;
        }else if (strcmp(val, "false")==0) {
            st->config.timer = false;
        }else{
            printf("Setting 'timer' can only be set to false/true.\n");
            valid = false;
        }
    }else if (strcmp(setting, "extended_ascii") == 0){
        if (strcmp(val, "true")==0){
            st->config.extended_ascii = true;
        }else if (strcmp(val, "false")==0) {
            st->config.extended_ascii = false;
        }else{
            printf("Setting 'extended_ascii' can only be set to false/true.\n");
            valid = false;
        }
    }else{
        printf("Unknown setting '%s.\n'", setting);
        valid = false;
    }
    if (valid){
        printf("Saving new config...\n");
        axo_bytes_to_file(fmt_str((char[axo_max_path_len]){}, "%s"axo_dir_sep"axo.config", st->root_path), (char*)(&(st->config)), sizeof(axo_compiler_config));
        return axo_info_cmd(st, argc, argv);
    }
    return 1;
}

void axo_new_source(axo_state* st, char* path){
    resize_dyn_arr_if_needed(axo_source, st->sources, st->sources_len, axo_state_sources_cap);
    axo_source* src = &(st->sources[st->sources_len]);
    src->name = alloc_str(path);
    src->kind = axo_file_source_kind;
    src->path = axo_resolve_path(path);
    // printf("parent dir: %s\n", src->path);
    src->file = fopen(src->path, "rb");
    src->index = 0;
    src->pos = 0;
    src->line = 1;
    src->col = 1;
    
    axo_chdir(axo_get_parent_dir(axo_tmp_path_str, path));
    yyrestart(src->file, st->scanner);
    st->sources_len++;
    if (!(src->file)){
        fprintf(stderr, "fopen('%s') error: ", path);
        perror("");
    }
}

void axo_free_source(axo_source s){
    free(s.name);
    switch(s.kind){
        case axo_file_source_kind:
            free(s.path);
            break;
        case axo_string_source_kind:
        break;
    }
}

void axo_free_index_access(axo_index_access ia){
    free(ia.indexes);
}

void axo_new_string_source(axo_state* st, char* code){
    resize_dyn_arr_if_needed(axo_source, st->sources, st->sources_len, axo_state_sources_cap);
    axo_source* src = &(st->sources[st->sources_len]);
    src->name = alloc_str("string source");
    src->path = alloc_str("input string");
    src->str = alloc_str(code);
    src->index = 0;
    src->pos = 0;
    src->line = 1;
    src->col = 1;
    src->kind = axo_string_source_kind;
    // axo_chdir(src->parent_dir);
    st->sources_len++;
}

void axo_pop_source(axo_state* st){
    st->sources_len--;
    axo_free_source(st->sources[st->sources_len]);
    if (st->sources_len>0){
        axo_source* src = &(st->sources[st->sources_len-1]);
        axo_switch_source(st, src);
    }else{
        printf("all sources ended. (this should never happen)\n");
    }
}

void axo_switch_source(axo_state* st, axo_source* src){
    switch (src->kind){
        case axo_string_source_kind:
            src->index = src->pos;
            break;
        case axo_file_source_kind:
            fseek(src->file, src->pos, SEEK_SET);
            yyrestart(src->file, st->scanner);
            char* dir = axo_get_parent_dir(axo_tmp_path_str, src->path);
            // printf("Switching chdir to %s\n", dir);
            axo_chdir(dir);
            break;
    }
}

axo_decl axo_include_file(axo_state* st, YYLTYPE* loc, char* filename, bool str_lit){
    char str[axo_max_path_len] = "";
    if (str_lit){
        strcpy(str, &(filename[1]));
        str[strlen(str)-1] = '\0';
    }else{
        strcpy(str, filename);
    }
    //Check local first
    bool exists = axo_file_exists(str);
    if (exists){
        char* res_path = axo_resolve_path(str);
        if (!axo_was_file_included(st, res_path)){
            hashmap_set(st->included_files, &res_path);
            axo_new_source(st, str);
        }else{
            free(res_path);
        }
    }else{
      axo_yyerror(loc, "Couldn't find '%s'.\n", str);
    }
    return (axo_decl){.val=fmtstr("//including '%s'", str), .kind=axo_use_decl_kind};
}

bool axo_was_file_included(axo_state* st, char* path){
    void* p = (char*)(hashmap_get(st->included_files, &path));
    return p?true:false;
}

axo_decl axo_use_module(axo_state* st, YYLTYPE* loc, char* name){
    //Check local first
    char path[axo_max_path_len];
    bool found = false;
    strcpy(path, name);

    if (!(found = axo_dir_exists(path))){
        sprintf(path, "%s"axo_dir_sep"modules"axo_dir_sep"%s", st->root_path, name);
        if (!(found = axo_dir_exists(path))){
            axo_yyerror(loc, "Couldn't find module '%s'.", name);
        }
    }
    if (found){
        strcat(path, axo_dir_sep);
        strcat(path, name);
        strcat(path, ".axo");
        if (axo_file_exists(path)){
            axo_include_file(st, loc, path, false);
            char* lua_path = axo_swap_file_extension(path, ".lua");
            if (axo_file_exists(lua_path)){
                bool ok;
                const char* res = axo_lua_dofile(st, lua_path, &ok);
                if (!ok){
                    axo_err_printf("Lua error: %s\n", res);
                }
            }
        }else{
            axo_yyerror(loc, "No entry file for module. Missing '%s.axo' in module directory?", name);
        }
    }
    return (axo_decl){.val=fmtstr("//use %s", name), .kind=axo_use_decl_kind};
}

axo_module axo_new_module(){
    return (axo_module){
        .name = NULL,
        .prefix = NULL,
        .version = NULL,
        .author = NULL,
        .website = NULL,
        .license_name = NULL,
        .license = NULL,
        .description = NULL,
    };
}

void axo_load_module_defaults(axo_state* st, axo_module* mod){
    if (!(mod->name)){
        char* no_ext = axo_strip_file_extension(axo_src_path(st));
        int i;
        for (i = strlen(no_ext); i>=0; i--){
            if (no_ext[i] == '.' || no_ext[i] == axo_dir_sep_char)
                break;
        }
        mod->name = alloc_str(&(no_ext[i+1]));
        free(no_ext);
    }
    mod->prefix = mod->prefix ? mod->prefix : fmtstr("%s_mod_", mod->name);
    mod->version = mod->version ? mod->version : alloc_str("0.0.0");
    mod->author = mod->author ? mod->author : alloc_str("?");
    mod->website = mod->website ? mod->website : alloc_str("https://www.website.com");
    mod->license_name = mod->license_name ? mod->license_name : alloc_str("Support free software! <3");
    mod->license = mod->license ? mod->license : alloc_str("https://www.license-website.org/license.txt");
    mod->description = mod->description ? mod->description : alloc_str("A cool module for cool people!");
}

void axo_set_module(axo_state* st, axo_module mod){
    axo_module* ptr = alloc_one(axo_module);
    *ptr = mod;
    hashmap_set(st->modules, ptr);
    free(ptr);
}

axo_module* axo_get_module(axo_state* st, char* name){
    axo_module placeholder = (axo_module){.name=name};
    return (axo_module*)(hashmap_get(st->modules, &placeholder));
}

char* axo_generate_module_string(axo_module mod){
    return fmtstr("(axo_module){.name=\"%s\",.prefix=\"%s\",.version=\"%s\", .author=\"%s\",.website=\"%s\",.license_name=\"%s\",.license=\"%s\",.description=\"%s\"}",
    mod.name, mod.prefix, mod.version, mod.author, mod.website, mod.license_name, mod.license, mod.description);
}

char* axo_generate_modules(axo_state* st){
    // char* ret = fmtstr("void axo_set_modules(){\naxo__arr tmp = (axo__arr){.data=((axo_module[]){");
    char* ret = fmtstr("axo_module axo_mods[] = {");
    for (int i=0; i<st->modules_len; i++){
        char* name = st->module_names[i];
        axo_module* mod = axo_get_module(st, name);
        char* mod_str = axo_generate_module_string(*mod);
        if (i>0) strapnd(&ret, ",");
        strapnd(&ret, mod_str);
        free(mod_str);
    }
    // strapnd(&ret, fmt_str(s_str(128), "}), .len=((axo_arr_dim_t[]){%d}),.flags=AXO_ARR_STATIC};\nmodules = tmp;\n}\n", st->modules_len));
    strapnd(&ret, fmt_str(s_str(256), "};\naxo__arr modules = {.data=axo_mods, .len=((axo_arr_dim_t[]){%d}),.flags=AXO_ARR_STATIC};\n", st->modules_len));
    return ret;
}

axo_decl axo_add_module(axo_state* st, axo_module mod){
    resize_dyn_arr_if_needed(char*, st->module_names, st->modules_len, axo_modules_cap);
    st->module_names[st->modules_len++] = mod.name;
    axo_set_module(st, mod);
    char* ret  = fmtstr("/*\n\tname: %s\n\tprefix: %s\n\tversion: %s\n\tauthor: %s\n\twebsite: %s\n\tlicense_name: %s\n\tlicense: %s\n\tdescription: %s\n*/", mod.name, mod.prefix, mod.version, mod.author, mod.website, mod.license_name, mod.license, mod.description);
    return (axo_decl){
        .kind = axo_module_info_decl_kind,
        .val = ret
    };
}

axo_typ_def* axo_set_typ_def(YYLTYPE* loc, axo_state* st, axo_typ_def td){
    const axo_typ_def* atd = hashmap_get(st->types_def, &td);
    if (atd == NULL){
        new_ptr_one(ptr, axo_typ_def);
        *ptr = td;
        hashmap_set(st->types_def, ptr);
        return ptr;
    }else
        axo_yyerror(loc, "'%s' already defined as '%s'", td.name, atd->name); //FIX!!!
    return NULL;
}

const axo_typ_def* axo_get_typ_def(axo_state* st, char* name){
    axo_typ_def placeholder = (axo_typ_def){.name=name};
    return hashmap_get(st->types_def, &placeholder);
}

axo_scope* axo_new_scope(axo_scope* parent){
    new_ptr_one(sc, axo_scope);
    *sc = (axo_scope){
        .statements = NULL,
        .statements_len = 0,
        .parent = parent,
        .variables = new_map(axo_var, map_hash_vars, map_cmp_vars),
        .to_global = NULL,
        .parent_func = parent ? parent->parent_func : NULL,
        .defer_used = false
    };
    return sc;
}

void axo_add_decl(axo_state* st, axo_decl d){
    resize_dyn_arr_if_needed(axo_decl, st->decls, st->decls_len, axo_decls_cap);
    st->decls[st->decls_len++] = d;
}

void axo_add_statement(axo_scope* sc, axo_statement s){
    resize_dyn_arr_if_needed(axo_statement, sc->statements, sc->statements_len, axo_statements_cap);
    sc->statements[sc->statements_len++] = s;
}

void axo_set_var(axo_scope* sc, axo_var var){
    if (var.typ.kind==axo_literal_kind) var.typ.kind=axo_simple_kind;
    if (sc->to_global){
        axo_set_var(sc->to_global, var);
        return;
    }
    // printf("'%s' of type %s->'%s'\n", var.name, axo_typ_kind_to_str(var.typ.kind), axo_typ_to_str(var.typ));
    if (axo_get_var(sc, var.name)){
        axo_yyerror(NULL, "Variable '%s' is already declared.", var.name);
        return;
    }
    hashmap_set(sc->variables, &var);
}

axo_var* axo_get_var(axo_scope* sc, char* name){
    if (sc==NULL || sc->variables==NULL) return NULL;
    if (sc->to_global) return axo_get_var(sc->to_global, name);
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
    new_ptr_one(fnt, axo_func_typ);
    *fnt = fn.f_typ;
    axo_var var = (axo_var){
        .name=fn.name,
        .typ=(axo_typ){
            .kind=axo_func_kind,
            .func_typ=fnt,
            .def=alloc_str("FUNC_DEFAULT")
        }
    };
    new_ptr_one(ptr, axo_var);
    *ptr = var;
    hashmap_set(st->global_scope->variables, ptr);
}

axo_statement axo_scope_to_statement(axo_scope* sc){
    axo_statement ret = (axo_statement){.kind=axo_scope_statement_kind};
    ret.val = sc->defer_used ? alloc_str("{Deferral") : alloc_str("{");
    for (int i = 0; i<sc->statements_len; i++){
        char* st = axo_scope_statement_to_str(sc, sc->statements[i]);
        strapnd(&ret.val, "\n");
        strapnd(&ret.val, st);
    }
    strapnd(&(ret.val), "\n}");
    return ret;
}

void axo_free_scope(axo_scope* sc){
    for (int i=0; i<sc->statements_len; i++)
        free(sc->statements[i].val);
    free(sc->statements);
    //This produces an error!
    axo_free_variables(sc->variables);
    free(sc);
}

void axo_free_variables(map vars){
    size_t iter = 0;
    void *item;
    while (hashmap_iter(vars, &iter, &item)) {
        axo_var* var = item;
        axo_typ typ = var->typ;
        // printf("Freeing %s\n", var->name);
        axo_free_typ(typ);
    }
    hashmap_free(vars);
}

axo_typ axo_deep_copy_typ(axo_typ t){
    axo_typ* s;
    axo_typ res = t;
    switch(t.kind){
        case axo_ptr_kind:
            s = alloc_one(axo_typ);
            *s = axo_deep_copy_typ(*((axo_typ*)(t.subtyp)));
            res.subtyp = s;
        default: break;
    }
    return res;
}

void axo_free_typ(axo_typ t){
    switch(t.kind){
        case axo_func_kind:
            axo_free_func_typ(*(axo_func_typ*)(t.func_typ));
            free(t.func_typ);
            break;
        case axo_ptr_kind:
            axo_free_typ(*(axo_typ*)(t.subtyp));
            // free(t.subtyp);
            break;
        case axo_arr_kind:
            free(t.arr);
        default: break;
    }
}

void axo_free_func(axo_func fn){
    int args_len = fn.f_typ.args_len;
    for (int i=0; i<args_len; i++){
        free(fn.args_names[i]);
    }
    if (fn.args_names) free(fn.args_names);
    if (fn.body) axo_free_scope(fn.body);
}

void axo_free_func_typ(axo_func_typ ft){
    for (int i=0; i<ft.args_len; i++){
        if (ft.args_defs[i]) free(ft.args_defs[i]);
        axo_free_typ(ft.args_types[i]);
    }
    if (ft.args_types) free(ft.args_types);
    if (ft.args_defs) free(ft.args_defs);
}

char* axo_scope_statement_to_str(axo_scope* sc, axo_statement stmnt){
    switch(stmnt.kind){
        case axo_ret_statement_kind:
            if (sc->defer_used) stmnt.val[0] = 'R';
            break;
        default:
            break;
    }
    return stmnt.val;
}

char* axo_scope_code(axo_scope* sc){
    char* ret = empty_str;
    for (int i = 0; i<sc->statements_len; i++){
        if (i>0) strapnd(&ret, "\n");
        strapnd(&ret, sc->statements[i].val);
    }
    return ret;
}

char* axo_err_msg(axo_err_code err_code){
  switch(err_code){
    case axo_undeclared_var_err_code: return "Variable used before declaration."; break;
    case axo_invalid_rval_err_code: return "Invalid r-value."; break;
    case axo_undeclared_assignment_expr_err_code: return "Assignment as rvalue is only valid for already declared lvalues."; break;
  }
  return "Invalid error code!";
}

char* axo_type_str(axo_typ typ, char* ret){
    axo_func_typ fnt;
    int i;
    char dim_stars[128];
    switch (typ.kind){
        case axo_literal_kind:
        case axo_simple_kind:
            return typ.simple.name;
            break;
        case axo_func_kind:
            fnt = *((axo_func_typ*)(typ.func_typ));
            ret = fmt_str(ret, "(%s fn ", axo_typ_to_str(fnt.ret_typ));
            for (int i=0; i<fnt.args_len; i++){
                if (i>0) strcat(ret, ",");
                strcat(ret, axo_typ_to_str(fnt.args_types[i]));
            }
            strcat(ret, ")");
            return ret;
            break;
        case axo_c_arg_list_kind:
            return "...";
            break;
        case axo_none_kind:
            return "none";
            break;
        case axo_no_kind:
            return "no_type";
            break;
        case axo_arr_kind:
            for (i=1; i<axo_get_arr_typ(typ).dim_count; i++){
                dim_stars[i-1] = ':';
            }
            dim_stars[i-1] = '\0';
            return fmt_str(s_str(512),"[%s]%s", dim_stars, axo_typ_to_str(*axo_subtyp(typ)));
            break;
        case axo_struct_kind:
            return ((axo_struct*)typ.structure)->name;
            break;
        case axo_ptr_kind:
            return fmt_str(ret, "@%s", axo_typ_to_str(*axo_subtyp(typ)));
            break;
        case axo_enum_kind:
            return "enum";
            break;
        default:
            return fmt_str(s_str(128), "TYP%d", typ.kind);
            break;
    }
}

char* axo_c_arr_of_typ(axo_typ typ, char* inside){
    char* ret = NULL;
    axo_func_typ fnt;
    switch(typ.kind){
        case axo_literal_kind:
        case axo_simple_kind: return fmtstr("%s[%s]", typ.simple.cname, inside); break;
        case axo_arr_kind: return fmtstr("axo__arr[%s]", inside); break;
        case axo_func_kind:
            fnt = *((axo_func_typ*)(typ.func_typ));
            ret = fmtstr("%s(*[])(", axo_typ_to_c_str(fnt.ret_typ));
            for (int i = 0; i<fnt.args_len; i++){
                if (i>0) strapnd(&ret, ",");
                strapnd(&ret, axo_typ_to_c_str(fnt.args_types[i]));
            }
            strapnd(&ret, ")");
            return ret;
            break;
        default:
            axo_yyerror(NULL, "Unsupported axo_c_arr_of_typ type '%s'!", axo_typ_to_str(typ));
            return alloc_str("unsupported_type");
    }
}

bool axo_is_typ_prim(axo_typ t){
    switch(t.kind){
        case axo_literal_kind:
        case axo_simple_kind:
        case axo_struct_kind:
        case axo_enum_kind:
        case axo_arr_kind:
        case axo_none_kind:
        case axo_c_arg_list_kind:
            return true;
            break;
        default:
            return false;
            break;
    }
}

char* axo_prim_typ_to_c_str(axo_typ t){
    switch(t.kind){
        case axo_simple_kind:
        case axo_literal_kind:
            return t.simple.cname; break;
        case axo_struct_kind:
            return ((axo_struct*)(t.structure))->name; break;
        case axo_enum_kind:
            return ((axo_enum*)(t.enumerate))->name; break;
        case axo_arr_kind:
            return "axo__arr"; break;
        case axo_none_kind:
            return "void"; break;
        case axo_c_arg_list_kind:
            return "..."; break;
        default:
            return "unknown";
    }
    return "unknown";
}

char** axo_typ_to_strings(axo_typ typ, char** dest){
    char* left = empty_str;
    char* nleft = NULL;
    char* right = empty_str;
    
    axo_typ cur_typ = typ;
    // typ.is_const = false;
    // typ.is_volatile = false;
    bool was_left = false;
    while(1){
        if (axo_is_typ_prim(cur_typ))
            break;
        switch(cur_typ.kind){
            case axo_ptr_kind:
                //Left side
                nleft = empty_str;
                strapnd(&nleft, "*");
                strapnd(&nleft, left);
                free(left);
                left = nleft;
                nleft = NULL;
                //Right side
                cur_typ = *axo_subtyp(cur_typ);
                was_left = true;
                break;
            case axo_func_kind:
                //Left side
                nleft = empty_str;
                strapnd(&nleft, left);
                strapnd(&nleft, was_left ? "((*" : "(*");
                free(left);
                left = nleft;
                nleft = NULL;
                //Right side
                strapnd(&right, ")(");
                axo_func_typ* fnt = (axo_func_typ*)(cur_typ.func_typ);
                for (int i=0; i<fnt->args_len; i++){
                    if (i>0) strapnd(&right, ",");
                    char* param_str = axo_typ_to_c_str(fnt->args_types[i]);
                    strapnd(&right, param_str);
                    free(param_str);
                }
                strapnd(&right, was_left ? "))" : ")");
                cur_typ = fnt->ret_typ;
                was_left = false;
                break;
            default:
                axo_yyerror(NULL, "Wrong type in declaration! (%s)", axo_typ_kind_to_str(cur_typ.kind));
                return dest;
                break;
        }
    }
    char* prim_typ = alloc_str(axo_prim_typ_to_c_str(cur_typ));
    dest[0] = fmtstr("%s%s", typ.is_const?"const ":"", typ.is_volatile?"volatile ":"");
    dest[1] = prim_typ;
    dest[2] = left;
    dest[3] = right;
    return dest;
}

char* axo_typ_to_c_str(axo_typ typ){
    char** strs = axo_typ_to_strings(typ, (char*[4]){});
    char* ret;
    ret = fmtstr("%s%s%s%s", strs[0], strs[1], strs[2], strs[3]);
    for (int i=0; i<4; i++) free(strs[i]);
    return ret;
}

char* axo_name_typ_decl(char* name, axo_typ typ){
    char** strs = axo_typ_to_strings(typ, (char*[4]){});
    char* ret = fmtstr("%s%s %s%s%s", strs[0], strs[1], strs[2], name, strs[3]);
    for (int i=0; i<4; i++) free(strs[i]);
    return ret;
}

axo_decl axo_func_decl_to_decl(axo_func func){
    char* name = strcmp(func.name, "main") == 0 ? "axo__main" : func.name;
    char* str = alloc_str(axo_typ_to_c_str(func.f_typ.ret_typ));
    char* arg_str = NULL;
    strapnd(&str, " ");
    strapnd(&str, name);
    strapnd(&str, "(");
    for (int i = 0; i<func.f_typ.args_len; i++){
        if (i!=0) strapnd(&str, ",");
        arg_str = axo_name_typ_decl(func.args_names[i], func.f_typ.args_types[i]);
        strapnd(&str, arg_str);
        free(arg_str);
    }
    strapnd(&str, ")");
    return (axo_decl){.kind=axo_func_decl_decl_kind, .val=str};
}

axo_decl axo_func_def_to_decl(axo_func func){
    axo_decl ret = axo_func_decl_to_decl(func);
    char* sc_str = axo_scope_to_statement(func.body).val;
    strapnd(&(ret.val), sc_str);
    free(sc_str);
    ret.kind = axo_func_def_decl_kind;
    for (int i = 0; i<func.f_typ.args_len; i++)
        axo_del_var(func.body, func.args_names[i]);
    return ret;
}

char* axo_arr_access_to_str(YYLTYPE* arr_loc, axo_expr arr, YYLTYPE* index_loc, axo_index_access index){
    axo_arr_typ arr_typ = axo_get_arr_typ(arr.typ);
    axo_typ t = (axo_typ){
        .kind=axo_ptr_kind,
        .subtyp=&(arr_typ.subtyp),
        .def=NULL
    };
    switch(arr_typ.dim_count){
        case 1:
            return fmtstr("axo_arr_1d_at(%s,%s,%s)", axo_typ_to_c_str(t), arr.val, index.indexes[0].val);
            break;
        case 2:
            return fmtstr("axo_arr_2d_at(%s,%s,%s,%s)", axo_typ_to_c_str(t), arr.val, index.indexes[0].val, index.indexes[1].val);
            break;
        case 3:
            return fmtstr("axo_arr_3d_at(%s,%s,%s,%s,%s)", axo_typ_to_c_str(t), arr.val, index.indexes[0].val, index.indexes[1].val, index.indexes[2].val);
            break;
        default:
            axo_yyerror(index_loc, "Indexing arrays above 3 dimensions is not yet implemented.");
            return alloc_str("invalid_array_access");
            break;
    }
}

bool axo_typ_valid_arr_index(axo_typ typ, axo_state* st){
    if (typ.kind != axo_simple_kind) return false;
    if (axo_typ_eq(typ, axo_int_typ(st))) return true;
    return false;
}

axo_typ axo_clean_typ(axo_typ typ){
    axo_typ new_typ = typ;
    switch(typ.kind){
        case axo_literal_kind:
            typ.kind=axo_simple_kind;
            return typ;
            break;
        case axo_func_kind:
            new_typ.func_typ = alloc_one(axo_func_typ);
            memcpy(new_typ.func_typ, typ.func_typ, sizeof(axo_func_typ));
            axo_func_typ* fnt = (axo_func_typ*)(new_typ.func_typ);
            fnt->args_defs = (char**)malloc(fnt->args_len*sizeof(char*));
            for (int i=0; i<fnt->args_len; i++){
                fnt->args_defs[i] = axo_get_typ_default(fnt->args_types[i]);
            }
            return new_typ;
            break;
        default: return typ; break;
    }
}

char* axo_get_code(axo_state* st){
    char* ret = alloc_str("");
    st->decls[st->modules_decl].val = axo_generate_modules(st);
    // strapnd(&ret, "axo_load_args(args);\n");
    for (int i = 0; i<st->decls_len; i++){
        strapnd(&ret, st->decls[i].val);
        strapnd(&ret, "\n");
    }
    return ret;
}

void* axo_safe_malloc(size_t n){
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %lu bytes.\n",(long unsigned)n);
        abort();
    }
    return p;
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
    //Free call params
    for (int i=0;i<cl.params_len; i++)
        free(cl.params[i].val);
    free(cl.params);
    
    axo_expr ret = (axo_expr){
        .typ=fnt->ret_typ,
        .val=str,
        .kind=axo_expr_normal_kind,
        .lval_kind=axo_not_lval_kind
    };
    return ret;
}

char* axo_get_arr_name_typ_decl(axo_typ typ, char* name, int sz){
    switch(typ.kind){
        case axo_simple_kind:
            return (sz ? fmtstr("%s %s[%d]", (char*)(typ.simple.cname), name, sz) : fmtstr("%s* %s", (char*)(typ.simple.cname), name));
            break;
        case axo_arr_kind:
            return (sz ? fmtstr("axo__arr %s[%d]", name, sz) : fmtstr("axo__arr* %s", name));
            break;
        default:
            return alloc_str("Arr type declaration no supported yet.");
    }
}

char* axo_for_loop_to_str(axo_for_loop lp){
    return fmtstr("for(%s %s; %s)%s", lp.start, lp.condition, lp.iteration, lp.body);
}

void axo_parse_each_loop(axo_each_loop* lp, axo_state* state, axo_scope* scope, int loop_count){
    switch(lp->collection.typ.kind){
        case axo_arr_kind:
            lp->iter_over = (bool*)malloc(lp->dim_count*sizeof(bool));
            axo_arr_typ arr_typ = axo_get_arr_typ(lp->collection.typ);
            if (arr_typ.dim_count != lp->dim_count)
                axo_yyerror(&(((YYLTYPE*)(lp->locs))[1]), "Cannot iterate over %d dimensional array with a %d dimensional index.", arr_typ.dim_count, lp->dim_count);
            //Only create specified indexes
            if (lp->value_iter.data == NULL){
                for(int i=0; i<lp->dim_count; i++){
                    axo_expr iter = lp->dim_iters[i];
                    if (iter.lval_kind == axo_var_lval_kind && iter.typ.kind == axo_no_kind){
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter.val});
                        lp->iter_over[i] = true;
                    }else if (lp->dim_iters[i].val == NULL){
                        lp->iter_over[i] = false;
                    }else if (!axo_typ_valid_arr_index(iter.typ, state)){
                        axo_yyerror(&(((YYLTYPE*)(lp->locs))[i+3]), "Cannot index array with type '%s'.", axo_typ_to_str(iter.typ));
                    }
                }
            //Create all needed indexes, even those not specified
            }else{
                for(int i=0; i<lp->dim_count; i++){
                    axo_expr iter = lp->dim_iters[i];
                    if (iter.lval_kind == axo_var_lval_kind && iter.typ.kind == axo_no_kind){
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter.val});
                        lp->iter_over[i] = true;
                    }else if (lp->dim_iters[i].val == NULL){
                        char* iter_name = fmtstr("axo__it%dd%d", i, loop_count);
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter_name});
                        lp->dim_iters[i] = (axo_expr){.typ=axo_int_typ(state), .val=iter_name};
                        lp->iter_over[i] = true;
                    }else if (!axo_typ_valid_arr_index(iter.typ, state)){
                        axo_yyerror(&(((YYLTYPE*)(lp->locs))[i+3]), "Cannot index array with type '%s'.", axo_typ_to_str(iter.typ));
                    }else{
                        lp->iter_over[i] = false;
                    }
                }
                //Finally, create the value iterator
                axo_set_var(scope, (axo_var){.typ = arr_typ.subtyp, .name = lp->value_iter.data});
            }
            break;
        default:
            break;
    }
}

axo_statement axo_each_to_statement(axo_each_loop lp){
    char* val = NULL;
    switch (lp.collection.typ.kind){
        case axo_arr_kind:
            val = empty_str;
            axo_arr_typ arr_typ = axo_get_arr_typ(lp.collection.typ);
            for (int i=0; i<lp.dim_count; i++){
                if (lp.iter_over[i])
                    strapnd(&val, fmtstr("for(axo_arr_it_t %s=0; %s<(%s).len[%d]; %s++)", lp.dim_iters[i].val, lp.dim_iters[i].val, lp.collection.val, i, lp.dim_iters[i].val));    
            }
            strapnd(&val, "{");
            if (lp.value_iter.data != NULL){
                char* arr_at_str = axo_arr_access_to_str(&(((YYLTYPE*)(lp.locs))[2]), lp.collection, &(((YYLTYPE*)(lp.locs))[1]), (axo_index_access){.indexes=lp.dim_iters, .index_count=lp.dim_count});
                strapnd(&val, axo_get_var_decl_assign(NULL, (axo_var){.name=lp.value_iter.data}, (axo_expr){.typ=arr_typ.subtyp, .val=arr_at_str}));
                strapnd(&val, ";");
                free(arr_at_str);
            }
            strapnd(&val, lp.body);
            strapnd(&val, "}");
            break;
        default:
            axo_yyerror(&(((YYLTYPE*)(lp.locs))[2]), "Each cannot iterate over '%s' type values.", axo_typ_kind_to_str(lp.collection.typ.kind));
            break;
    }
    return (axo_statement){
        .kind=axo_each_statement_kind,
        .val=val
    };
}

axo_statement axo_switch_to_statement(axo_switch swtch){
    char* str = fmtstr("switch(%s){", swtch.root.val);
    for (int i=0; i<swtch.cases_len; i++){
        strapnd(&str, "\n");
        axo_switch_case cs = swtch.cases[i];
        switch(cs.kind){
            case axo_list_case_kind:
                for (int j=0; j<cs.exprs_len; j++){
                    strapnd(&str, "case ");
                    strapnd(&str, cs.exprs[j].val);
                    strapnd(&str, ":\n");
                }
                break;
            case axo_range_case_kind:
                strapnd(&str, "case ");
                strapnd(&str, cs.exprs[0].val);
                strapnd(&str, " ... ");
                strapnd(&str, cs.exprs[1].val);
                strapnd(&str, ":\n");
                break;
            case axo_default_case_kind:
                strapnd(&str, "default:\n");
                break;
        }
        strapnd(&str, cs.statement.val);
        if (!(cs.no_break)) strapnd(&str, "\nbreak;");
    }
    strapnd(&str, "}");
    return (axo_statement){.val=str, .kind=axo_switch_statement_kind};
}

char* axo_get_var_decl_assign(YYLTYPE* pos, axo_var var, axo_expr expr){
    char* name = var.name;
    axo_typ typ = var.typ;
    char* var_decl = axo_name_typ_decl(name, expr.typ);
    char* ret = fmtstr("%s%s%s = %s", typ.is_const?"const ":"", typ.is_volatile?"volatile ":"", var_decl, expr.val);
    free(var_decl);
    return ret;
}

axo_typ axo_merge_type_with_qualifiers(axo_typ typ, axo_typ type_q){
    axo_typ res = typ;
    res.is_const = type_q.is_const;
    res.is_volatile = type_q.is_volatile;
    return res;
}

char* axo_typ_kind_to_str(axo_typ_kind tk){
    switch(tk){
        case axo_simple_kind: return "simple"; break;
        case axo_func_kind: return "function"; break;
        case axo_arr_kind: return "array"; break;
        case axo_c_arg_list_kind: return "C arg list"; break;
        case axo_ptr_kind: return "pointer"; break;
        case axo_enum_kind: return "enum";
        case axo_no_kind: return "no type"; break;
        case axo_struct_kind: return "struct"; break;
        case axo_none_kind: return "none"; break;
        case axo_module_kind: return "module"; break;
        case axo_literal_kind: return "literal"; break;
        default: return "unknown_kind"; break;
    }
    return "undefined kind";
}


bool axo_typ_eq(axo_typ t1, axo_typ t2){ //FIX!
    if ((t1.kind == axo_simple_kind && t2.kind == axo_literal_kind) || (t1.kind == axo_simple_kind && t2.kind == axo_literal_kind)) return true;
    if (t1.kind != t2.kind) return false;
    axo_arr_typ a1, a2;
    axo_func_typ* fnt1;
    axo_func_typ* fnt2;
    axo_typ* subtyp1;
    axo_typ* subtyp2;
    switch(t1.kind){
        case axo_none_kind: return true; break;
        case axo_literal_kind:
        case axo_simple_kind: return !(strcmp(t1.simple.cname, t2.simple.cname)); break;
        case axo_enum_kind: return t1.enumerate == t2.enumerate; break;
        case axo_struct_kind: return !(strcmp(((axo_struct*)(t1.structure))->name, ((axo_struct*)(t2.structure))->name)); break;
        case axo_ptr_kind:
            subtyp1 = axo_subtyp(t1);
            subtyp2 = axo_subtyp(t2);
            if (subtyp1->kind==axo_none_kind || subtyp2->kind==axo_none_kind) return true;
            return axo_typ_eq(*subtyp1, *subtyp2);
        case axo_arr_kind:
            a1 = axo_get_arr_typ(t1);
            a2 = axo_get_arr_typ(t2);
            return axo_typ_eq(a1.subtyp, a2.subtyp) && a1.dim_count==a2.dim_count;  break;
        case axo_func_kind:
            fnt1 = (axo_func_typ*)(t1.func_typ);
            fnt2 = (axo_func_typ*)(t2.func_typ);
            if (!axo_typ_eq(fnt1->ret_typ, fnt2->ret_typ)) return false;
            if (fnt1->args_len != fnt2->args_len) return false;
            for (int i=0; i<fnt1->args_len; i++){
                if (!axo_typ_eq(fnt1->args_types[i], fnt2->args_types[i])) return false;   
            }
            return true;
            break;
        default: break;
    }
    axo_yyerror(NULL, "Couldn't tell if type kinds '%s' and '%s' are equal or not", axo_typ_kind_to_str(t1.kind), axo_typ_kind_to_str(t2.kind));
    return true;
}

bool axo_is_no_typ(axo_typ typ){
    return typ.kind == axo_no_kind;
}

bool is_simple_typ_eq(axo_typ t1, char* t2){
    return (t1.kind == axo_simple_kind) && (strcmp(t1.simple.cname, t2) == 0);
}

axo_expr axo_parse_special_assignment(YYLTYPE* lval_loc, YYLTYPE* assign_loc, YYLTYPE* val_loc, axo_expr lval, const char* assign_op, axo_expr val){
    switch(lval.lval_kind){
        case axo_not_lval_kind:
            axo_yyerror(lval_loc, "Special assignments need the lval to be declared before.");
            break;
        case axo_var_lval_kind:
            if (lval.typ.kind == axo_no_kind){
                axo_yyerror(lval_loc, "Special assignments need the lval to be declared before.");
                break;
            }
        default:
        if (!axo_typ_eq(lval.typ, val.typ)){
            axo_yyerror(val_loc, "Type missmatch, expected type '%s' for the special assignment.", axo_typ_to_str(lval.typ));
        }else{
            return (axo_expr){
                .kind=axo_expr_normal_kind,
                .lval_kind=axo_not_lval_kind,
                .val=fmtstr("%s%s%s", lval.val, assign_op, val.val),
                .typ=lval.typ
            };
        }
        break;
    }
    return (axo_expr){};
}

void parse_operator(YYLTYPE* loc, axo_expr* dest, axo_expr val1, char* op, axo_expr val2){
    if (val1.typ.kind != axo_simple_kind || !axo_typ_eq(val1.typ, val2.typ)){
        axo_yyerror(loc, "The '%s' operator cannot be used with %s and %s!", op, axo_typ_to_str(val1.typ), axo_typ_to_str(val2.typ));
        return;
    }else{
        dest->typ = val1.typ;
        dest->val = fmtstr("%s%s%s", val1.val, op, val2.val);
        dest->kind = axo_expr_normal_kind;
        free(val1.val);
        free(val2.val);
    }
}

void set_val(axo_expr* dest, axo_typ typ, char* val){
    dest->typ = typ;
    dest->val = fmtstr("%s", val);
}


const char* axo_identifier_kind_to_str(axo_identifier_kind iden){
    switch(iden){
        case axo_identifier_var_kind: return "variable"; break;
        case axo_identifier_module_kind: return "module"; break;
        case axo_identifier_typ_kind: return "type"; break;
        case axo_no_identifier_kind: return "nothing"; break;
    }
    return "unknown";
}

axo_scope* axo_scopes_top(axo_scopes* scopes){
    return scopes->scopes[scopes->len-1];
}

void axo_push_scope(axo_scopes* scopes, axo_scope* sc){
    resize_dyn_arr_if_needed(axo_scope*, scopes->scopes, scopes->len, axo_scopes_table_cap);
    scopes->scopes[scopes->len++] = sc;
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

unsigned char axo_symbol(axo_symbol_kind s, bool e_ascii){
    switch(s){
        case axo_arrow_symbol:
            return e_ascii ? 175 : '>'; break;
        case axo_vertical_line_symbol:
            return e_ascii ? (unsigned char)179 : '|'; break;
    }
    return ' ';
}

char* axo_error_with_loc(axo_state* st, YYLTYPE *loc, char* msg){
    #ifdef __EMSCRIPTEN__
        return fmtstr("Error at %d:%d: %s", loc->first_line, loc->first_column);
    #endif
    bool e_ascii = st->config.extended_ascii;
    //Produce the error string from fmt and args
    char* line_num;
    //Add position and context to the error message
    // for (int i=st->sources_len; i>0; i--){
    //     printf("in %s", st->sources[i-1].name);
    //     if (i!=1) printf("\n");
    // }
    char cwd[1024];
    axo_cwd(cwd, 1024);
    if (st->sources_len==1){
        axo_chdir(st->orig_cwd);
    }else if (axo_get_source(st)->kind == axo_file_source_kind){
        axo_chdir(axo_get_parent_dir(axo_tmp_path_str, st->sources[st->sources_len-1].path));
    }
    char* code = axo_get_source(st)->kind == axo_string_source_kind ?
    axo_get_source(st)->str
    : axo_file_to_str(axo_src_path(st));
    if (!code){
        fprintf(stderr, "Error while getting code from src! Null string from file '%s' while in '%s'.\n", axo_src_path(st), axo_cwd((char[512]){}, 512));
        return alloc_str("Couldn't get an error message");
    }
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
    char* full_filepath = axo_resolve_path(axo_src_path(st));
    ret = fmtstr(axo_green_fgs axo_terminal_link("file://%s","%s") axo_reset_style axo_cyan_fgs " %c" axo_blue_fgs " %u:%u" axo_cyan_fgs " -> " axo_red_fgs axo_terminal_link("%s","ERROR: %s") "\n" axo_reset_style, full_filepath, axo_src_path(st), axo_symbol(axo_arrow_symbol, e_ascii), loc->first_line, loc->first_column, website, msg);
    while (line<=loc->last_line+down_lines){
      if (code[i] == '\0') break;
      else if (col == loc->first_column && line == loc->first_line){
        char c = code[i];
        code[i] = '\0';
        line_num = itoa_spaced(line);
        ret = fmtstr("%s" axo_red_fgs axo_terminal_blink("->%s") axo_cyan_fg " %c" axo_white_fg " %s", ret, line_num, axo_symbol(axo_vertical_line_symbol, e_ascii), &(code[last_i]));
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
        ret = fmtstr("%s" axo_red_bg axo_black_fg "%s" axo_reset_style, ret, &(code[last_i]));
        code[i] = c;
        last_i = i;
      }else if (code[i] == '\n'){
        code[i] = '\0';
        if (line == loc->first_line)
            ret = fmtstr("%s" "%s\n", ret, &(code[last_i]));
        else{
            line_num=itoa_spaced(line);
            ret = fmtstr("%s" axo_yellow_fgs "  %s" axo_cyan_fgs " %c" axo_white_fgs " %s\n", ret, line_num, axo_symbol(axo_vertical_line_symbol, e_ascii), &(code[last_i]));
            free(line_num);
        }
        last_i = i+1;
        line++;
        col = 1;
      }else col++;
      i++;
    }
    strapnd(&ret, axo_reset_style);
    free(code);
    axo_chdir(cwd);
    return ret;
}

void axo_bytes_to_file(const char *filename, char* bytes, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(bytes, sizeof(char), size, file);
        fclose(file);
    } else {
        printf("Saving failed, cannot to open the file '%s'\n", filename);
    }
}

char* axo_file_to_bytes(const char *filename, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Reading failed, cannot open the file '%s'\n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);
    char *byte_array = malloc(*size);
    if (byte_array == NULL) {
        printf("Failed to allocate memory\n");
        fclose(file);
        return NULL;
    }
    if (fread(byte_array, 1, *size, file) != *size) {
        printf("Failed to read the file\n");
        free(byte_array);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return byte_array;
}

char* axo_strip_file_extension(char* filename){
    int len = strlen(filename);
    int i=0;
    bool dot_found = false;
    for (i=len; i>0; i--){
        if (filename[i] == '.'){
            dot_found = true;
            break;
        }
    }
    if (!dot_found) return alloc_str(filename);
    char* res = (char*)malloc((i+1)*sizeof(char));
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
    memcpy(&(new_filename[stripped_len]), new_ext, ext_len+1);
    return new_filename;
}

bool axo_file_exists(char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r"))) {
        fclose(file);
        return true; // File exists
    }
    return false; // File does not exist
}

bool axo_dir_exists(char* dirname) {
    DIR *dir = opendir(dirname);
    if (dir) {
        closedir(dir);
        return true; // Directory exists
    } else if (ENOENT == errno) {
        return false; // Directory does not exist
    } else {
        return false; // opendir() failed for some other reason
    }
}

long long int* axo_encode_easter(char* input, int* out_len){
    //Assume long long int is 8 bytes
    int len = strlen(input);
    *out_len = (len+1)/8 + 1;
    long long int* ret = (long long int*)malloc((*out_len)*sizeof(long long int));
    ret = memcpy(ret, input, len+1);
    return ret;
}

char* axo_decode_easter(long long int* data){
    return (char*)data;
}

#ifdef _WIN32
    char* axo_resolve_path(char* filename){
        char buffer[MAX_PATH];
        char *lppPart={NULL};
        GetFullPathName(filename, MAX_PATH, buffer, &lppPart);
        return alloc_str(buffer);
    }
#elif __linux__
    char* axo_resolve_path(char* filename){
    if (filename == NULL) {
        printf("ERROR: filename is NULL\n");
        return NULL;
    }
    char* ret = (char*)malloc(PATH_MAX);
    if (ret == NULL) {
        printf("ERROR: malloc failed\n");
        return NULL;
    }
    // printf("realpath: %s\n", filename);
    char* res = realpath(filename, ret);
    if (res == NULL) {
        axo_err_printf("Couldn't get realpath for '%s'. cwd: '%s'\n", filename, axo_cwd(axo_tmp_path_str, 1024));
        free(ret);
        return NULL;
    }

    return ret;
    }
#elif __APPLE__ 
    char* axo_resolve_path(char* filename){
        return filename;
    }
#elif __EMSCRIPTEN__
    char* axo_resolve_path(char* filename) {
        char resolved_path[axo_max_path_len];
        EM_ASM({
            var inputPath = UTF8ToString($0);
            var lookup = FS.lookupPath(inputPath, { follow: true });
            var resolvedPath = lookup.path;
            stringToUTF8(resolvedPath, $1, 1024);
        }, filename, resolved_path);

        return alloc_str(resolved_path);
    }
#endif

#ifdef _WIN32
    int axo_chdir(char* path){
        return SetCurrentDirectory(path);
    }
#elif __linux 
    int axo_chdir(char* path){
        // printf(axo_magenta_fg"cd '%s'\n"axo_reset_style, path);
        return chdir(path);
    }
#elif __APPLE__ 
    int axo_chdir(char* path){
        return 1;
    }
#elif __EMSCRIPTEN__
    int axo_chdir(char* path) {
        int result;
        result = EM_ASM_INT({
            var newPath = UTF8ToString($0);
            try {
                FS.chdir(newPath);
                return 0; // Success
            } catch (e) {
                console.error('Failed to change directory to ' + newPath + ': ' + e);
                return -1; // Failure
            }
        }, path);

        return result;
    }

    
#endif

#ifdef _WIN32
    char* axo_get_exec_path(char* buf, int sz) {
        DWORD bytes = GetModuleFileName(NULL, buf, sz);
        if (bytes > 0) {
            buf[bytes] = '\0';
        } else {
            fprintf(stderr, "Error getting executable path: %lu\n", GetLastError());
        }
        return buf;
    }
#elif __linux
    char* axo_get_exec_path(char* buf, int sz){
        ssize_t bytes = readlink("/proc/self/exe", buf, sz);
        if (bytes >= 0) {
            buf[bytes] = '\0';
        } else {
            perror("Error getting executable path");
        }
        return buf;
    }
#elif __APPLE__ 
    char* axo_get_exec_path(char* buf, int sz){
        return "";
    }
#elif __EMSCRIPTEN__
    char* axo_get_exec_path(char* buf, int sz){
        return "";
    }
    
#endif

#ifdef _WIN32
char* axo_cwd(char* dest, size_t sz) {
    if (GetCurrentDirectory((DWORD)sz, dest) == 0) {
        DWORD errorMessageID = GetLastError();
        fprintf(stderr, "axo_cwd() error: %lu\n", errorMessageID);
        return NULL;
    }
    return dest;
}
#elif __linux || __APPLE__
    char* axo_cwd(char* dest, size_t sz){
        if (getcwd(dest, sz) == NULL)
            perror("axo_cwd() error");
        return dest;
    }
#elif __EMSCRIPTEN__
char* axo_cwd(char* dest, size_t sz) {
    EM_ASM({
        var currentDir = FS.cwd();
        stringToUTF8(currentDir, $0, $1);
    }, dest, sz);

    return dest;
}
    
#endif

char* axo_get_parent_dir(char* dest, char* path) {
    strcpy(dest, path);
    char *last_slash;
    #ifdef _WIN32
        /* Replace all '\' with '/' for Windows paths */
        for (char *p = dest; *p != '\0'; p++) {
            if (*p == '\\') {
                *p = '/';
            }
        }
    #endif

    last_slash = strrchr(dest, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';  /* Null-terminate the path at the last slash */
    }
    return dest;
}

void axo_err_vprintf(const char* fmt, va_list vargs){
    #ifdef __EMSCRIPTEN__
        vprintf(fmt, vargs);
    #else
        vfprintf(stderr, fmt, vargs);
    #endif
}

void axo_err_printf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    axo_err_vprintf(fmt, args);
    va_end(args);
}

//Returns error string or null if everything went correctly
const char* axo_lua_dofile(axo_state* st, const char* lua_file, bool* ok){
    *ok = false;
    lua_State* L = st->lua_state;
    if (luaL_dofile(L, lua_file)) {
        return lua_tostring(L, -1);
    }
    *ok = true;
    return NULL;
}

char* axo_typ_to_lua(axo_typ t){
    char* s = NULL;
    char* res = NULL;
    switch (t.kind){
        case axo_simple_kind:
            return fmtstr("{primitive=\"%s\"}", t.simple.name);
            break;
        case axo_ptr_kind:
            s = axo_typ_to_lua(*axo_subtyp(t));
            res = fmtstr("{pointer=%s}", s);
            free(s);
            return res;
            break;
        default:
            return alloc_str("unknown");
            break;
    }
}

int axo_lua_dostring_with_source(lua_State *L, const char *code, const char *source_name) {
    int load_status = luaL_loadbuffer(L, code, strlen(code), source_name);
    if (load_status != LUA_OK) {
        return load_status;
    }
    int call_status = lua_pcall(L, 0, LUA_MULTRET, 0);
    return call_status;
}

const char* axo_lua_dostring(axo_state* st, const char* lua_code, bool* ok, const char* src_name){
    *ok = false;
    lua_State* L = st->lua_state;
    if (axo_lua_dostring_with_source(L, lua_code, src_name)) {
        return lua_tostring(L, -1);
    }
    if (lua_isstring(L, -1)) {
        *ok = true;
        return lua_tostring(L, -1);
    }else{
        //error! Expected string
        lua_pop(L, 1);
        return "Returned a non-string value!";
    }
}

axo_expr ret_expr;
axo_expr axo_parse_string_for_expr(axo_state* st, const char* code){
    char* parse_input = fmtstr("__AXO_EXPR_AS_PARSE_RESULT %s __AXO_ARTIFICIAL_EOF_TOKEN", code);
    yyscan_t lexer;
    yylex_init(&lexer);
    axo_new_string_source(st, parse_input);
    yyparse(lexer);
    // axo_pop_source(st);
    return ret_expr;
}

char* ret_declarations;
axo_decl axo_parse_string_for_decl(axo_state* st, const char* code){
    char* parse_input = fmtstr("%s __AXO_ARTIFICIAL_EOF_TOKEN", code);
    yyscan_t lexer;
    yylex_init(&lexer);
    axo_new_string_source(st, parse_input);
    yyparse(lexer);
    axo_pop_source(st);
    return (axo_decl){
        .kind=axo_comptime_block_decl_kind,
        .val=ret_declarations
    };
}

void axo_test_lua(axo_state* st){
    
}
