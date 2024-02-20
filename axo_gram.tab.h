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
    C_REGISTER = 267,              /* "#register"  */
    FN_KWRD = 268,                 /* "fn"  */
    WHILE_KWRD = 269,              /* "while"  */
    FOR_KWRD = 270,                /* "for"  */
    EACH_KWRD = 271,               /* "each"  */
    IN_KWRD = 272,                 /* "in"  */
    IF_KWRD = 273,                 /* "if"  */
    ELSE_KWRD = 274,               /* "else"  */
    EQ_OP = 275,                   /* "=="  */
    INEQ_OP = 276,                 /* "!="  */
    EQ_SMLR_OP = 277,              /* ">="  */
    EQ_GRTR_OP = 278,              /* "<="  */
    BIT_OR_OP = 279,               /* "||"  */
    BIT_AND_OP = 280,              /* "&&"  */
    LOGICAL_OR_OP = 281,           /* "or"  */
    LOGICAL_AND_OP = 282,          /* "and"  */
    LEFT_SHIFT_OP = 283,           /* "<<"  */
    RIGHT_SHIFT_OP = 284,          /* ">>"  */
    TILL_KWRD = 285,               /* "till"  */
    INCR_OP = 286,                 /* "++"  */
    DECR_OP = 287,                 /* "--"  */
    ENUM_KWRD = 288,               /* "enum"  */
    STRUCT_KWRD = 289,             /* "struct"  */
    STRUCT_LITERAL_START = 290,    /* "struct{"  */
    DOT_FIELD = 291,               /* ".field"  */
    ARROW_OP = 292,                /* "->"  */
    IS_KWRD = 293,                 /* "is"  */
    IDENTIFIER_PREC = 294,         /* IDENTIFIER_PREC  */
    EXPR_AS_STATEMENT = 295,       /* EXPR_AS_STATEMENT  */
    LOOP_PREC = 296,               /* LOOP_PREC  */
    UMINUS = 297,                  /* UMINUS  */
    STRUCT_LIT_NAMED_FIELD = 298   /* STRUCT_LIT_NAMED_FIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "axo_gram.y"

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
  axo_arr_lit arr_lit_type;
  axo_empty_arr_lit empty_arr_lit_type;
  axo_index_access index_access_type;
  axo_each_loop each_loop_type;

#line 130 "axo_gram.tab.h"

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
