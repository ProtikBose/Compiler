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
#include <sstream>
#include "1505044symbolTable.h"

//#define YYSTYPE SymbolInfo*

using namespace std;

string variable_type;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
string pCode="";
SymbolTable table(13);
int argnum=0;
vector<string>argvalue; 
bool funcflag=false;
extern int line_count;
int errors;
vector<SymbolInfo>parameter; 
string pList="";
string tSpec="";
string dList="";
string cStmt="";

string var_dec="";
string unitG="";
string programG="";
string func_dec="";
string varG="";
string factorG="";
string una_exp="";
string func_def="";
string com_stat="";
string stats="";
string stat="";
string exp_stat="";
string expG="";
string logic_exp="";
string rel_exp="";
string sim_exp="";
string termG="";
string arg_list="";
string argG="";
//string expList="";
vector<string>arrvar;
vector<int>arrvarlen;
vector<string>var;
vector<string>tempvar;
string ret_lab;
int labelCount=0;
int tempCount=0;
int maxTemp = 0;
int pTempCount = 0;
ofstream logout, errorout,asmout;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	if(maxTemp < tempCount) maxTemp = tempCount;
	strcat(t,b);
	return t;
}

char *newPTemp()
{
	char *pt= new char[4];
	strcpy(pt,"tempo");
	char b[3];
	sprintf(b,"%d", pTempCount);
	pTempCount++;
	strcat(pt,b);
	return pt;
}

void yyerror(const char *s)
{
	//write your code
	printf("%s\n",s);
}



#line 172 "y.tab.c" /* yacc.c:339  */

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
    COMMENT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    DO = 263,
    BREAK = 264,
    CONTINUE = 265,
    INT = 266,
    FLOAT = 267,
    CHAR = 268,
    DOUBLE = 269,
    VOID = 270,
    RETURN = 271,
    SWITCH = 272,
    CASE = 273,
    DEFAULT = 274,
    INCOP = 275,
    DECOP = 276,
    ASSIGNOP = 277,
    LPAREN = 278,
    RPAREN = 279,
    LCURL = 280,
    RCURL = 281,
    LTHIRD = 282,
    RTHIRD = 283,
    SEMICOLON = 284,
    COMMA = 285,
    STRING = 286,
    NOT = 287,
    PRINTLN = 288,
    BITOP = 289,
    ID = 290,
    CONST_INT = 291,
    CONST_FLOAT = 292,
    CONST_CHAR = 293,
    ADDOP = 294,
    MULOP = 295,
    LOGICOP = 296,
    RELOP = 297,
    second_precedence = 298
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define DO 263
#define BREAK 264
#define CONTINUE 265
#define INT 266
#define FLOAT 267
#define CHAR 268
#define DOUBLE 269
#define VOID 270
#define RETURN 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define INCOP 275
#define DECOP 276
#define ASSIGNOP 277
#define LPAREN 278
#define RPAREN 279
#define LCURL 280
#define RCURL 281
#define LTHIRD 282
#define RTHIRD 283
#define SEMICOLON 284
#define COMMA 285
#define STRING 286
#define NOT 287
#define PRINTLN 288
#define BITOP 289
#define ID 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define CONST_CHAR 293
#define ADDOP 294
#define MULOP 295
#define LOGICOP 296
#define RELOP 297
#define second_precedence 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 106 "1505044_bison.y" /* yacc.c:355  */

SymbolInfo* symbolVal;

#line 302 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 319 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

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
       0,   128,   128,   155,   166,   179,   188,   197,   208,   239,
     246,   314,   337,   347,   367,   378,   383,   387,   382,   398,
     408,   421,   428,   441,   452,   465,   503,   550,   577,   611,
     619,   632,   640,   648,   656,   675,   689,   707,   725,   729,
     734,   744,   752,   761,   769,   776,   801,   839,   857,   888,
     904,   970,   987,  1059,  1077,  1114,  1131,  1189,  1208,  1223,
    1242,  1262,  1296,  1304,  1317,  1330,  1343,  1359,  1369,  1376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "IF", "ELSE", "FOR", "WHILE",
  "DO", "BREAK", "CONTINUE", "INT", "FLOAT", "CHAR", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "INCOP", "DECOP", "ASSIGNOP",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON",
  "COMMA", "STRING", "NOT", "PRINTLN", "BITOP", "ID", "CONST_INT",
  "CONST_FLOAT", "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP",
  "second_precedence", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "$@2", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,   -66,   -66,   -66,    13,    45,   -66,   -66,   -66,   -66,
      -9,   -66,   -66,     7,     3,    45,   -13,   -66,   -66,     2,
     -12,    23,    49,    32,    18,    45,   -66,   -66,    43,   -66,
      55,   -66,   -66,    50,    56,   -66,    91,   -66,   -66,    64,
      65,    68,    39,    39,   -66,    39,    77,    27,   -66,   -66,
      39,   -66,   -66,    66,    57,   -66,   -66,    97,    15,   -66,
      63,   -28,    69,   -66,   -66,    39,    76,    39,    19,    86,
      31,   -66,    87,    39,    39,   -66,    94,   -66,   -66,   -66,
     -66,    39,   -66,   -66,    39,    39,    39,    39,   101,    76,
     105,   -66,   -66,   -66,   107,   -66,   108,   103,   106,   -66,
     -66,   -66,    69,    96,   -66,    91,    39,    91,    20,   -66,
      39,   -66,   131,   113,   -66,   -66,   -66,   -66,    91,    91,
     -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,    15,     0,    21,    20,     0,
       0,    14,     0,    25,     0,     0,    13,    28,     0,     9,
      16,     8,    10,    12,     0,    19,     0,    11,    26,     0,
       0,     0,     0,     0,    42,     0,     0,    45,    63,    64,
       0,    33,    31,     0,     0,    29,    32,    60,     0,    47,
      49,    51,    53,    55,    59,     0,     0,     0,     0,     0,
      60,    58,     0,     0,     0,    57,    27,    17,    30,    65,
      66,     0,    44,    43,     0,     0,     0,     0,     0,     0,
       0,    41,    40,    62,     0,    69,     0,    67,     0,    18,
      48,    50,    54,    52,    56,     0,     0,     0,     0,    61,
       0,    46,    35,     0,    37,    39,    38,    68,     0,     0,
      36,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   133,   -66,   -66,   -66,   115,   -66,   -66,
      22,    10,   -66,   -66,   -52,   -65,   -45,   -36,   -64,    58,
      54,    59,   -42,   -66,   -66,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    51,    36,    99,
      52,    53,    14,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    89,    78,    71,    17,    70,    68,    69,    75,    95,
      10,    85,    24,    11,    86,    10,    82,   100,    25,    29,
      91,   115,     9,    22,   106,    21,    13,     9,    70,    88,
      15,    90,    18,    19,    16,    33,    70,    23,    98,    70,
      70,    70,    70,    30,    83,   104,   117,    31,    92,   116,
      73,    79,    80,   112,    74,   114,     1,     2,    26,    28,
       3,    39,    43,    40,    41,    70,   120,   121,     1,     2,
     113,    45,     3,    42,    47,    48,    49,    27,    50,    34,
      43,    35,    30,    77,    38,    37,    44,    65,    66,    45,
      46,    67,    47,    48,    49,    39,    50,    40,    41,    43,
      72,    76,     1,     2,    84,    44,     3,    42,    45,    87,
      93,    47,    48,    49,    43,    50,    30,    79,    80,    81,
      44,    16,    94,    45,    46,   105,    47,    48,    49,   107,
      50,   108,   109,   110,   111,    85,   118,   119,    12,    32,
     103,     0,   101,     0,   102
};

static const yytype_int8 yycheck[] =
{
      45,    66,    54,    45,     1,    50,    42,    43,    50,    73,
       0,    39,    24,     0,    42,     5,     1,    81,    30,     1,
       1,     1,     0,    36,    89,    15,    35,     5,    73,    65,
      23,    67,    29,    30,    27,    25,    81,    35,    74,    84,
      85,    86,    87,    25,    29,    87,   110,    29,    29,    29,
      23,    20,    21,   105,    27,   107,    11,    12,    35,    27,
      15,     4,    23,     6,     7,   110,   118,   119,    11,    12,
     106,    32,    15,    16,    35,    36,    37,    28,    39,    36,
      23,    26,    25,    26,    28,    35,    29,    23,    23,    32,
      33,    23,    35,    36,    37,     4,    39,     6,     7,    23,
      23,    35,    11,    12,    41,    29,    15,    16,    32,    40,
      24,    35,    36,    37,    23,    39,    25,    20,    21,    22,
      29,    27,    35,    32,    33,    24,    35,    36,    37,    24,
      39,    24,    24,    30,    28,    39,     5,    24,     5,    24,
      86,    -1,    84,    -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    15,    45,    46,    47,    48,    49,    54,
      55,     0,    47,    35,    56,    23,    27,     1,    29,    30,
      50,    55,    36,    35,    24,    30,    35,    28,    27,     1,
      25,    29,    51,    55,    36,    26,    52,    35,    28,     4,
       6,     7,    16,    23,    29,    32,    33,    35,    36,    37,
      39,    51,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    23,    23,    23,    61,    61,
      60,    66,    23,    23,    27,    66,    35,    26,    58,    20,
      21,    22,     1,    29,    41,    39,    42,    40,    61,    59,
      61,     1,    29,    24,    35,    62,    68,    69,    61,    53,
      62,    63,    65,    64,    66,    24,    59,    24,    24,    24,
      30,    28,    58,    61,    58,     1,    29,    62,     5,    24,
      58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    50,    50,    50,    50,    50,    52,    53,    51,    51,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       6,     4,     3,     2,     1,     0,     0,     0,     5,     2,
       3,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     5,     7,     5,     5,     5,
       3,     3,     1,     2,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     3,     1
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
#line 129 "1505044_bison.y" /* yacc.c:1646  */
    {
			
			//asmout<<1<<endl;
			
			logout<<"At line "<<line_count<<" : start : program\n"<<endl;
			logout<<pCode<<endl<<endl;
			for(int i=0;i<var.size();i++)
			{
				asmout<<var[i]<<" dw ?\n";			
			}

			for(int i=0;i<arrvar.size();i++)
			{
				asmout<<arrvar[i]<<" dw "<<arrvarlen[i]<<" dup(?)\n";
			}
			
			for(int i=0;i<tempvar.size();i++)
			{
				asmout<<tempvar[i]<<" dw ?\n";
			}

			
			asmout<<(yyvsp[0].symbolVal)->asmcode<<endl;
		}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 156 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : program : program unit\n"<<endl;
			programG=pCode+"\n"+unitG;
			pCode=programG;
			(yyval.symbolVal)->setSaveCode(pCode);
			logout<<(yyval.symbolVal)->getSaveCode()<<endl<<endl;
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
		}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 167 "1505044_bison.y" /* yacc.c:1646  */
    {	
			logout<<"At line "<<line_count<<" : program : unit\n"<<endl;
			//pCode=pCode+$$->getSaveCode()+"\n";
			programG=pCode+"\n"+unitG;
			pCode=programG;
			(yyval.symbolVal)->setSaveCode(pCode);
			logout<<(yyval.symbolVal)->getSaveCode()<<endl<<endl;
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			
		}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 180 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : unit : var_declaration\n"<<endl;
			unitG=var_dec;
			logout<<unitG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(unitG);
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
		}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 189 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : unit : func_declaration\n"<<endl;
			unitG=func_dec;
			logout<<unitG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(unitG);
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
     	}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 198 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : unit : func_definition\n"<<endl;
			//logout<<$$->getSaveCode()<<endl;
			unitG=func_def;
			logout<<unitG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(unitG);
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
     	}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 209 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout<<"At line "<<line_count<<" : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						//logout<<$2->getValue()<<endl;
						//checking if it exists
						SymbolInfo *tempval=table.lookTable((yyvsp[-4].symbolVal)->getValue(),"FUNC");
						//if it exists, then error
						if(tempval!=NULL)
						{
							errorout<<"Error at line "<<line_count<<" Function "<<(yyvsp[-4].symbolVal)->getValue()<<" already declared" <<endl;
							errors++;
						}
						//otherwise it will do perfectly well
						else 
						{
							SymbolInfo* tempval2=table.finalInsert((yyvsp[-4].symbolVal)->getValue(),"ID");
							tempval2->setReturnType("FUNC");
							tempval2->setFuncRet((yyvsp[-5].symbolVal)->getKeyType());
							for(int i=0;i<argvalue.size();i++){
								tempval2->pList.push_back(argvalue[i]);					
							}
							argvalue.clear();
							(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+(yyvsp[-4].symbolVal)->getValue()+"("+pList+")"+";"+"\n");
							func_dec=tSpec+" "+(yyvsp[-4].symbolVal)->getValue()+"("+pList+")"+";";
							logout<<func_dec<<endl<<endl;
							(yyval.symbolVal)->setSaveCode(func_dec);
							tSpec="";
							pList="";
						}
						//funcParam.exitScope();
					}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 240 "1505044_bison.y" /* yacc.c:1646  */
    {
						errorout << "Error at line " << line_count << "; missing" << endl << endl;
						errors++;
					}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 247 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout << "At line " << line_count << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
				//logout << $2->getValue() << endl << endl;
				SymbolInfo *tempval = table.lookTable((yyvsp[-4].symbolVal)->getValue(), "FUNC");
				if(argvalue.size() != argnum){
					errorout << "Error at line " << line_count << " Parameter mismatch for Function "<< (yyvsp[-4].symbolVal)->getValue() << endl << endl;
					argvalue.clear(); argnum = 0;
					errors++;
				}												
				if(tempval != NULL){
					//logout << "Function " << $2->getValue() <<" already declared" << endl;
					if(tempval->isFuncDefined()== true){
						errorout << "Error at line " << line_count << "Function "<< (yyvsp[-4].symbolVal)->getValue() <<" already defined" << endl << endl;
						errors++;
						argvalue.clear();
						argnum = 0;
					}
					else if(tempval->getFuncRet() != (yyvsp[-5].symbolVal)->getKeyType()){
						errorout << "Error at line " << line_count << "Function "<< (yyvsp[-4].symbolVal)->getValue() <<" :return type doesn't match declaration" << endl << endl;
						errors++;
						argvalue.clear();argnum = 0; 
					} 
					else if(tempval->pList.size() != argvalue.size()){
						errorout << "Error at line " << line_count << "Function "<< (yyvsp[-4].symbolVal)->getValue() <<" :Parameter list doesn not match declaration" << endl << endl;
						argvalue.clear();argnum = 0;
						errors++;					
					}
					else{
						for(int i = 0; i<tempval->pList.size(); i++){
							if(tempval->pList[i] != argvalue[i]){
								errorout << "Error at line " << line_count << "Function "<< (yyvsp[-4].symbolVal)->getValue()<< " :argument mismatch" << endl << endl;
								argvalue.clear();argnum = 0;
								errors++;	
							}
						}				
					}
				}
				else{
					SymbolInfo* tempval = new SymbolInfo();
					tempval = table.finalInsert((yyvsp[-4].symbolVal)->getValue(), "ID");
					//logout << $2->getValue() << " Function inserted" << endl;
					tempval->setReturnType("FUNC");
					tempval->setFuncRet((yyvsp[-5].symbolVal)->getKeyType());
					//
					for(int i = 0; i<argvalue.size(); i++){
						tempval->pList.push_back(argvalue[i]);					
					}
					tempval->setFuncDefined();
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+(yyvsp[-4].symbolVal)->getValue()+"("+pList+")"+"{"+"\n"+cStmt+"\n"+"}"+"\n");
					//logout<<$$->getSaveCode()<<endl<<endl;
					
					
				}
				argvalue.clear();
				argnum = 0;
				func_def=(yyvsp[-5].symbolVal)->getValue()+" "+(yyvsp[-4].symbolVal)->getValue()+"("+pList+")"+com_stat+"\n";
				logout<<func_def<<endl<<endl;
				pList="";
				cStmt="";
				com_stat="";
				(yyval.symbolVal)->setSaveCode(func_def);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
	
				//funcParam.exitScope();
				}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 315 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout << "At line " << line_count << " : parameter_list  : parameter_list COMMA type_specifier ID\n";
					//logout << $4->getValue() << endl << endl;
					argvalue.push_back(variable_type);//changed from $3->getKeyType()
					argnum++;
					//SymbolInfo* tempval = funcParam.finalInsert($4->getValue(), $4->getKeyword());					
					//tempval->setReturnType("VAR");
					//tempval->setkeyType($3->getKeyType());
					(yyvsp[0].symbolVal)->setReturnType("VAR");
					(yyvsp[0].symbolVal)->setkeyType(variable_type);//changed from $3->getKeyType()
					SymbolInfo* tempval = new SymbolInfo((yyvsp[0].symbolVal)->getValue(), (yyvsp[0].symbolVal)->getKeyword());
					tempval->setReturnType("VAR");
					
					parameter.push_back(*tempval);
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+","+tSpec+" "+(yyvsp[0].symbolVal)->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+","+tSpec+" "+(yyvsp[0].symbolVal)->getValue();
					//pCode=pCode+" "+","+tSpec+" "+$4->getValue();
					logout<<pList<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(pList);
				
				}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 338 "1505044_bison.y" /* yacc.c:1646  */
    {					
					logout << "At line " << line_count << " : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					argvalue.push_back((yyvsp[0].symbolVal)->getKeyType());
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+","+tSpec);
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+","+tSpec;
					logout<<pList<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(pList);
				}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 348 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout << "At line " << line_count << " : parameter_list  : type_specifier ID\n";
					//logout << $2->getValue() << endl << endl;
					//argvalue.clear();
					argvalue.push_back(variable_type);//$1->getKeyType()
					argnum++;
					//SymbolInfo* tempval = funcParam.finalInsert($2->getValue(), $2->getKeyword());
					//tempval->setReturnType("VAR");
					//tempval->setkeyType($1->getKeyType());
					(yyvsp[0].symbolVal)->setReturnType("VAR");
					(yyvsp[0].symbolVal)->setkeyType(variable_type);//$1->getKeyType()
					parameter.push_back(*(yyvsp[0].symbolVal));
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+(yyvsp[0].symbolVal)->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+tSpec+" "+(yyvsp[0].symbolVal)->getValue();
					logout<<pList<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(pList);
				
				}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 368 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout << "At line " << line_count << " : parameter_list  : type_specifier\n"<< endl;
					//argvalue.clear();
					argvalue.push_back(variable_type);
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+tSpec;
					logout<<pList<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(pList);
				}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 378 "1505044_bison.y" /* yacc.c:1646  */
    {//logout << "Empty parameter " << line_count << endl;
				}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 383 "1505044_bison.y" /* yacc.c:1646  */
    {
							table.enterScope(); 
							for(int i = 0; i<parameter.size(); i++) table.insertTable(parameter[i]);
							parameter.clear();
						}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 387 "1505044_bison.y" /* yacc.c:1646  */
    {table.exitScope();}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 388 "1505044_bison.y" /* yacc.c:1646  */
    {
							logout << "At line " << line_count << " : compound_statement : LCURL statements RCURL\n"<< endl;
							(yyval.symbolVal)=(yyvsp[-2].symbolVal);
							(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+"{"+"\n"+stats+"\n"+"}");
							com_stat=com_stat+"{"+"\n"+stats+"\n"+"}";
							logout<<com_stat<<endl<<endl;
							(yyval.symbolVal)->setSaveCode(com_stat);
							//asmout<<$$->asmcode;
							
						}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 399 "1505044_bison.y" /* yacc.c:1646  */
    {
							logout << "At line " << line_count << " : compound_statement : LCURL RCURL\n"<< endl;
							(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+"{"+"\n"+"\n"+"}");
							com_stat=com_stat+"{"+"\n"+"\n"+"}";
							logout<<com_stat<<endl<<endl;
							(yyval.symbolVal)->setSaveCode(com_stat);
						}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 409 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout << "At line " << line_count << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
				//$$->setSaveCode(pCode+";"+"\n");
				//logout<<$$->getSaveCode()<<endl<<endl;
				var_dec=tSpec+" "+dList+" "+";"+"\n";
				
				//tSpec=tSpec+" "+dList+";";
				logout<<var_dec<<endl;
				tSpec="";
				dList="";
				(yyval.symbolVal)->setSaveCode(var_dec);
			}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 422 "1505044_bison.y" /* yacc.c:1646  */
    {
						errorout << "Error at line " << line_count << "; missing" << endl << endl;
						errors++;
				}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 429 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At line "<<line_count<<" : type_specifier : INT"<<endl<<endl; 
					SymbolInfo* s=new SymbolInfo("INT");
					variable_type="INT";
					(yyval.symbolVal)=s;
					
					tSpec="int";
					(yyval.symbolVal)->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					(yyval.symbolVal)->setSaveCode("int");
					
				}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 442 "1505044_bison.y" /* yacc.c:1646  */
    {	
					logout << "At line " << line_count << " : type_specifier	: FLOAT\n"<< endl;
					SymbolInfo* s= new SymbolInfo("FLOAT");
					variable_type = "FLOAT";
					(yyval.symbolVal)=s;
					tSpec="float";
					(yyval.symbolVal)->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					(yyval.symbolVal)->setSaveCode("float");
				}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 453 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout << "At line " << line_count << " : type_specifier	: VOID\n"<< endl;
					SymbolInfo* s= new SymbolInfo("VOID");
					variable_type = "VOID";
					(yyval.symbolVal)=s;
					tSpec="void";
					(yyval.symbolVal)->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					(yyval.symbolVal)->setSaveCode("void");
				}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 466 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout << "At line " << line_count << " : declaration_list : 	declaration_list COMMA ID\n";
						//logout << $3->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable((yyvsp[0].symbolVal)->getValue(), "VAR");
							if(tempval != NULL){
							errorout << "Error at line " << line_count << ": Variable "<< (yyvsp[0].symbolVal)->getValue() <<" already declared" << endl << endl;	
							errors++;	
							}
							else
							{
								//SymbolInfo* tempval2 = table.finalInsert($3->getValue(), $3->getKeyword());
								//tempval2->setkeyType(variable_type);
								//tempval2->setReturnType("VAR");
								SymbolInfo* tempval2 = new SymbolInfo((yyvsp[0].symbolVal)->getValue(), (yyvsp[0].symbolVal)->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("VAR");
								table.insertTable(*tempval2);
								//table.printAll(logout);
								//$$=tempval2;
							
								(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+","+(yyvsp[0].symbolVal)->getValue());
								//logout<<$$->getSaveCode()<<endl<<endl;
								//pCode=pCode+" "+","+$3->getValue();
								dList=dList+" "+","+(yyvsp[0].symbolVal)->getValue();
								logout<<dList<<endl<<endl;

								//pCode=pCode+" "+$$->getSaveCode();
								//logout << $$->getValue() << endl << endl;
							}
						}
						
					}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 504 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout << "At line " << line_count << " : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						//logout << $3->getValue() << endl;
						//logout << $5->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " : array type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable((yyvsp[-3].symbolVal)->getValue(), "ARA");
							if(tempval!= NULL){
							errorout << "Error at line " << line_count << " : Array "<< (yyvsp[-3].symbolVal)->getValue()<< " already declared" << endl << endl;
								errors++;			
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo((yyvsp[-3].symbolVal)->getValue(), (yyvsp[-3].symbolVal)->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("ARA");
								int araSize = atoi(((yyvsp[-1].symbolVal)->getValue()).c_str());
								tempval2->setAraLength(araSize);
								if(variable_type == "INT"){								
									for(int i = tempval2->intstore.size(); i<araSize; i++){
										tempval2->intstore.push_back(0);
									}							
								}
								else if(variable_type == "FLOAT"){								
									for(int i = tempval2->floatstore.size(); i<araSize; i++){
										tempval2->floatstore.push_back(0);
									}							
								}
								else if(variable_type == "CHAR"){								
									for(int i = tempval2->charstore.size(); i<araSize; i++){
										tempval2->charstore.push_back('\0');
									}							
								}
								table.insertTable(*tempval2);						
								//table.printAll(logout);
								(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+" "+","+(yyvsp[-3].symbolVal)->getValue()+"["+(yyvsp[-1].symbolVal)->getValue()+"]");
								//logout<<$$->getSaveCode()<<endl<<endl;
								//pCode=pCode+" "+","+$3->getValue()+"["+$5->getValue()+"]";
								dList=dList+" "+","+(yyvsp[-3].symbolVal)->getValue()+"["+(yyvsp[-1].symbolVal)->getValue()+"]";
								logout<<dList<<endl<<endl;
							}
						}

					}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 551 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout << "At line " << line_count << " : declaration_list :	ID\n";
						//logout << $1->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable((yyvsp[0].symbolVal)->getValue(), "ARA");
							if(tempval!= NULL){
							errorout << "Error at line " << line_count << ": Variable "<< (yyvsp[0].symbolVal)->getValue() <<" already declared" << endl << endl;	
								errors++;		
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo((yyvsp[0].symbolVal)->getValue(), (yyvsp[0].symbolVal)->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("VAR");
								table.insertTable(*tempval2);
								//table.printAll(logout);
								(yyval.symbolVal)=tempval2;
								dList=(yyvsp[0].symbolVal)->getValue();
								logout<<dList<<endl<<endl;
								(yyval.symbolVal)->setSaveCode((yyvsp[0].symbolVal)->getValue());
							}
						}
					}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 578 "1505044_bison.y" /* yacc.c:1646  */
    {
						logout << "At line " << line_count << " : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						//logout << $1->getValue() << endl;
						//logout << $3->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :array type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable((yyvsp[-3].symbolVal)->getValue(), "ARA");
							if(tempval!= NULL){
								errorout << "Error at line " << line_count << ": Array "<< (yyvsp[-3].symbolVal)->getValue() <<" already declared" << endl << endl;	
								errors++;
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo((yyvsp[-3].symbolVal)->getValue(), (yyvsp[-3].symbolVal)->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("ARA");
								int araSize = atoi(((yyvsp[-1].symbolVal)->getValue()).c_str());
								tempval2->setAraLength(araSize);
								table.insertTable(*tempval2);
								//table.printAll(logout);
								(yyval.symbolVal)->setSaveCode(" "+(yyvsp[-3].symbolVal)->getValue()+"["+(yyvsp[-1].symbolVal)->getValue()+"]");
								//logout<<$$->getSaveCode()<<endl<<endl;	
								//pCode=pCode+" "+$1->getValue()+"["+$3->getValue()+"]";
								dList=	" "+(yyvsp[-3].symbolVal)->getValue()+"["+(yyvsp[-1].symbolVal)->getValue()+"]";
								logout<<dList<<endl<<endl;	
							}
						}
					}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 612 "1505044_bison.y" /* yacc.c:1646  */
    {	
			logout<<"At line "<<line_count<< " : statements : statement\n"<< endl;
			stats=stat;
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			logout<<stats<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stats);
		}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 620 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statements : statements statement\n"<< endl;
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
			delete (yyvsp[0].symbolVal);
			stats=stats+" "+stat+"\n";
			logout<<stats<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stats);
			//asmout<<$$->asmcode;
		}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 633 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : var_declaration\n"<< endl;
			stat=var_dec;
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			//asmout<<$$->asmcode;
		}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 641 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : expression_statement\n"<< endl;
			stat=exp_stat;
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
		}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 649 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : compound_statement\n"<< endl;
			stat=com_stat;
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
		}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 657 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
			(yyval.symbolVal)=(yyvsp[-4].symbolVal);
			stat="for ("+(yyvsp[-4].symbolVal)->getValue()+" "+(yyvsp[-3].symbolVal)->getValue()+" "+expG+")"+"\n"+(yyvsp[0].symbolVal)->getValue();
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			char *lab1=newLabel();
			char *lab2=newLabel();
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+string(lab1)+":"+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+(yyvsp[-3].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" mov ax , "+(yyvsp[-3].symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" cmp ax , 0\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" je "+string(lab2)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+ (yyvsp[0].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+ (yyvsp[-2].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" jmp "+string(lab1)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+string(lab2)+":"+"\n";
		}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 676 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
			stat="if ("+expG+" )"+stat;
			(yyval.symbolVal)=(yyvsp[-2].symbolVal);
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			char *label=newLabel();
			(yyval.symbolVal)->asmcode+="mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode+="cmp ax, 0\n";
			(yyval.symbolVal)->asmcode+="je "+string(label)+"\n";
			(yyval.symbolVal)->asmcode+=" "+(yyvsp[0].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode+=string(label)+":\n";
		}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 690 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
			stat="if("+expG+")"+"\n"+(yyvsp[-2].symbolVal)->getValue()+"\n"+"else"+"\n"+(yyvsp[0].symbolVal)->getValue();
			(yyval.symbolVal)=(yyvsp[-4].symbolVal);
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			char *lab1=newLabel(); //else
			char *lab2=newLabel();	//exit
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-4].symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"cmp ax,0\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"je "+string(lab1)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+(yyvsp[-2].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jmp "+string(lab2)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+string(lab1)+":\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+(yyvsp[0].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+string(lab2)+":\n";
		}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 708 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
			stat="while("+expG+")"+"\n"+(yyvsp[0].symbolVal)->getValue();
			(yyval.symbolVal)=new SymbolInfo();
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			char *lab1=newLabel(); //while
			char *lab2=newLabel();	//exit
			(yyval.symbolVal)->asmcode=string(lab1)+":"+"\n"; 
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+(yyvsp[-2].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax , "+(yyvsp[-2].symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"cmp ax , 0"+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"je "+string(lab2)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" "+(yyvsp[0].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jmp "+string(lab1)+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+string(lab2)+":"+"\n";
		}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 726 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
		}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 730 "1505044_bison.y" /* yacc.c:1646  */
    {
			errorout<<" Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 735 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : statement : RETURN expression SEMICOLON\n"<< endl;
			stat="return "+expG+";";
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			logout<<stat<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(stat);
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov dx,"+(yyvsp[-1].symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jmp   "+string(ret_lab)+"\n";
		}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 745 "1505044_bison.y" /* yacc.c:1646  */
    {
			errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 753 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At line "<<line_count<< " : expression_statement 	: SEMICOLON\n"<< endl;	
					exp_stat=";";
					logout<<exp_stat<<endl<<endl;
					(yyval.symbolVal)=new SymbolInfo(";","SEMICOLON");
					(yyval.symbolVal)->setSaveCode(exp_stat);
					(yyval.symbolVal)->asmcode="";
				}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 762 "1505044_bison.y" /* yacc.c:1646  */
    {
					logout<<"At line "<<line_count<< " : expression_statement : expression SEMICOLON\n"<< endl;
					exp_stat=expG+";";
					logout<<exp_stat<<endl<<endl;
					(yyval.symbolVal)=(yyvsp[-1].symbolVal);
					(yyval.symbolVal)->setSaveCode(exp_stat);
				}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 770 "1505044_bison.y" /* yacc.c:1646  */
    {
					errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
					errors++;
				}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 777 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<<" : variable : ID\n";
				//logout << $1->getValue() << endl << endl;
				SymbolInfo* tempval=table.lookTable((yyvsp[0].symbolVal)->getValue(),"VAR");
				if(tempval == NULL){
					//logout << "Variable " << $1->getValue() << " doesn't exist" << endl;
					errorout<<"Error at line "<<line_count<<" : "<<(yyvsp[0].symbolVal)->getValue()<<" doesn't exist"<<endl;					
					errors++;
				}
				else{
					(yyval.symbolVal)=(yyvsp[0].symbolVal);
					(yyval.symbolVal)->setSaveCode((yyval.symbolVal)->getSaveCode()+""+(yyvsp[0].symbolVal)->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					//pCode=pCode+""+$1->getValue();
					//variable_type = tempval->getKeyType();
					varG=(yyvsp[0].symbolVal)->getValue();
					logout<<varG<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(varG);
					(yyval.symbolVal)->asmcode="";
					(yyval.symbolVal)->setValue((yyval.symbolVal)->getValue()+to_string(table.scopeNum));
					var.push_back((yyval.symbolVal)->getValue());
					(yyval.symbolVal)->setKeyword("notarray");
				}			
			}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 802 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout << "At line " << line_count << " : variable : ID LTHIRD expression RTHIRD\n";
				//logout << $1->getValue() << endl << endl;
				SymbolInfo* tempval = table.lookTable((yyvsp[-3].symbolVal)->getValue(),"ARA");
				if(tempval == NULL){
				errorout << "Error at line " << line_count << " : " <<(yyvsp[-3].symbolVal)->getValue() << " doesn't exist" <<  endl << endl;					
					errors++;
					varG=(yyvsp[-3].symbolVal)->getValue()+"["+expG+"]";
					logout<<varG<<endl<<endl;
					(yyval.symbolVal)->setValue(varG);
					(yyval.symbolVal)->setSaveCode(varG);				
				}
				else{
					//$$ = tempval;
					
					(yyval.symbolVal)=(yyvsp[-3].symbolVal);
					varG=(yyvsp[-3].symbolVal)->getValue()+"["+expG+"]";
					logout<<varG<<endl<<endl;
					(yyval.symbolVal)->setValue(varG);
					(yyval.symbolVal)->setSaveCode(varG);
					(yyval.symbolVal)->setKeyword("array");
					(yyval.symbolVal)->setValue((yyval.symbolVal)->getValue()+to_string(table.scopeNum));
					arrvar.push_back((yyval.symbolVal)->getValue());
					arrvarlen.push_back((yyvsp[-3].symbolVal)->getAralength());
					(yyval.symbolVal)->asmcode=(yyvsp[-1].symbolVal)->asmcode ;
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" mov bx, " +(yyvsp[-1].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+" add bx, bx\n";
					
					delete (yyvsp[-1].symbolVal);
					//$$->setSaveCode($$->getSaveCode()+""+$1->getValue()+"["+expList+"]");
					//logout<<$$->getSaveCode()<<endl<<endl;
					//pCode=pCode+""+$1->getValue()+"["+expList+"]";
					//variable_type = tempval->getKeyType();
				}			
			}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 840 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : expression : logic_expression\n"<< endl;
			(yyval.symbolVal)=new SymbolInfo();
			//semantic check			
			//storing semantic value ( logic_expression)
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			
			//considering it both
			// for next term semantic check
			//varG=$1->getValue()+"["+expList+"]";
			//logout<<varG<<endl<<endl;
			//$$->setSaveCode(varG);
			expG=logic_exp;
			logout<<expG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(expG);
			
		}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 858 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : expression : variable ASSIGNOP logic_expression\n"<< endl;
			//semantic check
			string st=(yyvsp[-2].symbolVal)->getKeyType();

			//checking the variable type with the help of keyword
			
			(yyval.symbolVal)=new SymbolInfo();
			//storing semantic value
			(yyval.symbolVal) = (yyvsp[-2].symbolVal);
			//printing the value	
			//table.printAll(logout);	
			expG=(yyvsp[-2].symbolVal)->getValue()+"="+logic_exp;
			logout<<expG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(expG);
			(yyval.symbolVal)->asmcode=(yyvsp[0].symbolVal)->asmcode+(yyvsp[-2].symbolVal)->asmcode;
			(yyval.symbolVal)->asmcode+="mov ax, "+(yyvsp[0].symbolVal)->getValue()+"\n";
			if((yyval.symbolVal)->getKeyword()=="notarray")
			{ 
				(yyval.symbolVal)->asmcode+= "mov "+(yyvsp[-2].symbolVal)->getValue()+", ax\n";
			}
				
			else
			{
				(yyval.symbolVal)->asmcode+= "mov  "+(yyvsp[-2].symbolVal)->getValue()+"[bx], ax\n";
			}
				delete (yyvsp[0].symbolVal);
		}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 889 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				
				//considering it both
				// for next term semantic check
				logic_exp=rel_exp;
				logout<<logic_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(logic_exp);
				//asmout<<$$->asmcode;
				
			}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 905 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
				//ultimate value of this expression will be 0 or 1
				//going to take an object with int keyword
				

				char * lab1=newLabel();
				char * lab2=newLabel();
				char * temp=newPTemp();
				(yyval.symbolVal)=(yyvsp[-2].symbolVal);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
					

				
				string st=(yyvsp[-1].symbolVal)->getValue(); 
				//if the LOGICOP is &&
				if(st=="&&")
				{
					
					logic_exp=(yyvsp[-2].symbolVal)->getValue()+"&&"+(yyvsp[0].symbolVal)->getValue();
					/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
					*/
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov ax , " + (yyvsp[-2].symbolVal)->getValue() +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"cmp ax , 0\n";
				 	(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"je " + string(lab1) +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov ax , " + (yyvsp[0].symbolVal)->getValue() +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"cmp ax , 0\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"je " + string(lab1) +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov " + string(temp) + " , 1\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"jmp " + string(lab2) + "\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +string(lab1) + ":\n" ;
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov " + string(temp) + ", 0\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +string(lab2) + ":\n";
					(yyval.symbolVal)->setValue(temp+to_string(table.scopeNum));
					tempvar.push_back((yyval.symbolVal)->getValue());
				}
				//if the LOGICOP is ||
				else if(st=="||")
				{
					
					logic_exp=(yyvsp[-2].symbolVal)->getValue()+"||"+(yyvsp[0].symbolVal)->getValue();
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov ax , " + (yyvsp[-2].symbolVal)->getValue() +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"cmp ax , 0\n";
				 	(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"jne " + string(lab1) +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov ax , " + (yyvsp[0].symbolVal)->getValue() +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"cmp ax , 0\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"jne " + string(lab1) +"\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov " + string(temp) + " , 0\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"jmp " + string(lab2) + "\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +string(lab1) + ":\n" ;
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +"mov " + string(temp) + ", 1\n";
					(yyval.symbolVal)->asmcode =(yyval.symbolVal)->asmcode +string(lab2) + ":\n";
					(yyval.symbolVal)->setValue(temp);
				}
				//storing the semantic value
				//$$=tempval;
				
				logout<<logic_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(logic_exp);
				delete (yyvsp[0].symbolVal);
			}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 971 "1505044_bison.y" /* yacc.c:1646  */
    {
				
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				 
				//considering it both
				// for next term semantic check
				rel_exp=sim_exp;
				(yyval.symbolVal)->setValue(rel_exp);
				logout<<rel_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(rel_exp);
			
			}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 988 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression RELOP simple_expression\n"<< endl;
				//the ultimate result will be 0 or 1, that's why it's kept as int varaible
				SymbolInfo* tempval=new SymbolInfo("INT");
				string st=(yyvsp[-1].symbolVal)->getValue(); //the relop sign
				string var1=(yyvsp[-2].symbolVal)->getKeyType(); //getting the first simp.expression keyword
				string var2=(yyvsp[0].symbolVal)->getKeyType(); //getting the second simp.expression keyword
				(yyval.symbolVal)=(yyvsp[-2].symbolVal);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, " + (yyvsp[-2].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"cmp ax, " + (yyvsp[0].symbolVal)->getValue()+"\n";
				char *lab1=newLabel();
				char *lab2=newLabel();
				char *temp=newPTemp();
				
				//if the RELOP is ==
				if(st=="==")
				{
					if(var1!=var2) //this doesn't occur error 
					{
						errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					//$$=tempval;
					rel_exp=(yyvsp[-2].symbolVal)->getValue()+"="+(yyvsp[0].symbolVal)->getValue();
					logout<<rel_exp<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(rel_exp);
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"je " + string(lab1)+"\n";
				}
				//if the RELOP is !=
				else if(st=="!=")
				{
					if(var1!=var2) //this doesn't occur error
					{
						errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					
					rel_exp=(yyvsp[-2].symbolVal)->getValue()+"!"+(yyvsp[0].symbolVal)->getValue();
					logout<<rel_exp<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(rel_exp);
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jne "+string(lab1)+"\n";
				}
				//if the RELOP is <= or <
				//both term isn't required to be same keyword
				else if(st=="<"){
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jl "+string(lab1)+"\n";
				}
				else if(st=="<="){
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jle "+string(lab1)+"\n";
				}
				else if(st==">"){
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jg "+string(lab1)+"\n";
				}
				else if(st==">="){
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jge "+string(lab1)+"\n";
				}
				//stored in semantic value
				//$$=tempval;
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp) +", 0\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"jmp "+string(lab2) +"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+string(lab1)+":\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+", 1\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+string(lab2)+":\n";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
				delete (yyvsp[0].symbolVal);
				
			}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1060 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : simple_expression : term\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
			
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				
				//considering it both
				// for next term semantic check
				//logout<<$$->getSaveCode()<< endl<<endl;
				
				sim_exp=termG;
				(yyval.symbolVal)->setValue(sim_exp);
				logout<<sim_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(sim_exp);
			}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1078 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : simple_expression : simple_expression ADDOP term\n"<< endl;
				(yyval.symbolVal)=(yyvsp[-2].symbolVal);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+(yyvsp[0].symbolVal)->asmcode;
				char* temp = newTemp();
				//ADDOP is '+'
				if((yyvsp[-1].symbolVal)->getValue()=="+")
				{
					
					sim_exp=(yyvsp[-2].symbolVal)->getValue()+"+"+(yyvsp[0].symbolVal)->getValue();
					logout<<sim_exp<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(sim_exp);
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"add ax, "+(yyvsp[0].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+" , ax\n";
					(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
					tempvar.push_back((yyval.symbolVal)->getValue());
				}
				//ADDOP is -
				else if((yyvsp[-1].symbolVal)->getValue()=="-")
				{
					
					sim_exp=(yyvsp[-2].symbolVal)->getValue()+"-"+(yyvsp[0].symbolVal)->getValue();
					logout<<sim_exp<<endl<<endl;
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"sub ax, "+(yyvsp[0].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+" , ax\n";
					(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
					tempvar.push_back((yyval.symbolVal)->getValue());
				}
			
				(yyval.symbolVal)->setSaveCode(sim_exp);
				delete (yyvsp[0].symbolVal);
			}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1115 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : term : unary_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			
			//considering it both
			// for next term semantic check
			//logout<<$$->getSaveCode()<< endl<<endl;
			termG=una_exp;
			(yyval.symbolVal)->setValue(termG);
			logout<<termG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(termG);
			//asmout<<$$->asmcode;
		}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1132 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : term : term MULOP unary_expression\n"<< endl;
			(yyval.symbolVal)=(yyvsp[-2].symbolVal);
			char *temp=newTemp();
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+ (yyvsp[0].symbolVal)->asmcode;
			
			//MULOP is *
			if((yyvsp[-1].symbolVal)->getValue()=="*")
			{
					
					
			
				termG=termG+"*"+una_exp;
				(yyval.symbolVal)->setValue(termG);
				logout<<termG<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(termG);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov bx, "+(yyvsp[0].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mul bx\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+ string(temp) + ", ax\n";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
			}
			//MULOP is /
			else if((yyvsp[-1].symbolVal)->getValue()=="/")
			{
				
				termG=termG+"\\"+una_exp;
				logout<<termG<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(termG);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov bx, "+(yyvsp[0].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"xor dx , dx\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"div bx\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+" , ax\n";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
			}
			//MULOP is %
			else if((yyvsp[-1].symbolVal)->getValue()=="%")
			{
				
				termG=termG+"%"+una_exp;
				logout<<termG<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(termG);
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[-2].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov bx, "+(yyvsp[0].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"xor dx , dx\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"div bx\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+" , dx\n";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
			}
			//cout << endl << $$->code << endl;
			delete (yyvsp[0].symbolVal);
		}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1190 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : ADDOP unary_expression\n"<< endl;
				//in this case, only ADDOP - is need
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				if((yyvsp[-1].symbolVal)->getValue()=="-")
				{
					
					una_exp="-"+una_exp;
					logout<<una_exp<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(una_exp);
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[0].symbolVal)->getValue()+"\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"neg ax\n";
					(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+(yyvsp[0].symbolVal)->getValue()+" , ax\n";
				}
				//ultimate value is stored
				//$$=$2;
			
			}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1209 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : NOT unary_expression \n"<< endl;
				
				una_exp="!"+una_exp;
				logout<<una_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(una_exp);
				char *temp=newTemp();
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				(yyval.symbolVal)->asmcode="\tmov ax, "+(yyvsp[0].symbolVal)->getValue()+"\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"not ax\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+", ax";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
			}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1224 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : unary_expression : factor\n"<< endl;
			
				//semantic check			
				//storing semantic value 
				
				
				// for next term semantic check
				//logout<<$$->getSaveCode()<< endl<<endl;
				una_exp=factorG;
				logout<<una_exp<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(una_exp);
				(yyval.symbolVal)=(yyvsp[0].symbolVal);
				//asmout<<$$->asmcode;
			}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1243 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
			//logout<<$$->getSaveCode()<< endl<<endl;
			factorG=varG;
			
			char *temp=newTemp();
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			if((yyval.symbolVal)->getKeyword()=="notarray"){}
			else {
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax, "+(yyvsp[0].symbolVal)->getValue()+"[bx]\n";
				(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+string(temp)+", ax\n";
				(yyval.symbolVal)->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back((yyval.symbolVal)->getValue());
			}
			
			
		}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1263 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : ID LPAREN argument_list RPAREN\n"<< endl;
			//it's for a function call which returns something
			//printing the id
			//logout<<$1->getValue()<<endl;
			//an object is ready for checking
			SymbolInfo *tempval=new SymbolInfo();
			//checking the function name
			tempval=table.lookTable((yyvsp[-3].symbolVal)->getValue(),"FUNC");
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
					
					(yyval.symbolVal)=(yyvsp[-3].symbolVal);
					factorG=(yyvsp[-3].symbolVal)->getValue()+"("+arg_list+")";
					logout<<factorG<<endl<<endl;
					(yyval.symbolVal)->setSaveCode(factorG);
				}
			}
		}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1297 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : LPAREN expression RPAREN\n"<< endl;
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			factorG="("+expG+")";
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
		}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1305 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : CONST_INT\n"<< endl;
			//the number is printed out
			//logout<<$1->getValue()<<endl;
			
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			factorG=(yyvsp[0].symbolVal)->getValue();
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
			//asmout<<$$->asmcode;
			
		}
#line 2879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1318 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<<" : factor : CONST_FLOAT\n";
			//the number is printed out
			//logout<<$1->getValue()<<endl;
			
			(yyval.symbolVal)=(yyvsp[0].symbolVal);
			//logout <<"AT CONST_FLOAT , value" <<  $$->floatstore[0]<< " Type = " << $$->getKeyType() << endl;
			factorG=(yyvsp[0].symbolVal)->getValue();
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
		}
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1331 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable INCOP\n"<< endl;
			//value can be array or variable
			
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			factorG=varG+"++";
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax , "+(yyval.symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"add ax , 1\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov "+(yyval.symbolVal)->getValue()+" , ax\n";
		}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1344 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : factor : variable DECOP\n"<< endl;
			//value can be array or variable
			
			
			(yyval.symbolVal)=(yyvsp[-1].symbolVal);
			factorG=varG+"--";
			logout<<factorG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(factorG);
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov ax , "+(yyval.symbolVal)->getValue()+"\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"sub ax , 1\n";
			(yyval.symbolVal)->asmcode=(yyval.symbolVal)->asmcode+"mov " +(yyval.symbolVal)->getValue()+" , ax\n";
		}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1360 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : argument_list : arguments\n"<< endl;
				arg_list=argG;
				logout<<arg_list<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(arg_list);
			}
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1370 "1505044_bison.y" /* yacc.c:1646  */
    {
			logout<<"At line "<<line_count<< " : arguments : arguments COMMA logic_expression\n"<< endl;
			argG=argG+","+logic_exp;
			logout<<argG<<endl<<endl;
			(yyval.symbolVal)->setSaveCode(argG);
		}
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1377 "1505044_bison.y" /* yacc.c:1646  */
    {
				logout<<"At line "<<line_count<< " : arguments : logic_expression\n"<< endl;
				argG=logic_exp;
				logout<<argG<<endl<<endl;
				(yyval.symbolVal)->setSaveCode(argG);
			}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2967 "y.tab.c" /* yacc.c:1646  */
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
#line 1386 "1505044_bison.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{

	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	

	logout.open("1505044_log.txt");
	errorout.open("1505044_errors.txt");
	asmout.open("code.asm");
	
	yyparse();
	
	logout<<"Total Lines : "<<line_count<<endl; 
	//logFile << "Total Errors : " << semErrors << endl;
	logout.close();
	errorout.close();
	asmout.close();

	return 0;
}

