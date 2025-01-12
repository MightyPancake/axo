/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "axo_gram.y"

  #define test_playground 0
  #include "src/utils/utils.h"
  #include <stdint.h>
  #include "src/axo.h"
  #include "axo_gram.tab.h"
  //Bison extern
  extern int yylineno;
  extern YYLTYPE yylloc;
  extern YYSTYPE yylval;
  YY_DECL;
  //For returning from comptime
  extern axo_expr ret_expr;
  extern char* ret_declarations;
  
  void yyerror(yyscan_t scanner, YYLTYPE* loc, const char * fmt, ...);
  void axo_yyerror(YYLTYPE* loc, const char * fmt, ...);
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
        axo_yyerror(LOC, axo_err_msg(axo_undeclared_assignment_expr_err_code)); \
      else if (EXPR.lval_kind==axo_var_lval_kind) \
        axo_yyerror(LOC, axo_err_msg(axo_undeclared_var_err_code)); \
      else \
        axo_yyerror(LOC, axo_err_msg(axo_invalid_rval_err_code)); \
    } \
    AXO_RVAL_WAS_VALID; \
  })

  #define axo_is_valid_expr_as_statement(EXPR) (((EXPR).typ.kind!=axo_no_kind))
  #define axo_validate_expr_as_statement(LOC, EXPR) ({ \
    AXO_RVAL_WAS_VALID=true; \
    if (!axo_is_valid_expr_as_statement(EXPR)){ \
      AXO_RVAL_WAS_VALID=false; \
      if (EXPR.lval_kind==axo_var_lval_kind) \
        axo_yyerror(LOC, axo_err_msg(axo_undeclared_var_err_code)); \
      else \
        axo_yyerror(LOC, axo_err_msg(axo_invalid_rval_err_code)); \
    } \
    AXO_RVAL_WAS_VALID; \
  })
  
  #define axo_none_check(T) ((T).kind == axo_none_kind)

/* Line 371 of yacc.c  */
#line 134 "axo_gram.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "axo_gram.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 283 "axo_gram.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 323 "axo_gram.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1788

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNRULES -- Number of states.  */
#define YYNSTATES  377

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,     2,     2,    71,    81,     2,     2,
      85,    94,    79,    77,    99,    78,    83,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    95,
      75,    73,    76,    74,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    91,     2,   100,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    96,    98,    97,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    72,    82,    89,    90,
      92,    93
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    22,    25,
      27,    34,    38,    41,    44,    48,    51,    54,    56,    59,
      62,    64,    68,    70,    73,    75,    79,    85,    87,    92,
      93,    96,    99,   103,   105,   108,   111,   113,   116,   118,
     121,   125,   127,   129,   131,   133,   135,   137,   141,   145,
     149,   152,   156,   160,   164,   168,   171,   174,   176,   178,
     180,   186,   188,   192,   196,   200,   204,   208,   212,   216,
     219,   223,   227,   231,   233,   237,   240,   245,   250,   252,
     254,   256,   258,   260,   266,   268,   273,   280,   284,   286,
     289,   292,   296,   301,   304,   306,   310,   312,   314,   316,
     318,   321,   324,   326,   331,   333,   335,   337,   340,   345,
     347,   349,   351,   353,   356,   361,   364,   368,   372,   374,
     377,   379,   383,   386,   391,   393,   395,   397,   399,   402,
     407,   414,   417,   420,   423,   425,   428,   434,   436,   439,
     442,   445,   448,   451,   455,   459,   462,   467,   475,   482,
     484,   488,   492,   496,   500,   504,   508,   511,   514,   518,
     522,   526,   529,   532,   536,   539,   542,   544,   547,   549,
     551,   553,   557,   559,   562,   564,   567,   569,   571,   574,
     579,   581,   584,   588,   591,   594,   596,   600,   602,   606,
     610,   612,   615,   621,   623,   626,   631,   635,   638,   644,
     647,   650,   653,   657,   662,   663,   665,   669,   671
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,   103,    -1,    68,   116,    -1,    -1,   103,
     169,    -1,   103,    11,    -1,   103,    44,     6,    85,   172,
      94,    -1,   103,   104,    -1,   108,    -1,   165,   164,    85,
     171,    94,    95,    -1,    13,   156,     6,    -1,    46,     6,
      -1,    47,     3,    -1,    50,   109,    94,    -1,    12,     6,
      -1,    12,   108,    -1,   107,    -1,    61,     3,    -1,    60,
       3,    -1,   105,    -1,     6,    51,   156,    -1,    69,    -1,
      62,     3,    -1,    96,    -1,   106,   110,    97,    -1,    45,
       6,    85,   171,    94,    -1,    85,    -1,   109,     6,    86,
       3,    -1,    -1,   110,   122,    -1,    91,   116,    -1,   111,
      98,   116,    -1,     6,    -1,   116,    35,    -1,   116,    36,
      -1,    66,    -1,   115,    94,    -1,    67,    -1,    67,   116,
      -1,   115,    99,   116,    -1,     3,    -1,     4,    -1,     5,
      -1,   114,    -1,    53,    -1,    34,    -1,     6,    64,     6,
      -1,   116,    77,   116,    -1,   116,    78,   116,    -1,    78,
     116,    -1,   116,    79,   116,    -1,   116,    80,   116,    -1,
     116,    81,   116,    -1,    85,   116,    94,    -1,   116,    87,
      -1,   116,    83,    -1,   148,    -1,   149,    -1,   112,    -1,
     116,    74,   116,    86,   116,    -1,   161,    -1,   116,    75,
     116,    -1,   116,    76,   116,    -1,   116,    23,   116,    -1,
     116,    24,   116,    -1,   116,    25,   116,    -1,   116,    26,
     116,    -1,   116,    29,   116,    -1,    84,   116,    -1,   116,
      30,   116,    -1,   116,    32,   116,    -1,   116,    31,   116,
      -1,   168,    -1,   116,   111,   100,    -1,   116,    49,    -1,
      54,    85,   116,    94,    -1,    55,    85,   156,    94,    -1,
      57,    -1,    58,    -1,    59,    -1,   121,    -1,   113,    -1,
     116,    83,    85,   156,    94,    -1,    71,    -1,   118,   116,
      99,   116,    -1,   119,   100,    91,   116,    99,   116,    -1,
     117,    99,   116,    -1,    91,    -1,    91,    74,    -1,   118,
       4,    -1,   119,    98,     4,    -1,   118,   116,    99,   100,
      -1,   117,   100,    -1,   120,    -1,   119,   100,   156,    -1,
     123,    -1,   132,    -1,   116,    -1,    95,    -1,     7,   116,
      -1,     7,    95,    -1,   163,    -1,   116,    73,    52,   156,
      -1,     9,    -1,     8,    -1,   125,    -1,    56,   123,    -1,
     157,   112,    73,   116,    -1,   131,    -1,   141,    -1,   136,
      -1,   143,    -1,    16,   116,    -1,   124,    96,   126,    97,
      -1,   127,   122,    -1,   126,   127,   122,    -1,   128,    52,
       8,    -1,   128,    -1,   129,    17,    -1,   116,    -1,   129,
      99,   116,    -1,    21,   116,    -1,   130,   123,    22,   123,
      -1,   133,    -1,   142,    -1,   137,    -1,   144,    -1,   130,
     122,    -1,   130,   123,    22,   132,    -1,    33,    85,     6,
      73,   116,    94,    -1,    15,   116,    -1,   135,   123,    -1,
     135,   132,    -1,    18,    -1,   138,   122,    -1,   139,    99,
     116,    99,   122,    -1,   134,    -1,   140,   123,    -1,   140,
     132,    -1,   146,   123,    -1,   146,   132,    -1,    91,   116,
      -1,    91,    98,   116,    -1,   145,    98,   116,    -1,   145,
      98,    -1,   138,   112,    20,   116,    -1,   138,   112,    19,
     145,   100,    20,   116,    -1,   138,    19,   145,   100,    20,
     116,    -1,    73,    -1,   116,   147,   116,    -1,   116,    37,
     116,    -1,   116,    38,   116,    -1,   116,    39,   116,    -1,
     116,    40,   116,    -1,   116,    41,   116,    -1,    91,    98,
      -1,   150,    98,    -1,    91,   100,   156,    -1,   150,   100,
     156,    -1,    85,   156,    14,    -1,    85,    14,    -1,   152,
     156,    -1,   153,    99,   156,    -1,   152,    94,    -1,   153,
      94,    -1,     6,    -1,    87,   156,    -1,    52,    -1,   154,
      -1,   151,    -1,    83,    83,    83,    -1,   155,    -1,   157,
     155,    -1,   158,    -1,   157,   158,    -1,    63,    -1,    65,
      -1,   116,    85,    -1,   116,    86,     6,    85,    -1,   159,
      -1,   159,   116,    -1,   160,    99,   116,    -1,   160,    99,
      -1,   160,    94,    -1,    96,    -1,   162,   110,    97,    -1,
       6,    -1,     6,    64,     6,    -1,   156,    86,     6,    -1,
      14,    -1,   156,    14,    -1,   165,   164,    85,   171,    94,
      -1,    48,    -1,    48,   116,    -1,    48,     6,    73,   116,
      -1,   167,    99,   116,    -1,   167,    99,    -1,   167,    99,
       6,    73,   116,    -1,   167,    97,    -1,   166,   163,    -1,
     156,     6,    -1,     6,    73,   116,    -1,   156,     6,    73,
     116,    -1,    -1,   170,    -1,   171,    99,   170,    -1,     6,
      -1,   172,    99,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   218,   218,   221,   226,   229,   233,   251,   285,   291,
     318,   353,   360,   363,   366,   370,   378,   392,   396,   409,
     416,   422,   434,   447,   454,   461,   467,   487,   490,   516,
     517,   523,   532,   538,   554,   559,   566,   581,   610,   617,
     625,   632,   634,   643,   644,   645,   646,   654,   670,   671,
     672,   673,   674,   675,   676,   682,   692,   701,   702,   703,
     741,   758,   759,   770,   781,   792,   803,   814,   825,   834,
     845,   854,   863,   872,   895,   924,   928,   937,   946,   954,
     962,   970,   971,   972,  1003,  1018,  1033,  1048,  1059,  1062,
    1067,  1076,  1082,  1098,  1130,  1145,  1174,  1174,  1176,  1182,
    1188,  1207,  1224,  1228,  1242,  1249,  1256,  1259,  1267,  1284,
    1285,  1286,  1287,  1290,  1300,  1310,  1318,  1325,  1329,  1332,
    1346,  1354,  1360,  1366,  1371,  1372,  1373,  1374,  1377,  1380,
    1385,  1395,  1402,  1411,  1420,  1426,  1431,  1441,  1451,  1459,
    1468,  1476,  1484,  1493,  1503,  1507,  1512,  1526,  1540,  1555,
    1560,  1592,  1595,  1598,  1601,  1604,  1609,  1619,  1625,  1638,
    1646,  1657,  1670,  1679,  1690,  1691,  1694,  1702,  1710,  1713,
    1714,  1715,  1723,  1727,  1734,  1735,  1743,  1746,  1751,  1771,
    1777,  1785,  1801,  1817,  1832,  1855,  1861,  1867,  1873,  1883,
    1917,  1922,  1929,  1974,  1990,  2011,  2042,  2056,  2066,  2088,
    2097,  2115,  2122,  2129,  2143,  2149,  2158,  2170,  2175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"string literal\"",
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
  "\"volatile\"", "COMPTIME_VAR", "COMPTIME_CALL",
  "AXO_EXPR_AS_PARSE_RESULT", "\"comptime lua block\"", "IDENTIFIER_PREC",
  "'$'", "EXPR_AS_STATEMENT", "'='", "'?'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "LOOP_PREC", "'.'", "'!'", "'('", "':'", "'@'",
  "'^'", "UMINUS", "CALL_PREC", "'['", "TYPE_Q_PREC",
  "STRUCT_LIT_NAMED_FIELD", "')'", "';'", "'{'", "'}'", "'|'", "','",
  "']'", "$accept", "code", "declarations", "declaration", "c_code",
  "global_code_scope_start", "global_code_scope", "struct_def",
  "module_info", "statements", "index_access", "identifier",
  "incr_decr_op", "comptime_expr", "comptime_call_start", "expr",
  "stat_arr_literal_start", "arr_lit_start", "empty_arr_dims",
  "stat_arr_literal", "arr_literal", "statement", "matching_statement",
  "switch_statement_start", "switch_statement", "switch_body",
  "switch_branch", "switch_case", "switch_expr_list", "if_condition",
  "matching_if_statement", "non_matching_statement",
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
  "func_arg", "func_args", "enum_names", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    36,   326,    61,    63,    60,    62,    43,    45,    42,
      47,    37,   327,    46,    33,    40,    58,    64,    94,   328,
     329,    91,   330,   331,    41,    59,   123,   125,   124,    44,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   106,   107,   108,   109,   109,   110,
     110,   111,   111,   112,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   125,   126,   126,   127,   127,   128,
     129,   129,   130,   131,   132,   132,   132,   132,   133,   133,
     134,   135,   136,   137,   138,   139,   140,   140,   141,   142,
     143,   144,   145,   145,   145,   145,   146,   146,   146,   147,
     148,   149,   149,   149,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   155,   155,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   159,
     160,   160,   160,   160,   161,   162,   163,   164,   164,   164,
     165,   165,   166,   167,   167,   167,   167,   167,   167,   168,
     169,   170,   170,   170,   171,   171,   171,   172,   172
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     6,     2,     1,
       6,     3,     2,     2,     3,     2,     2,     1,     2,     2,
       1,     3,     1,     2,     1,     3,     5,     1,     4,     0,
       2,     2,     3,     1,     2,     2,     1,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     1,     3,     2,     4,     4,     1,     1,
       1,     1,     1,     5,     1,     4,     6,     3,     1,     2,
       2,     3,     4,     2,     1,     3,     1,     1,     1,     1,
       2,     2,     1,     4,     1,     1,     1,     2,     4,     1,
       1,     1,     1,     2,     4,     2,     3,     3,     1,     2,
       1,     3,     2,     4,     1,     1,     1,     1,     2,     4,
       6,     2,     2,     2,     1,     2,     5,     1,     2,     2,
       2,     2,     2,     3,     3,     2,     4,     7,     6,     1,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     2,     2,     3,     2,     2,     1,     2,     1,     1,
       1,     3,     1,     2,     1,     2,     1,     1,     2,     4,
       1,     2,     3,     2,     2,     1,     3,     1,     3,     3,
       1,     2,     5,     1,     2,     4,     3,     2,     5,     2,
       2,     2,     3,     4,     0,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,    41,    42,    43,    33,    46,   193,
      45,     0,     0,    78,    79,    80,    36,    38,    84,     0,
       0,     0,    88,    59,    82,    44,     0,     3,     0,     0,
       0,    94,    81,    57,    58,   180,     0,    61,     0,    73,
       1,   166,     6,     0,     0,   190,     0,     0,     0,     0,
       0,   168,     0,     0,     0,   176,   177,    22,     0,     0,
       0,     0,    24,     8,    20,    29,    17,     9,     0,   170,
       0,     0,   169,   172,     0,     0,   174,     0,     0,     5,
       0,    33,   194,     0,     0,    39,    50,    69,     0,    89,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    75,   149,     0,
       0,     0,     0,     0,     0,     0,     0,    56,   178,     0,
      55,     0,     0,     0,     0,    93,    42,     0,     0,     0,
     181,   184,   183,   199,   197,     0,    15,    16,   166,     0,
       0,     0,    12,    13,    27,     0,    19,    18,    23,     0,
     161,     0,   167,   156,     0,     0,   157,     0,   164,   162,
     165,     0,   191,   173,   175,   166,     0,     0,   185,    29,
     200,    47,     0,     0,     0,    54,    40,    64,    65,    66,
      67,    68,    70,    72,    71,   151,   152,   153,   154,   155,
       0,    62,    63,    48,    49,    51,    52,    53,     0,     0,
      31,     0,    74,   150,    87,     0,    91,     0,    95,   182,
      33,   196,    21,    11,     0,   204,     0,    14,   171,   160,
     158,     0,   105,   104,     0,     0,   134,     0,     0,     0,
      99,    25,    98,    30,    96,     0,   106,     0,   109,    97,
     124,   137,     0,   111,   126,     0,     0,     0,   110,   125,
     112,   127,     0,     0,   102,   159,   163,     0,     0,   204,
       0,   195,    76,    77,     0,     0,   179,    32,    92,    85,
       0,     0,   207,     0,   166,     0,   205,     0,     0,   101,
     100,   131,   113,   122,     0,   107,     0,     0,     0,     0,
     149,     0,   128,    96,   132,   133,     0,    59,   135,     0,
     138,   139,   140,   141,    33,     0,   188,   189,     0,   186,
      33,    60,    83,     0,   198,     7,     0,     0,   201,    26,
       0,    28,     0,     0,     0,   120,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,   192,    86,   208,
     202,     0,   206,     0,     0,   103,   114,     0,   115,     0,
     119,     0,   123,   129,     0,   142,   145,     0,     0,   146,
       0,   108,    10,   203,     0,   116,   117,   121,   143,   144,
       0,     0,   136,   130,   148,     0,   147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    63,    64,    65,    66,    67,   145,   155,
     122,    23,    24,    25,    26,   232,    28,    29,    30,    31,
      32,   233,   234,   235,   236,   326,   327,   328,   329,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   332,   252,   123,    33,    34,    68,
      69,    70,    71,    72,    73,   275,    75,    76,    35,    36,
      37,   169,   254,   167,    77,    78,    38,    39,    79,   276,
     277,   273
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     -55,   887,    35,   204,  -231,  -231,  -231,    -3,  -231,   922,
    -231,   -34,   -23,  -231,  -231,  -231,  -231,   887,  -231,   887,
     887,   887,    -6,  -231,  -231,  -231,   -85,  1413,   -60,   957,
     -19,  -231,  -231,  -231,  -231,   887,   -52,  -231,   -14,  -231,
    -231,    20,  -231,     1,   458,  -231,    72,    82,    83,   104,
      32,  -231,   115,   123,   131,  -231,  -231,  -231,    55,   380,
     458,    27,  -231,  -231,  -231,  -231,  -231,  -231,    45,  -231,
     254,   -51,  -231,  -231,   130,   458,  -231,   475,    53,  -231,
     147,   -43,  1413,   887,   458,  1413,    -4,   236,  1297,  -231,
    -231,   887,   887,   887,   887,   887,   887,   887,   887,   887,
    -231,  -231,   887,   887,   887,   887,   887,  -231,  -231,   887,
     887,   887,   887,   887,   887,   887,   887,    74,  -231,   162,
    -231,   887,    50,   887,   887,  -231,    58,  1084,   166,   553,
    1413,  -231,   887,  -231,   992,   458,  -231,  -231,  -231,   171,
      87,    93,  -231,  -231,  -231,     5,  -231,  -231,  -231,    97,
    -231,   175,  -231,  -231,   458,   498,  -231,   458,  -231,  -231,
    -231,   458,  -231,  -231,  -231,   -62,   105,   107,  -231,  -231,
    -231,  -231,   887,  1319,    96,  -231,  1413,   719,   719,  1697,
    1697,  1662,  1681,   197,   197,  1413,  1413,  1413,  1413,  1413,
    1482,  1697,  1697,  1055,  1055,   439,   439,   439,   458,   108,
    1413,   887,  -231,  1413,  1413,   362,  -231,   304,  -231,  1413,
     -37,  1413,  -231,  -231,   188,   777,   109,  -231,  -231,  -231,
    -231,   852,  -231,  -231,   887,   887,  -231,   887,   111,   817,
    -231,  -231,  1503,  -231,  -231,   101,  -231,   817,  -231,  -231,
    -231,  -231,   817,  -231,  -231,   723,   100,   817,  -231,  -231,
    -231,  -231,   817,     4,  -231,  -231,  -231,   195,   196,   777,
     593,  1413,  -231,  -231,  1027,   113,  -231,  1413,  -231,  1413,
    1155,   887,  -231,   -45,   132,   202,  -231,   -42,   200,  -231,
    1413,  1572,  1413,  1593,   203,  -231,   817,   817,   817,   817,
     159,   887,  -231,   190,  -231,  -231,   122,    36,  -231,   887,
    -231,  -231,  -231,  -231,  -231,   141,  -231,  -231,   -41,  -231,
     -59,   -11,  -231,   887,  1413,  -231,   213,   887,   154,  -231,
     777,  -231,   155,   208,   458,  1413,   628,   817,   182,   -13,
     817,   402,    62,   122,   887,  1226,   887,   140,  1413,  -231,
    1413,   887,  -231,   887,   817,  -231,  -231,   817,  -231,   228,
    -231,   887,  -231,  -231,   887,  1413,   887,   217,    69,  1572,
     817,  1413,  -231,  1413,  1391,  -231,  -231,  1413,  1413,  1413,
     887,   218,  -231,  -231,  1572,   887,  1572
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   198,  -231,    71,
    -231,  -212,  -231,  -231,  -231,    -1,  -231,  -231,  -231,  -231,
    -231,  -208,  -101,  -231,  -231,  -231,   -82,  -231,  -231,  -223,
    -231,  -230,  -231,  -231,  -214,  -231,  -231,  -231,  -231,  -123,
    -231,  -231,  -231,  -231,   -88,  -113,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   172,     0,  -105,   -74,  -231,  -231,
    -231,  -231,   174,  -231,  -231,  -231,  -231,  -231,  -231,   -67,
      -2,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -188
static const yytype_int16 yytable[] =
{
      27,   164,   257,    74,   350,    80,   286,   136,    82,    90,
     304,   216,   295,     1,    91,   287,    85,   301,    86,    87,
      88,    80,   303,  -187,   100,   101,   266,    80,   127,   292,
     172,   100,   101,   297,   130,    40,   271,   298,   107,   124,
     125,   305,   131,   160,   139,   107,    47,   132,   161,   315,
     253,    83,   319,   337,   316,   333,   334,   320,   320,   151,
     152,    80,    84,   286,   286,   286,   286,    55,    89,    56,
     159,   135,   287,   287,   287,   287,   120,   166,   140,   128,
     121,   129,   173,   133,   174,   134,   351,   121,   141,   142,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   217,
     353,   185,   186,   187,   188,   189,   288,   143,   190,   191,
     192,   193,   194,   195,   196,   197,   289,   144,   146,   348,
     200,   286,   203,   204,   253,   153,   147,   154,   285,   208,
     287,   209,   253,   211,   148,   212,   293,   253,   149,   365,
     253,   294,   253,   156,   162,   157,   300,   253,   201,   168,
     202,   302,   372,   171,   220,   253,   -90,   255,   -90,   198,
     356,   256,   357,   288,   288,   288,   288,   356,   199,   371,
     206,   261,   214,   289,   289,   289,   289,   213,   215,   164,
     218,   253,   253,   253,   253,   323,   294,   300,   302,   219,
     263,   258,   259,   266,   272,   278,   284,   291,   265,   299,
     267,   306,   307,   321,   269,   317,   270,   312,   318,   322,
      41,   324,   330,   331,   336,    42,    43,    44,    45,   339,
     280,   288,   253,   281,   282,   253,   283,   341,   343,   352,
     344,   289,   100,   101,   349,   362,   366,   370,   375,   253,
     260,   137,   253,   352,   347,   358,   107,   163,    46,    47,
      48,    49,   170,   342,    50,   253,    51,   308,     0,     0,
     138,     0,     0,   311,    52,    53,    54,    55,     0,    56,
     314,   100,   101,    57,   112,   113,   114,   115,   116,     0,
     117,     0,   118,   119,   120,   107,     0,    58,   121,    59,
     325,    60,     0,     0,     0,    61,     0,     0,   335,     0,
      62,     0,     0,     0,     0,     0,    51,     4,     5,     6,
       7,     0,   338,     0,     0,     0,   340,    55,     0,    56,
       0,   118,   119,   120,   345,   325,     0,   121,     0,     0,
     355,     0,     0,   359,     0,   361,     0,    58,     8,    59,
     363,    60,   364,     0,     0,    61,     0,     0,   158,     0,
     367,     0,     9,   368,     0,   369,     0,    10,    11,    12,
       0,    13,    14,    15,     0,     4,     5,     6,     7,   374,
      16,    17,     0,     0,   376,    18,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,   138,     0,    20,    21,
       0,     0,     0,     0,   150,    22,     8,     0,     0,     0,
       0,     0,   153,     0,   154,     4,     5,     6,     7,     0,
       9,     0,     0,     0,     0,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    51,    18,     0,     0,     8,     0,     0,     0,
      19,     0,     0,    55,     0,    56,    20,    21,     0,     0,
       9,     0,     0,    22,     0,    10,    11,    12,     0,    13,
      14,    15,   268,    58,   138,    59,     0,    60,    16,    17,
       0,    61,     0,    18,   100,   101,     0,     0,     0,     0,
      19,   165,     0,     0,     0,     0,    20,    21,   107,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
     354,     4,     5,     6,     7,   221,   222,   223,     0,     0,
      51,     0,     0,   224,   225,     0,   226,     0,     0,   227,
       0,    55,   117,    56,   118,   119,   120,    51,     0,     0,
     121,   228,     8,     0,     0,     0,     0,     0,    55,     0,
      56,    58,     0,    59,     0,    60,     9,     0,     0,    61,
       0,    10,    11,    12,   229,    13,    14,    15,    58,   138,
      59,    55,    60,    56,    16,    17,    61,     0,     0,    18,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,     0,    22,
       0,     0,     0,   230,   168,   231,     4,     5,     6,     7,
     221,   222,   223,     0,     0,    51,     0,     0,   224,   225,
       0,   226,     0,     0,   227,     0,    55,     0,    56,     0,
       0,     0,     0,     0,     0,     0,   228,     8,     0,     0,
       0,     4,     5,     6,     7,     0,    58,     0,    59,     0,
      60,     9,     0,     0,   207,     0,    10,    11,    12,   229,
      13,    14,    15,     0,     0,     0,    55,     0,    56,    16,
      17,     0,     8,     0,    18,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     9,    20,    21,     0,
       0,    10,    11,    12,    22,    13,    14,    15,   230,   168,
     309,     0,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,   346,     4,     5,     6,     7,
     221,   222,   223,     0,     0,     0,     0,     0,   224,   225,
       0,   226,   296,     0,   227,     0,     0,     0,     0,     0,
      98,    99,     0,     0,   100,   101,   228,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     9,     0,     0,     0,     0,    10,    11,    12,   229,
      13,    14,    15,   274,     0,     0,    55,     0,    56,    16,
      17,     0,     0,     0,    18,     0,   112,   113,   114,   115,
     116,    19,   117,     0,   118,   119,   120,    20,    21,     0,
     121,     0,     0,     0,    22,     0,     0,     0,   230,   168,
       4,     5,     6,     7,   221,   222,   223,     0,     0,    51,
       0,     0,   224,   225,     0,   226,     0,     0,   227,     0,
      55,     0,    56,     0,     0,     0,     0,     0,     0,     0,
     228,     8,     0,     0,     0,     4,     5,     6,     7,     0,
      58,     0,    59,     0,    60,     9,     0,     0,    61,     0,
      10,    11,    12,   229,    13,    14,    15,     0,     0,     0,
      55,     0,    56,    16,    17,     0,     8,     0,    18,     0,
       4,     5,     6,     7,     0,    19,     0,     0,     0,     0,
       9,    20,    21,     0,     0,    10,    11,    12,    22,    13,
      14,    15,   230,   168,     0,     0,     0,     0,    16,    17,
       0,     8,     0,    18,     0,     4,     5,     6,    81,     0,
      19,     0,     0,     0,     0,     9,    20,    21,     0,     0,
      10,    11,    12,    22,    13,    14,    15,   279,     0,     0,
       0,     0,     0,    16,    17,     0,     8,     0,    18,     0,
       4,   126,     6,     7,     0,    19,     0,     0,     0,     0,
       9,    20,    21,     0,     0,    10,    11,    12,    22,    13,
      14,    15,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     8,     0,    18,     0,     4,     5,     6,   210,     0,
      19,     0,     0,     0,     0,     9,    20,    21,     0,     0,
      10,    11,    12,    22,    13,    14,    15,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     8,     0,    18,     0,
       4,     5,     6,   310,     0,    19,     0,     0,     0,     0,
       9,    20,    21,     0,     0,    10,    11,    12,    22,    13,
      14,    15,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     8,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     9,    20,    21,     0,     0,
      10,    11,    12,    22,    13,    14,    15,     0,     0,     0,
     100,   101,     0,    16,    17,     0,     0,     0,    18,     0,
       0,     0,     0,     0,   107,    19,     0,    92,    93,    94,
      95,    20,    21,    96,    97,    98,    99,     0,    22,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,   107,   114,   115,   116,     0,   117,     0,
     118,   119,   120,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,     0,   118,
     119,   120,     0,     0,     0,   121,     0,     0,    92,    93,
      94,    95,     0,   205,    96,    97,    98,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,     0,
     118,   119,   120,     0,     0,     0,   121,     0,     0,    92,
      93,    94,    95,     0,   313,    96,    97,    98,    99,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
       0,   118,   119,   120,     0,     0,     0,   121,     0,     0,
      92,    93,    94,    95,     0,   360,    96,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,    92,    93,    94,    95,   107,     0,    96,    97,
      98,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   107,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,     0,   118,   119,   120,     0,     0,     0,   121,     0,
       0,   175,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,     0,   118,   119,   120,     0,     0,     0,
     121,     0,     0,   262,    92,    93,    94,    95,     0,     0,
      96,    97,    98,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,    92,    93,    94,    95,
     107,     0,    96,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,     0,   118,   119,   120,     0,
       0,     0,   121,     0,     0,   373,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,     0,   118,   119,
     120,     0,     0,     0,   121,    92,    93,    94,    95,     0,
       0,    96,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,    92,    93,    94,    95,
       0,   107,    96,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,     0,   118,   264,   120,
       0,     0,     0,   121,     0,     0,   290,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,     0,   118,   119,
     120,     0,     0,     0,   121,    92,    93,    94,    95,     0,
       0,    96,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,    92,    93,    94,    95,
       0,   107,    96,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,   108,   109,   110,   111,   112,
       0,   114,   115,   116,     0,   117,     0,   118,   119,   120,
       0,     0,     0,   121,     0,     0,   108,   109,   110,   111,
     112,     0,   114,   115,   116,     0,   117,     0,     0,   119,
     120,     0,     0,     0,   121,    92,    93,    94,    95,     0,
       0,     0,    97,    98,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,     0,
       0,   107,    98,    99,     0,     0,   100,   101,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,    98,    99,
     107,     0,   100,   101,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   107,   118,   119,   120,
       0,     0,     0,   121,     0,     0,   110,   111,   112,   113,
     114,   115,   116,     0,   117,     0,   118,   119,   120,     0,
       0,     0,   121,     0,   112,   113,   114,   115,   116,     0,
     117,     0,   118,   119,   120,     0,     0,     0,   121
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,    75,    64,     3,    17,    64,   229,     6,     9,    94,
       6,     6,   242,    68,    99,   229,    17,   247,    19,    20,
      21,    64,   252,    85,    35,    36,    85,    64,    29,   237,
      73,    35,    36,   245,    35,     0,    73,   245,    49,    99,
     100,   253,    94,    94,    44,    49,    45,    99,    99,    94,
     155,    85,    94,    94,    99,    19,    20,    99,    99,    59,
      60,    64,    85,   286,   287,   288,   289,    63,    74,    65,
      70,    51,   286,   287,   288,   289,    87,    77,     6,    98,
      91,   100,    83,    97,    84,    99,    99,    91,     6,     6,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    94,
     330,   102,   103,   104,   105,   106,   229,     3,   109,   110,
     111,   112,   113,   114,   115,   116,   229,    85,     3,   327,
     121,   344,   123,   124,   229,    98,     3,   100,   229,   129,
     344,   132,   237,   134,     3,   135,   237,   242,    83,   347,
     245,   242,   247,    98,    14,   100,   247,   252,    98,    96,
     100,   252,   360,     6,   154,   260,    98,   157,   100,    85,
      98,   161,   100,   286,   287,   288,   289,    98,     6,   100,
       4,   172,    85,   286,   287,   288,   289,     6,    85,   253,
      83,   286,   287,   288,   289,   286,   287,   288,   289,    14,
      94,    86,    85,    85,     6,    86,    85,    96,   198,    99,
     201,     6,     6,     3,   205,    73,   207,    94,     6,     6,
       6,    52,    22,    91,    73,    11,    12,    13,    14,     6,
     221,   344,   327,   224,   225,   330,   227,    73,    73,   330,
      22,   344,    35,    36,    52,    95,     8,    20,    20,   344,
     169,    43,   347,   344,   326,   333,    49,    75,    44,    45,
      46,    47,    78,   320,    50,   360,    52,   259,    -1,    -1,
       6,    -1,    -1,   264,    60,    61,    62,    63,    -1,    65,
     271,    35,    36,    69,    77,    78,    79,    80,    81,    -1,
      83,    -1,    85,    86,    87,    49,    -1,    83,    91,    85,
     291,    87,    -1,    -1,    -1,    91,    -1,    -1,   299,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    52,     3,     4,     5,
       6,    -1,   313,    -1,    -1,    -1,   317,    63,    -1,    65,
      -1,    85,    86,    87,   324,   326,    -1,    91,    -1,    -1,
     331,    -1,    -1,   334,    -1,   336,    -1,    83,    34,    85,
     341,    87,   343,    -1,    -1,    91,    -1,    -1,    94,    -1,
     351,    -1,    48,   354,    -1,   356,    -1,    53,    54,    55,
      -1,    57,    58,    59,    -1,     3,     4,     5,     6,   370,
      66,    67,    -1,    -1,   375,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,     6,    -1,    84,    85,
      -1,    -1,    -1,    -1,    14,    91,    34,    -1,    -1,    -1,
      -1,    -1,    98,    -1,   100,     3,     4,     5,     6,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    52,    71,    -1,    -1,    34,    -1,    -1,    -1,
      78,    -1,    -1,    63,    -1,    65,    84,    85,    -1,    -1,
      48,    -1,    -1,    91,    -1,    53,    54,    55,    -1,    57,
      58,    59,   100,    83,     6,    85,    -1,    87,    66,    67,
      -1,    91,    -1,    71,    35,    36,    -1,    -1,    -1,    -1,
      78,     6,    -1,    -1,    -1,    -1,    84,    85,    49,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      52,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,    21,
      -1,    63,    83,    65,    85,    86,    87,    52,    -1,    -1,
      91,    33,    34,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    83,    -1,    85,    -1,    87,    48,    -1,    -1,    91,
      -1,    53,    54,    55,    56,    57,    58,    59,    83,     6,
      85,    63,    87,    65,    66,    67,    91,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    52,    -1,    -1,    15,    16,
      -1,    18,    -1,    -1,    21,    -1,    63,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    83,    -1,    85,    -1,
      87,    48,    -1,    -1,    91,    -1,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    63,    -1,    65,    66,
      67,    -1,    34,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    48,    84,    85,    -1,
      -1,    53,    54,    55,    91,    57,    58,    59,    95,    96,
      97,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,     6,    -1,    -1,    63,    -1,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    77,    78,    79,    80,
      81,    78,    83,    -1,    85,    86,    87,    84,    85,    -1,
      91,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    52,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    21,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      83,    -1,    85,    -1,    87,    48,    -1,    -1,    91,    -1,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      63,    -1,    65,    66,    67,    -1,    34,    -1,    71,    -1,
       3,     4,     5,     6,    -1,    78,    -1,    -1,    -1,    -1,
      48,    84,    85,    -1,    -1,    53,    54,    55,    91,    57,
      58,    59,    95,    96,    -1,    -1,    -1,    -1,    66,    67,
      -1,    34,    -1,    71,    -1,     3,     4,     5,     6,    -1,
      78,    -1,    -1,    -1,    -1,    48,    84,    85,    -1,    -1,
      53,    54,    55,    91,    57,    58,    59,    95,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    34,    -1,    71,    -1,
       3,     4,     5,     6,    -1,    78,    -1,    -1,    -1,    -1,
      48,    84,    85,    -1,    -1,    53,    54,    55,    91,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    34,    -1,    71,    -1,     3,     4,     5,     6,    -1,
      78,    -1,    -1,    -1,    -1,    48,    84,    85,    -1,    -1,
      53,    54,    55,    91,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    34,    -1,    71,    -1,
       3,     4,     5,     6,    -1,    78,    -1,    -1,    -1,    -1,
      48,    84,    85,    -1,    -1,    53,    54,    55,    91,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    34,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    48,    84,    85,    -1,    -1,
      53,    54,    55,    91,    57,    58,    59,    -1,    -1,    -1,
      35,    36,    -1,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    49,    78,    -1,    23,    24,    25,
      26,    84,    85,    29,    30,    31,    32,    -1,    91,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    79,    80,    81,    -1,    83,    -1,
      85,    86,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    85,
      86,    87,    -1,    -1,    -1,    91,    -1,    -1,    23,    24,
      25,    26,    -1,    99,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    83,    -1,
      85,    86,    87,    -1,    -1,    -1,    91,    -1,    -1,    23,
      24,    25,    26,    -1,    99,    29,    30,    31,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,    -1,
      23,    24,    25,    26,    -1,    99,    29,    30,    31,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    23,    24,    25,    26,    49,    -1,    29,    30,
      31,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    -1,    85,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    23,    24,    25,    26,
      49,    -1,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    85,    86,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    91,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    23,    24,    25,    26,
      -1,    49,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    85,    86,    87,
      -1,    -1,    -1,    91,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    91,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    23,    24,    25,    26,
      -1,    49,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    -1,    83,    -1,    85,    86,    87,
      -1,    -1,    -1,    91,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    -1,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    91,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    49,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      49,    -1,    35,    36,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    49,    85,    86,    87,
      -1,    -1,    -1,    91,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    85,    86,    87,    -1,
      -1,    -1,    91,    -1,    77,    78,    79,    80,    81,    -1,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,   102,   103,     3,     4,     5,     6,    34,    48,
      53,    54,    55,    57,    58,    59,    66,    67,    71,    78,
      84,    85,    91,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   148,   149,   159,   160,   161,   167,   168,
       0,     6,    11,    12,    13,    14,    44,    45,    46,    47,
      50,    52,    60,    61,    62,    63,    65,    69,    83,    85,
      87,    91,    96,   104,   105,   106,   107,   108,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   165,   166,   169,
      64,     6,   116,    85,    85,   116,   116,   116,   116,    74,
      94,    99,    23,    24,    25,    26,    29,    30,    31,    32,
      35,    36,    37,    38,    39,    40,    41,    49,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    83,    85,    86,
      87,    91,   111,   147,    99,   100,     4,   116,    98,   100,
     116,    94,    99,    97,    99,    51,     6,   108,     6,   156,
       6,     6,     6,     3,    85,   109,     3,     3,     3,    83,
      14,   156,   156,    98,   100,   110,    98,   100,    94,   156,
      94,    99,    14,   155,   158,     6,   156,   164,    96,   162,
     163,     6,    73,   116,   156,    94,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    85,     6,
     116,    98,   100,   116,   116,    99,     4,    91,   156,   116,
       6,   116,   156,     6,    85,    85,     6,    94,    83,    14,
     156,     7,     8,     9,    15,    16,    18,    21,    33,    56,
      95,    97,   116,   122,   123,   124,   125,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   146,   157,   163,   156,   156,    64,    86,    85,
     110,   116,    94,    94,    86,   156,    85,   116,   100,   116,
     116,    73,     6,   172,     6,   156,   170,   171,    86,    95,
     116,   116,   116,   116,    85,   123,   130,   135,   140,   146,
      73,    96,   122,   123,   123,   132,    19,   112,   122,    99,
     123,   132,   123,   132,     6,   112,     6,     6,   171,    97,
       6,   116,    94,    99,   116,    94,    99,    73,     6,    94,
      99,     3,     6,   123,    52,   116,   126,   127,   128,   129,
      22,    91,   145,    19,    20,   116,    73,    94,   116,     6,
     116,    73,   170,    73,    22,   156,    97,   127,   122,    52,
      17,    99,   123,   132,    98,   116,    98,   100,   145,   116,
      99,   116,    95,   116,   116,   122,     8,   116,   116,   116,
      20,   100,   122,    94,   116,    20,   116
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
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
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, scanner); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (scanner);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, scanner)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    yyscan_t scanner;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, scanner); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    yyscan_t scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (yyscan_t scanner)
#else
int
yyparse (scanner)
    yyscan_t scanner;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 218 "axo_gram.y"
    {
    ret_declarations = (yyvsp[(1) - (1)].str);
  }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 221 "axo_gram.y"
    {
    ret_expr = (yyvsp[(2) - (2)].expression);
  }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 226 "axo_gram.y"
    {
    (yyval.str) = alloc_str("");
  }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 229 "axo_gram.y"
    {
    axo_add_decl(state, axo_func_def_to_decl((yyvsp[(2) - (2)].function)));
    axo_free_func((yyvsp[(2) - (2)].function));
  }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 233 "axo_gram.y"
    {
    if ((yyvsp[(2) - (2)].str)[0] == '<'){
      axo_add_decl(state, (axo_decl){.val = fmtstr("#include %s", (yyvsp[(2) - (2)].str)), .kind=axo_c_include_decl_kind});
    }else{
      char* path = &((yyvsp[(2) - (2)].str)[1]);
      path[strlen((yyvsp[(2) - (2)].str))-2] = '\0';
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
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 251 "axo_gram.y"
    {
    new_ptr_one(enm, axo_enum);
    *enm = (yyvsp[(5) - (6)].enum_type);
    enm->name=alloc_str((yyvsp[(3) - (6)].str));
    char* decl;
    int decl_sz = 18+(2+(yyvsp[(5) - (6)].enum_type).len)*strlen((yyvsp[(3) - (6)].str));  //typedef enum %name{\}name;
    for (int i=0; i<(yyvsp[(5) - (6)].enum_type).len; i++){
      decl_sz += strlen((yyvsp[(5) - (6)].enum_type).names[i]) + 2 + 1;
    }
    decl_sz--; //last comma
    decl = (char*)malloc(decl_sz*sizeof(char));
    strcpy(decl, "typedef enum ");
    strcat(decl, (yyvsp[(3) - (6)].str));
    strcat(decl, "{\n");
    for (int i=0; i<(yyvsp[(5) - (6)].enum_type).len; i++){
      if(i>0) strcat(decl, ",\n");
      char* field = fmtstr("%s$%s", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].enum_type).names[i]);
      strcat(decl, field);
      axo_set_var(state->global_scope, (axo_var){.name=field, .typ=axo_no_typ});
    }
    strcat(decl, "\n}");
    strcat(decl, (yyvsp[(3) - (6)].str));
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
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 285 "axo_gram.y"
    {
    (yyval.str) = strapnd(&(yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].declaration_type).val);
    axo_add_decl(state, (yyvsp[(2) - (2)].declaration_type));
  }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 291 "axo_gram.y"
    { //Fix! Make this use realloc less
    new_ptr_one(strct, axo_struct);
    *strct = (yyvsp[(1) - (1)].struct_type);
    char* decl = empty_str;
    strapnd(&decl, "typedef struct ");
    strapnd(&decl, (yyvsp[(1) - (1)].struct_type).name);
    strapnd(&decl, "{\n");
    for (int i=0; i<(yyvsp[(1) - (1)].struct_type).fields_len; i++){
      char* ntd = axo_name_typ_decl(strct->fields[i].name, strct->fields[i].typ);
      strapnd(&decl, ntd);
      strapnd(&decl, ";\n");
      free(ntd);
    }
    strapnd(&decl, "}");
    strapnd(&decl, (yyvsp[(1) - (1)].struct_type).name);
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
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 318 "axo_gram.y"
    {
    axo_func fn = (axo_func){
      .name=(yyvsp[(2) - (6)].function).name
    };
    int args_len = (yyvsp[(4) - (6)].function).f_typ.args_len;
    if ((yyvsp[(2) - (6)].function).args_names){
      args_len += (yyvsp[(2) - (6)].function).f_typ.args_len;
      fn.args_names = (char**)malloc(args_len*sizeof(char*));
      fn.f_typ = (axo_func_typ){
        .args_len = 0,
        .args_types=(axo_typ*)malloc(args_len*sizeof(axo_typ)),
        .args_defs=(char**)malloc(args_len*sizeof(char*)),
      };
      for (int i=0; i<(yyvsp[(2) - (6)].function).f_typ.args_len; i++){
        fn.args_names[fn.f_typ.args_len] = (yyvsp[(2) - (6)].function).args_names[i];
        fn.f_typ.args_types[fn.f_typ.args_len] = (yyvsp[(2) - (6)].function).f_typ.args_types[i];
        fn.f_typ.args_defs[fn.f_typ.args_len++] = (yyvsp[(2) - (6)].function).f_typ.args_defs[i];
      }
      for (int i=0; i<(yyvsp[(4) - (6)].function).f_typ.args_len; i++){
        fn.args_names[fn.f_typ.args_len] = (yyvsp[(4) - (6)].function).args_names[i];
        fn.f_typ.args_types[fn.f_typ.args_len] = (yyvsp[(4) - (6)].function).f_typ.args_types[i];
        fn.f_typ.args_defs[fn.f_typ.args_len++] = (yyvsp[(4) - (6)].function).f_typ.args_defs[i];
      }
    }else{
      fn.args_names = (yyvsp[(4) - (6)].function).args_names;
      fn.f_typ.args_defs = (yyvsp[(4) - (6)].function).f_typ.args_defs;
      fn.f_typ.args_types = (yyvsp[(4) - (6)].function).f_typ.args_types;
      fn.f_typ.args_len = args_len;
    }
    fn.f_typ.ret_typ = ((yyvsp[(1) - (6)].typ_type).kind==axo_no_kind) ? axo_none_typ : (yyvsp[(1) - (6)].typ_type);
    (yyval.declaration_type) = axo_func_decl_to_decl(fn);
    axo_free_func((yyvsp[(4) - (6)].function));
    axo_free_scope(top_scope);
    strapnd(&((yyval.declaration_type).val), ";");
  }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 353 "axo_gram.y"
    {
    // printf("providing '%s'\n", $IDEN);
    axo_set_var(state->global_scope, (axo_var){.typ = (yyvsp[(2) - (3)].typ_type), .name = alloc_str((yyvsp[(3) - (3)].str))});
    char* ntd = axo_name_typ_decl((yyvsp[(3) - (3)].str), (yyvsp[(2) - (3)].typ_type));
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//provided %s", ntd)};
    free(ntd);
  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 360 "axo_gram.y"
    {
    (yyval.declaration_type) = axo_use_module(state, &(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 363 "axo_gram.y"
    {
    (yyval.declaration_type) = axo_include_file(state, &(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str), true);
  }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 366 "axo_gram.y"
    {
    axo_load_module_defaults(state, &(yyvsp[(2) - (3)].module_type));
    (yyval.declaration_type) = axo_add_module(state, (yyvsp[(2) - (3)].module_type));
  }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 370 "axo_gram.y"
    {
    char* name = alloc_str((yyvsp[(2) - (2)].str));
    axo_set_typ_def(&(yyloc), state, (axo_typ_def){.name=name, .typ=(axo_typ){.kind=axo_simple_kind, .simple=(axo_simple_t){.name=name, .cname=name}, .def="0"}});
      (yyval.declaration_type) = (axo_decl){
        .kind = axo_typ_def_decl_kind,
        .val = fmtstr("//accepting type %s", (yyvsp[(2) - (2)].str))
      };
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 378 "axo_gram.y"
    {
    axo_struct* strct = alloc_one(axo_struct);
    *strct = (yyvsp[(2) - (2)].struct_type);
    axo_typ_def td = (axo_typ_def){
      .name=(yyvsp[(2) - (2)].struct_type).name,
      .typ=(axo_typ){
        .kind=axo_struct_kind,
        .structure=strct,
        .def="0" //FIX! DEFAULT VALUE!
      },
    };
    axo_set_typ_def(&(yyloc), state, td);
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//Recognized struct '%s'", (yyvsp[(2) - (2)].struct_type).name)};
  }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 392 "axo_gram.y"
    {
    (yyval.declaration_type) = (axo_decl){.val=axo_scope_code((yyvsp[(1) - (1)].scope))};
    axo_free_scope((yyvsp[(1) - (1)].scope));
  }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 396 "axo_gram.y"
    {
      char* res = alloc_str(&((yyvsp[(2) - (2)].str)[1]));
      res[strlen((yyvsp[(2) - (2)].str))-2] = '\0';
    if (axo_file_exists(res)){
      char* resolved = axo_resolve_path(res);
      resize_dyn_arr_if_needed(char*, state->extra_c_sources, state->extra_c_sources_len, axo_c_sources_cap);
      state->extra_c_sources[state->extra_c_sources_len++] = resolved;
    }else{
      axo_yyerror(&(yylsp[(2) - (2)]), "File '%s' doesn't exist.", res);
      YYERROR;
    }
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//sourced %s", res)};
  }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 409 "axo_gram.y"
    {
    char* res = alloc_str(&((yyvsp[(2) - (2)].str)[1]));
    res[strlen((yyvsp[(2) - (2)].str))-2] = '\0';
    resize_dyn_arr_if_needed(char*, state->cc_flags, state->cc_flags_len, axo_cc_flags_len);
    state->cc_flags[state->cc_flags_len++] = alloc_str(res);
    (yyval.declaration_type) = (axo_decl){.val=fmtstr("//flag %s", res)};
  }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 416 "axo_gram.y"
    {
    (yyval.declaration_type) = (axo_decl){
      .kind=axo_c_code_decl_kind,
      .val=(yyvsp[(1) - (1)].str)
    };
  }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 422 "axo_gram.y"
    {
    axo_typ_def td = (axo_typ_def){
      .name=alloc_str((yyvsp[(1) - (3)].str)),
      .typ=(yyvsp[(3) - (3)].typ_type)
    };
    td.typ.simple.name=td.typ.simple.cname=td.name;
    axo_set_typ_def(&(yyloc), state, td);
    (yyval.declaration_type) = (axo_decl){
      .kind=axo_typedef_decl_kind,
      .val=fmtstr("typedef %s %s;", axo_typ_to_c_str((yyvsp[(3) - (3)].typ_type)), (yyvsp[(1) - (3)].str))
    };
  }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 434 "axo_gram.y"
    {
    const char* lua_code = alloc_str((yyvsp[(1) - (1)].str));
    bool ok;
    const char* res = axo_lua_dostring(state, lua_code, &ok, alloc_str("block"));
    if (!ok){
      axo_yyerror(&(yyloc), res);
      YYERROR;
    }
    (yyval.declaration_type) = axo_parse_string_for_decl(state, res);
    (yyval.declaration_type).val = alloc_str("");
  }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 447 "axo_gram.y"
    {
    char* ret = alloc_str(&((yyvsp[(2) - (2)].str)[1]));
    ret[strlen(ret)-1] = '\0';
    (yyval.str) = ret;
  }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 454 "axo_gram.y"
    {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    top_scope->to_global = state->global_scope;
    axo_code_scope_started = false;
  }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 461 "axo_gram.y"
    {
    (yyval.scope) = top_scope;
    scopes->len--;
  }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 467 "axo_gram.y"
    {
    axo_struct_field* fields = (axo_struct_field*)malloc((yyvsp[(4) - (5)].function).f_typ.args_len*sizeof(axo_struct_field));
    for (int i = 0; i<(yyvsp[(4) - (5)].function).f_typ.args_len; i++){
      fields[i] = (axo_struct_field){
        .name = (yyvsp[(4) - (5)].function).args_names[i],
        .typ = (yyvsp[(4) - (5)].function).f_typ.args_types[i],
        .def = (yyvsp[(4) - (5)].function).f_typ.args_defs[i]
      };
    }
    free((yyvsp[(4) - (5)].function).args_names);
    free((yyvsp[(4) - (5)].function).f_typ.args_types);
    free((yyvsp[(4) - (5)].function).f_typ.args_defs);
    (yyval.struct_type) = (axo_struct){
      .name=alloc_str((yyvsp[(2) - (5)].str)),
      .fields=fields,
      .fields_len=(yyvsp[(4) - (5)].function).f_typ.args_len
    };
  }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 487 "axo_gram.y"
    {
    (yyval.module_type) = axo_new_module();
  }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 490 "axo_gram.y"
    {
    char* str_val = alloc_str(&((yyvsp[(4) - (4)].str)[1]));
    str_val[strlen(str_val)-1] = '\0';
    if (strcmp((yyvsp[(2) - (4)].str), "name") == 0){
      (yyval.module_type).name = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "prefix") == 0){
      (yyval.module_type).prefix = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "version") == 0){
      (yyval.module_type).version = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "author") == 0){
      (yyval.module_type).author = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "website") == 0){
      (yyval.module_type).website = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "license_name") == 0){
      (yyval.module_type).license_name = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "license") == 0){
      (yyval.module_type).license = str_val;
    }else if (strcmp((yyvsp[(2) - (4)].str), "description") == 0){
      (yyval.module_type).description = str_val;
    }else{
      axo_yyerror(&(yylsp[(2) - (4)]), "Not a valid module information field.");
      YYERROR;
    }
  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 516 "axo_gram.y"
    { }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 517 "axo_gram.y"
    {
    // printf("Adding statement to %p\n", top_scope);
    axo_add_statement(top_scope, (yyvsp[(2) - (2)].statement_type));
  }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 523 "axo_gram.y"
    {
    //TODO: Dynamic?
    axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression));
    (yyval.index_access_type) = (axo_index_access){
      .index_count=1,
      .indexes = (axo_expr*)malloc(128*sizeof(axo_expr))
    };
    (yyval.index_access_type).indexes[0] = (yyvsp[(2) - (2)].expression);
  }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 532 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.index_access_type).indexes[(yyval.index_access_type).index_count++] = (yyvsp[(3) - (3)].expression);
  }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 538 "axo_gram.y"
    {
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[(1) - (1)].str));
    if (td != NULL) {
         (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_typ_kind,
        .typ_def = *td
      };
    }else{
      (yyval.identifier_type) = (axo_identifier){
        .kind = axo_identifier_var_kind,
        .data = (void*)alloc_str((yyvsp[(1) - (1)].str))
      };
    }
  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 554 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (2)]), (yyvsp[(1) - (2)].expression));
    (yyval.expression).typ = (yyvsp[(1) - (2)].expression).typ;
    (yyval.expression).val = fmtstr("%s++", (yyvsp[(1) - (2)].expression).val);
  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 559 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (2)]), (yyvsp[(1) - (2)].expression));
    (yyval.expression).typ = (yyvsp[(1) - (2)].expression).typ;
    (yyval.expression).val = fmtstr("%s--", (yyvsp[(1) - (2)].expression).val);
  }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 566 "axo_gram.y"
    {
    // printf("got comptime: %s\n", &($1[1]));
    char* lua_input = fmtstr("return axo.get(%s)", &((yyvsp[(1) - (1)].str)[1]));
    // printf("Running Lua: %s\n", lua_input);
    bool ok = false;
    const char* res = axo_lua_dostring(state, lua_input, &ok, &((yyvsp[(1) - (1)].str)[1]));
    if (!ok){
      axo_yyerror(&(yyloc), "Macro error: %s\n", res);
      YYERROR;
    }
    (yyval.expression) = axo_parse_string_for_expr(state, res);
    // printf("Got expression: %s\nof type: %s\n\n", $$.val, axo_typ_to_str($$.typ));
    axo_pop_source(state);
    free(lua_input);
  }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 581 "axo_gram.y"
    {
    char* param = alloc_str("{");
    for (int i=0;i<(yyvsp[(1) - (2)].comptime_function_call).params_len; i++){
      axo_expr e = (yyvsp[(1) - (2)].comptime_function_call).params[i];
      char* lua_typ = axo_typ_to_lua(e.typ);
      char* estr = fmtstr("{typ=%s,\nvalue=\'%s\'}", lua_typ, e.val);
      //Write the param in...
      if (i>0) strapnd(&param, ",");
      strapnd(&param, estr);
      free(lua_typ);
      free(estr);
    }
    strapnd(&param, "}");
    const char* lua_code = fmtstr("return axo.get(axo.%s%s))", (yyvsp[(1) - (2)].comptime_function_call).name, param);
    free(param);
    // printf("comptime lua code: %s\n", lua_code);
    bool ok;
    const char* res = axo_lua_dostring(state, lua_code, &ok, (yyvsp[(1) - (2)].comptime_function_call).name);
    if (!ok){
      yyerror(state->scanner, &(yyloc), res);
      YYERROR;
    }
    // printf("Result: '%s'\n", res);
    (yyval.expression) = axo_parse_string_for_expr(state, res);
    axo_pop_source(state);
    // printf("Got expression: %s\nof type: %s\n\n", $$.val, axo_typ_to_str($$.typ));
  }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 610 "axo_gram.y"
    {
    (yyval.comptime_function_call) = (axo_comptime_call){
      .name = alloc_str(&((yyvsp[(1) - (1)].str)[1])),
      .params = NULL,
      .params_len = 0
    };
  }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 617 "axo_gram.y"
    {
    (yyval.comptime_function_call) = (axo_comptime_call){
      .name = alloc_str(&((yyvsp[(1) - (2)].str)[1])),
      .params = (axo_expr*)malloc(axo_comptime_params_cap*sizeof(axo_expr)),
      .params_len = 1
    };
    (yyval.comptime_function_call).params[0] = (yyvsp[(2) - (2)].expression);
  }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 625 "axo_gram.y"
    {
    resize_dyn_arr_if_needed(axo_expr, (yyval.comptime_function_call).params, (yyval.comptime_function_call).params_len, axo_comptime_params_cap);
    (yyval.comptime_function_call).params[(yyval.comptime_function_call).params_len++] = (yyvsp[(3) - (3)].expression);
  }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 632 "axo_gram.y"
    {set_val(&(yyval.expression), axo_deep_copy_typ(axo_str_typ(state)), (yyvsp[(1) - (1)].str)); (yyval.expression).kind=axo_expr_normal_kind;}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 634 "axo_gram.y"
    {
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val=(yyvsp[(1) - (1)].str),
      .typ=axo_int_typ(state)
    };
    (yyval.expression).typ.kind=axo_literal_kind;
  }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 643 "axo_gram.y"
    {set_val(&(yyval.expression), axo_float_typ(state), (yyvsp[(1) - (1)].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 645 "axo_gram.y"
    {set_val(&(yyval.expression), axo_byte_typ(state), (yyvsp[(1) - (1)].str)); (yyval.expression).kind=axo_expr_normal_kind; (yyval.expression).lval_kind = axo_not_lval_kind;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 646 "axo_gram.y"
    {
    (yyval.expression) = (axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val="NULL",
      .typ=axo_none_ptr_typ
    };
  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 654 "axo_gram.y"
    {
      axo_module* mod = axo_get_module(state, (yyvsp[(1) - (3)].str));
      if (!mod){
        axo_yyerror(&(yylsp[(1) - (3)]), "Module '%s'is not loaded. Did you forget to use it?", (yyvsp[(1) - (3)].str));
        YYERROR;
      }
      axo_var* var = axo_get_var(state->global_scope, fmt_str(s_str(1024), "%s%s", mod->prefix, (yyvsp[(3) - (3)].str)));
      if (var == NULL && rval_now)
        axo_yyerror(&(yyloc), "Module '%s' doesn't have variable '%s'.", mod->name, (yyvsp[(3) - (3)].str));
      (yyval.expression) = (axo_expr){
        .val = fmtstr("%s%s", mod->prefix, (yyvsp[(3) - (3)].str)),
        .typ=(var ? var->typ : axo_no_typ),
        .kind = axo_expr_normal_kind,
        .lval_kind = axo_var_lval_kind
      };
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 670 "axo_gram.y"
    {parse_operator(&(yylsp[(2) - (3)]), &(yyval.expression), (yyvsp[(1) - (3)].expression), "+", (yyvsp[(3) - (3)].expression)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 671 "axo_gram.y"
    {parse_operator(&(yylsp[(2) - (3)]), &(yyval.expression), (yyvsp[(1) - (3)].expression), "-", (yyvsp[(3) - (3)].expression)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 672 "axo_gram.y"
    {(yyval.expression).val = fmtstr("-%s", (yyvsp[(2) - (2)].expression).val); (yyval.expression).typ = (yyvsp[(2) - (2)].expression).typ; (yyval.expression).kind = axo_expr_normal_kind; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 673 "axo_gram.y"
    {parse_operator(&(yylsp[(2) - (3)]), &(yyval.expression), (yyvsp[(1) - (3)].expression), "*", (yyvsp[(3) - (3)].expression)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 674 "axo_gram.y"
    {parse_operator(&(yylsp[(2) - (3)]), &(yyval.expression), (yyvsp[(1) - (3)].expression), "/", (yyvsp[(3) - (3)].expression)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 675 "axo_gram.y"
    {parse_operator(&(yylsp[(2) - (3)]), &(yyval.expression), (yyvsp[(1) - (3)].expression), "%", (yyvsp[(3) - (3)].expression)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 676 "axo_gram.y"
    {
    (yyval.expression).val = fmtstr("(%s)", (yyvsp[(2) - (3)].expression).val);
    (yyval.expression).typ = (yyvsp[(2) - (3)].expression).typ;
    (yyval.expression).kind = (yyvsp[(2) - (3)].expression).kind == axo_expr_assigned_declaration_kind?axo_expr_assigned_declaration_kind:axo_expr_normal_kind;
    free((yyvsp[(2) - (3)].expression).val);
  }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 682 "axo_gram.y"
    { //Referencing
    if ((yyvsp[(1) - (2)].expression).lval_kind == axo_not_lval_kind)
      axo_yyerror(&(yylsp[(1) - (2)]), "Cannot reference a non l-value.");
    (yyval.expression).typ.kind = axo_ptr_kind;
    (yyval.expression).typ.subtyp = malloc(sizeof(axo_typ));
    (yyval.expression).val = fmtstr("&%s", (yyvsp[(1) - (2)].expression).val);
    (yyval.expression).lval_kind = axo_not_lval_kind;
    *axo_subtyp((yyval.expression).typ) = (yyvsp[(1) - (2)].expression).typ;
    free((yyvsp[(1) - (2)].expression).val);
  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 692 "axo_gram.y"
    { //Dereferencing
    axo_validate_rval(&(yylsp[(1) - (2)]), (yyvsp[(1) - (2)].expression));
    if ((yyvsp[(1) - (2)].expression).typ.kind != axo_ptr_kind)
      axo_yyerror(&(yylsp[(1) - (2)]), "Cannot dereference a value of non-pointer type '%s'.", axo_typ_to_str((yyvsp[(1) - (2)].expression).typ));
    (yyval.expression).typ = *axo_subtyp((yyvsp[(1) - (2)].expression).typ);
    (yyval.expression).lval_kind=(yyvsp[(1) - (2)].expression).lval_kind;
    (yyval.expression).val=fmtstr("(*(%s))", (yyvsp[(1) - (2)].expression).val);
    free((yyvsp[(1) - (2)].expression).val);
  }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 703 "axo_gram.y"
    {
    char* var_name = "";
    axo_typ_def td;
    switch((yyvsp[(1) - (1)].identifier_type).kind){
      case axo_identifier_var_kind:
        var_name = (char*)((yyvsp[(1) - (1)].identifier_type).data);
        axo_var* var = axo_get_var(top_scope, (char*)((yyvsp[(1) - (1)].identifier_type).data));
        if (var == NULL && rval_now)
          axo_yyerror(&(yylsp[(1) - (1)]), "Variable '%s' undefined before usage.", (char*)((yyvsp[(1) - (1)].identifier_type).data));
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
        td = (yyvsp[(1) - (1)].identifier_type).typ_def;
        switch (td.typ.kind){
          case axo_enum_kind:
            (yyval.expression) = (axo_expr){
              .kind=axo_expr_enum_typ_kind,
              .typ=td.typ,
              .val=fmtstr("%s$%s", td.name, ((axo_enum*)(td.typ.enumerate))->names[0])
            };
            break;
          default:
            axo_yyerror(&(yylsp[(1) - (1)]), "Non-enum type '%s' is not an expression.", td.name);
            break;
        }
        break;
      default:
        axo_yyerror(&(yylsp[(1) - (1)]), "Invalid identifier as expression.");
        break;
    }
  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 741 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(1) - (5)]), (yyvsp[(1) - (5)].expression)) && axo_validate_rval(&(yylsp[(3) - (5)]), (yyvsp[(3) - (5)].expression)) && axo_validate_rval(&(yylsp[(5) - (5)]), (yyvsp[(5) - (5)].expression))){
      if (axo_typ_eq((yyvsp[(3) - (5)].expression).typ, (yyvsp[(5) - (5)].expression).typ)){
        (yyval.expression) = (axo_expr){
          .kind=axo_expr_normal_kind,
          .lval_kind=axo_not_lval_kind,
          .val=fmtstr("(%s?%s:%s)", (yyvsp[(1) - (5)].expression).val, (yyvsp[(3) - (5)].expression).val, (yyvsp[(5) - (5)].expression).val),
          .typ=(yyvsp[(3) - (5)].expression).typ
        };
        free((yyvsp[(1) - (5)].expression).val);
        free((yyvsp[(3) - (5)].expression).val);
        free((yyvsp[(5) - (5)].expression).val);
      }else{
        axo_yyerror(&(yyloc), "Ternary expression cannot return both '%s' and '%s'.", axo_typ_to_str((yyvsp[(3) - (5)].expression).typ), axo_typ_to_str((yyvsp[(5) - (5)].expression).typ));
      }
    }
  }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 758 "axo_gram.y"
    {(yyval.expression) = axo_call_to_expr((yyvsp[(1) - (1)].function_call));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 759 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 770 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 781 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s==%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 792 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s!=%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 803 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s>=%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 814 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s<=%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
    free((yyvsp[(1) - (3)].expression).val);
    free((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 825 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("%s||%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
    };
  }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 834 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression));
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .typ = axo_bool_typ(state),
      .val = fmtstr("!(%s)", (yyvsp[(2) - (2)].expression).val),
      .lval_kind = axo_not_lval_kind
    };
    if ((yyvsp[(2) - (2)].expression).typ.kind != axo_simple_kind)
      axo_yyerror(&(yylsp[(2) - (2)]), "Negation can only be used on primitive types (byte, int etc.)");
  }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 845 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression)) && axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[(1) - (3)].expression).typ,
        .val = fmtstr("%s&&%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
      };
    }
  }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 854 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression)) && axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[(1) - (3)].expression).typ,
        .val = fmtstr("%s>>%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
      };
    }
  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 863 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression)) && axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression))){
      (yyval.expression) = (axo_expr){
        .kind = axo_expr_normal_kind,
        .typ = (yyvsp[(1) - (3)].expression).typ,
        .val = fmtstr("%s<<%s", (yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val)
      };
    }
  }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 872 "axo_gram.y"
    {
    (yyval.expression).typ = (yyvsp[(1) - (1)].struct_val_type).typ;
    axo_struct* structure = (axo_struct*)((yyval.expression).typ.structure);
    //size of the string to avoid reallocing: (name){.field1=value1, }
    int v_len = strlen(structure->name) + 5 + 2;
    for (int i=0; i<structure->fields_len; i++){
      v_len+=strlen(structure->fields[i].name)+4+strlen((yyvsp[(1) - (1)].struct_val_type).fields[i]);  //name of a field + 3 cause of .=
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
      strcat(v, (yyvsp[(1) - (1)].struct_val_type).fields[i]);
    }
    strcat(v,"})");
    (yyval.expression).val = v;
    (yyval.expression).kind = axo_expr_normal_kind;
  }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 895 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression));
    (yylsp[(2) - (3)]).last_column = (yylsp[(3) - (3)]).last_column;
    axo_arr_typ arr_typ;
    switch((yyvsp[(1) - (3)].expression).typ.kind){
      case axo_arr_kind:
        arr_typ = axo_get_arr_typ((yyvsp[(1) - (3)].expression).typ);
        (yylsp[(2) - (3)]).last_column = (yylsp[(3) - (3)]).last_column;
        if (arr_typ.dim_count != (yyvsp[(2) - (3)].index_access_type).index_count){
          axo_yyerror(&(yylsp[(2) - (3)]), "Cannot index %d dimensional array with %d dimensional index.", arr_typ.dim_count, (yyvsp[(2) - (3)].index_access_type).index_count);
        }else{
          (yyval.expression).val = axo_arr_access_to_str(&(yylsp[(1) - (3)]), (yyvsp[(1) - (3)].expression), &(yylsp[(2) - (3)]), (yyvsp[(2) - (3)].index_access_type));
          (yyval.expression).typ = arr_typ.subtyp;
          (yyval.expression).lval_kind = ((yyvsp[(1) - (3)].expression).lval_kind == axo_not_lval_kind ? axo_not_lval_kind : axo_other_lval_kind);
        }
        break;
      case axo_ptr_kind:
        if ((yyvsp[(2) - (3)].index_access_type).index_count != 1)
          axo_yyerror(&(yylsp[(2) - (3)]), "Expected a 1 dimensional index to access a pointer, but got %d dimensional index.", (yyvsp[(2) - (3)].index_access_type).index_count);
        (yyval.expression).typ = *axo_subtyp((yyvsp[(1) - (3)].expression).typ);
        (yyval.expression).val = fmtstr("%s[%s]", (yyvsp[(1) - (3)].expression).val, (yyvsp[(2) - (3)].index_access_type).indexes[0].val);
        break;
      default:
        axo_yyerror(&(yylsp[(1) - (3)]), "Cannot index an expression of type '%s'.", axo_typ_to_str((yyvsp[(1) - (3)].expression).typ));
        break;
    }
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_free_index_access((yyvsp[(2) - (3)].index_access_type));
  }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 924 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (2)]), (yyvsp[(1) - (2)].expression));
    (yyval.expression) = axo_expr_dot_field(state, &(yyloc), &(yylsp[(1) - (2)]), &(yylsp[(2) - (2)]), (yyvsp[(1) - (2)].expression), (yyvsp[(2) - (2)].str));
  }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 928 "axo_gram.y"
    {
    const axo_typ_def* lu_def = axo_get_typ_def(state, "size_t");
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("sizeof(%s)", (yyvsp[(3) - (4)].expression).val),
      .typ = lu_def->typ
    };
  }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 937 "axo_gram.y"
    {
    const axo_typ_def* lu_def = axo_get_typ_def(state, "size_t");
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("sizeof(%s)", axo_typ_to_c_str((yyvsp[(3) - (4)].typ_type))),
      .typ = lu_def->typ
    };
  }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 946 "axo_gram.y"
    {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("%d", (yyloc).first_line),
      .typ = axo_int_typ(state)
    };
  }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 954 "axo_gram.y"
    {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("%d", (yyloc).first_column),
      .typ = axo_int_typ(state)
    };
  }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 962 "axo_gram.y"
    {
    (yyval.expression) = (axo_expr){
      .kind = axo_expr_normal_kind,
      .lval_kind = axo_not_lval_kind,
      .val = fmtstr("\"%s\"", axo_src_path(state)),
      .typ = axo_str_typ(state)
    };
  }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 972 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (5)]), (yyvsp[(1) - (5)].expression));
    switch((yyvsp[(1) - (5)].expression).typ.kind){
      case axo_simple_kind:
      case axo_literal_kind:
        if ((yyvsp[(4) - (5)].typ_type).kind != axo_simple_kind)
          axo_yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[(1) - (5)].expression).typ), axo_typ_to_str((yyvsp[(4) - (5)].typ_type)));
        else
          (yyval.expression) = (axo_expr){
            .typ=(yyvsp[(4) - (5)].typ_type),
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str((yyvsp[(4) - (5)].typ_type)), (yyvsp[(1) - (5)].expression).val),
            .kind=axo_expr_normal_kind,
            .lval_kind=(yyvsp[(1) - (5)].expression).lval_kind
          };
        break;
      case axo_ptr_kind:
        if ((yyvsp[(4) - (5)].typ_type).kind != axo_ptr_kind)
          axo_yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[(1) - (5)].expression).typ), axo_typ_to_str((yyvsp[(4) - (5)].typ_type)));
        else
          (yyval.expression) = (axo_expr){
            .typ=(yyvsp[(4) - (5)].typ_type),
            .val=fmtstr("((%s)(%s))", axo_typ_to_c_str((yyvsp[(4) - (5)].typ_type)), (yyvsp[(1) - (5)].expression).val),
            .kind=axo_expr_normal_kind,
            .lval_kind=(yyvsp[(1) - (5)].expression).lval_kind
          };
        break;
      default:
          axo_yyerror(&(yyloc), "Cannot cast type '%s' to '%s'.", axo_typ_to_str((yyvsp[(1) - (5)].expression).typ), axo_typ_to_str((yyvsp[(4) - (5)].typ_type)));
        break;
    }
  }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 1003 "axo_gram.y"
    {
    axo_var* var = axo_get_var(top_scope, "_axo_self_param");
    if (!var){
      axo_yyerror(&(yyloc), "Cannot use self param '$' outside of a method.");
      YYERROR;
    }
    (yyval.expression) = (axo_expr){
      .val=alloc_str("_axo_self_param"),
      .typ=(var ? var->typ : axo_no_typ),
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_var_lval_kind
    };
  }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 1018 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (4)]), (yyvsp[(2) - (4)].expression));
    axo_validate_rval(&(yylsp[(4) - (4)]), (yyvsp[(4) - (4)].expression));
    if (!axo_typ_eq((yyvsp[(2) - (4)].expression).typ, (yyvsp[(4) - (4)].expression).typ)){
            axo_yyerror(&(yylsp[(4) - (4)]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[(4) - (4)].expression).typ), axo_typ_to_str((yyvsp[(2) - (4)].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[(1) - (4)].bool_type),
      .len=(int[]){0},
      .dim_count=1,
      .count=2,
      .val=fmtstr("%s,%s", (yyvsp[(2) - (4)].expression).val, (yyvsp[(4) - (4)].expression).val),
      .typ=(yyvsp[(2) - (4)].expression).typ
    };
  }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 1033 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(4) - (6)]), (yyvsp[(4) - (6)].expression));
    axo_validate_rval(&(yylsp[(6) - (6)]), (yyvsp[(6) - (6)].expression));
    if (!axo_typ_eq((yyvsp[(4) - (6)].expression).typ, (yyvsp[(6) - (6)].expression).typ)){
            axo_yyerror(&(yylsp[(6) - (6)]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[(6) - (6)].expression).typ), axo_typ_to_str((yyvsp[(4) - (6)].expression).typ));
    }
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[(1) - (6)].empty_arr_lit_type).dynamic,
      .len=(yyvsp[(1) - (6)].empty_arr_lit_type).len,
      .dim_count=(yyvsp[(1) - (6)].empty_arr_lit_type).dim_count,
      .count=2,
      .val= fmtstr("%s, %s", (yyvsp[(4) - (6)].expression).val, (yyvsp[(6) - (6)].expression).val),
      .typ=(yyvsp[(4) - (6)].expression).typ
    };
  }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 1048 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    if (!axo_typ_eq((yyval.arr_lit_type).typ, (yyvsp[(3) - (3)].expression).typ)){
            axo_yyerror(&(yylsp[(3) - (3)]), "A '%s' value cannot be an element of a '%s' array.", axo_typ_to_str((yyvsp[(3) - (3)].expression).typ), axo_typ_to_str((yyval.arr_lit_type).typ));
    }
    strapnd(&(yyval.arr_lit_type).val, ",");
    strapnd(&(yyval.arr_lit_type).val, (yyvsp[(3) - (3)].expression).val);
    (yyval.arr_lit_type).count++;
  }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 1059 "axo_gram.y"
    {
    (yyval.bool_type) = false;
  }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 1062 "axo_gram.y"
    {
    (yyval.bool_type) = true;
  }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1067 "axo_gram.y"
    {
    (yyval.empty_arr_lit_type) = (axo_empty_arr_lit){
      .dynamic=(yyvsp[(1) - (2)].bool_type),
      .len=malloc(axo_empty_arr_lit_cap),
      .dim_count=1
    };
    (yyval.empty_arr_lit_type).len[0] = atoi((yyvsp[(2) - (2)].str));
    free((yyvsp[(2) - (2)].str));
  }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 1076 "axo_gram.y"
    {
    (yyval.empty_arr_lit_type).len[(yyval.empty_arr_lit_type).dim_count++] = atoi((yyvsp[(3) - (3)].str));
    free((yyvsp[(3) - (3)].str));
  }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1082 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (4)]), (yyvsp[(2) - (4)].expression));
    axo_typ subtyp[1] = {(yyvsp[(2) - (4)].expression).typ};
    (yyval.arr_lit_type) = (axo_arr_lit){
      .dynamic=(yyvsp[(1) - (4)].bool_type),
      .len=(int[]){1},
      .dim_count=1,
      .count=1,
      .val= (yyvsp[(1) - (4)].bool_type) ?
          fmtstr("axo_arr_new_dyn(axo_dyn_bytes_cpy(%s, (%s){%s}, sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){1}, sizeof(axo_arr_dim_t)))",
          axo_typ_to_c_str((axo_typ){.kind=axo_ptr_kind, .subtyp=subtyp}), axo_c_arr_of_typ((yyvsp[(2) - (4)].expression).typ, "1"), (yyvsp[(2) - (4)].expression).val, axo_typ_to_c_str((yyvsp[(2) - (4)].expression).typ))
          : fmtstr("axo_arr_new_stat((%s){%s}, ((axo_arr_dim_t[]){1}))",
          axo_c_arr_of_typ((yyvsp[(2) - (4)].expression).typ, "1"), (yyvsp[(2) - (4)].expression).val),
      .typ=(yyvsp[(2) - (4)].expression).typ
    };
  }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1098 "axo_gram.y"
    {
    char* data_str = (yyval.arr_lit_type).val;
    (yyval.arr_lit_type).val = NULL;
    if ((yyval.arr_lit_type).len[0] != 0){
      unsigned expected = 1;
      for (int i=0; i<(yyval.arr_lit_type).dim_count; i++)
        expected *= (yyval.arr_lit_type).len[i];
      if (expected != (yyval.arr_lit_type).count)
        axo_yyerror(&(yyloc), "Expected %u elements, but provided %u.", expected, (yyval.arr_lit_type).count);
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
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1130 "axo_gram.y"
    {
    (yyval.expression)=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val=(yyvsp[(1) - (1)].arr_lit_type).val,
    };
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    arr_typ->subtyp = (yyvsp[(1) - (1)].arr_lit_type).typ;
    arr_typ->dim_count = (yyvsp[(1) - (1)].arr_lit_type).dim_count;
    (yyval.expression).typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ,
      .def=NULL
    };
  }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1145 "axo_gram.y"
    {
    char* dims_str = empty_str;
    unsigned total_sz = 1;
    for (int i=0; i<(yyvsp[(1) - (3)].empty_arr_lit_type).dim_count; i++){
      total_sz *= (yyvsp[(1) - (3)].empty_arr_lit_type).len[i];
      if (i>0) strapnd(&dims_str, ",");
      strapnd(&dims_str, fmt_str((char[16]){}, "%d", (yyvsp[(1) - (3)].empty_arr_lit_type).len[i]));
    }
    axo_typ typ = (axo_typ){
      .kind=axo_arr_kind,
      .arr=malloc(sizeof(axo_arr_typ)),
      .def=NULL
    };
    axo_get_arr_typ(typ).subtyp = (yyvsp[(3) - (3)].typ_type);
    axo_get_arr_typ(typ).dim_count = (yyvsp[(1) - (3)].empty_arr_lit_type).dim_count;
    char sz_str[128];
    sprintf(sz_str, "%u", total_sz);
    (yyval.expression)=(axo_expr){
      .kind=axo_expr_normal_kind,
      .lval_kind=axo_not_lval_kind,
      .val= (yyvsp[(1) - (3)].empty_arr_lit_type).dynamic ?
          fmtstr("axo_arr_new_dyn(malloc((%u)*sizeof(%s)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){%s}, (%d)*sizeof(axo_arr_dim_t)))", total_sz, axo_typ_to_c_str(axo_get_arr_typ(typ).subtyp), dims_str, (yyvsp[(1) - (3)].empty_arr_lit_type).dim_count)
          : fmtstr("axo_arr_new_stat((%s){}, ((axo_arr_dim_t[]){%s}))", axo_c_arr_of_typ((yyvsp[(3) - (3)].typ_type), sz_str), dims_str),
      .typ=typ
    };
    free(dims_str);
  }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1176 "axo_gram.y"
    {
    axo_validate_expr_as_statement(&(yylsp[(1) - (1)]), (yyvsp[(1) - (1)].expression));
    (yyval.statement_type).val = (yyvsp[(1) - (1)].expression).val;
    strapnd(&((yyval.statement_type).val), ";");
    (yyval.statement_type).kind = axo_call_statement_kind;
  }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1182 "axo_gram.y"
    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_empty_statement_kind,
      .val=alloc_str(";")
    };
  }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1188 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression));
    (yyval.statement_type).val=fmtstr("return %s;", (yyvsp[(2) - (2)].expression).val);
    (yyval.statement_type).kind = axo_ret_statement_kind;
    axo_var* parent_func = (axo_var*)(top_scope->parent_func);
    if (parent_func){
      axo_typ* ret_typ = &(((axo_func_typ*)(parent_func->typ.func_typ))->ret_typ);
      if (axo_is_no_typ(*ret_typ)){
        *ret_typ = (yyvsp[(2) - (2)].expression).typ;
      }else if(!axo_typ_eq(*ret_typ, (yyvsp[(2) - (2)].expression).typ)){
        char hlpr[64] = "";
        strcpy(hlpr, axo_typ_to_str(*ret_typ));
        axo_yyerror(&(yylsp[(2) - (2)]), "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str((yyvsp[(2) - (2)].expression).typ), hlpr);
      }
    }else{
      axo_yyerror(&(yylsp[(1) - (2)]), "Couldn't return outside of a function body.");
    }
    free((yyvsp[(2) - (2)].expression).val);
  }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1207 "axo_gram.y"
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
        axo_yyerror(&(yylsp[(2) - (2)]), "Cannot return %s type, expected %s type to be returned.", axo_typ_to_str(axo_none_typ), hlpr);
      }
    }else{
      axo_yyerror(&(yylsp[(1) - (2)]), "Couldn't return outside of a function body.");
    }
  }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1224 "axo_gram.y"
    {
    (yyval.statement_type) = axo_scope_to_statement((yyvsp[(1) - (1)].scope));
    axo_free_scope((yyvsp[(1) - (1)].scope));
  }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1228 "axo_gram.y"
    {
    if ((yyvsp[(1) - (4)].expression).lval_kind == axo_var_lval_kind){
      char* ntd = axo_name_typ_decl((yyvsp[(1) - (4)].expression).val, (yyvsp[(4) - (4)].typ_type));
      (yyval.statement_type) = (axo_statement){
        .kind=axo_var_is_decl_statement_kind,
        .val=ntd
      };
      strapnd(&((yyval.statement_type).val), ";");
      axo_set_var(top_scope, (axo_var){.name=(yyvsp[(1) - (4)].expression).val, .typ=axo_clean_typ((yyvsp[(4) - (4)].typ_type))});
    }else{
      axo_yyerror(&(yylsp[(1) - (4)]), "Cannot declare non-variable value '%s'.", (yyvsp[(1) - (4)].expression).val);
    }
    free((yyvsp[(1) - (4)].expression).val);
  }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1242 "axo_gram.y"
    {
    if (in_loop_count<=0) axo_yyerror(&(yylsp[(1) - (1)]), "No loop/switch to continue from.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_continue_statement_kind,
      .val = alloc_str("continue;")
    };
  }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1249 "axo_gram.y"
    {
    if (in_loop_count<=0) axo_yyerror(&(yylsp[(1) - (1)]), "No loop/switch to break out of.");
    (yyval.statement_type) = (axo_statement){
      .kind = axo_break_statement_kind,
      .val = alloc_str("break;")
    };
  }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1256 "axo_gram.y"
    {
    (yyval.statement_type) = axo_switch_to_statement((yyvsp[(1) - (1)].switch_type));
  }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1259 "axo_gram.y"
    {
    top_scope->defer_used = true;
    (yyval.statement_type) = (axo_statement){
      .kind=axo_defer_statement_kind,
      .val=fmtstr("Defer({%s});", (yyvsp[(2) - (2)].statement_type).val)
    };
    free((yyvsp[(2) - (2)].statement_type).val);
  }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1267 "axo_gram.y"
    {
    axo_typ typ = axo_merge_type_with_qualifiers((yyvsp[(4) - (4)].expression).typ, (yyvsp[(1) - (4)].typ_type));
    axo_validate_rval(&(yylsp[(4) - (4)]), (yyvsp[(4) - (4)].expression));
    char* var_name = ((char*)((yyvsp[(2) - (4)].identifier_type).data));
    if ((yyvsp[(2) - (4)].identifier_type).kind != axo_identifier_var_kind || axo_get_var(top_scope, var_name) != NULL){
      axo_yyerror(&(yylsp[(2) - (4)]), "Cannot declare variable, it's already a %s.", axo_identifier_kind_to_str((yyvsp[(2) - (4)].identifier_type).kind));
      YYERROR;
    }
    axo_var var = (axo_var){.name=var_name, .typ=typ};
    axo_set_var(top_scope, var);
    char* assign_decl = axo_get_var_decl_assign(&(yyloc), var, (yyvsp[(4) - (4)].expression));
    (yyval.statement_type) = (axo_statement){
      .kind=axo_assignment_statement_kind,
      .val = fmtstr("%s;", assign_decl)
    };
    free(assign_decl);
  }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1290 "axo_gram.y"
    {
    if ((yyvsp[(2) - (2)].expression).typ.kind != axo_simple_kind)
      axo_yyerror(&(yylsp[(2) - (2)]), "Cannot switch on a non-primitive (%s) value.", axo_typ_to_str((yyvsp[(2) - (2)].expression).typ));
    (yyval.switch_type) = (axo_switch){
      .root = (yyvsp[(2) - (2)].expression)
    };
    in_loop_count++;
  }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1300 "axo_gram.y"
    {
    (yyval.switch_type) = (axo_switch){
      .root=(yyvsp[(1) - (4)].switch_type).root,
      .cases = (yyvsp[(3) - (4)].switch_type).cases,
      .cases_len = (yyvsp[(3) - (4)].switch_type).cases_len
    };
    in_loop_count--;
  }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1310 "axo_gram.y"
    {
    (yyval.switch_type) = (axo_switch){
      .cases = (axo_switch_case*)malloc(axo_cases_cap*sizeof(axo_switch_case)),
      .cases_len = 1
    };
    (yyval.switch_type).cases[0] = (yyvsp[(1) - (2)].case_type);
    (yyval.switch_type).cases[0].statement = (yyvsp[(2) - (2)].statement_type);
  }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1318 "axo_gram.y"
    {
    resize_dyn_arr_if_needed(axo_switch_case, (yyval.switch_type).cases, (yyval.switch_type).cases_len, axo_cases_cap);
    (yyval.switch_type).cases[(yyval.switch_type).cases_len] = (yyvsp[(2) - (3)].case_type);
    (yyval.switch_type).cases[(yyval.switch_type).cases_len++].statement = (yyvsp[(3) - (3)].statement_type);
  }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1325 "axo_gram.y"
    {
    (yyval.case_type)=(yyvsp[(1) - (3)].case_type);
    (yyval.case_type).no_break = true;
  }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1332 "axo_gram.y"
    {
    (yyval.case_type) = (yyvsp[(1) - (2)].case_type);
  }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1346 "axo_gram.y"
    {
    (yyval.case_type) = (axo_switch_case){
      .exprs = (axo_expr*)malloc(axo_switch_expr_list_cap*sizeof(axo_expr)),
      .exprs_len = 1,
      .kind = axo_list_case_kind
    };
    (yyval.case_type).exprs[0] = (yyvsp[(1) - (1)].expression);
  }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1354 "axo_gram.y"
    {
    resize_dyn_arr_if_needed(axo_expr, (yyval.case_type).exprs, (yyval.case_type).exprs_len, axo_switch_expr_list_cap);
    (yyval.case_type).exprs[(yyval.case_type).exprs_len++] = (yyvsp[(3) - (3)].expression);
  }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1360 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression));
    (yyval.expression) = (yyvsp[(2) - (2)].expression);
  }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1366 "axo_gram.y"
    {
    (yyval.statement_type).val = fmtstr("if(%s)%s\nelse\n%s", (yyvsp[(1) - (4)].expression).val, (yyvsp[(2) - (4)].statement_type).val, (yyvsp[(4) - (4)].statement_type).val);
  }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1377 "axo_gram.y"
    {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s", (yyvsp[(1) - (2)].expression).val, (yyvsp[(2) - (2)].statement_type).val);
  }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1380 "axo_gram.y"
    {
    (yyval.statement_type).val = fmtstr("if(%s)\n%s\nelse\n%s", (yyvsp[(1) - (4)].expression).val, (yyvsp[(2) - (4)].statement_type).val, (yyvsp[(4) - (4)].statement_type).val);
  }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1385 "axo_gram.y"
    {
    (yyval.till_loop_type).iter = (yyvsp[(3) - (6)].str);
    (yyval.till_loop_type).start = "0";
    (yyval.till_loop_type).lim = (yyvsp[(5) - (6)].expression);
    printf("till iter %s created scope\n", (yyval.till_loop_type).iter);
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_set_var(top_scope, (axo_var){.typ=state->int_def->typ, .name=(yyval.till_loop_type).iter});
  }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1395 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression)))
      (yyval.str) = alloc_str((yyvsp[(2) - (2)].expression).val);
    in_loop_count++;
  }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1402 "axo_gram.y"
    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].statement_type).val),
    };
    in_loop_count--;
  }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1411 "axo_gram.y"
    {
    (yyval.statement_type) = (axo_statement){
      .kind=axo_while_statement_kind,
      .val=fmtstr("while(%s)\n%s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].statement_type).val),
    };
    in_loop_count--;
  }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1420 "axo_gram.y"
    {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    in_loop_count++;
  }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1426 "axo_gram.y"
    {
    (yyval.for_loop_type).start = (yyvsp[(2) - (2)].statement_type).val;
  }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1431 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(3) - (5)]), (yyvsp[(3) - (5)].expression));
    char* iter = (yyvsp[(5) - (5)].statement_type).val;
    iter[strlen(iter)-1] = '\0';
    (yyval.for_loop_type) = (axo_for_loop){
      .start = (yyvsp[(1) - (5)].for_loop_type).start,
      .condition = (yyvsp[(3) - (5)].expression).val,
      .iteration = iter,
    };
  }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1441 "axo_gram.y"
    {
    (yyval.for_loop_type) = (axo_for_loop){
      .start = fmtstr("int %s=%s;", (yyvsp[(1) - (1)].till_loop_type).iter, (yyvsp[(1) - (1)].till_loop_type).start),
      .condition = fmtstr("%s<%s", (yyvsp[(1) - (1)].till_loop_type).iter, (yyvsp[(1) - (1)].till_loop_type).lim.val),
      .iteration = fmtstr("%s++", (yyvsp[(1) - (1)].till_loop_type).iter),
    };
  }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1451 "axo_gram.y"
    {
    (yyvsp[(1) - (2)].for_loop_type).body = (yyvsp[(2) - (2)].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[(1) - (2)].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1459 "axo_gram.y"
    {
    (yyvsp[(1) - (2)].for_loop_type).body = (yyvsp[(2) - (2)].statement_type).val;
    (yyval.statement_type).kind = axo_for_statement_kind;
    (yyval.statement_type).val=axo_for_loop_to_str((yyvsp[(1) - (2)].for_loop_type));
    scopes->len--;
    in_loop_count--;
  }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1468 "axo_gram.y"
    {
    (yyvsp[(1) - (2)].each_loop_type).body = (yyvsp[(2) - (2)].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[(1) - (2)].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1476 "axo_gram.y"
    {
    (yyvsp[(1) - (2)].each_loop_type).body = (yyvsp[(2) - (2)].statement_type).val;
    (yyval.statement_type) = axo_each_to_statement((yyvsp[(1) - (2)].each_loop_type));
    scopes->len--;
    in_loop_count--;
  }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1484 "axo_gram.y"
    {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=1,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (yyvsp[(2) - (2)].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3] = (yylsp[(2) - (2)]);
  }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1493 "axo_gram.y"
    {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=2,
      .dim_iters=(axo_expr*)malloc(128*sizeof(axo_expr)),
      .locs=(YYLTYPE*)malloc(128*sizeof(YYLTYPE))
    };
    (yyval.each_loop_type).dim_iters[0] = (axo_expr){.val=NULL};
    (yyval.each_loop_type).dim_iters[1] = (yyvsp[(3) - (3)].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[4] = (yylsp[(3) - (3)]);
  }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1503 "axo_gram.y"
    {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count] = (yyvsp[(3) - (3)].expression);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[3+(yyval.each_loop_type).dim_count++] = (yylsp[(3) - (3)]);
  }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1507 "axo_gram.y"
    {
    (yyval.each_loop_type).dim_iters[(yyval.each_loop_type).dim_count++] = (axo_expr){.val=NULL};
  }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1512 "axo_gram.y"
    {
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=axo_get_arr_typ((yyvsp[(4) - (4)].expression).typ).dim_count,
      .dim_iters=malloc(axo_get_arr_typ((yyvsp[(4) - (4)].expression).typ).dim_count*sizeof(axo_expr)),
      .value_iter=(yyvsp[(2) - (4)].identifier_type),
      .collection=(yyvsp[(4) - (4)].expression),
      .locs=malloc(3*sizeof(YYLTYPE*))
    };
    for (int i=0; i<(yyval.each_loop_type).dim_count; i++)
      (yyval.each_loop_type).dim_iters[i].val = NULL;
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[(2) - (4)]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[(4) - (4)]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1526 "axo_gram.y"
    {
    (yylsp[(4) - (7)]).last_column = (yylsp[(5) - (7)]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[(4) - (7)].each_loop_type).dim_count,
      .dim_iters=(yyvsp[(4) - (7)].each_loop_type).dim_iters,
      .value_iter=(yyvsp[(2) - (7)].identifier_type),
      .collection=(yyvsp[(7) - (7)].expression),
      .locs=(yyvsp[(4) - (7)].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[0] = (yylsp[(2) - (7)]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[(4) - (7)]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[(7) - (7)]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1540 "axo_gram.y"
    {
    (yylsp[(3) - (6)]).last_column = (yylsp[(3) - (6)]).last_column;
    (yyval.each_loop_type) = (axo_each_loop){
      .dim_count=(yyvsp[(3) - (6)].each_loop_type).dim_count,
      .dim_iters=(yyvsp[(3) - (6)].each_loop_type).dim_iters,
      .value_iter=(axo_identifier){.kind=axo_no_identifier_kind, .data=NULL},
      .collection=(yyvsp[(6) - (6)].expression),
      .locs=(yyvsp[(3) - (6)].each_loop_type).locs
    };
    ((YYLTYPE*)((yyval.each_loop_type).locs))[1] = (yylsp[(3) - (6)]);
    ((YYLTYPE*)((yyval.each_loop_type).locs))[2] = (yylsp[(6) - (6)]);
    axo_parse_each_loop(&(yyval.each_loop_type), state, top_scope, in_loop_count);
  }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1555 "axo_gram.y"
    {
    rval_now = true;
  }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1560 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    (yyval.expression).kind=axo_expr_normal_kind;
    axo_typ l_typ = (yyvsp[(1) - (3)].expression).typ;
    switch((yyvsp[(1) - (3)].expression).lval_kind){
      case axo_var_lval_kind:
        if ((yyvsp[(1) - (3)].expression).typ.kind == axo_no_kind){
          l_typ = axo_clean_typ((yyvsp[(3) - (3)].expression).typ);
          axo_var var = (axo_var){.name=(yyvsp[(1) - (3)].expression).val, .typ=(yyvsp[(3) - (3)].expression).typ};
          (yyval.expression).val = axo_get_var_decl_assign(&(yyloc), var, (axo_expr){.typ=l_typ, .val=(yyvsp[(3) - (3)].expression).val});
          axo_set_var(top_scope, (axo_var){.typ = l_typ, .name = (yyvsp[(1) - (3)].expression).val});
          (yyval.expression).kind = axo_expr_assigned_declaration_kind;
        }else{
          (yyval.expression).val = fmtstr("%s=%s",(yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val);
        }
        break;
      case axo_not_lval_kind:
        axo_yyerror(&(yylsp[(1) - (3)]), "Cannot assign to a non-lvalue");
        break;
      default:
        if (!axo_typ_eq(l_typ, (yyvsp[(3) - (3)].expression).typ))
          axo_yyerror(&(yyloc), "Cannot assign '%s' to '%s'.", axo_typ_to_str((yyvsp[(3) - (3)].expression).typ), axo_typ_to_str(l_typ));
        else{
          (yyval.expression).val = fmtstr("%s=%s",(yyvsp[(1) - (3)].expression).val, (yyvsp[(3) - (3)].expression).val);
        }
        break;
    }
    (yyval.expression).typ = l_typ;
    rval_now=false;
  }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1592 "axo_gram.y"
    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[(1) - (3)]), &(yylsp[(2) - (3)]), &(yylsp[(3) - (3)]), (yyvsp[(1) - (3)].expression), "+=", (yyvsp[(3) - (3)].expression));
  }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1595 "axo_gram.y"
    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[(1) - (3)]), &(yylsp[(2) - (3)]), &(yylsp[(3) - (3)]), (yyvsp[(1) - (3)].expression), "-=", (yyvsp[(3) - (3)].expression));
  }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1598 "axo_gram.y"
    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[(1) - (3)]), &(yylsp[(2) - (3)]), &(yylsp[(3) - (3)]), (yyvsp[(1) - (3)].expression), "*=", (yyvsp[(3) - (3)].expression));
  }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1601 "axo_gram.y"
    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[(1) - (3)]), &(yylsp[(2) - (3)]), &(yylsp[(3) - (3)]), (yyvsp[(1) - (3)].expression), "/=", (yyvsp[(3) - (3)].expression));
  }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1604 "axo_gram.y"
    {
    (yyval.expression) = axo_parse_special_assignment(&(yylsp[(1) - (3)]), &(yylsp[(2) - (3)]), &(yylsp[(3) - (3)]), (yyvsp[(1) - (3)].expression), "%=", (yyvsp[(3) - (3)].expression));
  }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1609 "axo_gram.y"
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
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1619 "axo_gram.y"
    {
    (yyval.typ_type)=(yyvsp[(1) - (2)].typ_type);
    axo_get_arr_typ((yyval.typ_type)).dim_count++;
  }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1625 "axo_gram.y"
    {
    if (axo_none_check((yyvsp[(3) - (3)].typ_type)))
      axo_yyerror(&(yylsp[(3) - (3)]), "None arrays are not a type.");
    axo_arr_typ* arr_typ = alloc_one(axo_arr_typ);
    *arr_typ = (axo_arr_typ){
      .subtyp=(yyvsp[(3) - (3)].typ_type),
      .dim_count=1
    };
    (yyval.typ_type) = (axo_typ){
      .kind=axo_arr_kind,
      .arr=arr_typ
    };
  }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1638 "axo_gram.y"
    {
    if (axo_none_check((yyvsp[(3) - (3)].typ_type)))
      axo_yyerror(&(yylsp[(3) - (3)]), "None arrays are not a type.");
    (yyval.typ_type) = (yyvsp[(1) - (3)].typ_type);
    axo_get_arr_typ((yyval.typ_type)).subtyp = (yyvsp[(3) - (3)].typ_type);
  }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1646 "axo_gram.y"
    {
    axo_func_typ* func_typ = alloc_one(axo_func_typ);
    func_typ->args_len=0;
    func_typ->args_types=NULL;
    func_typ->args_defs=NULL;
    func_typ->ret_typ=(yyvsp[(2) - (3)].typ_type);
    (yyval.typ_type) = (axo_typ){
      .kind = axo_func_kind,
      .func_typ=func_typ
    };
  }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1657 "axo_gram.y"
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
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1670 "axo_gram.y"
    {
    (yyval.typ_type)=(yyvsp[(1) - (2)].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    func_typ->args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    func_typ->args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    func_typ->args_types[0] = (yyvsp[(2) - (2)].typ_type);
    func_typ->args_defs[0] = alloc_str(axo_get_typ_default((yyvsp[(2) - (2)].typ_type)));
    func_typ->args_len++;
  }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1679 "axo_gram.y"
    {
    (yyval.typ_type)=(yyvsp[(1) - (3)].typ_type);
    axo_func_typ* func_typ = (axo_func_typ*)((yyval.typ_type).func_typ);
    resize_dyn_arr_if_needed(axo_typ, func_typ->args_types, func_typ->args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, func_typ->args_defs, func_typ->args_len, axo_func_args_cap);
    func_typ->args_types[func_typ->args_len] = (yyvsp[(3) - (3)].typ_type);
    func_typ->args_defs[func_typ->args_len] = alloc_str(axo_get_typ_default((yyvsp[(3) - (3)].typ_type)));
    func_typ->args_len++;
  }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1694 "axo_gram.y"
    {
    const axo_typ_def* def = axo_get_typ_def(state, (yyvsp[(1) - (1)].str));
    if (def==NULL){
      axo_yyerror(&(yylsp[(1) - (1)]), "Type '%s' isn't defined.", (yyvsp[(1) - (1)].str));
    }else{
      (yyval.typ_type)=def->typ;
    }
  }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1702 "axo_gram.y"
    {
    (yyval.typ_type) = (axo_typ){
      .kind = axo_ptr_kind,
      .subtyp = malloc(sizeof(axo_typ)),
      .def = NULL,
    };
    *axo_subtyp((yyval.typ_type))=(yyvsp[(2) - (2)].typ_type);
  }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1710 "axo_gram.y"
    {
    (yyval.typ_type) = axo_none_typ;
  }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1715 "axo_gram.y"
    {
    (yyval.typ_type) = (axo_typ){
      .kind = axo_c_arg_list_kind,
      .def = NULL,
    };
  }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1723 "axo_gram.y"
    {
    (yyval.typ_type).is_const=false;
    (yyval.typ_type).is_volatile=false;
  }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1727 "axo_gram.y"
    {
    (yyval.typ_type) = (yyvsp[(2) - (2)].typ_type);
    (yyval.typ_type).is_const=(yyvsp[(1) - (2)].typ_type).is_const;
    (yyval.typ_type).is_volatile=(yyvsp[(1) - (2)].typ_type).is_volatile;
  }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1735 "axo_gram.y"
    {
      (yyval.typ_type) = (axo_typ){
        .is_const=(yyvsp[(1) - (2)].typ_type).is_const||(yyvsp[(2) - (2)].typ_type).is_const,
        .is_volatile=(yyvsp[(1) - (2)].typ_type).is_volatile||(yyvsp[(2) - (2)].typ_type).is_volatile
      };
    }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1743 "axo_gram.y"
    {
      (yyval.typ_type) = (axo_typ){.is_const=true, .is_volatile=false};
    }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1746 "axo_gram.y"
    {
      (yyval.typ_type) = (axo_typ){.is_const=false, .is_volatile=true};
    }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1751 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(1) - (2)]), (yyvsp[(1) - (2)].expression))){
      switch((yyvsp[(1) - (2)].expression).typ.kind){
        case axo_func_kind:
          (yyval.function_call) = (axo_func_call){
            .typ = (yyvsp[(1) - (2)].expression).typ,
            .called_val = (yyvsp[(1) - (2)].expression).val,
            .params_len=0,
            .params=NULL
          };
          break;
        default:
          axo_yyerror(&(yylsp[(1) - (2)]), "Cannot call an expression of non-function type '%s'.", axo_typ_to_str((yyvsp[(1) - (2)].expression).typ));
          break;
      }
    }else{
      axo_yyerror(&(yylsp[(1) - (2)]), "Cannot call an invalid rval.");
    }
    // printf("ret_typ: %s\n", axo_typ_to_str(((axo_func*)($$.typ.func_typ))->f_typ.ret_typ));
  }
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1771 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expression));
    (yyval.function_call) = axo_method_call(state, top_scope, &(yyloc), &(yylsp[(1) - (4)]), &(yylsp[(3) - (4)]), (yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].str), rval_now);
  }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1777 "axo_gram.y"
    {
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[(1) - (1)].function_call).typ.func_typ);
    if ((yyval.function_call).params_len<fnt->args_len){
      resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
      (yyval.function_call).params[(yyval.function_call).params_len].val = alloc_str(fnt->args_defs[(yyval.function_call).params_len]);
      (yyval.function_call).params_len++;
    }
  }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1785 "axo_gram.y"
    {
    if (axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression))) {
      axo_func_typ* fnt = (axo_func_typ*)((yyvsp[(1) - (2)].function_call).typ.func_typ);
      if ((yyval.function_call).params_len <= fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[(yyval.function_call).params_len], (yyvsp[(2) - (2)].expression).typ)){
          axo_yyerror(&(yylsp[(2) - (2)]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[(yyval.function_call).params_len]), (yyval.function_call).params_len+1, axo_typ_to_str((yyvsp[(2) - (2)].expression).typ));
        }else{
          resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
          (yyval.function_call).params[(yyval.function_call).params_len++] = (yyvsp[(2) - (2)].expression);
        }
      }else{
        if (fnt->args_types[0].kind != axo_c_arg_list_kind)
          axo_yyerror(&(yylsp[(1) - (2)]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[(1) - (2)].function_call).typ));
      }
    }
  }
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1801 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(3) - (3)]), (yyvsp[(3) - (3)].expression));
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[(1) - (3)].function_call).typ.func_typ);
    resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
    int i = (yyval.function_call).params_len;
    if (fnt->args_types[fnt->args_len-1].kind != axo_c_arg_list_kind){
      if (i < fnt->args_len){
        if (!axo_typ_eq(fnt->args_types[i], (yyvsp[(3) - (3)].expression).typ))
          axo_yyerror(&(yylsp[(3) - (3)]), "Expected value of type "axo_underline_start"%s"axo_reset_style axo_red_fgs " for argument #%d, got type "axo_underline_start"%s"axo_reset_style axo_red_fgs" instead.", axo_typ_to_str(fnt->args_types[i]), i, axo_typ_to_str((yyvsp[(3) - (3)].expression).typ));
      }else{
          axo_yyerror(&(yylsp[(3) - (3)]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[(1) - (3)].function_call).typ));
      }
    }
    (yyval.function_call).params[i] = (yyvsp[(3) - (3)].expression);
    (yyval.function_call).params_len++;
  }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1817 "axo_gram.y"
    {
    (yyval.function_call) = (yyvsp[(1) - (2)].function_call);
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[(1) - (2)].function_call).typ.func_typ);
    char** defaults = fnt->args_defs;
    resize_dyn_arr_if_needed(axo_expr, (yyval.function_call).params, (yyval.function_call).params_len, axo_func_args_cap);
    int i = (yyval.function_call).params_len;
    if (i >= fnt->args_len-1 && fnt->args_types[fnt->args_len-1].kind == axo_c_arg_list_kind)
        axo_yyerror(&(yylsp[(2) - (2)]), "Cannot generate a default param for '...'.");
    else if (i >= fnt->args_len)
        axo_yyerror(&(yylsp[(2) - (2)]), "Too many parameters for function type '%s'", axo_typ_to_str((yyvsp[(1) - (2)].function_call).typ));
    (yyval.function_call).params[i].val = alloc_str(defaults[i]);
    (yyval.function_call).params_len++;
  }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1832 "axo_gram.y"
    {
    (yyval.function_call)=(yyvsp[(1) - (2)].function_call);
    axo_func_typ* fnt = (axo_func_typ*)((yyvsp[(1) - (2)].function_call).typ.func_typ);
    if (fnt->args_len>(yyval.function_call).params_len){
      // printf("Filling params with args defaults in call '%s'\n", $$.called_val);
      (yyval.function_call).params=(axo_expr*)realloc((yyval.function_call).params, fnt->args_len*sizeof(axo_expr));
      for (int i=(yyvsp[(1) - (2)].function_call).params_len; i<fnt->args_len-1; i++){ //Fill with defaults up until pre-last arg!
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
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1855 "axo_gram.y"
    {
    if (!axo_code_scope_started) axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = false;
  }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1861 "axo_gram.y"
    {
    (yyval.scope) = top_scope;
    scopes->len--;
  }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1867 "axo_gram.y"
    {
    (yyval.function) = (axo_func){
      .name=alloc_str((yyvsp[(1) - (1)].str)),
      .args_names=NULL
    };
  }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1873 "axo_gram.y"
    {
    axo_module* mod = axo_get_module(state, (yyvsp[(1) - (3)].str));
    if (!mod)
      axo_yyerror(&(yylsp[(1) - (3)]), "Module doesn't exist.");
    else
      (yyval.function) = (axo_func){
        .name=fmtstr("%s%s", mod->prefix, (yyvsp[(3) - (3)].str)),
        .args_names=NULL
      };
  }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1883 "axo_gram.y"
    {
    axo_typ* subtyp = alloc_one(axo_typ);
    *subtyp = (yyvsp[(1) - (3)].typ_type);
    axo_typ typ = (axo_typ){
      .kind=axo_ptr_kind,
      .subtyp=subtyp,
      .def=alloc_str("NULL")
    };
    switch((yyvsp[(1) - (3)].typ_type).kind){
      case axo_simple_kind:
      case axo_struct_kind:
      case axo_enum_kind:
      case axo_none_kind:
        (yyval.function) = (axo_func){
          .name=fmtstr("met_%s_%s", axo_typ_to_str((yyvsp[(1) - (3)].typ_type)), (yyvsp[(3) - (3)].str)),
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
        axo_yyerror(&(yylsp[(1) - (3)]), "Method are only allowed for structs, enums and primitives, but got %s.", axo_typ_kind_to_str((yyvsp[(1) - (3)].typ_type).kind));
        break;
    }
  }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1917 "axo_gram.y"
    {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    (yyval.typ_type) = axo_no_typ;
  }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1922 "axo_gram.y"
    {
    axo_push_scope(scopes, axo_new_scope(top_scope));
    axo_code_scope_started = true;
    (yyval.typ_type) = (yyvsp[(1) - (2)].typ_type);
  }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1929 "axo_gram.y"
    {
    int args_len = (yyvsp[(4) - (5)].function).f_typ.args_len;
    (yyval.function) = (axo_func){
      .name=(yyvsp[(2) - (5)].function).name
    };
    if ((yyvsp[(2) - (5)].function).args_names){
      args_len += (yyvsp[(2) - (5)].function).f_typ.args_len;
      (yyval.function).args_names = (char**)malloc(args_len*sizeof(char*));
      (yyval.function).f_typ = (axo_func_typ){
        .args_len = 0,
        .args_types=(axo_typ*)malloc(args_len*sizeof(axo_typ)),
        .args_defs=(char**)malloc(args_len*sizeof(char*)),
      };
      for (int i=0; i<(yyvsp[(2) - (5)].function).f_typ.args_len; i++){
        (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[(2) - (5)].function).args_names[i];
        (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[(2) - (5)].function).f_typ.args_types[i];
        (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len++] = (yyvsp[(2) - (5)].function).f_typ.args_defs[i];
      }
      for (int i=0; i<(yyvsp[(4) - (5)].function).f_typ.args_len; i++){
        (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[(4) - (5)].function).args_names[i];
        (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[(4) - (5)].function).f_typ.args_types[i];
        (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len++] = (yyvsp[(4) - (5)].function).f_typ.args_defs[i];
      }
    //Free func_args
    free((yyvsp[(4) - (5)].function).f_typ.args_types);
    }else{
      (yyval.function).args_names = (yyvsp[(4) - (5)].function).args_names;
      (yyval.function).f_typ.args_defs = (yyvsp[(4) - (5)].function).f_typ.args_defs;
      (yyval.function).f_typ.args_types = (yyvsp[(4) - (5)].function).f_typ.args_types;
      (yyval.function).f_typ.args_len = args_len;
    }
    (yyval.function).f_typ.ret_typ = (yyvsp[(1) - (5)].typ_type);
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
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1974 "axo_gram.y"
    {
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[(1) - (1)].str));
    if (td==NULL){
      axo_yyerror(&(yylsp[(1) - (1)]), "Structure '%s' undefined before usage.", (yyvsp[(1) - (1)].str));
    }else if (td->typ.kind!=axo_struct_kind){
      axo_yyerror(&(yylsp[(1) - (1)]), "Type '%s' is not a struture.", (yyvsp[(1) - (1)].str));
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
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1990 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].expression));
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[(1) - (2)].str));
    if (td==NULL){
      axo_yyerror(&(yylsp[(1) - (2)]), "Structure type '%s' undefined before usage.", (yyvsp[(1) - (2)].str));
    }else if (td->typ.kind!=axo_struct_kind){
      axo_yyerror(&(yylsp[(1) - (2)]), "Type '%s' is not a struture.", (yyvsp[(1) - (2)].str));
    }else if (!axo_typ_eq(((axo_struct*)(td->typ.structure))->fields[0].typ, (yyvsp[(2) - (2)].expression).typ)){
      axo_struct* structure = ((axo_struct*)(td->typ.structure));
      axo_yyerror(&(yylsp[(2) - (2)]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[0].typ), structure->fields[0].name, structure->name, axo_typ_to_str((yyvsp[(2) - (2)].expression).typ));
    }else{
      int total_field_count = ((axo_struct*)(td->typ.structure))->fields_len;
      (yyval.struct_val_type) = (axo_struct_val){
        .typ=td->typ,
        .fields=(char**)malloc(((axo_struct*)(td->typ.structure))->fields_len*sizeof(char*)),
        .fields_count=1
      };
      for (int i=1;i<total_field_count;i++) (yyval.struct_val_type).fields[i]=NULL;
      (yyval.struct_val_type).fields[0] = (yyvsp[(2) - (2)].expression).val;
    }
  }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 2011 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(4) - (4)]), (yyvsp[(4) - (4)].expression));
    const axo_typ_def* td = axo_get_typ_def(state, (yyvsp[(1) - (4)].str));
    axo_struct* structure = (axo_struct*)(td->typ.structure);
    if (td==NULL){
      axo_yyerror(&(yylsp[(1) - (4)]), "Structure type '%s' undefined before usage.", (yyvsp[(1) - (4)].str));
    }else if (td->typ.kind!=axo_struct_kind){
      axo_yyerror(&(yylsp[(1) - (4)]), "Type '%s' is not a structure.", (yyvsp[(1) - (4)].str));
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
        if (strcmp(structure->fields[i].name, (yyvsp[(2) - (4)].str))==0){
          index = i;
          break;
        }
      }
      if (index<0) axo_yyerror(&(yylsp[(2) - (4)]), "Structure '%s' doesn't have '%s' field.", structure->name, (yyvsp[(2) - (4)].str));
      else if (!axo_typ_eq(structure->fields[index].typ, (yyvsp[(4) - (4)].expression).typ)){
        axo_yyerror(&(yylsp[(4) - (4)]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[(4) - (4)].expression).typ));
      }else{
        (yyval.struct_val_type).fields[index] = (yyvsp[(4) - (4)].expression).val;
      }
    }
  }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 2042 "axo_gram.y"
    {
    (yyval.struct_val_type)=(yyvsp[(1) - (3)].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      axo_yyerror(&(yylsp[(3) - (3)]), "Too many fields provided to structure '%s'.", structure->name);
    }else if (!axo_typ_eq(structure->fields[(yyval.struct_val_type).fields_count].typ, (yyvsp[(3) - (3)].expression).typ)){
        axo_yyerror(&(yylsp[(3) - (3)]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[(yyval.struct_val_type).fields_count].typ), structure->fields[(yyval.struct_val_type).fields_count].name, structure->name, axo_typ_to_str((yyvsp[(3) - (3)].expression).typ));
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = (yyvsp[(3) - (3)].expression).val;
      (yyval.struct_val_type).fields_count++;
    }else{
      axo_yyerror(&(yylsp[(3) - (3)]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].name);    
    }
  }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 2056 "axo_gram.y"
    {
    (yyval.struct_val_type)=(yyvsp[(1) - (2)].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    if ((yyval.struct_val_type).fields_count==structure->fields_len){
      axo_yyerror(&(yylsp[(2) - (2)]), "Too many fields provided to structure '%s'.", structure->name);
    }else if ((yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count]==NULL){
      (yyval.struct_val_type).fields[(yyval.struct_val_type).fields_count] = ((axo_struct*)((yyvsp[(1) - (2)].struct_val_type).typ.structure))->fields[(yyval.struct_val_type).fields_count].def;
      (yyval.struct_val_type).fields_count++;
    }
  }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 2066 "axo_gram.y"
    {
    axo_validate_rval(&(yylsp[(5) - (5)]), (yyvsp[(5) - (5)].expression));
    (yyval.struct_val_type)=(yyvsp[(1) - (5)].struct_val_type);
    axo_struct* structure = (axo_struct*)((yyval.struct_val_type).typ.structure);
    int index = -1;
    for (int i=0;i<structure->fields_len; i++){
      if (strcmp(structure->fields[i].name, (yyvsp[(3) - (5)].str))==0){
        index = i;
        break;
      }
    }
    if (index<0) axo_yyerror(&(yylsp[(3) - (5)]), "Structure '%s' doesn't have '%s' field.", structure->name, (yyvsp[(3) - (5)].str));
    else if (!axo_typ_eq(structure->fields[index].typ, (yyvsp[(5) - (5)].expression).typ)){
        axo_yyerror(&(yylsp[(5) - (5)]),"Expected type '%s' in field '%s' of struct '%s', but got '%s'.", axo_typ_to_str(structure->fields[index].typ), structure->fields[index].name, structure->name, axo_typ_to_str((yyvsp[(5) - (5)].expression).typ));
    }else if ((yyval.struct_val_type).fields[index]==NULL){
      (yyval.struct_val_type).fields[index] = (yyvsp[(5) - (5)].expression).val;
    }else{
      axo_yyerror(&(yylsp[(3) - (5)]), "Structure field '%s' was arleady assigned a value.", ((axo_struct*)((yyval.struct_val_type).typ.structure))->fields[index].name);    
    }
  }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 2088 "axo_gram.y"
    {
    (yyval.struct_val_type)=(yyvsp[(1) - (2)].struct_val_type);
    axo_struct* structure = ((axo_struct*)(yyval.struct_val_type).typ.structure);
    for(int i=0; i<structure->fields_len; i++){
      if((yyval.struct_val_type).fields[i] == NULL) (yyval.struct_val_type).fields[i] = structure->fields[i].def;
    }
  }
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 2097 "axo_gram.y"
    {
    axo_var* fn_var = axo_get_var(state->global_scope, (yyvsp[(1) - (2)].function).name);
    if (fn_var){
      axo_func_typ* fnt = (axo_func_typ*)(fn_var->typ.func_typ);
      if (fnt->ret_typ.kind == axo_no_kind)
        fnt->ret_typ = axo_none_typ;
      (yyval.function) = (axo_func){
        .name = (yyvsp[(1) - (2)].function).name,
        .args_names = (yyvsp[(1) - (2)].function).args_names,
        .f_typ = *fnt,
        .body = (yyvsp[(2) - (2)].scope)
      };
    }else{
      axo_yyerror(NULL, "This should never happen.");
    }
  }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 2115 "axo_gram.y"
    {
    if (axo_none_check((yyvsp[(1) - (2)].typ_type)))
      axo_yyerror(&(yylsp[(1) - (2)]), "Cannot declare a none value.");
    (yyval.function_argument).name = alloc_str((yyvsp[(2) - (2)].str));
    (yyval.function_argument).typ = (yyvsp[(1) - (2)].typ_type);
    (yyval.function_argument).def = alloc_str(axo_get_typ_default((yyvsp[(1) - (2)].typ_type)));
  }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 2122 "axo_gram.y"
    {
    if (axo_none_check((yyvsp[(3) - (3)].expression).typ))
      axo_yyerror(&(yylsp[(3) - (3)]), "Cannot declare a none variable.");
    (yyval.function_argument).name = alloc_str((yyvsp[(1) - (3)].str));
    (yyval.function_argument).typ = (yyvsp[(3) - (3)].expression).typ;
    (yyval.function_argument).def = alloc_str((yyvsp[(3) - (3)].expression).val);
  }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 2129 "axo_gram.y"
    {
    if (axo_none_check((yyvsp[(1) - (4)].typ_type)))
      axo_yyerror(&(yylsp[(1) - (4)]), "Cannot declare a none variable.");
    if (!axo_typ_eq((yyvsp[(1) - (4)].typ_type), (yyvsp[(4) - (4)].expression).typ)){
      char* expected_type_str = alloc_str(axo_typ_to_str((yyvsp[(1) - (4)].typ_type)));
      axo_yyerror(&(yylsp[(4) - (4)]), "Default value of type '%s' doesn't match expected type '%s'.", axo_typ_to_str((yyvsp[(4) - (4)].expression).typ), expected_type_str);
      free(expected_type_str);
    }
    (yyval.function_argument).name = alloc_str((yyvsp[(2) - (4)].str));
    (yyval.function_argument).typ = (yyvsp[(1) - (4)].typ_type);
    (yyval.function_argument).def = alloc_str((yyvsp[(4) - (4)].expression).val);
  }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 2143 "axo_gram.y"
    {
    (yyval.function).args_names = NULL;
    (yyval.function).f_typ.args_defs = NULL;
    (yyval.function).f_typ.args_types = NULL;
    (yyval.function).f_typ.args_len = 0;
  }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 2149 "axo_gram.y"
    {
    (yyval.function).args_names = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_defs = (char**)malloc(axo_func_args_cap*sizeof(char*));
    (yyval.function).f_typ.args_types = (axo_typ*)malloc(axo_func_args_cap*sizeof(axo_typ));
    (yyval.function).args_names[0] = (yyvsp[(1) - (1)].function_argument).name;
    (yyval.function).f_typ.args_defs[0] = (yyvsp[(1) - (1)].function_argument).def;
    (yyval.function).f_typ.args_types[0] = (yyvsp[(1) - (1)].function_argument).typ;
    (yyval.function).f_typ.args_len = 1;
  }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 2158 "axo_gram.y"
    {
    (yyval.function) = (yyvsp[(1) - (3)].function);
    resize_dyn_arr_if_needed(char*, (yyval.function).args_names, (yyval.function).f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(char*, (yyval.function).f_typ.args_defs, (yyval.function).f_typ.args_len, axo_func_args_cap);
    resize_dyn_arr_if_needed(axo_typ, (yyval.function).f_typ.args_types, (yyval.function).f_typ.args_len, axo_func_args_cap);
    (yyval.function).args_names[(yyval.function).f_typ.args_len] = (yyvsp[(3) - (3)].function_argument).name;
    (yyval.function).f_typ.args_defs[(yyval.function).f_typ.args_len] = (yyvsp[(3) - (3)].function_argument).def;
    (yyval.function).f_typ.args_types[(yyval.function).f_typ.args_len] = (yyvsp[(3) - (3)].function_argument).typ;
    (yyval.function).f_typ.args_len++;
  }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 2170 "axo_gram.y"
    {
    (yyval.enum_type).names = (char**)malloc(axo_enum_names_cap*sizeof(char*));
    (yyval.enum_type).names[0] = alloc_str((yyvsp[(1) - (1)].str));
    (yyval.enum_type).len = 1;
  }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 2175 "axo_gram.y"
    {
    (yyval.enum_type) = (yyvsp[(1) - (3)].enum_type);
    if ((yyval.enum_type).len % axo_enum_names_cap == 0)
    (yyval.enum_type).names = (char**)realloc((yyval.enum_type).names, ((yyval.enum_type).len+axo_enum_names_cap)*sizeof(char*));
    (yyval.enum_type).names[(yyval.enum_type).len] = alloc_str((yyvsp[(3) - (3)].str));
    (yyval.enum_type).len++;
  }
    break;


/* Line 1792 of yacc.c  */
#line 5041 "axo_gram.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval, &yylloc, scanner);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 2184 "axo_gram.y"


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


void vyyerror(yyscan_t scanner, YYLTYPE* loc, const char* fmt, va_list args){
  if (prog_return==0)
    axo_err_printf("Click an error to learn more.\n");
  prog_return = 1;
  axo_raise_error;
  if (loc==NULL){
    axo_err_printf(axo_red_fg "Error: ");
    axo_err_vprintf(fmt, args);
    printf(axo_reset_style"\n");
  }else{
    char* msg = NULL;
    if (vasprintf(&msg, fmt, args) < 0)
      axo_err_printf("Couldn't use vsprintf at %s:%d", __FILE__, __LINE__);
    #ifdef __EMSCRIPTEN__
      axo_err_printf("error: %s\n", msg);
      return;
    #endif
    char* err_msg = axo_error_with_loc(state, loc, msg);
    axo_err_printf("%s\n", err_msg);
    free(err_msg);
  }
}

void axo_yyerror(YYLTYPE* loc, const char * fmt, ...){
  va_list args;
  va_start(args, fmt);
  vyyerror(state->scanner, loc, fmt, args);
  va_end(args);
}

void yyerror(yyscan_t scanner, YYLTYPE* loc, const char * fmt, ...){
    va_list args;
    va_start(args, fmt);
    vyyerror(scanner, loc, fmt, args);
    va_end(args);
}

int compile(int argc, char** argv) {
  //Seed the pseudo random number generator
  srand(time(NULL));
  //Start timing the event
  clock_t start, end;
  double cpu_time_used;
  if (test_playground) return playground();
  
  //Get the root path (the path where the axo compiler lays)
  char full_exec_path[1024] = "";
  char root_p[1024] = "";
  axo_get_parent_dir(root_p, axo_get_exec_path(full_exec_path, sizeof(full_exec_path)));
  // printf("Root: %s\n", root_p);
  //Initialize state
  state = axo_new_state(root_p);
  axo_test_lua(state);
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
    axo_yyerror(NULL, "No input.");
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
        axo_yyerror(NULL, "Cannot take input from string and file.");
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
        axo_yyerror(NULL, "No input.");
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
      axo_yyerror(NULL, "No code provided.\nUsage: axo <source> |options|");
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
    yyparse(state->scanner);
    // axo_printf("Parsing done.\n");
    // char* cde = axo_get_code(state);
    //Check if the entry point is present
    axo_var* var = axo_get_var(top_scope, (strcmp("axo__main", state->entry_point) == 0) ? "main" : state->entry_point);
    if (var == NULL){
      axo_yyerror(NULL, "Entry point function '%s' doesn't exist.", state->entry_point);
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
          axo_yyerror(NULL, "Entry point has to be of type (int fn) or (int fn [][]byte), but is of type '%s'.", axo_typ_to_str(var->typ));
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
            // printf("Compiling command:\n%s\n", compiler_cmd);
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

char* axo_compile_to_c(char* input){
  char** argv = (char**)malloc(3*sizeof(char*));
  argv[0] = alloc_str(".");
  argv[1] = alloc_str("-i");
  argv[2] = alloc_str(input);
  compile(3, argv);
  char* res = axo_get_code(state);
  // printf("Code: %s\n", res);
  return res;
}

