/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "axo_gram.y"

  #define test_playground 0
  #define YY_DECL int yylex (YYSTYPE* yylval, struct YYLTYPE* yylloc)
  #include "src/utils/utils.h"
  #include <stdint.h>
  #include "src/axo.h"
  #include "axo_gram.tab.h"
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
  int axo_no_printf(const char* fmt, ...){
    return 0;
  }
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
  #define axo_is_valid_rval(EXPR) (((EXPR).typ.kind!=axo_no_kind) && ((EXPR).kind!=axo_expr_assigned_declaration_kind))
  #define axo_validate_rval(LOC, EXPR) ({ \
    AXO_RVAL_WAS_VALID=true; \
    if (!axo_is_valid_rval(EXPR)){ \
      AXO_RVAL_WAS_VALID=false; \
      if ((EXPR).kind == axo_expr_assigned_declaration_kind) \
        yyerror(LOC, axo_err_msg(axo_undeclared_assignment_expr_err_code)); \
      else if (EXPR.lval_kind==axo_var_lval_kind) \
        yyerror(LOC, axo_err_msg(axo_undeclared_var_err_code)); \
      else \
        yyerror(LOC, axo_err_msg(axo_invalid_rval_err_code)); \
    } \
    AXO_RVAL_WAS_VALID; \
  })

  #define axo_is_valid_expr_as_statement(EXPR) (((EXPR).typ.kind!=axo_no_kind))
  #define axo_validate_expr_as_statement(LOC, EXPR) ({ \
    AXO_RVAL_WAS_VALID=true; \
    if (!axo_is_valid_expr_as_statement(EXPR)){ \
      AXO_RVAL_WAS_VALID=false; \
      if (EXPR.lval_kind==axo_var_lval_kind) \
        yyerror(LOC, axo_err_msg(axo_undeclared_var_err_code)); \
      else \
        yyerror(LOC, axo_err_msg(axo_invalid_rval_err_code)); \
    } \
    AXO_RVAL_WAS_VALID; \
  })
  
  #define axo_none_check(T) ((T).kind == axo_none_kind)

#line 135 "axo_gram.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "axo_gram.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING_LITERAL = 3,             /* "string literal"  */
  YYSYMBOL_INTEGER_LITERAL = 4,            /* "integer literal"  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* "float literal"  */
  YYSYMBOL_IDEN = 6,                       /* "identifier"  */
  YYSYMBOL_RET_KWRD = 7,                   /* "ret"  */
  YYSYMBOL_BREAK_KWRD = 8,                 /* "break"  */
  YYSYMBOL_CONTINUE_KWRD = 9,              /* "continue"  */
  YYSYMBOL_C_INCLUDE_LOCAL = 10,           /* "#include 'local_file'"  */
  YYSYMBOL_C_INCLUDE = 11,                 /* "#include"  */
  YYSYMBOL_TAG_TYP = 12,                   /* "#typ"  */
  YYSYMBOL_PROVIDED_TAG = 13,              /* "#provided"  */
  YYSYMBOL_FN_KWRD = 14,                   /* "fn"  */
  YYSYMBOL_WHILE_KWRD = 15,                /* "while"  */
  YYSYMBOL_SWITCH_KWRD = 16,               /* "switch"  */
  YYSYMBOL_CASE_KWRD = 17,                 /* "case"  */
  YYSYMBOL_FOR_KWRD = 18,                  /* "for"  */
  YYSYMBOL_EACH_KWRD = 19,                 /* "each"  */
  YYSYMBOL_IN_KWRD = 20,                   /* "in"  */
  YYSYMBOL_IF_KWRD = 21,                   /* "if"  */
  YYSYMBOL_ELSE_KWRD = 22,                 /* "else"  */
  YYSYMBOL_EQ_OP = 23,                     /* "=="  */
  YYSYMBOL_INEQ_OP = 24,                   /* "!="  */
  YYSYMBOL_EQ_SMLR_OP = 25,                /* ">="  */
  YYSYMBOL_EQ_GRTR_OP = 26,                /* "<="  */
  YYSYMBOL_BIT_OR_OP = 27,                 /* "or"  */
  YYSYMBOL_BIT_AND_OP = 28,                /* "and"  */
  YYSYMBOL_LOGICAL_OR_OP = 29,             /* "||"  */
  YYSYMBOL_LOGICAL_AND_OP = 30,            /* "&&"  */
  YYSYMBOL_LEFT_SHIFT_OP = 31,             /* "<<"  */
  YYSYMBOL_RIGHT_SHIFT_OP = 32,            /* ">>"  */
  YYSYMBOL_TILL_KWRD = 33,                 /* "till"  */
  YYSYMBOL_NULL_KWRD = 34,                 /* "null"  */
  YYSYMBOL_INCR_OP = 35,                   /* "++"  */
  YYSYMBOL_DECR_OP = 36,                   /* "--"  */
  YYSYMBOL_ASSIGN_ADD = 37,                /* "+="  */
  YYSYMBOL_ASSIGN_SUB = 38,                /* "-="  */
  YYSYMBOL_ASSIGN_MUL = 39,                /* "*="  */
  YYSYMBOL_ASSIGN_DIV = 40,                /* "/="  */
  YYSYMBOL_ASSIGN_MOD = 41,                /* "%="  */
  YYSYMBOL_ASSIGN_AND_CALL_ERROR = 42,     /* "?="  */
  YYSYMBOL_WALRUS_OP = 43,                 /* ":="  */
  YYSYMBOL_ENUM_KWRD = 44,                 /* "enum"  */
  YYSYMBOL_STRUCT_KWRD = 45,               /* "struct"  */
  YYSYMBOL_USE_KWRD = 46,                  /* "use"  */
  YYSYMBOL_INCLUDE_KWRD = 47,              /* "include"  */
  YYSYMBOL_STRUCT_LITERAL_START = 48,      /* "struct{"  */
  YYSYMBOL_DOT_FIELD = 49,                 /* ".field"  */
  YYSYMBOL_MODULE_KWRD = 50,               /* "module"  */
  YYSYMBOL_ARROW_OP = 51,                  /* "->"  */
  YYSYMBOL_NONE_KWRD = 52,                 /* "none"  */
  YYSYMBOL_BYTE_LITERAL = 53,              /* "byte literal"  */
  YYSYMBOL_SZ_OF_KWRD = 54,                /* "sz_of"  */
  YYSYMBOL_TYPE_SZ_KWRD = 55,              /* "type_sz"  */
  YYSYMBOL_DEFER_KWRD = 56,                /* "defer"  */
  YYSYMBOL_LINE_TAG = 57,                  /* "#line"  */
  YYSYMBOL_COLUMN_TAG = 58,                /* "#column"  */
  YYSYMBOL_FILE_TAG = 59,                  /* "#file"  */
  YYSYMBOL_FLAG_TAG = 60,                  /* "#flag"  */
  YYSYMBOL_SOURCE_TAG = 61,                /* "#source"  */
  YYSYMBOL_C_TAG = 62,                     /* "#C"  */
  YYSYMBOL_CONST_KWRD = 63,                /* "const"  */
  YYSYMBOL_MODULE_ACCESS = 64,             /* "::"  */
  YYSYMBOL_VOLATILE_KWRD = 65,             /* "volatile"  */
  YYSYMBOL_IDENTIFIER_PREC = 66,           /* IDENTIFIER_PREC  */
  YYSYMBOL_67_ = 67,                       /* '$'  */
  YYSYMBOL_EXPR_AS_STATEMENT = 68,         /* EXPR_AS_STATEMENT  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_70_ = 70,                       /* '?'  */
  YYSYMBOL_71_ = 71,                       /* '<'  */
  YYSYMBOL_72_ = 72,                       /* '>'  */
  YYSYMBOL_73_ = 73,                       /* '+'  */
  YYSYMBOL_74_ = 74,                       /* '-'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_76_ = 76,                       /* '/'  */
  YYSYMBOL_77_ = 77,                       /* '%'  */
  YYSYMBOL_LOOP_PREC = 78,                 /* LOOP_PREC  */
  YYSYMBOL_79_ = 79,                       /* '.'  */
  YYSYMBOL_80_ = 80,                       /* '!'  */
  YYSYMBOL_81_ = 81,                       /* '('  */
  YYSYMBOL_82_ = 82,                       /* ':'  */
  YYSYMBOL_UMINUS = 83,                    /* UMINUS  */
  YYSYMBOL_84_ = 84,                       /* '@'  */
  YYSYMBOL_85_ = 85,                       /* '^'  */
  YYSYMBOL_CALL_PREC = 86,                 /* CALL_PREC  */
  YYSYMBOL_87_ = 87,                       /* '['  */
  YYSYMBOL_STRUCT_LIT_NAMED_FIELD = 88,    /* STRUCT_LIT_NAMED_FIELD  */
  YYSYMBOL_TYPE_Q_PREC = 89,               /* TYPE_Q_PREC  */
  YYSYMBOL_90_ = 90,                       /* ')'  */
  YYSYMBOL_91_ = 91,                       /* ';'  */
  YYSYMBOL_92_ = 92,                       /* '{'  */
  YYSYMBOL_93_ = 93,                       /* '}'  */
  YYSYMBOL_94_ = 94,                       /* '|'  */
  YYSYMBOL_95_ = 95,                       /* ']'  */
  YYSYMBOL_96_ = 96,                       /* ','  */
  YYSYMBOL_YYACCEPT = 97,                  /* $accept  */
  YYSYMBOL_declarations = 98,              /* declarations  */
  YYSYMBOL_declaration = 99,               /* declaration  */
  YYSYMBOL_c_code = 100,                   /* c_code  */
  YYSYMBOL_global_code_scope_start = 101,  /* global_code_scope_start  */
  YYSYMBOL_global_code_scope = 102,        /* global_code_scope  */
  YYSYMBOL_struct_def = 103,               /* struct_def  */
  YYSYMBOL_module_info = 104,              /* module_info  */
  YYSYMBOL_statements = 105,               /* statements  */
  YYSYMBOL_index_access = 106,             /* index_access  */
  YYSYMBOL_identifier = 107,               /* identifier  */
  YYSYMBOL_incr_decr_op = 108,             /* incr_decr_op  */
  YYSYMBOL_expr = 109,                     /* expr  */
  YYSYMBOL_stat_arr_literal_start = 110,   /* stat_arr_literal_start  */
  YYSYMBOL_arr_lit_start = 111,            /* arr_lit_start  */
  YYSYMBOL_empty_arr_dims = 112,           /* empty_arr_dims  */
  YYSYMBOL_stat_arr_literal = 113,         /* stat_arr_literal  */
  YYSYMBOL_arr_literal = 114,              /* arr_literal  */
  YYSYMBOL_statement = 115,                /* statement  */
  YYSYMBOL_matching_statement = 116,       /* matching_statement  */
  YYSYMBOL_switch_statement_start = 117,   /* switch_statement_start  */
  YYSYMBOL_switch_statement = 118,         /* switch_statement  */
  YYSYMBOL_switch_body = 119,              /* switch_body  */
  YYSYMBOL_switch_branch = 120,            /* switch_branch  */
  YYSYMBOL_switch_case = 121,              /* switch_case  */
  YYSYMBOL_switch_expr_list = 122,         /* switch_expr_list  */
  YYSYMBOL_if_condition = 123,             /* if_condition  */
  YYSYMBOL_matching_if_statement = 124,    /* matching_if_statement  */
  YYSYMBOL_non_matching_statement = 125,   /* non_matching_statement  */
  YYSYMBOL_non_matching_if_statement = 126, /* non_matching_if_statement  */
  YYSYMBOL_till_loop_start = 127,          /* till_loop_start  */
  YYSYMBOL_while_loop_base = 128,          /* while_loop_base  */
  YYSYMBOL_matching_while = 129,           /* matching_while  */
  YYSYMBOL_non_matching_while = 130,       /* non_matching_while  */
  YYSYMBOL_for_loop_start = 131,           /* for_loop_start  */
  YYSYMBOL_for_loop_init = 132,            /* for_loop_init  */
  YYSYMBOL_for_loop_base = 133,            /* for_loop_base  */
  YYSYMBOL_matching_for_loop = 134,        /* matching_for_loop  */
  YYSYMBOL_non_matching_for_loop = 135,    /* non_matching_for_loop  */
  YYSYMBOL_matching_each_loop = 136,       /* matching_each_loop  */
  YYSYMBOL_non_matching_each_loop = 137,   /* non_matching_each_loop  */
  YYSYMBOL_each_iter_dims = 138,           /* each_iter_dims  */
  YYSYMBOL_each_loop_base = 139,           /* each_loop_base  */
  YYSYMBOL_assign_op = 140,                /* assign_op  */
  YYSYMBOL_assignment = 141,               /* assignment  */
  YYSYMBOL_special_assignment = 142,       /* special_assignment  */
  YYSYMBOL_arr_multidim_typ = 143,         /* arr_multidim_typ  */
  YYSYMBOL_arr_typ = 144,                  /* arr_typ  */
  YYSYMBOL_func_typ_start = 145,           /* func_typ_start  */
  YYSYMBOL_func_typ_args = 146,            /* func_typ_args  */
  YYSYMBOL_func_typ = 147,                 /* func_typ  */
  YYSYMBOL_no_q_typ = 148,                 /* no_q_typ  */
  YYSYMBOL_val_typ = 149,                  /* val_typ  */
  YYSYMBOL_type_qualifier = 150,           /* type_qualifier  */
  YYSYMBOL_typ_q = 151,                    /* typ_q  */
  YYSYMBOL_called_expr = 152,              /* called_expr  */
  YYSYMBOL_func_call_start = 153,          /* func_call_start  */
  YYSYMBOL_func_call = 154,                /* func_call  */
  YYSYMBOL_code_scope_start = 155,         /* code_scope_start  */
  YYSYMBOL_code_scope = 156,               /* code_scope  */
  YYSYMBOL_func_def_name = 157,            /* func_def_name  */
  YYSYMBOL_func_def_ret_typ = 158,         /* func_def_ret_typ  */
  YYSYMBOL_func_def_start = 159,           /* func_def_start  */
  YYSYMBOL_struct_literal_start = 160,     /* struct_literal_start  */
  YYSYMBOL_struct_literal = 161,           /* struct_literal  */
  YYSYMBOL_func_def = 162,                 /* func_def  */
  YYSYMBOL_func_arg = 163,                 /* func_arg  */
  YYSYMBOL_func_args = 164,                /* func_args  */
  YYSYMBOL_enum_names = 165                /* enum_names  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2007

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  365

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,    67,    77,     2,     2,
      81,    90,    75,    73,    96,    74,    79,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    91,
      71,    69,    72,    70,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    95,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,    94,    93,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    78,    83,    86,    88,    89
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   210,   210,   211,   215,   233,   267,   272,   299,   334,
     341,   344,   347,   351,   359,   373,   377,   390,   397,   403,
     417,   424,   431,   437,   457,   460,   486,   487,   493,   502,
     508,   524,   529,   537,   539,   548,   549,   550,   558,   574,
     575,   576,   577,   578,   579,   580,   586,   596,   605,   606,
     607,   645,   662,   663,   674,   685,   696,   707,   718,   729,
     738,   749,   758,   767,   776,   799,   828,   832,   841,   850,
     858,   866,   874,   875,   876,   907,   922,   937,   952,   963,
     966,   971,   980,   986,  1002,  1034,  1049,  1078,  1078,  1080,
    1086,  1092,  1111,  1128,  1132,  1146,  1153,  1160,  1163,  1171,
    1188,  1189,  1190,  1191,  1194,  1204,  1214,  1222,  1229,  1233,
    1236,  1250,  1258,  1264,  1270,  1275,  1276,  1277,  1278,  1281,
    1284,  1289,  1299,  1306,  1315,  1324,  1330,  1335,  1345,  1355,
    1363,  1372,  1380,  1388,  1397,  1407,  1411,  1416,  1430,  1444,
    1459,  1464,  1496,  1499,  1502,  1505,  1508,  1513,  1523,  1529,
    1542,  1550,  1561,  1574,  1583,  1594,  1595,  1598,  1606,  1614,
    1617,  1618,  1619,  1627,  1631,  1638,  1639,  1647,  1650,  1655,
    1675,  1681,  1689,  1705,  1721,  1736,  1759,  1765,  1771,  1777,
    1787,  1821,  1826,  1833,  1878,  1894,  1915,  1946,  1960,  1970,
    1992,  2001,  2019,  2026,  2033,  2047,  2053,  2062,  2074,  2079
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"string literal\"",
  "\"integer literal\"", "\"float literal\"", "\"identifier\"", "\"ret\"",
  "\"break\"", "\"continue\"", "\"#include 'local_file'\"", "\"#include\"",
  "\"#typ\"", "\"#provided\"", "\"fn\"", "\"while\"", "\"switch\"",
  "\"case\"", "\"for\"", "\"each\"", "\"in\"", "\"if\"", "\"else\"",
  "\"==\"", "\"!=\"", "\">=\"", "\"<=\"", "\"or\"", "\"and\"", "\"||\"",
  "\"&&\"", "\"<<\"", "\">>\"", "\"till\"", "\"null\"", "\"++\"", "\"--\"",
  "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"?=\"", "\":=\"",
  "\"enum\"", "\"struct\"", "\"use\"", "\"include\"", "\"struct{\"",
  "\".field\"", "\"module\"", "\"->\"", "\"none\"", "\"byte literal\"",
  "\"sz_of\"", "\"type_sz\"", "\"defer\"", "\"#line\"", "\"#column\"",
  "\"#file\"", "\"#flag\"", "\"#source\"", "\"#C\"", "\"const\"", "\"::\"",
  "\"volatile\"", "IDENTIFIER_PREC", "'$'", "EXPR_AS_STATEMENT", "'='",
  "'?'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "LOOP_PREC",
  "'.'", "'!'", "'('", "':'", "UMINUS", "'@'", "'^'", "CALL_PREC", "'['",
  "STRUCT_LIT_NAMED_FIELD", "TYPE_Q_PREC", "')'", "';'", "'{'", "'}'",
  "'|'", "']'", "','", "$accept", "declarations", "declaration", "c_code",
  "global_code_scope_start", "global_code_scope", "struct_def",
  "module_info", "statements", "index_access", "identifier",
  "incr_decr_op", "expr", "stat_arr_literal_start", "arr_lit_start",
  "empty_arr_dims", "stat_arr_literal", "arr_literal", "statement",
  "matching_statement", "switch_statement_start", "switch_statement",
  "switch_body", "switch_branch", "switch_case", "switch_expr_list",
  "if_condition", "matching_if_statement", "non_matching_statement",
  "non_matching_if_statement", "till_loop_start", "while_loop_base",
  "matching_while", "non_matching_while", "for_loop_start",
  "for_loop_init", "for_loop_base", "matching_for_loop",
  "non_matching_for_loop", "matching_each_loop", "non_matching_each_loop",
  "each_iter_dims", "each_loop_base", "assign_op", "assignment",
  "special_assignment", "arr_multidim_typ", "arr_typ", "func_typ_start",
  "func_typ_args", "func_typ", "no_q_typ", "val_typ", "type_qualifier",
  "typ_q", "called_expr", "func_call_start", "func_call",
  "code_scope_start", "code_scope", "func_def_name", "func_def_ret_typ",
  "func_def_start", "struct_literal_start", "struct_literal", "func_def",
  "func_arg", "func_args", "enum_names", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-179)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -125,   309,  -125,    -9,  -125,     3,    79,  -125,     6,    37,
      52,    83,     8,  -125,    89,    96,   107,  -125,  -125,    -4,
     209,    79,    51,  -125,  -125,  -125,  -125,  -125,  -125,    53,
    -125,    48,   -52,  -125,  -125,   112,    79,  -125,   401,    38,
    -125,    79,  -125,  -125,  -125,   128,    56,    62,  -125,  -125,
    -125,     1,  -125,  -125,  -125,    78,  -125,   126,  -125,  -125,
      79,   502,  -125,    79,  -125,  -125,  -125,    79,  -125,  -125,
    -125,   -53,    77,    90,  -125,  -125,  -125,  -125,  -125,   158,
     405,    88,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   110,
     822,  -125,  -125,   880,   880,  -125,   880,    94,  -125,   915,
    -125,   105,   106,   781,  -125,  -125,  -125,  -125,   880,   880,
     880,   123,  -125,  -125,  -125,  -125,  1485,   -72,   952,    55,
    -125,  -125,  -125,  -125,    85,  -125,   781,  -125,  -125,  -125,
    -125,   781,  -125,  -125,   691,    98,   781,  -125,  -125,  -125,
    -125,   781,  -125,  -125,    -2,   880,   -44,  -125,  -125,   -60,
    -125,  -125,  -125,   202,   204,   405,   593,  -125,   -43,   143,
     207,  -125,   -40,   211,   212,  -125,  1550,  1680,  1550,  1745,
     216,    64,  1550,   880,    79,  -125,   781,   781,   781,   781,
     116,   170,  1281,  -125,   880,   880,   880,   880,   880,   880,
     880,   880,  -125,  -125,   880,   880,   880,   880,   880,  -125,
     173,   880,   880,   880,   880,   880,   880,   880,   880,   145,
    -125,   221,  -125,   880,    59,   880,  -125,   880,    61,  1077,
     225,   653,   880,  -125,   208,  -125,  -125,   144,    15,  -125,
     880,  -125,  -125,  -125,  -125,  -125,   163,  1550,  -125,   880,
    -125,   987,  -125,  -125,   -39,  -125,  -125,   228,   880,   168,
    -125,   405,  -125,  -125,  -125,   171,   880,  1349,   149,   222,
    -125,  1870,  1870,  1854,  1854,  1774,  1839,  1904,  1904,  1550,
    1550,  1550,  1550,  1550,    79,  1615,  1854,  1854,  1920,  1920,
     -10,   -10,   -10,    79,   162,  1550,   880,  -125,  1550,  1550,
     378,  -125,   360,  -125,  1550,   634,   781,   193,     5,   781,
     445,    67,   144,   880,  1145,   880,  1550,    72,  1550,   155,
    -125,  1550,   880,  -125,   880,  1550,  -125,  -125,   781,  -125,
    1024,   159,  -125,  1550,  -125,  1550,  1213,  -125,   781,  -125,
     240,  -125,   880,  -125,  -125,   880,  1550,   880,   233,    74,
    1680,   781,  1550,   880,  -125,  1550,  1417,   -50,   -20,  -125,
     880,  -125,  -125,  1550,  1550,  1550,   880,   235,  -125,  1550,
    -125,  1550,  1680,   880,  1680
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   157,     4,     0,     0,   181,     0,     0,
       0,     0,     0,   159,     0,     0,     0,   167,   168,     0,
       0,     0,     0,    21,     6,    18,    26,    15,     7,     0,
     161,     0,     0,   160,   163,     0,     0,   165,     0,     0,
       3,     0,    13,    14,   157,     0,     0,     0,    10,    11,
      24,     0,    17,    16,    20,     0,   152,     0,   158,   147,
       0,     0,   148,     0,   155,   153,   156,     0,   182,   164,
     166,   157,     0,     0,   176,    26,   191,    19,     9,     0,
     195,     0,    12,   162,   151,   149,    33,    34,    35,    30,
       0,    96,    95,     0,     0,   125,     0,     0,    37,   184,
      36,     0,     0,     0,    69,    70,    71,    75,     0,     0,
       0,    79,    90,    22,    50,    73,    89,     0,     0,     0,
      85,    72,    27,    87,     0,    97,     0,   100,    88,   115,
     128,     0,   102,   117,     0,     0,     0,   101,   116,   103,
     118,     0,    48,    49,     0,   171,     0,    52,    93,     0,
      64,   150,   154,     0,     0,   195,     0,   198,     0,   157,
       0,   196,     0,     0,     0,    92,    91,   122,   104,   113,
       0,    30,   185,     0,     0,    98,     0,     0,     0,     0,
      41,    60,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,     0,     0,     0,    66,
     140,     0,     0,     0,     0,     0,     0,     0,     0,    47,
     169,     0,    46,     0,     0,     0,    84,     0,    34,     0,
       0,     0,     0,   119,    87,   123,   124,     0,    50,   126,
       0,   129,   130,   131,   132,    30,     0,   172,   175,   174,
     190,   188,   179,   180,     0,   177,     5,     0,     0,   192,
      23,     0,    25,    38,   140,     0,     0,     0,     0,     0,
      45,    55,    56,    57,    58,    59,    61,    63,    62,   142,
     143,   144,   145,   146,     0,     0,    53,    54,    39,    40,
      42,    43,    44,     0,     0,    28,     0,    65,   141,    78,
       0,    82,     0,    86,   111,     0,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,   173,    30,   187,   183,
     199,   193,     0,   197,     0,   186,    67,    68,     0,    94,
       0,     0,   170,    29,    83,    76,     0,   105,     0,   106,
       0,   110,     0,   114,   120,     0,   133,   136,     0,     0,
     137,     0,    99,     0,     8,   194,     0,    30,    51,    74,
       0,   107,   108,   112,   134,   135,     0,     0,   127,   189,
     121,    77,   139,     0,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,  -125,  -125,   253,  -125,   184,  -125,
    -117,  -125,    -6,  -125,  -125,  -125,  -125,  -125,  -124,   -71,
    -125,  -125,  -125,   -33,  -125,  -125,   -97,  -125,  -123,  -125,
    -125,   -82,  -125,  -125,  -125,  -125,   -62,  -125,  -125,  -125,
    -125,   -37,   -54,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,   227,    -1,   -58,   -35,  -125,  -125,  -125,  -125,   229,
    -125,  -125,  -125,  -125,  -125,  -125,    16,   111,  -125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,    25,    26,    27,    28,    51,    61,   214,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   295,   296,   297,   298,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   301,   141,   215,   142,   143,    29,    30,    31,    32,
      33,    34,   160,    36,    37,   145,   146,   147,    75,   148,
      73,    38,    39,   149,   150,    40,   161,   162,   158
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    70,   223,   144,   235,    45,   176,    81,   226,    42,
     229,   153,    46,   232,   164,   192,   193,   228,   234,    57,
      58,   177,   331,   216,   217,   192,   193,   236,  -178,   199,
      65,   322,   175,   240,   302,   303,   241,    72,    66,   199,
      77,   178,    41,    47,    67,   144,   238,   246,     9,   179,
     250,   309,   239,   247,    44,   224,   251,   251,    48,    85,
     225,    17,   151,    18,   212,   231,   152,   213,   144,   209,
     233,   210,   211,   144,   212,    55,   144,   213,   144,   176,
     176,   176,   176,   144,   166,    44,    49,   167,   168,    50,
     169,    82,    52,   172,   177,   177,   177,   177,   144,    53,
      13,   332,   180,   181,   182,   259,   225,   231,   233,    70,
      54,    17,   219,    18,   178,   178,   178,   178,   144,   144,
     144,   144,   179,   179,   179,   179,    68,    19,   164,    20,
      74,    13,    21,   256,    78,    22,   164,    79,    64,   237,
      84,   343,    17,    80,    18,    59,    60,    62,    63,   220,
     221,   192,   193,   286,   287,   -81,   -81,    83,    19,   154,
      20,   337,   338,    21,   157,   199,    22,   257,   337,   357,
     163,   155,   329,   258,   164,   170,   334,   222,   261,   262,
     263,   264,   265,   266,   267,   268,   173,   174,   269,   270,
     271,   272,   273,   183,   230,   275,   276,   277,   278,   279,
     280,   281,   282,   213,   351,   192,   193,   285,   242,   288,
     243,   289,   248,   249,   252,    44,   294,   358,   253,   199,
     293,   176,   255,    56,   304,   274,   283,   284,   333,   291,
     299,   300,   305,   306,   310,   308,   177,   312,   144,   317,
     314,   144,   311,   322,   318,   330,   344,   333,   352,   349,
     315,   210,   211,   356,   212,   363,   178,   213,    43,   156,
     144,    13,   328,    69,   179,   339,   244,   313,    76,     0,
     144,     0,    17,   319,    18,     0,     0,     0,     0,     0,
     323,     0,   321,   144,   325,     0,   326,     0,    19,   294,
      20,     0,     0,    21,   336,     0,    22,   340,     0,   342,
       0,     0,     0,     0,     0,     0,   345,     0,   346,     2,
       0,     0,     0,     0,   348,     3,     0,     0,     0,     0,
       4,     5,     6,     7,     0,     0,   353,     0,     0,   354,
       0,   355,     0,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   361,     0,     0,     0,     0,     0,
     362,     0,     0,     8,     9,    10,    11,   364,     0,    12,
       0,    13,     0,    86,    87,    88,    89,     0,     0,    14,
      15,    16,    17,     0,    18,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    98,     0,    22,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    71,    99,     0,
       0,   159,    98,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,    99,   107,     0,     0,
       0,   100,   101,   102,   108,   104,   105,   106,     0,     0,
     109,   110,     0,     0,     0,   107,     0,   111,    86,    87,
      88,    89,   108,    13,    59,    60,     0,    13,   109,   110,
       0,     0,     0,     0,    17,   111,    18,     0,    17,     0,
      18,     0,     0,   324,     0,     0,     0,     0,     0,    98,
      19,     0,    20,     0,    19,    21,    20,     0,    22,    21,
       0,     0,    22,    99,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,    86,    87,    88,    89,    90,
      91,    92,   107,     0,     0,     0,     0,    93,    94,   108,
      95,     0,     0,    96,     0,   109,   110,     0,     0,     0,
       0,     0,   111,     0,     0,    97,    98,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,    17,     0,    18,     0,   107,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,     0,   111,
       0,     0,     0,   112,    74,   113,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    99,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,    17,     0,    18,    44,
     107,     0,     0,     0,     0,     0,     0,   108,    98,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,     0,
     111,     0,    99,     0,   112,    74,   245,   100,   101,   102,
       0,   104,   105,   106,    86,    87,    88,    89,    90,    91,
      92,   107,     0,     0,     0,    13,    93,    94,   108,    95,
     227,     0,    96,     0,   109,   110,    17,     0,    18,     0,
       0,   111,     0,     0,    97,    98,     0,   327,     0,     0,
       0,     0,    19,     0,    20,     0,     0,    21,     0,    99,
     292,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,    17,     0,    18,     0,   107,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   112,    74,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,    93,    94,     0,    95,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    99,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,    17,     0,    18,     0,   107,     0,
       0,     0,     0,     0,     0,   108,    98,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,     0,
      99,     0,   112,    74,     0,   100,   101,   102,     0,   104,
     105,   106,     0,    86,    87,    88,    89,     0,     0,   107,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,     0,   111,
       0,     0,     0,   165,    98,     0,     0,     0,    86,    87,
      88,   171,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   107,     0,    98,
       0,     0,     0,     0,   108,    86,   218,    88,    89,     0,
     109,   110,     0,    99,     0,     0,     0,   111,   100,   101,
     102,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,    98,     0,     0,   108,
      86,    87,    88,   307,     0,   109,   110,     0,     0,     0,
      99,     0,   111,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   107,
       0,    98,     0,     0,     0,     0,   108,    86,    87,    88,
     347,     0,   109,   110,     0,    99,     0,     0,     0,   111,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,    98,     0,
       0,   108,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,    99,     0,   111,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,   108,     0,
     184,   185,   186,   187,   109,   110,   188,   189,   190,   191,
       0,   111,   192,   193,   194,   195,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,     0,   210,   211,
       0,   212,     0,     0,   213,     0,     0,     0,   184,   185,
     186,   187,     0,   290,   188,   189,   190,   191,     0,     0,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,     0,   210,   211,     0,   212,
       0,     0,   213,     0,     0,     0,   184,   185,   186,   187,
       0,   341,   188,   189,   190,   191,     0,     0,   192,   193,
     194,   195,   196,   197,   198,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   201,   202,   203,   204,   205,   206,   207,
     208,     0,   209,     0,   210,   211,     0,   212,     0,     0,
     213,     0,     0,     0,   184,   185,   186,   187,     0,   350,
     188,   189,   190,   191,     0,     0,   192,   193,   194,   195,
     196,   197,   198,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,     0,   210,   211,     0,   212,     0,     0,   213,     0,
       0,   260,   184,   185,   186,   187,     0,     0,   188,   189,
     190,   191,     0,     0,   192,   193,   194,   195,   196,   197,
     198,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,     0,
     210,   211,     0,   212,     0,     0,   213,     0,     0,   316,
     184,   185,   186,   187,     0,     0,   188,   189,   190,   191,
       0,     0,   192,   193,   194,   195,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,     0,   210,   211,
       0,   212,     0,     0,   213,     0,     0,   360,   184,   185,
     186,   187,     0,     0,   188,   189,   190,   191,     0,     0,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,     0,   210,   211,     0,   212,
       0,     0,   213,   184,   185,   186,   187,     0,     0,   188,
     189,   190,   191,     0,     0,   192,   193,   194,   195,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
       0,   210,   211,     0,   212,     0,     0,   213,   184,   185,
     186,   187,     0,     0,   188,   189,   190,   191,     0,     0,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,     0,   210,   320,     0,   212,
       0,     0,   213,   184,   185,   186,   187,     0,     0,   188,
     189,   190,   191,     0,     0,   192,   193,   194,   195,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     201,   202,   203,   204,     0,   206,   207,   208,     0,   209,
       0,   210,   211,     0,   212,     0,     0,   213,   184,   185,
     186,   187,     0,     0,   188,   189,   190,   191,     0,     0,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,   184,   185,   186,
     187,     0,     0,     0,   189,   190,   191,     0,     0,   192,
     193,     0,     0,     0,   254,   201,   202,   203,   204,     0,
     206,   207,   208,   199,   209,     0,     0,   211,     0,   212,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,     0,   212,     0,
       0,   213,   184,   185,   186,   187,     0,     0,     0,     0,
     190,   191,     0,     0,   192,   193,     0,   184,   185,     0,
       0,     0,     0,     0,     0,   190,   191,     0,   199,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,   191,   199,     0,   192,   193,     0,     0,     0,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   199,
     210,   211,     0,   212,     0,     0,   213,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,     0,   212,   192,
     193,   213,     0,   204,   205,   206,   207,   208,     0,   209,
       0,   210,   211,   199,   212,   192,   193,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,     0,   212,     0,
       0,   213,     0,     0,     0,   206,   207,   208,     0,   209,
       0,   210,   211,     0,   212,     0,     0,   213
};

static const yytype_int16 yycheck[] =
{
       1,    36,   126,    61,     6,     6,   103,     6,   131,     6,
     134,    64,     6,   136,    64,    35,    36,   134,   141,    20,
      21,   103,    17,    95,    96,    35,    36,   144,    81,    49,
      31,    81,   103,    93,    19,    20,    96,    38,    90,    49,
      41,   103,    51,     6,    96,   103,    90,    90,    45,   103,
      90,    90,    96,    96,     6,   126,    96,    96,     6,    60,
     131,    63,    63,    65,    84,   136,    67,    87,   126,    79,
     141,    81,    82,   131,    84,    79,   134,    87,   136,   176,
     177,   178,   179,   141,    90,     6,     3,    93,    94,    81,
      96,    90,     3,    99,   176,   177,   178,   179,   156,     3,
      52,    96,   108,   109,   110,   176,   177,   178,   179,   144,
       3,    63,   118,    65,   176,   177,   178,   179,   176,   177,
     178,   179,   176,   177,   178,   179,    14,    79,    64,    81,
      92,    52,    84,    69,     6,    87,    64,    81,    90,   145,
      14,    69,    63,    81,    65,    94,    95,    94,    95,    94,
      95,    35,    36,    94,    95,    94,    95,    79,    79,    82,
      81,    94,    95,    84,     6,    49,    87,   173,    94,    95,
      82,    81,   296,   174,    64,    81,   299,    92,   184,   185,
     186,   187,   188,   189,   190,   191,    81,    81,   194,   195,
     196,   197,   198,    70,    96,   201,   202,   203,   204,   205,
     206,   207,   208,    87,   328,    35,    36,   213,     6,   215,
       6,   217,    69,     6,     3,     6,   222,   341,     6,    49,
     221,   318,     6,    14,   230,    52,    81,     6,   299,     4,
      22,    87,    69,   239,     6,   241,   318,    69,   296,    90,
      69,   299,   248,    81,    22,    52,    91,   318,     8,    90,
     256,    81,    82,    20,    84,    20,   318,    87,     5,    75,
     318,    52,   295,    36,   318,   302,   155,   251,    39,    -1,
     328,    -1,    63,   274,    65,    -1,    -1,    -1,    -1,    -1,
     286,    -1,   283,   341,   290,    -1,   292,    -1,    79,   295,
      81,    -1,    -1,    84,   300,    -1,    87,   303,    -1,   305,
      -1,    -1,    -1,    -1,    -1,    -1,   312,    -1,   314,     0,
      -1,    -1,    -1,    -1,   320,     6,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,   332,    -1,    -1,   335,
      -1,   337,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
     356,    -1,    -1,    44,    45,    46,    47,   363,    -1,    50,
      -1,    52,    -1,     3,     4,     5,     6,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    79,    -1,
      81,    -1,    -1,    84,    34,    -1,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,     6,    48,    -1,
      -1,     6,    34,    53,    54,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    67,    -1,    -1,
      -1,    53,    54,    55,    74,    57,    58,    59,    -1,    -1,
      80,    81,    -1,    -1,    -1,    67,    -1,    87,     3,     4,
       5,     6,    74,    52,    94,    95,    -1,    52,    80,    81,
      -1,    -1,    -1,    -1,    63,    87,    65,    -1,    63,    -1,
      65,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    34,
      79,    -1,    81,    -1,    79,    84,    81,    -1,    87,    84,
      -1,    -1,    87,    48,    -1,    -1,    -1,    -1,    53,    54,
      55,    -1,    57,    58,    59,     3,     4,     5,     6,     7,
       8,     9,    67,    -1,    -1,    -1,    -1,    15,    16,    74,
      18,    -1,    -1,    21,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    33,    34,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    91,    92,    93,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,
      -1,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    63,    -1,    65,     6,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    34,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    48,    -1,    91,    92,    93,    53,    54,    55,
      -1,    57,    58,    59,     3,     4,     5,     6,     7,     8,
       9,    67,    -1,    -1,    -1,    52,    15,    16,    74,    18,
      19,    -1,    21,    -1,    80,    81,    63,    -1,    65,    -1,
      -1,    87,    -1,    -1,    33,    34,    -1,    93,    -1,    -1,
      -1,    -1,    79,    -1,    81,    -1,    -1,    84,    -1,    48,
      87,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    34,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      48,    -1,    91,    92,    -1,    53,    54,    55,    -1,    57,
      58,    59,    -1,     3,     4,     5,     6,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    91,    34,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    53,    54,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    34,
      -1,    -1,    -1,    -1,    74,     3,     4,     5,     6,    -1,
      80,    81,    -1,    48,    -1,    -1,    -1,    87,    53,    54,
      55,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    34,    -1,    -1,    74,
       3,     4,     5,     6,    -1,    80,    81,    -1,    -1,    -1,
      48,    -1,    87,    -1,    -1,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    34,    -1,    -1,    -1,    -1,    74,     3,     4,     5,
       6,    -1,    80,    81,    -1,    48,    -1,    -1,    -1,    87,
      53,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    34,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    48,    -1,    87,    -1,    -1,    53,    54,    55,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      23,    24,    25,    26,    80,    81,    29,    30,    31,    32,
      -1,    87,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    23,    24,
      25,    26,    -1,    96,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    96,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    -1,    81,    82,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    96,
      29,    30,    31,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,
      36,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    49,    79,    -1,    -1,    82,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    49,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    49,    -1,    35,    36,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    49,
      81,    82,    -1,    84,    -1,    -1,    87,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    84,    35,
      36,    87,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    49,    84,    35,    36,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    84,    -1,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    98,     0,     6,    11,    12,    13,    14,    44,    45,
      46,    47,    50,    52,    60,    61,    62,    63,    65,    79,
      81,    84,    87,    92,    99,   100,   101,   102,   103,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   158,   159,
     162,    51,     6,   103,     6,   149,     6,     6,     6,     3,
      81,   104,     3,     3,     3,    79,    14,   149,   149,    94,
      95,   105,    94,    95,    90,   149,    90,    96,    14,   148,
     151,     6,   149,   157,    92,   155,   156,   149,     6,    81,
      81,     6,    90,    79,    14,   149,     3,     4,     5,     6,
       7,     8,     9,    15,    16,    18,    21,    33,    34,    48,
      53,    54,    55,    56,    57,    58,    59,    67,    74,    80,
      81,    87,    91,    93,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   139,   141,   142,   150,   152,   153,   154,   156,   160,
     161,   149,   149,    64,    82,    81,   105,     6,   165,     6,
     149,   163,   164,    82,    64,    91,   109,   109,   109,   109,
      81,     6,   109,    81,    81,   116,   123,   128,   133,   139,
     109,   109,   109,    70,    23,    24,    25,    26,    29,    30,
      31,    32,    35,    36,    37,    38,    39,    40,    41,    49,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    79,
      81,    82,    84,    87,   106,   140,    95,    96,     4,   109,
      94,    95,    92,   115,   116,   116,   125,    19,   107,   115,
      96,   116,   125,   116,   125,     6,   107,   109,    90,    96,
      93,    96,     6,     6,   164,    93,    90,    96,    69,     6,
      90,    96,     3,     6,    69,     6,    69,   109,   149,   116,
      90,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    52,   109,   109,   109,   109,   109,
     109,   109,   109,    81,     6,   109,    94,    95,   109,   109,
      96,     4,    87,   149,   109,   119,   120,   121,   122,    22,
      87,   138,    19,    20,   109,    69,   109,     6,   109,    90,
       6,   109,    69,   163,    69,   109,    90,    90,    22,   149,
      82,   149,    81,   109,    95,   109,   109,    93,   120,   115,
      52,    17,    96,   116,   125,    94,   109,    94,    95,   138,
     109,    96,   109,    69,    91,   109,   109,     6,   109,    90,
      96,   115,     8,   109,   109,   109,    20,    95,   115,   109,
      90,   109,   109,    20,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   102,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   124,   125,   125,   125,   125,   126,
     126,   127,   128,   129,   130,   131,   132,   133,   133,   134,
     135,   136,   137,   138,   138,   138,   138,   139,   139,   139,
     140,   141,   142,   142,   142,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   148,
     148,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   153,   154,   155,   156,   157,   157,
     157,   158,   158,   159,   160,   160,   160,   160,   160,   160,
     161,   162,   163,   163,   163,   164,   164,   164,   165,   165
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     6,     2,     1,     6,     3,
       2,     2,     3,     2,     2,     1,     2,     2,     1,     3,
       2,     1,     3,     5,     1,     4,     0,     2,     2,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     2,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     5,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     3,     2,     4,     4,     1,
       1,     1,     1,     1,     5,     1,     4,     6,     3,     1,
       2,     2,     3,     4,     2,     1,     3,     1,     1,     1,
       1,     2,     2,     1,     4,     1,     1,     1,     2,     4,
       1,     1,     1,     1,     2,     4,     2,     3,     3,     1,
       2,     1,     3,     2,     4,     1,     1,     1,     1,     2,
       4,     6,     2,     2,     2,     1,     2,     5,     1,     2,
       2,     2,     2,     2,     3,     3,     2,     4,     7,     6,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     2,     2,     3,     2,     2,     1,     2,     1,
       1,     1,     3,     1,     2,     1,     2,     1,     1,     2,
       4,     1,     2,     3,     2,     2,     1,     3,     1,     3,
       3,     1,     2,     5,     1,     2,     4,     3,     2,     5,
       2,     2,     2,     3,     4,     0,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* declarations: %empty  */
#line 210 "axo_gram.y"
                           {}
#line 2285 "axo_gram.tab.c"
    break;

  case 3: /* declarations: declarations func_def  */
#line 211 "axo_gram.y"
                          {
    axo_add_decl(state, axo_func_def_to_decl((yyvsp[0].function)));
    axo_free_func((yyvsp[0].function));
  }
#line 2294 "axo_gram.tab.c"
    break;

  case 4: /* declarations: declarations "#include"  */
#line 215 "axo_gram.y"
                           {
    if ((yyvsp[0].str)[0] == '<'){
      axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", (yyvsp[0].str)), .kind=axo_c_include_decl_kind});
    }else{
      char* path = &((yyvsp[0].str)[1]);
      path[strlen((yyvsp[0].str))-2] = '\0';
      // printf("Path of c_include: %s\nResolved path: %s\n", path, axo_resolve_path(path));
      char* res_path = axo_resolve_path(path);
      #ifdef __EMSCRIPTEN__
        char* code = axo_file_to_str(res_path);
        axo_add_decl(state, (axo_decl){.val = fmtstr("//#include \"%s\"\n%s", res_path, code), .kind=axo_c_include_decl_kind});
        free(code);
      #else
        axo_add_decl(state, (axo_decl){.val = fmtstr("#include \"%s\"", res_path), .kind=axo_c_include_decl_kind});
        free(res_path);
      #endif
    }
  }
#line 2317 "axo_gram.tab.c"
    break;

  case 5: /* declarations: declarations "enum" "identifier" '(' enum_names ')'  */
#line 233 "axo_gram.y"
                                                   {
    new_ptr_one(enm, axo_enum);
    *enm = (yyvsp[-1].enum_type);
    enm->name=alloc_str((yyvsp[-3].str));
    char* decl;
    int decl_sz = 18+(2+(yyvsp[-1].enum_type).len)*strlen((yyvsp[-3].str));  //typedef enum %name{\}name;
    for (int i=0; i<(yyvsp[-1].enum_type).len; i++){
      decl_sz += strlen((yyvsp[-1].enum_type).names[i]) + 2 + 1;
    }
    decl_sz--; //last comma
    decl = (char*)malloc(decl_sz*sizeof(char));
    strcpy(decl, "typedef enum ");
    strcat(decl, (yyvsp[-3].str));
    strcat(decl, "{\n");
    for (int i=0; i<(yyvsp[-1].enum_type).len; i++){
      if(i>0) strcat(decl, ",\n");
      char* field = fmtstr("%s$%s", (yyvsp[-3].str), (yyvsp[-1].enum_type).names[i]);
      strcat(decl, field);
      axo_set_var(state->global_scope, (axo_var){.name=field, .typ=axo_no_typ});
    }
    strcat(decl, "\n}");
    strcat(decl, (yyvsp[-3].str));
    strcat(decl, ";");
    axo_typ_def td = (axo_typ_def){
      .name=enm->name,
      .typ=(axo_typ){
        .kind=axo_enum_kind,
        .enumerate=enm,
        .def="0"
      },
    };
    axo_set_typ_def(&(yyloc), state, td);
    axo_add_decl(state, (axo_decl){.val=decl, .kind=axo_enum_decl_kind});
  }
#line 2356 "axo_gram.tab.c"
    break;

  case 6: /* declarations: declarations declaration  */
#line 267 "axo_gram.y"
                             {
    axo_add_decl(state, (yyvsp[0].declaration_type));
  }
#line 2364 "axo_gram.tab.c"
    break;

  case 7: /* declaration: struct_def  */
#line 272 "axo_gram.y"
                         { //Fix! Make this use realloc less
    new_ptr_one(strct, axo_struct);
    *strct = (yyvsp[0].struct_type);
    char* decl = empty_str;
    strapnd(&decl, "typedef struct ");
    strapnd(&decl, (yyvsp[0].struct_type).name);
    strapnd(&decl, "{\n");
    for (int i=0; i<(yyvsp[0].struct_type).fields_len; i++){
      char* ntd = axo_name_typ_decl(strct->fields[i].name, strct->fields[i].typ);
      strapnd(&decl, ntd);
      strapnd(&decl, ";\n");
      free(ntd);
    }
    strapnd(&decl, "}");
    strapnd(&decl, (yyvsp[0].struct_type).name);
    strapnd(&decl, ";");
    axo_typ_def td = (axo_typ_def){
      .name=strct->name,
      .typ=(axo_typ){
        .kind=axo_struct_kind,
        .structure=strct,
        .def="0" //FIX! DEFAULT VALUE!
      },
    };
    axo_set_typ_def(&(yyloc), state, td);
    (yyval.declaration_type) = (axo_decl){.val=decl, .kind=axo_struct_decl_kind};
  }
#line 2396 "axo_gram.tab.c"
    break;

  case 8: /* declaration: func_def_ret_typ func_def_name '(' func_args ')' ';'  */
#line 299 "axo_gram.y"
                                                         {
    axo_func fn = (axo_func){
      .name=(yyvsp[-4].function).name
    };
    int args_len = (yyvsp[-2].function).f_typ.args_len;
    if ((yyvsp[-4].function).args_names){
      args_len += (yyvsp[-4].function).f_typ.args_len;
      fn.args_names = (char**)malloc(args_len*sizeof(char*));
      fn.f_typ = (axo_func_typ){
        .args_len = 0,
        .args_types=(axo_typ*)malloc(args_len*sizeof(axo_typ)),
        .args_defs=(char**)malloc(args_len*sizeof(char*)),
      };
      for (int i=0; i<(yyvsp[-4].function).f_typ.args_len; i++){
        fn.args_names[fn.f_typ.args_len] = (yyvsp[-4].function).args_names[i];
        fn.f_typ.args_types[fn.f_typ.args_len] = (yyvsp[-4].function).f_typ.args_types[i];
        fn.f_typ.args_defs[fn.f_typ.args_len++] = (yyvsp[-4].function).f_typ.args_defs[i];
      }
      for (int i=0; i<(yyvsp[-2].function).f_typ.args_len; i++){
        fn.args_names[fn.f_typ.args_len] = (yyvsp[-2].function).args_names[i];
        fn.f_typ.args_types[fn.f_typ.args_len] = (yyvsp[-2].function).f_typ.args_types[i];
        fn.f_typ.args_defs[fn.f_typ.args_len++] = (yyvsp[-2].function).f_typ.args_defs[i];
      }
    }else{
      fn.args_names = (yyvsp[-2].function).args_names;
      fn.f_typ.args_defs = (yyvsp[-2].function).f_typ.args_defs;
      fn.f_typ.args_types = (yyvsp[-2].function).f_typ.args_types;
      fn.f_typ.args_len = args_len;
    }
    fn.f_typ.ret_typ = ((yyvsp[-5].typ_type).kind==axo_no_kind) ? axo_none_typ : (yyvsp[-5].typ_type);
    (yyval.declaration_type) = axo_func_decl_to_decl(fn);
    axo_free_func((yyvsp[-2].function));
    axo_free_scope(top_scope);
    strapnd(&((yyval.declaration_type).val), ";");
  }
#line 2436 "axo_gram.tab.c"
    break;

  case 9: /* declaration: "#provided" val_typ "identifier"  */
#line 334 "axo_gram.y"
                             {
    // printf("providing '%s'\n", $IDEN);
    axo_set_var(state->global_scope, (axo_var){.typ = (yyvsp[-1].typ_type), .name = alloc_str((yyvsp[0].str))});
    char* ntd = axo_name_typ_decl((yyvsp[0].str), (yyvsp[-1].typ_type));
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//provided %s", ntd)};
    free(ntd);
  }
#line 2448 "axo_gram.tab.c"
    break;

  case 10: /* declaration: "use" "identifier"  */
#line 341 "axo_gram.y"
               {
    (yyval.declaration_type) = axo_use_module(state, &(yylsp[0]), (yyvsp[0].str));
  }
#line 2456 "axo_gram.tab.c"
    break;

  case 11: /* declaration: "include" "string literal"  */
#line 344 "axo_gram.y"
                             {
    (yyval.declaration_type) = axo_include_file(state, &(yylsp[0]), (yyvsp[0].str), true);
  }
#line 2464 "axo_gram.tab.c"
    break;

  case 12: /* declaration: "module" module_info ')'  */
#line 347 "axo_gram.y"
                             {
    axo_load_module_defaults(state, &(yyvsp[-1].module_type));
    (yyval.declaration_type) = axo_add_module(state, (yyvsp[-1].module_type));
  }
#line 2473 "axo_gram.tab.c"
    break;

  case 13: /* declaration: "#typ" "identifier"  */
#line 351 "axo_gram.y"
                {
    char* name = alloc_str((yyvsp[0].str));
    axo_set_typ_def(&(yyloc), state, (axo_typ_def){.name=name, .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name=name, .cname=name}, .def="0"}});
      (yyval.declaration_type) = (axo_decl){
        .kind = axo_typ_def_decl_kind,
        .val = fmtstr("//accepting type %s", (yyvsp[0].str))
      };
  }
#line 2486 "axo_gram.tab.c"
    break;

  case 14: /* declaration: "#typ" struct_def  */
#line 359 "axo_gram.y"
                      {
    axo_struct* strct = alloc_one(axo_struct);
    *strct = (yyvsp[0].struct_type);
    axo_typ_def td = (axo_typ_def){
      .name=(yyvsp[0].struct_type).name,
      .typ=(axo_typ){
        .kind=axo_struct_kind,
        .structure=strct,
        .def="0" //FIX! DEFAULT VALUE!
      },
    };
    axo_set_typ_def(&(yyloc), state, td);
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//Recognized struct '%s'", (yyvsp[0].struct_type).name)};
  }
#line 2505 "axo_gram.tab.c"
    break;

  case 15: /* declaration: global_code_scope  */
#line 373 "axo_gram.y"
                      {
    (yyval.declaration_type) = (axo_decl){.val=axo_scope_code((yyvsp[0].scope))};
    axo_free_scope((yyvsp[0].scope));
  }
#line 2514 "axo_gram.tab.c"
    break;

  case 16: /* declaration: "#source" "string literal"  */
#line 377 "axo_gram.y"
                             {
      char* res = alloc_str(&((yyvsp[0].str)[1]));
      res[strlen((yyvsp[0].str))-2] = '\0';
    if (axo_file_exists(res)){
      char* resolved = axo_resolve_path(res);
      resize_dyn_arr_if_needed(char*, state->extra_c_sources, state->extra_c_sources_len, axo_c_sources_cap);
      state->extra_c_sources[state->extra_c_sources_len++] = resolved;
    }else{
      yyerror(&(yylsp[0]), "File '%s' doesn't exist.", res);
      YYERROR;
    }
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//sourced %s", res)};
  }
#line 2532 "axo_gram.tab.c"
    break;

  case 17: /* declaration: "#flag" "string literal"  */
#line 390 "axo_gram.y"
                           {
    char* res = alloc_str(&((yyvsp[0].str)[1]));
    res[strlen((yyvsp[0].str))-2] = '\0';
    resize_dyn_arr_if_needed(char*, state->cc_flags, state->cc_flags_len, axo_cc_flags_len);
    state->cc_flags[state->cc_flags_len++] = alloc_str(res);
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//flag %s", res)};
  }
#line 2544 "axo_gram.tab.c"
    break;

  case 18: /* declaration: c_code  */
#line 397 "axo_gram.y"
           {
    (yyval.declaration_type) = (axo_decl){
      .kind=axo_c_code_decl_kind,
      .val=(yyvsp[0].str)
    };
  }
#line 2555 "axo_gram.tab.c"
    break;

  case 19: /* declaration: "identifier" "->" val_typ  */
#line 403 "axo_gram.y"
                      {
    axo_typ_def td = (axo_typ_def){
      .name=alloc_str((yyvsp[-2].str)),
      .typ=(yyvsp[0].typ_type)
    };
    td.typ.simple.name=td.typ.simple.cname=td.name;
    axo_set_typ_def(&(yyloc), state, td);
    (yyval.declaration_type) = (axo_decl){
      .kind=axo_typedef_decl_kind,
      .val=fmtstr("typedef %s %s;", axo_typ_to_c_str((yyvsp[0].typ_type)), (yyvsp[-2].str))
    };
  }
#line 2572 "axo_gram.tab.c"
    break;

  case 20: /* c_code: "#C" "string literal"  */
#line 417 "axo_gram.y"
                             {
    char* ret = alloc_str(&((yyvsp[0].str)[1]));
    ret[strlen(ret)-1] = '\0';
    (yyval.str) = ret;
  }
#line 2582 "axo_gram.tab.c"
    break;

  case 21: /* global_code_scope_start: '{'  */
#line 424 "axo_gram.y"
                              {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    top_scope->to_global = state->global_scope;
    axo_code_scope_started = false;
  }
#line 2592 "axo_gram.tab.c"
    break;

  case 22: /* global_code_scope: global_code_scope_start statements '}'  */
#line 431 "axo_gram.y"
                                                           {
    (yyval.scope) = top_scope;
    scopes->len--;
  }
#line 2601 "axo_gram.tab.c"
    break;

  case 23: /* struct_def: "struct" "identifier" '(' func_args ')'  */
#line 437 "axo_gram.y"
                                                {
    axo_struct_field* fields = (axo_struct_field*)malloc((yyvsp[-1].function).f_typ.args_len*sizeof(axo_struct_field));
    for (int i = 0; i<(yyvsp[-1].function).f_typ.args_len; i++){
      fields[i] = (axo_struct_field){
        .name = (yyvsp[-1].function).args_names[i],
        .typ = (yyvsp[-1].function).f_typ.args_types[i],
        .def = (yyvsp[-1].function).f_typ.args_defs[i]
      };
    }
    free((yyvsp[-1].function).args_names);
    free((yyvsp[-1].function).f_typ.args_types);
    free((yyvsp[-1].function).f_typ.args_defs);
    (yyval.struct_type) = (axo_struct){
      .name=alloc_str((yyvsp[-3].str)),
      .fields=fields,
      .fields_len=(yyvsp[-1].function).f_typ.args_len
    };
  }
#line 2624 "axo_gram.tab.c"
    break;

  case 24: /* module_info: '('  */
#line 457 "axo_gram.y"
                  {
    (yyval.module_type) = axo_new_module();
  }
#line 2632 "axo_gram.tab.c"
    break;

  case 25: /* module_info: module_info "identifier" ':' "string literal"  */
#line 460 "axo_gram.y"
                                        {
    char* str_val = alloc_str(&((yyvsp[0].str)[1]));
    str_val[strlen(str_val)-1] = '\0';
    if (strcmp((yyvsp[-2].str), "name") == 0){
      (yyval.module_type).name = str_val;
    }else if (strcmp((yyvsp[-2].str), "prefix") == 0){
      (yyval.module_type).prefix = str_val;
    }else if (strcmp((yyvsp[-2].str), "version") == 0){
      (yyval.module_type).version = str_val;
    }else if (strcmp((yyvsp[-2].str), "author") == 0){
      (yyval.module_type).author = str_val;
    }else if (strcmp((yyvsp[-2].str), "website") == 0){
      (yyval.module_type).website = str_val;
    }else if (strcmp((yyvsp[-2].str), "license_name") == 0){
      (yyval.module_type).license_name = str_val;
    }else if (strcmp((yyvsp[-2].str), "license") == 0){
      (yyval.module_type).license = str_val;
    }else if (strcmp((yyvsp[-2].str), "description") == 0){
      (yyval.module_type).description = str_val;
    }else{
      yyerror(&(yylsp[-2]), "Not a valid module information field.");
      YYERROR;
    }
  }
#line 2661 "axo_gram.tab.c"
    break;

  case 26: /* statements: %empty  */
#line 486 "axo_gram.y"
                         { }
#line 2667 "axo_gram.tab.c"
    break;

  case 27: /* statements: statements statement  */
#line 487 "axo_gram.y"
                         {
    // printf("Adding statement to %p\n", top_scope);
    axo_add_statement(top_scope, (yyvsp[0].statement_type));
  }
#line 2676 "axo_gram.tab.c"
    break;

  case 28: /* index_access: '[' expr  */
#line 493 "axo_gram.y"
                        {
    //TODO: Dynamic?
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.index_access_type) = (axo_index_access){
      .index_count=1,
      .indexes = (axo_expr*)malloc(128*sizeof(axo_expr))
    };
    (yyval.index_access_type).indexes[0] = (yyvsp[0].expression);
  }
#line 2690 "axo_gram.tab.c"
    break;

  case 29: /* index_access: index_access '|' expr  */
#line 502 "axo_gram.y"
                          {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.index_access_type).indexes[(yyval.index_access_type).index_count++] = (yyvsp[0].expression);
  }
#line 2699 "axo_gram.tab.c"
    break;

  case 30: /* identifier: "identifier"  */
#line 508 "axo_gram.y"
                  {
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[0].str));
    if (td != NULL) {
         (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_typ_kind,
        .typ_def = *td
      };
    }else{
      (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_var_kind,
        .data = (void*)alloc_str((yyvsp[0].str))
      };
    }
  }
#line 2718 "axo_gram.tab.c"
    break;

  case 31: /* incr_decr_op: expr "++"  */
#line 524 "axo_gram.y"
                            {
    axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression));
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s++", (yyvsp[-1].expression).val);
  }
#line 2728 "axo_gram.tab.c"
    break;

  case 32: /* incr_decr_op: expr "--"  */
#line 529 "axo_gram.y"
                 {
    axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression));
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s--", (yyvsp[-1].expression).val);
  }
#line 2738 "axo_gram.tab.c"
    break;

  case 33: /* expr: "string literal"  */
#line 537 "axo_gram.y"
                      {set_val(&(yyval.expression), axo_deep_copy_typ(axo_str_typ(state)), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind;}
#line 2744 "axo_gram.tab.c"
    break;

  case 34: /* expr: "integer literal"  */
#line 539 "axo_gram.y"
                    {
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val=(yyvsp[0].str),
      .typ=axo_int_typ(state)
    };
    (yyval.expression).typ.kind=axo_literal_kind;
  }
#line 2758 "axo_gram.tab.c"
    break;

  case 35: /* expr: "float literal"  */
#line 548 "axo_gram.y"
                  {set_val(&(yyval.expression), axo_float_typ(state), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2764 "axo_gram.tab.c"
    break;

  case 36: /* expr: "byte literal"  */
#line 549 "axo_gram.y"
                 {set_val(&(yyval.expression), axo_byte_typ(state), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2770 "axo_gram.tab.c"
    break;

  case 37: /* expr: "null"  */
#line 550 "axo_gram.y"
           {
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val="NULL",
      .typ=axo_none_ptr_typ
    };
  }
#line 2783 "axo_gram.tab.c"
    break;

  case 38: /* expr: "identifier" "::" "identifier"  */
#line 558 "axo_gram.y"
                   {
      axo_module* mod = axo_get_module(state, (yyvsp[-2].str));
      if (!mod){
        yyerror(&(yylsp[-2]), "Module '%s'is not loaded. Did you forget to use it?", (yyvsp[-2].str));
        YYERROR;
      }
      axo_var* var = axo_get_var(state->global_scope, fmt_str(s_str(1024), "%s%s", mod->prefix, (yyvsp[0].str)));
      if (var == NULL && rval_now)
        yyerror(&(yyloc), "Module '%s' doesn't have variable '%s'.", mod->name, (yyvsp[0].str));
      (yyval.expression) = (axo_expr){
        .val = fmtstr("%s%s", mod->prefix, (yyvsp[0].str)),
        .typ=(var ? var->typ : axo_no_typ),
        .kind = axo_expr_normal_kind,
        .lval_kind = axo_var_lval_kind
      };
  }
#line 2804 "axo_gram.tab.c"
    break;

  case 39: /* expr: expr '+' expr  */
#line 574 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "+", (yyvsp[0].expression)); }
#line 2810 "axo_gram.tab.c"
    break;

  case 40: /* expr: expr '-' expr  */
#line 575 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "-", (yyvsp[0].expression)); }
#line 2816 "axo_gram.tab.c"
    break;

  case 41: /* expr: '-' expr  */
#line 576 "axo_gram.y"
             {(yyval.expression).val = fmtstr("-%s", (yyvsp[0].expression).val); (yyval.expression).typ = (yyvsp[0].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2822 "axo_gram.tab.c"
    break;

  case 42: /* expr: expr '*' expr  */
#line 577 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "*", (yyvsp[0].expression)); }
#line 2828 "axo_gram.tab.c"
    break;

  case 43: /* expr: expr '/' expr  */
#line 578 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "/", (yyvsp[0].expression)); }
#line 2834 "axo_gram.tab.c"
    break;

  case 44: /* expr: expr '%' expr  */
#line 579 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "%", (yyvsp[0].expression)); }
#line 2840 "axo_gram.tab.c"
    break;

  case 45: /* expr: '(' expr ')'  */
#line 580 "axo_gram.y"
                 {
    (yyval.expression).val = fmtstr("(%s)", (yyvsp[-1].expression).val);
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).kind = (yyvsp[-1].expression).kind == axo_expr_assigned_declaration_kind?axo_expr_assigned_declaration_kind:axo_expr_normal_kind;
    free((yyvsp[-1].expression).val);
  }
#line 2851 "axo_gram.tab.c"
    break;

  case 46: /* expr: expr '@'  */
#line 586 "axo_gram.y"
             { //Referencing
    if ((yyvsp[-1].expression).lval_kind == axo_not_lval_kind)
      yyerror(&(yylsp[-1]), "Cannot reference a non l-value.");
    (yyval.expression).typ.kind = axo_ptr_kind;
    (yyval.expression).typ.subtyp = malloc(sizeof(axo_typ));
    (yyval.expression).val = fmtstr("&%s", (yyvsp[-1].expression).val);
    (yyval.expression).lval_kind = axo_not_lval_kind;
    *axo_subtyp((yyval.expression).typ) = (yyvsp[-1].expression).typ;
    free((yyvsp[-1].expression).val);
  }
#line 2866 "axo_gram.tab.c"
    break;

  case 47: /* expr: expr '.'  */
#line 596 "axo_gram.y"
             { //Dereferencing
    axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression));
    if ((yyvsp[-1].expression).typ.kind != axo_ptr_kind)
      yyerror(&(yylsp[-1]), "Cannot dereference a value of non-pointer type '%s'.", axo_typ_to_str((yyvsp[-1].expression).typ));
    (yyval.expression).typ = *axo_subtyp((yyvsp[-1].expression).typ);
    (yyval.expression).lval_kind=(yyvsp[-1].expression).lval_kind;
    (yyval.expression).val=fmtstr("(*(%s))", (yyvsp[-1].expression).val);
    free((yyvsp[-1].expression).val);
  }
#line 2880 "axo_gram.tab.c"
    break;

  case 50: /* expr: identifier  */
#line 607 "axo_gram.y"
               {
    char* var_name = "";
    axo_typ_def td;
    switch((yyvsp[0].identifier_type).kind){
      case axo_identifier_var_kind:
        var_name = (char*)((yyvsp[0].identifier_type).data);
        axo_var* var = axo_get_var(top_scope, (char*)((yyvsp[0].identifier_type).data));
        if (var == NULL && rval_now)
          yyerror(&(yylsp[0]), "Variable '%s' undefined before usage.", (char*)((yyvsp[0].identifier_type).data));
        else{
           (yyval.expression) = (axo_expr){
            .val=var_name,
            .typ=(var ? var->typ : axo_no_typ),
            .kind=axo_expr_normal_kind,
            .lval_kind=axo_var_lval_kind
          };
        }
        break;
      case axo_identifier_typ_kind:
        td = (yyvsp[0].identifier_type).typ_def;
        switch (td.typ.kind){
          case axo_enum_kind:
            (yyval.expression) = (axo_expr){
              .kind=axo_expr_enum_typ_kind,
              .typ=td.typ,
              .val=fmtstr("%s$%s", td.name, ((axo_enum*)(td.typ.enumerate))->names[0])
            };
            break;
          default:
            yyerror(&(yylsp[0]), "Non-enum type '%s' is not an expression.", td.name);
            break;
        }
        break;
      default:
        yyerror(&(yylsp[0]), "Invalid identifier as expression.");
        break;
    }
  }
#line 2923 "axo_gram.tab.c"
    break;

  case 51: /* expr: expr '?' expr ':' expr  */
#line 645 "axo_gram.y"
                           {
    if (axo_validate_rval(&(yylsp[-4]), (yyvsp[-4].expression)) && axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      if (axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
        (yyval.expression) = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", (yyvsp[-4].expression).val, (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
          .typ=(yyvsp[-2].expression).typ
        };
        free((yyvsp[-4].expression).val);
        free((yyvsp[-2].expression).val);
        free((yyvsp[0].expression).val);
      }else{
        yyerror(&(yyloc), "Ternary expression cannot return both '%s' and '%s'.", axo_typ_to_str((yyvsp[-2].expression).typ), axo_typ_to_str((yyvsp[0].expression).typ));
      }
    }
  }
#line 2945 "axo_gram.tab.c"
    break;

  case 52: /* expr: func_call  */
#line 662 "axo_gram.y"
              {(yyval.expression) = axo_call_to_expr((yyvsp[0].function_call));}
#line 2951 "axo_gram.tab.c"
    break;

  case 53: /* expr: expr '<' expr  */
#line 663 "axo_gram.y"
                  {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 2967 "axo_gram.tab.c"
    break;

  case 54: /* expr: expr '>' expr  */
#line 674 "axo_gram.y"
                  {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 2983 "axo_gram.tab.c"
    break;

  case 55: /* expr: expr "==" expr  */
#line 685 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s==%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 2999 "axo_gram.tab.c"
    break;

  case 56: /* expr: expr "!=" expr  */
#line 696 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s!=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 3015 "axo_gram.tab.c"
    break;

  case 57: /* expr: expr ">=" expr  */
#line 707 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 3031 "axo_gram.tab.c"
    break;

  case 58: /* expr: expr "<=" expr  */
#line 718 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
    free((yyvsp[-2].expression).val);
    free((yyvsp[0].expression).val);
  }
#line 3047 "axo_gram.tab.c"
    break;

  case 59: /* expr: expr "||" expr  */
#line 729 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s||%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 3061 "axo_gram.tab.c"
    break;

  case 60: /* expr: '!' expr  */
#line 738 "axo_gram.y"
             {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("!(%s)", (yyvsp[0].expression).val),
      .lval_kind = axo_not_lval_kind
    };
    if ((yyvsp[0].expression).typ.kind != axo_simple_kind)
      yyerror(&(yylsp[0]), "Negation can only be used on primitive types (byte, int etc.)");
  }
#line 3077 "axo_gram.tab.c"
    break;

  case 61: /* expr: expr "&&" expr  */
#line 749 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s&&%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 3091 "axo_gram.tab.c"
    break;

  case 62: /* expr: expr ">>" expr  */
#line 758 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s>>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 3105 "axo_gram.tab.c"
    break;

  case 63: /* expr: expr "<<" expr  */
#line 767 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s<<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 3119 "axo_gram.tab.c"
    break;

  case 64: /* expr: struct_literal  */
#line 776 "axo_gram.y"
                   {
    (yyval.expression).typ = (yyvsp[0].struct_val_type).typ;
    axo_struct* structure = (axo_struct*)((yyval.expression).typ.structure);
    //size of the string to avoid reallocing: (name){.field1=value1, }
    int v_len = strlen(structure->name) + 5 + 2;
    for (int i=0; i<structure->fields_len; i++){
      v_len+=strlen(structure->fields[i].name)+4+strlen((yyvsp[0].struct_val_type).fields[i]);  //name of a field + 3 cause of .=
    }
    char* v = (char*)malloc(v_len*sizeof(char));
    strcpy(v, "((");
    strcat(v, structure->name);
    strcat(v, "){");
    for (int i=0; i<structure->fields_len; i++){
      if (i!=0) strcat(v, ", ");
      strcat(v, ".");
      strcat(v, structure->fields[i].name);
      strcat(v, "=");
      strcat(v, (yyvsp[0].struct_val_type).fields[i]);
    }
    strcat(v,"})");
    (yyval.expression).val = v;
    (yyval.expression).kind = axo_expr_normal_kind;
  }
#line 3147 "axo_gram.tab.c"
    break;

  case 65: /* expr: expr index_access ']'  */
#line 799 "axo_gram.y"
                         {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    (yylsp[-1]).last_column = (yylsp[0]).last_column;
    axo_arr_typ arr_typ;
    switch((yyvsp[-2].expression).typ.kind){
      case axo_arr_kind:
        arr_typ = axo_get_arr_typ((yyvsp[-2].expression).typ);
        (yylsp[-1]).last_column = (yylsp[0]).last_column;
        if (arr_typ.dim_count != (yyvsp[-1].index_access_type).index_count){
          yyerror(&(yylsp[-1]), "Cannot index %d dimensional array with %d dimensional index.", arr_typ.dim_count, (yyvsp[-1].index_access_type).index_count);
        }else{
          (yyval.expression).val = axo_arr_access_to_str(&(yylsp[-2]), (yyvsp[-2].expression), &(yylsp[-1]), (yyvsp[-1].index_access_type));
          (yyval.expression).typ = arr_typ.subtyp;
          (yyval.expression).lval_kind = ((yyvsp[-2].expression).lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        }
        break;
      case axo_ptr_kind:
        if ((yyvsp[-1].index_access_type).index_count != 1)
          yyerror(&(yylsp[-1]), "Expected a 1 dimensional index to access a pointer, but got %d dimensional index.", (yyvsp[-1].index_access_type).index_count);
        (yyval.expression).typ = *axo_subtyp((yyvsp[-2].expression).typ);
        (yyval.expression).val = fmtstr("%s[%s]", (yyvsp[-2].expression).val, (yyvsp[-1].index_access_type).indexes[0].val);
        break;
      default:
        yyerror(&(yylsp[-2]), "Cannot index an expression of type '%s'.", axo_typ_to_str((yyvsp[-2].expression).typ));
        break;
    }
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_free_index_access((yyvsp[-1].index_access_type));
  }
#line 3181 "axo_gram.tab.c"
    break;

  case 66: /* expr: expr ".field"  */
#line 828 "axo_gram.y"
                   {
    axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression));
    (yyval.expression) = axo_expr_dot_field(state, &(yyloc), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-1].expression), (yyvsp[0].str));
  }
#line 3190 "axo_gram.tab.c"
    break;

  case 67: /* expr: "sz_of" '(' expr ')'  */
#line 832 "axo_gram.y"
                         {
    const axo_typ_def* lu_def = axo_get_typ_def(state, "size_t");
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("sizeof(%s)", (yyvsp[-1].expression).val),
      .typ = lu_def->typ
    };
  }
#line 3204 "axo_gram.tab.c"
    break;

  case 68: /* expr: "type_sz" '(' val_typ ')'  */
#line 841 "axo_gram.y"
                              {
    const axo_typ_def* lu_def = axo_get_typ_def(state, "size_t");
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("sizeof(%s)", axo_typ_to_c_str((yyvsp[-1].typ_type))),
      .typ = lu_def->typ
    };
  }
#line 3218 "axo_gram.tab.c"
    break;

  case 69: /* expr: "#line"  */
#line 850 "axo_gram.y"
            {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("%d", (yyloc).first_line),
      .typ = axo_int_typ(state)
    };
  }
#line 3231 "axo_gram.tab.c"
    break;

  case 70: /* expr: "#column"  */
#line 858 "axo_gram.y"
              {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("%d", (yyloc).first_column),
      .typ = axo_int_typ(state)
    };
  }
#line 3244 "axo_gram.tab.c"
    break;

  case 71: /* expr: "#file"  */
#line 866 "axo_gram.y"
            {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("\"%s\"", axo_src_path(state)),
      .typ = axo_str_typ(state)
    };
  }
#line 3257 "axo_gram.tab.c"
    break;

  case 74: /* expr: expr '.' '(' val_typ ')'  */
#line 876 "axo_gram.y"
                             {
    axo_validate_rval(&(yylsp[-4]), (yyvsp[-4].expression));
    switch((yyvsp[-4].expression).typ.kind){
      case axo_simple_kind:
      case axo_literal_kind:
        if ((yyvsp[-1].typ_type).kind != axo_simple_kind)
          yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[-4].expression).typ), axo_typ_to_str((yyvsp[-1].typ_type)));
        else
          (yyval.expression) = (axo_expr){
            .typ=(yyvsp[-1].typ_type),
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str((yyvsp[-1].typ_type)), (yyvsp[-4].expression).val),
            .kind=axo_expr_normal_kind,
            .lval_kind=(yyvsp[-4].expression).lval_kind
          };
        break;
      case axo_ptr_kind:
        if ((yyvsp[-1].typ_type).kind != axo_ptr_kind)
          yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[-4].expression).typ), axo_typ_to_str((yyvsp[-1].typ_type)));
        else
          (yyval.expression) = (axo_expr){
            .typ=(yyvsp[-1].typ_type),
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str((yyvsp[-1].typ_type)), (yyvsp[-4].expression).val),
            .kind=axo_expr_normal_kind,
            .lval_kind=(yyvsp[-4].expression).lval_kind
          };
        break;
      default:
          yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[-4].expression).typ), axo_typ_to_str((yyvsp[-1].typ_type)));
        break;
    }
  }
#line 3293 "axo_gram.tab.c"
    break;

  case 75: /* expr: '$'  */
#line 907 "axo_gram.y"
        {
    axo_var* var = axo_get_var(top_scope, "_axo_self_param");
    if (!var){
      yyerror(&(yyloc), "Cannot use self param '$' outside of a method.");
      YYERROR;
    }
    (yyval.expression) = (axo_expr){
      .val=alloc_str("_axo_self_param"),
      .typ=(var ? var->typ : axo_no_typ),
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_var_lval_kind
    };
  }
#line 3311 "axo_gram.tab.c"
    break;

  case 76: /* stat_arr_literal_start: arr_lit_start expr ',' expr  */
#line 922 "axo_gram.y"
                                                     {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyvsp[-2].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[-3].bool_type),
      .len=(int[]){0},
      .dim_count=1,
      .count=2,
      .val=fmtstr("%s,%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 3331 "axo_gram.tab.c"
    break;

  case 77: /* stat_arr_literal_start: empty_arr_dims ']' '[' expr ',' expr  */
#line 937 "axo_gram.y"
                                         {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyvsp[-2].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[-5].empty_arr_lit_type).dynamic,
      .len=(yyvsp[-5].empty_arr_lit_type).len,
      .dim_count=(yyvsp[-5].empty_arr_lit_type).dim_count,
      .count=2,
      .val= fmtstr("%s, %s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 3351 "axo_gram.tab.c"
    break;

  case 78: /* stat_arr_literal_start: stat_arr_literal_start ',' expr  */
#line 952 "axo_gram.y"
                                    {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyval.arr_lit_type).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyval.arr_lit_type).typ));
    }
    strapnd(&(yyval.arr_lit_type).val, ",");
    strapnd(&(yyval.arr_lit_type).val, (yyvsp[0].expression).val);
    (yyval.arr_lit_type).count++;
  }
#line 3365 "axo_gram.tab.c"
    break;

  case 79: /* arr_lit_start: '['  */
#line 963 "axo_gram.y"
                    {
    (yyval.bool_type) = false;
  }
#line 3373 "axo_gram.tab.c"
    break;

  case 80: /* arr_lit_start: '[' '?'  */
#line 966 "axo_gram.y"
            {
    (yyval.bool_type) = true;
  }
#line 3381 "axo_gram.tab.c"
    break;

  case 81: /* empty_arr_dims: arr_lit_start "integer literal"  */
#line 971 "axo_gram.y"
                                               {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=(yyvsp[-1].bool_type),
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[0].str));
    free((yyvsp[0].str));
  }
#line 3395 "axo_gram.tab.c"
    break;

  case 82: /* empty_arr_dims: empty_arr_dims '|' "integer literal"  */
#line 980 "axo_gram.y"
                                       {
    (yyval.empty_arr_lit_type).len[(yyval.empty_arr_lit_type).dim_count++] = atoi((yyvsp[0].str));
    free((yyvsp[0].str));
  }
#line 3404 "axo_gram.tab.c"
    break;

  case 83: /* stat_arr_literal: arr_lit_start expr ',' ']'  */
#line 986 "axo_gram.y"
                                              {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_typ subtyp[1] = {(yyvsp[-2].expression).typ};
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[-3].bool_type),
      .len=(int[]){1},
      .dim_count=1,
      .count=1,
      .val= (yyvsp[-3].bool_type) ?
          fmtstr("axo_arr_new_dyn(axo_dyn_bytes_cpy(%s, (%s){%s}, sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){1}, sizeof(axo_arr_dim_t)))",
          axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=subtyp}), axo_c_arr_of_typ((yyvsp[-2].expression).typ, "1"), (yyvsp[-2].expression).val, axo_typ_to_c_str((yyvsp[-2].expression).typ))
          : fmtstr("axo_arr_new_stat((%s){%s}, ((axo_arr_dim_t[]){1}))",
          axo_c_arr_of_typ((yyvsp[-2].expression).typ, "1"), (yyvsp[-2].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 3425 "axo_gram.tab.c"
    break;

  case 84: /* stat_arr_literal: stat_arr_literal_start ']'  */
#line 1002 "axo_gram.y"
                               {
    char* data_str = (yyval.arr_lit_type).val;
    (yyval.arr_lit_type).val = NULL;
    if ((yyval.arr_lit_type).len[0] != 0){
      unsigned expected = 1;
      for (int i=0; i<(yyval.arr_lit_type).dim_count; i++)
        expected *= (yyval.arr_lit_type).len[i];
      if (expected != (yyval.arr_lit_type).count)
        yyerror(&(yyloc), "Expected %u elements, but provided %u.", expected, (yyval.arr_lit_type).count);
    }else{
      (yyval.arr_lit_type).len = (int[]){(yyval.arr_lit_type).count};
      (yyval.arr_lit_type).dim_count = 1;
    }
    char* len_str = alloc_str("{");
    char hlpr[128];
    for (int i=0; i<(yyval.arr_lit_type).dim_count; i++){
      if (i>0) strapnd(&len_str, ",");
      sprintf(hlpr, "%d", (yyval.arr_lit_type).len[i]);
      strapnd(&len_str, hlpr);
    }
    axo_typ subtyp[1] = {(yyval.arr_lit_type).typ};
    char count_str[16] = "";
    sprintf(count_str, "%d", (yyval.arr_lit_type).count);
    (yyval.arr_lit_type).val= (yyval.arr_lit_type).dynamic ?
      fmtstr("axo_arr_new_dyn(axo_dyn_bytes_cpy(%s, ((%s){%s}), %u*sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, ((axo_arr_dim_t[])%s}), %d*sizeof(axo_arr_dim_t)))",
      axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=subtyp}), axo_c_arr_of_typ((yyval.arr_lit_type).typ, count_str), data_str, (yyval.arr_lit_type).count, axo_typ_to_c_str((yyval.arr_lit_type).typ), len_str, (yyval.arr_lit_type).dim_count)
      : fmtstr("axo_arr_new_stat(((%s){%s}), ((axo_arr_dim_t[])%s}))",
      axo_c_arr_of_typ((yyval.arr_lit_type).typ, ""), data_str, len_str);
    free(len_str);
  }
#line 3460 "axo_gram.tab.c"
    break;

  case 85: /* arr_literal: stat_arr_literal  */
#line 1034 "axo_gram.y"
                               {
    (yyval.expression)=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val=(yyvsp[0].arr_lit_type).val,
    };
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    arr_typ->subtyp = (yyvsp[0].arr_lit_type).typ;
    arr_typ->dim_count = (yyvsp[0].arr_lit_type).dim_count;
    (yyval.expression).typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ,
      .def=NULL
    };
  }
#line 3480 "axo_gram.tab.c"
    break;

  case 86: /* arr_literal: empty_arr_dims ']' val_typ  */
#line 1049 "axo_gram.y"
                               {
    char* dims_str = empty_str;
    unsigned total_sz = 1;
    for (int i=0; i<(yyvsp[-2].empty_arr_lit_type).dim_count; i++){
      total_sz *= (yyvsp[-2].empty_arr_lit_type).len[i];
      if (i>0) strapnd(&dims_str, ",");
      strapnd(&dims_str, fmt_str((char[16]){}, "%d", (yyvsp[-2].empty_arr_lit_type).len[i]));
    }
    axo_typ typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=malloc(sizeof(axo_arr_typ)),
      .def=NULL
    };
    axo_get_arr_typ(typ).subtyp = (yyvsp[0].typ_type);
    axo_get_arr_typ(typ).dim_count = (yyvsp[-2].empty_arr_lit_type).dim_count;
    char sz_str[128];
    sprintf(sz_str, "%u", total_sz);
    (yyval.expression)=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val= (yyvsp[-2].empty_arr_lit_type).dynamic ?
          fmtstr("axo_arr_new_dyn(malloc((%u)*sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){%s}, (%d)*sizeof(axo_arr_dim_t)))", total_sz, axo_typ_to_c_str(axo_get_arr_typ(typ).subtyp), dims_str, (yyvsp[-2].empty_arr_lit_type).dim_count)
          : fmtstr("axo_arr_new_stat((%s){}, ((axo_arr_dim_t[]){%s}))", axo_c_arr_of_typ((yyvsp[0].typ_type), sz_str), dims_str),
      .typ=typ
    };
    free(dims_str);
  }
#line 3512 "axo_gram.tab.c"
    break;

  case 89: /* matching_statement: expr  */
#line 1080 "axo_gram.y"
                          {
    axo_validate_expr_as_statement(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 3523 "axo_gram.tab.c"
    break;

  case 90: /* matching_statement: ';'  */
#line 1086 "axo_gram.y"
        {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_empty_statement_kind,
      .val=alloc_str(";")
    };
  }
#line 3534 "axo_gram.tab.c"
    break;

  case 91: /* matching_statement: "ret" expr  */
#line 1092 "axo_gram.y"
               {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.statement_type).val=fmtstr("return %s;", (yyvsp[0].expression).val);
    (yyval.statement_type).kind = axo_ret_statement_kind;
    axo_var* parent_func = (axo_var*)(top_scope->parent_func);
    if (parent_func){
      axo_typ* ret_typ = &(((axo_func_typ*)(parent_func->typ.func_typ))->ret_typ);
      if (axo_is_no_typ(*ret_typ)){
        *ret_typ = (yyvsp[0].expression).typ;
      }else if(!axo_typ_eq(*ret_typ, (yyvsp[0].expression).typ)){
        char hlpr[64] = "";
        strcpy(hlpr, axo_typ_to_str(*ret_typ));
        yyerror(&(yylsp[0]), "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str((yyvsp[0].expression).typ), hlpr);
      }
    }else{
      yyerror(&(yylsp[-1]), "Couldn't return outside of a function body.");
    }
    free((yyvsp[0].expression).val);
  }
#line 3558 "axo_gram.tab.c"
    break;

  case 92: /* matching_statement: "ret" ';'  */
#line 1111 "axo_gram.y"
              {
    (yyval.statement_type).val=alloc_str("return;");
    (yyval.statement_type).kind = axo_ret_statement_kind;
    axo_var* parent_func = (axo_var*)(top_scope->parent_func);
    if (parent_func){
      axo_typ* ret_typ = &(((axo_func_typ*)(parent_func->typ.func_typ))->ret_typ);
      if (axo_is_no_typ(*ret_typ)){
        *ret_typ = axo_none_typ;
      }else if(!axo_typ_eq(*ret_typ, axo_none_typ)){
        char hlpr[64] = "";
        strcpy(hlpr, axo_typ_to_str(*ret_typ));
        yyerror(&(yylsp[0]), "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str(axo_none_typ), hlpr);
      }
    }else{
      yyerror(&(yylsp[-1]), "Couldn't return outside of a function body.");
    }
  }
#line 3580 "axo_gram.tab.c"
    break;

  case 93: /* matching_statement: code_scope  */
#line 1128 "axo_gram.y"
               {
    (yyval.statement_type) = axo_scope_to_statement((yyvsp[0].scope));
    axo_free_scope((yyvsp[0].scope));
  }
#line 3589 "axo_gram.tab.c"
    break;

  case 94: /* matching_statement: expr '=' "none" val_typ  */
#line 1132 "axo_gram.y"
                             {
    if ((yyvsp[-3].expression).lval_kind == axo_var_lval_kind){
      char* ntd = axo_name_typ_decl((yyvsp[-3].expression).val, (yyvsp[0].typ_type));
      (yyval.statement_type) = (axo_statement){
        .kind=axo_var_is_decl_statement_kind,
        .val=ntd
      };
      strapnd(&((yyval.statement_type).val), ";");
      axo_set_var(top_scope, (axo_var){.name=(yyvsp[-3].expression).val, .typ=axo_clean_typ((yyvsp[0].typ_type))});
    }else{
      yyerror(&(yylsp[-3]), "Cannot declare non-variable value '%s'.", (yyvsp[-3].expression).val);
    }
    free((yyvsp[-3].expression).val);
  }
#line 3608 "axo_gram.tab.c"
    break;

  case 95: /* matching_statement: "continue"  */
#line 1146 "axo_gram.y"
               {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop/switch to continue from.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = alloc_str("continue;")
    };
  }
#line 3620 "axo_gram.tab.c"
    break;

  case 96: /* matching_statement: "break"  */
#line 1153 "axo_gram.y"
            {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop/switch to break out of.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = alloc_str("break;")
    };
  }
#line 3632 "axo_gram.tab.c"
    break;

  case 97: /* matching_statement: switch_statement  */
#line 1160 "axo_gram.y"
                     {
    (yyval.statement_type) = axo_switch_to_statement((yyvsp[0].switch_type));
  }
#line 3640 "axo_gram.tab.c"
    break;

  case 98: /* matching_statement: "defer" matching_statement  */
#line 1163 "axo_gram.y"
                               {
    top_scope->defer_used = true;
    (yyval.statement_type) = (axo_statement){
      .kind=axo_defer_statement_kind,
      .val=fmtstr("Defer({%s});", (yyvsp[0].statement_type).val)
    };
    free((yyvsp[0].statement_type).val);
  }
#line 3653 "axo_gram.tab.c"
    break;

  case 99: /* matching_statement: type_qualifier identifier '=' expr  */
#line 1171 "axo_gram.y"
                                       {
    axo_typ typ = axo_merge_type_with_qualifiers((yyvsp[0].expression).typ, (yyvsp[-3].typ_type));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    char* var_name = ((char*)((yyvsp[-2].identifier_type).data));
    if ((yyvsp[-2].identifier_type).kind != axo_identifier_var_kind || axo_get_var(top_scope, var_name) != NULL){
      yyerror(&(yylsp[-2]), "Cannot declare variable, it's already a %s.", axo_identifier_kind_to_str((yyvsp[-2].identifier_type).kind));
      YYERROR;
    }
    axo_var var = (axo_var){.name=var_name, .typ=typ};
    axo_set_var(top_scope, var);
    char* assign_decl = axo_get_var_decl_assign(&(yyloc), var, (yyvsp[0].expression));
    (yyval.statement_type) = (axo_statement){
      .kind=axo_assignment_statement_kind,
      .val = fmtstr("%s;", assign_decl)
    };
    free(assign_decl);
  }
#line 3675 "axo_gram.tab.c"
    break;

  case 104: /* switch_statement_start: "switch" expr  */
#line 1194 "axo_gram.y"
                                       {
    if ((yyvsp[0].expression).typ.kind != axo_simple_kind)
      yyerror(&(yylsp[0]), "Cannot switch on a non-primitive (%s) value.", axo_typ_to_str((yyvsp[0].expression).typ));
    (yyval.switch_type) = (axo_switch){
      .root = (yyvsp[0].expression)
    };
    in_loop_count++;
  }
#line 3688 "axo_gram.tab.c"
    break;

  case 105: /* switch_statement: switch_statement_start '{' switch_body '}'  */
#line 1204 "axo_gram.y"
                                                              {
    (yyval.switch_type) = (axo_switch){
      .root=(yyvsp[-3].switch_type).root,
      .cases = (yyvsp[-1].switch_type).cases,
      .cases_len = (yyvsp[-1].switch_type).cases_len
    };
    in_loop_count--;
  }
#line 3701 "axo_gram.tab.c"
    break;

  case 106: /* switch_body: switch_branch statement  */
#line 1214 "axo_gram.y"
                                      {
    (yyval.switch_type) = (axo_switch){
      .cases = (axo_switch_case*)malloc(axo_cases_cap*sizeof(axo_switch_case)),
      .cases_len = 1
    };
    (yyval.switch_type).cases[0] = (yyvsp[-1].case_type);
    (yyval.switch_type).cases[0].statement = (yyvsp[0].statement_type);
  }
#line 3714 "axo_gram.tab.c"
    break;

  case 107: /* switch_body: switch_body switch_branch statement  */
#line 1222 "axo_gram.y"
                                        {
    resize_dyn_arr_if_needed(axo_switch_case, (yyval.switch_type).cases, (yyval.switch_type).cases_len, axo_cases_cap);
    (yyval.switch_type).cases[(yyval.switch_type).cases_len] = (yyvsp[-1].case_type);
    (yyval.switch_type).cases[(yyval.switch_type).cases_len++].statement = (yyvsp[0].statement_type);
  }
#line 3724 "axo_gram.tab.c"
    break;

  case 108: /* switch_branch: switch_case "none" "break"  */
#line 1229 "axo_gram.y"
                                           {
    (yyval.case_type)=(yyvsp[-2].case_type);
    (yyval.case_type).no_break = true;
  }
#line 3733 "axo_gram.tab.c"
    break;

  case 110: /* switch_case: switch_expr_list "case"  */
#line 1236 "axo_gram.y"
                                      {
    (yyval.case_type) = (yyvsp[-1].case_type);
  }
#line 3741 "axo_gram.tab.c"
    break;

  case 111: /* switch_expr_list: expr  */
#line 1250 "axo_gram.y"
                        {
    (yyval.case_type) = (axo_switch_case){
      .exprs = (axo_expr*)malloc(axo_switch_expr_list_cap*sizeof(axo_expr)),
      .exprs_len = 1,
      .kind = axo_list_case_kind
    };
    (yyval.case_type).exprs[0] = (yyvsp[0].expression);
  }
#line 3754 "axo_gram.tab.c"
    break;

  case 112: /* switch_expr_list: switch_expr_list ',' expr  */
#line 1258 "axo_gram.y"
                              {
    resize_dyn_arr_if_needed(axo_expr, (yyval.case_type).exprs, (yyval.case_type).exprs_len, axo_switch_expr_list_cap);
    (yyval.case_type).exprs[(yyval.case_type).exprs_len++] = (yyvsp[0].expression);
  }
#line 3763 "axo_gram.tab.c"
    break;

  case 113: /* if_condition: "if" expr  */
#line 1264 "axo_gram.y"
                            {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 3772 "axo_gram.tab.c"
    break;

  case 114: /* matching_if_statement: if_condition matching_statement "else" matching_statement  */
#line 1270 "axo_gram.y"
                                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 3780 "axo_gram.tab.c"
    break;

  case 119: /* non_matching_if_statement: if_condition statement  */
#line 1281 "axo_gram.y"
                                                   {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s", (yyvsp[-1].expression).val, (yyvsp[0].statement_type).val);
  }
#line 3788 "axo_gram.tab.c"
    break;

  case 120: /* non_matching_if_statement: if_condition matching_statement "else" non_matching_statement  */
#line 1284 "axo_gram.y"
                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 3796 "axo_gram.tab.c"
    break;

  case 121: /* till_loop_start: "till" '(' "identifier" '=' expr ')'  */
#line 1289 "axo_gram.y"
                                                   {
    (yyval.till_loop_type).iter = (yyvsp[-3].str);
    (yyval.till_loop_type).start = "0";
    (yyval.till_loop_type).lim = (yyvsp[-1].expression);
    printf("till iter %s created scope\n", (yyval.till_loop_type).iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=state->int_def->typ, .name=(yyval.till_loop_type).iter});
  }
#line 3809 "axo_gram.tab.c"
    break;

  case 122: /* while_loop_base: "while" expr  */
#line 1299 "axo_gram.y"
                               {
    if (axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression)))
      (yyval.str) = alloc_str((yyvsp[0].expression).val);
    in_loop_count++;
  }
#line 3819 "axo_gram.tab.c"
    break;

  case 123: /* matching_while: while_loop_base matching_statement  */
#line 1306 "axo_gram.y"
                                                    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 3831 "axo_gram.tab.c"
    break;

  case 124: /* non_matching_while: while_loop_base non_matching_statement  */
#line 1315 "axo_gram.y"
                                                            {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 3843 "axo_gram.tab.c"
    break;

  case 125: /* for_loop_start: "for"  */
#line 1324 "axo_gram.y"
                       {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    in_loop_count++;
  }
#line 3852 "axo_gram.tab.c"
    break;

  case 126: /* for_loop_init: for_loop_start statement  */
#line 1330 "axo_gram.y"
                                         {
    (yyval.for_loop_type).start = (yyvsp[0].statement_type).val;
  }
#line 3860 "axo_gram.tab.c"
    break;

  case 127: /* for_loop_base: for_loop_init ',' expr ',' statement  */
#line 1335 "axo_gram.y"
                                                     {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    char* iter = (yyvsp[0].statement_type).val;
    iter[strlen(iter)-1] = '\0';
    (yyval.for_loop_type) = (axo_for_loop){
      .start = (yyvsp[-4].for_loop_type).start,
      .condition = (yyvsp[-2].expression).val,
      .iteration = iter,
    };
  }
#line 3875 "axo_gram.tab.c"
    break;

  case 128: /* for_loop_base: till_loop_start  */
#line 1345 "axo_gram.y"
                    {
    (yyval.for_loop_type) = (axo_for_loop){
      .start = fmtstr("int %s=%s;", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).start),
      .condition = fmtstr("%s<%s", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).lim.val),
      .iteration = fmtstr("%s++", (yyvsp[0].till_loop_type).iter),
    };
  }
#line 3887 "axo_gram.tab.c"
    break;

  case 129: /* matching_for_loop: for_loop_base matching_statement  */
#line 1355 "axo_gram.y"
                                                     {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3899 "axo_gram.tab.c"
    break;

  case 130: /* non_matching_for_loop: for_loop_base non_matching_statement  */
#line 1363 "axo_gram.y"
                                                             {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3911 "axo_gram.tab.c"
    break;

  case 131: /* matching_each_loop: each_loop_base matching_statement  */
#line 1372 "axo_gram.y"
                                                       {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3922 "axo_gram.tab.c"
    break;

  case 132: /* non_matching_each_loop: each_loop_base non_matching_statement  */
#line 1380 "axo_gram.y"
                                                               {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3933 "axo_gram.tab.c"
    break;

  case 133: /* each_iter_dims: '[' expr  */
#line 1388 "axo_gram.y"
                          {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=1,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3] = (yylsp[0]);
  }
#line 3947 "axo_gram.tab.c"
    break;

  case 134: /* each_iter_dims: '[' '|' expr  */
#line 1397 "axo_gram.y"
                 {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=2,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (axo_expr){.val=NULL};
    (yyval.each_loop_type).dim_iters[1] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[4] = (yylsp[0]);
  }
#line 3962 "axo_gram.tab.c"
    break;

  case 135: /* each_iter_dims: each_iter_dims '|' expr  */
#line 1407 "axo_gram.y"
                            {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3+(yyval.each_loop_type).dim_count++] = (yylsp[0]);
  }
#line 3971 "axo_gram.tab.c"
    break;

  case 136: /* each_iter_dims: each_iter_dims '|'  */
#line 1411 "axo_gram.y"
                       {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count++] = (axo_expr){.val=NULL};
  }
#line 3979 "axo_gram.tab.c"
    break;

  case 137: /* each_loop_base: for_loop_start identifier "in" expr  */
#line 1416 "axo_gram.y"
                                                    {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=axo_get_arr_typ((yyvsp[0].expression).typ).dim_count,
      .dim_iters=malloc(axo_get_arr_typ((yyvsp[0].expression).typ).dim_count*sizeof(axo_expr)),
      .value_iter=(yyvsp[-2].identifier_type),
      .collection=(yyvsp[0].expression),
      .locs=malloc(3*sizeof(YYLTYPE*))
    };
    for (int i=0; i<(yyval.each_loop_type).dim_count; i++)
      (yyval.each_loop_type).dim_iters[i].val = NULL;
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[-2]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[0]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
#line 3998 "axo_gram.tab.c"
    break;

  case 138: /* each_loop_base: for_loop_start identifier "each" each_iter_dims ']' "in" expr  */
#line 1430 "axo_gram.y"
                                                                  {
    (yylsp[-3]).last_column = (yylsp[-2]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[-3].each_loop_type).dim_count,
      .dim_iters=(yyvsp[-3].each_loop_type).dim_iters,
      .value_iter=(yyvsp[-5].identifier_type),
      .collection=(yyvsp[0].expression),
      .locs=(yyvsp[-3].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[-5]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[-3]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[0]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
#line 4017 "axo_gram.tab.c"
    break;

  case 139: /* each_loop_base: for_loop_start "each" each_iter_dims ']' "in" expr  */
#line 1444 "axo_gram.y"
                                                       {
    (yylsp[-3]).last_column = (yylsp[-3]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[-3].each_loop_type).dim_count,
      .dim_iters=(yyvsp[-3].each_loop_type).dim_iters,
      .value_iter=(axo_identifier){.kind=axo_no_identifier_kind, .data=NULL},
      .collection=(yyvsp[0].expression),
      .locs=(yyvsp[-3].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[-3]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[0]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
#line 4035 "axo_gram.tab.c"
    break;

  case 140: /* assign_op: '='  */
#line 1459 "axo_gram.y"
                {
    rval_now = true;
  }
#line 4043 "axo_gram.tab.c"
    break;

  case 141: /* assignment: expr assign_op expr  */
#line 1464 "axo_gram.y"
                                 {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_typ l_typ = (yyvsp[-2].expression).typ;
    switch((yyvsp[-2].expression).lval_kind){
      case axo_var_lval_kind:
        if ((yyvsp[-2].expression).typ.kind == axo_no_kind){
          l_typ = axo_clean_typ((yyvsp[0].expression).typ);
          axo_var var = (axo_var){.name=(yyvsp[-2].expression).val, .typ=(yyvsp[0].expression).typ};
          (yyval.expression).val = axo_get_var_decl_assign(&(yyloc), var, (axo_expr){.typ=l_typ, .val=(yyvsp[0].expression).val});
          axo_set_var(top_scope, (axo_var){.typ = l_typ, .name = (yyvsp[-2].expression).val});
          (yyval.expression).kind = axo_expr_assigned_declaration_kind;
        }else{
          (yyval.expression).val = fmtstr("%s=%s",(yyvsp[-2].expression).val, (yyvsp[0].expression).val);
        }
        break;
      case axo_not_lval_kind:
        yyerror(&(yylsp[-2]), "Cannot assign to a non-lvalue");
        break;
      default:
        if (!axo_typ_eq(l_typ, (yyvsp[0].expression).typ))
          yyerror(&(yyloc), "Cannot assign '%s' to '%s'.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str(l_typ));
        else{
          (yyval.expression).val = fmtstr("%s=%s",(yyvsp[-2].expression).val, (yyvsp[0].expression).val);
        }
        break;
    }
    (yyval.expression).typ = l_typ;
    rval_now=false;
  }
#line 4078 "axo_gram.tab.c"
    break;

  case 142: /* special_assignment: expr "+=" expr  */
#line 1496 "axo_gram.y"
                                    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[-2]), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-2].expression), "+=", (yyvsp[0].expression));
  }
#line 4086 "axo_gram.tab.c"
    break;

  case 143: /* special_assignment: expr "-=" expr  */
#line 1499 "axo_gram.y"
                   {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[-2]), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-2].expression), "-=", (yyvsp[0].expression));
  }
#line 4094 "axo_gram.tab.c"
    break;

  case 144: /* special_assignment: expr "*=" expr  */
#line 1502 "axo_gram.y"
                   {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[-2]), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-2].expression), "*=", (yyvsp[0].expression));
  }
#line 4102 "axo_gram.tab.c"
    break;

  case 145: /* special_assignment: expr "/=" expr  */
#line 1505 "axo_gram.y"
                   {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[-2]), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-2].expression), "/=", (yyvsp[0].expression));
  }
#line 4110 "axo_gram.tab.c"
    break;

  case 146: /* special_assignment: expr "%=" expr  */
#line 1508 "axo_gram.y"
                   {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[-2]), &(yylsp[-1]), &(yylsp[0]), (yyvsp[-2].expression), "%=", (yyvsp[0].expression));
  }
#line 4118 "axo_gram.tab.c"
    break;

  case 147: /* arr_multidim_typ: '[' '|'  */
#line 1513 "axo_gram.y"
                           {
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    *arr_typ = (axo_arr_typ){
      .dim_count=2
    };
    (yyval.typ_type) = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ
    };
  }
#line 4133 "axo_gram.tab.c"
    break;

  case 148: /* arr_multidim_typ: arr_multidim_typ '|'  */
#line 1523 "axo_gram.y"
                         {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_get_arr_typ((yyval.typ_type)).dim_count++;
  }
#line 4142 "axo_gram.tab.c"
    break;

  case 149: /* arr_typ: '[' ']' val_typ  */
#line 1529 "axo_gram.y"
                          {
    if (axo_none_check((yyvsp[0].typ_type)))
      yyerror(&(yylsp[0]), "None arrays are not a type.");
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    *arr_typ = (axo_arr_typ){
      .subtyp=(yyvsp[0].typ_type),
      .dim_count=1
    };
    (yyval.typ_type) = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ
    };
  }
#line 4160 "axo_gram.tab.c"
    break;

  case 150: /* arr_typ: arr_multidim_typ ']' val_typ  */
#line 1542 "axo_gram.y"
                                 {
    if (axo_none_check((yyvsp[0].typ_type)))
      yyerror(&(yylsp[0]), "None arrays are not a type.");
    (yyval.typ_type) = (yyvsp[-2].typ_type);
    axo_get_arr_typ((yyval.typ_type)).subtyp = (yyvsp[0].typ_type);
  }
#line 4171 "axo_gram.tab.c"
    break;

  case 151: /* func_typ_start: '(' val_typ "fn"  */
#line 1550 "axo_gram.y"
                                     {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=(yyvsp[-1].typ_type);
    (yyval.typ_type) = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  }
#line 4187 "axo_gram.tab.c"
    break;

  case 152: /* func_typ_start: '(' "fn"  */
#line 1561 "axo_gram.y"
                {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=axo_none_typ;
    (yyval.typ_type) = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  }
#line 4203 "axo_gram.tab.c"
    break;

  case 153: /* func_typ_args: func_typ_start val_typ  */
#line 1574 "axo_gram.y"
                                       {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = (yyvsp[0].typ_type);
    func_typ->args_defs[0] = alloc_str(axo_get_typ_default((yyvsp[0].typ_type)));
    func_typ->args_len++;
  }
#line 4217 "axo_gram.tab.c"
    break;

  case 154: /* func_typ_args: func_typ_args ',' val_typ  */
#line 1583 "axo_gram.y"
                              {
    (yyval.typ_type)=(yyvsp[-2].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = (yyvsp[0].typ_type);
    func_typ->args_defs[func_typ->args_len] = alloc_str(axo_get_typ_default((yyvsp[0].typ_type)));
    func_typ->args_len++;
  }
#line 4231 "axo_gram.tab.c"
    break;

  case 157: /* no_q_typ: "identifier"  */
#line 1598 "axo_gram.y"
                {
    const axo_typ_def* def = axo_get_typ_def(state, (yyvsp[0].str));
    if (def==NULL){
      yyerror(&(yylsp[0]), "Type '%s' isn't defined.", (yyvsp[0].str));
    }else{
      (yyval.typ_type)=def->typ;
    }
  }
#line 4244 "axo_gram.tab.c"
    break;

  case 158: /* no_q_typ: '@' val_typ  */
#line 1606 "axo_gram.y"
                {
    (yyval.typ_type) = (axo_typ){
      .kind = axo_ptr_kind,
      .subtyp = malloc(sizeof(axo_typ)),
      .def = NULL,
    };
    *axo_subtyp((yyval.typ_type))=(yyvsp[0].typ_type);
  }
#line 4257 "axo_gram.tab.c"
    break;

  case 159: /* no_q_typ: "none"  */
#line 1614 "axo_gram.y"
           {
    (yyval.typ_type) = axo_none_typ;
  }
#line 4265 "axo_gram.tab.c"
    break;

  case 162: /* no_q_typ: '.' '.' '.'  */
#line 1619 "axo_gram.y"
                {
    (yyval.typ_type) = (axo_typ){
      .kind = axo_c_arg_list_kind,
      .def = NULL,
    };
  }
#line 4276 "axo_gram.tab.c"
    break;

  case 163: /* val_typ: no_q_typ  */
#line 1627 "axo_gram.y"
                   {
    (yyval.typ_type).is_const=false;
    (yyval.typ_type).is_volatile=false;
  }
#line 4285 "axo_gram.tab.c"
    break;

  case 164: /* val_typ: type_qualifier no_q_typ  */
#line 1631 "axo_gram.y"
                            {
    (yyval.typ_type) = (yyvsp[0].typ_type);
    (yyval.typ_type).is_const=(yyvsp[-1].typ_type).is_const;
    (yyval.typ_type).is_volatile=(yyvsp[-1].typ_type).is_volatile;
  }
#line 4295 "axo_gram.tab.c"
    break;

  case 166: /* type_qualifier: type_qualifier typ_q  */
#line 1639 "axo_gram.y"
                           {
      (yyval.typ_type) = (axo_typ){
        .is_const=(yyvsp[-1].typ_type).is_const||(yyvsp[0].typ_type).is_const,
        .is_volatile=(yyvsp[-1].typ_type).is_volatile||(yyvsp[0].typ_type).is_volatile
      };
    }
#line 4306 "axo_gram.tab.c"
    break;

  case 167: /* typ_q: "const"  */
#line 1647 "axo_gram.y"
                {
      (yyval.typ_type) = (axo_typ){.is_const=true, .is_volatile=false};
    }
#line 4314 "axo_gram.tab.c"
    break;

  case 168: /* typ_q: "volatile"  */
#line 1650 "axo_gram.y"
                 {
      (yyval.typ_type) = (axo_typ){.is_const=false, .is_volatile=true};
    }
#line 4322 "axo_gram.tab.c"
    break;

  case 169: /* called_expr: expr '('  */
#line 1655 "axo_gram.y"
                       {
    if (axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression))){
      switch((yyvsp[-1].expression).typ.kind){
        case axo_func_kind:
          (yyval.function_call) = (axo_func_call){
            .typ = (yyvsp[-1].expression).typ,
            .called_val = (yyvsp[-1].expression).val,
            .params_len=0,
            .params=NULL
          };
          break;
        default:
          yyerror(&(yylsp[-1]), "Cannot call an expression of non-function type '%s'.", axo_typ_to_str((yyvsp[-1].expression).typ));
          break;
      }
    }else{
      yyerror(&(yylsp[-1]), "Cannot call an invalid rval.");
    }
    // printf("ret_typ: %s\n", axo_typ_to_str(((axo_func*)($$.typ.func_typ))->f_typ.ret_typ));
  }
#line 4347 "axo_gram.tab.c"
    break;

  case 170: /* called_expr: expr ':' "identifier" '('  */
#line 1675 "axo_gram.y"
                      {
    axo_validate_rval(&(yylsp[-3]), (yyvsp[-3].expression));
    (yyval.function_call) = axo_method_call(state, top_scope, &(yyloc), &(yylsp[-3]), &(yylsp[-1]), (yyvsp[-3].expression), (yyvsp[-1].str), rval_now);
  }
#line 4356 "axo_gram.tab.c"
    break;

  case 171: /* func_call_start: called_expr  */
#line 1681 "axo_gram.y"
                              {
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[0].function_call).typ.func_typ);
    if ((yyval.function_call).params_len<fnt->args_len){
      resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
      (yyval.function_call).params[(yyval.function_call).params_len].val = alloc_str(fnt->args_defs[(yyval.function_call).params_len]);
      (yyval.function_call).params_len++;
    }
  }
#line 4369 "axo_gram.tab.c"
    break;

  case 172: /* func_call_start: called_expr expr  */
#line 1689 "axo_gram.y"
                     {
    if (axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))) {
      axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-1].function_call).typ.func_typ);
      if ((yyval.function_call).params_len <= fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[(yyval.function_call).params_len], (yyvsp[0].expression).typ)){
          yyerror(&(yylsp[0]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[(yyval.function_call).params_len]), (yyval.function_call).params_len+1, axo_typ_to_str((yyvsp[0].expression).typ));
        }else{
          resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
          (yyval.function_call).params[(yyval.function_call).params_len++] = (yyvsp[0].expression);
        }
      }else{
        if (fnt->args_types[0].kind != axo_c_arg_list_kind)
          yyerror(&(yylsp[-1]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[-1].function_call).typ));
      }
    }
  }
#line 4390 "axo_gram.tab.c"
    break;

  case 173: /* func_call_start: func_call_start ',' expr  */
#line 1705 "axo_gram.y"
                             {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-2].function_call).typ.func_typ);
    resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
    int i = (yyval.function_call).params_len;
    if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
      if (i < fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[i], (yyvsp[0].expression).typ))
          yyerror(&(yylsp[0]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[i]), i, axo_typ_to_str((yyvsp[0].expression).typ));
      }else{
          yyerror(&(yylsp[0]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[-2].function_call).typ));
      }
    }
    (yyval.function_call).params[i] = (yyvsp[0].expression);
    (yyval.function_call).params_len++;
  }
#line 4411 "axo_gram.tab.c"
    break;

  case 174: /* func_call_start: func_call_start ','  */
#line 1721 "axo_gram.y"
                        {
    (yyval.function_call) = (yyvsp[-1].function_call);
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-1].function_call).typ.func_typ);
    char** defaults = fnt->args_defs;
    resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
    int i = (yyval.function_call).params_len;
    if (i >= fnt->args_len-1 && fnt->args_types[fnt->args_len-1].kind == axo_c_arg_list_kind)
        yyerror(&(yylsp[0]), "Cannot generate a default param for '...'.");
    else if (i >= fnt->args_len)
        yyerror(&(yylsp[0]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[-1].function_call).typ));
    (yyval.function_call).params[i].val = alloc_str(defaults[i]);
    (yyval.function_call).params_len++;
  }
#line 4429 "axo_gram.tab.c"
    break;

  case 175: /* func_call: func_call_start ')'  */
#line 1736 "axo_gram.y"
                                {
    (yyval.function_call)=(yyvsp[-1].function_call);
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-1].function_call).typ.func_typ);
    if (fnt->args_len>(yyval.function_call).params_len){
      // printf("Filling params with args defaults in call '%s'\n", $$.called_val);
      (yyval.function_call).params=(axo_expr*)realloc((yyval.function_call).params, fnt->args_len*sizeof(axo_expr));
      for (int i=(yyvsp[-1].function_call).params_len; i<fnt->args_len-1; i++){ //Fill with defaults up until pre-last arg!
        // printf("arg #%d\n", i);
        // printf("%s\n", fnt->args_defs[i]);
        (yyval.function_call).params[i] = (axo_expr){.typ=fnt->args_types[i], .val=alloc_str(fnt->args_defs[i])};
      }
      (yyval.function_call).params_len=fnt->args_len-1;
      int i = fnt->args_len-1;
      if (fnt->args_types[i].kind != axo_c_arg_list_kind){
        // printf("arg #%d\n", i);
        // printf("%s\n", fnt->args_defs[i]);
        (yyval.function_call).params[i] = (axo_expr){.typ=fnt->args_types[i], .val=alloc_str(fnt->args_defs[i])};
        (yyval.function_call).params_len++;
      }
    }
  }
#line 4455 "axo_gram.tab.c"
    break;

  case 176: /* code_scope_start: '{'  */
#line 1759 "axo_gram.y"
                       {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
#line 4464 "axo_gram.tab.c"
    break;

  case 177: /* code_scope: code_scope_start statements '}'  */
#line 1765 "axo_gram.y"
                                             {
    (yyval.scope) = top_scope;
    scopes->len--;
  }
#line 4473 "axo_gram.tab.c"
    break;

  case 178: /* func_def_name: "identifier"  */
#line 1771 "axo_gram.y"
                     {
    (yyval.function) = (axo_func){
      .name=alloc_str((yyvsp[0].str)),
      .args_names=NULL
    };
  }
#line 4484 "axo_gram.tab.c"
    break;

  case 179: /* func_def_name: "identifier" "::" "identifier"  */
#line 1777 "axo_gram.y"
                   {
    axo_module* mod = axo_get_module(state, (yyvsp[-2].str));
    if (!mod)
      yyerror(&(yylsp[-2]), "Module doesn't exist.");
    else
      (yyval.function) = (axo_func){
        .name=fmtstr("%s%s", mod->prefix, (yyvsp[0].str)),
        .args_names=NULL
      };
  }
#line 4499 "axo_gram.tab.c"
    break;

  case 180: /* func_def_name: val_typ ':' "identifier"  */
#line 1787 "axo_gram.y"
                     {
    axo_typ* subtyp = alloc_one(axo_typ);
    *subtyp = (yyvsp[-2].typ_type);
    axo_typ typ = (axo_typ){
      .kind=axo_ptr_kind,
      .subtyp=subtyp,
      .def=alloc_str("NULL")
    };
    switch((yyvsp[-2].typ_type).kind){
      case axo_simple_kind:
      case axo_struct_kind:
      case axo_enum_kind:
      case axo_none_kind:
        (yyval.function) = (axo_func){
          .name=fmtstr("met_%s_%s", axo_typ_to_str((yyvsp[-2].typ_type)), (yyvsp[0].str)),
          .args_names = (char**)malloc(sizeof(char*)),
          .f_typ = (axo_func_typ){
            .args_len = 1,
            .args_defs = (char**)malloc(sizeof(char*)),
            .args_types = (axo_typ*)malloc(sizeof(axo_typ)),
          }
        };
        (yyval.function).f_typ.args_defs[0] = typ.def;
        (yyval.function).f_typ.args_types[0] = typ;
        (yyval.function).args_names[0] = alloc_str("_axo_self_param");
        break;
      default:
        free(subtyp);
        yyerror(&(yylsp[-2]), "Method are only allowed for structs, enums and primitives, but got %s.", axo_typ_kind_to_str((yyvsp[-2].typ_type).kind));
        break;
    }
  }
#line 4536 "axo_gram.tab.c"
    break;

  case 181: /* func_def_ret_typ: "fn"  */
#line 1821 "axo_gram.y"
                        {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    (yyval.typ_type) = axo_no_typ;
  }
#line 4546 "axo_gram.tab.c"
    break;

  case 182: /* func_def_ret_typ: val_typ "fn"  */
#line 1826 "axo_gram.y"
                 {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    (yyval.typ_type) = (yyvsp[-1].typ_type);
  }
#line 4556 "axo_gram.tab.c"
    break;

  case 183: /* func_def_start: func_def_ret_typ func_def_name '(' func_args ')'  */
#line 1833 "axo_gram.y"
                                                                  {
    int args_len = (yyvsp[-1].function).f_typ.args_len;
    (yyval.function) = (axo_func){
      .name=(yyvsp[-3].function).name
    };
    if ((yyvsp[-3].function).args_names){
      args_len += (yyvsp[-3].function).f_typ.args_len;
      (yyval.function).args_names = (char**)malloc(args_len*sizeof(char*));
      (yyval.function).f_typ = (axo_func_typ){
        .args_len = 0,
        .args_types=(axo_typ*)malloc(args_len*sizeof(axo_typ)),
        .args_defs=(char**)malloc(args_len*sizeof(char*)),
      };
      for (int i=0; i<(yyvsp[-3].function).f_typ.args_len; i++){
        (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[-3].function).args_names[i];
        (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[-3].function).f_typ.args_types[i];
        (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len++] = (yyvsp[-3].function).f_typ.args_defs[i];
      }
      for (int i=0; i<(yyvsp[-1].function).f_typ.args_len; i++){
        (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[-1].function).args_names[i];
        (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[-1].function).f_typ.args_types[i];
        (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len++] = (yyvsp[-1].function).f_typ.args_defs[i];
      }
    //Free func_args
    free((yyvsp[-1].function).f_typ.args_types);
    }else{
      (yyval.function).args_names = (yyvsp[-1].function).args_names;
      (yyval.function).f_typ.args_defs = (yyvsp[-1].function).f_typ.args_defs;
      (yyval.function).f_typ.args_types = (yyvsp[-1].function).f_typ.args_types;
      (yyval.function).f_typ.args_len = args_len;
    }
    (yyval.function).f_typ.ret_typ = (yyvsp[-4].typ_type);
    for (int i = 0; i<(yyval.function).f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=(yyval.function).args_names[i], .typ=(yyval.function).f_typ.args_types[i]});
    //Set the function
    axo_typ typ = (axo_typ){
      .kind=axo_func_kind,
      .func_typ=alloc_one(axo_func_typ)
    };
    *((axo_func_typ*)(typ.func_typ)) = (yyval.function).f_typ;
    axo_set_var(state->global_scope, (axo_var){.name=(yyval.function).name, .typ=typ});
    top_scope->parent_func = axo_get_var(state->global_scope, (yyval.function).name);
  }
#line 4604 "axo_gram.tab.c"
    break;

  case 184: /* struct_literal_start: "struct{"  */
#line 1878 "axo_gram.y"
                                            {
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[0].str));
    if (td==NULL){
      yyerror(&(yylsp[0]), "Structure '%s' undefined before usage.", (yyvsp[0].str));
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&(yylsp[0]), "Type '%s' is not a struture.", (yyvsp[0].str));
    }else{
    int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
    (yyval.struct_val_type) = (axo_struct_val){
      .typ=td->typ,
      .fields=(char**)malloc(total_field_count*sizeof(char*)),
      .fields_count=1 //Yes, that's correct
    };
    for (int i=0;i<total_field_count;i++) (yyval.struct_val_type).fields[i]=NULL;
    }
  }
#line 4625 "axo_gram.tab.c"
    break;

  case 185: /* struct_literal_start: "struct{" expr  */
#line 1894 "axo_gram.y"
                              {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[-1].str));
    if (td==NULL){
      yyerror(&(yylsp[-1]), "Structure type '%s' undefined before usage.", (yyvsp[-1].str));
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&(yylsp[-1]), "Type '%s' is not a struture.", (yyvsp[-1].str));
    }else if (!axo_typ_eq(((axo_struct*)(td->typ.structure))->fields[0].typ, (yyvsp[0].expression).typ)){
      axo_struct* structure = ((axo_struct*)(td->typ.structure));
      yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[0].typ), structure->fields[0].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
    }else{
      int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
      (yyval.struct_val_type) = (axo_struct_val){
        .typ=td->typ,
        .fields=(char**)malloc(((axo_struct*)(td->typ.structure))->fields_len*sizeof(char*)),
        .fields_count=1
      };
      for (int i=1;i<total_field_count;i++) (yyval.struct_val_type).fields[i]=NULL;
      (yyval.struct_val_type).fields[0] = (yyvsp[0].expression).val;
    }
  }
#line 4651 "axo_gram.tab.c"
    break;

  case 186: /* struct_literal_start: "struct{" "identifier" '=' expr  */
#line 1915 "axo_gram.y"
                                       {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[-3].str));
    axo_struct* structure = (axo_struct*)(td->typ.structure);
    if (td==NULL){
      yyerror(&(yylsp[-3]), "Structure type '%s' undefined before usage.", (yyvsp[-3].str));
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&(yylsp[-3]), "Type '%s' is not a structure.", (yyvsp[-3].str));
    }else{
      (yyval.struct_val_type) = (axo_struct_val){
        .typ=td->typ,
        .fields=(char**)malloc(((axo_struct*)(td->typ.structure))->fields_len*sizeof(char*)),
        .fields_count=0
      };
      int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
      for (int i=0;i<total_field_count;i++) (yyval.struct_val_type).fields[i]=NULL;
      int index = -1;
      for (int i=0;i<structure->fields_len; i++){
        if (strcmp(structure->fields[i].name, (yyvsp[-2].str))==0){
          index = i;
          break;
        }
      }
      if (index<0) yyerror(&(yylsp[-2]), "Structure '%s' doesn't have '%s' field.", structure->name, (yyvsp[-2].str));
      else if (!axo_typ_eq(structure->fields[index].typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
      }else{
        (yyval.struct_val_type).fields[index] = (yyvsp[0].expression).val;
      }
    }
  }
#line 4687 "axo_gram.tab.c"
    break;

  case 187: /* struct_literal_start: struct_literal_start ',' expr  */
#line 1946 "axo_gram.y"
                                  {
    (yyval.struct_val_type)=(yyvsp[-2].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      yyerror(&(yylsp[0]), "Too many fields provided to structure '%s'.", structure->name);
    }else if (!axo_typ_eq(structure->fields[(yyval.struct_val_type).fields_count].typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[(yyval.struct_val_type).fields_count].typ), structure->fields[(yyval.struct_val_type).fields_count].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = (yyvsp[0].expression).val;
      (yyval.struct_val_type).fields_count++;
    }else{
      yyerror(&(yylsp[0]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].name);    
    }
  }
#line 4706 "axo_gram.tab.c"
    break;

  case 188: /* struct_literal_start: struct_literal_start ','  */
#line 1960 "axo_gram.y"
                             {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      yyerror(&(yylsp[0]), "Too many fields provided to structure '%s'.", structure->name);
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = ((axo_struct*)((yyvsp[-1].struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].def;
      (yyval.struct_val_type).fields_count++;
    }
  }
#line 4721 "axo_gram.tab.c"
    break;

  case 189: /* struct_literal_start: struct_literal_start ',' "identifier" '=' expr  */
#line 1970 "axo_gram.y"
                                           {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.struct_val_type)=(yyvsp[-4].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    int index = -1;
    for (int i=0;i<structure->fields_len; i++){
      if (strcmp(structure->fields[i].name, (yyvsp[-2].str))==0){
        index = i;
        break;
      }
    }
    if (index<0) yyerror(&(yylsp[-2]), "Structure '%s' doesn't have '%s' field.", structure->name, (yyvsp[-2].str));
    else if (!axo_typ_eq(structure->fields[index].typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
    }else if ((yyval.struct_val_type).fields[index]==NULL){
      (yyval.struct_val_type).fields[index] = (yyvsp[0].expression).val;
    }else{
      yyerror(&(yylsp[-2]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[index].name);    
    }
  }
#line 4746 "axo_gram.tab.c"
    break;

  case 190: /* struct_literal: struct_literal_start '}'  */
#line 1992 "axo_gram.y"
                                          {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = ((axo_struct*)(yyval.struct_val_type).typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if((yyval.struct_val_type).fields[i] == NULL) (yyval.struct_val_type).fields[i] = structure->fields[i].def;
    }
  }
#line 4758 "axo_gram.tab.c"
    break;

  case 191: /* func_def: func_def_start code_scope  */
#line 2001 "axo_gram.y"
                                     {
    axo_var* fn_var = axo_get_var(state->global_scope, (yyvsp[-1].function).name);
    if (fn_var){
      axo_func_typ* fnt = (axo_func_typ*)(fn_var->typ.func_typ);
      if (fnt->ret_typ.kind == axo_no_kind)
        fnt->ret_typ = axo_none_typ;
      (yyval.function) = (axo_func){
        .name = (yyvsp[-1].function).name,
        .args_names = (yyvsp[-1].function).args_names,
        .f_typ = *fnt,
        .body = (yyvsp[0].scope)
      };
    }else{
      yyerror(NULL, "This should never happen.");
    }
  }
#line 4779 "axo_gram.tab.c"
    break;

  case 192: /* func_arg: val_typ "identifier"  */
#line 2019 "axo_gram.y"
                        {
    if (axo_none_check((yyvsp[-1].typ_type)))
      yyerror(&(yylsp[-1]), "Cannot declare a none value.");
    (yyval.function_argument).name = alloc_str((yyvsp[0].str));
    (yyval.function_argument).typ = (yyvsp[-1].typ_type);
    (yyval.function_argument).def = alloc_str(axo_get_typ_default((yyvsp[-1].typ_type)));
  }
#line 4791 "axo_gram.tab.c"
    break;

  case 193: /* func_arg: "identifier" '=' expr  */
#line 2026 "axo_gram.y"
                  {
    if (axo_none_check((yyvsp[0].expression).typ))
      yyerror(&(yylsp[0]), "Cannot declare a none variable.");
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[0].expression).typ;
    (yyval.function_argument).def = alloc_str((yyvsp[0].expression).val);
  }
#line 4803 "axo_gram.tab.c"
    break;

  case 194: /* func_arg: val_typ "identifier" '=' expr  */
#line 2033 "axo_gram.y"
                          {
    if (axo_none_check((yyvsp[-3].typ_type)))
      yyerror(&(yylsp[-3]), "Cannot declare a none variable.");
    if (!axo_typ_eq((yyvsp[-3].typ_type), (yyvsp[0].expression).typ)){
      char* expected_type_str = alloc_str(axo_typ_to_str((yyvsp[-3].typ_type)));
      yyerror(&(yylsp[0]), "Default value of type '%s' doesn't match expected type '%s'.", axo_typ_to_str((yyvsp[0].expression).typ), expected_type_str);
      free(expected_type_str);
    }
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[-3].typ_type);
    (yyval.function_argument).def = alloc_str((yyvsp[0].expression).val);
  }
#line 4820 "axo_gram.tab.c"
    break;

  case 195: /* func_args: %empty  */
#line 2047 "axo_gram.y"
                            {
    (yyval.function).args_names = NULL;
    (yyval.function).f_typ.args_defs = NULL;
    (yyval.function).f_typ.args_types = NULL;
    (yyval.function).f_typ.args_len = 0;
  }
#line 4831 "axo_gram.tab.c"
    break;

  case 196: /* func_args: func_arg  */
#line 2053 "axo_gram.y"
             {
    (yyval.function).args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.function).args_names[0] = (yyvsp[0].function_argument).name;
    (yyval.function).f_typ.args_defs[0] = (yyvsp[0].function_argument).def;
    (yyval.function).f_typ.args_types[0] = (yyvsp[0].function_argument).typ;
    (yyval.function).f_typ.args_len = 1;
  }
#line 4845 "axo_gram.tab.c"
    break;

  case 197: /* func_args: func_args ',' func_arg  */
#line 2062 "axo_gram.y"
                           {
    (yyval.function) = (yyvsp[-2].function);
    resize_dyn_arr_if_needed(char*, (yyval.function).args_names, (yyval.function).f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, (yyval.function).f_typ.args_defs, (yyval.function).f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(axo_typ, (yyval.function).f_typ.args_types, (yyval.function).f_typ.args_len, axo_func_args_cap);
    (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[0].function_argument).name;
    (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len] = (yyvsp[0].function_argument).def;
    (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[0].function_argument).typ;
    (yyval.function).f_typ.args_len++;
  }
#line 4860 "axo_gram.tab.c"
    break;

  case 198: /* enum_names: "identifier"  */
#line 2074 "axo_gram.y"
                  {
    (yyval.enum_type).names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    (yyval.enum_type).names[0] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len = 1;
  }
#line 4870 "axo_gram.tab.c"
    break;

  case 199: /* enum_names: enum_names ',' "identifier"  */
#line 2079 "axo_gram.y"
                        {
    (yyval.enum_type) = (yyvsp[-2].enum_type);
    if ((yyval.enum_type).len % axo_enum_names_cap == 0)
    (yyval.enum_type).names = (char**)realloc((yyval.enum_type).names, ((yyval.enum_type).len+axo_enum_names_cap)*sizeof(char*));
    (yyval.enum_type).names[(yyval.enum_type).len] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len++;
  }
#line 4882 "axo_gram.tab.c"
    break;


#line 4886 "axo_gram.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 2088 "axo_gram.y"


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

void yyerror(YYLTYPE* loc, const char * fmt, ...){
  if (prog_return==0)
    axo_err_printf("Click an error to learn more.\n");
  prog_return = 1;
  axo_raise_error;
  va_list args;
  if (loc==NULL){
    axo_err_printf(axo_red_fg "Error: ");
    va_start(args, fmt);
    axo_err_vprintf(fmt, args);
    va_end(args);
    printf(axo_reset_style"\n");
  }else{
    va_start(args, fmt);
    char* msg = NULL;
    if (vasprintf(&msg, fmt, args) < 0)
      axo_err_printf("Couldn't use vsprintf at %s:%d", __FILE__, __LINE__);
    #ifdef __EMSCRIPTEN__
      axo_err_printf("error %d:%d: %s\n", loc->first_line, loc->first_column, msg);
      free(msg);
      return;
    #endif
    char* err_msg = axo_error_with_loc(state, loc, msg);
    va_end(args);
    axo_err_printf("%s\n", err_msg);
    free(err_msg);
    free(msg);
  }
  // exit(1);
}

int compile(int argc, char** argv) {
  //Seed the pseudo random number generator
  srand(time(NULL));
  //Start timing the event
  clock_t start, end;
  double cpu_time_used;
  if (test_playground) return playground();
  
  //Get the root path (the path where the axo compiler lays)
  char* root_p = axo_get_parent_dir(axo_get_exec_path((char[512]){}, 512));
  // printf("Root: %s\n", root_p);
  //Initialize state
  state = axo_new_state(root_p);
  //Save the original working dir
  state->orig_cwd = axo_cwd((char[axo_max_path_len]){}, axo_max_path_len);
  // printf("orig_cwd: %s\n", orig_cwd);
  
  //Load config from axo.config
  // axo_bytes_to_file("axo.config", (char*)(&(state->config)), sizeof(axo_compiler_config));
  axo_load_cfg(state);
  bool measure_time = state->config.timer;
  if (measure_time){
    start = clock();
  }
  if (argc <= 1){
    yyerror(NULL, "No input.");
    return 1;
  }
  char* cmd = argv[1];
  if (strcmp(cmd, "info")==0){
      prog_return = axo_info_cmd(state, argc, argv);
  }else if (strcmp(cmd, "set")==0){
    prog_return = axo_set_cmd(state, argc, argv);
  }else{
    axo_handle_args(state, argc, argv, 1);
    axo_printf = state->silenced ?  axo_no_printf : printf;
    if (state->entry_file || state->input_str){
      if (state->input_str && state->entry_file){
        yyerror(NULL, "Cannot take input from string and file.");
        return 1;
      }else if (state->entry_file){
        char* input_file_path = state->entry_file;
        state->output_c_file = state->output_c_file ? state->output_c_file : axo_swap_file_extension(input_file_path, ".c");
        state->output_file = state->output_file ? state->output_file : axo_swap_file_extension(input_file_path, AXO_BIN_EXT);
      }else if (state->input_str){
        axo_new_string_source(state, state->input_str);
        state->output_c_file = state->output_c_file ? state->output_c_file : alloc_str("a.c");
        state->output_file = state->output_file ? state->output_file : alloc_str("a"AXO_BIN_EXT);
      }else{
        yyerror(NULL, "No input.");
        return 1;
      }
      state->entry_point = state->entry_point ? state->entry_point : alloc_str("axo__main");
      //Scopes table
      scopes = alloc_one(axo_scopes);
      scopes->scopes = NULL;
      scopes->len = 0;
      axo_push_scope(scopes, state->global_scope);
      if (state->entry_file)
        axo_new_source(state, state->entry_file);
      else
        state->entry_file = alloc_str("./in.axo");
    }else{
      yyerror(NULL, "No code provided.\nUsage: axo <source> |options|");
      return 1;
    }
    //Use the core module
    axo_add_decl(state, axo_use_module(state, NULL, "core"));
    state->in_core = true;
    //Set entry point
    //empty_str should just be null to prevent leaks?
    axo_add_decl(state, (axo_decl){
      .kind=axo_other_decl_kind,
      .val=empty_str
    });
    //Parse
    yyparse();
    // axo_printf("Parsing done.\n");
    // char* cde = axo_get_code(state);
    //Check if the entry point is present
    axo_var* var = axo_get_var(top_scope, (strcmp("axo__main", state->entry_point) == 0) ? "main" : state->entry_point);
    if (var == NULL){
      yyerror(NULL, "Entry point function '%s' doesn't exist.", state->entry_point);
    }else{
      axo_func_typ f_typ = *((axo_func_typ*)(var->typ.func_typ));
      if (f_typ.args_len == 0){
        state->decls[1].val=fmtstr("#define AXO_DEFINE_ENTRY_POINT int %s();\n#define AXO_MAIN_ENTRY_POINT %s\n#define AXO_MAIN_ENTRY_NO_ARGS 1\n", state->entry_point, state->entry_point);
      }else{
        axo_typ expected_typ = (axo_typ){
          .kind=axo_arr_kind,
          .arr=&(axo_arr_typ){
            .dim_count=1,
            .subtyp=(axo_typ){
              .kind=axo_arr_kind,
              .arr=&(axo_arr_typ){
                .dim_count=1,
                .subtyp=(axo_byte_typ(state))
              }
            }
          }
        };
        if (f_typ.args_len > 1 || !axo_typ_eq(f_typ.args_types[0], expected_typ)) {
          yyerror(NULL, "Entry point has to be of type (int fn) or (int fn [][]byte), but is of type '%s'.", axo_typ_to_str(var->typ));
        }else{
          state->decls[1].val=fmtstr("#define AXO_DEFINE_ENTRY_POINT int %s(axo__arr args);\n#define AXO_MAIN_ENTRY_POINT %s", state->entry_point, state->entry_point);
        }
      }
    }
    //Handle produced C code
    //change the working dir back to original
    axo_chdir(state->orig_cwd);
    if (!prog_return){
      #ifdef __EMSCRIPTEN__
        return 0;
      #else
        char* code = axo_get_code(state);
        overwrite_file_with_string(state->output_c_file, code);
        free(code);
        //Compile program
        char* compiler_cmd;
        int res = 1;
        switch(state->config.cc){
          case axo_gcc_cc_kind:
            compiler_cmd = fmtstr("gcc -o %s %s", state->output_file, state->output_c_file, state->output_c_file);
            for (int i=0; i<state->extra_c_sources_len; i++){
              strapnd(&compiler_cmd, " ");
              strapnd(&compiler_cmd, state->extra_c_sources[i]);
            }
            for (int i=0; i<state->cc_flags_len; i++){
              strapnd(&compiler_cmd, " ");
              strapnd(&compiler_cmd, state->cc_flags[i]);
            }
            printf("Compiling command:\n%s\n", compiler_cmd);
            res = system(compiler_cmd) >> 8;
            break;
          default:
            fprintf(stderr, "This C compiler is not yet supported!\n");
            break;
        }
        if (res != 0)
          printf("Error while compiling the output C file! D:\n");
        prog_return = prog_return||res;
        if (prog_return) return prog_return;
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
      #endif
    }
    // printf("\n\n%s\n", axo_axelotl_str);
  }
  //Time the action if the according option was and is true
  if (state->config.timer && measure_time && !(state->silenced)){
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    axo_lolprintf(state->config.color_support, rand(), "Took: %fs\n", cpu_time_used);
  }
  // printf("Returning: %d\n", prog_return);
  return prog_return;
}

int main(int argc, char** argv){
  #ifdef __EMSCRIPTEN__
    return 0;
  #else
    int ret = compile(argc, argv);
    axo_free_state(state);
    return ret;
  #endif
}

char* axo_compile_to_c(int argc, char* input){
  char** argv = (char**)malloc(3*sizeof(char*));
  argv[0] = alloc_str(".");
  argv[1] = alloc_str("-i");
  argv[2] = alloc_str(input);
  compile(argc, argv);
  return axo_get_code(state);
}

