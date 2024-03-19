#ifndef AXO_TYPES_H
#define AXO_TYPES_H

typedef struct hashmap* map;
#define axo_no_typ ((axo_typ){.kind=axo_no_kind})

#include <stdbool.h>

#define axo_max_path_len 2048

//Memory management
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

#ifdef __WIN32
    #define AXO_BIN_EXT ".exe"
#else
    #define AXO_BIN_EXT ""
#endif

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
    axo_module_kind
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
        void*           module;
    };
    void*              def;
}axo_typ;

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
    axo_expr_module_kind,
}axo_expr_kind;

typedef enum axo_lval_kind{
    axo_var_lval_kind,
    axo_other_lval_kind,
    axo_not_lval_kind
}axo_lval_kind;

typedef struct axo_expr{
    axo_expr_kind  kind;
    axo_lval_kind  lval_kind;
    char*          val;
    axo_typ        typ;
}axo_expr;

typedef enum axo_identifier_kind{
    axo_identifier_var_kind,
    axo_identifier_module_kind,
    axo_identifier_typ_kind,
    axo_no_identifier_kind
}axo_identifier_kind;

typedef struct axo_identifier {
    axo_identifier_kind    kind;
    void*                  data;
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
    axo_func_decl_kind,
    axo_use_decl_kind,
    axo_c_include_decl_kind,
    axo_c_register_decl_kind,
    axo_module_info_decl_kind,
    axo_assign_decl_kind,
    axo_is_decl_kind,
    axo_typ_def_decl_kind
}axo_decl_kind;

typedef struct axo_decl {
    axo_decl_kind    kind;
    char*            val;
}axo_decl;

typedef struct axo_scope{
    axo_statement* statements;    //Statements in the scope
    int            statements_len;//Length of statments
    map            variables;      //Variables declared in the scope
    void*          parent;         //Pointer to the parent scope (or NULL for global scope)
    
    int            def_iter;
    
    axo_typ        ret_typ;
    char*          ret_assign;
}axo_scope;

typedef struct axo_scopes{
    axo_scope**    scopes;
    int             len;
}axo_scopes;

typedef struct axo_var{
    char*       name;
    axo_typ     typ;
    bool        is_const;
}axo_var;

typedef struct axo_simple_typ{
    char*        name;
    char*        def;
}axo_simple_typ;

typedef struct axo_typ_def {
    char*             name;
    axo_typ           typ;
}axo_typ_def;

typedef enum axo_cc_kind{
    axo_gcc_cc_kind,
    axo_tcc_cc_kind,
    axo_clang_cc_kind
}axo_cc_kind;

typedef struct axo_compiler_config{
    axo_cc_kind  cc;
    char*        output_name;
    bool         delete_c;
    bool         measure_time;
    bool         bug_hunter;
}axo_compiler_config;

typedef struct axo_source{
    char*            path;
    char*            parent_dir;
    FILE*            file;
    long             pos;
    int              line;
    int              col;
}axo_source;

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
    axo_decl*              decls;
    int                    decls_len;
    axo_scope*             global_scope;
    axo_scope**            scopes_table;
    
    map                    types_def;
    
    axo_compiler_config    config;

    //Default types
    axo_typ_def*           int_def;
    axo_typ_def*           bool_def;
    axo_typ_def*           float_def;
    axo_typ_def*           byte_def;
    axo_typ_def*           str_def;

    //File related
    char*                  root_path;
    axo_source*            sources;
    int                    sources_len;

    //Modules
    map                    modules;
    char**                 module_names;
    int                    modules_len;
    int                    modules_decl;
    bool                   in_core;
}axo_state;

#define axo_source(ST) (&(ST->sources[ST->sources_len-1]))
#define axo_line(ST) (axo_source(ST)->line)
#define axo_col(ST) (axo_source(ST)->col)
#define axo_pos(ST) (axo_source(ST)->pos)
#define axo_src_path(ST) (axo_source(ST)->path)

#define axo_int_typ(STATE) (STATE->int_def->typ)
#define axo_float_typ(STATE) (STATE->float_def->typ)
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

#endif
