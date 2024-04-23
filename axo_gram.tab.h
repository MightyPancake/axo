/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_AXO_GRAM_TAB_H_INCLUDED
# define YY_YY_AXO_GRAM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING_LITERAL = 258,          /* "string literal"  */
    INTEGER_LITERAL = 259,         /* "integer literal"  */
    FLOAT_LITERAL = 260,           /* "float literal"  */
    IDEN = 261,                    /* "identifier"  */
    RET_KWRD = 262,                /* "ret"  */
    BREAK_KWRD = 263,              /* "break"  */
    CONTINUE_KWRD = 264,           /* "continue"  */
    C_INCLUDE_LOCAL = 265,         /* "#include 'local_file'"  */
    C_INCLUDE = 266,               /* "#include"  */
    TAG_TYP = 267,                 /* "#typ"  */
    PROVIDED_TAG = 268,            /* "#provided"  */
    FN_KWRD = 269,                 /* "fn"  */
    WHILE_KWRD = 270,              /* "while"  */
    SWITCH_KWRD = 271,             /* "switch"  */
    CASE_KWRD = 272,               /* "case"  */
    FOR_KWRD = 273,                /* "for"  */
    EACH_KWRD = 274,               /* "each"  */
    IN_KWRD = 275,                 /* "in"  */
    IF_KWRD = 276,                 /* "if"  */
    ELSE_KWRD = 277,               /* "else"  */
    EQ_OP = 278,                   /* "=="  */
    INEQ_OP = 279,                 /* "!="  */
    EQ_SMLR_OP = 280,              /* ">="  */
    EQ_GRTR_OP = 281,              /* "<="  */
    BIT_OR_OP = 282,               /* "or"  */
    BIT_AND_OP = 283,              /* "and"  */
    LOGICAL_OR_OP = 284,           /* "||"  */
    LOGICAL_AND_OP = 285,          /* "&&"  */
    LEFT_SHIFT_OP = 286,           /* "<<"  */
    RIGHT_SHIFT_OP = 287,          /* ">>"  */
    TILL_KWRD = 288,               /* "till"  */
    NULL_KWRD = 289,               /* "null"  */
    INCR_OP = 290,                 /* "++"  */
    DECR_OP = 291,                 /* "--"  */
    ASSIGN_ADD = 292,              /* "+="  */
    ASSIGN_SUB = 293,              /* "-="  */
    ASSIGN_MUL = 294,              /* "*="  */
    ASSIGN_DIV = 295,              /* "/="  */
    ASSIGN_MOD = 296,              /* "%="  */
    ASSIGN_AND_CALL_ERROR = 297,   /* "?="  */
    WALRUS_OP = 298,               /* ":="  */
    ENUM_KWRD = 299,               /* "enum"  */
    STRUCT_KWRD = 300,             /* "struct"  */
    USE_KWRD = 301,                /* "use"  */
    INCLUDE_KWRD = 302,            /* "include"  */
    STRUCT_LITERAL_START = 303,    /* "struct{"  */
    DOT_FIELD = 304,               /* ".field"  */
    MODULE_KWRD = 305,             /* "module"  */
    ARROW_OP = 306,                /* "->"  */
    NONE_KWRD = 307,               /* "none"  */
    IDENTIFIER_PREC = 308,         /* IDENTIFIER_PREC  */
    EXPR_AS_STATEMENT = 309,       /* EXPR_AS_STATEMENT  */
    LOOP_PREC = 310,               /* LOOP_PREC  */
    UMINUS = 311,                  /* UMINUS  */
    CALL_PREC = 312,               /* CALL_PREC  */
    STRUCT_LIT_NAMED_FIELD = 313   /* STRUCT_LIT_NAMED_FIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 166 "axo_gram.y"

  char* str;
  axo_strings strings_type;
  axo_scope* scope;
  axo_expr expression;
  axo_decl declaration_type;
  axo_func function;
  axo_func_arg function_argument;
  axo_func_call function_call;
  axo_typ typ_type;
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
  axo_switch_case case_type;
  axo_switch switch_type;

#line 149 "axo_gram.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (void);


#endif /* !YY_YY_AXO_GRAM_TAB_H_INCLUDED  */
