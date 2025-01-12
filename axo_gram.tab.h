/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_AXO_GRAM_TAB_H_INCLUDED
# define YY_YY_AXO_GRAM_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING_LITERAL = 258,
     INTEGER_LITERAL = 259,
     FLOAT_LITERAL = 260,
     IDEN = 261,
     RET_KWRD = 262,
     BREAK_KWRD = 263,
     CONTINUE_KWRD = 264,
     C_INCLUDE_LOCAL = 265,
     C_INCLUDE = 266,
     TAG_TYP = 267,
     PROVIDED_TAG = 268,
     FN_KWRD = 269,
     WHILE_KWRD = 270,
     SWITCH_KWRD = 271,
     CASE_KWRD = 272,
     FOR_KWRD = 273,
     EACH_KWRD = 274,
     IN_KWRD = 275,
     IF_KWRD = 276,
     ELSE_KWRD = 277,
     EQ_OP = 278,
     INEQ_OP = 279,
     EQ_SMLR_OP = 280,
     EQ_GRTR_OP = 281,
     BIT_OR_OP = 282,
     BIT_AND_OP = 283,
     LOGICAL_OR_OP = 284,
     LOGICAL_AND_OP = 285,
     LEFT_SHIFT_OP = 286,
     RIGHT_SHIFT_OP = 287,
     TILL_KWRD = 288,
     NULL_KWRD = 289,
     INCR_OP = 290,
     DECR_OP = 291,
     ASSIGN_ADD = 292,
     ASSIGN_SUB = 293,
     ASSIGN_MUL = 294,
     ASSIGN_DIV = 295,
     ASSIGN_MOD = 296,
     ASSIGN_AND_CALL_ERROR = 297,
     WALRUS_OP = 298,
     ENUM_KWRD = 299,
     STRUCT_KWRD = 300,
     USE_KWRD = 301,
     INCLUDE_KWRD = 302,
     STRUCT_LITERAL_START = 303,
     DOT_FIELD = 304,
     MODULE_KWRD = 305,
     ARROW_OP = 306,
     NONE_KWRD = 307,
     BYTE_LITERAL = 308,
     SZ_OF_KWRD = 309,
     TYPE_SZ_KWRD = 310,
     DEFER_KWRD = 311,
     LINE_TAG = 312,
     COLUMN_TAG = 313,
     FILE_TAG = 314,
     FLAG_TAG = 315,
     SOURCE_TAG = 316,
     C_TAG = 317,
     CONST_KWRD = 318,
     MODULE_ACCESS = 319,
     VOLATILE_KWRD = 320,
     COMPTIME_VAR = 321,
     COMPTIME_CALL = 322,
     AXO_EXPR_AS_PARSE_RESULT = 323,
     COMPTIME_LUA_BLOCK = 324,
     IDENTIFIER_PREC = 325,
     EXPR_AS_STATEMENT = 326,
     LOOP_PREC = 327,
     UMINUS = 328,
     CALL_PREC = 329,
     TYPE_Q_PREC = 330,
     STRUCT_LIT_NAMED_FIELD = 331
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 187 "axo_gram.y"

  char* str;
  axo_strings strings_type;
  axo_scope* scope;
  axo_expr expression;
  axo_decl declaration_type;
  axo_func function;
  axo_func_arg function_argument;
  axo_func_call function_call;
  axo_comptime_call comptime_function_call;
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
  axo_var variable_type;


/* Line 2058 of yacc.c  */
#line 163 "axo_gram.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (yyscan_t scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_AXO_GRAM_TAB_H_INCLUDED  */
