%{

  #define YY_DECL int yylex (YYSTYPE* yylval, struct YYLTYPE* yylloc)
  #include "util/utils.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "axo/axo.h"
  extern int yylineno;
  extern FILE *yyin;
  extern YYLTYPE yylloc;
  extern YYSTYPE yylval;
  int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
  void yyerror(YYLTYPE* loc, const char *, ...);
  int yyparse(void);
  //State
  #define top_scope axo_scopes_top(scopes)
  axo_state* state;
  axo_scope* global_scope;
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
%token<str> FN_KWRD "fn"
%token<str> WHILE_KWRD "while"
%token<str> FOR_KWRD "for"
%token<str> IF_KWRD "if"
%token<str> ELSE_KWRD "else"
%token<str> EQ_OP "=="
%token<str> INEQ_OP "!="
%token<str> EQ_SMLR_OP ">="
%token<str> EQ_GRTR_OP "<="
%token<str> LOGICAL_OR_OP "||"
%token<str> LOGICAL_AND_OP "&&"
%token<str> TILL_KWRD "till"
%token<str> INCR_OP "++"
%token<str> DECR_OP "--"
%token<str> ENUM_KWRD "enum"
%token<str> STRUCT_KWRD "struct"
%token<str> STRUCT_LITERAL_START "struct{"
%token<str> DOT_FIELD ".field"
%token<str> ARROW_OP "->"
%token<str> IS_KWRD "is"
%type<scope> code_scope code_scope_start
%type<function> func_def func_args func_def_start
%type<function_call> func_call_start func_call
%type<expression> expr incr_decr_op if_condition assignment
%type<str> statements declarations while_loop_base
%type<typ_type> val_typ c_typ stat_arr_typ dyn_arr_typ func_typ func_typ_start func_typ_args
%type<types_list> c_typ_list
%type<function_argument> func_arg
%type<for_loop_type> for_loop_start for_loop_init for_loop_base
%type<till_loop_type> till_loop_start
%type<enum_type> enum_names
%type<statement_type> statement matching_statement non_matching_statement matching_if_statement non_matching_if_statement non_matching_for_loop matching_for_loop multi_statement non_matching_while matching_while
%type<struct_type> struct_def
%type<struct_val_type> struct_literal_start struct_literal
%type<identifier_type> identifier
%type<stat_arr_val_type> stat_arr_literal_start stat_arr_literal
%type<stat_arr_init_type> stat_arr_init_dims stat_arr_init

//Prec
%left IDENTIFIER_PREC
%left EXPR_AS_STATEMENT
%left EQ_OP '<' '>' EQ_GRTR_OP EQ_SMLR_OP INEQ_OP
%left '+' '-'
%left '*' '/' '%'
%left '@' '^'
%left "||" "&&"
%left DOT_FIELD
%left IF_KWRD
%left '['
%right INCR_OP DECR_OP
%left UMINUS
%left '('
%left '$'
%right '='
%left STRUCT_LIT_NAMED_FIELD
%left '?'
%precedence RET_KWRD

%union {
  char* str;
  axo_strings strings_type;
  axo_scope* scope;
  axo_expr expression;
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
  axo_stat_arr_val stat_arr_val_type;
  axo_stat_arr_init stat_arr_init_type;
}

%%

declarations : /* EMPTY */ {}
  | declarations func_def {
    axo_add_decl(state, axo_func_def_to_decl($2));
  }
  | declarations C_INCLUDE { //Fix: Check if file exists
    axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", $C_INCLUDE), .kind=axo_c_include_decl_kind});
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
      axo_set_var(global_scope, (axo_var){.name=field, .typ=axo_no_typ, .is_const=true});
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
  | declarations struct_def { //Fix! Make this use realloc less
    new_ptr_one(strct, axo_struct);
    *strct = $2;
    char* decl = empty_str;
    strapnd(&decl, "typedef struct ");
    strapnd(&decl, $2.name);
    strapnd(&decl, "{\n");
    for (int i=0; i<$2.fields_len; i++){
      strapnd(&decl, axo_name_typ_decl($2.fields[i].name, $2.fields[i].def.typ));
      strapnd(&decl, ";\n");
    }
    strapnd(&decl, "}");
    strapnd(&decl, $2.name);
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
    axo_add_decl(state, (axo_decl){.val=decl, .kind=axo_struct_decl_kind});
  }
  ;

statements : /* EMPTY */ {}
  | statements statement {axo_add_statement(top_scope, $2);}
  | statements multi_statement {axo_add_statement(top_scope, $2);}
  ;

multi_statement : stat_arr_init {
    axo_typ typ = $1.code->ret_typ;
    char* ret_arr = top_scope->ret_assign;
    for (int i=0; i<$1.len; i++){
      asprintf(&ret_arr, "%s[%s]", ret_arr, $1.iters[i]);
    }
    for (int i=0; i<$1.code->statements_len; i++){
      if ($1.code->statements[i].kind==axo_ret_statement_kind){
        char* new_ret = fmtstr("%s = %s;", ret_arr, &(($1.code->statements[i].val)[6]));
        free($1.code->statements[i].val);
        $1.code->statements[i].val = new_ret;
      }
    }
    for (int i=$1.len-1; i>=0; i--){
      axo_arr* arr_ptr = alloc_one(axo_arr);
      arr_ptr->sz = $1.dims[i];
      arr_ptr->typ=typ;
      typ.arr = arr_ptr;
      typ.kind = axo_stat_arr_kind;
    }
    char* arr_decl = axo_name_typ_decl($1.lval.val, typ);
    char* arr_init = empty_str;
    for (int i=0; i<$1.len; i++){
      char* for_body = fmtstr("for (int %s=0; %s<%d; %s++)\n", $1.iters[i], $1.iters[i], $1.dims[i], $1.iters[i]);
      strapnd(&arr_init, for_body);
      free(for_body);
    }
    strapnd(&arr_init, axo_scope_to_statement($1.code).val);
    $$ = (axo_statement){
      .kind=axo_stat_arr_init_statement_kind,
      .val=fmtstr("%s;\n%s", arr_decl, arr_init)
    };
    free(arr_init);
    free(arr_decl);
  }
  ;

identifier : IDEN {
    axo_typ_def* td = axo_get_typ_def(state, $1);
    if (td != NULL) {
         $$ = (axo_identifier){
        .kind = axo_identifier_typ_kind,
        .data = td
      };
    }else if (false) { //check for module!
    }else{ //Then assume it was a variable
      $$ = (axo_identifier){
        .kind = axo_identifier_var_kind,
        .data = (void*)alloc_str($1)
      };
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

expr : STRING_LITERAL {set_val(&$$, axo_mk_simple_typ("char*"), $1); $$.kind=axo_expr_normal_kind;}
  | INTEGER_LITERAL {set_val(&$$, axo_mk_simple_typ("int"), $1); $$.kind=axo_expr_normal_kind; }
  | FLOAT_LITERAL {set_val(&$$, axo_mk_simple_typ("float"), $1); $$.kind=axo_expr_normal_kind; }
  | expr '+' expr {parse_operator(&@2, &$$, $1, "+", $3); }
  | expr '-' expr {parse_operator(&@2, &$$, $1, "-", $3); }
  | '(' '-' expr ')' {asprintf(&($$.val), "-%s", $3.val); $$.typ = $3.typ; $$.kind = axo_expr_normal_kind; } %prec UMINUS
  | expr '*' expr {parse_operator(&@2, &$$, $1, "*", $3); }
  | expr '/' expr {parse_operator(&@2, &$$, $1, "/", $3); }
  | expr '%' expr {parse_operator(&@2, &$$, $1, "%", $3); }
  | '(' expr ')' {asprintf(&($$.val), "(%s)", $2.val); $$.typ = $2.typ; $$.kind = axo_expr_normal_kind; }
  | '@' expr {
    $$.typ.kind = axo_ptr_kind;
    $$.typ.ptr = malloc(sizeof(axo_ptr));
    axo_ptr* ptr = (axo_ptr*)($$.typ.ptr);
    ptr->typ = $2.typ;
    asprintf(&($$.val), "&%s", $2.val);
  }
  | assignment
  | identifier {
    switch($1.kind){
      case axo_identifier_var_kind:
        char* var_name = (char*)($identifier.data);
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
        axo_typ_def* td = (axo_typ_def*)($1.data);
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
  | '(' expr '?' expr ':' expr ')' {
    if (axo_validate_rval(&@2, $2) && axo_validate_rval(&@4, $4) && axo_validate_rval(&@6, $6)){
      YYLTYPE loc = (YYLTYPE){.first_line=@4.first_line, .first_column=@4.first_column, .last_line=@6.last_line, .last_column=@6.last_column};
      if (axo_typ_eq($4.typ, $6.typ)){
        $$ = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", $2.val, $4.val, $6.val),
          .typ=$4.typ
        };
      }else{
        yyerror(&loc, "Ternary expression attempts to return different types: '%s' and '%s'.", axo_typ_to_str($4.typ), axo_typ_to_str($6.typ));
      }
    }
  }
  | func_call {$$ = axo_call_to_expr($1);}
  | expr '^' {
    $$=$1; //FIX!
  }
  | expr '<' expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<%s", $1.val, $3.val)
    };
  }
  | expr '>' expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>%s", $1.val, $3.val)
    };
  }
  | expr EQ_OP expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s==%s", $1.val, $3.val)
    };
  }
  | expr INEQ_OP expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s!=%s", $1.val, $3.val)
    };
  }
  | expr EQ_SMLR_OP expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>=%s", $1.val, $3.val)
    };
  }
  | expr EQ_GRTR_OP expr {
    $$ = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<=%s", $1.val, $3.val)
    };
  }
  | expr "||" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = axo_mk_simple_typ("bool"),
        .val = fmtstr("%s||%s", $1.val, $3.val)
      };
    }
  }
  | expr "&&" expr {
    if (axo_validate_rval(&@1, $1) && axo_validate_rval(&@3, $3)){
      $$ = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = axo_mk_simple_typ("bool"),
        .val = fmtstr("%s&&%s", $1.val, $3.val)
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
  | expr '[' expr ']'{
    axo_arr* arr;
    switch($1.typ.kind){
      case axo_stat_arr_kind:
        arr = (axo_arr*)($1.typ.arr);
        $$.typ = arr->typ;
        $$.val = fmtstr("%s[%s]", $1.val, $3.val);
        $$.lval_kind = ($1.lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        break;
      case axo_dyn_arr_kind:
        arr = (axo_arr*)($1.typ.arr);
        $$.typ = arr->typ;
        $$.val = fmtstr("%s[%s]", $1.val, $3.val);
        $$.lval_kind = ($1.lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        break;
      default:
        yyerror(&@1, "Cannot index an expression of type '%s'.", axo_typ_to_str($1.typ));
        break;
    }
    $$.kind=axo_expr_normal_kind;
  }
  | expr DOT_FIELD {
    switch($1.kind){
      case axo_expr_enum_typ_kind:
        axo_enum* enumerate = (axo_enum*)($1.typ.enumerate);
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
        if ($1.typ.kind==axo_struct_kind){
          axo_struct* structure = (axo_struct*)($1.typ.structure);
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
              .typ=structure->fields[index].def.typ
            };
          }
        }else{
          yyerror(&@$, "Cannot get field of type '%s'", axo_typ_to_str($1.typ));
        }
        break;
    }
  }
  | stat_arr_literal {
    char* val = alloc_str("{");
    for (int i=0; i<$1.len; i++){
      if (i>0) strapnd(&val, ",");
      strapnd(&val, $1.data[i]);
    }
    strapnd(&val, "}");
    axo_arr* arr_ptr = alloc_one(axo_arr);
    *arr_ptr = (axo_arr){
      .typ=$1.typ,
      .sz=$1.len
    };
    $$ = (axo_expr){
      .kind=axo_expr_normal_kind,
      .typ=(axo_typ){
        .kind=axo_stat_arr_kind,
        .arr=arr_ptr
      },
      .val=val
    };
  }
  | incr_decr_op
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
    $$.kind = axo_ret_statement_kind;
    char* ret_assign = axo_get_ret_assign(top_scope);
    if (ret_assign == NULL)
      asprintf(&($$.val), "return %s;", $2.val);
    else
      asprintf(&($$.val), "%s = %s;", ret_assign, $2.val);
    if (axo_is_no_typ(top_scope->ret_typ)) //Add line it was done in? FIX
      top_scope->ret_typ = $2.typ;
    else if(!axo_typ_eq(top_scope->ret_typ, $2.typ))
      yyerror(&@2, "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str($2.typ), axo_typ_to_str(top_scope->ret_typ));
  }
  | code_scope {
    $$ = axo_scope_to_statement($1);
  }
  | expr IS_KWRD val_typ {
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
    axo_set_var(top_scope, (axo_var){.typ=axo_mk_simple_typ("int"), .name=$$.iter, .is_const=false});
  }
  ;

while_loop_base : WHILE_KWRD '(' expr ')' {
    if (axo_validate_rval(&@3, $expr))
      $$ = alloc_str($expr.val);
    in_loop_count++;
  }
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

non_matching_for_loop : for_loop_base non_matching_statement {
    $1.body = $2.val;
    $$.kind = axo_for_statement_kind;
    $$.val=axo_for_loop_to_str($1);
    scopes->len--;
    in_loop_count--;
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

for_loop_start : FOR_KWRD {
    axo_push_scope(scopes, axo_new_scope(top_scope));
  }
  ;

for_loop_init : for_loop_start '(' statement {
    $$.start = $3.val;
  }
  ;

for_loop_base : for_loop_init ',' expr ',' statement ')' {
    axo_validate_rval(&@expr, $expr);
    char* iter = $5.val;
    iter[strlen(iter)-1] = '\0';
    $$ = (axo_for_loop){
      .start = $1.start,
      .condition = $3.val,
      .iteration = iter,
    };
    in_loop_count++;
  }
  | till_loop_start {
    $$ = (axo_for_loop){
      .start = fmtstr("int %s=%s;", $1.iter, $1.start),
      .condition = fmtstr("%s<%s", $1.iter, $1.lim.val),
      .iteration = fmtstr("%s++", $1.iter),
    };
    in_loop_count++;
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
          $$.val = axo_get_var_decl_assign(&@$, $1.val, (axo_expr){.typ=l_typ, .val=$3.val});
          axo_set_var(top_scope, (axo_var){.typ = l_typ, .name = $1.val, .is_const=false});
        }else{
          $$.val = fmtstr("%s=%s",$1.val, $3.val);
        }
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

stat_arr_init_dims : expr assign_op '[' identifier ARROW_OP INTEGER_LITERAL ']' {
    //FIX! Check if iter is free to use
    $$ = (axo_stat_arr_init){
      .dims = (int*)malloc(axo_stat_arr_literal_cap*sizeof(int)),
      .iters = (char**)malloc(axo_stat_arr_literal_cap*sizeof(char*)),
      .len=1,
      .lval=$1
    };
    $$.dims[0] = atoi($6);
    $$.iters[0] = (char*)($4.data);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    axo_set_var(top_scope, (axo_var){.name=alloc_str(((char*)($4.data))), .typ=state->int_def->typ});
    top_scope->ret_assign = fmtstr("%s[%s]", $1.val, (char*)($4.data));
    rval_now=false;
  } %prec '='
  | stat_arr_init_dims '[' identifier ARROW_OP INTEGER_LITERAL ']' {
    $$=$1;
    if ($$.len % axo_stat_arr_literal_cap == 0){
      $$.dims = (int*)realloc($$.dims, ($$.len+axo_stat_arr_literal_cap)*sizeof(int));
      $$.iters = (char**)realloc($$.iters, ($$.len+axo_stat_arr_literal_cap)*sizeof(char*));
    }
    $$.dims[$$.len] = atoi($5);
    $$.iters[$$.len] = (char*)($3.data);
    $$.len++;
    axo_set_var(top_scope, (axo_var){.name=alloc_str(((char*)($3.data))), .typ=state->int_def->typ});
    top_scope->ret_assign = fmtstr("%s[%s]", top_scope->ret_assign, (char*)($3.data));
  }
  ;

stat_arr_init : stat_arr_init_dims code_scope {
    axo_typ r_typ = $2->ret_typ;
    axo_arr* arr;
    for (int i=0; i<$1.len; i++){
      arr = alloc_one(axo_arr);
      arr->typ = r_typ;
      arr->sz = $1.dims[0];
      r_typ = (axo_typ){
        .kind=axo_stat_arr_kind,
        .arr=arr
      };
    }
    axo_typ l_typ=r_typ;
    //Check lval for initialization need, this is messy FIX potentially!
    if ($1.lval.lval_kind == axo_var_lval_kind){
      axo_var* var = axo_get_var(top_scope, $1.lval.val);
      if (var==NULL){
        axo_set_var(top_scope, (axo_var){.typ = r_typ, .name = $1.lval.val, .is_const=false});
      }else{
        l_typ=var->typ;
      }
    }
    if (!axo_typ_eq(l_typ, r_typ))
      yyerror(&@$, "Cannot assign '%s' to '%s'.", axo_typ_to_str(r_typ), axo_typ_to_str(l_typ));
    $$=$1;
    $$.code = $2;
  }
  ;

stat_arr_literal_start : '[' expr {
    $$ = (axo_stat_arr_val){
      .typ=$2.typ,
      .data=(char**)malloc(axo_stat_arr_literal_cap*sizeof(char*)),
      .len=1
    };
    $$.data[0] = $2.val;
  }
  | stat_arr_literal_start ',' expr {
    if (!axo_typ_eq($1.typ, $3.typ))
      yyerror(&@3, "A value of type '%s' cannot be an element of an array of type '%s'.", axo_typ_to_str($3.typ), axo_typ_to_str($1.typ));
    else{
      $$=$1;
      if ($$.len % axo_stat_arr_literal_cap == 0)
        $$.data = (char**)realloc($$.data, ($$.len+axo_stat_arr_literal_cap)*sizeof(char*));
      $$.data[$$.len] = $3.val;
      $$.len++;
    }
  }
  ;

stat_arr_literal : stat_arr_literal_start ']'
  ;

stat_arr_typ : '[' INTEGER_LITERAL ']' val_typ{
    $$.kind = axo_stat_arr_kind;
    $$.arr = alloc_one(axo_arr);
    *(axo_arr*)($$.arr) = (axo_arr){
      .typ = $4,
      .sz = atoi($2)
    };
  }
  ;

dyn_arr_typ : '[' ']' val_typ {
    $$.kind = axo_dyn_arr_kind;
    $$.arr = alloc_one(axo_arr);
    *(axo_arr*)($$.arr) = (axo_arr){
      .typ = $3,
      .sz = 0
    };
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
    $$.ptr = malloc(sizeof(axo_typ));
    axo_ptr* ptr = $$.ptr;
    ptr->typ = $2;
  }
  | stat_arr_typ
  | func_typ
  | dyn_arr_typ {
    $$.kind = axo_simple_kind;
    $$.simple = alloc_str("DYN_ARR");
  }
  ;
  
c_typ : IDEN {
    $$.kind = axo_simple_kind;
    $$.simple = alloc_str($1);
  }
  | c_typ '*' {
    asprintf(&($1.simple), "%s*", $1.simple);
    $$.simple = $1.simple;
    $$.kind = $1.kind;
  }
  | '.' '.' '.' {
    $$.kind = axo_c_arg_list_kind;
    $$.simple = NULL;
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

func_call_start : expr '(' {
    if (axo_validate_rval(&@1, $1)) {
      switch($1.typ.kind){
        case axo_func_kind:
          axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
          char** defaults = fnt->args_defs;
          $$.typ = $1.typ;
          $$.called_val = $1.val;
          $$.params = (axo_expr*)malloc(sizeof(axo_expr)*axo_func_args_cap);
          if (fnt->args_len>0){
            $$.params[0].val = defaults[0];
            $$.params_len = 1;
          }
          break;
        default:
          yyerror(&@1, "Cannot call a non-funtion value.");
          break;
      }
    }
  }
  | expr '(' expr {
    if (axo_validate_rval(&@1, $1)){
      switch($1.typ.kind){
        case axo_func_kind:
          if (axo_validate_rval(&@3, $3)) {
            axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
            $$.typ = $1.typ;
            $$.called_val = $1.val;
            $$.params = (axo_expr*)malloc(sizeof(axo_expr)*axo_func_args_cap);
            $$.params[0] = $3;
            $$.params_len = 1;
            if ($$.params_len <= fnt->args_len){
              if (!axo_typ_eq(fnt->args_types[0], $3.typ))
                yyerror(&@3, "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[$$.params_len-1]), $$.params_len, axo_typ_to_str($$.params[$$.params_len-1].typ));
            }else{
              if (fnt->args_types[0].kind != axo_c_arg_list_kind)
                yyerror(&@1, "Too many parameters for function type '%s'", axo_typ_to_str($1.typ));
            }
          }
          break;
        default:
          yyerror(&@1, "Cannot call a non-function value of type '%s'.", axo_typ_to_str($$.typ));
          break;
      }
  
    }
  }
  | func_call_start ',' expr {
    $$ = $1;
    axo_func_typ* fnt = (axo_func_typ*)($1.typ.func_typ);
    resize_dyn_arr_if_needed(axo_expr, $$.params, $$.params_len, axo_func_args_cap);
    int i = $$.params_len;
    if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
      if (i < fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[i], $3.typ))
          yyerror(&@3, "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[i]), i, axo_typ_to_str($$.params[i].typ));
      }else{
          yyerror(&@3, "Too many parameters for function type '%s'", axo_typ_to_str($1.typ));
      }
    }
    $$.params[i] = $3;
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
  }
  ;

func_def_start : FN_KWRD IDEN '(' func_args ')' {
    $$.name = alloc_str($IDEN);
    $$.args_names = $func_args.args_names;
    $$.f_typ.args_defs = $func_args.f_typ.args_defs;
    $$.f_typ.args_types = $func_args.f_typ.args_types;
    $$.f_typ.args_len = $func_args.f_typ.args_len;
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    for (int i = 0; i<$$.f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=$$.args_names[i], .typ=$$.f_typ.args_types[i], .is_const=true});
    }
  | FN_KWRD val_typ IDEN '(' func_args ')' {
    $$.name = alloc_str($IDEN);
    $$.args_names = $func_args.args_names;
    $$.f_typ.args_defs = $func_args.f_typ.args_defs;
    $$.f_typ.args_types = $func_args.f_typ.args_types;
    $$.f_typ.args_len = $func_args.f_typ.args_len;
    axo_push_scope(scopes, axo_new_scope(top_scope));
    top_scope->ret_typ = $val_typ;
    axo_code_scope_started = true;
    for (int i = 0; i<$$.f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=$$.args_names[i], .typ=$$.f_typ.args_types[i], .is_const=true});
    }
  ;

struct_def : STRUCT_KWRD IDEN '(' func_args ')' {
    axo_struct_field* fields = (axo_struct_field*)malloc($4.f_typ.args_len*sizeof(axo_struct_field));
    for (int i = 0; i<$4.f_typ.args_len; i++){
      fields[i].name = $4.args_names[i];
      fields[i].def = (axo_expr){.kind=axo_expr_normal_kind, .val=$4.f_typ.args_defs[i], .typ=$4.f_typ.args_types[i]};
    }
    $$ = (axo_struct){
      .name=alloc_str($2),
      .fields=fields,
      .fields_len=$4.f_typ.args_len
    };
  }  ;

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
    }else if (!axo_typ_eq(((axo_struct*)(td->typ.structure))->fields[0].def.typ, $2.typ)){
      axo_struct* structure = ((axo_struct*)(td->typ.structure));
      yyerror(&@2,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[0].def.typ), structure->fields[0].name, structure->name, axo_typ_to_str($2.typ));
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
      else if (!axo_typ_eq(structure->fields[index].def.typ, $4.typ)){
        yyerror(&@4,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].def.typ), structure->fields[index].name, structure->name, axo_typ_to_str($4.typ));
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
    }else if (!axo_typ_eq(structure->fields[$$.fields_count].def.typ, $3.typ)){
        yyerror(&@3,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[$$.fields_count].def.typ), structure->fields[$$.fields_count].name, structure->name, axo_typ_to_str($3.typ));
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
      $$.fields[$$.fields_count] = ((axo_struct*)($1.typ.structure))->fields[$$.fields_count].def.val;
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
    else if (!axo_typ_eq(structure->fields[index].def.typ, $5.typ)){
        yyerror(&@5,"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].def.typ), structure->fields[index].name, structure->name, axo_typ_to_str($5.typ));
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
      if($$.fields[i] == NULL) $$.fields[i] = structure->fields[i].def.val;
    }
  }
  ;

func_def : func_def_start code_scope {
    $$ = $1;
    $$.body = $2;
    $$.f_typ.ret_typ = axo_is_no_typ($2->ret_typ) ? axo_mk_simple_typ("void") : $2->ret_typ;
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
    $$.typ = $1;
    $$.def = $1.def;
  }
  | IDEN ':' expr {
    $$.name = alloc_str($1);
    $$.typ = $3.typ;
    $$.def = $3.val;
  }
  | val_typ IDEN ':' expr {
    $$.name = alloc_str($2);
    $$.typ = $1;
    $$.def = $4.val; //FIX! Look if types match!
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
    $$.f_typ.args_defs[0] = $1.def;
    $$.f_typ.args_types[0] = $1.typ;
    $$.f_typ.args_len = 1;
  }
  | func_args ',' func_arg {
    $$ = $1;
    resize_dyn_arr_if_needed(char*, $$.args_names, $$.f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, $$.f_typ.args_defs, $$.f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(axo_typ, $$.f_typ.args_types, $$.f_typ.args_len, axo_func_args_cap);
    $$.args_names[$$.f_typ.args_len] = $3.name;
    $$.f_typ.args_defs[$$.f_typ.args_len] = $3.def;
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

int main(int argc, char** argv) {
  //Get tokens from the given file instead of stdin
  FILE *file;
  if (argc != 2) {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      return 1;
  }
  file = fopen(argv[1], "r");
  if (!file) {
      perror("fopen");
      return 1;
  }
  yyin = file;
  //Initialize state
  state = axo_new_state();
  state->filepath = argv[1];
  global_scope = state->global_scope;
  //Scopes table
  scopes = alloc_one(axo_scopes);
  scopes->scopes = (axo_scope**)malloc(axo_scopes_table_cap*sizeof(axo_scope*));
  scopes->len = 0;
  axo_push_scope(scopes, global_scope);
  //Parse
  yyparse();
  //Handle produced C code
  if (!prog_return){
    if (state->config.output_name==NULL) state->config.output_name = axo_swap_file_extension(state->filepath, "c");
    char* code = axo_get_code(state);
    overwrite_file_with_string(state->config.output_name, code);
    free(code);
    //Compile program
    char* compiler_cmd;
    int res = 1;
    switch(state->config.cc){
      case axo_gcc_cc_kind:
        compiler_cmd = fmtstr("gcc %s -o %s", state->config.output_name, axo_swap_file_extension(state->config.output_name, "exe"));
        res = system(compiler_cmd);
        break;
      default:
        fprintf(stderr, "This C compiler is not yet supported!\n");
        break;
    }
    if (res != 0)
      printf("Error while compiling the output C file! D:\n");
    prog_return = prog_return||res;
  }
  // printf("\n\n%s\n", axo_axelotl_str);
  fclose(file);
  return prog_return;
}
