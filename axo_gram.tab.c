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
  YYSYMBOL_NULL_KWRD = 31,                 /* "null"  */
  YYSYMBOL_INCR_OP = 32,                   /* "++"  */
  YYSYMBOL_DECR_OP = 33,                   /* "--"  */
  YYSYMBOL_ENUM_KWRD = 34,                 /* "enum"  */
  YYSYMBOL_STRUCT_KWRD = 35,               /* "struct"  */
  YYSYMBOL_USE_KWRD = 36,                  /* "use"  */
  YYSYMBOL_INCLUDE_KWRD = 37,              /* "include"  */
  YYSYMBOL_STRUCT_LITERAL_START = 38,      /* "struct{"  */
  YYSYMBOL_DOT_FIELD = 39,                 /* ".field"  */
  YYSYMBOL_ARROW_OP = 40,                  /* "->"  */
  YYSYMBOL_IS_KWRD = 41,                   /* "is"  */
  YYSYMBOL_IDENTIFIER_PREC = 42,           /* IDENTIFIER_PREC  */
  YYSYMBOL_43_ = 43,                       /* '$'  */
  YYSYMBOL_EXPR_AS_STATEMENT = 44,         /* EXPR_AS_STATEMENT  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '?'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_LOOP_PREC = 54,                 /* LOOP_PREC  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_UMINUS = 58,                    /* UMINUS  */
  YYSYMBOL_59_ = 59,                       /* '@'  */
  YYSYMBOL_60_ = 60,                       /* '^'  */
  YYSYMBOL_61_ = 61,                       /* '['  */
  YYSYMBOL_STRUCT_LIT_NAMED_FIELD = 62,    /* STRUCT_LIT_NAMED_FIELD  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* '|'  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '{'  */
  YYSYMBOL_68_ = 68,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_declarations = 70,              /* declarations  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_statements = 72,                /* statements  */
  YYSYMBOL_index_access = 73,              /* index_access  */
  YYSYMBOL_identifier = 74,                /* identifier  */
  YYSYMBOL_incr_decr_op = 75,              /* incr_decr_op  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_stat_arr_literal_start = 77,    /* stat_arr_literal_start  */
  YYSYMBOL_stat_arr_literal = 78,          /* stat_arr_literal  */
  YYSYMBOL_arr_literal = 79,               /* arr_literal  */
  YYSYMBOL_empty_arr_dims = 80,            /* empty_arr_dims  */
  YYSYMBOL_statement = 81,                 /* statement  */
  YYSYMBOL_matching_statement = 82,        /* matching_statement  */
  YYSYMBOL_if_condition = 83,              /* if_condition  */
  YYSYMBOL_matching_if_statement = 84,     /* matching_if_statement  */
  YYSYMBOL_non_matching_statement = 85,    /* non_matching_statement  */
  YYSYMBOL_non_matching_if_statement = 86, /* non_matching_if_statement  */
  YYSYMBOL_till_loop_start = 87,           /* till_loop_start  */
  YYSYMBOL_while_loop_base = 88,           /* while_loop_base  */
  YYSYMBOL_matching_while = 89,            /* matching_while  */
  YYSYMBOL_non_matching_while = 90,        /* non_matching_while  */
  YYSYMBOL_for_loop_start = 91,            /* for_loop_start  */
  YYSYMBOL_for_loop_init = 92,             /* for_loop_init  */
  YYSYMBOL_for_loop_base = 93,             /* for_loop_base  */
  YYSYMBOL_matching_for_loop = 94,         /* matching_for_loop  */
  YYSYMBOL_non_matching_for_loop = 95,     /* non_matching_for_loop  */
  YYSYMBOL_each_iter_dims = 96,            /* each_iter_dims  */
  YYSYMBOL_each_loop_start = 97,           /* each_loop_start  */
  YYSYMBOL_each_loop_base = 98,            /* each_loop_base  */
  YYSYMBOL_matching_each_loop = 99,        /* matching_each_loop  */
  YYSYMBOL_non_matching_each_loop = 100,   /* non_matching_each_loop  */
  YYSYMBOL_assign_op = 101,                /* assign_op  */
  YYSYMBOL_assignment = 102,               /* assignment  */
  YYSYMBOL_arr_multidim_typ = 103,         /* arr_multidim_typ  */
  YYSYMBOL_arr_typ = 104,                  /* arr_typ  */
  YYSYMBOL_func_typ_start = 105,           /* func_typ_start  */
  YYSYMBOL_func_typ_args = 106,            /* func_typ_args  */
  YYSYMBOL_func_typ = 107,                 /* func_typ  */
  YYSYMBOL_val_typ = 108,                  /* val_typ  */
  YYSYMBOL_c_typ = 109,                    /* c_typ  */
  YYSYMBOL_c_typ_list = 110,               /* c_typ_list  */
  YYSYMBOL_func_call_start = 111,          /* func_call_start  */
  YYSYMBOL_func_call = 112,                /* func_call  */
  YYSYMBOL_code_scope_start = 113,         /* code_scope_start  */
  YYSYMBOL_code_scope = 114,               /* code_scope  */
  YYSYMBOL_func_def_start = 115,           /* func_def_start  */
  YYSYMBOL_struct_def = 116,               /* struct_def  */
  YYSYMBOL_struct_literal_start = 117,     /* struct_literal_start  */
  YYSYMBOL_struct_literal = 118,           /* struct_literal  */
  YYSYMBOL_func_def = 119,                 /* func_def  */
  YYSYMBOL_func_arg = 120,                 /* func_arg  */
  YYSYMBOL_func_args = 121,                /* func_args  */
  YYSYMBOL_enum_names = 122                /* enum_names  */
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
#define YYLAST   1099

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
       2,     2,     2,     2,     2,     2,    43,    53,     2,     2,
      56,    63,    51,    49,    66,    50,    55,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      47,    45,    48,    46,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    65,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    64,    68,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    54,
      58,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   156,   159,   162,   181,   215,   220,   245,
     258,   259,   262,   270,   275,   292,   296,   303,   304,   305,
     306,   314,   315,   316,   317,   318,   319,   320,   321,   329,
     338,   339,   375,   389,   390,   397,   404,   411,   418,   425,
     432,   441,   450,   459,   468,   491,   517,   595,   596,   597,
     628,   643,   658,   669,   679,   702,   717,   746,   754,   762,
     768,   768,   770,   776,   781,   793,   796,   815,   822,   829,
     830,   831,   832,   835,   841,   846,   847,   848,   849,   852,
     855,   860,   870,   877,   886,   895,   900,   905,   916,   927,
     935,   944,   953,   963,   967,   972,   978,   992,  1006,  1020,
    1036,  1044,  1052,  1057,  1083,  1093,  1099,  1110,  1116,  1127,
    1140,  1149,  1160,  1161,  1164,  1171,  1176,  1177,  1180,  1181,
    1186,  1190,  1195,  1206,  1226,  1229,  1256,  1272,  1287,  1304,
    1310,  1318,  1329,  1343,  1356,  1372,  1393,  1423,  1437,  1447,
    1468,  1477,  1492,  1497,  1502,  1509,  1515,  1524,  1536,  1541
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
  "\"&&\"", "\"or\"", "\"and\"", "\"<<\"", "\">>\"", "\"till\"",
  "\"null\"", "\"++\"", "\"--\"", "\"enum\"", "\"struct\"", "\"use\"",
  "\"include\"", "\"struct{\"", "\".field\"", "\"->\"", "\"is\"",
  "IDENTIFIER_PREC", "'$'", "EXPR_AS_STATEMENT", "'='", "'?'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "LOOP_PREC", "'.'", "'('",
  "':'", "UMINUS", "'@'", "'^'", "'['", "STRUCT_LIT_NAMED_FIELD", "')'",
  "'|'", "']'", "','", "'{'", "'}'", "$accept", "declarations",
  "declaration", "statements", "index_access", "identifier",
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

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,   250,  -105,  -105,    13,    14,     2,    11,    25,  -105,
     -32,  -105,  -105,  -105,   -16,     1,    23,    71,    82,  -105,
       0,   -20,  -105,  -105,    39,    10,    65,    30,    45,  -105,
    -105,   274,  -105,    57,  -105,   108,  -105,  -105,    23,  -105,
      23,  -105,  -105,  -105,    23,   111,    24,   116,   121,    24,
    -105,  -105,  -105,  -105,   339,  -105,  -105,   122,   138,   339,
     124,  -105,   353,   339,   126,   339,   339,   339,   370,   208,
    -105,  -105,   718,   -13,  -105,  -105,    92,  -105,  -105,   274,
    -105,  -105,  -105,  -105,   274,  -105,  -105,   274,   123,   274,
    -105,  -105,     4,   274,  -105,  -105,  -105,   -19,  -105,  -105,
      34,  -105,  -105,  -105,  -105,  -105,  -105,    13,   128,   187,
    -105,   -12,    24,  -105,    15,    66,  1008,   339,  -105,  1008,
     188,   150,   760,   760,   195,    16,   586,    16,    96,   460,
    -105,  -105,   339,   339,   339,   339,   339,   339,   339,   339,
    -105,  -105,  -105,    23,  -105,   339,   339,   339,   339,   339,
     339,   339,   339,   144,   339,   196,  -105,   339,    98,   339,
    -105,   339,   197,    58,  -105,   185,  -105,  -105,  -105,   339,
    -105,  -105,   290,    -8,   100,  -105,  -105,  -105,   339,   401,
    -105,  -105,    78,   339,   141,  -105,    24,    87,  -105,   200,
    -105,   630,   163,   339,  -105,  -105,   120,  1038,  1038,   966,
     966,   886,   928,   192,   192,  -105,   802,   966,   966,   258,
     258,  1019,  1019,  1019,    23,   760,   153,   760,   339,  -105,
     760,   760,  -105,    84,  -105,   274,   502,   339,   760,   339,
     157,   339,    33,   760,   175,   760,  -105,    13,   760,   339,
    -105,  -105,  -105,  -105,   339,   760,  -105,   760,   418,   164,
    -105,   760,   544,  -105,  -105,   274,   760,   844,   119,   760,
     339,   223,   339,  -105,   760,   674,   153,   136,  -105,   339,
    -105,   213,   844,   215,   760,  -105,   760,   339,   339,   844,
     844
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,     0,     0,     0,     0,     0,     7,
       0,     8,     3,   114,     0,     0,     0,     0,     0,   117,
       0,     0,   116,   118,     0,   114,     0,     0,     0,     9,
     129,     0,   141,     0,   109,     0,   115,   104,     0,   105,
       0,   112,   110,   113,     0,     0,   145,     0,     0,   145,
      17,    18,    19,    14,     0,    68,    67,     0,    85,     0,
       0,    20,   134,     0,     0,     0,     0,     0,     0,     0,
      31,    48,    62,     0,    55,    47,     0,    10,    60,     0,
      69,    61,    75,    88,     0,    71,    77,     0,     0,     0,
      70,    76,     0,     0,    72,    78,    30,     0,    33,    65,
       0,    44,   119,   108,   106,   107,   111,   120,   114,     0,
     146,     0,   145,   148,     0,     0,    64,     0,    95,    73,
       0,    14,   135,    63,     0,    23,     0,    28,    18,     0,
     130,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    46,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,    29,     0,     0,     0,
      54,     0,     0,     0,    79,    60,    83,    84,    86,     0,
      89,    90,     0,     0,     0,   100,   101,   128,   127,   138,
     140,   121,     0,     0,   142,   131,     0,     0,     6,     0,
     133,     0,     0,     0,    57,    27,     0,    36,    37,    38,
      39,    40,    41,    43,    42,    66,     0,    34,    35,    21,
      22,    24,    25,    26,     0,   125,     0,    12,     0,    45,
     103,    52,    59,     0,    56,     0,     0,     0,    91,     0,
       0,    94,     0,   126,    14,   137,     5,     0,   143,     0,
     147,   132,   149,    82,     0,   136,    53,    50,     0,     0,
     124,    13,     0,    74,    80,     0,    92,    96,     0,    93,
       0,     0,     0,   122,   144,     0,    14,    32,    49,     0,
      87,     0,    99,     0,   139,    81,    51,     0,     0,    97,
      98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,  -105,  -105,   -90,  -105,   -41,  -105,  -105,
    -105,  -105,   -64,   -51,  -105,  -105,   -52,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,     5,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    -4,
    -104,  -105,  -105,  -105,  -105,   224,  -105,  -105,  -105,  -105,
    -105,    54,   -45,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     9,    69,   158,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   174,    92,    93,
      94,    95,   159,    96,    18,    19,    20,    21,    22,   109,
      24,   182,    97,    98,    31,    99,    10,    11,   100,   101,
      12,   110,   111,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    26,   173,   181,   115,   131,    13,    13,    27,   229,
      53,    35,    36,   116,    34,   164,    42,    28,   119,    13,
      25,   122,   123,   168,   125,   126,   127,   129,   165,    13,
     108,    29,   167,   166,   104,    30,   105,   171,   170,    33,
     106,   176,   175,    43,   177,    45,    44,   178,   140,   141,
     260,   185,   160,   161,   186,   142,    15,    15,   230,    16,
      16,    17,    17,    41,    13,   172,    46,   187,    14,    15,
      15,    47,    16,    16,    17,    17,   191,   157,   188,    15,
      15,   189,    16,    16,    17,    17,    48,    50,    51,    52,
      53,   197,   198,   199,   200,   201,   202,   203,   204,   261,
     179,    49,   180,    23,   206,   207,   208,   209,   210,   211,
     212,   213,   102,   215,    15,    61,   217,    16,   220,   223,
     221,   103,    62,    50,    51,    52,    53,   113,   226,   190,
      64,   228,   186,   263,    65,    37,    38,   233,   235,   205,
      66,   236,   238,    67,   237,    68,    39,    40,    37,    38,
     241,    61,   245,   186,   118,   247,   162,   163,    62,   224,
     -58,   -58,   218,   219,   231,   232,    64,   107,   140,   141,
      65,   273,   112,   254,   253,   142,    66,   251,   117,    67,
     120,    68,   252,   231,   271,   246,   256,   124,   257,   169,
     259,   270,   183,   184,   192,   193,   156,   157,   264,   194,
     214,   222,   216,   265,   225,   239,   242,   267,   244,   250,
     249,    50,    51,    52,    53,    54,    55,    56,   172,   272,
     262,   274,    57,    58,   140,   141,    59,   268,   276,    53,
     277,   142,   278,    23,    32,   258,   279,   280,    60,    61,
     240,   148,   149,   150,   151,   152,    62,   153,   154,   155,
       2,    63,   156,   157,    64,     0,     0,     0,    65,     0,
       0,     3,     4,     5,    66,     0,     0,    67,     0,    68,
       0,     0,     0,     0,     0,    30,   130,    50,    51,    52,
      53,    54,    55,    56,     6,     7,     8,     0,    57,    58,
     140,   141,    59,    50,    51,    52,    53,   142,     0,     0,
       0,     0,     0,     0,    60,    61,     0,     0,     0,   150,
     151,   152,    62,   153,   154,   155,     0,    63,   156,   157,
      64,    61,     0,     0,    65,     0,     0,     0,    62,     0,
      66,     0,     0,    67,     0,    68,    64,     0,     0,     0,
      65,    30,    50,    51,    52,    53,    66,     0,     0,    67,
       0,    68,     0,     0,   227,     0,    50,    51,    52,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    50,   128,    52,    53,    62,     0,     0,
       0,     0,     0,     0,    61,    64,     0,     0,     0,    65,
       0,    62,     0,     0,     0,    66,     0,     0,    67,    64,
      68,    61,     0,    65,    50,    51,    52,   234,    62,    66,
       0,     0,    67,     0,    68,     0,    64,     0,     0,     0,
      65,    50,    51,    52,   266,     0,    66,     0,     0,    67,
       0,    68,    61,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,    64,     0,    61,
       0,    65,     0,     0,     0,     0,    62,    66,     0,     0,
      67,     0,    68,     0,    64,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    66,     0,     0,    67,     0,    68,
     132,   133,   134,   135,     0,     0,   136,   137,   138,   139,
       0,     0,   140,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,     0,     0,
     156,   157,   132,   133,   134,   135,   196,     0,   136,   137,
     138,   139,     0,     0,   140,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,   153,   154,   155,
       0,     0,   156,   157,   132,   133,   134,   135,   255,     0,
     136,   137,   138,   139,     0,     0,   140,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,     0,     0,   156,   157,   132,   133,   134,   135,
     269,     0,   136,   137,   138,   139,     0,     0,   140,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,     0,     0,   156,   157,     0,   195,
     132,   133,   134,   135,     0,     0,   136,   137,   138,   139,
       0,     0,   140,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,     0,     0,
     156,   157,     0,   243,   132,   133,   134,   135,     0,     0,
     136,   137,   138,   139,     0,     0,   140,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,     0,     0,   156,   157,     0,   275,   132,   133,
     134,   135,     0,     0,   136,   137,   138,   139,     0,     0,
     140,   141,     0,     0,     0,     0,     0,   142,     0,   143,
       0,     0,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,     0,     0,   156,   157,
     132,   133,   134,   135,     0,     0,   136,   137,   138,   139,
       0,     0,   140,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,     0,     0,
     156,   157,   132,   133,   134,   135,     0,     0,   136,   137,
     138,   139,     0,     0,   140,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,   153,   154,   248,
       0,     0,   156,   157,   132,   133,   134,   135,     0,     0,
     136,   137,   138,   139,     0,     0,   140,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   144,
       0,   146,   147,   148,     0,   150,   151,   152,     0,   153,
     154,   155,     0,     0,   156,   157,   132,   133,   134,   135,
       0,     0,     0,   137,   138,   139,     0,     0,   140,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,     0,     0,   156,   157,   132,   133,
     134,   135,     0,     0,     0,     0,   138,   139,     0,     0,
     140,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   132,   133,   156,   157,
       0,     0,     0,     0,   138,   139,     0,     0,   140,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
       0,   153,   154,   155,     0,     0,   156,   157,   132,   133,
     134,   135,     0,     0,   136,   137,   138,   139,     0,     0,
     140,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   140,   141,   144,     0,   146,   147,   148,   142,   150,
     151,   152,     0,   153,     0,   155,   138,   139,   156,     0,
     140,   141,     0,     0,   153,   154,   155,   142,     0,   156,
     157,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,     0,   153,   154,   155,     0,     0,   156,   157
};

static const yytype_int16 yycheck[] =
{
       4,     5,    92,   107,    49,    69,     6,     6,     6,    17,
       6,    15,    16,    54,    13,    79,    20,     6,    59,     6,
       6,    62,    63,    87,    65,    66,    67,    68,    79,     6,
       6,     6,    84,    84,    38,    67,    40,    89,    89,    55,
      44,    93,    93,    63,    63,     6,    66,    66,    32,    33,
      17,    63,    65,    66,    66,    39,    56,    56,    66,    59,
      59,    61,    61,    63,     6,    61,    56,   112,    55,    56,
      56,     6,    59,    59,    61,    61,   117,    61,    63,    56,
      56,    66,    59,    59,    61,    61,    56,     3,     4,     5,
       6,   132,   133,   134,   135,   136,   137,   138,   139,    66,
      66,    56,    68,   107,   145,   146,   147,   148,   149,   150,
     151,   152,    55,   154,    56,    31,   157,    59,   159,    61,
     161,    13,    38,     3,     4,     5,     6,     6,   169,    63,
      46,   172,    66,   237,    50,    64,    65,   178,   179,   143,
      56,    63,   183,    59,    66,    61,    64,    65,    64,    65,
      63,    31,   193,    66,    16,   196,    64,    65,    38,   163,
      64,    65,    64,    65,    64,    65,    46,    56,    32,    33,
      50,   261,    56,   225,   225,    39,    56,   218,    56,    59,
      56,    61,   223,    64,    65,    65,   227,    61,   229,    66,
     231,   255,    64,     6,     6,    45,    60,    61,   239,     4,
      56,     4,     6,   244,    19,    64,     6,   248,    45,    56,
     214,     3,     4,     5,     6,     7,     8,     9,    61,   260,
      45,   262,    14,    15,    32,    33,    18,    63,   269,     6,
      17,    39,    17,   237,    10,   230,   277,   278,    30,    31,
     186,    49,    50,    51,    52,    53,    38,    55,    56,    57,
       0,    43,    60,    61,    46,    -1,    -1,    -1,    50,    -1,
      -1,    11,    12,    13,    56,    -1,    -1,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,     3,     4,     5,
       6,     7,     8,     9,    34,    35,    36,    -1,    14,    15,
      32,    33,    18,     3,     4,     5,     6,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    51,
      52,    53,    38,    55,    56,    57,    -1,    43,    60,    61,
      46,    31,    -1,    -1,    50,    -1,    -1,    -1,    38,    -1,
      56,    -1,    -1,    59,    -1,    61,    46,    -1,    -1,    -1,
      50,    67,     3,     4,     5,     6,    56,    -1,    -1,    59,
      -1,    61,    -1,    -1,    64,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,     3,     4,     5,     6,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    46,    -1,    -1,    -1,    50,
      -1,    38,    -1,    -1,    -1,    56,    -1,    -1,    59,    46,
      61,    31,    -1,    50,     3,     4,     5,     6,    38,    56,
      -1,    -1,    59,    -1,    61,    -1,    46,    -1,    -1,    -1,
      50,     3,     4,     5,     6,    -1,    56,    -1,    -1,    59,
      -1,    61,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    31,
      -1,    50,    -1,    -1,    -1,    -1,    38,    56,    -1,    -1,
      59,    -1,    61,    -1,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    -1,    -1,
      60,    61,    20,    21,    22,    23,    66,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      -1,    -1,    60,    61,    20,    21,    22,    23,    66,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    60,    61,    20,    21,    22,    23,
      66,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    -1,    -1,    60,    61,    -1,    63,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    -1,    -1,
      60,    61,    -1,    63,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    60,    61,    -1,    63,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    -1,    -1,    60,    61,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    -1,    -1,
      60,    61,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      -1,    -1,    60,    61,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    60,    61,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    -1,    -1,    60,    61,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    20,    21,    60,    61,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    -1,    -1,    60,    61,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    32,    33,    45,    -1,    47,    48,    49,    39,    51,
      52,    53,    -1,    55,    -1,    57,    28,    29,    60,    -1,
      32,    33,    -1,    -1,    55,    56,    57,    39,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    -1,    -1,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,     0,    11,    12,    13,    34,    35,    36,    71,
     115,   116,   119,     6,    55,    56,    59,    61,   103,   104,
     105,   106,   107,   108,   109,     6,   108,     6,     6,     6,
      67,   113,   114,    55,    13,   108,   108,    64,    65,    64,
      65,    63,   108,    63,    66,     6,    56,     6,    56,    56,
       3,     4,     5,     6,     7,     8,     9,    14,    15,    18,
      30,    31,    38,    43,    46,    50,    56,    59,    61,    72,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    97,    98,    99,   100,   102,   111,   112,   114,
     117,   118,    55,    13,   108,   108,   108,    56,     6,   108,
     120,   121,    56,     6,   122,   121,    76,    56,    16,    76,
      56,     6,    76,    76,    61,    76,    76,    76,     4,    76,
      68,    81,    20,    21,    22,    23,    26,    27,    28,    29,
      32,    33,    39,    41,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    55,    56,    57,    60,    61,    73,   101,
      65,    66,    64,    65,    81,    82,    82,    85,    81,    66,
      82,    85,    61,    74,    96,    82,    85,    63,    66,    66,
      68,   109,   110,    64,     6,    63,    66,   121,    63,    66,
      63,    76,     6,    45,     4,    63,    66,    76,    76,    76,
      76,    76,    76,    76,    76,   108,    76,    76,    76,    76,
      76,    76,    76,    76,    56,    76,     6,    76,    64,    65,
      76,    76,     4,    61,   108,    19,    76,    64,    76,    17,
      66,    64,    65,    76,     6,    76,    63,    66,    76,    64,
     120,    63,     6,    63,    45,    76,    65,    76,    57,   108,
      56,    76,    76,    82,    85,    66,    76,    76,    96,    76,
      17,    66,    45,   109,    76,    76,     6,    76,    63,    66,
      81,    65,    76,    74,    76,    63,    76,    17,    17,    76,
      76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    84,    85,    85,    85,    85,    86,
      86,    87,    88,    89,    90,    91,    92,    93,    93,    94,
      95,    96,    96,    96,    96,    97,    98,    98,    98,    98,
      99,   100,   101,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   111,   111,   111,   111,   111,   112,   113,
     114,   115,   115,   116,   117,   117,   117,   117,   117,   117,
     118,   119,   120,   120,   120,   121,   121,   121,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     7,     6,     2,     1,     2,
       1,     2,     2,     3,     1,     2,     2,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     3,     3,     2,     2,
       1,     1,     5,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     2,     1,     1,     5,
       4,     6,     3,     4,     2,     1,     3,     3,     2,     3,
       1,     1,     1,     2,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     1,     1,     1,     2,
       4,     6,     4,     2,     2,     1,     2,     5,     1,     2,
       2,     2,     3,     3,     2,     2,     4,     7,     7,     5,
       2,     2,     1,     3,     2,     2,     3,     3,     3,     2,
       2,     3,     2,     2,     1,     2,     1,     1,     1,     3,
       0,     1,     3,     2,     4,     3,     3,     2,     2,     1,
       3,     5,     6,     5,     1,     2,     4,     3,     2,     5,
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
#line 155 "axo_gram.y"
                           {}
#line 1986 "axo_gram.tab.c"
    break;

  case 3: /* declarations: declarations func_def  */
#line 156 "axo_gram.y"
                          {
    axo_add_decl(state, axo_func_def_to_decl((yyvsp[0].function)));
  }
#line 1994 "axo_gram.tab.c"
    break;

  case 4: /* declarations: declarations "#include"  */
#line 159 "axo_gram.y"
                           { //Fix: Check if file exists
    axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", (yyvsp[0].str)), .kind=axo_c_include_decl_kind});
  }
#line 2002 "axo_gram.tab.c"
    break;

  case 5: /* declarations: declarations "#register" c_typ "identifier" '(' c_typ_list ')'  */
#line 162 "axo_gram.y"
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
#line 2026 "axo_gram.tab.c"
    break;

  case 6: /* declarations: declarations "enum" "identifier" '(' enum_names ')'  */
#line 181 "axo_gram.y"
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
#line 2065 "axo_gram.tab.c"
    break;

  case 7: /* declarations: declarations declaration  */
#line 215 "axo_gram.y"
                             {
    axo_add_decl(state, (yyvsp[0].declaration_type));
  }
#line 2073 "axo_gram.tab.c"
    break;

  case 8: /* declaration: struct_def  */
#line 220 "axo_gram.y"
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
#line 2103 "axo_gram.tab.c"
    break;

  case 9: /* declaration: "use" "identifier"  */
#line 245 "axo_gram.y"
               {
    printf("Using: %s\n", (yyvsp[0].str));
    printf("Searching for dir...\n");
    //Check local first
    if (axo_dir_exists((yyvsp[0].str)) == 1){
      printf("Found locally!\n");
    }else if (axo_dir_exists(fmt_str(static_str_ptr(500), "%s"axo_dir_sep"%s", state->root_path, (yyvsp[0].str)))){
      printf("Found in root path\n");
    }else
      yyerror(&(yylsp[0]), "Couldn't find '%s' locally.", (yyvsp[0].str));
  }
#line 2119 "axo_gram.tab.c"
    break;

  case 10: /* statements: statement  */
#line 258 "axo_gram.y"
                       {axo_add_statement(top_scope, (yyvsp[0].statement_type));}
#line 2125 "axo_gram.tab.c"
    break;

  case 11: /* statements: statements statement  */
#line 259 "axo_gram.y"
                         {axo_add_statement(top_scope, (yyvsp[0].statement_type));}
#line 2131 "axo_gram.tab.c"
    break;

  case 12: /* index_access: '[' expr  */
#line 262 "axo_gram.y"
                        {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.index_access_type) = (axo_index_access){
      .index_count=1,
      .indexes = (axo_expr*)malloc(128*sizeof(axo_expr))
    };
    (yyval.index_access_type).indexes[0] = (yyvsp[0].expression);
  }
#line 2144 "axo_gram.tab.c"
    break;

  case 13: /* index_access: index_access '|' expr  */
#line 270 "axo_gram.y"
                          {
    (yyval.index_access_type).indexes[(yyval.index_access_type).index_count++] = (yyvsp[0].expression);
  }
#line 2152 "axo_gram.tab.c"
    break;

  case 14: /* identifier: "identifier"  */
#line 275 "axo_gram.y"
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
#line 2172 "axo_gram.tab.c"
    break;

  case 15: /* incr_decr_op: expr "++"  */
#line 292 "axo_gram.y"
                            {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s++", (yyvsp[-1].expression).val);
  }
#line 2181 "axo_gram.tab.c"
    break;

  case 16: /* incr_decr_op: expr "--"  */
#line 296 "axo_gram.y"
                 {
    (yyval.expression).typ = (yyvsp[-1].expression).typ;
    (yyval.expression).val = fmtstr("%s--", (yyvsp[-1].expression).val);
  }
#line 2190 "axo_gram.tab.c"
    break;

  case 17: /* expr: "string literal"  */
#line 303 "axo_gram.y"
                      {set_val(&(yyval.expression), axo_str_typ(state), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind;}
#line 2196 "axo_gram.tab.c"
    break;

  case 18: /* expr: "integer literal"  */
#line 304 "axo_gram.y"
                    {set_val(&(yyval.expression), axo_int_typ(state), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2202 "axo_gram.tab.c"
    break;

  case 19: /* expr: "float literal"  */
#line 305 "axo_gram.y"
                  {set_val(&(yyval.expression), axo_float_typ(state), (yyvsp[0].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
#line 2208 "axo_gram.tab.c"
    break;

  case 20: /* expr: "null"  */
#line 306 "axo_gram.y"
           {
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val="((char*)(NULL))",
      .typ=axo_str_typ(state)
    };
  }
#line 2221 "axo_gram.tab.c"
    break;

  case 21: /* expr: expr '+' expr  */
#line 314 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "+", (yyvsp[0].expression)); }
#line 2227 "axo_gram.tab.c"
    break;

  case 22: /* expr: expr '-' expr  */
#line 315 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "-", (yyvsp[0].expression)); }
#line 2233 "axo_gram.tab.c"
    break;

  case 23: /* expr: '-' expr  */
#line 316 "axo_gram.y"
             {asprintf(&((yyval.expression).val), "-%s", (yyvsp[0].expression).val); (yyval.expression).typ = (yyvsp[0].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2239 "axo_gram.tab.c"
    break;

  case 24: /* expr: expr '*' expr  */
#line 317 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "*", (yyvsp[0].expression)); }
#line 2245 "axo_gram.tab.c"
    break;

  case 25: /* expr: expr '/' expr  */
#line 318 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "/", (yyvsp[0].expression)); }
#line 2251 "axo_gram.tab.c"
    break;

  case 26: /* expr: expr '%' expr  */
#line 319 "axo_gram.y"
                  {parse_operator(&(yylsp[-1]), &(yyval.expression), (yyvsp[-2].expression), "%", (yyvsp[0].expression)); }
#line 2257 "axo_gram.tab.c"
    break;

  case 27: /* expr: '(' expr ')'  */
#line 320 "axo_gram.y"
                 {asprintf(&((yyval.expression).val), "(%s)", (yyvsp[-1].expression).val); (yyval.expression).typ = (yyvsp[-1].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
#line 2263 "axo_gram.tab.c"
    break;

  case 28: /* expr: '@' expr  */
#line 321 "axo_gram.y"
             { //Referencing
    if ((yyvsp[0].expression).lval_kind == axo_not_lval_kind)
      yyerror(&(yylsp[0]), "Cannot reference a non l-value.");
    (yyval.expression).typ.kind = axo_ptr_kind;
    (yyval.expression).typ.subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp((yyval.expression).typ) = (yyvsp[0].expression).typ;
    asprintf(&((yyval.expression).val), "&%s", (yyvsp[0].expression).val);
  }
#line 2276 "axo_gram.tab.c"
    break;

  case 29: /* expr: expr '^'  */
#line 329 "axo_gram.y"
             { //Dereferencing
    if ((yyvsp[-1].expression).typ.kind != axo_ptr_kind)
      yyerror(&(yylsp[-1]), "Cannot dereference a value of non-pointer type '%s'.", axo_typ_to_str((yyvsp[-1].expression).typ));
    (yyval.expression).typ = *axo_subtyp((yyvsp[-1].expression).typ);
    asprintf(&((yyval.expression).val), "(*(%s))", (yyvsp[-1].expression).val);
  }
#line 2287 "axo_gram.tab.c"
    break;

  case 31: /* expr: identifier  */
#line 339 "axo_gram.y"
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
#line 2328 "axo_gram.tab.c"
    break;

  case 32: /* expr: expr '?' expr ':' expr  */
#line 375 "axo_gram.y"
                           {
    if (axo_validate_rval(&(yylsp[-4]), (yyvsp[-4].expression)) && axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      if (axo_typ_eq((yyvsp[-2].expression).typ, (yyvsp[0].expression).typ)){
        (yyval.expression) = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", (yyvsp[-4].expression).val, (yyvsp[-2].expression).val, (yyvsp[0].expression).val),
          .typ=(yyvsp[-2].expression).typ
        };
      }else{
        yyerror(&(yyloc), "Ternary expression cannot return both '%s' and '%s'.", axo_typ_to_str((yyvsp[-2].expression).typ), axo_typ_to_str((yyvsp[0].expression).typ));
      }
    }
  }
#line 2347 "axo_gram.tab.c"
    break;

  case 33: /* expr: func_call  */
#line 389 "axo_gram.y"
              {(yyval.expression) = axo_call_to_expr((yyvsp[0].function_call));}
#line 2353 "axo_gram.tab.c"
    break;

  case 34: /* expr: expr '<' expr  */
#line 390 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2365 "axo_gram.tab.c"
    break;

  case 35: /* expr: expr '>' expr  */
#line 397 "axo_gram.y"
                  {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2377 "axo_gram.tab.c"
    break;

  case 36: /* expr: expr "==" expr  */
#line 404 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s==%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2389 "axo_gram.tab.c"
    break;

  case 37: /* expr: expr "!=" expr  */
#line 411 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s!=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2401 "axo_gram.tab.c"
    break;

  case 38: /* expr: expr ">=" expr  */
#line 418 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2413 "axo_gram.tab.c"
    break;

  case 39: /* expr: expr "<=" expr  */
#line 425 "axo_gram.y"
                   {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<=%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
    };
  }
#line 2425 "axo_gram.tab.c"
    break;

  case 40: /* expr: expr "or" expr  */
#line 432 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = axo_bool_typ(state),
        .val = fmtstr("%s||%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2439 "axo_gram.tab.c"
    break;

  case 41: /* expr: expr "and" expr  */
#line 441 "axo_gram.y"
                    {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s&&%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2453 "axo_gram.tab.c"
    break;

  case 42: /* expr: expr ">>" expr  */
#line 450 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s>>%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2467 "axo_gram.tab.c"
    break;

  case 43: /* expr: expr "<<" expr  */
#line 459 "axo_gram.y"
                   {
    if (axo_validate_rval(&(yylsp[-2]), (yyvsp[-2].expression)) && axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[-2].expression).typ,
        .val = fmtstr("%s<<%s", (yyvsp[-2].expression).val, (yyvsp[0].expression).val)
      };
    }
  }
#line 2481 "axo_gram.tab.c"
    break;

  case 44: /* expr: struct_literal  */
#line 468 "axo_gram.y"
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
#line 2509 "axo_gram.tab.c"
    break;

  case 45: /* expr: expr index_access ']'  */
#line 491 "axo_gram.y"
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
#line 2540 "axo_gram.tab.c"
    break;

  case 46: /* expr: expr ".field"  */
#line 517 "axo_gram.y"
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
#line 2623 "axo_gram.tab.c"
    break;

  case 49: /* expr: expr '.' '(' val_typ ')'  */
#line 597 "axo_gram.y"
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
#line 2657 "axo_gram.tab.c"
    break;

  case 50: /* stat_arr_literal_start: '[' expr ',' expr  */
#line 628 "axo_gram.y"
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
#line 2677 "axo_gram.tab.c"
    break;

  case 51: /* stat_arr_literal_start: empty_arr_dims ']' '[' expr ',' expr  */
#line 643 "axo_gram.y"
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
#line 2697 "axo_gram.tab.c"
    break;

  case 52: /* stat_arr_literal_start: stat_arr_literal_start ',' expr  */
#line 658 "axo_gram.y"
                                    {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    if (!axo_typ_eq((yyval.arr_lit_type).typ, (yyvsp[0].expression).typ)){
            yyerror(&(yylsp[0]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[0].expression).typ), axo_typ_to_str((yyval.arr_lit_type).typ));
    }
    strapnd(&(yyval.arr_lit_type).val, ",");
    strapnd(&(yyval.arr_lit_type).val, (yyvsp[0].expression).val);
    (yyval.arr_lit_type).count++;
  }
#line 2711 "axo_gram.tab.c"
    break;

  case 53: /* stat_arr_literal: '[' expr ',' ']'  */
#line 669 "axo_gram.y"
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
#line 2726 "axo_gram.tab.c"
    break;

  case 54: /* stat_arr_literal: stat_arr_literal_start ']'  */
#line 679 "axo_gram.y"
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
#line 2752 "axo_gram.tab.c"
    break;

  case 55: /* arr_literal: stat_arr_literal  */
#line 702 "axo_gram.y"
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
#line 2772 "axo_gram.tab.c"
    break;

  case 56: /* arr_literal: empty_arr_dims ']' val_typ  */
#line 717 "axo_gram.y"
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
#line 2804 "axo_gram.tab.c"
    break;

  case 57: /* empty_arr_dims: '?' '[' "integer literal"  */
#line 746 "axo_gram.y"
                                         {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=true,
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[0].str));
  }
#line 2817 "axo_gram.tab.c"
    break;

  case 58: /* empty_arr_dims: '[' "integer literal"  */
#line 754 "axo_gram.y"
                        {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=false,
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[0].str));
  }
#line 2830 "axo_gram.tab.c"
    break;

  case 59: /* empty_arr_dims: empty_arr_dims '|' "integer literal"  */
#line 762 "axo_gram.y"
                                       {
    (yyval.empty_arr_lit_type)=(yyvsp[-2].empty_arr_lit_type);
    (yyval.empty_arr_lit_type).len[(yyval.empty_arr_lit_type).dim_count++] = atoi((yyvsp[0].str));
  }
#line 2839 "axo_gram.tab.c"
    break;

  case 62: /* matching_statement: expr  */
#line 770 "axo_gram.y"
                          {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2850 "axo_gram.tab.c"
    break;

  case 63: /* matching_statement: '$' expr  */
#line 776 "axo_gram.y"
             {
    (yyval.statement_type).val = (yyvsp[0].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
#line 2860 "axo_gram.tab.c"
    break;

  case 64: /* matching_statement: "ret" expr  */
#line 781 "axo_gram.y"
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
#line 2877 "axo_gram.tab.c"
    break;

  case 65: /* matching_statement: code_scope  */
#line 793 "axo_gram.y"
               {
    (yyval.statement_type) = axo_scope_to_statement((yyvsp[0].scope));
  }
#line 2885 "axo_gram.tab.c"
    break;

  case 66: /* matching_statement: expr "is" val_typ  */
#line 796 "axo_gram.y"
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
#line 2909 "axo_gram.tab.c"
    break;

  case 67: /* matching_statement: "continue"  */
#line 815 "axo_gram.y"
               {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to continue.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = "continue;"
    };
  }
#line 2921 "axo_gram.tab.c"
    break;

  case 68: /* matching_statement: "break"  */
#line 822 "axo_gram.y"
            {
    if (in_loop_count<=0) yyerror(&(yylsp[0]), "No loop to break out of.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = "break;"
    };
  }
#line 2933 "axo_gram.tab.c"
    break;

  case 73: /* if_condition: "if" expr  */
#line 835 "axo_gram.y"
                            {
    axo_validate_rval(&(yylsp[0]), (yyvsp[0].expression));
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2942 "axo_gram.tab.c"
    break;

  case 74: /* matching_if_statement: if_condition matching_statement "else" matching_statement  */
#line 841 "axo_gram.y"
                                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2950 "axo_gram.tab.c"
    break;

  case 79: /* non_matching_if_statement: if_condition statement  */
#line 852 "axo_gram.y"
                                                   {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s", (yyvsp[-1].expression).val, (yyvsp[0].statement_type).val);
  }
#line 2958 "axo_gram.tab.c"
    break;

  case 80: /* non_matching_if_statement: if_condition matching_statement "else" non_matching_statement  */
#line 855 "axo_gram.y"
                                                                     {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s\nelse\n%s", (yyvsp[-3].expression).val, (yyvsp[-2].statement_type).val, (yyvsp[0].statement_type).val);
  }
#line 2966 "axo_gram.tab.c"
    break;

  case 81: /* till_loop_start: "till" '(' "identifier" '=' expr ')'  */
#line 860 "axo_gram.y"
                                                   {
    (yyval.till_loop_type).iter = (yyvsp[-3].str);
    (yyval.till_loop_type).start = "0";
    (yyval.till_loop_type).lim = (yyvsp[-1].expression);
    printf("till iter %s created scope\n", (yyval.till_loop_type).iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=state->int_def->typ, .name=(yyval.till_loop_type).iter, .is_const=false});
  }
#line 2979 "axo_gram.tab.c"
    break;

  case 82: /* while_loop_base: "while" '(' expr ')'  */
#line 870 "axo_gram.y"
                                       {
    if (axo_validate_rval(&(yylsp[-1]), (yyvsp[-1].expression)))
      (yyval.str) = alloc_str((yyvsp[-1].expression).val);
    in_loop_count++;
  }
#line 2989 "axo_gram.tab.c"
    break;

  case 83: /* matching_while: while_loop_base matching_statement  */
#line 877 "axo_gram.y"
                                                    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 3001 "axo_gram.tab.c"
    break;

  case 84: /* non_matching_while: while_loop_base non_matching_statement  */
#line 886 "axo_gram.y"
                                                            {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[-1].str), (yyvsp[0].statement_type).val),
    };
    in_loop_count--;
  }
#line 3013 "axo_gram.tab.c"
    break;

  case 85: /* for_loop_start: "for"  */
#line 895 "axo_gram.y"
                       {
    axo_push_scope(scopes, axo_new_scope(top_scope));
  }
#line 3021 "axo_gram.tab.c"
    break;

  case 86: /* for_loop_init: for_loop_start statement  */
#line 900 "axo_gram.y"
                                         {
    (yyval.for_loop_type).start = (yyvsp[0].statement_type).val;
  }
#line 3029 "axo_gram.tab.c"
    break;

  case 87: /* for_loop_base: for_loop_init ',' expr ',' statement  */
#line 905 "axo_gram.y"
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
#line 3045 "axo_gram.tab.c"
    break;

  case 88: /* for_loop_base: till_loop_start  */
#line 916 "axo_gram.y"
                    {
    (yyval.for_loop_type) = (axo_for_loop){
      .start = fmtstr("int %s=%s;", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).start),
      .condition = fmtstr("%s<%s", (yyvsp[0].till_loop_type).iter, (yyvsp[0].till_loop_type).lim.val),
      .iteration = fmtstr("%s++", (yyvsp[0].till_loop_type).iter),
    };
    in_loop_count++;
  }
#line 3058 "axo_gram.tab.c"
    break;

  case 89: /* matching_for_loop: for_loop_base matching_statement  */
#line 927 "axo_gram.y"
                                                     {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3070 "axo_gram.tab.c"
    break;

  case 90: /* non_matching_for_loop: for_loop_base non_matching_statement  */
#line 935 "axo_gram.y"
                                                             {
    (yyvsp[-1].for_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[-1].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3082 "axo_gram.tab.c"
    break;

  case 91: /* each_iter_dims: '[' expr  */
#line 944 "axo_gram.y"
                          {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=1,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3] = (yylsp[0]);
  }
#line 3096 "axo_gram.tab.c"
    break;

  case 92: /* each_iter_dims: '[' '|' expr  */
#line 953 "axo_gram.y"
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
#line 3111 "axo_gram.tab.c"
    break;

  case 93: /* each_iter_dims: each_iter_dims '|' expr  */
#line 963 "axo_gram.y"
                            {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count] = (yyvsp[0].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3+(yyval.each_loop_type).dim_count++] = (yylsp[0]);
  }
#line 3120 "axo_gram.tab.c"
    break;

  case 94: /* each_iter_dims: each_iter_dims '|'  */
#line 967 "axo_gram.y"
                       {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count++] = (axo_expr){.kind=axo_no_kind, .val=NULL};
  }
#line 3128 "axo_gram.tab.c"
    break;

  case 95: /* each_loop_start: "for" "each"  */
#line 972 "axo_gram.y"
                               {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    in_loop_count++;
  }
#line 3137 "axo_gram.tab.c"
    break;

  case 96: /* each_loop_base: each_loop_start identifier "in" expr  */
#line 978 "axo_gram.y"
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
#line 3156 "axo_gram.tab.c"
    break;

  case 97: /* each_loop_base: each_loop_start identifier ',' each_iter_dims ']' "in" expr  */
#line 992 "axo_gram.y"
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
#line 3175 "axo_gram.tab.c"
    break;

  case 98: /* each_loop_base: each_loop_start each_iter_dims ']' ',' identifier "in" expr  */
#line 1006 "axo_gram.y"
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
#line 3194 "axo_gram.tab.c"
    break;

  case 99: /* each_loop_base: each_loop_start each_iter_dims ']' "in" expr  */
#line 1020 "axo_gram.y"
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
#line 3212 "axo_gram.tab.c"
    break;

  case 100: /* matching_each_loop: each_loop_base matching_statement  */
#line 1036 "axo_gram.y"
                                                       {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3223 "axo_gram.tab.c"
    break;

  case 101: /* non_matching_each_loop: each_loop_base non_matching_statement  */
#line 1044 "axo_gram.y"
                                                               {
    (yyvsp[-1].each_loop_type).body = (yyvsp[0].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[-1].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
#line 3234 "axo_gram.tab.c"
    break;

  case 102: /* assign_op: '='  */
#line 1052 "axo_gram.y"
                {
    rval_now = true;
  }
#line 3242 "axo_gram.tab.c"
    break;

  case 103: /* assignment: expr assign_op expr  */
#line 1057 "axo_gram.y"
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
#line 3271 "axo_gram.tab.c"
    break;

  case 104: /* arr_multidim_typ: '[' '|'  */
#line 1083 "axo_gram.y"
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
#line 3286 "axo_gram.tab.c"
    break;

  case 105: /* arr_multidim_typ: arr_multidim_typ '|'  */
#line 1093 "axo_gram.y"
                         {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_get_arr_typ((yyval.typ_type)).dim_count++;
  }
#line 3295 "axo_gram.tab.c"
    break;

  case 106: /* arr_typ: '[' ']' val_typ  */
#line 1099 "axo_gram.y"
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
#line 3311 "axo_gram.tab.c"
    break;

  case 107: /* arr_typ: arr_multidim_typ ']' val_typ  */
#line 1110 "axo_gram.y"
                                 {
    (yyval.typ_type) = (yyvsp[-2].typ_type);
    axo_get_arr_typ((yyval.typ_type)).subtyp = (yyvsp[0].typ_type);
  }
#line 3320 "axo_gram.tab.c"
    break;

  case 108: /* func_typ_start: '(' val_typ "fn"  */
#line 1116 "axo_gram.y"
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
#line 3336 "axo_gram.tab.c"
    break;

  case 109: /* func_typ_start: '(' "fn"  */
#line 1127 "axo_gram.y"
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
#line 3352 "axo_gram.tab.c"
    break;

  case 110: /* func_typ_args: func_typ_start val_typ  */
#line 1140 "axo_gram.y"
                                       {
    (yyval.typ_type)=(yyvsp[-1].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = (yyvsp[0].typ_type);
    func_typ->args_defs[0] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 3366 "axo_gram.tab.c"
    break;

  case 111: /* func_typ_args: func_typ_args ',' val_typ  */
#line 1149 "axo_gram.y"
                              {
    (yyval.typ_type)=(yyvsp[-2].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = (yyvsp[0].typ_type);
    func_typ->args_defs[func_typ->args_len] = axo_typ_def_val((yyvsp[0].typ_type));
    func_typ->args_len++;
  }
#line 3380 "axo_gram.tab.c"
    break;

  case 112: /* func_typ: func_typ_start ')'  */
#line 1160 "axo_gram.y"
                              {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 3386 "axo_gram.tab.c"
    break;

  case 113: /* func_typ: func_typ_args ')'  */
#line 1161 "axo_gram.y"
                      {(yyval.typ_type)=(yyvsp[-1].typ_type);}
#line 3392 "axo_gram.tab.c"
    break;

  case 114: /* val_typ: "identifier"  */
#line 1164 "axo_gram.y"
               {
    axo_typ_def* def = axo_get_typ_def(state, (yyvsp[0].str));
    if (def==NULL)
      yyerror(&(yylsp[0]), "Type '%s' isn't defined.", (yyvsp[0].str));
    else
      (yyval.typ_type)=def->typ;
  }
#line 3404 "axo_gram.tab.c"
    break;

  case 115: /* val_typ: '@' val_typ  */
#line 1171 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_ptr_kind;
    (yyval.typ_type).subtyp = malloc(sizeof(axo_typ));
    *axo_subtyp((yyval.typ_type))=(yyvsp[0].typ_type);
  }
#line 3414 "axo_gram.tab.c"
    break;

  case 119: /* c_typ: '.' '.' '.'  */
#line 1181 "axo_gram.y"
                {
    (yyval.typ_type).kind = axo_c_arg_list_kind;
  }
#line 3422 "axo_gram.tab.c"
    break;

  case 120: /* c_typ_list: %empty  */
#line 1186 "axo_gram.y"
                           {
    (yyval.types_list).len = 0;
    (yyval.types_list).values = NULL;
  }
#line 3431 "axo_gram.tab.c"
    break;

  case 121: /* c_typ_list: c_typ  */
#line 1190 "axo_gram.y"
          {
    (yyval.types_list).values = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.types_list).values[0] = (yyvsp[0].typ_type);
    (yyval.types_list).len = 1;
  }
#line 3441 "axo_gram.tab.c"
    break;

  case 122: /* c_typ_list: c_typ_list ',' c_typ  */
#line 1195 "axo_gram.y"
                         {
    if ((yyvsp[-2].types_list).values[(yyvsp[-2].types_list).len-1].kind == axo_c_arg_list_kind)
      yyerror(&(yylsp[-2]), "The C v_args argument has to be the last one.");
    (yyval.types_list) = (yyvsp[-2].types_list);
    if ((yyval.types_list).len % axo_func_args_cap == 0)
      (yyval.types_list).values = (axo_typ*)realloc((yyval.types_list).values, ((yyval.types_list).len+axo_func_args_cap)*sizeof(axo_typ));
    (yyval.types_list).values[(yyval.types_list).len] = (yyvsp[0].typ_type);
    (yyval.types_list).len++;
  }
#line 3455 "axo_gram.tab.c"
    break;

  case 123: /* func_call_start: expr '('  */
#line 1206 "axo_gram.y"
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
#line 3480 "axo_gram.tab.c"
    break;

  case 124: /* func_call_start: expr ':' "identifier" '('  */
#line 1226 "axo_gram.y"
                     {
    //TODO: Methods
  }
#line 3488 "axo_gram.tab.c"
    break;

  case 125: /* func_call_start: expr '(' expr  */
#line 1229 "axo_gram.y"
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
#line 3520 "axo_gram.tab.c"
    break;

  case 126: /* func_call_start: func_call_start ',' expr  */
#line 1256 "axo_gram.y"
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
#line 3541 "axo_gram.tab.c"
    break;

  case 127: /* func_call_start: func_call_start ','  */
#line 1272 "axo_gram.y"
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
#line 3559 "axo_gram.tab.c"
    break;

  case 128: /* func_call: func_call_start ')'  */
#line 1287 "axo_gram.y"
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
#line 3579 "axo_gram.tab.c"
    break;

  case 129: /* code_scope_start: '{'  */
#line 1304 "axo_gram.y"
                       {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
#line 3588 "axo_gram.tab.c"
    break;

  case 130: /* code_scope: code_scope_start statements '}'  */
#line 1310 "axo_gram.y"
                                             {
    (yyval.scope) = top_scope;
    scopes->len--;
    if ((yyval.scope)->statements_len == 0)
      yyerror(&(yyloc), "Code scopes cannot be empty.");
  }
#line 3599 "axo_gram.tab.c"
    break;

  case 131: /* func_def_start: "fn" "identifier" '(' func_args ')'  */
#line 1318 "axo_gram.y"
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
#line 3615 "axo_gram.tab.c"
    break;

  case 132: /* func_def_start: "fn" val_typ "identifier" '(' func_args ')'  */
#line 1329 "axo_gram.y"
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
#line 3632 "axo_gram.tab.c"
    break;

  case 133: /* struct_def: "struct" "identifier" '(' func_args ')'  */
#line 1343 "axo_gram.y"
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
#line 3649 "axo_gram.tab.c"
    break;

  case 134: /* struct_literal_start: "struct{"  */
#line 1356 "axo_gram.y"
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
#line 3670 "axo_gram.tab.c"
    break;

  case 135: /* struct_literal_start: "struct{" expr  */
#line 1372 "axo_gram.y"
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
#line 3696 "axo_gram.tab.c"
    break;

  case 136: /* struct_literal_start: "struct{" "identifier" '=' expr  */
#line 1393 "axo_gram.y"
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
#line 3731 "axo_gram.tab.c"
    break;

  case 137: /* struct_literal_start: struct_literal_start ',' expr  */
#line 1423 "axo_gram.y"
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
#line 3750 "axo_gram.tab.c"
    break;

  case 138: /* struct_literal_start: struct_literal_start ','  */
#line 1437 "axo_gram.y"
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
#line 3765 "axo_gram.tab.c"
    break;

  case 139: /* struct_literal_start: struct_literal_start ',' "identifier" '=' expr  */
#line 1447 "axo_gram.y"
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
#line 3789 "axo_gram.tab.c"
    break;

  case 140: /* struct_literal: struct_literal_start '}'  */
#line 1468 "axo_gram.y"
                                          {
    (yyval.struct_val_type)=(yyvsp[-1].struct_val_type);
    axo_struct* structure = ((axo_struct*)(yyval.struct_val_type).typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if((yyval.struct_val_type).fields[i] == NULL) (yyval.struct_val_type).fields[i] = structure->fields[i].def.val;
    }
  }
#line 3801 "axo_gram.tab.c"
    break;

  case 141: /* func_def: func_def_start code_scope  */
#line 1477 "axo_gram.y"
                                     {
    (yyval.function) = (yyvsp[-1].function);
    (yyval.function).body = (yyvsp[0].scope);
    (yyval.function).f_typ.ret_typ = axo_is_no_typ((yyvsp[0].scope)->ret_typ) ? axo_none_typ : (yyvsp[0].scope)->ret_typ;
    axo_func_typ* fnt_ptr = (axo_func_typ*)malloc(sizeof(axo_func_typ));
    *fnt_ptr = (yyval.function).f_typ;
    axo_typ typ = (axo_typ){
      .kind=axo_func_kind,
      .func_typ=fnt_ptr,
      .def=(yyval.function).f_typ.args_defs
    };
    axo_set_var(state->global_scope, (axo_var){.name=(yyval.function).name, .typ=typ, .is_const=true});
  }
#line 3819 "axo_gram.tab.c"
    break;

  case 142: /* func_arg: val_typ "identifier"  */
#line 1492 "axo_gram.y"
                        {
    (yyval.function_argument).name = alloc_str((yyvsp[0].str));
    (yyval.function_argument).typ = (yyvsp[-1].typ_type);
    (yyval.function_argument).def = (yyvsp[-1].typ_type).def;
  }
#line 3829 "axo_gram.tab.c"
    break;

  case 143: /* func_arg: "identifier" '|' expr  */
#line 1497 "axo_gram.y"
                  {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[0].expression).typ;
    (yyval.function_argument).def = (yyvsp[0].expression).val;
  }
#line 3839 "axo_gram.tab.c"
    break;

  case 144: /* func_arg: val_typ "identifier" '|' expr  */
#line 1502 "axo_gram.y"
                          {
    (yyval.function_argument).name = alloc_str((yyvsp[-2].str));
    (yyval.function_argument).typ = (yyvsp[-3].typ_type);
    (yyval.function_argument).def = (yyvsp[0].expression).val; //FIX! Look if types match!
  }
#line 3849 "axo_gram.tab.c"
    break;

  case 145: /* func_args: %empty  */
#line 1509 "axo_gram.y"
                            {
    (yyval.function).args_names = NULL;
    (yyval.function).f_typ.args_defs = NULL;
    (yyval.function).f_typ.args_types = NULL;
    (yyval.function).f_typ.args_len = 0;
  }
#line 3860 "axo_gram.tab.c"
    break;

  case 146: /* func_args: func_arg  */
#line 1515 "axo_gram.y"
             {
    (yyval.function).args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.function).args_names[0] = (yyvsp[0].function_argument).name;
    (yyval.function).f_typ.args_defs[0] = (yyvsp[0].function_argument).def;
    (yyval.function).f_typ.args_types[0] = (yyvsp[0].function_argument).typ;
    (yyval.function).f_typ.args_len = 1;
  }
#line 3874 "axo_gram.tab.c"
    break;

  case 147: /* func_args: func_args ',' func_arg  */
#line 1524 "axo_gram.y"
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
#line 3889 "axo_gram.tab.c"
    break;

  case 148: /* enum_names: "identifier"  */
#line 1536 "axo_gram.y"
                  {
    (yyval.enum_type).names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    (yyval.enum_type).names[0] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len = 1;
  }
#line 3899 "axo_gram.tab.c"
    break;

  case 149: /* enum_names: enum_names ',' "identifier"  */
#line 1541 "axo_gram.y"
                        {
    (yyval.enum_type) = (yyvsp[-2].enum_type);
    if ((yyval.enum_type).len % axo_enum_names_cap == 0)
    (yyval.enum_type).names = (char**)realloc((yyval.enum_type).names, ((yyval.enum_type).len+axo_enum_names_cap)*sizeof(char*));
    (yyval.enum_type).names[(yyval.enum_type).len] = alloc_str((yyvsp[0].str));
    (yyval.enum_type).len++;
  }
#line 3911 "axo_gram.tab.c"
    break;


#line 3915 "axo_gram.tab.c"

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

#line 1550 "axo_gram.y"


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
  char* root_p = axo_get_parent_dir(axo_get_exec_path((char[512]){}, 512));
  state = axo_new_state(root_p);
  printf("Root: %s\n", root_p);
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
  // if (state->config.delete_c)
  //   remove();
  return prog_return;
}
