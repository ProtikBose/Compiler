/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1505044_bison.y" /* yacc.c:339  */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include "1505044symbolTable.h"


using namespace std;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
SymbolTable symbltable(13);
string vtype;
extern int line_count;
int errors=0;
int argnum = 0;
vector<string>argvalue;
vector<SymbolInfo>parameter; 
ofstream logout, errorout;

void yyerror(const char *s)
{
	printf("%d --- > %s\n",line_count,s);
}


#line 97 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    CONST_INT = 259,
    CONST_FLOAT = 260,
    CONST_CHAR = 261,
    ADDOP = 262,
    MULOP = 263,
    LOGICOP = 264,
    RELOP = 265,
    COMMENT = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    DO = 271,
    BREAK = 272,
    CONTINUE = 273,
    INT = 274,
    FLOAT = 275,
    CHAR = 276,
    DOUBLE = 277,
    VOID = 278,
    RETURN = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    INCOP = 283,
    DECOP = 284,
    ASSIGNOP = 285,
    LPAREN = 286,
    RPAREN = 287,
    LCURL = 288,
    RCURL = 289,
    LTHIRD = 290,
    RTHIRD = 291,
    SEMICOLON = 292,
    COMMA = 293,
    STRING = 294,
    NOT = 295,
    PRINTLN = 296,
    BITOP = 297,
    second_precedence = 298
  };
#endif
/* Tokens.  */
#define ID 258
#define CONST_INT 259
#define CONST_FLOAT 260
#define CONST_CHAR 261
#define ADDOP 262
#define MULOP 263
#define LOGICOP 264
#define RELOP 265
#define COMMENT 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define DO 271
#define BREAK 272
#define CONTINUE 273
#define INT 274
#define FLOAT 275
#define CHAR 276
#define DOUBLE 277
#define VOID 278
#define RETURN 279
#define SWITCH 280
#define CASE 281
#define DEFAULT 282
#define INCOP 283
#define DECOP 284
#define ASSIGNOP 285
#define LPAREN 286
#define RPAREN 287
#define LCURL 288
#define RCURL 289
#define LTHIRD 290
#define RTHIRD 291
#define SEMICOLON 292
#define COMMA 293
#define STRING 294
#define NOT 295
#define PRINTLN 296
#define BITOP 297
#define second_precedence 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "1505044_bison.y" /* yacc.c:355  */

SymbolInfo* symbolVal;

#line 227 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    60,    65,    71,    76,    81,    87,   110,
     116,   187,   204,   209,   224,   230,   235,   239,   242,   234,
     246,   253,   258,   265,   272,   279,   286,   316,   364,   391,
     422,   426,   432,   436,   440,   444,   448,   452,   456,   460,
     464,   469,   473,   481,   485,   489,   496,   513,   561,   573,
     682,   694,   831,   845,  1042,  1054,  1502,  1514,  2152,  2182,
    2226,  2240,  2244,  2286,  2291,  2307,  2323,  2362,  2403,  2407,
    2410,  2414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP", "COMMENT", "IF",
  "ELSE", "FOR", "WHILE", "DO", "BREAK", "CONTINUE", "INT", "FLOAT",
  "CHAR", "DOUBLE", "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT", "INCOP",
  "DECOP", "ASSIGNOP", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD",
  "RTHIRD", "SEMICOLON", "COMMA", "STRING", "NOT", "PRINTLN", "BITOP",
  "second_precedence", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "$@2", "$@3", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -64,   -64,   -64,    12,    16,   -64,   -64,   -64,   -64,
       4,   -64,   -64,   -11,     0,    16,    29,   -64,   -64,    48,
      -9,    50,    42,    23,     7,    16,   -64,   -64,    75,   -64,
      53,   -64,   -64,    86,    60,   -64,    57,   -64,   -64,    28,
     -64,   -64,    10,    68,    69,    71,    10,    10,   -64,    10,
      72,   -64,   -64,    98,    57,   -64,   -64,    63,    15,   -64,
      95,    24,    97,   -64,   -64,    10,    10,    45,   -64,    10,
      79,    10,    18,    74,   -64,   104,    73,    77,   -64,   -64,
     -64,    10,   -64,   -64,    10,    10,    10,    10,   -64,    80,
      76,    81,    83,    79,    88,   -64,   -64,   -64,    89,   -64,
     -64,   -64,    97,   102,   -64,   -64,    10,   -64,    57,    10,
      57,    20,   -64,   -64,   100,    90,   -64,   -64,   -64,    57,
      57,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,    15,     0,    22,    21,     0,
       0,    14,     0,    26,     0,     0,    13,    29,     0,     9,
      16,     8,    10,    12,     0,    20,     0,    11,    27,    46,
      64,    65,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    34,    32,     0,    17,    30,    33,    61,     0,    48,
      50,    52,    54,    56,    60,    69,     0,    61,    58,     0,
       0,     0,     0,     0,    59,     0,    28,     0,    31,    66,
      67,     0,    45,    44,     0,     0,     0,     0,    71,     0,
      68,     0,     0,     0,     0,    42,    41,    63,     0,    18,
      49,    51,    55,    53,    57,    62,     0,    47,     0,     0,
       0,     0,    19,    70,    36,     0,    38,    40,    39,     0,
       0,    37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   113,   -64,   -64,   -64,    99,   -64,   -64,
     -64,    22,    70,   -64,   -64,   -54,   -61,   -39,   -41,   -63,
      40,    39,    41,   -38,   -64,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    51,    36,    77,
     112,    52,    53,    14,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,    17,    88,    67,    68,    72,    73,    13,    29,    93,
      67,    74,    11,    39,    40,    41,    82,    42,   100,    95,
      15,   117,     9,    24,    16,    91,    67,     9,    92,    25,
      94,    85,   109,    22,    86,     1,     2,    18,    19,     3,
      30,    47,    67,   113,    31,    67,    67,    67,    67,   104,
      49,    23,    83,    26,   114,    96,   116,   118,    28,    65,
      39,    40,    41,    66,    42,   121,   122,    67,   115,    43,
      10,    44,    45,    79,    80,    10,     1,     2,    27,    34,
       3,    46,    39,    40,    41,    21,    42,    35,    47,    37,
      30,    79,    80,    81,    48,    33,    38,    49,    50,    69,
      70,    76,    71,    75,    84,    87,    97,    98,    16,    85,
      47,    99,   105,   119,   106,   108,    48,   107,    12,    49,
     110,   111,   120,    32,   101,   103,   102
};

static const yytype_uint8 yycheck[] =
{
      54,     1,    65,    42,    42,    46,    47,     3,     1,    70,
      49,    49,     0,     3,     4,     5,     1,     7,    81,     1,
      31,     1,     0,    32,    35,    66,    65,     5,    69,    38,
      71,     7,    93,     4,    10,    19,    20,    37,    38,    23,
      33,    31,    81,   106,    37,    84,    85,    86,    87,    87,
      40,     3,    37,     3,   108,    37,   110,    37,    35,    31,
       3,     4,     5,    35,     7,   119,   120,   106,   109,    12,
       0,    14,    15,    28,    29,     5,    19,    20,    36,     4,
      23,    24,     3,     4,     5,    15,     7,    34,    31,     3,
      33,    28,    29,    30,    37,    25,    36,    40,    41,    31,
      31,     3,    31,    31,     9,     8,    32,     3,    35,     7,
      31,    34,    32,    13,    38,    32,    37,    36,     5,    40,
      32,    32,    32,    24,    84,    86,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    20,    23,    45,    46,    47,    48,    49,    55,
      56,     0,    47,     3,    57,    31,    35,     1,    37,    38,
      50,    56,     4,     3,    32,    38,     3,    36,    35,     1,
      33,    37,    51,    56,     4,    34,    52,     3,    36,     3,
       4,     5,     7,    12,    14,    15,    24,    31,    37,    40,
      41,    51,    55,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    31,    35,    61,    67,    31,
      31,    31,    62,    62,    67,    31,     3,    53,    59,    28,
      29,    30,     1,    37,     9,     7,    10,     8,    63,    69,
      70,    62,    62,    60,    62,     1,    37,    32,     3,    34,
      63,    64,    66,    65,    67,    32,    38,    36,    32,    60,
      32,    32,    54,    63,    59,    62,    59,     1,    37,    13,
      32,    59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    50,    50,    50,    50,    50,    52,    53,    54,    51,
      51,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       6,     4,     3,     2,     1,     0,     0,     0,     0,     6,
       2,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       5,     3,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 54 "1505044_bison.y" /* yacc.c:1646  */
    { 

			logout<<"At line "<<line_count<<" : start : program\n"<< endl;
		}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : program : program unit\n"<< endl;
		}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : program : unit\n"<< endl;
		}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" unit : var_declaration\n"<< endl;	
		}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "1505044_bison.y" /* yacc.c:1646  */
    {	
			logout<<"At line "<<line_count<<" unit : func_declaration\n"<< endl;
		}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" unit : func_definition\n"<< endl;
		}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At Line "<<line_count<<" : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						logout<<(yyvsp[-4].symbolVal)->getValue()<<endl;
						SymbolInfo *tempval=symbltable.lookTable((yyvsp[-4].symbolVal)->getValue(),"FUNC");
						if(tempval!=NULL)
						{
							errorout<<"Error at line "<<line_count<<" Function "<<(yyvsp[-4].symbolVal)->getValue()<<" already declared" << endl;
							errors++;
	
						}
						else
						{
							SymbolInfo* tempval2=symbltable.finalInsert((yyvsp[-4].symbolVal)->getValue(),"ID");
							tempval2->setkeyType("FUNC");
							tempval2->setFuncRet((yyvsp[-5].symbolVal)->getReturnType());
							for(int i = 0; i<argvalue.size(); i++){
								tempval2->pList.push_back(argvalue[i]);					
							}
							argvalue.clear();
						}
						//funcParam.exitScope();
					}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "1505044_bison.y" /* yacc.c:1646  */
    {
						errorout<<"Error at line "<<line_count<<" ; missing"<<endl;
						errors++;
					}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At Line "<<line_count<<" : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<<endl;
					logout<<(yyvsp[-4].symbolVal)->getValue()<<endl;
					SymbolInfo *tempval=symbltable.lookTable((yyvsp[-4].symbolVal)->getValue(),"FUNC");
					if(argvalue.size()!=argnum)
					{
						errorout<<"Error at line "<<line_count<<" Parameter mismatch for Function "<<(yyvsp[-4].symbolVal)->getValue()<< endl;
						argvalue.clear();
						argnum=0;
						errors++;
					}												
					if(tempval!=NULL)
					{
					//logFile << "Function " << $2->getValue() <<" already declared" << endl;
						if(tempval->isFuncDefined()==true)
						{
							errorout<<"Error at line "<<line_count<<"Function "<< (yyvsp[-4].symbolVal)->getValue()<<" already defined" << endl;
							errors++;
							argvalue.clear();
							argnum=0;
						}
						else if(tempval->getFuncRet()!=(yyvsp[-5].symbolVal)->getReturnType())
						{
							errorout<<"Error at line "<<line_count<<"Function "<<(yyvsp[-4].symbolVal)->getValue()<<" :return type doesn't match declaration"<<endl;
							errors++;
							argvalue.clear();
							argnum=0; 
						} 
						else if(tempval->pList.size()!=argvalue.size())
						{
							errorout<<"Error at line "<<line_count<<"Function "<<(yyvsp[-4].symbolVal)->getValue()<<" :Parameter list doesn not match declaration"<<endl;
							errors++;
							argvalue.clear();
							argnum=0;					
						}
						else
						{
							for(int i=0;i<tempval->pList.size();i++)
							{
								if(tempval->pList[i]!=argvalue[i])
								{
									errorout<<"Error at line "<<line_count<<"Function "<< (yyvsp[-4].symbolVal)->getValue()<< " :argument mismatch"<<endl;
									errors++;
									argvalue.clear();
									argnum=0;	
								}
							}				
						}
					}
					else
					{
						SymbolInfo* tempval=new SymbolInfo();
						tempval=symbltable.finalInsert((yyvsp[-4].symbolVal)->getValue(),"ID");
						//logFile << $2->getValue() << " Function inserted" << endl;
						tempval->setkeyType("FUNC");
						tempval->setFuncRet((yyvsp[-5].symbolVal)->getReturnType());
					//
						for(int i=0;i<argvalue.size(); i++){
						tempval->pList.push_back(argvalue[i]);					
					}
					tempval->setFuncDefined();
				}
				argvalue.clear();
				argnum=0;
				
	
				//funcParam.exitScope();
				}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 188 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At Line "<<line_count<<" : parameter_list  : parameter_list COMMA type_specifier ID\n";
					logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
					argvalue.push_back(vtype);//changed from $3->getReturnType()
					argnum++;
					//SymbolInfo* temp = funcParam.finalInsert($4->getValue(), $4->getKeyword());					
					//temp->setkeyType("VAR");
					//temp->setReturnType($3->getReturnType());
					(yyvsp[0].symbolVal)->setkeyType("VAR");
					(yyvsp[0].symbolVal)->setReturnType(vtype);//changed from $3->getReturnType()
					SymbolInfo* tempval=new SymbolInfo((yyvsp[0].symbolVal)->getValue(),(yyvsp[0].symbolVal)->getKeyword());
					tempval->setkeyType("VAR");
					
					parameter.push_back(*tempval);
				
				}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "1505044_bison.y" /* yacc.c:1646  */
    {					
					logout<<"At Line "<<line_count<<" : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					argvalue.push_back((yyvsp[0].symbolVal)->getReturnType());
				}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At Line "<<line_count<<" : parameter_list  : type_specifier ID\n";
					logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
					//args.clear();
					argvalue.push_back(vtype);//$1->getReturnType()
					argnum++;
					//SymbolInfo* temp = funcParam.finalInsert($2->getValue(), $2->getKeyword());
					//temp->setkeyType("VAR");
					//temp->setReturnType($1->getReturnType());
					(yyvsp[0].symbolVal)->setkeyType("VAR");
					(yyvsp[0].symbolVal)->setReturnType(vtype);//$1->getReturnType()
					parameter.push_back(*(yyvsp[0].symbolVal));
				
				}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 225 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At Line "<<line_count<<" : parameter_list  : type_specifier\n"<< endl;
					//args.clear();
					argvalue.push_back(vtype);
				}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 230 "1505044_bison.y" /* yacc.c:1646  */
    {//logFile << "Empty parameter " << lCount << endl;
				}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 235 "1505044_bison.y" /* yacc.c:1646  */
    {	symbltable.enterScope();
				for(int i=0;i<parameter.size();i++) 
					symbltable.insertTable(parameter[i]);
				parameter.clear();
			}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 239 "1505044_bison.y" /* yacc.c:1646  */
    {
				symbltable.printAllTable(logout);
			}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "1505044_bison.y" /* yacc.c:1646  */
    {
				symbltable.exitScope();	
			}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 244 "1505044_bison.y" /* yacc.c:1646  */
    { logout<<"At line "<<line_count<< " : compound_statement : LCURL statements RCURL\n"<< endl; }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "1505044_bison.y" /* yacc.c:1646  */
    { 
				logout<<"At line "<<line_count<< " : compound_statement : LCURL RCURL\n"<< endl; 
			}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 254 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
				
			}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "1505044_bison.y" /* yacc.c:1646  */
    {
				errorout<<"Error at line "<<line_count<<" ';' missing " <<endl;
				errors++;
			}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 265 "1505044_bison.y" /* yacc.c:1646  */
    { 	logout<<"At line "<<line_count<< " : type_specifier : INT\n"<< endl;
			SymbolInfo* str=new SymbolInfo("INT");
			vtype="INT";
			(yyval.symbolVal)=str;

			}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "1505044_bison.y" /* yacc.c:1646  */
    { logout<<"At line "<<line_count<< " : type_specifier : FLOAT\n"<< endl;
			SymbolInfo* str=new SymbolInfo("FLOAT");
			vtype="FLOAT";
			(yyval.symbolVal)=str;

			}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 279 "1505044_bison.y" /* yacc.c:1646  */
    {  logout<<"At line "<<line_count<< " : type_specifier : VOID\n"<< endl;
			SymbolInfo* str=new SymbolInfo("VOID");
			vtype="VOID";
			(yyval.symbolVal)=str;
		}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 287 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At Line "<<line_count<<" : declaration_list : 	declaration_list COMMA ID\n";
						logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :variable type can't be void" << endl;
							errors++;
						}
						else
						{
							SymbolInfo* tempval=symbltable.lookTable((yyvsp[0].symbolVal)->getValue(),"VAR");
							if(tempval!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Variable "<<(yyvsp[0].symbolVal)->getValue()<<" already declared"<<endl;	
								errors++;	
							}
							else
							{
								//SymbolInfo* tempval2 = symbltable.finalInsert($3->getValue(), $3->getKeyword());
								//tempval2->setReturnType(vtype);
								//tempval2->setkeyType("VAR");
								SymbolInfo* tempval2=new SymbolInfo((yyvsp[0].symbolVal)->getValue(),(yyvsp[0].symbolVal)->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("VAR");
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);
							}
						}
					}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 317 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At Line "<<line_count<<" : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						logout<<(yyvsp[-3].symbolVal)->getValue()<<endl;
						logout<<(yyvsp[-1].symbolVal)->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" : array type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* tempval=symbltable.lookTable((yyvsp[-3].symbolVal)->getValue(),"ARA");
							if(tempval!=NULL)
							{
								errorout<<"Error at line "<<line_count<<" : Array "<<(yyvsp[-3].symbolVal)->getValue()<< " already declared"<<endl;
								errors++;			
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo((yyvsp[-3].symbolVal)->getValue(),(yyvsp[-3].symbolVal)->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("ARA");
								int araSize=atoi(((yyvsp[-1].symbolVal)->getValue()).c_str());
								tempval2->setAraLength(araSize);
								if(vtype=="INT")			  {								
									for(int i=tempval2->intstore.size();i<araSize;i++)
									{
										tempval2->intstore.push_back(0);
									}							
								}
								else if(vtype=="FLOAT")	{								
									for(int i=tempval2->floatstore.size();i<araSize;i++)
									{
										tempval2->floatstore.push_back(0);
									}							
								}
								else if(vtype=="CHAR"){								
									for(int i=tempval2->charstore.size();i<araSize;i++){
										tempval2->charstore.push_back('\0');
									}							
								}
								symbltable.insertTable(*tempval2);						
								//symbltable.printAllTable(logFile);
							}
						}

					}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 365 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At Line "<<line_count<<" : declaration_list :	ID\n";
						logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :variable type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* temp=symbltable.lookTable((yyvsp[0].symbolVal)->getValue(), "ARA");
							if(temp!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Variable "<< (yyvsp[0].symbolVal)->getValue() <<" already declared"<<endl;	
								errors++;		
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo((yyvsp[0].symbolVal)->getValue(),(yyvsp[0].symbolVal)->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("VAR");
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);		
							}
						}
					}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 392 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At Line "<<line_count<<" : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						logout<<(yyvsp[-3].symbolVal)->getValue()<<endl;
						logout<<(yyvsp[-1].symbolVal)->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :array type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* temp=symbltable.lookTable((yyvsp[-3].symbolVal)->getValue(),"ARA");
							if(temp!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Array "<<(yyvsp[-3].symbolVal)->getValue()<<" already declared"<<endl;	
								errors++;
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo((yyvsp[-3].symbolVal)->getValue(),(yyvsp[-3].symbolVal)->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("ARA");
								int araSize=atoi(((yyvsp[-1].symbolVal)->getValue()).c_str());
								tempval2->setAraLength(araSize);
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);			
							}
						}
					}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "1505044_bison.y" /* yacc.c:1646  */
    {	
			logout<<"At line "<<line_count<< " : statements : statement\n"<< endl;
		}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 427 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statements : statements statement\n"<< endl;
		}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 433 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : var_declaration\n"<< endl;
		}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 437 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : expression_statement\n"<< endl;
		}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 441 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : compound_statement\n"<< endl;
		}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 445 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
		}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 449 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
		}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 453 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
		}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 457 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
		}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 461 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
		}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 465 "1505044_bison.y" /* yacc.c:1646  */
    {
			errorout<<" Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 470 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : RETURN expression SEMICOLON\n"<< endl;
		}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 474 "1505044_bison.y" /* yacc.c:1646  */
    {
			errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 482 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At line "<<line_count<< " : expression_statement 	: SEMICOLON\n"<< endl;	
				}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 486 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At line "<<line_count<< " : expression_statement 	: expression SEMICOLON\n"<< endl;
				}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 490 "1505044_bison.y" /* yacc.c:1646  */
    {
					errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
					errors++;
				}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 497 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At Line "<<line_count<<" : variable : ID\n";
				logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
				SymbolInfo* tempval=symbltable.lookTable((yyvsp[0].symbolVal)->getValue(),"VAR");
				if(tempval==NULL)
				{
					//logFile << "Variable " << $1->getValue() << " doesn't exist" << endl;
					errorout<<"Error at line "<<line_count<<" : "<<(yyvsp[0].symbolVal)->getValue()<<" doesn't exist"<< endl;					
					errors++;
				}
				else
				{
					(yyval.symbolVal)=tempval;
					//vtype = temp->getReturnType();
				}			
			}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 514 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"Line "<<line_count<<" : variable : ID LTHIRD expression RTHIRD\n";
				logout<<(yyvsp[-3].symbolVal)->getValue()<<endl;
				SymbolInfo* tempval=symbltable.lookTable((yyvsp[-3].symbolVal)->getValue(),"ARA");
				if(tempval==NULL)
				{
					errorout<<"Error at line "<<line_count<<" : " <<(yyvsp[-3].symbolVal)->getValue()<<" doesn't exist"<< endl;					
					errors++;				
				}
				else
				{
					//$$ = temp;
					if((yyvsp[-1].symbolVal)->intstore[0]>=tempval->getAralength())
					{
						errorout<<"Error at line "<<line_count<<" : " <<(yyvsp[-3].symbolVal)->getValue()<<" array index out of bounds"<<  endl;				
						errors++;
						//temp->setAraIndex(0);
					} 
					else 
						tempval->setAraIndex((yyvsp[-1].symbolVal)->intstore[0]);
					if(tempval->getReturnType()=="INT")
					{
						while(tempval->intstore.size()<=tempval->getAraIndex())
						{
							tempval->intstore.push_back(0);
						}
					}
					else if(tempval->getReturnType()=="FLOAT")
					{
						while(tempval->floatstore.size()<=tempval->getAraIndex())
						{
							tempval->floatstore.push_back(0);
						}
					}
					else if(tempval->getReturnType()=="CHAR")
					{
						while(tempval->charstore.size()<=tempval->getAraIndex())
						{
							tempval->charstore.push_back('\0');
						}
					}
					(yyval.symbolVal)=tempval;
					//vtype = temp->getReturnType();
				}			
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 562 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : expression : logic_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			(yyval.symbolVal)->intstore.push_back(0); //if the term is int
			(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
			//considering it both
			// for next term semantic check
		}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 574 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : expression : variable ASSIGNOP logic_expression\n"<< endl;
			//semantic check
			string st=(yyvsp[-2].symbolVal)->getReturnType();

			//checking the variable type with the help of keyword
			if(st=="INT")
			{
				// varaible or array 
				if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
				{
					(yyvsp[-2].symbolVal)->intstore.push_back(0);

					//checking the logical_expression keyword
					if((yyvsp[0].symbolVal)->getReturnType()=="INT")
					{
					
					}
					//logical expression isn't int
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning float value to integer"<<endl;
						//semantic correction
						//making the float value into int
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")  //logical expression is varaible
							(yyvsp[-2].symbolVal)->intstore[0]=(int)(yyvsp[0].symbolVal)->floatstore[0];
						//logical expression is array
						else 
							(yyvsp[-2].symbolVal)->intstore[0]=(int)(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
					}
				}
				//the $1 variable is array
				else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
				{
					(yyvsp[-2].symbolVal)->intstore.push_back(0);
					//checking the logical_expression keyword  
					if((yyvsp[0].symbolVal)->getReturnType()=="INT")
					{
					
					}
					//logical expression isn't int
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning float value to integer"<<endl;
						//semantic correction
						//making the float value into int
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")  //logical expression is varaible
							(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]=(int)(yyvsp[0].symbolVal)->floatstore[0];
						//logical expression is array
						else 
							(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]=(int)(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
					}
				}
			}
			
			else if(st=="FLOAT")
			{
				// varaible or array
				if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
				{
					(yyvsp[-2].symbolVal)->floatstore.push_back(0);
					//checking the logical_expression keyword
					if((yyvsp[0].symbolVal)->getReturnType()=="INT")
					{
						errorout<<"Error at line " <<line_count<<" : Assigning integer value to float"<<endl;
						//semantic correction
						//making the int value into float
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR") //logical expression is varaible
							(yyvsp[-2].symbolVal)->floatstore[0]=(float)(yyvsp[0].symbolVal)->intstore[0];
						//logical expression is array
						else 
							(yyvsp[-2].symbolVal)->floatstore[0]=(float)(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
					}
					else
					{
						
					}
				
				}
				else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
				{
					(yyvsp[-2].symbolVal)->floatstore.push_back(0);
					//if the logical_expression is variable
					if((yyvsp[0].symbolVal)->getReturnType()=="INT")
					{
					
					}
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning integer value to float"<<endl;
						//semantic correction
						//making the int value into float
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()] = (yyvsp[0].symbolVal)->floatstore[0]; //logical expression is varaible
						//logical expression is array
						else 
							(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()] = (yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
					}
				}
			}
			//storing semantic value
			(yyval.symbolVal) = (yyvsp[-2].symbolVal);
			//printing the value	
			symbltable.printAllTable(logout);	
			
		}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 683 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				(yyval.symbolVal)->intstore.push_back(0); //if the term is int
				(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 695 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
				//ultimate value of this expression will be 0 or 1
				//going to take an object with int keyword
				
				SymbolInfo* tempval=new SymbolInfo("INT");

				//if $1 or $3 is character keyword , then there will be no logical operation
				if((yyvsp[-2].symbolVal)->getReturnType()=="CHAR"||(yyvsp[0].symbolVal)->getReturnType()=="CHAR")
				{
					//errorout<<"Error at line " <<line_count<<" : invalid keyword"<<endl;
					tempval->intstore.push_back(0);
				}
				string st=(yyvsp[-1].symbolVal)->getValue(); 
				//if the LOGICOP is &&
				if(st=="&&")
				{
					//if the term is float keyword
					if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
					{
						(yyvsp[-2].symbolVal)->floatstore.push_back(0); //indicating float varaible
						//if any term is 0, then the ans will be 0
						if((yyvsp[-2].symbolVal)->floatstore[0]==0)
						{
							tempval->intstore[0]=0; //	answer is zero							
						}
						//if the second term is float, then this term will be added to float array 
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							(yyvsp[0].symbolVal)->floatstore.push_back(0); //added
							if((yyvsp[0].symbolVal)->floatstore[0]==0)  // the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
						//if the second term is int, then this term will be added to int array 
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT")
						{
							(yyvsp[0].symbolVal)->intstore.push_back(0); //added 
							if((yyvsp[0].symbolVal)->intstore[0]==0)   //the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
					}
					//if the term is int keyword
					else if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
					{
						(yyvsp[-2].symbolVal)->intstore.push_back(0); //indicating int variable
						//if any term is 0, then the ans will be 0
						if((yyvsp[-2].symbolVal)->intstore[0]==0) 
							tempval->intstore[0]=0; //	answer is zero
						//if the second term is float, then this term will be added to float array
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							(yyvsp[0].symbolVal)->floatstore.push_back(0); //added
							if((yyvsp[0].symbolVal)->floatstore[0]==0) // the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
						//if the second term is int, then this term will be added to int array 
						else if((yyvsp[0].symbolVal)->getReturnType() == "INT")
						{
							(yyvsp[0].symbolVal)->intstore.push_back(0); //added 
							if((yyvsp[0].symbolVal)->intstore[0]==0) //the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
					}
				}
				//if the LOGICOP is ||
				else if(st=="||")
				{
					//if the term is float keyword
					if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
					{
						(yyvsp[-2].symbolVal)->floatstore.push_back(0); //indicating float varaible
						//if both term is 0, then the ans will be 1
						if((yyvsp[-2].symbolVal)->floatstore[0]!=0)
						{
							tempval->intstore[0]=1; //	answer is one							
						}
						//if the second term is float, then this term will be added to float array
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							(yyvsp[0].symbolVal)->floatstore.push_back(0); //added
							if((yyvsp[0].symbolVal)->floatstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0]=0; //otherwise the term will be zero
						}
						//if the second term is int, then this term will be added to int array 
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT")
						{
							(yyvsp[0].symbolVal)->intstore.push_back(0); //added
							if((yyvsp[0].symbolVal)->intstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0] =0; //otherwise the term will be zero
						}
					}
					//if the term is int keyword
					else if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
					{
						(yyvsp[-2].symbolVal)->intstore.push_back(0); //indicating float varaible
						//if both term is 0, then the ans will be 1
						if((yyvsp[-2].symbolVal)->intstore[0]!=0) 
							tempval->intstore[0]=1; //	answer is one
						//if the second term is float, then this term will be added to float array
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							(yyvsp[0].symbolVal)->floatstore.push_back(0); //added 									
							if((yyvsp[0].symbolVal)->floatstore[0]!=0) //the term is one
								 tempval->intstore[0]=1;
							else 
								tempval->intstore[0] =0; //otherwise the term will be zero
						}
						//if the second term is int, then this term will be added to int array
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT")
						{
							(yyvsp[0].symbolVal)->intstore.push_back(0); //added
							if((yyvsp[0].symbolVal)->intstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0]=0; //otherwise the term will be zero
						}
					}
				}
				//storing the semantic value
				(yyval.symbolVal)=tempval;
				
			}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 832 "1505044_bison.y" /* yacc.c:1646  */
    {
				
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				(yyval.symbolVal)->intstore.push_back(0); //if the term is int
				(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			
			}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 846 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : simple_expression RELOP simple_expression\n"<< endl;
				//the ultimate result will be 0 or 1, that's why it's kept as int varaible
				SymbolInfo* tempval=new SymbolInfo("INT");
				string st=(yyvsp[-1].symbolVal)->getValue(); //the relop sign
				string var1=(yyvsp[-2].symbolVal)->getReturnType(); //getting the first simp.expression keyword
				string var2=(yyvsp[0].symbolVal)->getReturnType(); //getting the second simp.expression keyword
				//if the RELOP is ==
				if(st=="==")
				{
					if(var1!=var2) //this doesn't occur error 
					{
						//errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					else if(var1=="INT") //the first term is of int keyword
					{
						//both term is equal, so the result will be one
						if((yyvsp[-2].symbolVal)->intstore[0]==(yyvsp[0].symbolVal)->intstore[0]) 
							tempval->intstore[0]=1;  //result added
						else
							tempval->intstore[0]=0;  //otherwise result will be zero
					}
					//the first term is of float keyword
					else if(var1=="FLOAT")
					{
						//both term is equal, so the result will be one
						if((yyvsp[-2].symbolVal)->floatstore[0]==(yyvsp[0].symbolVal)->floatstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero		
					}
					//the first term is of character keyword
					else if(var1=="CHAR")
					{
						//both term is equal, so the result will be one
						if((yyvsp[-2].symbolVal)->charstore[0]==(yyvsp[0].symbolVal)->charstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero		
					}
				}
				//if the RELOP is !=
				else if(st=="!=")
				{
					if(var1!=var2) //this doesn't occur error
					{
						//errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					else if(var1=="INT") //the first term is of int keyword
					{
						//both term is not equal, so the result will be one
						if((yyvsp[-2].symbolVal)->intstore[0]!=(yyvsp[0].symbolVal)->intstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero
					}
					//the first term is of float keyword
					else if(var1=="FLOAT")
					{
						//both term is not equal, so the result will be one
						if((yyvsp[-2].symbolVal)->floatstore[0]!=(yyvsp[0].symbolVal)->floatstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero	
					}
					//the first term is of char keyword
					else if(var1=="CHAR")
					{
						//both term is not equal, so the result will be one
						if((yyvsp[-2].symbolVal)->charstore[0]!=(yyvsp[0].symbolVal)->charstore[0])
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero	
					}
				}
				//if the RELOP is <= or <
				//both term isn't required to be same keyword
				else if(st=="<="||st=="<")
				{
					if(var1=="INT") //the first term is int keyword
					{
						if(var2=="INT") //the second one is also int keyword
						{
							if((yyvsp[-2].symbolVal)->intstore[0]<(yyvsp[0].symbolVal)->intstore[0]) // less than
								tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->intstore[0]==(yyvsp[0].symbolVal)->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								tempval->intstore[0]=0; //greater than
						}
						//second term is float keyword
						else if(var2=="FLOAT")
						{
							if((yyvsp[-2].symbolVal)->intstore[0]<(yyvsp[0].symbolVal)->floatstore[0]) //less than
								 tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->intstore[0]==(yyvsp[0].symbolVal)->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //greater than
						}
					}
					//the first term is float
					else if(var1=="FLOAT")
					{
						if(var2=="INT")  //the second term is int keyword
						{
							if((yyvsp[-2].symbolVal)->floatstore[0]<(yyvsp[0].symbolVal)->intstore[0]) //less than
								 tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->floatstore[0]==(yyvsp[0].symbolVal)->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0;	//greater than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							if((yyvsp[-2].symbolVal)->floatstore[0]<(yyvsp[0].symbolVal)->floatstore[0]) //less than
								 tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->floatstore[0]==(yyvsp[0].symbolVal)->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //greater than
						}
					}
					//the first term is character keyword
					else if(var1=="CHAR")
					{
					}

				}
				//if the relop is >= or >
				//true for both type of keywords
				else if(st==">="||st==">")
				{
					if(var1=="INT") //the first term is int keyword
					{
						if(var2=="INT") //the second term is int keyword
						{
							if((yyvsp[-2].symbolVal)->intstore[0]>(yyvsp[0].symbolVal)->intstore[0]) //greater than
						        	tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->intstore[0]==(yyvsp[0].symbolVal)->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							//greater than
							if((yyvsp[-2].symbolVal)->intstore[0]>(yyvsp[0].symbolVal)->floatstore[0])
								 tempval->intstore[0]=1;
							//equal
							else if((yyvsp[-2].symbolVal)->intstore[0]==(yyvsp[0].symbolVal)->floatstore[0])
								 tempval->intstore[0]=1;
							//less than
							else
								 tempval->intstore[0]=0;
						}
					}
					//the first term is float keyword
					else if(var1=="FLOAT")
					{
						if(var2=="INT") //the second term is int keyword
						{
							if((yyvsp[-2].symbolVal)->floatstore[0]>(yyvsp[0].symbolVal)->intstore[0]) //greater than
								 tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->floatstore[0]==(yyvsp[0].symbolVal)->intstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							if((yyvsp[-2].symbolVal)->floatstore[0]>(yyvsp[0].symbolVal)->floatstore[0]) //greater than
								 tempval->intstore[0]=1;
							else if((yyvsp[-2].symbolVal)->floatstore[0]==(yyvsp[0].symbolVal)->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
					}
					//the first term is character keyword
					else if(var1=="CHAR")
					{
					}

				}
				//stored in semantic value
				(yyval.symbolVal)=tempval;
				
			}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1043 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : simple_expression : term\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				(yyval.symbolVal)->intstore.push_back(0); //if the term is int
				(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1055 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : simple_expression : simple_expression ADDOP term\n"<< endl;
				//ADDOP is '+'
				if((yyvsp[-1].symbolVal)->getValue()=="+")
				{
					//variable or array
					//at first, it may be variable
					if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
					{
						//second term is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{	
							//if the first term is float, then the answer will be float					
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept as a float number
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int keyword
								// a float and an int keyword is being added
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->intstore[0];							
								}
								//the second term is float keyword
								//a float and a float keyword value is being added
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate value is being stored 
								(yyval.symbolVal)=tempval;
							}
							//if the second term is float, then the answer will be float					
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept as a float number
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int keyword
								// a float and an int keyword is being added
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]+(yyvsp[0].symbolVal)->floatstore[0];							
								}
								//the first term is float keyword
								// a float and a float keyword is being added
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate value is being stored 
								(yyval.symbolVal)=tempval;
							}
							//if both values is int keyword
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								//the result will be int
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]+(yyvsp[0].symbolVal)->intstore[0];
								(yyval.symbolVal)=tempval; //value is stored 
							}
						}
						//second term is an array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{	
							//if the first term is float, then the answer will be					
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the ultimate result will be float
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//second term is int keyword
								//an int and a float will make a float value as result
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];							
								}
								//second term is float keyword
								//a float and a float will make a float value as result 
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
							//if the second term is float, then the answer will be
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the ultimate result will be float
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//first term is int keyword
								//an int and a float will make a float value as result
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];							
								}
								//first term is float keyword
								//a float and a float will make a float value as result
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
							//both terms is int keyword
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								//the answer will be int
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]+(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
						}
					}
					// if it is an array
					else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
					{
						//second term is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{			
							//the first term is float
							//the answer will be float			
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								//answer is kept in float
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->intstore[0];							
								}
								//the second value is int
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
							//the second term is float
							//the answer will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								//the answer is kept in float
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[0];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
							//both terms is int
							//the answer will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->intstore[0];
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
						}
						//if the second term is an array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{		
							//the first term is float
							//the answer will be float				
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								//the answer is kept in float
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
							//the second term is float
							//the answer will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								//the answer is kept in float
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the first term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
							//both terms is int
							//the answer will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]+(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//the ultimate answer is stored
								(yyval.symbolVal)=tempval;
							}
						}
					}
				}
				//ADDOP is -
				else if((yyvsp[-1].symbolVal)->getValue()=="-")
				{
					//first term is varaible
					if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
					{
						//second term is varaible
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{			
							//first term keyword is float
							//the answer will be float			
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->intstore[0];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate value is stored
								(yyval.symbolVal)=tempval;
							}
							//second term keyword is float
							//the answer will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]-(yyvsp[0].symbolVal)->floatstore[0];							
								}
								//the first team is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
							//both result is int
							//the answer will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								//an int keyword is ready to store
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]-(yyvsp[0].symbolVal)->intstore[0];
								//ultimate value is stored
								(yyval.symbolVal)=tempval;
							}
						}
						//if the second term is array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{			
							//if the first term is float
							//the result will be float			
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//the value will be float, ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate value is stored
								(yyval.symbolVal)=tempval;
							}
							//if the second term is float
							//the result will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//the value will be float, ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
							//both result is int
							//the result will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]-(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
						}
					}
					//if first term is array
					else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
					{
						//the second term is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{				
							//the first term is float
							//so the answer will be float		
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//second term is int
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->intstore[0];							
								}
								//second term is int
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate result is stored
								(yyval.symbolVal) =tempval;
							}
							//the second term is float
							//so the answer will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first value is int
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[0];							
								}
								//the first value is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[0];
								}
								//the ultimate value is stored
								(yyval.symbolVal)=tempval;
							}
							//both values are int
							//the answer will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->intstore[0];
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
						}
						//the second term is array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{	
							//the first term is float
							//the answer will be float					
							if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if((yyvsp[0].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
							//the second term is float
							//the answer will be float
							else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
							{
								//float value is ready to stored
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//first term is int
								if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//first term is float
								else
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//the ultimate value is stored
								(yyval.symbolVal)=tempval;
							}
							//both values is int
							//the answer will be int
							else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]-(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//the ultimate result is stored
								(yyval.symbolVal)=tempval;
							}
						}
					}
				}
			}
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1503 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : term : unary_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			(yyval.symbolVal)->intstore.push_back(0); //if the term is int
			(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
			//considering it both
			// for next term semantic check
		}
#line 3055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1515 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : term : term MULOP unary_expression\n"<< endl;
			//MULOP is *
			if((yyvsp[-1].symbolVal)->getValue()=="*")
			{
				//the first term is variable
				if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
				{	
					//second value is variable 
					if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
					{		
						//the first value is float
						//the result will be float
						if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
						{
							
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->intstore[0];							
							}
							//the second value is float
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->floatstore[0];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//second value is float
						//the result will be float
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the first value is int
							if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]*(yyvsp[0].symbolVal)->floatstore[0];							
							}
							//the first value is float
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->floatstore[0];
							}
							//ultimate result is stored
							(yyval.symbolVal)=tempval;
						}
						//both value is int
						//result is int
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]*(yyvsp[0].symbolVal)->intstore[0];
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
					}
					//the second value is array
					else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
					{		
						//the first value is float
						//result will be float
						if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];							
							}
							//the second value is int
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//the second value is float
						//result will be float
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//first value is int
							if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];							
							}
							//first value is int
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//both value is int
						//result will be int
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]*(yyvsp[0].symbolVal)->intstore[0];
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
					}
				}
				//the first value is array
				else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
				{	
					//the second value is variable
					if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
					{		
						//the first value is float
						//the answer will be float
						if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->intstore[0];							
							}
							//the second value is float
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[0];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//the second value is float
						//the answer will be float
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//first value is int
							if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[0];							
							}
							//first value is float
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[0];
							}
							//the ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//both value is int
						//result is int
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->intstore[0];
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
					}
					//the second value is array
					else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
					{		
						//the first value is float
						//the result will be float
						if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//second value is int
							if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//second value is int
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//the second value is float
						//the result will be float
						else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the first value is int
							if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//the first value is float
							else
							{
								tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
						//both value is int
						//answer will be int
						else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]*(yyvsp[0].symbolVal)->intstore[0];
							//ultimate value is stored
							(yyval.symbolVal)=tempval;
						}
					}
				}
			}
			//MULOP is /
			else if((yyvsp[-1].symbolVal)->getValue()=="/")
			{
				//the first value is float
				//answer will be float
				if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
				{
					SymbolInfo* tempval=new SymbolInfo("FLOAT");
					//second value is int
					if((yyvsp[0].symbolVal)->getReturnType()=="INT")
					{
						//first value can be varaible or array
						//if it is variable
						if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
						{
							//the second value can be variable or array
							//if it is varaible
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//if the second value is not zero, the answer will be nonzero
								if((yyvsp[0].symbolVal)->intstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->intstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//the second value is array
							else if((yyvsp[0].symbolVal)->getKeyType() == "ARA")
							{
								//the second value is nonzero
								//answer will be nonzero
								if((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//otherwise an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value will result nonzero
								if((yyvsp[0].symbolVal)->intstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->intstore[0];
								//otherwise an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value will result nonzero 
								if((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//otherwise an error will occur
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}
					//the second value is float
					else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
					{
						//the first value is variable
						if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
						{
							//the second value is variable or array
							//if it is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value will give nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise it will occur an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//if second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//otherwise an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is an aray
						else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise an error will occur
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}
					//ultimate value is stored
					(yyval.symbolVal)=tempval;
				}
				//second value is float
				//the answer will be float
				else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
				{
					//float value is ready to store
					SymbolInfo* tempval=new SymbolInfo("FLOAT");
					//first value is int
					if((yyvsp[-2].symbolVal)->getReturnType()=="INT")
					{
						//first value is variable
						if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[0]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise there will be an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 	
								}
							}
						}
					}
					//first value is float
					else if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT")
					{
						//first value is variable
						if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[0]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
						{
							//second value is variable
							if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[0]!=0)
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=(yyvsp[-2].symbolVal)->floatstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}	
					//ultimate value is stored			
					(yyval.symbolVal)=tempval;
				}
				//both values is int
				//the answer will be int
				else if((yyvsp[0].symbolVal)->getReturnType()=="INT"&&(yyvsp[-2].symbolVal)->getReturnType()=="INT")
				{
					//int value is ready to store
					SymbolInfo* tempval=new SymbolInfo("INT");
					//first value is variable
					if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
					{	
						//second value is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{		
							//nonzero value,nonzero result	
							if((yyvsp[0].symbolVal)->intstore[0]!=0)
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]/(yyvsp[0].symbolVal)->intstore[0];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
						//second value is array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{
							//nonzero value,nonzero result
							if((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[0]/(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
					}
					//first value is array
					else if((yyvsp[-2].symbolVal)->getKeyType()=="ARA")
					{
						//second value is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						{			
							//nonzero value,nonzero result
							if((yyvsp[0].symbolVal)->intstore[0]!=0)
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->intstore[0];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
						//second value is array
						else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						{
							//nonzero value,nonzero result
							if((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]!=0)
							{
								tempval->intstore[0]=(yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()]/(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
							}
							//otherwise there will be an error
							else
							{
								//tempval->floatstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
					}
					//ultimate value is stored
					(yyval.symbolVal)=tempval;
				}
			}
			//MULOP is %
			else if((yyvsp[-1].symbolVal)->getValue()=="%")
			{
				//answer will be int keyword
				//int value is ready to store
				SymbolInfo* tempval=new SymbolInfo("INT");
				//variable or array type
				//this requires a variable type
				//not sure, is this necessary ?
				tempval->setkeyType("VAR");
				//values should be int keyword
				//otherwise an error
				if((yyvsp[-2].symbolVal)->getReturnType()=="FLOAT"||(yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
				{
					errorout<<"Error at line "<<line_count<<" : Unsuported operand for mod operator"<<endl;
					errors++; 
				}
				else if((yyvsp[-2].symbolVal)->getReturnType()=="INT"&&(yyvsp[0].symbolVal)->getReturnType()=="INT")
				{
					//first value is variable
					if((yyvsp[-2].symbolVal)->getKeyType()=="VAR")
					{
						//second value is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							tempval->intstore[0]=((yyvsp[-2].symbolVal)->intstore[0])%((yyvsp[0].symbolVal)->intstore[0]);
						//second value is array
						else 
							tempval->intstore[0]=((yyvsp[-2].symbolVal)->intstore[0])%((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]);					
					}
					//first value is array
					else
					{
						//second value is variable
						if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
							tempval->intstore[0]=((yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()])%((yyvsp[0].symbolVal)->intstore[0]);
						//second value is array
						else 
							tempval->intstore[0]=((yyvsp[-2].symbolVal)->intstore[(yyvsp[-2].symbolVal)->getAraIndex()])%((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]);					
					}
				}
				//ultimate result is stored
				(yyval.symbolVal)=tempval;
			}
		}
#line 3695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 2153 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : ADDOP unary_expression\n"<< endl;
				//in this case, only ADDOP - is need
				if((yyvsp[-1].symbolVal)->getValue()=="-")
				{
					//value can be array or variable
					//if the value is variable
					if((yyvsp[0].symbolVal)->getReturnType()=="VAR")
					{	
						//int value
						if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							(yyvsp[0].symbolVal)->intstore[0]=(-1)*((yyvsp[0].symbolVal)->intstore[0]); //the value is changed
						//float value
						else
							(yyvsp[0].symbolVal)->floatstore[0]=(-1)*((yyvsp[0].symbolVal)->floatstore[0]); //the value is changed
					}
					else if((yyvsp[0].symbolVal)->getReturnType()=="ARA")
					{
						//int value
						if((yyvsp[0].symbolVal)->getReturnType()=="INT")
							(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()] = (-1)*((yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()]); //the value is changed
						//float value
						else
							(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()] = (-1)*((yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()]); //the value is changed
					}
				}
				//ultimate value is stored
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
			}
#line 3729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 2183 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : NOT unary_expression \n"<< endl;
				//answer will 0 or 1
				//answer will be int
				//int value is ready to store
				SymbolInfo* tempval=new SymbolInfo("INT");
				//variable or array type
				//this requires a variable type
				//not sure, is this necessary ?
				tempval->setkeyType("VAR");
				int val;
				//both int and float value can access this process
				//if the value is int
				if((yyvsp[0].symbolVal)->getReturnType()=="INT")
				{
					//if the value is variable
					if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						val=(yyvsp[0].symbolVal)->intstore[0];
					//if the value is array
					else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						val=(yyvsp[0].symbolVal)->intstore[(yyvsp[0].symbolVal)->getAraIndex()];
				}
				//if the value is float
				else if((yyvsp[0].symbolVal)->getReturnType()=="FLOAT")
				{
					//if the value is variable
					if((yyvsp[0].symbolVal)->getKeyType()=="VAR")
						 val=(int)(yyvsp[0].symbolVal)->floatstore[0];
					//if the value is array
					else if((yyvsp[0].symbolVal)->getKeyType()=="ARA")
						 val=(int)(yyvsp[0].symbolVal)->floatstore[(yyvsp[0].symbolVal)->getAraIndex()];
				} 
				//not process
				if(val!=0)
					 val=0;
				else
					 val=1;
				//int value is stored
				//0 or 1
				tempval->intstore[0]=val;
				//the ultimate value is stored
				(yyval.symbolVal)=tempval;
			}
#line 3777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 2227 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : factor\n"<< endl;
			
				//semantic check			
				//storing semantic value 
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				(yyval.symbolVal)->intstore.push_back(0); //if the term is int
				(yyval.symbolVal)->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
#line 3793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 2241 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
		}
#line 3801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 2245 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
			//it's for a function call which returns something
			//printing the id
			logout<<(yyvsp[-3].symbolVal)->getValue()<<endl;
			//an object is ready for checking
			SymbolInfo *tempval=new SymbolInfo();
			//checking the function name
			tempval=symbltable.lookTable((yyvsp[-3].symbolVal)->getValue(),"FUNC");
			//if the function doesn't exist
			if(tempval==NULL)
			{
				errorout<<"Error at line "<< line_count<<" : Function "<<(yyvsp[-3].symbolVal)->getValue()<<" doesn't exist"<<endl;
			}
			//if the function exist
			else
			{
				//the factor is in previous grammer ADDOP something, that means it will return something
				//if we get void, then there will occur a problem
				if(tempval->getFuncRet()=="VOID")
				{
					errorout<<"Error at line "<<line_count<<" : Function " <<(yyvsp[-3].symbolVal)->getValue()<<" returns void"<<endl;
				} 
				else
				{ 
					// an object is ready to store which contains the return type keyword
					SymbolInfo *tempval2=new SymbolInfo((yyvsp[-3].symbolVal)->getFuncRet());
					//values are kept for future semantic check
					//if it is int
					if(tempval2->getReturnType()=="INT")
						tempval2->intstore[0]=0;
					//if it is float
					else if(tempval2->getReturnType()=="FLOAT")
						tempval2->floatstore[0]=0;
					//if it is char
					else if(tempval2->getReturnType()=="CHAR")
						tempval2->charstore[0]='\0';
					(yyval.symbolVal)=tempval2;
				}
			}
		}
#line 3847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 2287 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : LPAREN expression RPAREN\n"<< endl;
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
		}
#line 3856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 2292 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : CONST_INT\n"<< endl;
			//the number is printed out
			logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
			//the number is set as an int
			(yyvsp[0].symbolVal)->setReturnType("INT");
			//type is set as an varaible
			//not sure is it necessary(have to check)
			(yyvsp[0].symbolVal)->setkeyType("VAR");
			//atoi works as an conversion of array of character to int
			//string is converted to int			
			(yyvsp[0].symbolVal)->intstore[0]=atoi((yyvsp[0].symbolVal)->getValue().c_str());
			//ultimate value is stored
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
		}
#line 3876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2308 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : CONST_FLOAT\n"<< endl;
			//the number is printed out
			logout<<(yyvsp[0].symbolVal)->getValue()<<endl;
			//the number is set as an int
			(yyvsp[0].symbolVal)->setReturnType("FLOAT");
			//type is set as an varaible
			//not sure is it necessary(have to check)
			(yyvsp[0].symbolVal)->setkeyType("VAR");
			//atof works as an conversion of array of character to float
			//string is converted to float			
			(yyvsp[0].symbolVal)->intstore[0]=atof((yyvsp[0].symbolVal)->getValue().c_str());
			//ultimate value is stored
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
		}
#line 3896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2324 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable INCOP\n"<< endl;
			//value can be array or variable
			if((yyvsp[-1].symbolVal)->getKeyType()=="ARA")
			{
				//first value is int
				if((yyvsp[-1].symbolVal)->getReturnType()=="INT")
				{
					(yyvsp[-1].symbolVal)->intstore[(yyvsp[-1].symbolVal)->getAraIndex()]=(yyvsp[-1].symbolVal)->intstore[(yyvsp[-1].symbolVal)->getAraIndex()]+1; 
				}
				//first value is float
				else if((yyvsp[-1].symbolVal)->getReturnType()=="FLOAT")
				{
					(yyvsp[-1].symbolVal)->floatstore[(yyvsp[-1].symbolVal)->getAraIndex()]=(yyvsp[-1].symbolVal)->floatstore[(yyvsp[-1].symbolVal)->getAraIndex()]+1.0; 
				}			
			}
			//value is array
			else if((yyvsp[-1].symbolVal)->getKeyType()=="VAR")
			{
				//first value is int
				if((yyvsp[-1].symbolVal)->getReturnType()=="INT")
				{
					(yyvsp[-1].symbolVal)->intstore[0]=(yyvsp[-1].symbolVal)->intstore[0]+1; 
				}
				//first value is float
				else if((yyvsp[-1].symbolVal)->getReturnType()=="FLOAT"){
					(yyvsp[-1].symbolVal)->floatstore[0]=(yyvsp[-1].symbolVal)->floatstore[0]+1.0; 
				}					
			}
			//value is character
			//error
			else if((yyvsp[-1].symbolVal)->getKeyType()=="CHAR")
			{
				//errorout<<"Error at line "<<line_count<<" Character varaible can't increase "<<endl; 
			}
			//value is stored
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
		}
#line 3939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2363 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable DECOP\n"<< endl;
			//value can be array or variable
			if((yyvsp[-1].symbolVal)->getKeyType()=="ARA")
			{
				//first value is int
				if((yyvsp[-1].symbolVal)->getReturnType()=="INT")
				{
					(yyvsp[-1].symbolVal)->intstore[(yyvsp[-1].symbolVal)->getAraIndex()]=(yyvsp[-1].symbolVal)->intstore[(yyvsp[-1].symbolVal)->getAraIndex()]-1; 
				}
				//first value is float
				else if((yyvsp[-1].symbolVal)->getReturnType()=="FLOAT")
				{
					(yyvsp[-1].symbolVal)->floatstore[(yyvsp[-1].symbolVal)->getAraIndex()]=(yyvsp[-1].symbolVal)->floatstore[(yyvsp[-1].symbolVal)->getAraIndex()]-1.0; 
				}			
			}
			//value is array
			else if((yyvsp[-1].symbolVal)->getKeyType()=="VAR")
			{
				//first value is int
				if((yyvsp[-1].symbolVal)->getReturnType()=="INT")
				{
					(yyvsp[-1].symbolVal)->intstore[0]=(yyvsp[-1].symbolVal)->intstore[0]-1; 
				}
				//first value is float
				else if((yyvsp[-1].symbolVal)->getReturnType()=="FLOAT"){
					(yyvsp[-1].symbolVal)->floatstore[0]=(yyvsp[-1].symbolVal)->floatstore[0]-1.0; 
				}					
			}
			//value is character
			//error
			else if((yyvsp[-1].symbolVal)->getKeyType()=="CHAR")
			{
				//errorout<<"Error at line "<<line_count<<" Character varaible can't increase "<<endl; 
			}
			//value is stored
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
		}
#line 3982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2404 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : argument_list : arguments\n"<< endl;
			}
#line 3990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2411 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : arguments : arguments COMMA logic_expression\n"<< endl;
		}
#line 3998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 2415 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : arguments : logic_expression\n"<< endl;
			}
#line 4006 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4010 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 2421 "1505044_bison.y" /* yacc.c:1906  */


int main(int argc,char *argv[])
{

	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("1505044_log.txt");
	errorout.open("1505044_errors.txt");
	
	
	yyparse();
	
	logout<<"Total Lines : "<<line_count<<endl; 
	
	logout.close();
	errorout.close();

	return 0;
}
