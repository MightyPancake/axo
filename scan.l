%{
  #define YY_DECL int yylex (YYSTYPE * yylval, struct YYLTYPE * yylloc)
  #include "util/mem.h"
  #include "axo/types.h"
  #include <stdio.h>
  #include "axo_gram.tab.h"
  extern int prog_return;
  int yywrap(void);
  int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
  void yyerror(YYLTYPE* loc, const char * fmt, ...);
  #define adv_loc ({ \
    yylloc->first_line=yylloc->last_line=line; \
    yylloc->first_column=col; \
    yylloc->last_column=col=col+yyleng; \
  })
  #define ret_def ({ \
    yylloc->first_line=yylloc->last_line=line; \
    yylloc->first_column=col; \
    yylloc->last_column=col=col+yyleng; \
    yylval->str=alloc_str(yytext); \
  })
  #define ret_null ({ \
    yylloc->first_line=yylloc->last_line=line; \
    yylloc->first_column=col; \
    yylloc->last_column=col=col+yyleng; \
    yylval->str=""; \
  })
  int line = 1;
  int col = 1;
  #define YY_NO_INPUT
  
%}
%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x INCLUDE_MORE_ST
%x INCLUDE_ST

ident_pat [a-zA-Z][0-9a-zA-Z_]*
include_core_pat [0-9a-zA-Z\\_\/\.\-]+
include_path_pat (\<[0-9a-zA-Z\\_\/\.\-]+\>|\"[0-9a-zA-Z\\_\/\.\-]+\")
%%
  
<INITIAL>"/*" {BEGIN(MULTI_LINE_COMMENT);}
<INITIAL>"//" {BEGIN(SINGLE_LINE_COMMENT);}
<SINGLE_LINE_COMMENT>\n {line++; col=1; BEGIN(INITIAL);}
<MULTI_LINE_COMMENT>"*/" {BEGIN(INITIAL);}
<MULTI_LINE_COMMENT>\n {line++; col=1;};
<SINGLE_LINE_COMMENT,MULTI_LINE_COMMENT>. col++;
"#register" {ret_null; return(C_REGISTER); }
"#include" {adv_loc; BEGIN(INCLUDE_ST); }
<INCLUDE_ST>{include_path_pat}/\s*\, {ret_def; BEGIN(INCLUDE_MORE_ST); return C_INCLUDE;}
<INCLUDE_ST>{include_path_pat} {ret_def; BEGIN(INITIAL); return C_INCLUDE;}
<INCLUDE_MORE_ST>\, {adv_loc; BEGIN(INCLUDE_ST);}
<INCLUDE_ST,INCLUDE_MORE_ST>[\r\n\t\f\v ]+ {adv_loc;}
<INCLUDE_ST,INCLUDE_MORE_ST>. {
    adv_loc;
    yyerror(yylloc, "Unexpected '%c' in a #include macro.", yytext[0]);
  }

"while" {ret_null; return WHILE_KWRD; }
"enum" {ret_null; return ENUM_KWRD; }
"ret" {ret_null; return RET_KWRD; }
"break" {ret_null; return BREAK_KWRD; }
"continue" {ret_null; return CONTINUE_KWRD; }
"fn" {ret_null; return FN_KWRD; }
"if" {ret_null; return IF_KWRD; }
"for" {ret_null; return FOR_KWRD; }
"each" {ret_null; return EACH_KWRD; }
"till" {ret_null; return TILL_KWRD; }
"else" {ret_null; return ELSE_KWRD; }
"struct" {ret_null; return STRUCT_KWRD; }
"is" {ret_null; return IS_KWRD; }
"in" {ret_null; return IN_KWRD; }
"or" {ret_null; return LOGICAL_OR_OP; }
"and" {ret_null; return LOGICAL_AND_OP; }
"null" {ret_null; return NULL_KWRD; }
"use" {ret_null; return USE_KWRD; }
"include" {ret_null; return INCLUDE_KWRD; }

"--" {ret_null; return DECR_OP; }
"++" {ret_null; return INCR_OP; }
"==" {ret_null; return EQ_OP; }
"!=" {ret_null; return INEQ_OP; }
"<=" {ret_null; return EQ_GRTR_OP; }
">=" {ret_null; return EQ_SMLR_OP; }
"||" {ret_null; return BIT_OR_OP; }
"&&" {ret_null; return BIT_AND_OP; }
"<<" {ret_null; return LEFT_SHIFT_OP; }
">>" {ret_null; return RIGHT_SHIFT_OP; }
"->" {ret_null; return ARROW_OP; }

\"[^\"\n]*\" {ret_def; return(STRING_LITERAL); }
[0-9]+ {ret_def; return(INTEGER_LITERAL); }
([0-9]+\.[0-9]*|[0-9]*\.[0-9]+) {ret_def; return FLOAT_LITERAL;}
[a-zA-Z][0-9a-zA-Z_]* {ret_def; return IDEN; }
\.[a-zA-Z][0-9a-zA-Z_]* {
    yylloc->first_line=yylloc->last_line=line;
    yylloc->first_column=col;
    yylloc->last_column=col=col+yyleng;
    yylval->str=alloc_str(&(yytext[1]));
    return DOT_FIELD;
}
[a-zA-Z][0-9a-zA-Z_]*\{ {
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
(\+|\-|\*|\/|\(|\)|\=|\{|\}|\$|\,|\:|\>|\<|\.|\[|\]|\?|\_|\@|\%|\^|\|) {ret_def; return yytext[0]; }
\n {line++; col=1;}
\r ;
[ \t]+ {col=col+yyleng;}
. { printf("Lexical error: unexpected '%c' in input file\n", yytext[0]);
    return -1;
  }
%%
int yywrap(void) { return 1; }

//FIX: else{ ?
