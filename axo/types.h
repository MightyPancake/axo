#ifndef AXO_TYPES_H
#define AXO_TYPES_H

typedef struct hashmap* map;
#define axo_no_typ ((axo_typ){.kind=axo_no_kind, .simple=NULL})

#include <stdbool.h>

//Memory management
#define axo_scopes_cap 32
#define axo_scopes_table_cap 8
#define axo_decls_cap 16
#define axo_statements_cap 16
#define axo_func_args_cap 2
#define axo_tok_locations_cap 1024
#define axo_enum_names_cap 16
#define axo_types_def_cap 16
#define axo_stat_arr_literal_cap 1
#define axo_strings_cap 1

typedef enum axo_typ_kind{
    axo_simple_kind,
    axo_func_kind,
    axo_c_arg_list_kind,
    axo_dyn_arr_kind,
    axo_stat_arr_kind,
    axo_ptr_kind,
    axo_enum_kind,
    axo_struct_kind,
    axo_no_kind,
    axo_module_kind,
}axo_typ_kind;

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

typedef struct axo_typ {
    axo_typ_kind       kind;
    union {
        char*           simple;
        void*           func_typ;
        void*           arr;
        void*           ptr;
        void*           enumerate;
        void*           structure;
    };
    void*              def;
}axo_typ;

typedef struct axo_ptr{
    axo_typ        typ;
}axo_ptr;

typedef struct axo_arr{
    axo_typ        typ;
    int            sz; //0 for dynamic arrays, anything positive for static arays
}axo_arr;

typedef struct axo_types_list{
    axo_typ*           values;
    int                len;
}axo_types_list;

typedef enum axo_expr_kind{
    axo_expr_normal_kind,
    axo_expr_enum_typ_kind,
    axo_expr_module_kind
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
    axo_identifier_typ_kind
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
    axo_ret_statement_kind,
    axo_scope_statement_kind,
    axo_incr_decr_statement_kind,
    axo_continue_statement_kind,
    axo_break_statement_kind,
    axo_stat_arr_init_statement_kind,
    axo_var_is_decl_statement_kind,
    axo_expr_statement_kind
}axo_statement_kind;

typedef struct axo_statement{
    axo_statement_kind    kind;
    char*                 val;
}axo_statement;

typedef enum axo_decl_kind{
    axo_enum_decl_kind,
    axo_struct_decl_kind,
    axo_func_decl_kind,
    axo_c_include_decl_kind,
    axo_c_register_decl_kind
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

typedef struct axo_var {
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

typedef struct axo_state{
    axo_decl*              decls;
    int                    decls_len;
    axo_scope*             global_scope;
    axo_scope**            scopes_table;
    char*                  filepath;
    
    map                    types_def;
    
    axo_compiler_config    config;

    //Default types
    axo_typ_def*           int_def;
}axo_state;

typedef struct axo_struct_field{
    char*           name;
    axo_expr        def;
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

typedef struct axo_stat_arr_val{
    axo_typ        typ;
    char**         data;
    int            len;
}axo_stat_arr_val;

typedef struct axo_stat_arr_init{
    axo_expr        lval;
    int*            dims;
    char**          iters;
    int             len;
    axo_scope*      code;
}axo_stat_arr_init;

#endif