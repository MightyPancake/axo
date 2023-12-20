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
  YYSYMBOL_IF_KWRD = 16,                   /* "if"  */
  YYSYMBOL_ELSE_KWRD = 17,                 /* "else"  */
  YYSYMBOL_EQ_OP = 18,                     /* "=="  */
  YYSYMBOL_INEQ_OP = 19,                   /* "!="  */
  YYSYMBOL_EQ_SMLR_OP = 20,                /* ">="  */
  YYSYMBOL_EQ_GRTR_OP = 21,                /* "<="  */
  YYSYMBOL_LOGICAL_OR_OP = 22,             /* "||"  */
  YYSYMBOL_LOGICAL_AND_OP = 23,            /* "&&"  */
  YYSYMBOL_LEFT_SHIFT_OP = 24,             /* "<<"  */
  YYSYMBOL_RIGHT_SHIFT_OP = 25,            /* ">>"  */
  YYSYMBOL_TILL_KWRD = 26,                 /* "till"  */
  YYSYMBOL_INCR_OP = 27,                   /* "++"  */
  YYSYMBOL_DECR_OP = 28,                   /* "--"  */
  YYSYMBOL_ENUM_KWRD = 29,                 /* "enum"  */
  YYSYMBOL_STRUCT_KWRD = 30,               /* "struct"  */
  YYSYMBOL_STRUCT_LITERAL_START = 31,      /* "struct{"  */
  YYSYMBOL_DOT_FIELD = 32,                 /* ".field"  */
  YYSYMBOL_ARROW_OP = 33,                  /* "->"  */
  YYSYMBOL_IS_KWRD = 34,                   /* "is"  */
  YYSYMBOL_IDENTIFIER_PREC = 35,           /* IDENTIFIER_PREC  */
  YYSYMBOL_36_ = 36,                       /* '$'  */
  YYSYMBOL_EXPR_AS_STATEMENT = 37,         /* EXPR_AS_STATEMENT  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '?'  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '@'  */
  YYSYMBOL_50_ = 50,                       /* '^'  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_STRUCT_LIT_NAMED_FIELD = 52,    /* STRUCT_LIT_NAMED_FIELD  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '.'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_declarations = 61,              /* declarations  */
  YYSYMBOL_statements = 62,                /* statements  */
  YYSYMBOL_multi_statement = 63,           /* multi_statement  */
  YYSYMBOL_identifier = 64,                /* identifier  */
  YYSYMBOL_incr_decr_op = 65,              /* incr_decr_op  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_matching_statement = 68,        /* matching_statement  */
  YYSYMBOL_if_condition = 69,              /* if_condition  */
  YYSYMBOL_matching_if_statement = 70,     /* matching_if_statement  */
  YYSYMBOL_non_matching_statement = 71,    /* non_matching_statement  */
  YYSYMBOL_non_matching_if_statement = 72, /* non_matching_if_statement  */
  YYSYMBOL_till_loop_start = 73,           /* till_loop_start  */
  YYSYMBOL_while_loop_base = 74,           /* while_loop_base  */
  YYSYMBOL_matching_while = 75,            /* matching_while  */
  YYSYMBOL_non_matching_while = 76,        /* non_matching_while  */
  YYSYMBOL_non_matching_for_loop = 77,     /* non_matching_for_loop  */
  YYSYMBOL_matching_for_loop = 78,         /* matching_for_loop  */
  YYSYMBOL_for_loop_start = 79,            /* for_loop_start  */
  YYSYMBOL_for_loop_init = 80,             /* for_loop_init  */
  YYSYMBOL_for_loop_base = 81,             /* for_loop_base  */
  YYSYMBOL_assign_op = 82,                 /* assign_op  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_stat_arr_init_dims = 84,        /* stat_arr_init_dims  */
  YYSYMBOL_stat_arr_init = 85,             /* stat_arr_init  */
  YYSYMBOL_stat_arr_literal_start = 86,    /* stat_arr_literal_start  */
  YYSYMBOL_stat_arr_literal = 87,          /* stat_arr_literal  */
  YYSYMBOL_stat_arr_typ = 88,              /* stat_arr_typ  */
  YYSYMBOL_dyn_arr_typ = 89,               /* dyn_arr_typ  */
  YYSYMBOL_func_typ_start = 90,            /* func_typ_start  */
  YYSYMBOL_func_typ_args = 91,             /* func_typ_args  */
  YYSYMBOL_func_typ = 92,                  /* func_typ  */
  YYSYMBOL_val_typ = 93,                   /* val_typ  */
  YYSYMBOL_c_typ = 94,                     /* c_typ  */
  YYSYMBOL_c_typ_list = 95,                /* c_typ_list  */
  YYSYMBOL_func_call_start = 96,           /* func_call_start  */
  YYSYMBOL_func_call = 97,                 /* func_call  */
  YYSYMBOL_code_scope_start = 98,          /* code_scope_start  */
  YYSYMBOL_code_scope = 99,                /* code_scope  */
  YYSYMBOL_func_def_start = 100,           /* func_def_start  */
  YYSYMBOL_struct_def = 101,               /* struct_def  */
  YYSYMBOL_struct_literal_start = 102,     /* struct_literal_start  */
  YYSYMBOL_struct_literal = 103,           /* struct_literal  */
  YYSYMBOL_func_def = 104,                 /* func_def  */
  YYSYMBOL_func_arg = 105,                 /* func_arg  */
  YYSYMBOL_func_args = 106,                /* func_args  */
  YYSYMBOL_enum_names = 107                /* enum_names  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   837

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,    36,    47,     2,     2,
      38,    53,    45,    43,    56,    44,    57,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      41,    39,    42,    40,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    55,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      35,    37,    48,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   141,   144,   147,   166,   200,   227,   228,
     229,   232,   269,   286,   290,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   313,   314,   350,   365,
     366,   369,   376,   383,   390,   397,   404,   411,   420,   429,
     438,   447,   470,   491,   536,   557,   560,   560,   562,   568,
     573,   585,   588,   600,   607,   614,   615,   616,   619,   625,
     630,   631,   632,   635,   638,   643,   653,   660,   669,   678,
     687,   696,   701,   706,   717,   727,   732,   758,   774,   788,
     817,   825,   838,   841,   851,   861,   872,   885,   894,   905,
     906,   909,   916,   922,   923,   924,   930,   934,   939,   945,
     949,   954,   965,   985,  1012,  1028,  1043,  1060,  1066,  1072,
    1083,  1097,  1110,  1126,  1147,  1177,  1191,  1201,  1222,  1231,
    1246,  1251,  1256,  1263,  1269,  1278,  1290,  1295
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
  "\"#register\"", "\"fn\"", "\"while\"", "\"for\"", "\"if\"", "\"else\"",
  "\"==\"", "\"!=\"", "\">=\"", "\"<=\"", "\"||\"", "\"&&\"", "\"<<\"",
  "\">>\"", "\"till\"", "\"++\"", "\"--\"", "\"enum\"", "\"struct\"",
  "\"struct{\"", "\".field\"", "\"->\"", "\"is\"", "IDENTIFIER_PREC",
  "'$'", "EXPR_AS_STATEMENT", "'('", "'='", "'?'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMINUS", "'@'", "'^'", "'['",
  "STRUCT_LIT_NAMED_FIELD", "')'", "':'", "']'", "','", "'.'", "'{'",
  "'}'", "$accept", "declarations", "statements", "multi_statement",
  "identifier", "incr_decr_op", "expr", "statement", "matching_statement",
  "if_condition", "matching_if_statement", "non_matching_statement",
  "non_matching_if_statement", "till_loop_start", "while_loop_base",
  "matching_while", "non_matching_while", "non_matching_for_loop",
  "matching_for_loop", "for_loop_start", "for_loop_init", "for_loop_base",
  "assign_op", "assignment", "stat_arr_init_dims", "stat_arr_init",
  "stat_arr_literal_start", "stat_arr_literal", "stat_arr_typ",
  "dyn_arr_typ", "func_typ_start", "func_typ_args", "func_typ", "val_typ",
  "c_typ", "c_typ_list", "func_call_start", "func_call",
  "code_scope_start", "code_scope", "func_def_start", "struct_def",
  "struct_literal_start", "struct_literal", "func_def", "func_arg",
  "func_args", "enum_names", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -153,    41,  -153,  -153,    -1,     8,    26,    30,   -20,  -153,
    -153,  -153,   -17,    19,    22,   101,    43,     3,  -153,  -153,
      27,   -19,  -153,    56,    29,    31,  -153,  -153,  -153,    25,
      55,  -153,    66,  -153,  -153,    78,  -153,    63,    43,  -153,
    -153,  -153,    43,    82,   104,    66,   139,  -153,    -1,    95,
     145,  -153,   -11,  -153,    43,  -153,  -153,    66,  -153,    -9,
      21,  -153,  -153,  -153,  -153,   158,  -153,  -153,   119,  -153,
     158,   120,   188,   158,    17,   158,   158,  -153,  -153,  -153,
    -153,   553,  -153,  -153,   196,  -153,  -153,  -153,  -153,   196,
    -153,  -153,  -153,  -153,   121,   110,   196,  -153,   -40,  -153,
      53,  -153,    72,  -153,  -153,    73,  -153,   115,    77,   158,
     113,  -153,    66,  -153,    85,  -153,   162,  -153,   753,   158,
     753,   165,   133,   587,   587,   158,   373,    84,   587,   158,
     158,   158,   158,   158,   158,   158,   158,  -153,  -153,  -153,
      43,   158,  -153,   158,   158,   158,   158,   158,   158,   158,
    -153,   158,   210,   553,  -153,   156,  -153,  -153,   196,   158,
    -153,  -153,   168,  -153,  -153,   158,  -153,   158,   225,  -153,
    -153,    -1,   587,   158,  -153,  -153,  -153,   158,   409,   137,
     158,   445,   158,  -153,   777,   777,   719,   719,   655,   689,
     786,   786,  -153,   587,   719,   719,   243,   243,   193,   193,
     193,   298,   158,   621,   196,  -153,   259,   147,   587,   587,
     143,   587,   115,   587,  -153,   158,   587,  -153,   336,  -153,
     150,  -153,  -153,   196,   174,   158,   481,   158,   180,   132,
     131,   587,  -153,   517,   140,  -153,  -153,  -153,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     4,     0,     0,     0,     0,     0,     7,
       3,    96,     0,     0,    91,     0,     0,     0,    93,    95,
       0,     0,    94,     0,     0,     0,   107,     8,   119,     0,
       0,    97,   123,    91,    86,     0,    92,     0,     0,    89,
      87,    90,     0,     0,     0,   123,     0,    98,    99,    91,
       0,   124,     0,    85,     0,    84,    88,   123,   126,     0,
       0,    15,    16,    17,    12,     0,    54,    53,     0,    71,
       0,     0,   112,     0,     0,     0,     0,   108,    10,    27,
      45,    48,     9,    46,     0,    55,    47,    60,    74,     0,
      57,    62,    61,    56,     0,     0,     0,    26,     0,    11,
       0,    44,     0,    29,    51,     0,    41,   100,     0,     0,
     120,   109,     0,    83,     0,     6,     0,   111,    50,     0,
      58,     0,    12,   113,    49,     0,     0,    25,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    43,
       0,   102,    75,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,    48,    63,    46,    67,    68,     0,     0,
      70,    69,     0,    79,    82,     0,   106,   105,   116,   118,
       5,     0,   121,     0,   125,   110,   127,     0,     0,     0,
       0,     0,     0,    24,    33,    34,    35,    36,    37,    38,
      39,    40,    52,   103,    31,    32,    18,    19,    21,    22,
      23,     0,     0,    76,     0,    72,     0,     0,    81,   104,
      12,   115,   101,   122,    66,     0,   114,    20,     0,    42,
      27,    59,    64,     0,     0,     0,     0,     0,     0,     0,
       0,   117,    65,     0,     0,    73,    78,    28,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -153,  -152,  -153,   -46,   -83,   -80,  -153,
    -153,   -81,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,   106,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,    -3,   -45,  -153,  -153,  -153,  -153,    -2,
    -153,  -153,  -153,  -153,  -153,    94,   -14,  -153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    46,    78,    79,    80,   153,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   177,    97,    98,    99,   100,   101,    18,    19,
      20,    21,    22,    50,    13,   108,   102,   103,    27,   104,
       8,     9,   105,   106,    10,    51,    52,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,   154,    23,   107,   155,    11,    28,    37,   157,   156,
     207,   162,    35,    36,    14,   161,   160,    40,    26,   118,
      61,    62,    63,    64,   120,    30,   123,   124,   126,   127,
     128,    60,    24,    33,    41,    55,    25,    42,    26,    56,
      29,     2,   111,   114,   115,   112,    15,   116,    72,    33,
     220,   113,     3,     4,     5,    74,    12,    16,    38,    17,
      32,   125,    43,   172,    31,    15,    75,    44,    76,    45,
       6,     7,    49,   178,   117,   205,    16,   112,    17,   181,
      39,    15,    47,   184,   185,   186,   187,   188,   189,   190,
     191,    53,    16,    48,    17,   193,   163,   194,   195,   196,
     197,   198,   199,   200,    15,   201,   203,    33,   164,   165,
      58,   137,   138,   206,    34,    16,   139,    17,    54,   208,
      57,   209,   211,   222,   221,   166,   212,   213,   167,   168,
     170,   203,   169,   171,   216,   151,   218,   192,   175,    15,
     229,   112,    61,    62,    63,    64,    65,    66,    67,   109,
      16,   110,    17,    68,    69,    70,   128,   119,   121,   158,
      31,    61,    62,    63,    64,    71,   159,   173,   176,   226,
      72,   179,   180,   204,    64,    73,   215,    74,   230,   231,
     224,   233,   225,   228,   234,   235,   236,   152,    75,    72,
      76,    61,    62,    63,   122,   238,    74,    26,    77,    61,
      62,    63,    64,    65,    66,    67,   174,    75,     0,    76,
      68,    69,    70,    61,    62,    63,    64,     0,     0,    72,
     137,   138,    71,     0,     0,   139,    74,    72,    61,    62,
      63,   210,    73,     0,    74,     0,     0,    75,     0,    76,
       0,    72,     0,   150,   151,    75,     0,    76,    74,     0,
       0,     0,     0,     0,    26,     0,    72,     0,     0,    75,
       0,   202,     0,    74,     0,     0,     0,     0,     0,     0,
     137,   138,     0,     0,    75,   139,    76,   129,   130,   131,
     132,   133,   134,   135,   136,     0,   137,   138,   147,   148,
     149,   139,     0,   150,   151,     0,     0,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,     0,     0,     0,     0,   223,   129,   130,   131,   132,
     133,   134,   135,   136,     0,   137,   138,     0,     0,     0,
     139,     0,     0,     0,     0,     0,   141,   142,     0,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,     0,   219,   129,   130,   131,   132,   133,   134,
     135,   136,     0,   137,   138,     0,     0,     0,   139,     0,
       0,     0,     0,     0,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,     0,
     227,   129,   130,   131,   132,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   141,   142,   182,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,     0,   183,   129,   130,   131,
     132,   133,   134,   135,   136,     0,   137,   138,     0,     0,
       0,   139,     0,     0,     0,     0,     0,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,     0,   214,   129,   130,   131,   132,   133,   134,   135,
     136,     0,   137,   138,     0,     0,     0,   139,     0,     0,
       0,     0,     0,   141,   142,     0,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,     0,   217,   129,
     130,   131,   132,   133,   134,   135,   136,     0,   137,   138,
       0,     0,     0,   139,     0,     0,     0,     0,     0,   141,
     142,     0,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,     0,   232,   129,   130,   131,   132,   133,
     134,   135,   136,     0,   137,   138,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,     0,
     237,   129,   130,   131,   132,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,   139,     0,   140,     0,     0,
       0,   141,   142,     0,   143,   144,   145,   146,   147,   148,
     149,     0,     0,   150,   151,   129,   130,   131,   132,   133,
     134,   135,   136,     0,   137,   138,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   129,
     130,   131,   132,   133,   134,   135,   136,     0,   137,   138,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   129,   130,   131,   132,     0,   134,   135,
     136,     0,   137,   138,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   129,   130,   131,
     132,     0,     0,   135,   136,     0,   137,   138,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   129,   130,   150,
     151,     0,     0,   135,   136,     0,   137,   138,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   129,   130,   131,   132,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,   139,     0,     0,     0,     0,
       0,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   135,   136,   150,   137,   138,     0,     0,     0,   139,
       0,     0,     0,   137,   138,     0,     0,     0,   139,     0,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   145,
     146,   147,   148,   149,     0,     0,   150,   151
};

static const yytype_int16 yycheck[] =
{
      46,    84,     5,    48,    84,     6,     8,     4,    89,    89,
     162,    51,    15,    16,     6,    96,    96,    20,    58,    65,
       3,     4,     5,     6,    70,     6,    72,    73,    74,    75,
      76,    45,     6,     6,    53,    38,     6,    56,    58,    42,
      57,     0,    53,    57,    53,    56,    38,    56,    31,     6,
     202,    54,    11,    12,    13,    38,    57,    49,    55,    51,
      38,    44,     6,   109,    45,    38,    49,    38,    51,    38,
      29,    30,     6,   119,    53,   158,    49,    56,    51,   125,
      53,    38,    57,   129,   130,   131,   132,   133,   134,   135,
     136,    13,    49,    38,    51,   141,    98,   143,   144,   145,
     146,   147,   148,   149,    38,   151,   152,     6,    55,    56,
       6,    27,    28,   159,    13,    49,    32,    51,    55,   165,
      38,   167,   168,   204,   204,    53,   171,   173,    56,    56,
      53,   177,    59,    56,   180,    51,   182,   140,    53,    38,
     223,    56,     3,     4,     5,     6,     7,     8,     9,    54,
      49,     6,    51,    14,    15,    16,   202,    38,    38,    38,
      45,     3,     4,     5,     6,    26,    56,    54,     6,   215,
      31,     6,    39,    17,     6,    36,    39,    38,     4,   225,
      33,   227,    39,    33,     4,    53,    55,    81,    49,    31,
      51,     3,     4,     5,     6,    55,    38,    58,    59,     3,
       4,     5,     6,     7,     8,     9,   112,    49,    -1,    51,
      14,    15,    16,     3,     4,     5,     6,    -1,    -1,    31,
      27,    28,    26,    -1,    -1,    32,    38,    31,     3,     4,
       5,     6,    36,    -1,    38,    -1,    -1,    49,    -1,    51,
      -1,    31,    -1,    50,    51,    49,    -1,    51,    38,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    31,    -1,    -1,    49,
      -1,    51,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    49,    32,    51,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    45,    46,
      47,    32,    -1,    50,    51,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    50,    51,
      -1,    -1,    -1,    55,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    50,    51,    -1,    -1,
      54,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    50,    51,    -1,    53,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
      51,    -1,    53,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    51,    -1,    53,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    51,    -1,    53,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    50,    51,    -1,
      53,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    50,    51,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    50,    51,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    51,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    51,    18,    19,    20,
      21,    -1,    -1,    24,    25,    -1,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    18,    19,    50,
      51,    -1,    -1,    24,    25,    -1,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    -1,    50,
      51,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    24,    25,    50,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      43,    44,    45,    46,    47,    -1,    -1,    50,    51,    43,
      44,    45,    46,    47,    -1,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,     0,    11,    12,    13,    29,    30,   100,   101,
     104,     6,    57,    94,     6,    38,    49,    51,    88,    89,
      90,    91,    92,    93,     6,     6,    58,    98,    99,    57,
       6,    45,    38,     6,    13,    93,    93,     4,    55,    53,
      93,    53,    56,     6,    38,    38,    62,    57,    38,     6,
      93,   105,   106,    13,    55,    93,    93,    38,     6,   107,
     106,     3,     4,     5,     6,     7,     8,     9,    14,    15,
      16,    26,    31,    36,    38,    49,    51,    59,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    96,    97,    99,   102,   103,    94,    95,    54,
       6,    53,    56,    93,   106,    53,    56,    53,    66,    38,
      66,    38,     6,    66,    66,    44,    66,    66,    66,    18,
      19,    20,    21,    22,    23,    24,    25,    27,    28,    32,
      34,    38,    39,    41,    42,    43,    44,    45,    46,    47,
      50,    51,    82,    66,    67,    68,    68,    71,    38,    56,
      68,    71,    51,    99,    55,    56,    53,    56,    56,    59,
      53,    56,    66,    54,   105,    53,     6,    82,    66,     6,
      39,    66,    40,    53,    66,    66,    66,    66,    66,    66,
      66,    66,    93,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    51,    66,    17,    67,    66,    64,    66,    66,
       6,    66,    94,    66,    53,    39,    66,    53,    66,    55,
      64,    68,    71,    56,    33,    39,    66,    54,    33,    67,
       4,    66,    53,    66,     4,    53,    55,    53,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      71,    71,    71,    72,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    81,    82,    83,    84,    84,    85,
      86,    86,    87,    88,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    97,    98,    99,   100,
     100,   101,   102,   102,   102,   102,   102,   102,   103,   104,
     105,   105,   105,   106,   106,   106,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     7,     6,     2,     0,     2,
       2,     1,     1,     2,     2,     1,     1,     1,     3,     3,
       4,     3,     3,     3,     3,     2,     1,     1,     7,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     2,     4,
       1,     1,     1,     2,     4,     6,     4,     2,     2,     2,
       2,     1,     3,     6,     1,     1,     3,     7,     6,     2,
       2,     3,     2,     4,     3,     3,     2,     2,     3,     2,
       2,     1,     2,     1,     1,     1,     1,     2,     3,     0,
       1,     3,     2,     3,     3,     2,     2,     1,     3,     5,
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
#line 140 "axo_gram.y"
                           {}
#line 1892 "axo_gram.tab.c"
    break;

  case 3: /* declarations: declarations func_def  */
#line 141 "axo_gram.y"
                          {
    axo_add_decl(state, axo_func_def_to_decl((yyvsp[0].function)));
  }
#line 1900 "axo_gram.tab.c"
    break;

  case 4: /* declarations: declarations "#include"  */
#line 144 "axo_gram.y"
                           { //Fix: Check if file exists
    axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", (yyvsp[0].str)), .kind=axo_c_include_decl_kind});
  }
#line 1908 "axo_gram.tab.c"
    break;

  case 5: /* declarations: declarations "#register" c_typ "identifier" '(' c_typ_list ')'  */
#line 147 "axo_gram.y"
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
#line 1932 "axo_gram.tab.c"
    break;

  case 6: /* declarations: declarations "enum" "identifier" '(' enum_names ')'  */
#line 166 "axo_gram.y"
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
#line 1971 "axo_gram.tab.c"
    break;

  case 7: /* declarations: declarations struct_def  */
#line 200 "axo_gram.y"
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
#line 2001 "axo_gram.tab.c"
    break;

  case 8: /* statements: %empty  */
#line 227 "axo_gram.y"
                         {}
#line 2007 "axo_gram.tab.c"
    break;

  case 9: /* statements: statements statement  */
#line 228 "axo_gram.y"
                         {axo_add_statement(top_scope, (yyvsp[0].statement_type));}
#line 2013 "axo_gram.tab.c"
    break;

  case 10: /* statements: statements multi_statement  */
#line 229 "axo_gram.y"
                               {axo_add_statement(top_scope, (yyvsp[0].statement_type));}
#line 2019 "axo_gram.tab.c"
    break;

  case 11: /* multi_statement: stat_arr_init  */
#line 232 "axo_gram.y"
                                {
    axo_typ typ = (yyvsp[0].stat_arr_init_type).code->ret_typ;
    char* ret_arr = top_scope->ret_assign;
    for (int i=0; i<(yyvsp[0].stat_arr_init_type).len; i++){
      asprintf(&ret_arr, "%s[%s]", ret_arr, (yyvsp[0].stat_arr_init_type).iters[i]);
    }
    for (int i=0; i<(yyvsp[0].stat_arr_init_type).code->statements_len; i++){
      if ((yyvsp[0].stat_arr_init_type).code->statements[i].kind==axo_ret_statement_kind){
        char* new_ret = fmtstr("%s = %s;", ret_arr, &(((yyvsp[0].stat_arr_init_type).code->statements[i].val)[6]));
        free((yyvsp[0].stat_arr_init_type).code->statements[i].val);
        (yyvsp[0].stat_arr_init_type).code->statements[i].val = new_ret;
      }
    }
    for (int i=(yyvsp[0].stat_arr_init_type).len-1; i>=0; i--){
      axo_arr* arr_ptr = alloc_one(axo_arr);
      arr_ptr->sz = (yyvsp[0].stat_arr_init_type).dims[i];
      arr_ptr->typ=typ;
      typ.arr = arr_ptr;
      typ.kind = axo_stat_arr_kind;
    }
    char* arr_decl = axo_name_typ_decl((yyvsp[0].stat_arr_init_type).lval.val, typ);
    char* arr_init = empty_str;
    for (int i=0; i<(yyvsp[0].stat_arr_init_type).len; i++){
      char* for_body = fmtstr("for (int %s=0; %s<%d; %s++)\n", (yyvsp[0].stat_arr_init_type).iters[i], (yyvsp[0].stat_arr_init_type).iters[i], (yyvsp[0].stat_arr_init_type).dims[i], (yyvsp[0].stat_arr_init_type).iters[i]);
      strapnd(&arr_init, for_body);
      free(for_body);
    }
    strapnd(&arr_init, axo_scope_to_statement((yyvsp[0].stat_arr_init_type).code).val);
    (yyval.statement_type) = (axo_statement){
      .kind=axo_stat_arr_init_statement_kind,
      .val=fmtstr("%s;\n%s", arr_decl, arr_init)
    };
    free(arr_init);
    free(arr_decl);
  }
#line 2059 "axo_gram.tab.c"
    break;

  case 12: /* identifier: "identifier"  */
#line 269 "axo_gram.y"
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
#line 2079 "axo_gram.tab.c"
    break;

  case 13: /* incr_decr_op: expr "++"  */
#line 286 "axo_gram.y"
                            {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s++", (yyvsp[-1].expression).val);
  }
#line 2088 "axo_gram.tab.c"
    break;

  case 14: /* incr_decr_op: expr "--"  */
#line 290 "axo_gram.y"
                 {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s--", (yyvsp[-1].expression).val);
  }
#line 2097 "axo_gram.tab.c"
    break;

  case 15: /* expr: "string literal"  */
#line 296 "axo_gram.y"
                      {set_val(&(yyval.expression), axo_mk_simple_typ("char*"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind;}
#line 2103 "axo_gram.tab.c"
    break;

  case 16: /* expr: "integer literal"  */
#line 297 "axo_gram.y"
                    {set_val(&(yyval.expression), axo_mk_simple_typ("int"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; }
#line 2109 "axo_gram.tab.c"
    break;

  case 17: /* expr: "float literal"  */
#line 298 "axo_gram.y"
                  {set_val(&(yyval.expression), axo_mk_simple_typ("float"), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; }
#line 2115 "axo_gram.tab.c"
    break;

  case 18: /* expr: expr '+' expr  */
#line 299 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "+", (yyvsp[0].expression)); }
#line 2121 "axo_gram.tab.c"
    break;

  case 19: /* expr: expr '-' expr  */
#line 300 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "-", (yyvsp[0].expression)); }
#line 2127 "axo_gram.tab.c"
    break;

  case 20: /* expr: '(' '-' expr ')'  */
#line 301 "axo_gram.y"
                     {asprintf(&((yyval.expression).val), "-%s", (yyvsp[-1].expression).val); (yyval.expression).typ = (yyvsp[-1].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2133 "axo_gram.tab.c"
    break;

  case 21: /* expr: expr '*' expr  */
#line 302 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "*", (yyvsp[0].expression)); }
#line 2139 "axo_gram.tab.c"
    break;

  case 22: /* expr: expr '/' expr  */
#line 303 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "/", (yyvsp[0].expression)); }
#line 2145 "axo_gram.tab.c"
    break;

  case 23: /* expr: expr '%' expr  */
#line 304 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "%", (yyvsp[0].expression)); }
#line 2151 "axo_gram.tab.c"
    break;

  case 24: /* expr: '(' expr ')'  */
#line 305 "axo_gram.y"
                 {asprintf(&((yyval.expression).val), "(%s)", (yyvsp[-1].expression).val); (yyval.expression).typ = (yyvsp[-1].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2157 "axo_gram.tab.c"
    break;

  case 25: /* expr: '@' expr  */
#line 306 "axo_gram.y"
             {
    (yyval.expression).typ.kind = axo_ptr_kind;
    (yyval.expression).typ.ptr = malloc(sizeof(axo_ptr));
    axo_ptr* ptr = (axo_ptr*)((yyval.expression).typ.ptr);
    ptr->typ = (yyvsp[0].expression).typ;
    asprintf(&((yyval.expression).val), "&%s", (yyvsp[0].expression).val);
  }
#line 2169 "axo_gram.tab.c"
    break;

  case 27: /* expr: identifier  */
#line 314 "axo_gram.y"
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
#line 2210 "axo_gram.tab.c"
    break;

  case 28: /* expr: '(' expr '?' expr ':' expr ')'  */
#line 350 "axo_gram.y"
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
#line 2230 "axo_gram.tab.c"
    break;

  case 29: /* expr: func_call  */
#line 365 "axo_gram.y"
              {(yyval.expression) = axo_call_to_expr((yyvsp[0].function_call));}
#line 2236 "axo_gram.tab.c"
    break;

  case 30: /* expr: expr '^'  */
#line 366 "axo_gram.y"
             {
    (yyval.expression)=(yyvsp[-1].expression); //FIX!
  }
#line 2244 "axo_gram.tab.c"
    break;

  case 31: /* expr: expr '<' expr  */
#line 369 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2256 "axo_gram.tab.c"
    break;

  case 32: /* expr: expr '>' expr  */
#line 376 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2268 "axo_gram.tab.c"
    break;

  case 33: /* expr: expr "==" expr  */
#line 383 "axo_gram.y"
                    {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s==%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2280 "axo_gram.tab.c"
    break;

  case 34: /* expr: expr "!=" expr  */
#line 390 "axo_gram.y"
                      {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s!=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2292 "axo_gram.tab.c"
    break;

  case 35: /* expr: expr ">=" expr  */
#line 397 "axo_gram.y"
                         {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s>=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2304 "axo_gram.tab.c"
    break;

  case 36: /* expr: expr "<=" expr  */
#line 404 "axo_gram.y"
                         {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_mk_simple_typ("bool"),
      .val = fmtstr("%s<=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2316 "axo_gram.tab.c"
    break;

  case 37: /* expr: expr "||" expr  */
#line 411 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s||%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2330 "axo_gram.tab.c"
    break;

  case 38: /* expr: expr "&&" expr  */
#line 420 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s&&%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2344 "axo_gram.tab.c"
    break;

  case 39: /* expr: expr "<<" expr  */
#line 429 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s<<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2358 "axo_gram.tab.c"
    break;

  case 40: /* expr: expr ">>" expr  */
#line 438 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s>>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2372 "axo_gram.tab.c"
    break;

  case 41: /* expr: struct_literal  */
#line 447 "axo_gram.y"
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
#line 2400 "axo_gram.tab.c"
    break;

  case 42: /* expr: expr '[' expr ']'  */
#line 470 "axo_gram.y"
                     {
    axo_arr* arr;
    switch((yyvsp[-3].expression).typ.kind){
      case axo_stat_arr_kind:
        arr = (axo_arr*)((yyvsp[-3].expression).typ.arr);
        (yyval.expression).typ = arr->typ;
        (yyval.expression).val = fmtstr("%s[%s]", (yyvsp[-3].expression).val, (yyvsp[-1].expression).val);
        (yyval.expression).lval_kind = ((yyvsp[-3].expression).lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        break;
      case axo_dyn_arr_kind:
        arr = (axo_arr*)((yyvsp[-3].expression).typ.arr);
        (yyval.expression).typ = arr->typ;
        (yyval.expression).val = fmtstr("%s[%s]", (yyvsp[-3].expression).val, (yyvsp[-1].expression).val);
        (yyval.expression).lval_kind = ((yyvsp[-3].expression).lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        break;
      default:
        yyerror(&(yylsp[-3]), "Cannot index an expression of type '%s'.", axo_typ_to_str((yyvsp[-3].expression).typ));
        break;
    }
    (yyval.expression).kind=axo_expr_normal_kind;
  }
#line 2426 "axo_gram.tab.c"
    break;

  case 43: /* expr: expr ".field"  */
#line 491 "axo_gram.y"
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
        if ((yyvsp[-1].expression).typ.kind==axo_struct_kind){
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
        }else{
          yyerror(&(yyloc), "Cannot get field of type '%s'", axo_typ_to_str((yyvsp[-1].expression).typ));
        }
        break;
    }
  }
#line 2476 "axo_gram.tab.c"
    break;

  case 44: /* expr: stat_arr_literal  */
#line 536 "axo_gram.y"
                     {
    char* val = alloc_str("{");
    for (int i=0; i<(yyvsp[0].stat_arr_val_type).len; i++){
      if (i>0) strapnd(&val, ",");
      strapnd(&val, (yyvsp[0].stat_arr_val_type).data[i]);
    }
    strapnd(&val, "}");
    axo_arr* arr_ptr = alloc_one(axo_arr);
    *arr_ptr = (axo_arr){
      .typ=(yyvsp[0].stat_arr_val_type).typ,
      .sz=(yyvsp[0].stat_arr_val_type).len
    };
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .typ=(axo_typ){
        .kind=axo_stat_arr_kind,
        .arr=arr_ptr
      },
      .val=val
    };
  }
#line 2502 "axo_gram.tab.c"
    break;

  case 48: /* matching_statement: expr  */
#line 562 "axo_gram.y"
                          {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2513 "axo_gram.tab.c"
    break;

  case 49: /* matching_statement: '$' expr  */
#line 568 "axo_gram.y"
             {
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2523 "axo_gram.tab.c"
    break;

  case 50: /* matching_statement: "ret" expr  */
#line 573 "axo_gram.y"
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
#line 2540 "axo_gram.tab.c"
    break;

  case 51: /* matching_statement: code_scope  */
#line 585 "axo_gram.y"
               {
    (yyval.statement_type) = axo_scope_to_statement((yyvsp[0].scope));
  }
#line 2548 "axo_gram.tab.c"
    break;

  case 52: /* matching_statement: expr "is" val_typ  */
#line 588 "axo_gram.y"
                         {
    if ((yyvsp[-2].expression).lval_kind == axo_var_lval_kind){
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
#line 2565 "axo_gram.tab.c"
    break;

  case 53: /* matching_statement: "continue"  */
#line 600 "axo_gram.y"
               {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to continue.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = "continue;"
    };
  }
#line 2577 "axo_gram.tab.c"
    break;

  case 54: /* matching_statement: "break"  */
#line 607 "axo_gram.y"
            {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to break out of.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = "break;"
    };
  }
#line 2589 "axo_gram.tab.c"
    break;

  case 58: /* if_condition: "if" expr  */
#line 619 "axo_gram.y"
                            {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2598 "axo_gram.tab.c"
    break;

  case 59: /* matching_if_statement: if_condition matching_statement "else" matching_statement  */
#line 625 "axo_gram.y"
                                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2606 "axo_gram.tab.c"
    break;

  case 63: /* non_matching_if_statement: if_condition statement  */
#line 635 "axo_gram.y"
                                                   {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s", (yyvsp[-1].expression).val, (yyvsp[0].statement_type).val);
  }
#line 2614 "axo_gram.tab.c"
    break;

  case 64: /* non_matching_if_statement: if_condition matching_statement "else" non_matching_statement  */
#line 638 "axo_gram.y"
                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2622 "axo_gram.tab.c"
    break;

  case 65: /* till_loop_start: "till" '(' "identifier" '=' expr ')'  */
#line 643 "axo_gram.y"
                                                   {
    (yyval.till_loop_type).iter = (yyvsp[-3].str);
    (yyval.till_loop_type).start = "0";
    (yyval.till_loop_type).lim = (yyvsp[-1].expression);
    printf("till iter %s created scope\n", (yyval.till_loop_type).iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=axo_mk_simple_typ("int"), .name=(yyval.till_loop_type).iter, .is_const=false});
  }
#line 2635 "axo_gram.tab.c"
    break;

  case 66: /* while_loop_base: "while" '(' expr ')'  */
#line 653 "axo_gram.y"
                                          {
    if (axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression)))
      (yyval.str) = alloc_str((yyvsp[-1].expression).val);
    in_loop_count++;
  }
#line 2645 "axo_gram.tab.c"
    break;

  case 67: /* matching_while: while_loop_base matching_statement  */
#line 660 "axo_gram.y"
                                                    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 2657 "axo_gram.tab.c"
    break;

  case 68: /* non_matching_while: while_loop_base non_matching_statement  */
#line 669 "axo_gram.y"
                                                            {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 2669 "axo_gram.tab.c"
    break;

  case 69: /* non_matching_for_loop: for_loop_base non_matching_statement  */
#line 678 "axo_gram.y"
                                                             {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 2681 "axo_gram.tab.c"
    break;

  case 70: /* matching_for_loop: for_loop_base matching_statement  */
#line 687 "axo_gram.y"
                                                     {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 2693 "axo_gram.tab.c"
    break;

  case 71: /* for_loop_start: "for"  */
#line 696 "axo_gram.y"
                          {
    axo_push_scope(scopes, axo_new_scope(top_scope));
  }
#line 2701 "axo_gram.tab.c"
    break;

  case 72: /* for_loop_init: for_loop_start '(' statement  */
#line 701 "axo_gram.y"
                                             {
    (yyval.for_loop_type).start = (yyvsp[0].statement_type).val;
  }
#line 2709 "axo_gram.tab.c"
    break;

  case 73: /* for_loop_base: for_loop_init ',' expr ',' statement ')'  */
#line 706 "axo_gram.y"
                                                         {
    axo_validate_rval(&(yylsp[-3]), (yyvsp[-3].expression));
    char* iter = (yyvsp[-1].statement_type).val;
    iter[strlen(iter)-1] = '\0';
    (yyval.for_loop_type) = (axo_for_loop){
      .start = (yyvsp[-5].for_loop_type).start,
      .condition = (yyvsp[-3].expression).val,
      .iteration = iter,
    };
    in_loop_count++;
  }
#line 2725 "axo_gram.tab.c"
    break;

  case 74: /* for_loop_base: till_loop_start  */
#line 717 "axo_gram.y"
                    {
    (yyval.for_loop_type) = (axo_for_loop){
      .start = fmtstr("int %s=%s;", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).start),
      .condition = fmtstr("%s<%s", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).lim.val),
      .iteration = fmtstr("%s++", (yyvsp[0].till_loop_type).iter),
    };
    in_loop_count++;
  }
#line 2738 "axo_gram.tab.c"
    break;

  case 75: /* assign_op: '='  */
#line 727 "axo_gram.y"
                {
    rval_now = true;
  }
#line 2746 "axo_gram.tab.c"
    break;

  case 76: /* assignment: expr assign_op expr  */
#line 732 "axo_gram.y"
                                 {
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_typ l_typ = (yyvsp[-2].expression).typ;
    switch((yyvsp[-2].expression).lval_kind){
      case axo_var_lval_kind:
        if ((yyvsp[-2].expression).typ.kind == axo_no_kind){
          l_typ = axo_clean_typ((yyvsp[0].expression).typ);
          (yyval.expression).val = axo_get_var_decl_assign(&(yyloc), (yyvsp[-2].expression).val, (axo_expr){.typ=l_typ, .val=(yyvsp[0].expression).val});
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
#line 2775 "axo_gram.tab.c"
    break;

  case 77: /* stat_arr_init_dims: expr assign_op '[' identifier "->" "integer literal" ']'  */
#line 758 "axo_gram.y"
                                                                                {
    //FIX! Check if iter is free to use
    (yyval.stat_arr_init_type) = (axo_stat_arr_init){
      .dims = (int*)malloc(axo_stat_arr_literal_cap*sizeof(int)),
      .iters = (char**)malloc(axo_stat_arr_literal_cap*sizeof(char*)),
      .len=1,
      .lval=(yyvsp[-6].expression)
    };
    (yyval.stat_arr_init_type).dims[0] = atoi((yyvsp[-1].str));
    (yyval.stat_arr_init_type).iters[0] = (char*)((yyvsp[-3].identifier_type).data);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    axo_set_var(top_scope, (axo_var){.name=alloc_str(((char*)((yyvsp[-3].identifier_type).data))), .typ=state->int_def->typ});
    top_scope->ret_assign = fmtstr("%s[%s]", (yyvsp[-6].expression).val, (char*)((yyvsp[-3].identifier_type).data));
    rval_now=false;
  }
#line 2796 "axo_gram.tab.c"
    break;

  case 78: /* stat_arr_init_dims: stat_arr_init_dims '[' identifier "->" "integer literal" ']'  */
#line 774 "axo_gram.y"
                                                                   {
    (yyval.stat_arr_init_type)=(yyvsp[-5].stat_arr_init_type);
    if ((yyval.stat_arr_init_type).len % axo_stat_arr_literal_cap == 0){
      (yyval.stat_arr_init_type).dims = (int*)realloc((yyval.stat_arr_init_type).dims, ((yyval.stat_arr_init_type).len+axo_stat_arr_literal_cap)*sizeof(int));
      (yyval.stat_arr_init_type).iters = (char**)realloc((yyval.stat_arr_init_type).iters, ((yyval.stat_arr_init_type).len+axo_stat_arr_literal_cap)*sizeof(char*));
    }
    (yyval.stat_arr_init_type).dims[(yyval.stat_arr_init_type).len] = atoi((yyvsp[-1].str));
    (yyval.stat_arr_init_type).iters[(yyval.stat_arr_init_type).len] = (char*)((yyvsp[-3].identifier_type).data);
    (yyval.stat_arr_init_type).len++;
    axo_set_var(top_scope, (axo_var){.name=alloc_str(((char*)((yyvsp[-3].identifier_type).data))), .typ=state->int_def->typ});
    top_scope->ret_assign = fmtstr("%s[%s]", top_scope->ret_assign, (char*)((yyvsp[-3].identifier_type).data));
  }
#line 2813 "axo_gram.tab.c"
    break;

  case 79: /* stat_arr_init: stat_arr_init_dims code_scope  */
#line 788 "axo_gram.y"
                                              {
    axo_typ r_typ = (yyvsp[0].scope)->ret_typ;
    axo_arr* arr;
    for (int i=0; i<(yyvsp[-1].stat_arr_init_type).len; i++){
      arr = alloc_one(axo_arr);
      arr->typ = r_typ;
      arr->sz = (yyvsp[-1].stat_arr_init_type).dims[0];
      r_typ = (axo_typ){
        .kind=axo_stat_arr_kind,
        .arr=arr
      };
    }
    axo_typ l_typ=r_typ;
    //Check lval for initialization need, this is messy FIX potentially!
    if ((yyvsp[-1].stat_arr_init_type).lval.lval_kind == axo_var_lval_kind){
      axo_var* var = axo_get_var(top_scope, (yyvsp[-1].stat_arr_init_type).lval.val);
      if (var==NULL){
        axo_set_var(top_scope, (axo_var){.typ = r_typ, .name = (yyvsp[-1].stat_arr_init_type).lval.val, .is_const=false});
      }else{
        l_typ=var->typ;
      }
    }
    if (!axo_typ_eq(l_typ, r_typ))
      yyerror(&(yyloc), "Cannot assign '%s' to '%s'.", axo_typ_to_str(r_typ), axo_typ_to_str(l_typ));
    (yyval.stat_arr_init_type)=(yyvsp[-1].stat_arr_init_type);
    (yyval.stat_arr_init_type).code = (yyvsp[0].scope);
  }
#line 2845 "axo_gram.tab.c"
    break;

  case 80: /* stat_arr_literal_start: '[' expr  */
#line 817 "axo_gram.y"
                                  {
    (yyval.stat_arr_val_type) = (axo_stat_arr_val){
      .typ=(yyvsp[0].expression).typ,
      .data=(char**)malloc(axo_stat_arr_literal_cap*sizeof(char*)),
      .len=1
    };
    (yyval.stat_arr_val_type).data[0] = (yyvsp[0].expression).val;
  }
#line 2858 "axo_gram.tab.c"
    break;

  case 81: /* stat_arr_literal_start: stat_arr_literal_start ',' expr  */
#line 825 "axo_gram.y"
                                    {
    if (!axo_typ_eq((yyvsp[-2].stat_arr_val_type).typ, (yyvsp[0].expression).typ))
      yyerror(&(yylsp[0]), "A value of type '%s' cannot be an element of an array of type '%s'.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyvsp[-2].stat_arr_val_type).typ));
    else{
      (yyval.stat_arr_val_type)=(yyvsp[-2].stat_arr_val_type);
      if ((yyval.stat_arr_val_type).len % axo_stat_arr_literal_cap == 0)
        (yyval.stat_arr_val_type).data = (char**)realloc((yyval.stat_arr_val_type).data, ((yyval.stat_arr_val_type).len+axo_stat_arr_literal_cap)*sizeof(char*));
      (yyval.stat_arr_val_type).data[(yyval.stat_arr_val_type).len] = (yyvsp[0].expression).val;
      (yyval.stat_arr_val_type).len++;
    }
  }
#line 2874 "axo_gram.tab.c"
    break;

  case 83: /* stat_arr_typ: '[' "integer literal" ']' val_typ  */
#line 841 "axo_gram.y"
                                              {
    (yyval.typ_type).kind = axo_stat_arr_kind;
    (yyval.typ_type).arr = alloc_one(axo_arr);
    *(axo_arr*)((yyval.typ_type).arr) = (axo_arr){
      .typ = (yyvsp[0].typ_type),
      .sz = atoi((yyvsp[-2].str))
    };
  }
#line 2887 "axo_gram.tab.c"
    break;

  case 84: /* dyn_arr_typ: '[' ']' val_typ  */
#line 851 "axo_gram.y"
                              {
    (yyval.typ_type).kind = axo_dyn_arr_kind;
    (yyval.typ_type).arr = alloc_one(axo_arr);
    *(axo_arr*)((yyval.typ_type).arr) = (axo_arr){
      .typ = (yyvsp[0].typ_type),
      .sz = 0
    };
  }
#line 2900 "axo_gram.tab.c"
    break;

  case 85: /* func_typ_start: '(' val_typ "fn"  */
#line 861 "axo_gram.y"
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
#line 2916 "axo_gram.tab.c"
    break;

  case 86: /* func_typ_start: '(' "fn"  */
#line 872 "axo_gram.y"
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
#line 2932 "axo_gram.tab.c"
    break;

  case 87: /* func_typ_args: func_typ_start val_typ  */
#line 885 "axo_gram.y"
                                       {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = (yyvsp[0].typ_type);
    func_typ->args_defs[0] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 2946 "axo_gram.tab.c"
    break;

  case 88: /* func_typ_args: func_typ_args ',' val_typ  */
#line 894 "axo_gram.y"
                              {
    (yyval.typ_type)=(yyvsp[-2].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = (yyvsp[0].typ_type);
    func_typ->args_defs[func_typ->args_len] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 2960 "axo_gram.tab.c"
    break;

  case 89: /* func_typ: func_typ_start ')'  */
#line 905 "axo_gram.y"
                              {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 2966 "axo_gram.tab.c"
    break;

  case 90: /* func_typ: func_typ_args ')'  */
#line 906 "axo_gram.y"
                      {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 2972 "axo_gram.tab.c"
    break;

  case 91: /* val_typ: "identifier"  */
#line 909 "axo_gram.y"
               {
    axo_typ_def* def = axo_get_typ_def(state, (yyvsp[0].str));
    if (def==NULL)
      yyerror(&(yylsp[0]), "Type '%s' isn't defined.", (yyvsp[0].str));
    else
      (yyval.typ_type)=def->typ;
  }
#line 2984 "axo_gram.tab.c"
    break;

  case 92: /* val_typ: '@' val_typ  */
#line 916 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_ptr_kind;
    (yyval.typ_type).ptr = malloc(sizeof(axo_typ));
    axo_ptr* ptr = (yyval.typ_type).ptr;
    ptr->typ = (yyvsp[0].typ_type);
  }
#line 2995 "axo_gram.tab.c"
    break;

  case 95: /* val_typ: dyn_arr_typ  */
#line 924 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_simple_kind;
    (yyval.typ_type).simple = alloc_str("DYN_ARR");
  }
#line 3004 "axo_gram.tab.c"
    break;

  case 96: /* c_typ: "identifier"  */
#line 930 "axo_gram.y"
             {
    (yyval.typ_type).kind = axo_simple_kind;
    (yyval.typ_type).simple = alloc_str((yyvsp[0].str));
  }
#line 3013 "axo_gram.tab.c"
    break;

  case 97: /* c_typ: c_typ '*'  */
#line 934 "axo_gram.y"
              {
    asprintf(&((yyvsp[-1].typ_type).simple), "%s*", (yyvsp[-1].typ_type).simple);
    (yyval.typ_type).simple = (yyvsp[-1].typ_type).simple;
    (yyval.typ_type).kind = (yyvsp[-1].typ_type).kind;
  }
#line 3023 "axo_gram.tab.c"
    break;

  case 98: /* c_typ: '.' '.' '.'  */
#line 939 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_c_arg_list_kind;
    (yyval.typ_type).simple = NULL;
  }
#line 3032 "axo_gram.tab.c"
    break;

  case 99: /* c_typ_list: %empty  */
#line 945 "axo_gram.y"
                           {
    (yyval.types_list).len = 0;
    (yyval.types_list).values = NULL;
  }
#line 3041 "axo_gram.tab.c"
    break;

  case 100: /* c_typ_list: c_typ  */
#line 949 "axo_gram.y"
          {
    (yyval.types_list).values = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.types_list).values[0] = (yyvsp[0].typ_type);
    (yyval.types_list).len = 1;
  }
#line 3051 "axo_gram.tab.c"
    break;

  case 101: /* c_typ_list: c_typ_list ',' c_typ  */
#line 954 "axo_gram.y"
                         {
    if ((yyvsp[-2].types_list).values[(yyvsp[-2].types_list).len-1].kind == axo_c_arg_list_kind)
      yyerror(&(yylsp[-2]), "The C v_args argument has to be the last one.");
    (yyval.types_list) = (yyvsp[-2].types_list);
    if ((yyval.types_list).len % axo_func_args_cap == 0)
      (yyval.types_list).values = (axo_typ*)realloc((yyval.types_list).values, ((yyval.types_list).len+axo_func_args_cap)*sizeof(axo_typ));
    (yyval.types_list).values[(yyval.types_list).len] = (yyvsp[0].typ_type);
    (yyval.types_list).len++;
  }
#line 3065 "axo_gram.tab.c"
    break;

  case 102: /* func_call_start: expr '('  */
#line 965 "axo_gram.y"
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
#line 3090 "axo_gram.tab.c"
    break;

  case 103: /* func_call_start: expr '(' expr  */
#line 985 "axo_gram.y"
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
#line 3122 "axo_gram.tab.c"
    break;

  case 104: /* func_call_start: func_call_start ',' expr  */
#line 1012 "axo_gram.y"
                             {
    (yyval.function_call) = (yyvsp[-2].function_call);
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
#line 3143 "axo_gram.tab.c"
    break;

  case 105: /* func_call_start: func_call_start ','  */
#line 1028 "axo_gram.y"
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
#line 3161 "axo_gram.tab.c"
    break;

  case 106: /* func_call: func_call_start ')'  */
#line 1043 "axo_gram.y"
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
#line 3181 "axo_gram.tab.c"
    break;

  case 107: /* code_scope_start: '{'  */
#line 1060 "axo_gram.y"
                       {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
#line 3190 "axo_gram.tab.c"
    break;

  case 108: /* code_scope: code_scope_start statements '}'  */
#line 1066 "axo_gram.y"
                                             {
    (yyval.scope) = top_scope;
    scopes->len--;
  }
#line 3199 "axo_gram.tab.c"
    break;

  case 109: /* func_def_start: "fn" "identifier" '(' func_args ')'  */
#line 1072 "axo_gram.y"
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
#line 3215 "axo_gram.tab.c"
    break;

  case 110: /* func_def_start: "fn" val_typ "identifier" '(' func_args ')'  */
#line 1083 "axo_gram.y"
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
#line 3232 "axo_gram.tab.c"
    break;

  case 111: /* struct_def: "struct" "identifier" '(' func_args ')'  */
#line 1097 "axo_gram.y"
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
#line 3249 "axo_gram.tab.c"
    break;

  case 112: /* struct_literal_start: "struct{"  */
#line 1110 "axo_gram.y"
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
#line 3270 "axo_gram.tab.c"
    break;

  case 113: /* struct_literal_start: "struct{" expr  */
#line 1126 "axo_gram.y"
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
#line 3296 "axo_gram.tab.c"
    break;

  case 114: /* struct_literal_start: "struct{" "identifier" '=' expr  */
#line 1147 "axo_gram.y"
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
#line 3331 "axo_gram.tab.c"
    break;

  case 115: /* struct_literal_start: struct_literal_start ',' expr  */
#line 1177 "axo_gram.y"
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
#line 3350 "axo_gram.tab.c"
    break;

  case 116: /* struct_literal_start: struct_literal_start ','  */
#line 1191 "axo_gram.y"
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
#line 3365 "axo_gram.tab.c"
    break;

  case 117: /* struct_literal_start: struct_literal_start ',' "identifier" '=' expr  */
#line 1201 "axo_gram.y"
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
#line 3389 "axo_gram.tab.c"
    break;

  case 118: /* struct_literal: struct_literal_start '}'  */
#line 1222 "axo_gram.y"
                                          {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = ((axo_struct*)(yyval.struct_val_type).typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if((yyval.struct_val_type).fields[i] == NULL) (yyval.struct_val_type).fields[i] = structure->fields[i].def.val;
    }
  }
#line 3401 "axo_gram.tab.c"
    break;

  case 119: /* func_def: func_def_start code_scope  */
#line 1231 "axo_gram.y"
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
#line 3419 "axo_gram.tab.c"
    break;

  case 120: /* func_arg: val_typ "identifier"  */
#line 1246 "axo_gram.y"
                        {
    (yyval.function_argument).name = alloc_str((yyvsp[0].str));
    (yyval.function_argument).typ = (yyvsp[-1].typ_type);
    (yyval.function_argument).def = (yyvsp[-1].typ_type).def;
  }
#line 3429 "axo_gram.tab.c"
    break;

  case 121: /* func_arg: "identifier" ':' expr  */
#line 1251 "axo_gram.y"
                  {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[0].expression).typ;
    (yyval.function_argument).def = (yyvsp[0].expression).val;
  }
#line 3439 "axo_gram.tab.c"
    break;

  case 122: /* func_arg: val_typ "identifier" ':' expr  */
#line 1256 "axo_gram.y"
                          {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[-3].typ_type);
    (yyval.function_argument).def = (yyvsp[0].expression).val; //FIX! Look if types match!
  }
#line 3449 "axo_gram.tab.c"
    break;

  case 123: /* func_args: %empty  */
#line 1263 "axo_gram.y"
                            {
    (yyval.function).args_names = NULL;
    (yyval.function).f_typ.args_defs = NULL;
    (yyval.function).f_typ.args_types = NULL;
    (yyval.function).f_typ.args_len = 0;
  }
#line 3460 "axo_gram.tab.c"
    break;

  case 124: /* func_args: func_arg  */
#line 1269 "axo_gram.y"
             {
    (yyval.function).args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.function).args_names[0] = (yyvsp[0].function_argument).name;
    (yyval.function).f_typ.args_defs[0] = (yyvsp[0].function_argument).def;
    (yyval.function).f_typ.args_types[0] = (yyvsp[0].function_argument).typ;
    (yyval.function).f_typ.args_len = 1;
  }
#line 3474 "axo_gram.tab.c"
    break;

  case 125: /* func_args: func_args ',' func_arg  */
#line 1278 "axo_gram.y"
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
#line 3489 "axo_gram.tab.c"
    break;

  case 126: /* enum_names: "identifier"  */
#line 1290 "axo_gram.y"
                  {
    (yyval.enum_type).names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    (yyval.enum_type).names[0] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len = 1;
  }
#line 3499 "axo_gram.tab.c"
    break;

  case 127: /* enum_names: enum_names ',' "identifier"  */
#line 1295 "axo_gram.y"
                        {
    (yyval.enum_type) = (yyvsp[-2].enum_type);
    if ((yyval.enum_type).len % axo_enum_names_cap == 0)
    (yyval.enum_type).names = (char**)realloc((yyval.enum_type).names, ((yyval.enum_type).len+axo_enum_names_cap)*sizeof(char*));
    (yyval.enum_type).names[(yyval.enum_type).len] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len++;
  }
#line 3511 "axo_gram.tab.c"
    break;


#line 3515 "axo_gram.tab.c"

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

#line 1304 "axo_gram.y"


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
