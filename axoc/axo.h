#ifndef AXO_H
#define AXO_H

#define AXO_VERSION "0.0.0"

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
#endif

#include <string.h>
#include <stdlib.h>
#include "./types.h"
#include "./axo_err.h"
#include "../util/utils.h"
#include "../axo_gram.tab.h"

#include <errno.h>
#include <dirent.h>

//YYLEX
extern FILE *yyin;
void yyrestart(FILE*);

long long int axo_easter_msg1[] = {2334956330867777876, 2338060278192697204, 8243113893085146979, 8297728800164421695, 7237125614924164640, 2339460887010487854, 7594793506165449313, 8030798189137847406, 7954880256880436589, 7310595013176488804, 2188385};

#define static_str_ptr(SZ) ((char**)(&((char[SZ]){})))  
#define s_str(SZ) ((char[SZ]){})

char* fmt_str(char* dest, const char fmt[], ...){
    va_list args;
    va_start(args, fmt);
    vsprintf(dest, fmt, args);
    va_end(args);
    return dest;
}

//Hashmap helpers
#define new_map(typ, hsh, comp) ((map)(hashmap_new(sizeof(typ), 0, 0, 0, hsh, comp, NULL, NULL)))

int map_cmp_vars(const void* a, const void* b, void *udata){return strcmp(((axo_var*)(a))->name, ((axo_var*)(b))->name); }
uint64_t map_hash_vars(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_var*)item)->name, strlen(((axo_var*)item)->name), seed0, seed1);}

int map_cmp_func(const void* a, const void* b, void *udata){return strcmp(((axo_func*)(a))->name, ((axo_func*)(b))->name); }
uint64_t map_hash_func(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_func*)item)->name, strlen(((axo_func*)item)->name), seed0, seed1);}

int map_cmp_module(const void* a, const void* b, void *udata){return strcmp(((axo_module*)(a))->name, ((axo_module*)(b))->name); }
uint64_t map_hash_module(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_module*)item)->name, strlen(((axo_module*)item)->name), seed0, seed1);}

int map_cmp_str(const void* a, const void* b, void *udata){return strcmp((char*)a, (char*)b); }
uint64_t map_hash_str(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(item, strlen((char*)item), seed0, seed1);}

int map_cmp_typ_def(const void* a, const void* b, void *udata){return strcmp(((axo_typ_def*)(a))->name, ((axo_typ_def*)(b))->name); }
uint64_t map_hash_typ_def(const void *item, uint64_t seed0, uint64_t seed1) {return hashmap_murmur(((axo_typ_def*)item)->name, strlen(((axo_typ_def*)item)->name), seed0, seed1);}

#define axo_mk_simple_typ(NAME, CNAME) ((axo_typ){.kind = axo_simple_kind, .simple = (axo_simple_t){.name=NAME, .cname=CNAME}})
#define axo_none_typ axo_mk_simple_typ("none", "void")
//Styles
#define axo_reset_style     "\x1B[0m"
#define axo_bold_style      "\x1B[1m"
#define axo_inverse_style   "\x1B[7m"
//Foreground colors
#define axo_black_fg        "\x1B[30m"
#define axo_red_fg          "\x1B[31m"
#define axo_green_fg        "\x1B[32m"
#define axo_yellow_fg       "\x1B[33m"
#define axo_blue_fg         "\x1B[34m"
#define axo_magenta_fg      "\x1B[35m"
#define axo_cyan_fg         "\x1B[36m"
#define axo_white_fg        "\x1B[37m"
//Background colors
#define axo_black_bg        "\x1B[40m"
#define axo_red_bg          "\x1B[41m"
#define axo_green_bg        "\x1B[42m"
#define axo_yellow_bg       "\x1B[43m"
#define axo_blue_bg         "\x1B[44m"
#define axo_magenta_bg      "\x1B[45m"
#define axo_cyan_bg         "\x1B[46m"
#define axo_white_bg        "\x1B[47m"
//Foreground strong colors
#define axo_black_fgs       "\x1B[90m"
#define axo_red_fgs         "\x1B[91m"
#define axo_green_fgs       "\x1B[92m"
#define axo_yellow_fgs      "\x1B[93m"
#define axo_blue_fgs        "\x1B[94m"
#define axo_magenta_fgs     "\x1B[95m"
#define axo_cyan_fgs        "\x1B[96m"
#define axo_white_fgs       "\x1B[97m"
//Background strong colors
#define axo_black_bgs       "\x1B[100m"
#define axo_red_bgs         "\x1B[101m"
#define axo_green_bgs       "\x1B[102m"
#define axo_yellow_bgs      "\x1B[103m"
#define axo_blue_bgs        "\x1B[104m"
#define axo_magenta_bgs     "\x1B[105m"
#define axo_cyan_bgs        "\x1B[106m"
#define axo_white_bgs       "\x1B[107m"
//Underline
#define axo_underline_start "\033[4m"
#define axo_underline_end "\033[0m"
#define axo_terminal_link(LINK, TEXT) "\e]8;;"LINK"\a"TEXT"\e]8;;\a"
#define axo_terminal_blink(TEXT) "\033[5m"TEXT"\033[0m"
#include "./asciiart.h" //ASCII art for the mascot!

#ifdef _WIN32
    #define axo_dir_sep "\\"
#else
    #define axo_dir_sep "/"
#endif
#define axo_dir_sep_char axo_dir_sep[0]
//Function declarations
//Yacc
int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
void yyerror(YYLTYPE*, const char *, ...);
int yyparse(void);

int asprintf(char **strp, const char *format, ...);

//State
axo_state* axo_new_state();
void axo_switch_input_file(axo_state* st, char* path);
char* axo_get_code(axo_state* st);
axo_typ_def* axo_set_typ_def(YYLTYPE* loc, axo_state* st, axo_typ_def td);
void axo_add_decl(axo_state* st, axo_decl d);
void axo_set_func(axo_state* st, axo_func fn);
axo_decl axo_func_def_to_decl(axo_func func);

//Scope
axo_scope* axo_new_scope();
void axo_add_statement(axo_scope* sc, axo_statement s);
axo_var* axo_set_var(axo_scope* sc, axo_var var);
axo_var* axo_get_var(axo_scope* sc, char* name);
axo_var* axo_del_var(axo_scope* sc, char* name);
char* axo_typ_to_str(axo_typ typ);
char* axo_typ_to_c_str(axo_typ t);
axo_statement axo_scope_to_statement(axo_scope* sc);

//Types
bool axo_typ_eq(axo_typ t1, axo_typ t2);
axo_typ_def* axo_set_typ_def(YYLTYPE* loc, axo_state* st, axo_typ_def td);
axo_typ_def* axo_get_typ_def(axo_state* st, char* name);
axo_typ axo_clean_typ(axo_typ typ);
bool axo_typ_valid_arr_index(axo_typ typ, axo_state* st);
char* axo_arr_access_to_str(YYLTYPE* arr_loc, axo_expr arr, YYLTYPE* index_loc, axo_index_access index);

//to string
char* axo_func_to_typ_str(axo_func* fn);
char* axo_typ_to_str(axo_typ typ);
char* axo_typ_to_ctyp_str(axo_typ typ);
char* axo_name_typ_decl(char* name, axo_typ typ);
char* axo_get_arr_name_typ_decl(axo_typ typ, char* name, int sz);
char* axo_get_var_decl_assign(YYLTYPE* loc, char* name, axo_expr expr);
char* axo_typ_to_c_str(axo_typ t);
char* axo_typ_def_val(axo_typ typ);
char* axo_c_arr_of_typ(axo_typ typ, char* inside);
char* axo_typ_kind_to_str(axo_typ_kind tk);

//Functions
axo_expr axo_call_to_expr(axo_func_call cl);

//Structs
int axo_get_struct_field_index(axo_struct* structure, char* name);

//Loops
char* axo_for_loop_to_str(axo_for_loop lp);

//Misc
int (*axo_printf)(const char* fmt, ...);
int axo_no_printf(const char* fmt, ...){return 0;}
char* fmtstr(const char fmt[], ...);
char* tmpfmtstr(const char fmt[], ...);
char* axo_file_to_str(char* path);
char* repstr(char* str, int times);
const char* axo_identifier_kind_to_str(axo_identifier_kind kind);
void* axo_safe_malloc(size_t n);

//Files
int axo_chdir(char* path);
bool axo_dir_exists(char* dir_path);
bool axo_file_exists(char* file_path);
char* axo_resolve_path(char* filename);
char* axo_get_exec_path(char* buf, int sz);
char* axo_get_parent_dir(char* path);
char* axo_strip_file_extension(char* filename);
void axo_bytes_to_file(const char *filename, char* bytes, size_t size);

char* fmtstr(const char fmt[], ...){
    char* ret;
    va_list args;
    va_start(args, fmt);
    int r = vasprintf(&ret, fmt, args);
    va_end(args);
    if (r<0)
        printf("fmtstr error! Returned '%d'!\n", r);
    return ret;
}

char* axo_get_typ_default(axo_typ typ){
    if (typ.def != NULL) return (char*)(typ.def);
    switch(typ.kind){
        case axo_arr_kind:
            return "AXO_NULL_ARR";
            break;
        case axo_func_kind:
        case axo_ptr_kind:
            return "NULL";
            break;
        default:
            yyerror(NULL, "Couldn't get default type for kind %s.", axo_typ_kind_to_str(typ.kind));
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
            fread(str, sizeof(char), len, file);
        }
        fclose(file);
    }
    str[len] = '\0';
    if (!(str && file)) return (char*)NULL;
    return str;
}

#define axo_new_numeric_typ(ST, NAME, CNAME, DEF) axo_set_typ_def(NULL, ST, (axo_typ_def){.name=NAME, .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name=NAME, .cname=CNAME}, .def=DEF}});

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
    st->float_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="f32", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="f32", .cname="float"}, .def="0.0"}});
    st->byte_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="byte", .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name="byte", .cname="char"}, .def="((char)0)"}});
    // st->str_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="AXO_STRING_TYP", .typ=(axo_typ){.kind=axo_arr_kind, .arr=new_struct_lit_ptr(axo_arr_typ, axo_arr_typ*, ((axo_arr_typ){.subtyp=axo_byte_typ(st), .dim_count=1})), .def="\"\""}});
    st->str_def = axo_set_typ_def(NULL, st, (axo_typ_def){.name="AXO_STRING_TYP", .typ=(axo_typ){.kind=axo_ptr_kind, .def="\"\""}});
    st->str_def->typ.subtyp = &axo_byte_typ(st);
    //Other types
    axo_new_numeric_typ(st, "f64", "double", "0.0");
    axo_new_numeric_typ(st, "i16", "short int", "0");
    axo_new_numeric_typ(st, "i64", "long long int", "0");
    axo_new_numeric_typ(st, "u16", "short unsigned", "0");
    axo_new_numeric_typ(st, "u64", "long long unsigned", "0");
    //File related
    st->root_path = root_path;
    st->sources = NULL;
    st->sources_len = 0;
    st->entry_file = NULL;
    st->entry_point = NULL;
    st->output_file = NULL;
    st->output_c_file = NULL;
    //Modules
    st->modules = new_map(axo_module, map_hash_module, map_cmp_module);
    st->module_names = NULL;
    st->modules_len = 0;
    //Misc
    st->silenced = false;
    st->run = false;
    return st;
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
        yyerror(NULL, "Expected at least one more argument after: %s", argv[arg_num-1]); \
        return; \
    } \
    arg; \
})

void axo_handle_args(axo_state* st, int argc, char** argv, int init_arg){
    int arg_num = init_arg;
    char* arg = argv[init_arg];
    while (arg != NULL){
        // printf("Got arg #%d: %s\n", arg_num, arg);
        if (strcmp(arg, "-e")==0){ //Set entry point
            next_arg;
            if (st->entry_point == NULL)
                st->entry_point = arg;
            else
                yyerror(NULL, "Cannot set entry point to '%s' after it was already set to '%s'.", arg, st->entry_point);
        }else if (strcmp(arg, "-r")==0 || strcmp(arg, "run") == 0){ //Silence compiler's printfs
            st->run = true;
        }else if (strcmp(arg, "-s")==0){ //Silence compiler's printfs
            st->silenced = true;
        }else if (strcmp(arg, "-o")==0){ //Set output file name
            next_arg;
            if (st->output_file == NULL)
                st->output_file = arg;
            else
                yyerror(NULL, "Cannot set output file name to '%s' after it was already set to '%s'.", arg, st->output_file);
        }else if (strcmp(arg, "-oc")==0){ //Set output c file name
            next_arg;
            if (st->output_c_file == NULL)
                st->output_c_file = arg;
            else
                yyerror(NULL, "Cannot set output c file name to '%s' after it was already set to '%s'.", arg, st->output_c_file);
        }else{//Set entry file
            if (st->entry_file == NULL)
                st->entry_file = arg;
            else
                yyerror(NULL, "Cannot set entry file to '%s' after it was already set to '%s'.", arg, st->entry_file);
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
                yyerror(expr_loc, "Field not supported for %dd arays yet.");
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
            yyerror(field_loc, "Field not yet supported for %dd arrays!");
    }else{
        yyerror(field_loc, "Invalid array field.");
    }
    return (axo_expr){};
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
            yyerror(name_loc, "Method not yet supported for %dd arrays!", arr_typ.dim_count);
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
            yyerror(expr_loc, "Method unsupported for %dd arrays yet!", arr_typ.dim_count);
        return ret;
    }else{
        yyerror(name_loc, "Undefined array method.");
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
            vasprintf(&str, fmt, args);
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
            vasprintf(&str, fmt, args);
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
    printf(axo_get_color_esc(index, col_sup));
    vprintf(fmt, args);
    printf(axo_reset_style);
    va_end(args);
}

void axo_print_config(axo_state* st){
    axo_compiler_config cfg = st->config;
    axo_color_support_kind col_sup = axo_col_sup(st);
    int col_count = axo_color_count(col_sup);
    int seed = rand() % col_count;
    printf(axo_get_color_esc(28, col_sup));
    if (col_sup == axo_no_color_support_kind)
        system(fmt_str((char[axo_max_path_len]){},"%s"axo_dir_sep"printmoji"AXO_BIN_EXT, st->root_path));
    else
        system(fmt_str((char[axo_max_path_len]){},"%s"axo_dir_sep"printcolmoji"AXO_BIN_EXT, st->root_path));
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
    src->path = alloc_str(path);
    src->parent_dir = alloc_str(axo_get_parent_dir(axo_resolve_path(path)));
    src->file = fopen(src->path, "rb");
    src->pos = 0;
    src->line = 1;
    src->col = 1;
    axo_chdir(src->parent_dir);
    if (!(src->file))
        perror("fopen");
    yyrestart(src->file);
    st->sources_len++;
    // printf("Switched to file: '%s'\n", src->path);
}

void axo_pop_source(axo_state* st){
    st->sources_len--;
    // printf("INPUT LEN: %d\n", st->sources_len);
    // printf("Input '%s' ended, ", st->sources[st->sources_len].path);
    // free(st->sources[st->sources_len].path);
    // fclose(st->sources[st->sources_len].file);
    if (st->sources_len>0){
        axo_source* src = &(st->sources[st->sources_len-1]);
        fseek(src->file, src->pos, SEEK_SET);
        axo_chdir(src->parent_dir);
        yyrestart(src->file);
        // printf("switching to '%s':%ld\n", src->path, ftell(yyin));
    }else{
        printf("all sources ended. (this should never happen)\n");
    }
}

axo_decl axo_include_file(axo_state* st, YYLTYPE* loc, char* filename, bool str_lit){
    char str[axo_max_path_len];
    if (str_lit){
        strcpy(str, &(filename[1]));
        str[strlen(str)-1] = '\0';
    }else{
        strcpy(str, filename);
    }
    // printf("include %s\n", str);
    // printf("Checking for '%s'\n", str);
    //Check local first
    bool exists = axo_file_exists(str);
    if (exists){
      // printf("Found!\n");
      axo_new_source(st, str);
    }else{
      yyerror(loc, "Couldn't find '%s'.\n", str);
    }
    return (axo_decl){.val=fmtstr("//including '%s'", str), .kind=axo_use_decl_kind};
}

axo_decl axo_use_module(axo_state* st, YYLTYPE* loc, char* name){
    // printf("use %s\n", name);
    // printf("Searching for dir...\n");
    //Check local first
    char path[axo_max_path_len];
    bool found = false;
    strcpy(path, name);

    if (!(found = axo_dir_exists(path))){
        sprintf(path, "%s"axo_dir_sep"modules"axo_dir_sep"%s", st->root_path, name);
        if (!(found = axo_dir_exists(path))){
            yyerror(loc, "Couldn't find module '%s'.", name);
        }
    }
    if (found){
        strcat(path, axo_dir_sep);
        strcat(path, name);
        strcat(path, ".axo");
        // printf("Found the folder, searching for the file:\n%s\n", path);
        if (axo_file_exists(path))
            axo_include_file(st, loc, path, false);
        else
            yyerror(loc, "No entry file for module. Missing '%s.axo' in module directory?", name);
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
        .scope = axo_new_scope(NULL)
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
    axo_typ_def* atd = hashmap_get(st->types_def, &td);
    if (atd == NULL){
        new_ptr_one(ptr, axo_typ_def);
        *ptr = td;
        hashmap_set(st->types_def, ptr);
        return ptr;
    }else
        yyerror(loc, "'%s' already defined as '%s'", td.name, atd->name); //FIX!!!
    return NULL;
}

axo_typ_def* axo_get_typ_def(axo_state* st, char* name){
    axo_typ_def placeholder = (axo_typ_def){.name=name};
    return hashmap_get(st->types_def, &placeholder);
}

axo_scope* axo_new_scope(axo_scope* parent){
    new_ptr_one(sc, axo_scope);
    sc->statements = NULL;
    sc->statements_len = 0;
    sc->parent = parent;
    sc->variables = new_map(axo_var, map_hash_vars, map_cmp_vars);
    sc->def_iter = (parent==NULL ? 0 : parent->def_iter);
    sc->parent_func = NULL;
    return sc;
}

const char* axo_identifier_kind_to_str(axo_identifier_kind kind){
    switch(kind){
        case axo_identifier_var_kind: return "variable"; break;
        case axo_identifier_module_kind: return "module"; break;
        case axo_identifier_typ_kind: return "type"; break;
        default: return "!!!"; break;
    }
}

void axo_add_decl(axo_state* st, axo_decl d){
    resize_dyn_arr_if_needed(axo_decl, st->decls, st->decls_len, axo_decls_cap);
    st->decls[st->decls_len++] = d;
}

void axo_add_statement(axo_scope* sc, axo_statement s){
    resize_dyn_arr_if_needed(axo_statement, sc->statements, sc->statements_len, axo_statements_cap);
    sc->statements[sc->statements_len++] = s;
}

axo_var* axo_set_var(axo_scope* sc, axo_var var){
    // printf("'%s' of type '%s'\n", var.name, axo_typ_to_str(var.typ));
    new_ptr_one(ptr, axo_var);
    *ptr = var;
    hashmap_set(sc->variables, ptr);
    return ptr;
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
    char* ret = (char[1024]){};
    axo_func_typ fnt;
    int i;
    char dim_stars[128];
    switch (typ.kind){
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
            yyerror(NULL, "Unsupported axo_c_arr_of_typ type '%s'!", axo_typ_to_str(typ));
            return alloc_str("unsupported_type");
    }
}

char* axo_typ_to_c_str(axo_typ t){
    axo_typ cur_typ = t;
    axo_func_typ fnt = (axo_func_typ){};
    char* ret = "";
    int ptr_lvl = 0;
    char* stars = "";
    switch(t.kind){
        case axo_simple_kind:
            return alloc_str(t.simple.cname);
            break;
        case axo_func_kind:
            fnt = *((axo_func_typ*)(t.func_typ));
            ret = fmtstr("%s(*)(", axo_typ_to_c_str(fnt.ret_typ));
            for (int i = 0; i<fnt.args_len; i++){
                if (i>0) strapnd(&ret, ",");
                strapnd(&ret, axo_typ_to_c_str(fnt.args_types[i]));
            }
            strapnd(&ret, ")");
            return ret;
            break;
        case axo_arr_kind:
            return alloc_str("axo__arr"); break;
        case axo_ptr_kind:
            while(cur_typ.kind==axo_ptr_kind){
                ptr_lvl++;
                cur_typ = *axo_subtyp(cur_typ);
            }
            stars = (char*)malloc(ptr_lvl+1);
            for(int i=0; i<ptr_lvl; i++) stars[i] = '*';
            stars[ptr_lvl] = '\0';
            switch(cur_typ.kind){
                case axo_simple_kind:
                    asprintf(&ret, "%s%s", cur_typ.simple.cname, stars);
                    return ret;
                    break;
                case axo_struct_kind:
                    asprintf(&ret, "%s%s", ((axo_struct*)(cur_typ.structure))->name, stars);
                    return ret;
                    break;
                case axo_arr_kind:
                    asprintf(&ret, "axo__arr%s", stars);
                    return ret;
                    break;
                case axo_func_kind:
                    fnt = *((axo_func_typ*)(cur_typ.func_typ));
                    ret = fmtstr("%s(*%s)(", axo_typ_to_c_str(fnt.ret_typ), stars);
                    for (int i = 0; i<fnt.args_len; i++){
                        if (i>0) strapnd(&ret, ",");
                        strapnd(&ret, axo_typ_to_c_str(fnt.args_types[i]));
                    }
                    strapnd(&ret, ")");
                    return ret;
                    break;
                default:
                    yyerror(NULL, "Couldn't create a string for pointer of that kind '%s'", axo_typ_kind_to_str(cur_typ.kind));
            }
            break;
        case axo_struct_kind:
            return ((axo_struct*)t.structure)->name;
            break;
        case axo_no_kind:
            return alloc_str("no_kind_typ");
            break;
        default: 
            return alloc_str("unhandled_typ");
            break;
    }
    return alloc_str("unknown_typ");
}

char* axo_name_typ_decl(char* name, axo_typ typ){ //Fix arr, ptr, func
    char* ret = NULL;
    axo_func_typ fnt = (axo_func_typ){};
    switch(typ.kind){
        case axo_simple_kind: return fmtstr("%s %s", axo_typ_to_c_str(typ), name); break;
        case axo_struct_kind: return fmtstr("%s %s", ((axo_struct*)(typ.structure))->name, name); break;
        case axo_enum_kind: return fmtstr("%s %s", ((axo_enum*)(typ.enumerate))->name, name); break;
        case axo_arr_kind: return fmtstr("axo__arr %s", name); break;
        case axo_func_kind:
            fnt = *((axo_func_typ*)(typ.func_typ));
            ret = fmtstr("%s(*%s)(", axo_typ_to_c_str(fnt.ret_typ), name);
            for (int i = 0; i<fnt.args_len; i++){
                if (i>0) strapnd(&ret, ",");
                strapnd(&ret, axo_typ_to_c_str(fnt.args_types[i]));
            }
            strapnd(&ret, ")");
            return ret;
            break;
        case axo_ptr_kind:
            switch(axo_subtyp(typ)->kind){
                case axo_ptr_kind:
                case axo_simple_kind:
                case axo_enum_kind:
                case axo_struct_kind:
                    return fmtstr("%s %s", axo_typ_to_c_str(typ), name);
                    break;
                default:
                    yyerror(NULL, "Unsupported pointer type in axo_name_typ_decl (%s).", axo_typ_kind_to_str(typ.kind));
                    return fmtstr("Unsupported pointer type (pointing to %s)", axo_typ_to_str(*axo_subtyp(typ)));
                    break;
            }
            break;
        default: break;
    }
    return alloc_str("typ name decl");
}

axo_decl axo_func_def_to_decl(axo_func func){
    char* name = strcmp(func.name, "main") == 0 ? "axo__main" : func.name;
    // int sz = strlen(axo_typ_to_str(func.f_typ.ret_typ))+strlen(name)-(func.f_typ.args_len>0?1:0) + 4;    
    // for (int i = 0; i<func.f_typ.args_len; i++)
    //     sz = sz + strlen(axo_typ_to_str(func.f_typ.args_types[i])) + strlen(func.args_names[i]) + 2;
    // char* str = (char*)malloc(sz*sizeof(char));
    char* str = alloc_str(axo_typ_to_c_str(func.f_typ.ret_typ));
    // strcpy(str, axo_typ_to_c_str(func.f_typ.ret_typ));
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
    for (int i = 0; i<func.f_typ.args_len; i++)
        axo_del_var(func.body, func.args_names[i]);
    strapnd(&str, axo_scope_to_statement(func.body).val);
    return (axo_decl){.kind=axo_func_decl_kind, .val=str};
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
            yyerror(index_loc, "Indexing arrays above 3 dimensions is not yet implemented.");
            return alloc_str("invalid_array_access");
            break;
    }
}

bool axo_typ_valid_arr_index(axo_typ typ, axo_state* st){
    if (typ.kind != axo_simple_kind) return false;
    if (axo_typ_eq(typ, axo_int_typ(st))) return true;
    return false;
}

char* axo_typ_def_val(axo_typ typ){
    //Fix: Add default function value
    switch (typ.kind){
        case axo_func_kind: return "default_function_value"; break;
        default: return (char*)(typ.def); break;
    }
}

axo_typ axo_clean_typ(axo_typ typ){
    axo_typ new_typ = typ;
    switch(typ.kind){
        case axo_func_kind:
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
    //Generate rest of the code
    //Load args
    char* ret = empty_str;
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
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
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
    int dims = 0;
    switch(t.kind){
        case axo_simple_kind:
            return alloc_str(t.simple.cname);
            break;
        case axo_ptr_kind:
        case axo_arr_kind:
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
                yyerror(&(((YYLTYPE*)(lp->locs))[1]), "Cannot iterate over %d dimensional array with a %d dimensional index.", arr_typ.dim_count, lp->dim_count);
            //Only create specified indexes
            if (lp->value_iter.data == NULL){
                for(int i=0; i<lp->dim_count; i++){
                    axo_expr iter = lp->dim_iters[i];
                    if (iter.lval_kind == axo_var_lval_kind && iter.typ.kind == axo_no_kind){
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter.val, .is_const=false});
                        lp->iter_over[i] = true;
                    }else if (lp->dim_iters[i].val == NULL){
                        lp->iter_over[i] = false;
                    }else if (!axo_typ_valid_arr_index(iter.typ, state)){
                        yyerror(&(((YYLTYPE*)(lp->locs))[i+3]), "Cannot index array with type '%s'.", axo_typ_to_str(iter.typ));
                    }
                }
            //Create all needed indexes, even those not specified
            }else{
                for(int i=0; i<lp->dim_count; i++){
                    axo_expr iter = lp->dim_iters[i];
                    if (iter.lval_kind == axo_var_lval_kind && iter.typ.kind == axo_no_kind){
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter.val, .is_const=false});
                        lp->iter_over[i] = true;
                    }else if (lp->dim_iters[i].val == NULL){
                        char* iter_name = fmtstr("axo__it%dd%d", i, loop_count);
                        axo_set_var(scope, (axo_var){.typ = axo_int_typ(state), .name = iter_name, .is_const=false});
                        lp->dim_iters[i] = (axo_expr){.typ=axo_int_typ(state), .val=iter_name};
                        lp->iter_over[i] = true;
                    }else if (!axo_typ_valid_arr_index(iter.typ, state)){
                        yyerror(&(((YYLTYPE*)(lp->locs))[i+3]), "Cannot index array with type '%s'.", axo_typ_to_str(iter.typ));
                    }else{
                        lp->iter_over[i] = false;
                    }
                }
                //Finally, create the value iterator
                axo_set_var(scope, (axo_var){.typ = arr_typ.subtyp, .name = lp->value_iter.data, .is_const=false});
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
                strapnd(&val, axo_get_var_decl_assign(NULL, lp.value_iter.data, (axo_expr){.typ=arr_typ.subtyp, .val=arr_at_str}));
                strapnd(&val, ";");
                free(arr_at_str);
            }
            strapnd(&val, lp.body);
            strapnd(&val, "}");
            break;
        default:
            yyerror(&(((YYLTYPE*)(lp.locs))[2]), "Each cannot iterate over '%s' type values.", axo_typ_kind_to_str(lp.collection.typ.kind));
            break;
    }
    return (axo_statement){
        .kind=axo_each_statement_kind,
        .val=val
    };
}

char* axo_get_var_decl_assign(YYLTYPE* pos, char* name, axo_expr expr){
    axo_typ typ = expr.typ;
    axo_func_typ f_typ;
    char* ret = NULL;
    switch(typ.kind){
        case axo_enum_kind:
            return fmtstr("%s %s=%s", ((axo_enum*)(typ.enumerate))->name, name, expr.val); break;
        case axo_simple_kind:
            return fmtstr("%s %s=%s", typ.simple.cname, name, expr.val); break;
        case axo_struct_kind:
            return fmtstr("%s %s=%s", ((axo_struct*)(typ.structure))->name, name, expr.val); break;
        case axo_arr_kind:
            return fmtstr("axo__arr %s = %s", name, expr.val); break;
        case axo_ptr_kind:
            //FIX: This doesn't always work. Example: function pointers
            return fmtstr("%s %s = %s", axo_typ_to_c_str(typ), name, expr.val); break;
        case axo_func_kind:
            f_typ = *((axo_func_typ*)(typ.func_typ));
            ret = alloc_str(axo_typ_to_c_str(f_typ.ret_typ));
            strapnd(&ret, "(*");
            strapnd(&ret, name);
            strapnd(&ret, ")(");
            for (int i=0; i<f_typ.args_len; i++){
                if (i>0) strapnd(&ret, ",");
                strapnd(&ret, axo_typ_to_c_str(f_typ.args_types[i]));
            }
            strapnd(&ret, ")=");
            strapnd(&ret, expr.val);
            return ret;
            break;
        default:
            yyerror(pos, "Type assign declaration not yet supported for this (%s) kind!", axo_typ_kind_to_str(typ.kind));
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
        default: return "unknown_kind"; break;
    }
    return "undefined kind";
}


bool axo_typ_eq(axo_typ t1, axo_typ t2){ //FIX!
    if (t1.kind != t2.kind) return false;
    axo_arr_typ a1, a2;
    axo_func_typ* fnt1;
    axo_func_typ* fnt2;
    switch(t1.kind){
        case axo_simple_kind: return !(strcmp(t1.simple.cname, t2.simple.cname)); break;
        case axo_enum_kind: return t1.enumerate == t2.enumerate; break;
        case axo_struct_kind: return t1.structure == t2.structure; break;
        case axo_ptr_kind:
            return axo_typ_eq(*((axo_typ*)(t1.subtyp)), *((axo_typ*)(t2.subtyp)));
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
    yyerror(NULL, "Couldn't tell if type kinds '%s' and '%s' are equal or not", axo_typ_kind_to_str(t1.kind), axo_typ_kind_to_str(t2.kind));
    return true;
}

bool axo_is_no_typ(axo_typ typ){
    return typ.kind == axo_no_kind;
}

bool is_simple_typ_eq(axo_typ t1, char* t2){
    return (t1.kind == axo_simple_kind) && (strcmp(t1.simple.cname, t2) == 0);
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
    bool e_ascii = st->config.extended_ascii;
    //Produce the error string from fmt and args
    char* line_num;
    //Add position and context to the error message
    char* code = axo_file_to_str(axo_source(st)->path);
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
    char* full_filepath = axo_resolve_path(axo_source(st)->path);
    asprintf(&ret, axo_green_fgs axo_terminal_link("file://%s","%s") axo_reset_style axo_cyan_fgs " %c" axo_blue_fgs " %u:%u" axo_cyan_fgs " -> " axo_red_fgs axo_terminal_link("%s","ERROR: %s") "\n" axo_reset_style, full_filepath, axo_source(st)->path, axo_symbol(axo_arrow_symbol, e_ascii), loc->first_line, loc->first_column, website, msg);
    while (line<=loc->last_line+down_lines){
      if (code[i] == '\0') break;
      else if (col == loc->first_column && line == loc->first_line){
        char c = code[i];
        code[i] = '\0';
        line_num = itoa_spaced(line);
        asprintf(&ret, "%s" axo_red_fgs axo_terminal_blink("->%s") axo_cyan_fg " %c" axo_white_fg " %s", ret, line_num, axo_symbol(axo_vertical_line_symbol, e_ascii), &(code[last_i]));
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
            asprintf(&ret, "%s" axo_yellow_fgs "  %s" axo_cyan_fgs " %c" axo_white_fgs " %s\n", ret, line_num, axo_symbol(axo_vertical_line_symbol, e_ascii), &(code[last_i]));   
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

void axo_bytes_to_file(const char *filename, char* bytes, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(bytes, sizeof(char), size, file);
        fclose(file);
    } else {
        printf("Failed to open the file %s\n", filename);
    }
}

char* axo_file_to_bytes(const char *filename, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open the file %s\n", filename);
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
        char ret[axo_max_path_len];
        return alloc_str(realpath(filename, ret));
    }
#elif __APPLE__ 
    char* axo_resolve_path(char* filename){
        return filename;
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
        return 0;
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
#endif

#ifdef _WIN32

#elif __linux
    char* axo_cwd(char* dest, size_t sz){
        if (getcwd(dest, sz) == NULL)
            perror("axo_cwd() error");
        return dest;
    }

#elif __APPLE__

#endif

char* axo_get_parent_dir(char* path) {
    char *last_slash;
    #ifdef _WIN32
        /* Replace all '\' with '/' for Windows paths */
        for (char *p = path; *p != '\0'; p++) {
            if (*p == '\\') {
                *p = '/';
            }
        }
    #endif

    last_slash = strrchr(path, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';  /* Null-terminate the path at the last slash */
    }
    return path;
}

#endif
