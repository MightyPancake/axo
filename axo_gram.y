%{
  #define test_playground 0
  #define YY_DECL int yylex (YYSTYPE* yylval, struct YYLTYPE* yylloc)
  #include "util/utils.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "axoc/axo.h"
  #include <time.h>
  //Bison extern
  extern int yylineno;
  extern FILE *yyin;
  extern YYLTYPE yylloc;
  extern YYSTYPE yylval;
  int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
  void yyerror(YYLTYPE* loc, const char *, ...);
  int yyparse(void);
  //Axo extern
  extern int (*axo_printf)(const char* fmt, ...);
  //State
  #define top_scope axo_scopes_top(scopes)
  axo_state* state;
  //Scopes
  axo_scopes* scopes;
  int in_loop_count = 0;

  bool rval_now=false;
  bool AXO_RVAL_WAS_VALID;

  int prog_return = 0;                    //Return value of the compiler - 0 if ok, 1 otherwise
  bool axo_code_scope_started = false;    //This indicates that a new codescope is already on top and doesn't need to be added
  #define axo_raise_error prog_return = 1;
  #define axo_is_valid_rval(EXPR) (EXPR.typ.kind!=axo_no_kind)
  #define axo_validate_rval(LOC, EXPR) ({ \
    AXO_RVAL_WAS_VALID=true; \
    if (!axo_is_valid_rval(EXPR)){ \
      AXO_RVAL_WAS_VALID=false; \
      if (EXPR.lval_kind==axo_var_lval_kind) \
        yyerror(LOC, axo_err_msg(axo_undeclared_var_err_code)); \
      else \
        yyerror(LOC, axo_err_msg(axo_invalid_rval_err_code)); \
    } \
    AXO_RVAL_WAS_VALID; \
  }) \
%}

%define parse.error verbose
%locations
%define api.pure full

%token<str> STRING_LITERAL "string literal"
%token<str> INTEGER_LITERAL "integer literal"
%token<str> FLOAT_LITERAL "float literal"
%token<str> IDEN "identifier"
%token<str> RET_KWRD "ret"
%token<str> BREAK_KWRD "break"
%token<str> CONTINUE_KWRD "continue"
%token<str> C_INCLUDE_LOCAL "#include 'local_file'"
%token<str> C_INCLUDE "#include"
%token<str> C_REGISTER "#register"
%token<str> TAG_TYP "#typ"
%token<str> FN_KWRD "fn"
%token<str> WHILE_KWRD "while"
%token<str> FOR_KWRD "for"
%token<str> EACH_KWRD "each"
%token<str> IN_KWRD "in"
%token<str> IF_KWRD "if"
%token<str> ELSE_KWRD "else"
%token<str> EQ_OP "=="
%token<str> INEQ_OP "!="
%token<str> EQ_SMLR_OP ">="
%token<str> EQ_GRTR_OP "<="
%token<str> BIT_OR_OP "or"
%token<str> BIT_AND_OP "and"
%token<str> LOGICAL_OR_OP "||"
%token<str> LOGICAL_AND_OP "&&"
%token<str> LEFT_SHIFT_OP "<<"
%token<str> RIGHT_SHIFT_OP ">>"
%token<str> TILL_KWRD "till"
%token<str> NULL_KWRD "null"
%token<str> INCR_OP "++"
%token<str> DECR_OP "--"
%token<str> ASSIGN_ADD "+="
%token<str> ASSIGN_SUB "-="
%token<str> ASSIGN_MUL "*="
%token<str> ASSIGN_DIV "/="
%token<str> ENUM_KWRD "enum"
%token<str> STRUCT_KWRD "struct"
%token<str> USE_KWRD "use"
%token<str> INCLUDE_KWRD "include"
%token<str> STRUCT_LITERAL_START "struct{"
%token<str> DOT_FIELD ".field"
%token<str> MODULE_KWRD "module"
%token<str> ARROW_OP "->"
%type<scope> code_scope code_scope_start
%type<function> func_def func_args func_def_start func_def_name
%type<function_call> func_call_start func_call called_expr
%type<expression> expr incr_decr_op if_condition assignment arr_literal
%type<declaration_type> declaration
%type<str> statements declarations while_loop_base func_def_ret_typ
%type<typ_type> val_typ c_typ arr_typ arr_multidim_typ func_typ func_typ_start func_typ_args
%type<types_list> c_typ_list
%type<function_argument> func_arg
%type<for_loop_type> for_loop_start for_loop_init for_loop_base
%type<till_loop_type> till_loop_start
%type<enum_type> enum_names
%type<statement_type> statement matching_statement non_matching_statement matching_if_statement non_matching_if_statement non_matching_for_loop matching_for_loop non_matching_while matching_while matching_each_loop non_matching_each_loop
%type<struct_type> struct_def
%type<struct_val_type> struct_literal_start struct_literal
%type<identifier_type> identifier
%type<empty_arr_lit_type> empty_arr_dims
%type<index_access_type> index_access
%type<arr_lit_type> stat_arr_literal stat_arr_literal_start
%type<each_loop_type> each_iter_dims each_loop_base
%type<module_type> module_info
%type<bool_type> arr_lit_start

//Prec
%left IDENTIFIER_PREC
%left '$'
%left EXPR_AS_STATEMENT
%left RET_KWRD
%right '='
%left '?'
%left "||"
%left "&&"
%left '<' '>' "<=" ">="
%left "==" "!="
%left "<<" ">>"
%left '+' '-'
%left '*' '/' '%'
%left "in" LOOP_PREC
%left '.'
%left '(' ':'
%left UMINUS '@' '^'
%left '!'
%left CALL_PREC
%left INCR_OP DECR_OP '[' DOT_FIELD
%left IF_KWRD
%left STRUCT_LIT_NAMED_FIELD

%union {
  char* str;
  axo_strings strings_type;
  axo_scope* scope;
  axo_expr expression;
  axo_decl declaration_type;
  axo_func function;
  axo_func_arg function_argument;
  axo_func_call function_call;
  axo_typ typ_type;
  axo_types_list types_list;
  axo_for_loop for_loop_type;
  axo_till_loop till_loop_type;
  axo_enum enum_type;
  axo_statement statement_type;
  axo_struct struct_type;
  axo_struct_val struct_val_type;
  axo_identifier identifier_type;
  axo_arr_lit arr_lit_type;
  axo_empty_arr_lit empty_arr_lit_type;
  axo_index_access index_access_type;
  axo_each_loop each_loop_type;
  axo_module module_type;
  bool bool_type;
}

%%

declarations : /* EMPTY */ {}
  | declarations func_def {
    axo_add_decl(state, axo_func_def_to_decl($2));
  }
  | declarations C_INCLUDE {
    if ($C_INCLUDE[0] == '<'){
      axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", $C_INCLUDE), .kind=axo_c_include_decl_kind});
    }else{
      char* path = &($C_INCLUDE[1]);
      path[strlen($C_INCLUDE)-2] = '\0';
      // printf("Path of c_include: %s\nResolved path: %s\n", path, axo_resolve_path(path));
      char* res_path = axo_resolve_path(path);
      axo_add_decl(state, (axo_decl){.val = fmtstr("#include \"%s\"", res_path), .kind=axo_c_include_decl_kind});
      free(res_path);
    }
  }
  | declarations C_REGISTER c_typ IDEN '(' c_typ_list ')' {
    // printf("Starting to register a C function\n");
    axo_func fn;
    fn.name = alloc_str($4);
    fn.f_typ.args_len = $6.len;
    fn.f_typ.ret_typ = $3;
    fn.body = NULL; //This is only true for C functions!
    fn.args_names = (char**)malloc(fn.f_typ.args_len*sizeof(char*));
    fn.f_typ.args_defs = (char**)malloc(fn.f_typ.args_len*sizeof(char*));
    fn.f_typ.args_types = (axo_typ*)malloc(fn.f_typ.args_len*sizeof(axo_typ));
    for (int i = 0; i<fn.f_typ.args_len; i++){
      asprintf(&(fn.args_names[i]), "p%d", i+1);
      //FIX: Every type should have default value!
      fn.f_typ.args_defs[i] = $6.values[i].def;
      fn.f_typ.args_types[i] = $6.values[i];
    }
    axo_set_func(state, fn);
    axo_add_decl(state, (axo_decl){.val=fmtstr("//registered function '%s'", fn.name), .kind=axo_c_register_decl_kind});
  }
  | declarations ENUM_KWRD IDEN '(' enum_names ')' {
    new_ptr_one(enm, axo_enum);
    *enm = $5;
    enm->name=alloc_str($3);
    char* decl;
    int decl_sz = 18+(2+$5.len)*strlen($3);  //typedef enum %name{\}name;
    for (int i=0; i<$5.len; i++){
      decl_sz += strlen($5.names[i]) + 2 + 1;
    }
    decl_sz--; //last comma
    decl = (char*)malloc(decl_sz*sizeof(char));
    strcpy(decl, "typedef enum ");
    strcat(decl, $3);
    strcat(decl, "{\n");
    for (int i=0; i<$5.len; i++){
      if(i>0) strcat(decl, ",\n");
      char* field = fmtstr("%s$%s", $3, $5.names[i]);
      strcat(decl, field);
      axo_set_var(state->global_scope, (axo_var){.name=field, .typ=axo_no_typ, .is_const=true});
    }
    strcat(decl, "\n}");
    strcat(decl, $3);
    strcat(decl, ";");
    axo_typ_def td = (axo_typ_def){
      .name=enm->name,
      .typ=(axo_typ){
        .kind=axo_enum_kind,
        .enumerate=enm,
        .def="0"
      },
    };
    axo_set_typ_def(&@$, state, td);
    axo_add_decl(state, (axo_decl){.val=decl, .kind=axo_enum_decl_kind});
  }
  | declarations declaration {
    axo_add_decl(state, $declaration);
  }
  ;

declaration : struct_def { //Fix! Make this use realloc less
    new_ptr_one(strct, axo_struct);
    *strct = $struct_def;
    char* decl = empty_str;
    strapnd(&decl, "typedef struct ");
    strapnd(&decl, $struct_def.name);
    strapnd(&decl, "{\n");
    for (int i=0; i<$struct_def.fields_len; i++){
      strapnd(&decl, axo_name_typ_decl(strct->fields[i].name, strct->fields[i].typ));
      strapnd(&decl, ";\n");
    }
    strapnd(&decl, "}");
    strapnd(&decl, $struct_def.name);
    strapnd(&decl, ";");
    axo_typ_def td = (axo_typ_def){
      .name=strct->name,
      .typ=(axo_typ){
        .kind=axo_struct_kind,
        .structure=strct,
        .def="0" //FIX! DEFAULT VALUE!
      },
    };
    axo_set_typ_def(&@$, state, td);
    $$ = (axo_decl){.val=decl, .kind=axo_struct_decl_kind};
  }
  | "use" IDEN {
    $$ = axo_use_module(state, &@2, $IDEN);
  }
  | "include" STRING_LITERAL {
    $$ = axo_include_file(state, &@2, $STRING_LITERAL, true);
  }
  | "module" module_info ')' {
    axo_load_module_defaults(state, &$module_info);
    $$ = axo_add_module(state, $module_info);
  }
  | expr '|' val_typ {
    if ($1.lval_kind == axo_var_lval_kind){
      $$ = (axo_decl){
        .kind=axo_is_decl_kind,
        .val=axo_name_typ_decl($1.val, $3)
      };
      strapnd(&($$.val), ";");
      axo_set_var(top_scope, (axo_var){.name=$1.val, .typ=axo_clean_typ($3), .is_const=false});
    }else{
      yyerror(&@1, "Cannot declare non-variable value '%s'.", $1.val);
    }
  }
  | expr '|' val_typ '=' expr {
    if ($1.lval_kind == axo_var_lval_kind){
      $$ = (axo_decl){
        .kind=axo_is_decl_kind,
        .val = axo_get_var_decl_assign($1.val, (axo_expr){.typ=$val_typ, .val=$5.val})
      };
      strapnd(&($$.val), ";");
      axo_set_var(top_scope, (axo_var){.name=$1.val, .typ=axo_clean_typ($3), .is_const=false});
    }else{
      yyerror(&@1, "Cannot declare non-variable value '%s'.", $1.val);
    }
  }
  | "#typ" IDEN {
    char* name = alloc_str($IDEN);
    axo_set_typ_def(&@$, state, (axo_typ_def){.name=name, .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name=name, .cname=name}, .def="0"}});
      $$ = (axo_decl){
        .kind = axo_typ_def_decl_kind,
        .val = fmtstr("//accepting type %s", $IDEN)
      };
  }
  ;

struct_def : STRUCT_KWRD IDEN '(' func_args ')' {
    axo_struct_field* fields = (axo_struct_field*)malloc($4.f_typ.args_len*sizeof(axo_struct_field));
    for (int i = 0; i<$4.f_typ.args_len; i++){
      fields[i] = (axo_struct_field){
        .name = alloc_str($func_args.args_names[i]),
        .typ = $func_args.f_typ.args_types[i],
        .def = $func_args.f_typ.args_defs[i]
      };
    }
    $$ = (axo_struct){
      .name=alloc_str($IDEN),
      .fields=fields,
      .fields_len=$4.f_typ.args_len
    };
  }
  ;

module_info : '(' {
    $$ = axo_new_module();
  }
  | module_info IDEN ':' STRING_LITERAL {
    char* str_val = alloc_str(&($STRING_LITERAL[1]));
    str_val[strlen(str_val)-1] = '\0';
    if (strcmp($IDEN, "name") == 0){
      $$.name = str_val;
    }else if (strcmp($IDEN, "prefix") == 0){
      $$.prefix = str_val;
    }else if (strcmp($IDEN, "version") == 0){
      $$.version = str_val;
    }else if (strcmp($IDEN, "author") == 0){
      $$.author = str_val;
    }else if (strcmp($IDEN, "website") == 0){
      $$.website = str_val;
    }else if (strcmp($IDEN, "license_name") == 0){
      $$.license_name = str_val;
    }else if (strcmp($IDEN, "license") == 0){
      $$.license = str_val;
    }else if (strcmp($IDEN, "description") == 0){
      $$.description = str_val;
    }else
      yyerror(&@2, "Not a valid module information field.");
    // printf("Setting %s to %s\n", $IDEN, $STRING_LITERAL);
  }
  ;

statements : statement {axo_add_statement(top_scope, $statement);}
  | statements statement {axo_add_statement(top_scope, $statement);}
  ;

index_access : '[' expr {
    axo_validate_rval(&@expr, $expr);
    $$ = (axo_index_access){
      .index_count=1,
      .indexes = (axo_expr*)malloc(128*sizeof(axo_expr))
    };
    $$.indexes[0] = $expr;
  }
  | index_access '|' expr {
    $$.indexes[$$.index_count++] = $expr;
  }
  ;

identifier : IDEN {
    axo_typ_def* td = axo_get_typ_def(state, $1);
    if (td != NULL) {
         $$ = (axo_identifier){
        .kind = axo_identifier_typ_kind,
        .data = td
      };
    }else{
      axo_module* mod = axo_get_module(state, $IDEN);
      if (mod){
        $$ = (axo_identifier){
          .kind = axo_identifier_module_kind,
          .data = mod
        };
      }else{
        $$ = (axo_identifier){
          .kind = axo_identifier_var_kind,
          .data = (void*)alloc_str($1)
        };
      }
    }
  } %prec IDENTIFIER_PREC
  ;

incr_decr_op : expr INCR_OP {
    $$.typ = $expr.typ;
    $$.val = fmtstr("%s++", $1.val);
  }
  | expr DECR_OP {
    $$.typ = $1.typ;
    $$.val = fmtstr("%s--", $1.val);
  }
  ;

//String literal should be a pointer!
expr : STRING_LITERAL {set_val(&$$, axo_str_typ(state), $1); $$.kind=axo_expr_normal_kind;}
  | INTEGER_LITERAL {set_val(&$$, axo_int_typ(state), $1); $$.kind=axo_expr_normal_kind; $$.lval_kind = axo_not_lval_kind;}
  | FLOAT_LITERAL {set_val(&$$, axo_float_typ(state), $1); $$.kind=axo_expr_normal_kind; $$.lval_kind = axo_not_lval_kind;}
  | "null" {
    $$ = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val="((char*)(NULL))",
      .typ=axo_str_typ(state)
    };
  }
  | expr '+' expr {parse_operator(&@2, &$$, $1, "+", $3); }
  | expr '-' expr {parse_operator(&@2, &$$, $1, "-", $3); }
  | '-' expr {asprintf(&($$.val), "-%s", $2.val); $$.typ = $2.typ; $$.kind = axo_expr_normal_kind; } %prec UMINUS
  | expr '*' expr {parse_operator(&@2, &$$, $1, "*", $3); }
  | expr '/' expr {parse_operator(&@2, &$$, $1, "/", $3); }
  | expr '%' expr {parse_operator(&@2, &$$, $1, "%", $3); }
  | '(' expr ')' {asprintf(&($$.val), "(%s)", $2.val); $$.typ = $2.typ; $$.kind = axo_expr_normal_kind; }
  | expr '@' { //Referencing
    if ($1.lval_kind == axo_not_lval_kind)
      yyerror(&@1, "Cannot reference a non l-value.");
    $$.typ.kind = axo_ptr_kind;
    $$.typ.subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp($$.typ) = $1.typ;
    asprintf(&($$.val), "&%s", $1.val);
  }
  | expr '^' { //Dereferencing
    if ($1.typ.kind != axo_ptr_kind)
      yyerror(&@1, "Cannot dereference a value of non-pointer type '%s'.", axo_typ_to_str($1.typ));
    $$.typ = *axo_subtyp($1.typ);
    $$.lval_kind=$1.lval_kind;
    asprintf(&($$.val), "(*(%s))", $1.val);
  }
  | assignment
  | identifier {
    char* var_name = "";
    axo_typ_def* td;
    switch($1.kind){
      case axo_identifier_module_kind:
        $$ = (axo_expr){
          .val = alloc_str(""),
          .typ = (axo_typ){
            .kind = axo_module_kind,
            .module = $identifier.data
          },
          .kind = axo_expr_module_kind,
          .lval_kind=axo_not_lval_kind
        };
        break;
      case axo_identifier_var_kind:
        var_name = (char*)($identifier.data);
        axo_var* var = axo_get_var(top_scope, (char*)($1.data));
        if (var == NULL && rval_now)
          yyerror(&@1, "Variable '%s' undefined before usage.", (char*)($1.data));
        else{
           $$ = (axo_expr){
            .val=var_name,
            .typ=(var ? var->typ : axo_no_typ),
            .kind=axo_expr_normal_kind,
            .lval_kind=axo_var_lval_kind
          };
        }
        break;
      case axo_identifier_typ_kind:
        td = (axo_typ_def*)($1.data);
        switch (td->typ.kind){
          case axo_enum_kind:
            $$ = (axo_expr){
              .kind=axo_expr_enum_typ_kind,
              .typ=td->typ,
              .val=fmtstr("%s$%s", td->name, ((axo_enum*)(td->typ.enumerate))->names[0])
            };
            break;
          default:
            yyerror(&@1, "Non-enum type '%s' is not an expression.", td->name);
            break;
        }
        break;
      default:
        yyerror(&@1, "Invalid identifier as expression.");
        break;
    }
  }
  | expr '?' expr ':' expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3) && axo_validate_rval(&@5, $5)){
      if (axo_typ_eq($3.typ, $5.typ)){
        $$ = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", $1.val, $3.val, $5.val),
          .typ=$3.typ
        };
      }else{
        yyerror(&@$, "Ternary expression cannot return both '%s' and '%s'.", axo_typ_to_str($3.typ), axo_typ_to_str($5.typ));
      }
    }
  }
  | func_call {$$ = axo_call_to_expr($1);}
  | expr '<' expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<%s", $1.val, $3.val)
    };
  }
  | expr '>' expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>%s", $1.val, $3.val)
    };
  }
  | expr "==" expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s==%s", $1.val, $3.val)
    };
  }
  | expr "!=" expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s!=%s", $1.val, $3.val)
    };
  }
  | expr ">=" expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>=%s", $1.val, $3.val)
    };
  }
  | expr "<=" expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<=%s", $1.val, $3.val)
    };
  }
  | expr "||" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = axo_bool_typ(state),
        .val = fmtstr("%s||%s", $1.val, $3.val)
      };
    }
  }
  | '!' expr {
    if (axo_validate_rval(&@2, $2)) {
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = axo_bool_typ(state),
        .val = fmtstr("!(%s)", $2.val),
        .lval_kind = axo_not_lval_kind
      };
      if ($2.typ.kind != axo_simple_kind)
        yyerror(&@2, "Negation can only be used on primitive types (byte, int etc.)");
    }
  }
  | expr "&&" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = $1.typ,
        .val = fmtstr("%s&&%s", $1.val, $3.val)
      };
    }
  }
  | expr ">>" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = $1.typ,
        .val = fmtstr("%s>>%s", $1.val, $3.val)
      };
    }
  }
  | expr "<<" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = $1.typ,
        .val = fmtstr("%s<<%s", $1.val, $3.val)
      };
    }
  }
  | struct_literal {
    $$.typ = $1.typ;
    axo_struct* structure = (axo_struct*)($$.typ.structure);
    //size of the string to avoid reallocing: (name){.field1=value1, }
    int v_len = strlen(structure->name) + 5;
    for (int i=0; i<structure->fields_len; i++){
      v_len+=strlen(structure->fields[i].name)+4+strlen($1.fields[i]);  //name of a field + 3 cause of .=
    }
    char* v = (char*)malloc(v_len*sizeof(char));
    strcpy(v, "(");
    strcat(v, structure->name);
    strcat(v, "){");
    for (int i=0; i<structure->fields_len; i++){
      if (i!=0) strcat(v, ", ");
      strcat(v, ".");
      strcat(v, structure->fields[i].name);
      strcat(v, "=");
      strcat(v, $1.fields[i]);
    }
    strcat(v,"}");
    $$.val = v;
    $$.kind = axo_expr_normal_kind;
  }
  | expr index_access ']'{
    @2.last_column = @3.last_column;
    axo_arr_typ arr_typ;
    switch($1.typ.kind){
      case axo_arr_kind:
        arr_typ = axo_get_arr_typ($1.typ);
        @2.last_column = @3.last_column;
        if (arr_typ.dim_count != $index_access.index_count){
          yyerror(&@2, "Cannot index %d dimensional array with %d dimensional index.", arr_typ.dim_count, $index_access.index_count);
        }else{
          $$.val = axo_arr_access_to_str(&@1, $1, &@2, $2);
          $$.typ = arr_typ.subtyp;
          $$.lval_kind = ($1.lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        }
        break;
      case axo_ptr_kind:
        if ($index_access.index_count != 1)
          yyerror(&@2, "Expected a 1 dimensional index to access a pointer, but got %d dimensional index.", $index_access.index_count);
        $$.typ = *axo_subtyp($1.typ);
        $$.val = fmtstr("%s[%s]", $1.val, $2.indexes[0].val);
        break;
      default:
        yyerror(&@1, "Cannot index an expression of type '%s'.", axo_typ_to_str($1.typ));
        break;
    }
    $$.kind=axo_expr_normal_kind;
  }
  | expr DOT_FIELD {
    axo_enum* enumerate;
    axo_struct* structure;
    axo_var* var;
    axo_module* mod;
    switch($1.kind){
      case axo_expr_module_kind:
        mod = (axo_module*)($1.typ.module);
        var = axo_get_var(state->global_scope, fmt_str(s_str(1024), "%s%s", mod->prefix, $DOT_FIELD));        
        if (var == NULL && rval_now)
          yyerror(&@2, "Module '%s' doesn't have variable '%s'.", mod->name, $DOT_FIELD);
        $$ = (axo_expr){
          .val = fmtstr("%s%s", mod->prefix, $DOT_FIELD),
          .typ=(var ? var->typ : axo_no_typ),
          .kind = axo_expr_normal_kind,
          .lval_kind = axo_var_lval_kind
        };
        break;
      case axo_expr_enum_typ_kind:
        enumerate = (axo_enum*)($1.typ.enumerate);
        int index = -1;
        for (int i=0; i<enumerate->len; i++){
          if (strcmp(enumerate->names[i], $2)==0){
            index = i;
            break;
          }
        }
        if (index<0)
         yyerror(&@$, "Enum '%s' doesn't have a field named '%s'.", enumerate->name, $2);
        else{
          $$ = (axo_expr){
            .kind=axo_expr_normal_kind,
            .typ=$1.typ,
            .val=fmtstr("%s$%s", enumerate->name, enumerate->names[index])
          };
        }
        break;
      default:
        switch($1.typ.kind){
          case axo_struct_kind:
            structure = (axo_struct*)($1.typ.structure);
            int index = -1;
            for (int i=0;i<structure->fields_len; i++){
              if (strcmp(structure->fields[i].name, $2)==0){
                index = i;
                break;
              }
            }
            if (index<0) yyerror(&@$, "Struct '%s' doesn't have a field named '%s'.", structure->name, $2);
            else{
              $$ = (axo_expr){
                .kind=axo_expr_normal_kind,
                .val=fmtstr("%s.%s", $1.val, $2),
                .typ=structure->fields[index].typ
              };
            }
            break;
          case axo_arr_kind: //.len, .data, .dims
            $$ = axo_get_array_field(state, &@1, &@2, $1, $2);
            break;
          default:
            yyerror(&@1, "Cannot get field of type '%s'", axo_typ_to_str($1.typ));
          break;
        }
        break;
    }
  }
  | arr_literal
  | incr_decr_op
  | expr '.' '(' val_typ ')' {
    switch($1.typ.kind){
      case axo_simple_kind:
        if ($val_typ.kind != axo_simple_kind)
          yyerror(&@$, "Cannot cast type '%s' to '%s'.", axo_typ_to_str($1.typ), axo_typ_to_str($val_typ));
        else
          $$ = (axo_expr){
            .typ=$val_typ,
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str($val_typ), $1.val),
            .kind=axo_expr_normal_kind,
            .lval_kind=$1.lval_kind
          };
        break;
      case axo_ptr_kind:
        if ($val_typ.kind != axo_ptr_kind)
          yyerror(&@$, "Cannot cast type '%s' to '%s'.", axo_typ_to_str($1.typ), axo_typ_to_str($val_typ));
        else
          $$ = (axo_expr){
            .typ=$val_typ,
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str($val_typ), $1.val),
            .kind=axo_expr_normal_kind,
            .lval_kind=$1.lval_kind
          };
        break;
      default:
          yyerror(&@$, "Cannot cast type '%s' to '%s'.", axo_typ_to_str($1.typ), axo_typ_to_str($val_typ));
        break;
    }
  }
  ;

stat_arr_literal_start : arr_lit_start expr ',' expr {
    axo_validate_rval(&@2, $2);
    axo_validate_rval(&@4, $4);
    if (!axo_typ_eq($2.typ, $4.typ)){
            yyerror(&@4, "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str($4.typ), axo_typ_to_str($2.typ));
    }
    $$ = (axo_arr_lit){
      .dynamic=$arr_lit_start,
      .len=(int[]){0},
      .dim_count=1,
      .count=2,
      .val=fmtstr("%s,%s", $2.val, $4.val),
      .typ=$2.typ
    };
  }
  | empty_arr_dims ']' '[' expr ',' expr {
    axo_validate_rval(&@4, $4);
    axo_validate_rval(&@6, $6);
    if (!axo_typ_eq($4.typ, $6.typ)){
            yyerror(&@6, "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str($6.typ), axo_typ_to_str($4.typ));
    }
    $$ = (axo_arr_lit){
      .dynamic=$empty_arr_dims.dynamic,
      .len=$1.len,
      .dim_count=$1.dim_count,
      .count=2,
      .val= fmtstr("%s, %s", $4.val, $6.val),
      .typ=$4.typ
    };
  }
  | stat_arr_literal_start ',' expr {
    axo_validate_rval(&@3, $3);
    if (!axo_typ_eq($$.typ, $3.typ)){
            yyerror(&@3, "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str($3.typ), axo_typ_to_str($$.typ));
    }
    strapnd(&$$.val, ",");
    strapnd(&$$.val, $3.val);
    $$.count++;
  }
  ;

arr_lit_start : '[' {
    $$ = false;
  }
  | '[' '?' {
    $$ = true;
  }
  ;

empty_arr_dims : arr_lit_start INTEGER_LITERAL {
    $$ = (axo_empty_arr_lit){
      .dynamic=$arr_lit_start,
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    $$.len[0] = atoi($2);
  }
  | empty_arr_dims '|' INTEGER_LITERAL {
    $$.len[$$.dim_count++] = atoi($3);
  }
  ;

stat_arr_literal : arr_lit_start expr ',' ']' {
    axo_typ subtyp[1] = {$expr.typ};
    $$ = (axo_arr_lit){
      .dynamic=$arr_lit_start,
      .len=(int[]){1},
      .dim_count=1,
      .count=1,
      .val= $arr_lit_start ?
          fmtstr("axo_arr_new_dyn(axo_dyn_bytes_cpy(%s, (%s){%s}, sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){1}, sizeof(axo_arr_dim_t)))",
          axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=subtyp}), axo_c_arr_of_typ($expr.typ, "1"), $expr.val, axo_typ_to_c_str($expr.typ))
          : fmtstr("axo_arr_new_stat((%s){%s}, ((axo_arr_dim_t[]){1}))",
          axo_c_arr_of_typ($expr.typ, "1"), $expr.val),
      .typ=$2.typ
    };
  }
  | stat_arr_literal_start ']' {
    char* data_str = $$.val;
    $$.val = NULL;
    if ($$.len[0] != 0){
      unsigned expected = 1;
      for (int i=0; i<$$.dim_count; i++)
        expected *= $$.len[i];
      if (expected != $$.count)
        yyerror(&@$, "Expected %u elements, but provided %u.", expected, $$.count);
    }else{
      $$.len = (int[]){$$.count};
      $$.dim_count = 1;
    }
    char* len_str = alloc_str("{");
    char hlpr[128];
    for (int i=0; i<$$.dim_count; i++){
      if (i>0) strapnd(&len_str, ",");
      sprintf(hlpr, "%d", $$.len[i]);
      strapnd(&len_str, hlpr);
    }
    axo_typ subtyp[1] = {$$.typ};
    char count_str[16] = "";
    sprintf(count_str, "%d", $$.count);
    $$.val= $$.dynamic ?
      fmtstr("axo_arr_new_dyn(axo_dyn_bytes_cpy(%s, ((%s){%s}), %u*sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, ((axo_arr_dim_t[])%s}), %d*sizeof(axo_arr_dim_t)))",
      axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=subtyp}), axo_c_arr_of_typ($$.typ, count_str), data_str, $$.count, axo_typ_to_c_str($$.typ), len_str, $$.dim_count)
      : fmtstr("axo_arr_new_stat(((%s){%s}), ((axo_arr_dim_t[])%s}))",
      axo_c_arr_of_typ($$.typ, ""), data_str, len_str);
    free(len_str);
  }
  ;

arr_literal : stat_arr_literal {
    $$=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val=$1.val,
    };
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    arr_typ->subtyp = $1.typ;
    arr_typ->dim_count = $1.dim_count;
    $$.typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ,
      .def=NULL
    };
  }
  | empty_arr_dims ']' val_typ {
    char* dims_str = empty_str;
    unsigned total_sz = 1;
    for (int i=0; i<$1.dim_count; i++){
      total_sz *= $1.len[i];
      if (i>0) strapnd(&dims_str, ",");
      asprintf(&dims_str, "%s%d", dims_str, $1.len[i]);
    }
    strapnd(&dims_str, "");
    axo_typ typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=malloc(sizeof(axo_arr_typ)),
      .def=NULL
    };
    axo_get_arr_typ(typ).subtyp = $val_typ;
    axo_get_arr_typ(typ).dim_count = $empty_arr_dims.dim_count;
    char sz_str[128];
    sprintf(sz_str, "%u", total_sz);
    $$=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val= $1.dynamic ?
          fmtstr("axo_arr_new_dyn(malloc((%u)*sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){%s}, (%d)*sizeof(axo_arr_dim_t)))", total_sz, axo_typ_to_c_str(axo_get_arr_typ(typ).subtyp), dims_str, $empty_arr_dims.dim_count)
          : fmtstr("axo_arr_new_stat((%s){}, ((axo_arr_dim_t[]){%s}))", axo_c_arr_of_typ($val_typ, sz_str), dims_str),
      .typ=typ
    };
  }
  ;

statement : matching_statement | non_matching_statement ;

matching_statement : expr {
    axo_validate_rval(&@expr, $expr);
    $$.val = $1.val;
    strapnd(&($$.val), ";");
    $$.kind = axo_call_statement_kind;
  } %prec EXPR_AS_STATEMENT
  | '$' expr {
    $$.val = $2.val;
    strapnd(&($$.val), ";");
    $$.kind = axo_call_statement_kind;
  }
  | RET_KWRD expr {
    $$.val="return;";
    $$.kind = axo_ret_statement_kind;
    char* ret_assign = axo_get_ret_assign(top_scope);
    if (ret_assign == NULL)
      asprintf(&($$.val), "return %s;", $2.val);
    else
      asprintf(&($$.val), "%s = %s;", ret_assign, $2.val);
  
    if (axo_is_no_typ(top_scope->ret_typ)) //Add line it was done in? FIX
      top_scope->ret_typ = $expr.typ;
    else if(!axo_typ_eq(top_scope->ret_typ, $2.typ)){
      char hlpr[64] = "";
      strcpy(hlpr, axo_typ_to_str(top_scope->ret_typ));
      yyerror(&@2, "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str($2.typ), hlpr);
    }
  }
  | code_scope {
    $$ = axo_scope_to_statement($1);
  }
  | expr '|' val_typ {
    if ($1.lval_kind == axo_var_lval_kind){
      $$ = (axo_statement){
        .kind=axo_var_is_decl_statement_kind,
        .val=axo_name_typ_decl($1.val, $3)
      };
      strapnd(&($$.val), ";");
      axo_set_var(top_scope, (axo_var){.name=$1.val, .typ=axo_clean_typ($3), .is_const=false});
    }else{
      yyerror(&@1, "Cannot declare non-variable value '%s'.", $1.val);
    }
  }
  | expr '|' val_typ '=' expr {
    if ($1.lval_kind == axo_var_lval_kind){
      $$ = (axo_statement){
        .kind=axo_assignment_statement_kind,
        .val = axo_get_var_decl_assign($1.val, (axo_expr){.typ=$val_typ, .val=$5.val})
      };
      strapnd(&($$.val), ";");
      axo_set_var(top_scope, (axo_var){.name=$1.val, .typ=axo_clean_typ($3), .is_const=false});
    }else{
      yyerror(&@1, "Cannot declare non-variable value '%s'.", $1.val);
    }
  }
  | "continue" {
    if (in_loop_count<=0) yyerror(&@1, "No loop to continue.");
    $$ = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = "continue;"
    };
  }
  | "break" {
    if (in_loop_count<=0) yyerror(&@1, "No loop to break out of.");
    $$ = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = "break;"
    };
  }
  | matching_if_statement
  | matching_for_loop
  | matching_while
  | matching_each_loop
  ;

if_condition : IF_KWRD expr {
    axo_validate_rval(&@expr, $expr);
    $$ = $expr;
  }
  ;

matching_if_statement : if_condition matching_statement ELSE_KWRD matching_statement {
    $$.val = fmtstr("if(%s)%s\nelse\n%s", $1.val, $2.val, $4.val);
  }
  ;
  
non_matching_statement : non_matching_if_statement 
  | non_matching_for_loop
  | non_matching_while
  | non_matching_each_loop
  ;

non_matching_if_statement : if_condition statement {
    $$.val = fmtstr("if(%s)\n%s", $1.val, $2.val);
  }
  | if_condition matching_statement ELSE_KWRD non_matching_statement {
    $$.val = fmtstr("if(%s)\n%s\nelse\n%s", $1.val, $2.val, $4.val);
  }
  ;

till_loop_start : TILL_KWRD '(' IDEN  '=' expr ')' {
    $$.iter = $3;
    $$.start = "0";
    $$.lim = $5;
    printf("till iter %s created scope\n", $$.iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=state->int_def->typ, .name=$$.iter, .is_const=false});
  }
  ;

while_loop_base : "while" expr {
    if (axo_validate_rval(&@2, $expr))
      $$ = alloc_str($expr.val);
    in_loop_count++;
  } %prec LOOP_PREC
  ;

matching_while : while_loop_base matching_statement {
    $$ = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", $while_loop_base, $matching_statement.val),
    };
    in_loop_count--;
  }
  ;

non_matching_while : while_loop_base non_matching_statement {
    $$ = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", $while_loop_base, $non_matching_statement.val),
    };
    in_loop_count--;
  }
  ;

for_loop_start : "for" {
    axo_push_scope(scopes, axo_new_scope(top_scope));
  }
  ;

for_loop_init : for_loop_start statement {
    $$.start = $2.val;
  }
  ;

for_loop_base : for_loop_init ',' expr ',' statement {
    axo_validate_rval(&@expr, $expr);
    char* iter = $5.val;
    iter[strlen(iter)-1] = '\0';
    $$ = (axo_for_loop){
      .start = $1.start,
      .condition = $3.val,
      .iteration = iter,
    };
    in_loop_count++;
  } %prec LOOP_PREC
  | till_loop_start {
    $$ = (axo_for_loop){
      .start = fmtstr("int %s=%s;", $1.iter, $1.start),
      .condition = fmtstr("%s<%s", $1.iter, $1.lim.val),
      .iteration = fmtstr("%s++", $1.iter),
    };
    in_loop_count++;
  }
  ;


matching_for_loop : for_loop_base matching_statement {
    $1.body = $2.val;
    $$.kind = axo_for_statement_kind;
    $$.val=axo_for_loop_to_str($1);
    scopes->len--;
    in_loop_count--;
  }
  ;
non_matching_for_loop : for_loop_base non_matching_statement {
    $1.body = $2.val;
    $$.kind = axo_for_statement_kind;
    $$.val=axo_for_loop_to_str($1);
    scopes->len--;
    in_loop_count--;
  }
  ;

each_iter_dims : '[' expr {
    $$ = (axo_each_loop){
      .dim_count=1,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    $$.dim_iters[0] = $2;
    ((YYLTYPE*)($$.locs))[3] = @2;
  }
  | '[' '|' expr {
    $$ = (axo_each_loop){
      .dim_count=2,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    $$.dim_iters[0] = (axo_expr){.val=NULL};
    $$.dim_iters[1] = $3;
    ((YYLTYPE*)($$.locs))[4] = @3;
  }
  | each_iter_dims '|' expr {
    $$.dim_iters[$$.dim_count] = $3;
    ((YYLTYPE*)($$.locs))[3+$$.dim_count++] = @3;
  }
  | each_iter_dims '|' {
    $$.dim_iters[$$.dim_count++] = (axo_expr){.val=NULL};
  }
  ;

each_loop_start : "for" "each" {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    in_loop_count++;
  }
  ;

each_loop_base: each_loop_start identifier "in" expr {
    $$ = (axo_each_loop){
      .dim_count=axo_get_arr_typ($expr.typ).dim_count,
      .dim_iters=malloc(axo_get_arr_typ($expr.typ).dim_count*sizeof(axo_expr)),
      .value_iter=$identifier,
      .collection=$expr,
      .locs=malloc(3*sizeof(YYLTYPE*))
    };
    for (int i=0; i<$$.dim_count; i++)
      $$.dim_iters[i].val = NULL;
    ((YYLTYPE*)($$.locs))[0] = @identifier;
    ((YYLTYPE*)($$.locs))[2] = @expr;
    axo_parse_each_loop(&$$, state, top_scope, in_loop_count);
  }
  | each_loop_start identifier ',' each_iter_dims ']' "in" expr {
    @each_iter_dims.last_column = @5.last_column;
    $$ = (axo_each_loop){
      .dim_count=$each_iter_dims.dim_count,
      .dim_iters=$each_iter_dims.dim_iters,
      .value_iter=(axo_identifier){.kind=axo_no_identifier_kind, .data=NULL},
      .collection=$expr,
      .locs=$each_iter_dims.locs
    };
    ((YYLTYPE*)($$.locs))[0] = @identifier;
    ((YYLTYPE*)($$.locs))[1] = @each_iter_dims;
    ((YYLTYPE*)($$.locs))[2] = @expr;
    axo_parse_each_loop(&$$, state, top_scope, in_loop_count);
  }
  | each_loop_start each_iter_dims ']' ',' identifier "in" expr {
    @each_iter_dims.last_column = @3.last_column;
    $$ = (axo_each_loop){
      .dim_count=$each_iter_dims.dim_count,
      .dim_iters=$each_iter_dims.dim_iters,
      .value_iter=$identifier,
      .collection=$expr,
      .locs=$each_iter_dims.locs
    };
    ((YYLTYPE*)($$.locs))[0] = @identifier;
    ((YYLTYPE*)($$.locs))[1] = @each_iter_dims;
    ((YYLTYPE*)($$.locs))[2] = @expr;
    axo_parse_each_loop(&$$, state, top_scope, in_loop_count);
  }
  | each_loop_start each_iter_dims ']' "in" expr {
    @each_iter_dims.last_column = @3.last_column;
    $$ = (axo_each_loop){
      .dim_count=$each_iter_dims.dim_count,
      .dim_iters=$each_iter_dims.dim_iters,
      .value_iter=(axo_identifier){.kind=axo_no_identifier_kind, .data=NULL},
      .collection=$expr,
      .locs=$each_iter_dims.locs
    };
    ((YYLTYPE*)($$.locs))[1] = @each_iter_dims;
    ((YYLTYPE*)($$.locs))[2] = @expr;
    axo_parse_each_loop(&$$, state, top_scope, in_loop_count);
  }
  ;


matching_each_loop : each_loop_base matching_statement {
    $1.body = $2.val;
    $$ = axo_each_to_statement($1);
    scopes->len--;
    in_loop_count--;
  }
  ;

non_matching_each_loop : each_loop_base non_matching_statement {
    $1.body = $2.val;
    $$ = axo_each_to_statement($1);
    scopes->len--;
    in_loop_count--;
  }
  ;

assign_op : '=' {
    rval_now = true;
  } %prec '='
  ;

assignment : expr assign_op expr {
    $$.kind=axo_expr_normal_kind;
    axo_typ l_typ = $1.typ;
    switch($1.lval_kind){
      case axo_var_lval_kind:
        if ($1.typ.kind == axo_no_kind){
          l_typ = axo_clean_typ($3.typ);
          $$.val = axo_get_var_decl_assign($1.val, (axo_expr){.typ=l_typ, .val=$3.val});
          axo_set_var(top_scope, (axo_var){.typ = l_typ, .name = $1.val, .is_const=false});
        }else{
          $$.val = fmtstr("%s=%s",$1.val, $3.val);
        }
        break;
      case axo_not_lval_kind:
        yyerror(&@1, "Cannot assign to a non-lvalue");
        break;
      default:
        if (!axo_typ_eq(l_typ, $3.typ))
          yyerror(&@$, "Cannot assign '%s' to '%s'.", axo_typ_to_str($3.typ), axo_typ_to_str(l_typ));
        else{
          $$.val = fmtstr("%s=%s",$1.val, $3.val);
        }
        break;
    }
    $$.typ = l_typ;
    rval_now=false;
  } %prec '='
  ;

arr_multidim_typ : '[' '|' {
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    *arr_typ = (axo_arr_typ){
      .dim_count=2
    };
    $$ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ
    };
  }
  | arr_multidim_typ '|' {
    $$=$1;
    axo_get_arr_typ($$).dim_count++;
  }
  ;

arr_typ : '[' ']' val_typ {
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    *arr_typ = (axo_arr_typ){
      .subtyp=$val_typ,
      .dim_count=1
    };
    $$ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ
    };
  }
  | arr_multidim_typ ']' val_typ {
    $$ = $arr_multidim_typ;
    axo_get_arr_typ($$).subtyp = $val_typ;
  }
  ;

func_typ_start : '(' val_typ FN_KWRD {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=$2;
    $$ = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  } 
  | '(' FN_KWRD {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=axo_no_typ;
    $$ = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  }
  ;

func_typ_args : func_typ_start val_typ {
    $$=$1;
    axo_func_typ* func_typ = (axo_func_typ*)($$.func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = $2;
    func_typ->args_defs[0] = axo_typ_def_val($2);
    func_typ->args_len++;
  }
  | func_typ_args ',' val_typ {
    $$=$1;
    axo_func_typ* func_typ = (axo_func_typ*)($$.func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = $3;
    func_typ->args_defs[func_typ->args_len] = axo_typ_def_val($3);
    func_typ->args_len++;
  }
  ;

func_typ : func_typ_start ')' {$$=$1;}
  | func_typ_args ')' {$$=$1;}
  ;

val_typ : IDEN {
    axo_typ_def* def = axo_get_typ_def(state, $1);
    if (def==NULL)
      yyerror(&@1, "Type '%s' isn't defined.", $1);
    else
      $$=def->typ;
  }
  | '@' val_typ {
    $$.kind = axo_ptr_kind;
    $$.subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp($$)=$2;
  }
  | func_typ
  | arr_typ
  ;
  
c_typ : val_typ
  | '.' '.' '.' {
    $$.kind = axo_c_arg_list_kind;
  }
  ;

c_typ_list : /*  EMPTY  */ {
    $$.len = 0;
    $$.values = NULL;
  }
  | c_typ {
    $$.values = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    $$.values[0] = $1;
    $$.len = 1;
  }
  | c_typ_list ',' c_typ {
    if ($1.values[$1.len-1].kind == axo_c_arg_list_kind)
      yyerror(&@1, "The C v_args argument has to be the last one.");
    $$ = $1;
    if ($$.len % axo_func_args_cap == 0)
      $$.values = (axo_typ*)realloc($$.values, ($$.len+axo_func_args_cap)*sizeof(axo_typ));
    $$.values[$$.len] = $3;
    $$.len++;
  }
  ;

called_expr : expr '(' {
    if (axo_validate_rval(&@expr, $expr)){
      switch($1.typ.kind){
        case axo_func_kind:
          $$ = (axo_func_call){
            .typ = $expr.typ,
            .called_val = $expr.val,
            .params_len=0,
            .params=NULL
          };
          break;
        default:
          yyerror(&@1, "Cannot call an expression of non-function type '%s'.", axo_typ_to_str($expr.typ));
          break;
      }
    }else{
      yyerror(&@1, "Cannot call an invalid rval.");
    }
    // printf("ret_typ: %s\n", axo_typ_to_str(((axo_func*)($$.typ.func_typ))->f_typ.ret_typ));
  } %prec CALL_PREC
  | expr ':' IDEN '(' {
    axo_expr passed_expr;
    switch($expr.typ.kind){
      case axo_enum_kind:
      case axo_simple_kind:
      case axo_struct_kind:
        if ($expr.lval_kind == axo_not_lval_kind){
          yyerror(&@1, "Cannot reference a non-lvalue expression to call a method.");
        }else{
          char* fn_name = fmtstr("met_%s_%s", axo_typ_to_str($expr.typ), $IDEN);
          axo_var* var = axo_get_var(top_scope, fn_name);
          if (var == NULL && rval_now)
            yyerror(&@1, "Method '%s' undefined before usage.", $IDEN);
          else{
            if (var->typ.kind != axo_func_kind){
              yyerror(&@3, "Attempted to call a non-function method. (Naming clash?)");  
            }else{
              passed_expr = (axo_expr){
                .kind=axo_expr_normal_kind,
                .lval_kind=axo_not_lval_kind,
                .val=fmtstr("(&(%s))", $expr.val),
                .typ=(axo_typ){
                  .kind=axo_ptr_kind,
                  .subtyp=alloc_one(axo_typ)
                }
              };
              *axo_subtyp(passed_expr.typ) = $expr.typ;
              $$ = (axo_func_call){
                .typ = var->typ,
                .called_val = fn_name,
                .params_len=1,
                .params=(axo_expr*)malloc(axo_func_args_cap*sizeof(axo_expr))
              };
              $$.params[0] = passed_expr;
            }
          }
        }        
        break;
        case axo_arr_kind:
          passed_expr = (axo_expr){
            .kind=axo_expr_normal_kind,
            .lval_kind=axo_not_lval_kind,
            .val=fmtstr("(&(%s))", $expr.val),
            .typ=(axo_typ){
              .kind=axo_ptr_kind,
              .subtyp=alloc_one(axo_typ)
            }
          };
          *axo_subtyp(passed_expr.typ) = $expr.typ;
          $$ = axo_get_array_method(state, &@expr, &@IDEN, passed_expr, $IDEN);
          break;
      default:
        yyerror(&@1, "Methods can only operate on simple types (primitives, enums or structures), not '%s'.", axo_typ_to_str($expr.typ));
        break;
    }
  
  }
  | expr '$' IDEN '(' {
    if ($expr.typ.kind != axo_ptr_kind){
      yyerror(&@1, "Methods cannot operate on '%s', only on pointers to simple types (primitives, enums or structures).", axo_typ_to_str($expr.typ));
    }else{
      axo_typ subtyp = *axo_subtyp($expr.typ);
      char* fn_name = fmtstr("met_%s_%s", axo_typ_to_str(subtyp), $IDEN);
      axo_var* var = axo_get_var(top_scope, fn_name);
      switch(subtyp.kind){
        case axo_enum_kind:
        case axo_simple_kind:
        case axo_struct_kind:
          if (var == NULL && rval_now)
            yyerror(&@1, "Method '%s' undefined before usage.", $IDEN);
          else{
            if (var->typ.kind != axo_func_kind){
              yyerror(&@3, "Attempted to call a non-function method. (Naming clash?)");  
            }else{
              $$ = (axo_func_call){
                .typ = var->typ,
                .called_val = fn_name,
                .params_len=1,
                .params=(axo_expr*)malloc(axo_func_args_cap*sizeof(axo_expr))
              };
              $$.params[0] = $expr;
            }
          }
          break;
        case axo_arr_kind:
          $$ = axo_get_array_method(state, &@expr, &@IDEN, $expr, $IDEN);
          break;
        default:
          yyerror(&@1, "Methods cannot operate on '%s', only on pointers to simple types (primitives, enums or structures).", axo_typ_to_str($expr.typ));
          break;
      }
    }
  } %prec CALL_PREC
  ;

func_call_start : called_expr {
    axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
    if ($$.params_len<fnt->args_len){
      resize_dyn_arr_if_needed(axo_expr, $$.params, $$.params_len, axo_func_args_cap);
      $$.params[$$.params_len].val = fnt->args_defs[$$.params_len];
      $$.params_len++;
    }
  }
  | called_expr expr {
    if (axo_validate_rval(&@expr, $expr)) {
      axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
      if ($$.params_len <= fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[$$.params_len], $expr.typ))
          yyerror(&@2, "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[$$.params_len]), $$.params_len+1, axo_typ_to_str($expr.typ));
        else{
          resize_dyn_arr_if_needed(axo_expr, $$.params, $$.params_len, axo_func_args_cap);
          $$.params[$$.params_len++] = $expr;
        }
      }else{
        if (fnt->args_types[0].kind != axo_c_arg_list_kind)
          yyerror(&@1, "Too many parameters for function type '%s'", axo_typ_to_str($1.typ));
      }
    }
  }
  | func_call_start ',' expr {
    axo_validate_rval(&@3, $3);
    axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
    resize_dyn_arr_if_needed(axo_expr, $$.params, $$.params_len, axo_func_args_cap);
    int i = $$.params_len;
    if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
      if (i < fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[i], $expr.typ))
          yyerror(&@3, "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[i]), i, axo_typ_to_str($expr.typ));
      }else{
          yyerror(&@3, "Too many parameters for function type '%s'", axo_typ_to_str($1.typ));
      }
    }
    $$.params[i] = $expr;
    $$.params_len++;
  }
  | func_call_start ',' {
    $$ = $1;
    axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
    char** defaults = fnt->args_defs;
    resize_dyn_arr_if_needed(axo_expr, $$.params, $$.params_len, axo_func_args_cap);
    int i = $$.params_len;
    if (i >= fnt->args_len-1 && fnt->args_types[fnt->args_len-1].kind == axo_c_arg_list_kind)
        yyerror(&@2, "Cannot generate a default param for '...'.");
    else if (i >= fnt->args_len)
        yyerror(&@2, "Too many parameters for function type '%s'", axo_typ_to_str($1.typ));
    $$.params[i].val = defaults[i];
    $$.params_len++;
  }
  ;

func_call : func_call_start ')' {
    $$=$1;
    axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
    if (fnt->args_len>$$.params_len){
      $$.params=(axo_expr*)realloc($$.params, fnt->args_len*sizeof(axo_expr));
      for (int i=$1.params_len; i<fnt->args_len-1; i++){ //Fill with defaults up until pre-last arg!
        $$.params[i] = (axo_expr){.typ=fnt->args_types[i], .val=fnt->args_defs[i]};
      }
      $$.params_len=fnt->args_len-1;
      if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
        $$.params[fnt->args_len-1] = (axo_expr){.typ=fnt->args_types[fnt->args_len-1], .val=fnt->args_defs[fnt->args_len-1]};
        $$.params_len++;
      }
    }
  }
  ;

code_scope_start : '{' {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
  ;
  
code_scope : code_scope_start statements '}' {
    $$ = top_scope;
    scopes->len--;
    if ($$->statements_len == 0)
      yyerror(&@$, "Code scopes cannot be empty.");
  }
  ;

func_def_name : IDEN {
    $$ = (axo_func){
      .name=alloc_str($IDEN),
      .args_names=NULL
    };
  }
  | IDEN DOT_FIELD {
    axo_module* mod = axo_get_module(state, $IDEN);
    if (!mod)
      yyerror(&@IDEN, "Module doesn't exist.");
    else
      $$ = (axo_func){
        .name=fmtstr("%s%s", mod->prefix, $DOT_FIELD),
        .args_names=NULL
      };
  }
  | val_typ ':' IDEN {
    axo_typ* subtyp = alloc_one(axo_typ);
    *subtyp = $val_typ;
    axo_typ typ = (axo_typ){
      .kind=axo_ptr_kind,
      .subtyp=subtyp,
      .def=alloc_str("NULL")
    };
    switch($val_typ.kind){
      case axo_simple_kind:
      case axo_struct_kind:
      case axo_enum_kind:
        $$ = (axo_func){
          .name=fmtstr("met_%s_%s", axo_typ_to_str($val_typ), $IDEN),
          .args_names = (char**)malloc(sizeof(char*)),
          .f_typ = (axo_func_typ){
            .args_len = 1,
            .args_defs = (char**)malloc(sizeof(char*)),
            .args_types = (axo_typ*)malloc(sizeof(axo_typ)),
          }
        };
        $$.f_typ.args_defs[0] = typ.def;
        $$.f_typ.args_types[0] = typ;
        $$.args_names[0] = alloc_str("self");
        break;
      default:
        free(subtyp);
        yyerror(&@1, "Method are only allowed for structs, enums and primitives, but got %s.", axo_typ_kind_to_str($val_typ.kind));
        break;
    }
  }
  ;

func_def_ret_typ : "fn" {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
  }
  | val_typ "fn" {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    top_scope->ret_typ = $val_typ;
    axo_code_scope_started = true;
  }
  ;

func_def_start : func_def_ret_typ func_def_name '(' func_args ')' {
    int args_len = $func_args.f_typ.args_len;
    $$ = (axo_func){
      .name=$func_def_name.name
    };
    if ($func_def_name.args_names){
      args_len += $func_def_name.f_typ.args_len;
      $$.args_names = (char**)malloc(args_len*sizeof(char*));
      $$.f_typ = (axo_func_typ){
        .args_len = 0,
        .args_types=(axo_typ*)malloc(args_len*sizeof(axo_typ)),
        .args_defs=(char**)malloc(args_len*sizeof(char*)),
      };
      for (int i=0; i<$func_def_name.f_typ.args_len; i++){
        $$.args_names[$$.f_typ.args_len] = $func_def_name.args_names[i];
        $$.f_typ.args_types[$$.f_typ.args_len] = $func_def_name.f_typ.args_types[i];
        $$.f_typ.args_defs[$$.f_typ.args_len++] = $func_def_name.f_typ.args_defs[i];
      }
      for (int i=0; i<$func_args.f_typ.args_len; i++){
        $$.args_names[$$.f_typ.args_len] = $func_args.args_names[i];
        $$.f_typ.args_types[$$.f_typ.args_len] = $func_args.f_typ.args_types[i];
        $$.f_typ.args_defs[$$.f_typ.args_len++] = $func_args.f_typ.args_defs[i];
      }
    }else{
      $$.args_names = $func_args.args_names;
      $$.f_typ.args_defs = $func_args.f_typ.args_defs;
      $$.f_typ.args_types = $func_args.f_typ.args_types;
      $$.f_typ.args_len = args_len;
    }
    for (int i = 0; i<$$.f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=$$.args_names[i], .typ=$$.f_typ.args_types[i], .is_const=true});
  }
  ;

struct_literal_start : STRUCT_LITERAL_START {
    axo_typ_def* td = axo_get_typ_def(state, $1);
    if (td==NULL){
      yyerror(&@1, "Structure '%s' undefined before usage.", $1);
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&@1, "Type '%s' is not a struture.", $1);
    }else{
    int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
    $$ = (axo_struct_val){
      .typ=td->typ,
      .fields=(char**)malloc(total_field_count*sizeof(char*)),
      .fields_count=1 //Yes, that's correct
    };
    for (int i=0;i<total_field_count;i++) $$.fields[i]=NULL;
    }
  }
  | STRUCT_LITERAL_START expr {
    
    axo_typ_def* td = axo_get_typ_def(state, $1);
    if (td==NULL){
      yyerror(&@1, "Structure type '%s' undefined before usage.", $1);
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&@1, "Type '%s' is not a struture.", $1);
    }else if (!axo_typ_eq(((axo_struct*)(td->typ.structure))->fields[0].typ, $2.typ)){
      axo_struct* structure = ((axo_struct*)(td->typ.structure));
      yyerror(&@2,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[0].typ), structure->fields[0].name, structure->name, axo_typ_to_str($2.typ));
    }else{
      int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
      $$ = (axo_struct_val){
        .typ=td->typ,
        .fields=(char**)malloc(((axo_struct*)(td->typ.structure))->fields_len*sizeof(char*)),
        .fields_count=1
      };
      for (int i=1;i<total_field_count;i++) $$.fields[i]=NULL;
      $$.fields[0] = $2.val;
    }
  }
  | STRUCT_LITERAL_START IDEN '=' expr {
    axo_typ_def* td = axo_get_typ_def(state, $1);
    axo_struct* structure = (axo_struct*)(td->typ.structure);
    if (td==NULL){
      yyerror(&@1, "Structure type '%s' undefined before usage.", $1);
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&@1, "Type '%s' is not a structure.", $1);
    }else{
      $$ = (axo_struct_val){
        .typ=td->typ,
        .fields=(char**)malloc(((axo_struct*)(td->typ.structure))->fields_len*sizeof(char*)),
        .fields_count=0
      };
      int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
      for (int i=0;i<total_field_count;i++) $$.fields[i]=NULL;
      int index = -1;
      for (int i=0;i<structure->fields_len; i++){
        if (strcmp(structure->fields[i].name, $2)==0){
          index = i;
          break;
        }
      }
      if (index<0) yyerror(&@2, "Structure '%s' doesn't have '%s' field.", structure->name, $2);
      else if (!axo_typ_eq(structure->fields[index].typ, $4.typ)){
        yyerror(&@4,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str($4.typ));
      }else{
        $$.fields[index] = $4.val;
      }
    }
  } %prec STRUCT_LIT_NAMED_FIELD
  | struct_literal_start ',' expr {
    $$=$1;
    axo_struct* structure = (axo_struct*)($$.typ.structure);
    if ($$.fields_count==structure->fields_len){
      yyerror(&@3, "Too many fields provided to structure '%s'.", structure->name);
    }else if (!axo_typ_eq(structure->fields[$$.fields_count].typ, $3.typ)){
        yyerror(&@3,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[$$.fields_count].typ), structure->fields[$$.fields_count].name, structure->name, axo_typ_to_str($3.typ));
    }else if ($$.fields[$$.fields_count]==NULL){
      $$.fields[$$.fields_count] = $3.val;
      $$.fields_count++;
    }else{
      yyerror(&@3, "Structure field '%s' was arleady assigned a value.", ((axo_struct*)($$.typ.structure))->fields[$$.fields_count].name);    
    }
  }
  | struct_literal_start ',' {
    $$=$1;
    axo_struct* structure = (axo_struct*)($$.typ.structure);
    if ($$.fields_count==structure->fields_len){
      yyerror(&@2, "Too many fields provided to structure '%s'.", structure->name);
    }else if ($$.fields[$$.fields_count]==NULL){
      $$.fields[$$.fields_count] = ((axo_struct*)($1.typ.structure))->fields[$$.fields_count].def;
      $$.fields_count++;
    }
  } %prec STRUCT_LIT_NAMED_FIELD
  | struct_literal_start ',' IDEN '=' expr {
    $$=$1;
    axo_struct* structure = (axo_struct*)($$.typ.structure);
    int index = -1;
    for (int i=0;i<structure->fields_len; i++){
      if (strcmp(structure->fields[i].name, $3)==0){
        index = i;
        break;
      }
    }
    if (index<0) yyerror(&@3, "Structure '%s' doesn't have '%s' field.", structure->name, $3);
    else if (!axo_typ_eq(structure->fields[index].typ, $5.typ)){
        yyerror(&@5,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str($5.typ));
    }else if ($$.fields[index]==NULL){
      $$.fields[index] = $5.val;
    }else{
      yyerror(&@3, "Structure field '%s' was arleady assigned a value.", ((axo_struct*)($$.typ.structure))->fields[index].name);    
    }
  }
  ;
  
struct_literal : struct_literal_start '}' {
    $$=$1;
    axo_struct* structure = ((axo_struct*)$$.typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if($$.fields[i] == NULL) $$.fields[i] = structure->fields[i].def;
    }
  }
  ;

func_def : func_def_start code_scope {
    $$.body = $2;
    $$.f_typ.ret_typ = axo_is_no_typ($2->ret_typ) ? axo_none_typ : $2->ret_typ;
    axo_func_typ* fnt_ptr = (axo_func_typ*)malloc(sizeof(axo_func_typ));
    *fnt_ptr = $$.f_typ;
    axo_typ typ = (axo_typ){
      .kind=axo_func_kind,
      .func_typ=fnt_ptr,
      .def=$$.f_typ.args_defs
    };
    axo_set_var(state->global_scope, (axo_var){.name=$$.name, .typ=typ, .is_const=true});
  }
  ;

func_arg : val_typ IDEN {
    $$.name = alloc_str($2);
    $$.typ = $val_typ;
    $$.def = $val_typ.def;
  }
  | IDEN '|' expr {
    $$.name = alloc_str($1);
    $$.typ = $expr.typ;
    $$.typ.def = $expr.val;
  }
  | val_typ IDEN '|' expr {
    if (axo_typ_eq($val_typ, $expr.typ))
      yyerror(&@expr, "Default value doesn't match type.");
    $$.name = alloc_str($2);
    $$.typ = $1;
    $$.typ.def = $expr.val;
  }
  ;

func_args : /*  NO TOKEN */ {
    $$.args_names = NULL;
    $$.f_typ.args_defs = NULL;
    $$.f_typ.args_types = NULL;
    $$.f_typ.args_len = 0;
  }
  | func_arg {
    $$.args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    $$.f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    $$.f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    $$.args_names[0] = $1.name;
    $$.f_typ.args_defs[0] = axo_get_typ_default($1.typ);
    $$.f_typ.args_types[0] = $1.typ;
    $$.f_typ.args_len = 1;
  }
  | func_args ',' func_arg {
    $$ = $1;
    resize_dyn_arr_if_needed(char*, $$.args_names, $$.f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, $$.f_typ.args_defs, $$.f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(axo_typ, $$.f_typ.args_types, $$.f_typ.args_len, axo_func_args_cap);
    $$.args_names[$$.f_typ.args_len] = $3.name;
    $$.f_typ.args_defs[$$.f_typ.args_len] = axo_get_typ_default($3.typ);
    $$.f_typ.args_types[$$.f_typ.args_len] = $3.typ;
    $$.f_typ.args_len++;
  }
  ;

enum_names : IDEN {
    $$.names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    $$.names[0] = alloc_str($1);
    $$.len = 1;
  }
  | enum_names ',' IDEN {
    $$ = $1;
    if ($$.len % axo_enum_names_cap == 0)
    $$.names = (char**)realloc($$.names, ($$.len+axo_enum_names_cap)*sizeof(char*));
    $$.names[$$.len] = alloc_str($3);
    $$.len++;
  }
  ;

%%

void yyerror(YYLTYPE* loc, const char * fmt, ...){
  if (prog_return==0)
    printf(axo_cyan_bg axo_magenta_fg "\aClick an error to learn more."axo_reset_style"\n");
  axo_raise_error;
  va_list args;
  if (loc==NULL){
    printf(axo_red_fg "Error: ");
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf(axo_reset_style"\n");
  }else{
    va_start(args, fmt);
    char* msg;
    vasprintf(&msg, fmt, args);
    char* err_msg = axo_error_with_loc(state, loc, msg);
    va_end(args);
    printf("%s\n", err_msg);
    free(err_msg);
  }
}

void overwrite_file_with_string(char *filepath, char *string) {
  FILE *fp = fopen(filepath, "w");
  if (fp != NULL){
    fwrite(string, 1 , strlen(string) , fp);
    fclose(fp);
  }
}

int playground(){
  int len;
  long long int* msg = axo_encode_easter("Talking to your compiler? That's no good... How about finding some friends instead!", &len);
  printf("Message: %s\n{", axo_decode_easter(msg));
  for (int i=0; i<len; i++){
    if (i>0) printf(", ");
    printf("%lld", msg[i]);
  }
  printf("}\n");
  long long int new_msg[] = {2334956330867777876, 7885630463268646772, 5197223730545977712, 8391735949001783151, 7453010313414796832, 8243311787948077856, 7955925896704976233, 36715014485107};
  
  printf("New message: %s\n", axo_decode_easter(new_msg));
  if (strcmp(axo_decode_easter(msg), axo_decode_easter(new_msg)) == 0)
    printf(axo_green_fg"Matched!"axo_reset_style"\n");
  else
    printf(axo_red_fg"Not matched!"axo_reset_style"\n");
  
  return 0;
}

int main(int argc, char** argv) {
  //Seed the pseudo random number generator
  srand(time(NULL));
  //Start timing the event
  clock_t start, end;
  double cpu_time_used;
  if (test_playground) return playground();
  char* root_p = axo_get_parent_dir(axo_get_exec_path((char[512]){}, 512));
  // printf("Root: %s\n", root_p);
  //Initialize state
  state = axo_new_state(root_p);
  //Load config from axo.config
  // axo_bytes_to_file("axo.config", (char*)(&(state->config)), sizeof(axo_compiler_config));
  // axo_lolprintf(axo_col_sup(state), rand(), "Hello %s!\n", "world");
  size_t cfg_sz;
  axo_compiler_config* cfg = (axo_compiler_config*)axo_file_to_bytes(fmt_str((char[axo_max_path_len]){}, "%s"axo_dir_sep"axo.config", state->root_path), &cfg_sz);
  // printf("%lu\n%lu\n", sizeof(axo_compiler_config), cfg_sz);
  // printf("%d\n", (int)(cfg->timer));
  state->config = *cfg;
  bool measure_time = state->config.timer;
  if (measure_time){
    start = clock();
  }
  char* cmd = argv[1];
  if (strcmp(cmd, "info")==0){
      prog_return = axo_info_cmd(state, argc, argv);
  }else if (strcmp(cmd, "set")==0){
    prog_return = axo_set_cmd(state, argc, argv);
  }else{
    axo_handle_args(state, argc, argv, 1);
    axo_printf = state->silenced ?  axo_no_printf : printf;
    if (state->entry_file){
      //Load default args where needed
      char* input_file_path = state->entry_file;
      state->output_c_file = state->output_c_file ? state->output_c_file : axo_swap_file_extension(input_file_path, ".c");
      state->output_file = state->output_file ? state->output_file : axo_swap_file_extension(input_file_path, AXO_BIN_EXT);
      state->entry_point = state->entry_point ? state->entry_point : alloc_str("axo__main");
      //Scopes table
      scopes = alloc_one(axo_scopes);
      scopes->scopes = NULL;
      scopes->len = 0;
      axo_push_scope(scopes, state->global_scope);
      axo_new_source(state, state->entry_file);
    }else{
      yyerror(NULL, "Entry file wasn't provided.\nUsage: axo <file> |options|");
      return 1;
    }
    axo_add_decl(state, axo_use_module(state, NULL, "core"));
    state->in_core = true;
    //Set entry point
    axo_add_decl(state, (axo_decl){.kind=axo_other_decl_kind, .val=fmtstr("#define AXO_DEFINE_ENTRY_POINT int %s(axo__arr args);\n#define AXO_MAIN_ENTRY_POINT %s", state->entry_point, state->entry_point)});
    //Parse
    yyparse();
    // axo_printf("Parsing done.\n");
    //Handle produced C code
    if (!prog_return){
      char* code = axo_get_code(state);
      overwrite_file_with_string(state->output_c_file, code);
      free(code);
      //Compile program
      char* compiler_cmd;
      int res = 1;
      switch(state->config.cc){
        case axo_gcc_cc_kind:
          compiler_cmd = fmtstr("gcc %s -o %s -g", state->output_c_file, state->output_file);
          res = system(compiler_cmd);
          break;
        default:
          fprintf(stderr, "This C compiler is not yet supported!\n");
          break;
      }
      if (res != 0)
        printf("Error while compiling the output C file! D:\n");
      prog_return = prog_return||res;
      if (state->run){
        #ifdef _WIN32
          prog_return = system(fmt_str((char[512]){}, "%s", state->output_file)) >> 8;
        #else
          prog_return = system(fmt_str((char[512]){}, "./%s", state->output_file)) >> 8;
        #endif
        remove(state->output_file);
        remove(state->output_c_file);
      }else if (!(state->config.keep_c)){
        remove(state->output_c_file);
      }
    }
    // printf("\n\n%s\n", axo_axelotl_str);
  }
  //Time the action if the according option was and is true
  if (state->config.timer && measure_time && !(state->silenced)){
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    axo_lolprintf(state->config.color_support, rand(), "Took: %fs\n", cpu_time_used);
  }
  return prog_return;
}
