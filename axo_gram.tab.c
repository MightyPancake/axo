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

#line 113 "axo_gram.tab.c"

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
  YYSYMBOL_C_REGISTER = 12,                /* "#register"  */
  YYSYMBOL_FN_KWRD = 13,                   /* "fn"  */
  YYSYMBOL_WHILE_KWRD = 14,                /* "while"  */
  YYSYMBOL_FOR_KWRD = 15,                  /* "for"  */
  YYSYMBOL_EACH_KWRD = 16,                 /* "each"  */
  YYSYMBOL_IN_KWRD = 17,                   /* "in"  */
  YYSYMBOL_IF_KWRD = 18,                   /* "if"  */
  YYSYMBOL_ELSE_KWRD = 19,                 /* "else"  */
  YYSYMBOL_EQ_OP = 20,                     /* "=="  */
  YYSYMBOL_INEQ_OP = 21,                   /* "!="  */
  YYSYMBOL_EQ_SMLR_OP = 22,                /* ">="  */
  YYSYMBOL_EQ_GRTR_OP = 23,                /* "<="  */
  YYSYMBOL_BIT_OR_OP = 24,                 /* "||"  */
  YYSYMBOL_BIT_AND_OP = 25,                /* "&&"  */
  YYSYMBOL_LOGICAL_OR_OP = 26,             /* "or"  */
  YYSYMBOL_LOGICAL_AND_OP = 27,            /* "and"  */
  YYSYMBOL_LEFT_SHIFT_OP = 28,             /* "<<"  */
  YYSYMBOL_RIGHT_SHIFT_OP = 29,            /* ">>"  */
  YYSYMBOL_TILL_KWRD = 30,                 /* "till"  */
  YYSYMBOL_INCR_OP = 31,                   /* "++"  */
  YYSYMBOL_DECR_OP = 32,                   /* "--"  */
  YYSYMBOL_ENUM_KWRD = 33,                 /* "enum"  */
  YYSYMBOL_STRUCT_KWRD = 34,               /* "struct"  */
  YYSYMBOL_STRUCT_LITERAL_START = 35,      /* "struct{"  */
  YYSYMBOL_DOT_FIELD = 36,                 /* ".field"  */
  YYSYMBOL_ARROW_OP = 37,                  /* "->"  */
  YYSYMBOL_IS_KWRD = 38,                   /* "is"  */
  YYSYMBOL_IDENTIFIER_PREC = 39,           /* IDENTIFIER_PREC  */
  YYSYMBOL_40_ = 40,                       /* '$'  */
  YYSYMBOL_EXPR_AS_STATEMENT = 41,         /* EXPR_AS_STATEMENT  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '?'  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '/'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_LOOP_PREC = 51,                 /* LOOP_PREC  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_UMINUS = 55,                    /* UMINUS  */
  YYSYMBOL_56_ = 56,                       /* '@'  */
  YYSYMBOL_57_ = 57,                       /* '^'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_STRUCT_LIT_NAMED_FIELD = 59,    /* STRUCT_LIT_NAMED_FIELD  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_62_ = 62,                       /* ']'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_index_access = 69,              /* index_access  */
  YYSYMBOL_identifier = 70,                /* identifier  */
  YYSYMBOL_incr_decr_op = 71,              /* incr_decr_op  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_stat_arr_literal_start = 73,    /* stat_arr_literal_start  */
  YYSYMBOL_stat_arr_literal = 74,          /* stat_arr_literal  */
  YYSYMBOL_arr_literal = 75,               /* arr_literal  */
  YYSYMBOL_empty_arr_dims = 76,            /* empty_arr_dims  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_matching_statement = 78,        /* matching_statement  */
  YYSYMBOL_if_condition = 79,              /* if_condition  */
  YYSYMBOL_matching_if_statement = 80,     /* matching_if_statement  */
  YYSYMBOL_non_matching_statement = 81,    /* non_matching_statement  */
  YYSYMBOL_non_matching_if_statement = 82, /* non_matching_if_statement  */
  YYSYMBOL_till_loop_start = 83,           /* till_loop_start  */
  YYSYMBOL_while_loop_base = 84,           /* while_loop_base  */
  YYSYMBOL_matching_while = 85,            /* matching_while  */
  YYSYMBOL_non_matching_while = 86,        /* non_matching_while  */
  YYSYMBOL_for_loop_start = 87,            /* for_loop_start  */
  YYSYMBOL_for_loop_init = 88,             /* for_loop_init  */
  YYSYMBOL_for_loop_base = 89,             /* for_loop_base  */
  YYSYMBOL_matching_for_loop = 90,         /* matching_for_loop  */
  YYSYMBOL_non_matching_for_loop = 91,     /* non_matching_for_loop  */
  YYSYMBOL_each_iter_dims = 92,            /* each_iter_dims  */
  YYSYMBOL_each_loop_start = 93,           /* each_loop_start  */
  YYSYMBOL_each_loop_base = 94,            /* each_loop_base  */
  YYSYMBOL_matching_each_loop = 95,        /* matching_each_loop  */
  YYSYMBOL_non_matching_each_loop = 96,    /* non_matching_each_loop  */
  YYSYMBOL_assign_op = 97,                 /* assign_op  */
  YYSYMBOL_assignment = 98,                /* assignment  */
  YYSYMBOL_arr_multidim_typ = 99,          /* arr_multidim_typ  */
  YYSYMBOL_arr_typ = 100,                  /* arr_typ  */
  YYSYMBOL_func_typ_start = 101,           /* func_typ_start  */
  YYSYMBOL_func_typ_args = 102,            /* func_typ_args  */
  YYSYMBOL_func_typ = 103,                 /* func_typ  */
  YYSYMBOL_val_typ = 104,                  /* val_typ  */
  YYSYMBOL_c_typ = 105,                    /* c_typ  */
  YYSYMBOL_c_typ_list = 106,               /* c_typ_list  */
  YYSYMBOL_func_call_start = 107,          /* func_call_start  */
  YYSYMBOL_func_call = 108,                /* func_call  */
  YYSYMBOL_code_scope_start = 109,         /* code_scope_start  */
  YYSYMBOL_code_scope = 110,               /* code_scope  */
  YYSYMBOL_func_def_start = 111,           /* func_def_start  */
  YYSYMBOL_struct_def = 112,               /* struct_def  */
  YYSYMBOL_struct_literal_start = 113,     /* struct_literal_start  */
  YYSYMBOL_struct_literal = 114,           /* struct_literal  */
  YYSYMBOL_func_def = 115,                 /* func_def  */
  YYSYMBOL_func_arg = 116,                 /* func_arg  */
  YYSYMBOL_func_args = 117,                /* func_args  */
  YYSYMBOL_enum_names = 118                /* enum_names  */
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
#define YYLAST   1131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,     2,     2,     2,    40,    50,     2,     2,
      53,    60,    48,    46,    63,    47,    52,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      44,    42,    45,    43,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    62,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    61,    65,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    41,    51,    55,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   151,   154,   157,   176,   210,   237,   238,
     241,   249,   254,   271,   275,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   299,   308,   309,   345,
     360,   361,   368,   375,   382,   389,   396,   403,   412,   421,
     430,   439,   462,   488,   566,   567,   568,   599,   614,   629,
     640,   650,   673,   688,   717,   725,   733,   739,   739,   741,
     747,   752,   764,   767,   786,   793,   800,   801,   802,   803,
     806,   812,   817,   818,   819,   820,   823,   826,   831,   841,
     848,   857,   866,   871,   876,   887,   898,   906,   915,   924,
     934,   938,   943,   949,   963,   977,   991,  1007,  1015,  1023,
    1028,  1054,  1064,  1070,  1081,  1087,  1098,  1111,  1120,  1131,
    1132,  1135,  1142,  1147,  1148,  1151,  1155,  1160,  1166,  1170,
    1175,  1186,  1206,  1209,  1236,  1252,  1267,  1284,  1290,  1298,
    1309,  1323,  1336,  1352,  1373,  1403,  1417,  1427,  1448,  1457,
    1472,  1477,  1482,  1489,  1495,  1504,  1516,  1521
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
  "\"#register\"", "\"fn\"", "\"while\"", "\"for\"", "\"each\"", "\"in\"",
  "\"if\"", "\"else\"", "\"==\"", "\"!=\"", "\">=\"", "\"<=\"", "\"||\"",
  "\"&&\"", "\"or\"", "\"and\"", "\"<<\"", "\">>\"", "\"till\"", "\"++\"",
  "\"--\"", "\"enum\"", "\"struct\"", "\"struct{\"", "\".field\"",
  "\"->\"", "\"is\"", "IDENTIFIER_PREC", "'$'", "EXPR_AS_STATEMENT", "'='",
  "'?'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "LOOP_PREC",
  "'.'", "'('", "':'", "UMINUS", "'@'", "'^'", "'['",
  "STRUCT_LIT_NAMED_FIELD", "')'", "'|'", "']'", "','", "'{'", "'}'",
  "$accept", "declarations", "statements", "index_access", "identifier",
  "incr_decr_op", "expr", "stat_arr_literal_start", "stat_arr_literal",
  "arr_literal", "empty_arr_dims", "statement", "matching_statement",
  "if_condition", "matching_if_statement", "non_matching_statement",
  "non_matching_if_statement", "till_loop_start", "while_loop_base",
  "matching_while", "non_matching_while", "for_loop_start",
  "for_loop_init", "for_loop_base", "matching_for_loop",
  "non_matching_for_loop", "each_iter_dims", "each_loop_start",
  "each_loop_base", "matching_each_loop", "non_matching_each_loop",
  "assign_op", "assignment", "arr_multidim_typ", "arr_typ",
  "func_typ_start", "func_typ_args", "func_typ", "val_typ", "c_typ",
  "c_typ_list", "func_call_start", "func_call", "code_scope_start",
  "code_scope", "func_def_start", "struct_def", "struct_literal_start",
  "struct_literal", "func_def", "func_arg", "func_args", "enum_names", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -104,   135,  -104,  -104,    20,    47,    32,    49,    38,  -104,
    -104,  -104,     7,     0,    26,    18,    54,   -54,   -11,  -104,
      -4,   -18,  -104,    83,    56,    58,  -104,  -104,  -104,    65,
      70,  -104,    62,  -104,  -104,   115,  -104,  -104,    54,  -104,
      54,  -104,  -104,  -104,    54,    77,   126,    62,   182,  -104,
      20,    75,   132,  -104,   -17,  -104,  -104,  -104,  -104,    62,
    -104,   -16,     1,  -104,  -104,  -104,  -104,   326,  -104,  -104,
      92,   136,   326,   100,   346,   326,    96,   326,   326,   326,
     382,  -104,  -104,  -104,   729,    29,  -104,  -104,    52,  -104,
    -104,   245,  -104,  -104,  -104,  -104,   245,  -104,  -104,   245,
      94,   245,  -104,  -104,    -1,   245,  -104,  -104,  -104,     2,
    -104,  -104,    25,  -104,   110,     6,   326,    98,  -104,    62,
      10,  -104,   154,  -104,   998,   326,  -104,   998,   155,   122,
     768,   768,   162,     5,   565,     5,    60,   448,   326,   326,
     326,   326,   326,   326,   326,   326,  -104,  -104,  -104,    54,
    -104,   326,   326,   326,   326,   326,   326,   326,   117,   326,
     166,  -104,   326,    72,   326,  -104,   326,   170,    71,  -104,
     157,  -104,  -104,  -104,   326,  -104,  -104,   319,    12,    81,
    -104,  -104,  -104,   326,   402,  -104,  -104,    20,   768,   326,
    -104,  -104,  -104,   606,   137,   326,  -104,   326,  -104,   312,
    1025,  1025,   959,   959,   885,   924,  1049,  1049,  -104,   959,
     959,  1073,  1073,  1034,  1034,  1034,    54,   768,   124,   768,
     326,  -104,   768,   768,  -104,   252,  -104,   245,   487,   326,
     768,   326,   120,   326,    15,   768,   138,   768,   110,   768,
    -104,   326,   768,   807,  -104,   768,   121,  -104,   768,   526,
    -104,  -104,   245,   768,   846,    89,   768,   326,   176,   326,
     647,   409,  -104,   326,  -104,   167,   846,   175,   768,  -104,
     124,   688,   768,   326,   326,  -104,   846,   846
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,     0,     0,     0,     0,     0,     7,
       3,   115,     0,     0,   111,     0,     0,     0,     0,   114,
       0,     0,   113,     0,     0,     0,   127,     8,   139,     0,
       0,   116,   143,   111,   106,     0,   112,   101,     0,   102,
       0,   109,   107,   110,     0,     0,     0,   143,     0,   117,
     118,   111,     0,   144,     0,   105,   103,   104,   108,   143,
     146,     0,     0,    15,    16,    17,    12,     0,    65,    64,
       0,    82,     0,     0,   132,     0,     0,     0,     0,     0,
       0,   128,    28,    45,    59,     0,    52,    44,     0,     9,
      57,     0,    66,    58,    72,    85,     0,    68,    74,     0,
       0,     0,    67,    73,     0,     0,    69,    75,    27,     0,
      30,    62,     0,    41,   119,     0,     0,   140,   129,     0,
       0,     6,     0,   131,    61,     0,    92,    70,     0,    12,
     133,    60,     0,    20,     0,    25,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    43,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,    26,     0,     0,     0,    51,     0,     0,     0,    76,
      57,    80,    81,    83,     0,    86,    87,     0,     0,     0,
      97,    98,   126,   125,   136,   138,     5,     0,   141,     0,
     145,   130,   147,     0,     0,     0,    54,     0,    24,     0,
      33,    34,    35,    36,    37,    38,    40,    39,    63,    31,
      32,    18,    19,    21,    22,    23,     0,   123,     0,    10,
       0,    42,   100,    49,    56,     0,    53,     0,     0,     0,
      88,     0,     0,    91,     0,   124,    12,   135,   120,   142,
      79,     0,   134,     0,    50,    47,     0,   122,    11,     0,
      71,    77,     0,    89,    93,     0,    90,     0,     0,     0,
       0,     0,    46,     0,    84,     0,    96,     0,   137,    78,
      12,     0,    48,     0,     0,    29,    94,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -104,  -103,  -104,   -58,  -104,  -104,  -104,
    -104,   -87,   -78,  -104,  -104,   -71,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   -39,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    -5,   -47,
    -104,  -104,  -104,  -104,   186,  -104,  -104,  -104,  -104,  -104,
      76,   -19,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    48,   163,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   179,   104,   105,   106,
     107,   164,   108,    18,    19,    20,    21,    22,    52,    13,
     115,   109,   110,    27,   111,     8,     9,   112,   113,    10,
      53,    54,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   178,    33,   114,   169,    66,    30,    37,    38,   124,
      35,    36,   173,   170,   127,    42,   130,   131,   171,   133,
     134,   135,   137,   175,    33,   172,    11,   180,    62,   231,
     176,    34,   257,    56,   181,    57,   146,   147,    24,    58,
     120,   148,    43,   118,   121,    44,   119,   122,    31,    15,
      39,    40,    16,    14,    17,    25,    41,   177,   188,    29,
      33,   123,   182,   162,   119,   183,   186,   193,    51,   187,
     191,    15,    12,   119,    16,   232,    17,    33,   258,    32,
     200,   201,   202,   203,   204,   205,   206,   207,   184,    45,
     185,   165,   166,   209,   210,   211,   212,   213,   214,   215,
      15,   217,    26,    16,   219,    17,   222,    15,   223,    46,
      16,    47,    17,   167,   168,    15,   228,    49,    16,   230,
      17,   -55,   -55,    50,    15,   235,   237,    16,    55,   225,
      59,   239,    60,   220,   221,     2,   116,   242,   117,   243,
     238,   245,   233,   234,   208,   125,     3,     4,     5,   250,
     233,   265,   126,   128,   132,   267,   251,   174,    31,   189,
     192,   194,   248,   226,   195,   264,   196,   249,     6,     7,
     216,   253,   218,   254,   224,   256,   227,   247,   177,   241,
     259,   262,    66,   260,   273,    63,    64,    65,    66,    67,
      68,    69,   274,   255,    28,   190,    70,    71,     0,   266,
      72,   268,     0,   271,     0,   272,     0,     0,     0,     0,
       0,   246,    73,     0,     0,   276,   277,    74,     0,     0,
       0,     0,    75,     0,     0,    76,     0,     0,     0,    77,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
      80,     0,     0,     0,     0,     0,    26,    81,    63,    64,
      65,    66,    67,    68,    69,    63,    64,    65,    66,    70,
      71,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
      74,     0,     0,     0,     0,    75,     0,    74,    76,     0,
       0,     0,    77,     0,     0,    76,     0,     0,    78,    77,
       0,    79,     0,    80,     0,    78,     0,     0,    79,    26,
      80,     0,     0,    37,    38,    63,    64,    65,    66,     0,
       0,     0,    63,    64,    65,    66,     0,     0,     0,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    63,
      64,    65,   129,     0,    74,    76,     0,     0,     0,    77,
       0,    74,    76,     0,     0,    78,    77,     0,    79,    76,
      80,     0,    78,    77,   244,    79,     0,    80,     0,    78,
     229,    74,    79,     0,    80,    63,   136,    65,    66,    76,
       0,     0,     0,    77,     0,     0,     0,     0,     0,    78,
       0,     0,    79,     0,    80,    63,    64,    65,   236,     0,
       0,     0,    63,    64,    65,   270,     0,    74,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,    77,
       0,     0,     0,     0,     0,    78,     0,    74,    79,     0,
      80,     0,     0,     0,    74,    76,     0,     0,     0,    77,
       0,     0,    76,     0,     0,    78,    77,     0,    79,     0,
      80,     0,    78,     0,     0,    79,     0,    80,   138,   139,
     140,   141,     0,     0,   142,   143,   144,   145,     0,   146,
     147,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     150,     0,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,     0,     0,   161,   162,   138,   139,   140,
     141,   199,     0,   142,   143,   144,   145,     0,   146,   147,
       0,     0,     0,   148,     0,     0,     0,     0,     0,   150,
       0,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,     0,     0,   161,   162,   138,   139,   140,   141,
     252,     0,   142,   143,   144,   145,     0,   146,   147,     0,
       0,     0,   148,     0,     0,     0,     0,     0,   150,     0,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
     160,     0,     0,   161,   162,   138,   139,   140,   141,   263,
       0,   142,   143,   144,   145,     0,   146,   147,     0,     0,
       0,   148,     0,     0,     0,     0,     0,   150,   197,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
       0,     0,   161,   162,     0,   198,   138,   139,   140,   141,
       0,     0,   142,   143,   144,   145,     0,   146,   147,     0,
       0,     0,   148,     0,     0,     0,     0,     0,   150,     0,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
     160,     0,     0,   161,   162,     0,   240,   138,   139,   140,
     141,     0,     0,   142,   143,   144,   145,     0,   146,   147,
       0,     0,     0,   148,     0,     0,     0,     0,     0,   150,
       0,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,     0,     0,   161,   162,     0,   269,   138,   139,
     140,   141,     0,     0,   142,   143,   144,   145,     0,   146,
     147,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     150,     0,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,     0,     0,   161,   162,     0,   275,   138,
     139,   140,   141,     0,     0,   142,   143,   144,   145,     0,
     146,   147,     0,     0,     0,   148,     0,   149,     0,     0,
       0,   150,     0,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,     0,     0,   161,   162,   138,   139,
     140,   141,     0,     0,   142,   143,   144,   145,     0,   146,
     147,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     150,     0,   151,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,     0,     0,   161,   162,   138,   139,   140,
     141,     0,     0,   142,   143,   144,   145,     0,   146,   147,
       0,     0,     0,   148,     0,     0,     0,     0,     0,   150,
       0,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   261,     0,     0,   161,   162,   138,   139,   140,   141,
       0,     0,   142,   143,   144,   145,     0,   146,   147,     0,
       0,     0,   148,     0,     0,     0,     0,     0,   150,     0,
     151,   152,   153,     0,   155,   156,   157,     0,   158,   159,
     160,     0,     0,   161,   162,   138,   139,   140,   141,     0,
       0,     0,   143,   144,   145,     0,   146,   147,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
       0,     0,   161,   162,   138,   139,   140,   141,     0,     0,
       0,     0,   144,   145,     0,   146,   147,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,   157,     0,   158,   159,   160,   138,
     139,   161,   162,     0,     0,     0,     0,   144,   145,     0,
     146,   147,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
       0,   158,   159,   160,     0,     0,   161,   162,   138,   139,
     140,   141,     0,     0,   142,   143,   144,   145,     0,   146,
     147,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     150,     0,   151,   152,   153,     0,   155,   156,   157,     0,
     158,     0,   160,   144,   145,   161,   146,   147,     0,     0,
       0,   148,     0,     0,     0,   146,   147,     0,     0,     0,
     148,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     146,   147,   161,   162,     0,   148,   158,   159,   160,     0,
       0,   161,   162,     0,     0,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   146,   147,   161,   162,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,     0,   158,   159,   160,     0,     0,
     161,   162
};

static const yytype_int16 yycheck[] =
{
       5,   104,     6,    50,    91,     6,     6,    61,    62,    67,
      15,    16,    99,    91,    72,    20,    74,    75,    96,    77,
      78,    79,    80,   101,     6,    96,     6,   105,    47,    17,
     101,    13,    17,    38,   105,    40,    31,    32,     6,    44,
      59,    36,    60,    60,    60,    63,    63,    63,    48,    53,
      61,    62,    56,     6,    58,     6,    60,    58,   116,    52,
       6,    60,    60,    58,    63,    63,    60,   125,     6,    63,
      60,    53,    52,    63,    56,    63,    58,     6,    63,    53,
     138,   139,   140,   141,   142,   143,   144,   145,    63,     6,
      65,    62,    63,   151,   152,   153,   154,   155,   156,   157,
      53,   159,    64,    56,   162,    58,   164,    53,   166,    53,
      56,    53,    58,    61,    62,    53,   174,    52,    56,   177,
      58,    61,    62,    53,    53,   183,   184,    56,    13,    58,
      53,   189,     6,    61,    62,     0,    61,   195,     6,   197,
     187,   199,    61,    62,   149,    53,    11,    12,    13,   227,
      61,    62,    16,    53,    58,   258,   227,    63,    48,    61,
       6,     6,   220,   168,    42,   252,     4,   225,    33,    34,
      53,   229,     6,   231,     4,   233,    19,    53,    58,    42,
      42,    60,     6,   241,    17,     3,     4,     5,     6,     7,
       8,     9,    17,   232,     8,   119,    14,    15,    -1,   257,
      18,   259,    -1,   261,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   216,    30,    -1,    -1,   273,   274,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    65,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,    35,    43,    -1,
      -1,    -1,    47,    -1,    -1,    43,    -1,    -1,    53,    47,
      -1,    56,    -1,    58,    -1,    53,    -1,    -1,    56,    64,
      58,    -1,    -1,    61,    62,     3,     4,     5,     6,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,     3,
       4,     5,     6,    -1,    35,    43,    -1,    -1,    -1,    47,
      -1,    35,    43,    -1,    -1,    53,    47,    -1,    56,    43,
      58,    -1,    53,    47,    62,    56,    -1,    58,    -1,    53,
      61,    35,    56,    -1,    58,     3,     4,     5,     6,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    58,     3,     4,     5,     6,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    35,    56,    -1,
      58,    -1,    -1,    -1,    35,    43,    -1,    -1,    -1,    47,
      -1,    -1,    43,    -1,    -1,    53,    47,    -1,    56,    -1,
      58,    -1,    53,    -1,    -1,    56,    -1,    58,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    20,    21,    22,
      23,    63,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    20,    21,    22,    23,
      63,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    20,    21,    22,    23,    63,
      -1,    26,    27,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      -1,    -1,    57,    58,    -1,    60,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    60,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    -1,    60,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    -1,    60,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    -1,
      31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    -1,    -1,    57,    58,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    -1,    48,    49,    50,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      -1,    -1,    57,    58,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    20,
      21,    57,    58,    -1,    -1,    -1,    -1,    28,    29,    -1,
      31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    -1,    -1,    57,    58,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    -1,    48,    49,    50,    -1,
      52,    -1,    54,    28,    29,    57,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      36,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      31,    32,    57,    58,    -1,    36,    52,    53,    54,    -1,
      -1,    57,    58,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    31,    32,    57,    58,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    52,    53,    54,    -1,    -1,
      57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,     0,    11,    12,    13,    33,    34,   111,   112,
     115,     6,    52,   105,     6,    53,    56,    58,    99,   100,
     101,   102,   103,   104,     6,     6,    64,   109,   110,    52,
       6,    48,    53,     6,    13,   104,   104,    61,    62,    61,
      62,    60,   104,    60,    63,     6,    53,    53,    68,    52,
      53,     6,   104,   116,   117,    13,   104,   104,   104,    53,
       6,   118,   117,     3,     4,     5,     6,     7,     8,     9,
      14,    15,    18,    30,    35,    40,    43,    47,    53,    56,
      58,    65,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    93,    94,    95,    96,    98,   107,
     108,   110,   113,   114,   105,   106,    61,     6,    60,    63,
     117,    60,    63,    60,    72,    53,    16,    72,    53,     6,
      72,    72,    58,    72,    72,    72,     4,    72,    20,    21,
      22,    23,    26,    27,    28,    29,    31,    32,    36,    38,
      42,    44,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    57,    58,    69,    97,    62,    63,    61,    62,    77,
      78,    78,    81,    77,    63,    78,    81,    58,    70,    92,
      78,    81,    60,    63,    63,    65,    60,    63,    72,    61,
     116,    60,     6,    72,     6,    42,     4,    43,    60,    63,
      72,    72,    72,    72,    72,    72,    72,    72,   104,    72,
      72,    72,    72,    72,    72,    72,    53,    72,     6,    72,
      61,    62,    72,    72,     4,    58,   104,    19,    72,    61,
      72,    17,    63,    61,    62,    72,     6,    72,   105,    72,
      60,    42,    72,    72,    62,    72,   104,    53,    72,    72,
      78,    81,    63,    72,    72,    92,    72,    17,    63,    42,
      72,    54,    60,    63,    77,    62,    72,    70,    72,    60,
       6,    72,    72,    17,    17,    60,    72,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    81,    81,    81,    81,    82,    82,    83,    84,
      85,    86,    87,    88,    89,    89,    90,    91,    92,    92,
      92,    92,    93,    94,    94,    94,    94,    95,    96,    97,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   109,   110,   111,
     111,   112,   113,   113,   113,   113,   113,   113,   114,   115,
     116,   116,   116,   117,   117,   117,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     7,     6,     2,     0,     2,
       2,     3,     1,     2,     2,     1,     1,     1,     3,     3,
       2,     3,     3,     3,     3,     2,     2,     1,     1,     7,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     1,     1,     5,     4,     6,     3,
       4,     2,     1,     3,     3,     2,     3,     1,     1,     1,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     1,     1,     1,     2,     4,     6,     4,
       2,     2,     1,     2,     5,     1,     2,     2,     2,     3,
       3,     2,     2,     4,     7,     7,     5,     2,     2,     1,
       3,     2,     2,     3,     3,     3,     2,     2,     3,     2,
       2,     1,     2,     1,     1,     1,     2,     3,     0,     1,
       3,     2,     4,     3,     3,     2,     2,     1,     3,     5,
       6,     5,     1,     2,     4,     3,     2,     5,     2,     2,
       2,     3,     4,     0,     1,     3,     1,     3
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
#line 150 "axo_gram.y"
                           {}
#line 1985 "axo_gram.tab.c"
    break;

  case 3: /* declarations: declarations func_def  */
#line 151 "axo_gram.y"
                          {
    axo_add_decl(state, axo_func_def_to_decl((yyvsp[0].function)));
  }
#line 1993 "axo_gram.tab.c"
    break;

  case 4: /* declarations: declarations "#include"  */
#line 154 "axo_gram.y"
                           { //Fix: Check if file exists
    axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", (yyvsp[0].str)), .kind=axo_c_include_decl_kind});
  }
#line 2001 "axo_gram.tab.c"
    break;

  case 5: /* declarations: declarations "#register" c_typ "identifier" '(' c_typ_list ')'  */
#line 157 "axo_gram.y"
                                                          {
    // printf("Starting to register a C function\n");
    axo_func fn;
    fn.name = alloc_str((yyvsp[-3].str));
    fn.f_typ.args_len = (yyvsp[-1].types_list).len;
    fn.f_typ.ret_typ = (yyvsp[-4].typ_type);
    fn.body = NULL; //This is only true for C functions!
    fn.args_names = (char**)malloc(fn.f_typ.args_len*sizeof(char*));
    fn.f_typ.args_defs = (char**)malloc(fn.f_typ.args_len*sizeof(char*));
    fn.f_typ.args_types = (axo_typ*)malloc(fn.f_typ.args_len*sizeof(axo_typ));
    for (int i = 0; i<fn.f_typ.args_len; i++){
      asprintf(&(fn.args_names[i]), "p%d", i+1);
      //FIX: Every type should have default value!
      fn.f_typ.args_defs[i] = (yyvsp[-1].types_list).values[i].def;
      fn.f_typ.args_types[i] = (yyvsp[-1].types_list).values[i];
    }
    axo_set_func(state, fn);
    axo_add_decl(state, (axo_decl){.val=fmtstr("//registered function '%s'", fn.name), .kind=axo_c_register_decl_kind});
  }
#line 2025 "axo_gram.tab.c"
    break;

  case 6: /* declarations: declarations "enum" "identifier" '(' enum_names ')'  */
#line 176 "axo_gram.y"
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
      axo_set_var(global_scope, (axo_var){.name=field, .typ=axo_no_typ, .is_const=true});
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
#line 2064 "axo_gram.tab.c"
    break;

  case 7: /* declarations: declarations struct_def  */
#line 210 "axo_gram.y"
                            { //Fix! Make this use realloc less
    new_ptr_one(strct, axo_struct);
    *strct = (yyvsp[0].struct_type);
    char* decl = empty_str;
    strapnd(&decl, "typedef struct ");
    strapnd(&decl, (yyvsp[0].struct_type).name);
    strapnd(&decl, "{\n");
    for (int i=0; i<(yyvsp[0].struct_type).fields_len; i++){
      strapnd(&decl, axo_name_typ_decl((yyvsp[0].struct_type).fields[i].name, (yyvsp[0].struct_type).fields[i].def.typ));
      strapnd(&decl, ";\n");
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
    axo_add_decl(state, (axo_decl){.val=decl, .kind=axo_struct_decl_kind});
  }
#line 2094 "axo_gram.tab.c"
    break;

  case 8: /* statements: %empty  */
#line 237 "axo_gram.y"
                         {}
#line 2100 "axo_gram.tab.c"
    break;

  case 9: /* statements: statements statement  */
#line 238 "axo_gram.y"
                         {axo_add_statement(top_scope, (yyvsp[0].statement_type));}
#line 2106 "axo_gram.tab.c"
    break;

  case 10: /* index_access: '[' expr  */
#line 241 "axo_gram.y"
                        {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.index_access_type) = (axo_index_access){
      .index_count=1,
      .indexes = (axo_expr*)malloc(128*sizeof(axo_expr))
    };
    (yyval.index_access_type).indexes[0] = (yyvsp[0].expression);
  }
#line 2119 "axo_gram.tab.c"
    break;

  case 11: /* index_access: index_access '|' expr  */
#line 249 "axo_gram.y"
                          {
    (yyval.index_access_type).indexes[(yyval.index_access_type).index_count++] = (yyvsp[0].expression);
  }
#line 2127 "axo_gram.tab.c"
    break;

  case 12: /* identifier: "identifier"  */
#line 254 "axo_gram.y"
                  {
    axo_typ_def* td = axo_get_typ_def(state, (yyvsp[0].str));
    if (td != NULL) {
         (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_typ_kind,
        .data = td
      };
    }else if (false) { //check for module!
    }else{ //Then assume it was a variable
      (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_var_kind,
        .data = (void*)alloc_str((yyvsp[0].str))
      };
    }
  }
#line 2147 "axo_gram.tab.c"
    break;

  case 13: /* incr_decr_op: expr "++"  */
#line 271 "axo_gram.y"
                            {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s++", (yyvsp[-1].expression).val);
  }
#line 2156 "axo_gram.tab.c"
    break;

  case 14: /* incr_decr_op: expr "--"  */
#line 275 "axo_gram.y"
                 {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s--", (yyvsp[-1].expression).val);
  }
#line 2165 "axo_gram.tab.c"
    break;

  case 15: /* expr: "string literal"  */
#line 281 "axo_gram.y"
                      {set_val(&(yyval.expression), axo_mk_simple_typ("char*"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind;}
#line 2171 "axo_gram.tab.c"
    break;

  case 16: /* expr: "integer literal"  */
#line 282 "axo_gram.y"
                    {set_val(&(yyval.expression), axo_mk_simple_typ("int"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2177 "axo_gram.tab.c"
    break;

  case 17: /* expr: "float literal"  */
#line 283 "axo_gram.y"
                  {set_val(&(yyval.expression), axo_mk_simple_typ("float"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2183 "axo_gram.tab.c"
    break;

  case 18: /* expr: expr '+' expr  */
#line 284 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "+", (yyvsp[0].expression)); }
#line 2189 "axo_gram.tab.c"
    break;

  case 19: /* expr: expr '-' expr  */
#line 285 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "-", (yyvsp[0].expression)); }
#line 2195 "axo_gram.tab.c"
    break;

  case 20: /* expr: '-' expr  */
#line 286 "axo_gram.y"
             {asprintf(&((yyval.expression).val), "-%s", (yyvsp[0].expression).val); (yyval.expression).typ = (yyvsp[0].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2201 "axo_gram.tab.c"
    break;

  case 21: /* expr: expr '*' expr  */
#line 287 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "*", (yyvsp[0].expression)); }
#line 2207 "axo_gram.tab.c"
    break;

  case 22: /* expr: expr '/' expr  */
#line 288 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "/", (yyvsp[0].expression)); }
#line 2213 "axo_gram.tab.c"
    break;

  case 23: /* expr: expr '%' expr  */
#line 289 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "%", (yyvsp[0].expression)); }
#line 2219 "axo_gram.tab.c"
    break;

  case 24: /* expr: '(' expr ')'  */
#line 290 "axo_gram.y"
                 {asprintf(&((yyval.expression).val), "(%s)", (yyvsp[-1].expression).val); (yyval.expression).typ = (yyvsp[-1].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2225 "axo_gram.tab.c"
    break;

  case 25: /* expr: '@' expr  */
#line 291 "axo_gram.y"
             { //Referencing
    if ((yyvsp[0].expression).lval_kind == axo_not_lval_kind)
      yyerror(&(yylsp[0]), "Cannot reference a non l-value.");
    (yyval.expression).typ.kind = axo_ptr_kind;
    (yyval.expression).typ.subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp((yyval.expression).typ) = (yyvsp[0].expression).typ;
    asprintf(&((yyval.expression).val), "&%s", (yyvsp[0].expression).val);
  }
#line 2238 "axo_gram.tab.c"
    break;

  case 26: /* expr: expr '^'  */
#line 299 "axo_gram.y"
             { //Dereferencing
    if ((yyvsp[-1].expression).typ.kind != axo_ptr_kind)
      yyerror(&(yylsp[-1]), "Cannot dereference a value of non-pointer type '%s'.", axo_typ_to_str((yyvsp[-1].expression).typ));
    (yyval.expression).typ = *axo_subtyp((yyvsp[-1].expression).typ);
    asprintf(&((yyval.expression).val), "(*(%s))", (yyvsp[-1].expression).val);
  }
#line 2249 "axo_gram.tab.c"
    break;

  case 28: /* expr: identifier  */
#line 309 "axo_gram.y"
               {
    switch((yyvsp[0].identifier_type).kind){
      case axo_identifier_var_kind:
        char* var_name = (char*)((yyvsp[0].identifier_type).data);
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
        axo_typ_def* td = (axo_typ_def*)((yyvsp[0].identifier_type).data);
        switch (td->typ.kind){
          case axo_enum_kind:
            (yyval.expression) = (axo_expr){
              .kind=axo_expr_enum_typ_kind,
              .typ=td->typ,
              .val=fmtstr("%s$%s", td->name, ((axo_enum*)(td->typ.enumerate))->names[0])
            };
            break;
          default:
            yyerror(&(yylsp[0]), "Non-enum type '%s' is not an expression.", td->name);
            break;
        }
        break;
      default:
        yyerror(&(yylsp[0]), "Invalid identifier as expression.");
        break;
    }
  }
#line 2290 "axo_gram.tab.c"
    break;

  case 29: /* expr: '(' expr '?' expr ':' expr ')'  */
#line 345 "axo_gram.y"
                                   {
    if (axo_validate_rval(&(yylsp[-5]), (yyvsp[-5].expression)) && axo_validate_rval(&(yylsp[-3]), (yyvsp[-3].expression)) && axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression))){
      YYLTYPE loc = (YYLTYPE){.first_line=(yylsp[-3]).first_line, .first_column=(yylsp[-3]).first_column, .last_line=(yylsp[-1]).last_line, .last_column=(yylsp[-1]).last_column};
      if (axo_typ_eq((yyvsp[-3].expression).typ, (yyvsp[-1].expression).typ)){
        (yyval.expression) = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", (yyvsp[-5].expression).val, (yyvsp[-3].expression).val, (yyvsp[-1].expression).val),
          .typ=(yyvsp[-3].expression).typ
        };
      }else{
        yyerror(&loc, "Ternary expression attempts to return different types: '%s' and '%s'.", axo_typ_to_str((yyvsp[-3].expression).typ), axo_typ_to_str((yyvsp[-1].expression).typ));
      }
    }
  }
#line 2310 "axo_gram.tab.c"
    break;

  case 30: /* expr: func_call  */
#line 360 "axo_gram.y"
              {(yyval.expression) = axo_call_to_expr((yyvsp[0].function_call));}
#line 2316 "axo_gram.tab.c"
    break;

  case 31: /* expr: expr '<' expr  */
#line 361 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2328 "axo_gram.tab.c"
    break;

  case 32: /* expr: expr '>' expr  */
#line 368 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2340 "axo_gram.tab.c"
    break;

  case 33: /* expr: expr "==" expr  */
#line 375 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s==%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2352 "axo_gram.tab.c"
    break;

  case 34: /* expr: expr "!=" expr  */
#line 382 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s!=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2364 "axo_gram.tab.c"
    break;

  case 35: /* expr: expr ">=" expr  */
#line 389 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2376 "axo_gram.tab.c"
    break;

  case 36: /* expr: expr "<=" expr  */
#line 396 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2388 "axo_gram.tab.c"
    break;

  case 37: /* expr: expr "or" expr  */
#line 403 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s||%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2402 "axo_gram.tab.c"
    break;

  case 38: /* expr: expr "and" expr  */
#line 412 "axo_gram.y"
                    {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s&&%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2416 "axo_gram.tab.c"
    break;

  case 39: /* expr: expr ">>" expr  */
#line 421 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s>>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2430 "axo_gram.tab.c"
    break;

  case 40: /* expr: expr "<<" expr  */
#line 430 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s<<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2444 "axo_gram.tab.c"
    break;

  case 41: /* expr: struct_literal  */
#line 439 "axo_gram.y"
                   {
    (yyval.expression).typ = (yyvsp[0].struct_val_type).typ;
    axo_struct* structure = (axo_struct*)((yyval.expression).typ.structure);
    //size of the string to avoid reallocing: (name){.field1=value1, }
    int v_len = strlen(structure->name) + 5;
    for (int i=0; i<structure->fields_len; i++){
      v_len+=strlen(structure->fields[i].name)+4+strlen((yyvsp[0].struct_val_type).fields[i]);  //name of a field + 3 cause of .=
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
      strcat(v, (yyvsp[0].struct_val_type).fields[i]);
    }
    strcat(v,"}");
    (yyval.expression).val = v;
    (yyval.expression).kind = axo_expr_normal_kind;
  }
#line 2472 "axo_gram.tab.c"
    break;

  case 42: /* expr: expr index_access ']'  */
#line 462 "axo_gram.y"
                         {
    (yylsp[-1]).last_column = (yylsp[0]).last_column;
    switch((yyvsp[-2].expression).typ.kind){
      case axo_arr_kind:
        axo_arr_typ arr_typ = axo_get_arr_typ((yyvsp[-2].expression).typ);
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
  }
#line 2503 "axo_gram.tab.c"
    break;

  case 43: /* expr: expr ".field"  */
#line 488 "axo_gram.y"
                   {
    switch((yyvsp[-1].expression).kind){
      case axo_expr_enum_typ_kind:
        axo_enum* enumerate = (axo_enum*)((yyvsp[-1].expression).typ.enumerate);
        int index = -1;
        for (int i=0; i<enumerate->len; i++){
          if (strcmp(enumerate->names[i], (yyvsp[0].str))==0){
            index = i;
            break;
          }
        }
        if (index<0)
         yyerror(&(yyloc), "Enum '%s' doesn't have a field named '%s'.", enumerate->name, (yyvsp[0].str));
        else{
          (yyval.expression) = (axo_expr){
            .kind=axo_expr_normal_kind,
            .typ=(yyvsp[-1].expression).typ,
            .val=fmtstr("%s$%s", enumerate->name, enumerate->names[index])
          };
        }
        break;
      default:
        switch((yyvsp[-1].expression).typ.kind){
          case axo_struct_kind:
            axo_struct* structure = (axo_struct*)((yyvsp[-1].expression).typ.structure);
            int index = -1;
            for (int i=0;i<structure->fields_len; i++){
              if (strcmp(structure->fields[i].name, (yyvsp[0].str))==0){
                index = i;
                break;
              }
            }
            if (index<0) yyerror(&(yyloc), "Struct '%s' doesn't have a field named '%s'.", structure->name, (yyvsp[0].str));
            else{
              (yyval.expression) = (axo_expr){
                .kind=axo_expr_normal_kind,
                .val=fmtstr("%s.%s", (yyvsp[-1].expression).val, (yyvsp[0].str)),
                .typ=structure->fields[index].def.typ
              };
            }
            break;
          case axo_arr_kind: //.len, .data, .dims
            if (strcmp("len", (yyvsp[0].str))==0){
              //FIX! This should return an int pointer, not first element
              axo_typ typ = (axo_typ){
                .kind = axo_ptr_kind,
                .subtyp=malloc(sizeof(axo_typ))
              };
              *axo_subtyp(typ) = state->int_def->typ;
              (yyval.expression) = (axo_expr){
                .kind=axo_expr_normal_kind,
                .typ = typ,
                .val=fmtstr("%s.len", (yyvsp[-1].expression).val),
                .lval_kind = axo_not_lval_kind
              };
            }else if (strcmp("dims", (yyvsp[0].str))==0){
              (yyval.expression) = (axo_expr){
                .kind=axo_expr_normal_kind,
                .typ=state->int_def->typ,
                .val=fmtstr("%d", axo_get_arr_typ((yyvsp[-1].expression).typ).dim_count),
                .lval_kind = axo_not_lval_kind
              };
            }else if (strcmp("data", (yyvsp[0].str))==0){
              (yyval.expression) = (axo_expr){
                .kind=axo_expr_normal_kind,
                .typ=state->int_def->typ,
                .val=fmtstr("%s.data", (yyvsp[-1].expression).val),
                .lval_kind = axo_other_lval_kind
              };
            }
            break;
          default:
            yyerror(&(yylsp[-1]), "Cannot get field of type '%s'", axo_typ_to_str((yyvsp[-1].expression).typ));
          break;
        }
        break;
    }
  }
#line 2586 "axo_gram.tab.c"
    break;

  case 46: /* expr: expr '.' '(' val_typ ')'  */
#line 568 "axo_gram.y"
                             {
    switch((yyvsp[-4].expression).typ.kind){
      case axo_simple_kind:
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
#line 2620 "axo_gram.tab.c"
    break;

  case 47: /* stat_arr_literal_start: '[' expr ',' expr  */
#line 599 "axo_gram.y"
                                           {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyvsp[-2].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=false,
      .len=(int[]){0},
      .dim_count=1,
      .count=2,
      .val=fmtstr("(axo__arr){.data=(%s){%s,%s", axo_c_arr_of_typ((yyvsp[-2].expression).typ, ""), (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 2640 "axo_gram.tab.c"
    break;

  case 48: /* stat_arr_literal_start: empty_arr_dims ']' '[' expr ',' expr  */
#line 614 "axo_gram.y"
                                         {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyvsp[-2].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=false,
      .len=(yyvsp[-5].empty_arr_lit_type).len,
      .dim_count=(yyvsp[-5].empty_arr_lit_type).dim_count,
      .count=2,
      .val=fmtstr("(axo__arr){.data=(%s){%s,%s", axo_c_arr_of_typ((yyvsp[-2].expression).typ, ""), (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 2660 "axo_gram.tab.c"
    break;

  case 49: /* stat_arr_literal_start: stat_arr_literal_start ',' expr  */
#line 629 "axo_gram.y"
                                    {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyval.arr_lit_type).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyval.arr_lit_type).typ));
    }
    strapnd(&(yyval.arr_lit_type).val, ",");
    strapnd(&(yyval.arr_lit_type).val, (yyvsp[0].expression).val);
    (yyval.arr_lit_type).count++;
  }
#line 2674 "axo_gram.tab.c"
    break;

  case 50: /* stat_arr_literal: '[' expr ',' ']'  */
#line 640 "axo_gram.y"
                                    {
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=false,
      .len=(int[]){1},
      .dim_count=1,
      .count=1,
      .val=fmtstr("(axo__arr){.data=(%s){%s},.len=(axo_arr_dim_t[]){1},.flags=AXO_ARR_STATIC}", axo_c_arr_of_typ((yyvsp[-2].expression).typ, ""), (yyvsp[-2].expression).val),
      .typ=(yyvsp[-2].expression).typ
    };
  }
#line 2689 "axo_gram.tab.c"
    break;

  case 51: /* stat_arr_literal: stat_arr_literal_start ']'  */
#line 650 "axo_gram.y"
                               {
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
    char* len_str = alloc_str("(axo_arr_dim_t[]){");
    char hlpr[128];
    for (int i=0; i<(yyval.arr_lit_type).dim_count; i++){
      if (i>0) strapnd(&len_str, ",");
      sprintf(hlpr, "%d", (yyval.arr_lit_type).len[i]);
      strapnd(&len_str, hlpr);
    }
    strapnd(&((yyval.arr_lit_type).val), fmtstr("}, .len=%s},.flags=AXO_ARR_STATIC}", len_str));
    free(len_str);
  }
#line 2715 "axo_gram.tab.c"
    break;

  case 52: /* arr_literal: stat_arr_literal  */
#line 673 "axo_gram.y"
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
#line 2735 "axo_gram.tab.c"
    break;

  case 53: /* arr_literal: empty_arr_dims ']' val_typ  */
#line 688 "axo_gram.y"
                               {
    char* dims_str = empty_str;
    unsigned total_sz = 1;
    for (int i=0; i<(yyvsp[-2].empty_arr_lit_type).dim_count; i++){
      total_sz *= (yyvsp[-2].empty_arr_lit_type).len[i];
      if (i>0) strapnd(&dims_str, ",");
      asprintf(&dims_str, "%s%d", dims_str, (yyvsp[-2].empty_arr_lit_type).len[i]);
    }
    strapnd(&dims_str, "");
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
          fmtstr("axo_arr_new_dyn(malloc((%u)*sizeof(%s)), ((axo_arr_dim_t[]){%s}))", total_sz, axo_typ_to_c_str(axo_get_arr_typ(typ).subtyp), dims_str)
          : fmtstr("axo_arr_new_stat((%s){}, ((axo_arr_dim_t[]){%s}))", axo_c_arr_of_typ((yyvsp[0].typ_type), sz_str), dims_str),
      .typ=typ
    };
  }
#line 2767 "axo_gram.tab.c"
    break;

  case 54: /* empty_arr_dims: '?' '[' "integer literal"  */
#line 717 "axo_gram.y"
                                         {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=true,
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[0].str));
  }
#line 2780 "axo_gram.tab.c"
    break;

  case 55: /* empty_arr_dims: '[' "integer literal"  */
#line 725 "axo_gram.y"
                        {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=false,
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[0].str));
  }
#line 2793 "axo_gram.tab.c"
    break;

  case 56: /* empty_arr_dims: empty_arr_dims '|' "integer literal"  */
#line 733 "axo_gram.y"
                                       {
    (yyval.empty_arr_lit_type)=(yyvsp[-2].empty_arr_lit_type);
    (yyval.empty_arr_lit_type).len[(yyval.empty_arr_lit_type).dim_count++] = atoi((yyvsp[0].str));
  }
#line 2802 "axo_gram.tab.c"
    break;

  case 59: /* matching_statement: expr  */
#line 741 "axo_gram.y"
                          {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2813 "axo_gram.tab.c"
    break;

  case 60: /* matching_statement: '$' expr  */
#line 747 "axo_gram.y"
             {
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2823 "axo_gram.tab.c"
    break;

  case 61: /* matching_statement: "ret" expr  */
#line 752 "axo_gram.y"
                  {
    (yyval.statement_type).kind = axo_ret_statement_kind;
    char* ret_assign = axo_get_ret_assign(top_scope);
    if (ret_assign == NULL)
      asprintf(&((yyval.statement_type).val), "return %s;", (yyvsp[0].expression).val);
    else
      asprintf(&((yyval.statement_type).val), "%s = %s;", ret_assign, (yyvsp[0].expression).val);
    if (axo_is_no_typ(top_scope->ret_typ)) //Add line it was done in? FIX
      top_scope->ret_typ = (yyvsp[0].expression).typ;
    else if(!axo_typ_eq(top_scope->ret_typ, (yyvsp[0].expression).typ))
      yyerror(&(yylsp[0]), "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str(top_scope->ret_typ));
  }
#line 2840 "axo_gram.tab.c"
    break;

  case 62: /* matching_statement: code_scope  */
#line 764 "axo_gram.y"
               {
    (yyval.statement_type) = axo_scope_to_statement((yyvsp[0].scope));
  }
#line 2848 "axo_gram.tab.c"
    break;

  case 63: /* matching_statement: expr "is" val_typ  */
#line 767 "axo_gram.y"
                      {
    if ((yyvsp[-2].expression).lval_kind == axo_var_lval_kind){
      //
      axo_typ typ = axo_clean_typ((yyvsp[0].typ_type));
      printf(axo_cyan_fg"Setting var '%s':"axo_reset_style"\n", (yyvsp[-2].expression).val);
      printf("type: '%s'\n", axo_typ_to_str(typ));
      printf("c_type: '%s'\n", axo_typ_to_c_str(typ));
      printf("name_typ_decl: '%s'\n", axo_name_typ_decl((yyvsp[-2].expression).val, typ));
      //
      (yyval.statement_type) = (axo_statement){
        .kind=axo_var_is_decl_statement_kind,
        .val=axo_name_typ_decl((yyvsp[-2].expression).val, (yyvsp[0].typ_type))
      };
      strapnd(&((yyval.statement_type).val), ";");
      axo_set_var(top_scope, (axo_var){.name=(yyvsp[-2].expression).val, .typ=axo_clean_typ((yyvsp[0].typ_type)), .is_const=false});
    }else{
      yyerror(&(yylsp[-2]), "Cannot declare non-variable value '%s'.", (yyvsp[-2].expression).val);
    }
  }
#line 2872 "axo_gram.tab.c"
    break;

  case 64: /* matching_statement: "continue"  */
#line 786 "axo_gram.y"
               {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to continue.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = "continue;"
    };
  }
#line 2884 "axo_gram.tab.c"
    break;

  case 65: /* matching_statement: "break"  */
#line 793 "axo_gram.y"
            {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to break out of.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = "break;"
    };
  }
#line 2896 "axo_gram.tab.c"
    break;

  case 70: /* if_condition: "if" expr  */
#line 806 "axo_gram.y"
                            {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2905 "axo_gram.tab.c"
    break;

  case 71: /* matching_if_statement: if_condition matching_statement "else" matching_statement  */
#line 812 "axo_gram.y"
                                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2913 "axo_gram.tab.c"
    break;

  case 76: /* non_matching_if_statement: if_condition statement  */
#line 823 "axo_gram.y"
                                                   {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s", (yyvsp[-1].expression).val, (yyvsp[0].statement_type).val);
  }
#line 2921 "axo_gram.tab.c"
    break;

  case 77: /* non_matching_if_statement: if_condition matching_statement "else" non_matching_statement  */
#line 826 "axo_gram.y"
                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2929 "axo_gram.tab.c"
    break;

  case 78: /* till_loop_start: "till" '(' "identifier" '=' expr ')'  */
#line 831 "axo_gram.y"
                                                   {
    (yyval.till_loop_type).iter = (yyvsp[-3].str);
    (yyval.till_loop_type).start = "0";
    (yyval.till_loop_type).lim = (yyvsp[-1].expression);
    printf("till iter %s created scope\n", (yyval.till_loop_type).iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=axo_mk_simple_typ("int"), .name=(yyval.till_loop_type).iter, .is_const=false});
  }
#line 2942 "axo_gram.tab.c"
    break;

  case 79: /* while_loop_base: "while" '(' expr ')'  */
#line 841 "axo_gram.y"
                                       {
    if (axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression)))
      (yyval.str) = alloc_str((yyvsp[-1].expression).val);
    in_loop_count++;
  }
#line 2952 "axo_gram.tab.c"
    break;

  case 80: /* matching_while: while_loop_base matching_statement  */
#line 848 "axo_gram.y"
                                                    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 2964 "axo_gram.tab.c"
    break;

  case 81: /* non_matching_while: while_loop_base non_matching_statement  */
#line 857 "axo_gram.y"
                                                            {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 2976 "axo_gram.tab.c"
    break;

  case 82: /* for_loop_start: "for"  */
#line 866 "axo_gram.y"
                       {
    axo_push_scope(scopes, axo_new_scope(top_scope));
  }
#line 2984 "axo_gram.tab.c"
    break;

  case 83: /* for_loop_init: for_loop_start statement  */
#line 871 "axo_gram.y"
                                         {
    (yyval.for_loop_type).start = (yyvsp[0].statement_type).val;
  }
#line 2992 "axo_gram.tab.c"
    break;

  case 84: /* for_loop_base: for_loop_init ',' expr ',' statement  */
#line 876 "axo_gram.y"
                                                     {
    axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression));
    char* iter = (yyvsp[0].statement_type).val;
    iter[strlen(iter)-1] = '\0';
    (yyval.for_loop_type) = (axo_for_loop){
      .start = (yyvsp[-4].for_loop_type).start,
      .condition = (yyvsp[-2].expression).val,
      .iteration = iter,
    };
    in_loop_count++;
  }
#line 3008 "axo_gram.tab.c"
    break;

  case 85: /* for_loop_base: till_loop_start  */
#line 887 "axo_gram.y"
                    {
    (yyval.for_loop_type) = (axo_for_loop){
      .start = fmtstr("int %s=%s;", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).start),
      .condition = fmtstr("%s<%s", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).lim.val),
      .iteration = fmtstr("%s++", (yyvsp[0].till_loop_type).iter),
    };
    in_loop_count++;
  }
#line 3021 "axo_gram.tab.c"
    break;

  case 86: /* matching_for_loop: for_loop_base matching_statement  */
#line 898 "axo_gram.y"
                                                     {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3033 "axo_gram.tab.c"
    break;

  case 87: /* non_matching_for_loop: for_loop_base non_matching_statement  */
#line 906 "axo_gram.y"
                                                             {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3045 "axo_gram.tab.c"
    break;

  case 88: /* each_iter_dims: '[' expr  */
#line 915 "axo_gram.y"
                          {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=1,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3] = (yylsp[0]);
  }
#line 3059 "axo_gram.tab.c"
    break;

  case 89: /* each_iter_dims: '[' '|' expr  */
#line 924 "axo_gram.y"
                 {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=2,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (axo_expr){.kind=axo_no_kind, .val=NULL};
    (yyval.each_loop_type).dim_iters[1] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[4] = (yylsp[0]);
  }
#line 3074 "axo_gram.tab.c"
    break;

  case 90: /* each_iter_dims: each_iter_dims '|' expr  */
#line 934 "axo_gram.y"
                            {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3+(yyval.each_loop_type).dim_count++] = (yylsp[0]);
  }
#line 3083 "axo_gram.tab.c"
    break;

  case 91: /* each_iter_dims: each_iter_dims '|'  */
#line 938 "axo_gram.y"
                       {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count++] = (axo_expr){.kind=axo_no_kind, .val=NULL};
  }
#line 3091 "axo_gram.tab.c"
    break;

  case 92: /* each_loop_start: "for" "each"  */
#line 943 "axo_gram.y"
                               {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    in_loop_count++;
  }
#line 3100 "axo_gram.tab.c"
    break;

  case 93: /* each_loop_base: each_loop_start identifier "in" expr  */
#line 949 "axo_gram.y"
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
#line 3119 "axo_gram.tab.c"
    break;

  case 94: /* each_loop_base: each_loop_start identifier ',' each_iter_dims ']' "in" expr  */
#line 963 "axo_gram.y"
                                                                {
    (yylsp[-3]).last_column = (yylsp[-2]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[-3].each_loop_type).dim_count,
      .dim_iters=(yyvsp[-3].each_loop_type).dim_iters,
      .value_iter=(axo_identifier){.kind=axo_no_identifier_kind, .data=NULL},
      .collection=(yyvsp[0].expression),
      .locs=(yyvsp[-3].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[-5]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[-3]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[0]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
#line 3138 "axo_gram.tab.c"
    break;

  case 95: /* each_loop_base: each_loop_start each_iter_dims ']' ',' identifier "in" expr  */
#line 977 "axo_gram.y"
                                                                {
    (yylsp[-5]).last_column = (yylsp[-4]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[-5].each_loop_type).dim_count,
      .dim_iters=(yyvsp[-5].each_loop_type).dim_iters,
      .value_iter=(yyvsp[-2].identifier_type),
      .collection=(yyvsp[0].expression),
      .locs=(yyvsp[-5].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[-2]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[-5]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[0]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
#line 3157 "axo_gram.tab.c"
    break;

  case 96: /* each_loop_base: each_loop_start each_iter_dims ']' "in" expr  */
#line 991 "axo_gram.y"
                                                 {
    (yylsp[-3]).last_column = (yylsp[-2]).last_column;
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
#line 3175 "axo_gram.tab.c"
    break;

  case 97: /* matching_each_loop: each_loop_base matching_statement  */
#line 1007 "axo_gram.y"
                                                       {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3186 "axo_gram.tab.c"
    break;

  case 98: /* non_matching_each_loop: each_loop_base non_matching_statement  */
#line 1015 "axo_gram.y"
                                                               {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3197 "axo_gram.tab.c"
    break;

  case 99: /* assign_op: '='  */
#line 1023 "axo_gram.y"
                {
    rval_now = true;
  }
#line 3205 "axo_gram.tab.c"
    break;

  case 100: /* assignment: expr assign_op expr  */
#line 1028 "axo_gram.y"
                                 {
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_typ l_typ = (yyvsp[-2].expression).typ;
    switch((yyvsp[-2].expression).lval_kind){
      case axo_var_lval_kind:
        if ((yyvsp[-2].expression).typ.kind == axo_no_kind){
          l_typ = axo_clean_typ((yyvsp[0].expression).typ);
          (yyval.expression).val = axo_get_var_decl_assign((yyvsp[-2].expression).val, (axo_expr){.typ=l_typ, .val=(yyvsp[0].expression).val});
          axo_set_var(top_scope, (axo_var){.typ = l_typ, .name = (yyvsp[-2].expression).val, .is_const=false});
        }else{
          (yyval.expression).val = fmtstr("%s=%s",(yyvsp[-2].expression).val, (yyvsp[0].expression).val);
        }
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
#line 3234 "axo_gram.tab.c"
    break;

  case 101: /* arr_multidim_typ: '[' '|'  */
#line 1054 "axo_gram.y"
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
#line 3249 "axo_gram.tab.c"
    break;

  case 102: /* arr_multidim_typ: arr_multidim_typ '|'  */
#line 1064 "axo_gram.y"
                         {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_get_arr_typ((yyval.typ_type)).dim_count++;
  }
#line 3258 "axo_gram.tab.c"
    break;

  case 103: /* arr_typ: '[' ']' val_typ  */
#line 1070 "axo_gram.y"
                          {
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
#line 3274 "axo_gram.tab.c"
    break;

  case 104: /* arr_typ: arr_multidim_typ ']' val_typ  */
#line 1081 "axo_gram.y"
                                 {
    (yyval.typ_type) = (yyvsp[-2].typ_type);
    axo_get_arr_typ((yyval.typ_type)).subtyp = (yyvsp[0].typ_type);
  }
#line 3283 "axo_gram.tab.c"
    break;

  case 105: /* func_typ_start: '(' val_typ "fn"  */
#line 1087 "axo_gram.y"
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
#line 3299 "axo_gram.tab.c"
    break;

  case 106: /* func_typ_start: '(' "fn"  */
#line 1098 "axo_gram.y"
                {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=axo_no_typ;
    (yyval.typ_type) = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  }
#line 3315 "axo_gram.tab.c"
    break;

  case 107: /* func_typ_args: func_typ_start val_typ  */
#line 1111 "axo_gram.y"
                                       {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = (yyvsp[0].typ_type);
    func_typ->args_defs[0] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 3329 "axo_gram.tab.c"
    break;

  case 108: /* func_typ_args: func_typ_args ',' val_typ  */
#line 1120 "axo_gram.y"
                              {
    (yyval.typ_type)=(yyvsp[-2].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = (yyvsp[0].typ_type);
    func_typ->args_defs[func_typ->args_len] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 3343 "axo_gram.tab.c"
    break;

  case 109: /* func_typ: func_typ_start ')'  */
#line 1131 "axo_gram.y"
                              {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 3349 "axo_gram.tab.c"
    break;

  case 110: /* func_typ: func_typ_args ')'  */
#line 1132 "axo_gram.y"
                      {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 3355 "axo_gram.tab.c"
    break;

  case 111: /* val_typ: "identifier"  */
#line 1135 "axo_gram.y"
               {
    axo_typ_def* def = axo_get_typ_def(state, (yyvsp[0].str));
    if (def==NULL)
      yyerror(&(yylsp[0]), "Type '%s' isn't defined.", (yyvsp[0].str));
    else
      (yyval.typ_type)=def->typ;
  }
#line 3367 "axo_gram.tab.c"
    break;

  case 112: /* val_typ: '@' val_typ  */
#line 1142 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_ptr_kind;
    (yyval.typ_type).subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp((yyval.typ_type))=(yyvsp[0].typ_type);
  }
#line 3377 "axo_gram.tab.c"
    break;

  case 115: /* c_typ: "identifier"  */
#line 1151 "axo_gram.y"
             {
    (yyval.typ_type).kind = axo_simple_kind;
    (yyval.typ_type).simple = alloc_str((yyvsp[0].str));
  }
#line 3386 "axo_gram.tab.c"
    break;

  case 116: /* c_typ: c_typ '*'  */
#line 1155 "axo_gram.y"
              {
    asprintf(&((yyvsp[-1].typ_type).simple), "%s*", (yyvsp[-1].typ_type).simple);
    (yyval.typ_type).simple = (yyvsp[-1].typ_type).simple;
    (yyval.typ_type).kind = (yyvsp[-1].typ_type).kind;
  }
#line 3396 "axo_gram.tab.c"
    break;

  case 117: /* c_typ: '.' '.' '.'  */
#line 1160 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_c_arg_list_kind;
    (yyval.typ_type).simple = NULL;
  }
#line 3405 "axo_gram.tab.c"
    break;

  case 118: /* c_typ_list: %empty  */
#line 1166 "axo_gram.y"
                           {
    (yyval.types_list).len = 0;
    (yyval.types_list).values = NULL;
  }
#line 3414 "axo_gram.tab.c"
    break;

  case 119: /* c_typ_list: c_typ  */
#line 1170 "axo_gram.y"
          {
    (yyval.types_list).values = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.types_list).values[0] = (yyvsp[0].typ_type);
    (yyval.types_list).len = 1;
  }
#line 3424 "axo_gram.tab.c"
    break;

  case 120: /* c_typ_list: c_typ_list ',' c_typ  */
#line 1175 "axo_gram.y"
                         {
    if ((yyvsp[-2].types_list).values[(yyvsp[-2].types_list).len-1].kind == axo_c_arg_list_kind)
      yyerror(&(yylsp[-2]), "The C v_args argument has to be the last one.");
    (yyval.types_list) = (yyvsp[-2].types_list);
    if ((yyval.types_list).len % axo_func_args_cap == 0)
      (yyval.types_list).values = (axo_typ*)realloc((yyval.types_list).values, ((yyval.types_list).len+axo_func_args_cap)*sizeof(axo_typ));
    (yyval.types_list).values[(yyval.types_list).len] = (yyvsp[0].typ_type);
    (yyval.types_list).len++;
  }
#line 3438 "axo_gram.tab.c"
    break;

  case 121: /* func_call_start: expr '('  */
#line 1186 "axo_gram.y"
                           {
    if (axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression))) {
      switch((yyvsp[-1].expression).typ.kind){
        case axo_func_kind:
          axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-1].expression).typ.func_typ);
          char** defaults = fnt->args_defs;
          (yyval.function_call).typ = (yyvsp[-1].expression).typ;
          (yyval.function_call).called_val = (yyvsp[-1].expression).val;
          (yyval.function_call).params = (axo_expr*)malloc(sizeof(axo_expr)*axo_func_args_cap);
          if (fnt->args_len>0){
            (yyval.function_call).params[0].val = defaults[0];
            (yyval.function_call).params_len = 1;
          }
          break;
        default:
          yyerror(&(yylsp[-1]), "Cannot call a non-funtion value.");
          break;
      }
    }
  }
#line 3463 "axo_gram.tab.c"
    break;

  case 122: /* func_call_start: expr ':' "identifier" '('  */
#line 1206 "axo_gram.y"
                     {
    //TODO: Methods
  }
#line 3471 "axo_gram.tab.c"
    break;

  case 123: /* func_call_start: expr '(' expr  */
#line 1209 "axo_gram.y"
                  {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression))){
      switch((yyvsp[-2].expression).typ.kind){
        case axo_func_kind:
          if (axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))) {
            axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-2].expression).typ.func_typ);
            (yyval.function_call).typ = (yyvsp[-2].expression).typ;
            (yyval.function_call).called_val = (yyvsp[-2].expression).val;
            (yyval.function_call).params = (axo_expr*)malloc(sizeof(axo_expr)*axo_func_args_cap);
            (yyval.function_call).params[0] = (yyvsp[0].expression);
            (yyval.function_call).params_len = 1;
            if ((yyval.function_call).params_len <= fnt->args_len){
              if (!axo_typ_eq(fnt->args_types[0], (yyvsp[0].expression).typ))
                yyerror(&(yylsp[0]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[(yyval.function_call).params_len-1]), (yyval.function_call).params_len, axo_typ_to_str((yyval.function_call).params[(yyval.function_call).params_len-1].typ));
            }else{
              if (fnt->args_types[0].kind != axo_c_arg_list_kind)
                yyerror(&(yylsp[-2]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[-2].expression).typ));
            }
          }
          break;
        default:
          yyerror(&(yylsp[-2]), "Cannot call a non-function value of type '%s'.", axo_typ_to_str((yyval.function_call).typ));
          break;
      }
  
    }
  }
#line 3503 "axo_gram.tab.c"
    break;

  case 124: /* func_call_start: func_call_start ',' expr  */
#line 1236 "axo_gram.y"
                             {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-2].function_call).typ.func_typ);
    resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
    int i = (yyval.function_call).params_len;
    if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
      if (i < fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[i], (yyvsp[0].expression).typ))
          yyerror(&(yylsp[0]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[i]), i, axo_typ_to_str((yyval.function_call).params[i].typ));
      }else{
          yyerror(&(yylsp[0]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[-2].function_call).typ));
      }
    }
    (yyval.function_call).params[i] = (yyvsp[0].expression);
    (yyval.function_call).params_len++;
  }
#line 3524 "axo_gram.tab.c"
    break;

  case 125: /* func_call_start: func_call_start ','  */
#line 1252 "axo_gram.y"
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
    (yyval.function_call).params[i].val = defaults[i];
    (yyval.function_call).params_len++;
  }
#line 3542 "axo_gram.tab.c"
    break;

  case 126: /* func_call: func_call_start ')'  */
#line 1267 "axo_gram.y"
                                {
    (yyval.function_call)=(yyvsp[-1].function_call);
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[-1].function_call).typ.func_typ);
    if (fnt->args_len>(yyval.function_call).params_len){
      (yyval.function_call).params=(axo_expr*)realloc((yyval.function_call).params, fnt->args_len*sizeof(axo_expr));
      for (int i=(yyvsp[-1].function_call).params_len; i<fnt->args_len-1; i++){ //Fill with defaults up until pre-last arg!
        (yyval.function_call).params[i] = (axo_expr){.typ=fnt->args_types[i], .val=fnt->args_defs[i]};
      }
      (yyval.function_call).params_len=fnt->args_len-1;
      if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
        (yyval.function_call).params[fnt->args_len-1] = (axo_expr){.typ=fnt->args_types[fnt->args_len-1], .val=fnt->args_defs[fnt->args_len-1]};
        (yyval.function_call).params_len++;
      }
    }
  }
#line 3562 "axo_gram.tab.c"
    break;

  case 127: /* code_scope_start: '{'  */
#line 1284 "axo_gram.y"
                       {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
#line 3571 "axo_gram.tab.c"
    break;

  case 128: /* code_scope: code_scope_start statements '}'  */
#line 1290 "axo_gram.y"
                                             {
    (yyval.scope) = top_scope;
    scopes->len--;
    if ((yyval.scope)->statements_len == 0)
      yyerror(&(yyloc), "Code scopes cannot be empty.");
  }
#line 3582 "axo_gram.tab.c"
    break;

  case 129: /* func_def_start: "fn" "identifier" '(' func_args ')'  */
#line 1298 "axo_gram.y"
                                                {
    (yyval.function).name = alloc_str((yyvsp[-3].str));
    (yyval.function).args_names = (yyvsp[-1].function).args_names;
    (yyval.function).f_typ.args_defs = (yyvsp[-1].function).f_typ.args_defs;
    (yyval.function).f_typ.args_types = (yyvsp[-1].function).f_typ.args_types;
    (yyval.function).f_typ.args_len = (yyvsp[-1].function).f_typ.args_len;
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    for (int i = 0; i<(yyval.function).f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=(yyval.function).args_names[i], .typ=(yyval.function).f_typ.args_types[i], .is_const=true});
    }
#line 3598 "axo_gram.tab.c"
    break;

  case 130: /* func_def_start: "fn" val_typ "identifier" '(' func_args ')'  */
#line 1309 "axo_gram.y"
                                           {
    (yyval.function).name = alloc_str((yyvsp[-3].str));
    (yyval.function).args_names = (yyvsp[-1].function).args_names;
    (yyval.function).f_typ.args_defs = (yyvsp[-1].function).f_typ.args_defs;
    (yyval.function).f_typ.args_types = (yyvsp[-1].function).f_typ.args_types;
    (yyval.function).f_typ.args_len = (yyvsp[-1].function).f_typ.args_len;
    axo_push_scope(scopes, axo_new_scope(top_scope));
    top_scope->ret_typ = (yyvsp[-4].typ_type);
    axo_code_scope_started = true;
    for (int i = 0; i<(yyval.function).f_typ.args_len; i++)
      axo_set_var(top_scope, (axo_var){.name=(yyval.function).args_names[i], .typ=(yyval.function).f_typ.args_types[i], .is_const=true});
    }
#line 3615 "axo_gram.tab.c"
    break;

  case 131: /* struct_def: "struct" "identifier" '(' func_args ')'  */
#line 1323 "axo_gram.y"
                                                {
    axo_struct_field* fields = (axo_struct_field*)malloc((yyvsp[-1].function).f_typ.args_len*sizeof(axo_struct_field));
    for (int i = 0; i<(yyvsp[-1].function).f_typ.args_len; i++){
      fields[i].name = (yyvsp[-1].function).args_names[i];
      fields[i].def = (axo_expr){.kind=axo_expr_normal_kind, .val=(yyvsp[-1].function).f_typ.args_defs[i], .typ=(yyvsp[-1].function).f_typ.args_types[i]};
    }
    (yyval.struct_type) = (axo_struct){
      .name=alloc_str((yyvsp[-3].str)),
      .fields=fields,
      .fields_len=(yyvsp[-1].function).f_typ.args_len
    };
  }
#line 3632 "axo_gram.tab.c"
    break;

  case 132: /* struct_literal_start: "struct{"  */
#line 1336 "axo_gram.y"
                                            {
    axo_typ_def* td = axo_get_typ_def(state, (yyvsp[0].str));
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
#line 3653 "axo_gram.tab.c"
    break;

  case 133: /* struct_literal_start: "struct{" expr  */
#line 1352 "axo_gram.y"
                              {
    
    axo_typ_def* td = axo_get_typ_def(state, (yyvsp[-1].str));
    if (td==NULL){
      yyerror(&(yylsp[-1]), "Structure type '%s' undefined before usage.", (yyvsp[-1].str));
    }else if (td->typ.kind!=axo_struct_kind){
      yyerror(&(yylsp[-1]), "Type '%s' is not a struture.", (yyvsp[-1].str));
    }else if (!axo_typ_eq(((axo_struct*)(td->typ.structure))->fields[0].def.typ, (yyvsp[0].expression).typ)){
      axo_struct* structure = ((axo_struct*)(td->typ.structure));
      yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[0].def.typ), structure->fields[0].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
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
#line 3679 "axo_gram.tab.c"
    break;

  case 134: /* struct_literal_start: "struct{" "identifier" '=' expr  */
#line 1373 "axo_gram.y"
                                       {
    axo_typ_def* td = axo_get_typ_def(state, (yyvsp[-3].str));
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
      else if (!axo_typ_eq(structure->fields[index].def.typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].def.typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
      }else{
        (yyval.struct_val_type).fields[index] = (yyvsp[0].expression).val;
      }
    }
  }
#line 3714 "axo_gram.tab.c"
    break;

  case 135: /* struct_literal_start: struct_literal_start ',' expr  */
#line 1403 "axo_gram.y"
                                  {
    (yyval.struct_val_type)=(yyvsp[-2].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      yyerror(&(yylsp[0]), "Too many fields provided to structure '%s'.", structure->name);
    }else if (!axo_typ_eq(structure->fields[(yyval.struct_val_type).fields_count].def.typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[(yyval.struct_val_type).fields_count].def.typ), structure->fields[(yyval.struct_val_type).fields_count].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = (yyvsp[0].expression).val;
      (yyval.struct_val_type).fields_count++;
    }else{
      yyerror(&(yylsp[0]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].name);    
    }
  }
#line 3733 "axo_gram.tab.c"
    break;

  case 136: /* struct_literal_start: struct_literal_start ','  */
#line 1417 "axo_gram.y"
                             {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      yyerror(&(yylsp[0]), "Too many fields provided to structure '%s'.", structure->name);
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = ((axo_struct*)((yyvsp[-1].struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].def.val;
      (yyval.struct_val_type).fields_count++;
    }
  }
#line 3748 "axo_gram.tab.c"
    break;

  case 137: /* struct_literal_start: struct_literal_start ',' "identifier" '=' expr  */
#line 1427 "axo_gram.y"
                                           {
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
    else if (!axo_typ_eq(structure->fields[index].def.typ, (yyvsp[0].expression).typ)){
        yyerror(&(yylsp[0]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].def.typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[0].expression).typ));
    }else if ((yyval.struct_val_type).fields[index]==NULL){
      (yyval.struct_val_type).fields[index] = (yyvsp[0].expression).val;
    }else{
      yyerror(&(yylsp[-2]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[index].name);    
    }
  }
#line 3772 "axo_gram.tab.c"
    break;

  case 138: /* struct_literal: struct_literal_start '}'  */
#line 1448 "axo_gram.y"
                                          {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = ((axo_struct*)(yyval.struct_val_type).typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if((yyval.struct_val_type).fields[i] == NULL) (yyval.struct_val_type).fields[i] = structure->fields[i].def.val;
    }
  }
#line 3784 "axo_gram.tab.c"
    break;

  case 139: /* func_def: func_def_start code_scope  */
#line 1457 "axo_gram.y"
                                     {
    (yyval.function) = (yyvsp[-1].function);
    (yyval.function).body = (yyvsp[0].scope);
    (yyval.function).f_typ.ret_typ = axo_is_no_typ((yyvsp[0].scope)->ret_typ) ? axo_mk_simple_typ("void") : (yyvsp[0].scope)->ret_typ;
    axo_func_typ* fnt_ptr = (axo_func_typ*)malloc(sizeof(axo_func_typ));
    *fnt_ptr = (yyval.function).f_typ;
    axo_typ typ = (axo_typ){
      .kind=axo_func_kind,
      .func_typ=fnt_ptr,
      .def=(yyval.function).f_typ.args_defs
    };
    axo_set_var(state->global_scope, (axo_var){.name=(yyval.function).name, .typ=typ, .is_const=true});
  }
#line 3802 "axo_gram.tab.c"
    break;

  case 140: /* func_arg: val_typ "identifier"  */
#line 1472 "axo_gram.y"
                        {
    (yyval.function_argument).name = alloc_str((yyvsp[0].str));
    (yyval.function_argument).typ = (yyvsp[-1].typ_type);
    (yyval.function_argument).def = (yyvsp[-1].typ_type).def;
  }
#line 3812 "axo_gram.tab.c"
    break;

  case 141: /* func_arg: "identifier" '|' expr  */
#line 1477 "axo_gram.y"
                  {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[0].expression).typ;
    (yyval.function_argument).def = (yyvsp[0].expression).val;
  }
#line 3822 "axo_gram.tab.c"
    break;

  case 142: /* func_arg: val_typ "identifier" '|' expr  */
#line 1482 "axo_gram.y"
                          {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[-3].typ_type);
    (yyval.function_argument).def = (yyvsp[0].expression).val; //FIX! Look if types match!
  }
#line 3832 "axo_gram.tab.c"
    break;

  case 143: /* func_args: %empty  */
#line 1489 "axo_gram.y"
                            {
    (yyval.function).args_names = NULL;
    (yyval.function).f_typ.args_defs = NULL;
    (yyval.function).f_typ.args_types = NULL;
    (yyval.function).f_typ.args_len = 0;
  }
#line 3843 "axo_gram.tab.c"
    break;

  case 144: /* func_args: func_arg  */
#line 1495 "axo_gram.y"
             {
    (yyval.function).args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.function).args_names[0] = (yyvsp[0].function_argument).name;
    (yyval.function).f_typ.args_defs[0] = (yyvsp[0].function_argument).def;
    (yyval.function).f_typ.args_types[0] = (yyvsp[0].function_argument).typ;
    (yyval.function).f_typ.args_len = 1;
  }
#line 3857 "axo_gram.tab.c"
    break;

  case 145: /* func_args: func_args ',' func_arg  */
#line 1504 "axo_gram.y"
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
#line 3872 "axo_gram.tab.c"
    break;

  case 146: /* enum_names: "identifier"  */
#line 1516 "axo_gram.y"
                  {
    (yyval.enum_type).names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    (yyval.enum_type).names[0] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len = 1;
  }
#line 3882 "axo_gram.tab.c"
    break;

  case 147: /* enum_names: enum_names ',' "identifier"  */
#line 1521 "axo_gram.y"
                        {
    (yyval.enum_type) = (yyvsp[-2].enum_type);
    if ((yyval.enum_type).len % axo_enum_names_cap == 0)
    (yyval.enum_type).names = (char**)realloc((yyval.enum_type).names, ((yyval.enum_type).len+axo_enum_names_cap)*sizeof(char*));
    (yyval.enum_type).names[(yyval.enum_type).len] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len++;
  }
#line 3894 "axo_gram.tab.c"
    break;


#line 3898 "axo_gram.tab.c"

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

#line 1530 "axo_gram.y"


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
  axo_typ typ = (axo_typ){
    .kind=axo_simple_kind,
    .simple=alloc_str("int")
  };
  
  printf("Playground:"axo_magenta_fg"\n%s\n", axo_typ_to_ctyp_str(typ));
  return 0;
}

int main(int argc, char** argv) {
  if (test_playground) return playground();
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
