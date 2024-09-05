#ifndef AXO_TYPES_H
#define AXO_TYPES_H

typedef struct hashmap* map;

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
#elif __EMSCRIPTEN__
    #include <emscripten.h>
    #include <emscripten/html5.h>
#endif

#include <stdbool.h>
#include <string.h>
#include "./axo_err.h"
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>

//Define YYLTYPE
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
#define axo_max_path_len 2048

//Memory management values
#define axo_scopes_cap 32
#define axo_scopes_table_cap 8
#define axo_decls_cap 128
#define axo_statements_cap 128
#define axo_func_args_cap 128
#define axo_tok_locations_cap 1024
#define axo_enum_names_cap 32
#define axo_types_def_cap 16
#define axo_stat_arr_literal_cap 16
#define axo_strings_cap 1024
#define axo_empty_arr_lit_cap 128
#define axo_index_access_cap 128
#define axo_state_sources_cap 32
#define axo_modules_cap 16
#define axo_switch_expr_list_cap 16
#define axo_cases_cap 16
#define axo_c_sources_cap 16
#define axo_cc_flags_len 16

#ifdef __WIN32
    #define AXO_BIN_EXT ".exe"
#else
    #define AXO_BIN_EXT ""
#endif

//Function declarations
typedef enum axo_typ_kind{
    axo_simple_kind,
    axo_func_kind,
    axo_arr_kind,
    axo_ptr_kind,
    axo_enum_kind,
    axo_struct_kind,
    axo_no_kind,
    axo_c_arg_list_kind,
    axo_map_kind,
    axo_none_kind,
    axo_module_kind,
    axo_literal_kind
}axo_typ_kind;

#define axo_subtyp(T) ((axo_typ*)(T.subtyp))
#define axo_get_arr_typ(T) (*((axo_arr_typ*)(T.arr)))

typedef enum axo_include_path_kind{
    axo_local_include_path_kind,
    axo_global_include_path_kind
}axo_include_path_kind;

typedef struct axo_strings {
    char**        strs;
    int           len;
}axo_strings;

#define axo_new_strings(LEN) ((axo_strings){.strs=(char**)malloc((LEN)*sizeof(char*)), .len=0})
#define axo_empty_strings axo_new_strings(axo_strings_cap)
#define new_struct_lit_ptr(TYP, PTYP, LIT) ({ \
    PTYP RET_PTR = (PTYP)malloc(sizeof(TYP)); \
    *RET_PTR = LIT; \
    RET_PTR; \
})

typedef struct axo_simple_t{
    char*        name;
    char*        cname;
}axo_simple_t;
#define axo_mk_simple_typ(NAME, CNAME) ((axo_typ){.kind = axo_simple_kind, .simple = (axo_simple_t){.name=NAME, .cname=CNAME}})
#define axo_new_numeric_typ(ST, NAME, CNAME, DEF) axo_set_typ_def(NULL, ST, (axo_typ_def){.name=NAME, .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name=NAME, .cname=CNAME}, .def=DEF}});

typedef struct axo_typ {
    axo_typ_kind       kind;
    union {
        axo_simple_t    simple;
        void*           subtyp;
        void*           func_typ;
        void*           enumerate;
        void*           structure;
        void*           arr;
        void*           map;
    };
    void*              def;
    bool               is_const;
    bool               is_volatile;
}axo_typ;

#define axo_no_typ ((axo_typ){.kind=axo_no_kind, .def=NULL})
#define axo_none_typ ((axo_typ){.kind=axo_none_kind, .def=NULL})
#define axo_none_ptr_typ ((axo_typ){.kind=axo_ptr_kind, .subtyp=&axo_none_typ,.def=NULL})

typedef struct axo_arr_typ{
    axo_typ    subtyp;
    int        dim_count;
}axo_arr_typ;

typedef struct axo_types_list{
    axo_typ*           values;
    int                len;
}axo_types_list;

typedef enum axo_expr_kind{
    axo_expr_normal_kind,
    axo_expr_enum_typ_kind,
    axo_expr_assigned_declaration_kind
}axo_expr_kind;

typedef enum axo_lval_kind{
    axo_var_lval_kind,
    axo_other_lval_kind,
    axo_not_lval_kind
}axo_lval_kind;

typedef struct axo_expr{
    axo_expr_kind          kind;
    axo_lval_kind          lval_kind;
    char*                  val;
    axo_typ                typ;
}axo_expr;

typedef enum axo_identifier_kind{
    axo_identifier_var_kind,
    axo_identifier_module_kind,
    axo_identifier_typ_kind,
    axo_no_identifier_kind
}axo_identifier_kind;

typedef struct axo_typ_def {
    char*             name;
    axo_typ           typ;
}axo_typ_def;


typedef struct axo_identifier {
    axo_identifier_kind    kind;
    union {
        axo_typ_def        typ_def;
        void*              data;
    };
}axo_identifier;

typedef struct axo_func_arg{
    char*           name;
    char*           def;
    axo_typ         typ;
}axo_func_arg;

typedef enum axo_statement_kind{
    axo_assignment_statement_kind,
    axo_call_statement_kind,
    axo_if_statement_kind,
    axo_if_else_statement_kind,
    axo_while_statement_kind,
    axo_for_statement_kind,
    axo_each_statement_kind,
    axo_ret_statement_kind,
    axo_scope_statement_kind,
    axo_incr_decr_statement_kind,
    axo_continue_statement_kind,
    axo_break_statement_kind,
    axo_stat_arr_init_statement_kind,
    axo_var_is_decl_statement_kind,
    axo_expr_statement_kind,
    axo_switch_statement_kind,
    axo_defer_statement_kind,
    axo_empty_statement_kind,
    axo_no_statement_kind
}axo_statement_kind;

typedef struct axo_statement{
    axo_statement_kind    kind;
    char*                 val;
}axo_statement;

#define axo_no_statement ((axo_statement){.kind=axo_no_statement_kind, .val=""})

typedef enum axo_decl_kind{
    axo_enum_decl_kind,
    axo_struct_decl_kind,
    axo_func_def_decl_kind,
    axo_func_decl_decl_kind,
    axo_use_decl_kind,
    axo_c_include_decl_kind,
    axo_c_register_decl_kind,
    axo_module_info_decl_kind,
    axo_assign_decl_kind,
    axo_is_decl_kind,
    axo_typ_def_decl_kind,
    axo_other_decl_kind,
    axo_c_code_decl_kind,
    axo_typedef_decl_kind
}axo_decl_kind;

typedef struct axo_decl {
    axo_decl_kind    kind;
    char*            val;
}axo_decl;

typedef struct axo_scope{
    axo_statement* statements;     //Statements in the scope
    int            statements_len; //Length of statments
    map            variables;      //Variables declared in the scope
    void*          parent;         //Pointer to the parent scope (or NULL for global scope)
    
    void*          to_global;      //Pointer to global scope (for global scopes, else NULL)
    void*          parent_func;    //Pointer to the function (else NULL)
    bool           defer_used;
}axo_scope;

typedef struct axo_scopes{
    axo_scope**    scopes;
    int             len;
}axo_scopes;

typedef struct axo_var{
    char*                  name;
    axo_typ                typ;
}axo_var;

typedef enum axo_storage_qualifier {
    axo_default_storage_qualifier,
    axo_auto_storage_qualifier,
    axo_register_storage_qualifier,
    axo_static_storage_qualifier,
    axo_extern_storage_qualifier
}axo_storage_qualifier;

typedef struct axo_simple_typ{
    char*        name;
    char*        def;
}axo_simple_typ;

typedef enum axo_cc_kind{
    axo_gcc_cc_kind,
    axo_tcc_cc_kind,
    axo_clang_cc_kind
}axo_cc_kind;

typedef enum axo_color_support_kind{
    axo_no_color_support_kind,
    axo_limited_color_support_kind,
    axo_full_color_support_kind
}axo_color_support_kind;

typedef struct axo_compiler_config{
    axo_cc_kind               cc;
    bool                      keep_c;
    bool                      timer;
    bool                      bug_hunter;
    axo_color_support_kind    color_support;
    bool                      extended_ascii;
}axo_compiler_config;

typedef struct axo_source{
    char*            path;
    char*            parent_dir;
    FILE*            file;
    long             pos;
    int              line;
    int              col;
    int              index;
}axo_source;

#define axo_source(ST) (&(ST->sources[ST->sources_len-1]))
#define axo_line(ST) (axo_source(ST)->line)
#define axo_col(ST) (axo_source(ST)->col)
#define axo_pos(ST) (axo_source(ST)->pos)
#define axo_src_path(ST) (axo_source(ST)->path)
#define axo_src_file(ST) (axo_source(ST)->file)
#define axo_src_index(ST) (axo_source(ST)->index)

typedef struct axo_module{
    char*        name;
    char*        prefix;
    char*        version;
    char*        author;
    // char**       contributors
    char*        website;
    char*        license_name;
    char*        license;
    char*        description;
    axo_scope*   scope;
}axo_module;

typedef struct axo_state{
    axo_decl*              decls;            //Declarations
    int                    decls_len;        //Length of declarations
    axo_scope*             global_scope;     //Global scope
    axo_scope**            scopes_table;     //All scopes
    
    map                    types_def;        //Type definitions
    
    axo_compiler_config    config;           //Config from file

    //Default types
    axo_typ_def*           int_def;
    axo_typ_def*           u32_def;
    axo_typ_def*           bool_def;
    axo_typ_def*           f32_def;
    axo_typ_def*           byte_def;
    axo_typ_def*           str_def;

    //File related
    char*                  orig_cwd;            //Original working directory
    char*                  root_path;           //Compiler root path (compiler's parent dir)
    axo_source*            sources;             //Code sources
    int                    sources_len;         //Code sources length
    char*                  entry_file;          //Path to entry file (NULL if none)
    char*                  entry_point;         //Entry point (function name), defaults to axo__main
    char*                  output_file;         //Binary output path
    char*                  output_c_file;       //C output path (deleted by default)
    char**                 extra_c_sources;     //Sources pointed by #source directive
    int                    extra_c_sources_len; //Length of extra C sources
    char*                  input_str;           //Input string (defaults to NULL)
    int                    input_str_index;
    map                    included_files;

    //Modules
    map                    modules;
    char**                 module_names;
    int                    modules_len;
    int                    modules_decl;
    bool                   in_core;
    //Misc
    bool                   silenced;
    bool                   run;
    char**                 cc_flags;
    int                    cc_flags_len;
}axo_state;

#define axo_col_sup(ST) (ST->config.color_support)

#define axo_int_typ(STATE) (STATE->int_def->typ)
#define axo_u32_typ(STATE) (STATE->u32_def->typ)
#define axo_float_typ(STATE) (STATE->f32_def->typ)
#define axo_byte_typ(STATE) (STATE->byte_def->typ)
#define axo_bool_typ(STATE) (STATE->bool_def->typ)
#define axo_str_typ(STATE) (STATE->str_def->typ)

typedef struct axo_struct_field{
    char*           name;
    axo_typ         typ;
    char*           def;
}axo_struct_field;

typedef struct axo_struct{
    char*               name;
    axo_struct_field*   fields;
    int                 fields_len;
}axo_struct;

typedef struct axo_struct_val{
    axo_typ               typ;
    char**                fields;
    int                   fields_count;
}axo_struct_val;

typedef struct axo_call_params{
    axo_expr*       params;
    int             params_len;
}axo_call_params;

typedef struct axo_func_typ {
    int        args_len;
    axo_typ*   args_types;
    char**     args_defs;
    axo_typ    ret_typ;
}axo_func_typ;

typedef struct axo_func{
    char*              name;
    //Arguments
    char**             args_names;
    //Return type
    //Type includes: args_len, args_types and ret_typ
    axo_func_typ       f_typ;
    //Code of the function
    axo_scope*         body;
}axo_func;

typedef struct axo_func_call{
    char*               called_val;
    axo_typ             typ;    //Type of the function being called
    //Arguments
    axo_expr*           params;        //Fix: should be just char**
    int                 params_len;
}axo_func_call;

typedef struct axo_for_loop{
    char*          start;
    char*          condition;
    char*          iteration;
    char*          body;
}axo_for_loop;

typedef enum axo_case_kind{
    axo_list_case_kind,
    axo_range_case_kind,
    axo_default_case_kind
}axo_case_kind;

typedef struct axo_switch_case {
    axo_expr*        exprs;
    int              exprs_len;
    axo_case_kind    kind;
    axo_statement    statement;
    bool             no_break;
}axo_switch_case;

typedef struct axo_switch {
    axo_expr            root;
    axo_switch_case*    cases;
    int                 cases_len;
}axo_switch;

typedef struct axo_till_loop{
    char*        iter;
    char*        body;
    char*        start;
    axo_expr     lim;
}axo_till_loop;

typedef struct axo_enum {
    char*  name;
    char** names;
    int    len;
}axo_enum;

typedef struct axo_empty_arr_lit{
    bool           dynamic;
    int*           len;
    int            dim_count;
}axo_empty_arr_lit;

typedef struct axo_arr_lit{
    bool       dynamic;
    int*       len;
    int        dim_count;
    //new
    unsigned   count;
    char*      val;
    axo_typ    typ;
}axo_arr_lit;

typedef struct axo_index_access{
    axo_expr*      indexes;
    int            index_count;
}axo_index_access;

typedef struct axo_each_loop{
    int             dim_count;
    axo_expr*       dim_iters;
    axo_identifier  value_iter;
    axo_expr        collection;
    char*           body;
    //Locations
    void*           locs;
    bool*           iter_over;
    //0 -> value_iter_loc
    //1 -> iter_dims_loc
    //2 -> collection_loc
    //3+ -> iter_locs (individuals)
}axo_each_loop;

typedef enum axo_symbol_kind{
    axo_arrow_symbol,
    axo_vertical_line_symbol
}axo_symbol_kind;

typedef enum axo_action_assign_op{
    axo_add_assign_op,
    axo_sub_assign_op,
    axo_mul_assign_op,
    axo_div_assign_op,
    axo_mod_assign_op,
    axo_err_assign_op
}axo_action_assign_op;

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

#define axo_basic_col_sup(ST) (!((ST)->config->color_support != axo_no_color_support_kind))

//Function declarations

//Hashmap helpers
#define new_map(typ, hsh, comp) ((map)(hashmap_new(sizeof(typ), 0, 0, 0, hsh, comp, NULL, NULL)))

int map_cmp_vars(const void* a, const void* b, void *udata);
uint64_t map_hash_vars(const void *item, uint64_t seed0, uint64_t seed1);

int map_cmp_func(const void* a, const void* b, void *udata);
uint64_t map_hash_func(const void *item, uint64_t seed0, uint64_t seed1);

int map_cmp_module(const void* a, const void* b, void *udata);
uint64_t map_hash_module(const void *item, uint64_t seed0, uint64_t seed1);

int map_cmp_str(const void* a, const void* b, void *udata);
uint64_t map_hash_str(const void *item, uint64_t seed0, uint64_t seed1);

int map_cmp_typ_def(const void* a, const void* b, void *udata);
uint64_t map_hash_typ_def(const void *item, uint64_t seed0, uint64_t seed1);

#ifdef _WIN32
    #define axo_dir_sep "\\"
#else
    #define axo_dir_sep "/"
#endif
#define axo_dir_sep_char axo_dir_sep[0]

#define static_str_ptr(SZ) ((char**)(&((char[SZ]){})))  
#define s_str(SZ) ((char[SZ]){})


#define YYLTYPE_IS_DECLARED
//Only then include grammar header file
#include "../axo_gram.tab.h"

//Yacc
int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
void yyerror(YYLTYPE*, const char *, ...);
int yyparse(void);
int asprintf(char **strp, const char *format, ...);

//State
axo_state* axo_new_state(char* root_path);
void axo_add_decl(axo_state* st, axo_decl d);
void axo_handle_args(axo_state* st, int argc, char** argv, int init_arg);
void axo_load_cfg(axo_state* st);
void axo_print_config(axo_state* st);
int axo_info_cmd(axo_state* st, int argc, char** argv);
int axo_set_cmd(axo_state* st, int argc, char** argv);
char* axo_get_code(axo_state* st);

//Scopes
axo_scope* axo_new_scope(axo_scope* parent);
void axo_add_statement(axo_scope* sc, axo_statement s);
axo_statement axo_scope_to_statement(axo_scope* sc);
char* axo_scope_statement_to_str(axo_scope* sc, axo_statement stmnt);
char* axo_scope_code(axo_scope* sc);
axo_scope* axo_scopes_top(axo_scopes* scopes);
void axo_push_scope(axo_scopes* scopes, axo_scope* sc);

//Variables
void axo_set_var(axo_scope* sc, axo_var var);
axo_var* axo_get_var(axo_scope* sc, char* name);
axo_var* axo_del_var(axo_scope* sc, char* name);
void axo_set_func(axo_state* st, axo_func fn);
char* axo_get_var_decl_assign(YYLTYPE* pos, axo_var var, axo_expr expr);

//Sources
void axo_new_source(axo_state* st, char* path);
void axo_new_string_source(axo_state* st, char* code);
void axo_pop_source(axo_state* st);
void axo_switch_source(axo_source* src);
axo_decl axo_include_file(axo_state* st, YYLTYPE* loc, char* filename, bool str_lit);
bool axo_was_file_included(axo_state* st, char* path);
void axo_set_input_string(const char *str);

//Modules
axo_decl axo_use_module(axo_state* st, YYLTYPE* loc, char* name);
axo_module axo_new_module();
void axo_load_module_defaults(axo_state* st, axo_module* mod);
void axo_set_module(axo_state* st, axo_module mod);
axo_module* axo_get_module(axo_state* st, char* name);
char* axo_generate_module_string(axo_module mod);
char* axo_generate_modules(axo_state* st);
axo_decl axo_add_module(axo_state* st, axo_module mod);

//Functions
axo_decl axo_func_decl_to_decl(axo_func func);
axo_decl axo_func_def_to_decl(axo_func func);
axo_expr axo_call_to_expr(axo_func_call cl);
axo_func_call axo_method_call(axo_state* st, axo_scope* sc, YYLTYPE* pos, YYLTYPE* expr_pos, YYLTYPE* name_pos, axo_expr expr, char* name, bool rval_now);
axo_expr axo_expr_dot_field(axo_state* st, YYLTYPE* pos, YYLTYPE* expr_pos, YYLTYPE* field_pos, axo_expr passed_expr, char* field);

//Structures
int axo_get_struct_field_index(axo_struct* structure, char* name);

//Arrays
axo_expr axo_get_array_field(axo_state* st, YYLTYPE* expr_loc, YYLTYPE* field_loc, axo_expr expr, char* field);
axo_func_call axo_get_array_method(axo_state* st, YYLTYPE* expr_loc, YYLTYPE* name_loc, axo_expr expr, char* name);
char* axo_arr_access_to_str(YYLTYPE* arr_loc, axo_expr arr, YYLTYPE* index_loc, axo_index_access index);
bool axo_typ_valid_arr_index(axo_typ typ, axo_state* st);
char* axo_get_arr_name_typ_decl(axo_typ typ, char* name, int sz);

//Types
axo_typ_def* axo_set_typ_def(YYLTYPE* loc, axo_state* st, axo_typ_def td);
const axo_typ_def* axo_get_typ_def(axo_state* st, char* name);
char* axo_get_typ_default(axo_typ typ);
char* axo_type_str(axo_typ typ, char* dest);
#define axo_typ_to_str(T) axo_type_str(T, (char[1024]){'\0'})
char* axo_c_arr_of_typ(axo_typ typ, char* inside);
bool axo_is_typ_prim(axo_typ t);
char* axo_prim_typ_to_c_str(axo_typ t);
char** axo_typ_to_strings(axo_typ typ, char** dest);
char* axo_typ_to_c_str(axo_typ typ);
char* axo_name_typ_decl(char* name, axo_typ typ);
axo_typ axo_clean_typ(axo_typ typ);
char* axo_typ_kind_to_str(axo_typ_kind tk);
bool axo_typ_eq(axo_typ t1, axo_typ t2); //FIX!
bool axo_is_no_typ(axo_typ typ);
bool is_simple_typ_eq(axo_typ t1, char* t2);
const char* axo_identifier_kind_to_str(axo_identifier_kind kind);
axo_typ axo_merge_type_with_qualifiers(axo_typ typ, axo_typ type_q);

//Loops
char* axo_for_loop_to_str(axo_for_loop lp);

//Switch
axo_statement axo_switch_to_statement(axo_switch swtch);

//Files
char* axo_file_to_str(char* path);
void axo_parse_each_loop(axo_each_loop* lp, axo_state* state, axo_scope* scope, int loop_count);
axo_statement axo_each_to_statement(axo_each_loop lp);
char* axo_file_to_bytes(const char *filename, size_t *size) ;
void axo_bytes_to_file(const char *filename, char* bytes, size_t size) ;
char* axo_strip_file_extension(char* filename);
char* axo_add_file_extension(char* filename, char* ext);
char* axo_swap_file_extension(char* filename, char* new_ext);
bool axo_file_exists(char *fname) ;
bool axo_dir_exists(char* dirname) ;

//Misc
char* fmt_str(char* dest, const char fmt[], ...);
char* fmtstr(const char fmt[], ...);
char* axo_bool_to_str(bool a, axo_color_support_kind col_sup);
const char* axo_identifier_kind_to_str(axo_identifier_kind iden);
char* axo_cc_to_str(axo_cc_kind cc);
char* axo_color_support_to_str(axo_color_support_kind col_sup);
int axo_color_count(axo_color_support_kind col_sup);
char* axo_get_color_esc(int index, axo_color_support_kind col_sup);
void axo_lolprintf(axo_color_support_kind col_sup, int seed, const char* fmt, ...);
char* axo_lolsprintf(axo_color_support_kind col_sup, int seed, char* dest, const char* fmt, ...);
void axo_color_printf(int index, axo_color_support_kind col_sup, const char* fmt, ...);
char* itoa_spaced(int a);
unsigned char axo_symbol(axo_symbol_kind s, bool e_ascii);

//Memory related
void* axo_safe_malloc(size_t n);

//Errors
char* axo_error_with_loc(axo_state* st, YYLTYPE *loc, char* msg);

//Unknown
void parse_operator(YYLTYPE* loc, axo_expr* dest, axo_expr val1, char* op, axo_expr val2);
axo_expr axo_parse_special_assignment(YYLTYPE* lval_loc, YYLTYPE* assign_loc, YYLTYPE* val_loc, axo_expr lval, const char* assign_op, axo_expr val);
axo_expr axo_parse_error_assignment(YYLTYPE* lval_loc, YYLTYPE* assign_loc, YYLTYPE* val_loc, axo_expr lval, axo_func_call fcall);
long long int* axo_encode_easter(char* input, int* out_len);
char* axo_decode_easter(long long int* data);
char* axo_err_msg(axo_err_code err_code);

//Platform specific
char* axo_resolve_path(char* filename);
int axo_chdir(char* path);
char* axo_get_exec_path(char* buf, int sz) ;
char* axo_cwd(char* dest, size_t sz);
char* axo_get_parent_dir(char* path);

//Deprecated/shouldn't be used (will have to replace them)
void set_val(axo_expr* dest, axo_typ typ, char* val);

//Free
void axo_free_state(axo_state* st);
void axo_free_scope(axo_scope* sc);
void axo_free_source(axo_source s);
void axo_free_variables(map vars);
void axo_free_func(axo_func fn);
void axo_free_typ(axo_typ t);
void axo_free_func_typ(axo_func_typ ft);
void axo_free_index_access(axo_index_access ia);

#endif
