%option reentrant

%{
  #include "src/utils/utils.h"
  #include "src/axo.h"
  #include "axo_gram.tab.h"
  int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param, yyscan_t scanner);
    YYLTYPE yylloc = (YYLTYPE){
    .first_line = 1,
    .first_column = 1,
    .last_line = 1,
    .last_column = 1
  };
  
  extern int prog_return;
  extern axo_state* state;
  void axo_pop_source(axo_state* st);
  void axo_add_decl(axo_state* st, axo_decl decl);
  int yywrap(yyscan_t yyscanner);
  // void axo_yyerror(YYLTYPE* loc, const char * fmt, ...);
  //Reentrant scanner bs
  // typedef struct yyguts_t *yyscan_t; // Ensure you have this typedef

#define YY_INPUT(buf, result, max_size) \
{ \
  axo_source* src = axo_get_source(state); \
  char* str; \
  switch(src->kind){ \
    case axo_string_source_kind: \
      str = src->str; \
      int LEN = strlen(str + axo_src_index(state)); \
      result = max_size > LEN ? LEN : max_size; \
      if (result>0){ \
        memcpy(buf, str + axo_src_index(state), result); \
      } \
      axo_src_index(state) += result; \
      break; \
    case axo_file_source_kind: \
      if ((result = fread(buf, 1, max_size, yyin)) < 0) \
        YY_FATAL_ERROR("input in flex scanner failed"); \
      break; \
  } \
}

  void bin_to_hex_lit(char *bin, int len) {
    char hex_char[17] = "0123456789ABCDEF";
    int i = 0;
    int j = 0;
    while (i<len){
      int hex = 0;
      int mult = 8;
      while (i<len){
        if (bin[i++] == '1') hex+=mult;
        if (mult == 1) break;
        mult /= 2;
      }
      bin[j++] = hex_char[hex];
    }
    bin[j] = '\0';
  }

  #define axo_adv_loc(ST) ({ \
    yylloc->first_line=yylloc->last_line=axo_line(ST); \
    yylloc->first_column=axo_col(ST); \
    yylloc->last_column=axo_col(ST)=axo_col(ST)+yyleng; \
  })
  #define axo_ret_def(ST) ({ \
    yylloc->first_line=yylloc->last_line=axo_line(ST); \
    yylloc->first_column=axo_col(ST); \
    yylloc->last_column=axo_col(ST)+=yyleng; \
    yylval->str=alloc_str(yytext); \
  })
  #define axo_ret_null(ST) ({ \
    yylloc->first_line=yylloc->last_line=axo_line(ST); \
    yylloc->first_column=axo_col(ST); \
    yylloc->last_column=axo_col(ST)+=yyleng; \
    yylval->str=""; \
  })

  #define ret_null axo_ret_null(state)
  #define ret_def axo_ret_def(state)
  #define adv_loc axo_adv_loc(state)
  
  #define YY_NO_INPUT
  #define YY_USER_ACTION axo_pos(state)+=yyleng;
  
%}
%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x INCLUDE_MORE_ST
%x INCLUDE_ST
%x COMPTIME_LUA_ST

ident_pat [a-zA-Z][0-9a-zA-Z_]*
include_core_pat [0-9a-zA-Z\\_\/\.\-]+
include_path_pat (\<[0-9a-zA-Z\\_\/\.\-]+\>|\"[0-9a-zA-Z\\_\/\.\-]+\")
%%
  
<INITIAL>"/*" {BEGIN(MULTI_LINE_COMMENT);}
<INITIAL>"//" {BEGIN(SINGLE_LINE_COMMENT);}
<SINGLE_LINE_COMMENT>\n {axo_line(state)++; axo_col(state)=1; BEGIN(INITIAL);}
<MULTI_LINE_COMMENT>"*/" {BEGIN(INITIAL);}
<MULTI_LINE_COMMENT>\n {axo_line(state)++; axo_col(state)=1;};
<SINGLE_LINE_COMMENT,MULTI_LINE_COMMENT>. axo_col(state)++;
"#include" {adv_loc; BEGIN(INCLUDE_ST); }
<INCLUDE_ST>{include_path_pat}/\s*\, {ret_def; BEGIN(INCLUDE_MORE_ST); return C_INCLUDE;}
<INCLUDE_ST>{include_path_pat} {ret_def; BEGIN(INITIAL); return C_INCLUDE;}
<INCLUDE_MORE_ST>\, {adv_loc; BEGIN(INCLUDE_ST);}
<INCLUDE_ST,INCLUDE_MORE_ST>[\r\n\t\f\v ]+ {adv_loc;}
<INCLUDE_ST,INCLUDE_MORE_ST>. {
    adv_loc;
    axo_yyerror(yylloc, "Unexpected '%c' in a #include macro.", yytext[0]);
  }
"~~" { BEGIN(COMPTIME_LUA_ST); }
<COMPTIME_LUA_ST>([^~]|~[^~])+ {ret_def; return COMPTIME_LUA_BLOCK;}
<COMPTIME_LUA_ST>"~~" {BEGIN(INITIAL); }
"#source" {ret_null; return SOURCE_TAG; }
"#provided" {ret_null; return PROVIDED_TAG; }
"#typ" {ret_null; return TAG_TYP; }
"#line" {ret_null; return LINE_TAG; }
"#column" {ret_null; return COLUMN_TAG; }
"#file" {ret_null; return FILE_TAG; }
"#flag" {ret_null; return FLAG_TAG; }
"#C" {ret_null; return C_TAG; }
"while" {ret_null; return WHILE_KWRD; }
"switch" {ret_null; return SWITCH_KWRD; }
"case" {ret_null; return CASE_KWRD; }
"enum" {ret_null; return ENUM_KWRD; }
"ret" {ret_null; return RET_KWRD; }
"const" {ret_null; return CONST_KWRD; }
"volatile" {ret_null; return VOLATILE_KWRD; }
"break" {ret_null; return BREAK_KWRD; }
"continue" {ret_null; return CONTINUE_KWRD; }
"fn" {ret_null; return FN_KWRD; }
"if" {ret_null; return IF_KWRD; }
"for" {ret_null; return FOR_KWRD; }
"each" {ret_null; return EACH_KWRD; }
"till" {ret_null; return TILL_KWRD; }
"else" {ret_null; return ELSE_KWRD; }
"struct" {ret_null; return STRUCT_KWRD; }
"in" {ret_null; return IN_KWRD; }
"null" {ret_null; return NULL_KWRD; }
"use" {ret_null; return USE_KWRD; }
"include" {ret_null; return INCLUDE_KWRD; }
"module" {ret_null; return MODULE_KWRD; }
"none" {ret_null; return NONE_KWRD; }
"sz_of" {ret_null; return SZ_OF_KWRD;}
"type_sz" {ret_null; return TYPE_SZ_KWRD;}
"defer" {ret_null; return DEFER_KWRD;}
"__AXO_EXPR_AS_PARSE_RESULT" {
  ret_null;
  return AXO_EXPR_AS_PARSE_RESULT;
}
"__AXO_ARTIFICIAL_EOF_TOKEN" {
  return 0;
}

"or" {ret_null; return BIT_OR_OP; }
"and" {ret_null; return BIT_AND_OP; }

"--" {ret_null; return DECR_OP; }
"++" {ret_null; return INCR_OP; }
"==" {ret_null; return EQ_OP; }
"!=" {ret_null; return INEQ_OP; }
"<=" {ret_null; return EQ_GRTR_OP; }
">=" {ret_null; return EQ_SMLR_OP; }
"||" {ret_null; return LOGICAL_OR_OP; }
"&&" {ret_null; return LOGICAL_AND_OP; }
"<<" {ret_null; return LEFT_SHIFT_OP; }
">>" {ret_null; return RIGHT_SHIFT_OP; }
"->" {ret_null; return ARROW_OP; }

":=" {ret_null; return WALRUS_OP; }
"+=" {ret_null; return ASSIGN_ADD; }
"-=" {ret_null; return ASSIGN_SUB; }
"*=" {ret_null; return ASSIGN_MUL; }
"/=" {ret_null; return ASSIGN_DIV; }
"/=" {ret_null; return ASSIGN_MOD; }
"::" {ret_null; return MODULE_ACCESS; }
"?=" {ret_null; return ASSIGN_AND_CALL_ERROR; }

\"([^"\\]|\\.|\\\n)*\" {ret_def; return(STRING_LITERAL); }
([0-9]+|0x[0-9a-fA-F]+|0b(0|1)+) {
  ret_def;
  //Return the literal directly if it's not binary
  if (yyleng<=3 || yytext[1] != 'b'){
    return(INTEGER_LITERAL);
  }
  bin_to_hex_lit(&(yytext[2]), yyleng-2);
  yytext[1] = 'x';
  char* prev = yylval->str;
  yylval->str=alloc_str(yytext);
  free(prev);
  return(INTEGER_LITERAL);
}
\~[a-zA-Z][0-9a-zA-Z_]* {
  ret_def;
  return COMPTIME_VAR;
}
\~[a-zA-Z][0-9a-zA-Z_]*\( {
  ret_def;
  return COMPTIME_CALL;
}
([0-9]+\.[0-9]+|[0-9]*\.[0-9]+) {ret_def; return FLOAT_LITERAL;}
[a-zA-Z_][0-9a-zA-Z_]* {ret_def; return IDEN; }
\.[a-zA-Z_][0-9a-zA-Z_]* {
    yylloc->first_line=yylloc->last_line=axo_line(state);
    yylloc->first_column=axo_col(state);
    yylloc->last_column=axo_col(state)+=yyleng;
    yylval->str=alloc_str(&(yytext[1]));
    return DOT_FIELD;
}
[a-zA-Z_][0-9a-zA-Z_]*\{ {
  ret_def;
  yylval->str[yyleng-1] = '\0';
  //Super dirty! Changes needed to structure literals
  if (strcmp(yylval->str, "else") == 0){
    unput('{');
    return ELSE_KWRD;
  }else{
    return STRUCT_LITERAL_START;
  }
}
'((\\[abfnrtv\\?'']|a)|(\\[0-7]{1,3})|(\\x[0-9A-Fa-f]+)|.)' {
  ret_def;
  return BYTE_LITERAL;
}
(\!|\+|\-|\*|\/|\(|\)|\=|\{|\}|\$|\,|\:|\>|\<|\.|\[|\]|\?|\_|\@|\%|\^|\||\;) {ret_def; return yytext[0]; }
\n {axo_line(state)++; axo_col(state)=1;}
\r ;
[ \t]+ {axo_col(state)+=yyleng;}
. { 
    ret_null;
    axo_yyerror(NULL, "Unexpected '%c' at %d:%d in input.", yytext[0], yylloc->first_line, yylloc->first_column);
  }

%%
int yywrap(yyscan_t scanner) {
  if (state->in_core){
    state->in_core = false;
    axo_add_decl(state, (axo_decl){.kind=axo_assign_decl_kind, .val=NULL});
    state->modules_decl = state->decls_len-1;
  }
  if (state->sources_len>1){
    axo_pop_source(state);
    return 0;
  }
  return 1;
}

//FIX: else{ ?
