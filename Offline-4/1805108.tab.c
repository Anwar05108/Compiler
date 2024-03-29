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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1805108.y"

#include<stdio.h>
#include<string.h>
#include"SymbolTable.cpp"
#include<fstream>
#include<iostream>
#include<bits/stdc++.h>

struct nodeVar{
    string name;
    string type;
    int arraySize;
}tempNodeVar;
int lineCount = 1;
int errorCount = 0;
int tempCount = 0;
int labelCount = 0;
vector<nodeVar> var_list_asm;

string newTemp(){
    stringstream ss;
    ss << "temp_" << tempCount++;
    nodeVar temp;
    temp.name = ss.str();
    temp.type = "int";
    temp.arraySize = 0;
    var_list_asm.push_back(temp);
    return ss.str();
}

string newLabel(){
    stringstream ss;
    ss << "label_" << labelCount++;
    return ss.str();
}

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}




struct nodeParam{
    string name;
    string type;
}tempNodeParam;


vector<nodeVar> variable_list;
vector<nodeParam> parameter_list;
vector<nodeVar> parameter_list_asm;

SymbolTable symbolTable(30);

// FILE *errorFile, *logFile;
ofstream errorFile, logFile,asmFile;

extern FILE *yyin;
// extern ifstream yyin;

int yyparse(void);
int yylex(void);

void yyerror(const char* str) {
}
    

#line 151 "1805108.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    VOID = 258,                    /* VOID  */
    NEWLINE = 259,                 /* NEWLINE  */
    NUMBER = 260,                  /* NUMBER  */
    LESS = 261,                    /* LESS  */
    GREATER = 262,                 /* GREATER  */
    EQUAL = 263,                   /* EQUAL  */
    IF = 264,                      /* IF  */
    FOR = 265,                     /* FOR  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    BREAK = 268,                   /* BREAK  */
    CONTINUE = 269,                /* CONTINUE  */
    CASE = 270,                    /* CASE  */
    DEFAULT = 271,                 /* DEFAULT  */
    SWITCH = 272,                  /* SWITCH  */
    DO = 273,                      /* DO  */
    RETURN = 274,                  /* RETURN  */
    INCOP = 275,                   /* INCOP  */
    DECOP = 276,                   /* DECOP  */
    ASSIGNOP = 277,                /* ASSIGNOP  */
    LOGICNOT = 278,                /* LOGICNOT  */
    NOT = 279,                     /* NOT  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    LCURL = 282,                   /* LCURL  */
    RCURL = 283,                   /* RCURL  */
    LTHIRD = 284,                  /* LTHIRD  */
    RTHIRD = 285,                  /* RTHIRD  */
    COMMA = 286,                   /* COMMA  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COLON = 288,                   /* COLON  */
    PRINTLN = 289,                 /* PRINTLN  */
    INT = 290,                     /* INT  */
    FLOAT = 291,                   /* FLOAT  */
    DOUBLE = 292,                  /* DOUBLE  */
    CHAR = 293,                    /* CHAR  */
    PLUS = 294,                    /* PLUS  */
    MINUS = 295,                   /* MINUS  */
    SLASH = 296,                   /* SLASH  */
    ASTERISK = 297,                /* ASTERISK  */
    ADDOP = 298,                   /* ADDOP  */
    MULOP = 299,                   /* MULOP  */
    RELOP = 300,                   /* RELOP  */
    BITOP = 301,                   /* BITOP  */
    LOGICOP = 302,                 /* LOGICOP  */
    ID = 303,                      /* ID  */
    CONST_CHAR = 304,              /* CONST_CHAR  */
    CONST_INT = 305,               /* CONST_INT  */
    CONST_FLOAT = 306,             /* CONST_FLOAT  */
    LOWER_THAN_ELSE = 307          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "1805108.y"

    SymbolInfo *symbolInfo;

#line 257 "1805108.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_LESS = 6,                       /* LESS  */
  YYSYMBOL_GREATER = 7,                    /* GREATER  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_DEFAULT = 16,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_INCOP = 20,                     /* INCOP  */
  YYSYMBOL_DECOP = 21,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 22,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICNOT = 23,                  /* LOGICNOT  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LCURL = 27,                     /* LCURL  */
  YYSYMBOL_RCURL = 28,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 29,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 30,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 33,                     /* COLON  */
  YYSYMBOL_PRINTLN = 34,                   /* PRINTLN  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_FLOAT = 36,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 37,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 38,                      /* CHAR  */
  YYSYMBOL_PLUS = 39,                      /* PLUS  */
  YYSYMBOL_MINUS = 40,                     /* MINUS  */
  YYSYMBOL_SLASH = 41,                     /* SLASH  */
  YYSYMBOL_ASTERISK = 42,                  /* ASTERISK  */
  YYSYMBOL_ADDOP = 43,                     /* ADDOP  */
  YYSYMBOL_MULOP = 44,                     /* MULOP  */
  YYSYMBOL_RELOP = 45,                     /* RELOP  */
  YYSYMBOL_BITOP = 46,                     /* BITOP  */
  YYSYMBOL_LOGICOP = 47,                   /* LOGICOP  */
  YYSYMBOL_ID = 48,                        /* ID  */
  YYSYMBOL_CONST_CHAR = 49,                /* CONST_CHAR  */
  YYSYMBOL_CONST_INT = 50,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 51,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 52,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_start = 54,                     /* start  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_unit = 56,                      /* unit  */
  YYSYMBOL_function_declaration = 57,      /* function_declaration  */
  YYSYMBOL_function_definition = 58,       /* function_definition  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_compound_statement = 62,        /* compound_statement  */
  YYSYMBOL_variable_declaration = 63,      /* variable_declaration  */
  YYSYMBOL_type_specifier = 64,            /* type_specifier  */
  YYSYMBOL_declaration_list = 65,          /* declaration_list  */
  YYSYMBOL_statement_list = 66,            /* statement_list  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_expression_statement = 69,      /* expression_statement  */
  YYSYMBOL_variable = 70,                  /* variable  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_logic_expression = 72,          /* logic_expression  */
  YYSYMBOL_rel_expression = 73,            /* rel_expression  */
  YYSYMBOL_simple_expression = 74,         /* simple_expression  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_unary_expression = 76,          /* unary_expression  */
  YYSYMBOL_factor = 77,                    /* factor  */
  YYSYMBOL_argument_list = 78,             /* argument_list  */
  YYSYMBOL_arguments = 79                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   215,   222,   232,   240,   247,   257,   309,
     344,   342,   494,   493,   569,   581,   593,   604,   624,   635,
     643,   695,   703,   711,   719,   734,   752,   769,   792,   815,
     822,   832,   840,   847,   847,   854,   898,   926,   946,   971,
     988,  1026,  1031,  1043,  1059,  1109,  1116,  1192,  1198,  1263,
    1270,  1326,  1332,  1378,  1384,  1465,  1491,  1521,  1531,  1538,
    1630,  1639,  1647,  1656,  1676,  1701,  1708,  1717,  1727
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "NEWLINE",
  "NUMBER", "LESS", "GREATER", "EQUAL", "IF", "FOR", "ELSE", "WHILE",
  "BREAK", "CONTINUE", "CASE", "DEFAULT", "SWITCH", "DO", "RETURN",
  "INCOP", "DECOP", "ASSIGNOP", "LOGICNOT", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "COLON",
  "PRINTLN", "INT", "FLOAT", "DOUBLE", "CHAR", "PLUS", "MINUS", "SLASH",
  "ASTERISK", "ADDOP", "MULOP", "RELOP", "BITOP", "LOGICOP", "ID",
  "CONST_CHAR", "CONST_INT", "CONST_FLOAT", "LOWER_THAN_ELSE", "$accept",
  "start", "program", "unit", "function_declaration",
  "function_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "variable_declaration", "type_specifier",
  "declaration_list", "statement_list", "statement", "$@3",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      14,   -76,   -76,   -76,   -76,    23,    14,   -76,   -76,   -76,
     -76,   -22,   -76,   -76,    -5,    43,     5,   -21,   -15,   -76,
       7,   -12,   -11,    26,    29,   -76,    35,    28,    14,   -76,
     -76,    15,    54,   -76,   -76,    35,    20,    40,    55,    58,
      59,   118,   118,   118,   -76,   -76,    60,   118,    -4,   -76,
     -76,   -76,    44,    84,   -76,    35,   -76,    33,    49,   -76,
      48,   -30,    57,   -76,   -76,   -76,   -76,   -76,   118,   104,
     118,    66,    56,   -76,    73,    52,   -76,   118,   118,    77,
     -76,   -76,   -76,   -76,   -76,   118,   -76,   118,   118,   118,
     118,    81,   104,    85,   -76,   -76,    87,   -76,    88,    79,
      92,   -76,   -76,    57,    72,   -76,   114,   118,   114,    93,
     -76,   118,   -76,   119,   105,   -76,   -76,   -76,   114,   114,
     -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    24,    21,    22,    23,     0,     2,     4,     6,     7,
       5,     0,     1,     3,    27,     0,     0,     0,     0,    20,
      12,     0,    17,     0,    25,     9,     0,    10,     0,    16,
      28,     0,    33,    13,     8,     0,    15,     0,     0,     0,
       0,     0,     0,     0,    19,    41,     0,     0,    43,    61,
      62,    31,     0,    33,    29,     0,    32,    58,     0,    45,
      47,    49,    51,    53,    57,    11,    14,    26,     0,     0,
       0,     0,    58,    56,     0,     0,    55,    66,     0,    27,
      18,    30,    34,    63,    64,     0,    42,     0,     0,     0,
       0,     0,     0,     0,    39,    60,     0,    68,     0,    65,
       0,    46,    48,    52,    50,    54,    33,     0,    33,     0,
      59,     0,    44,    37,     0,    36,    40,    67,    33,    33,
      38,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   131,   -76,   -76,   -76,   -76,   -76,   -28,
      12,    16,   -76,   -76,   -47,   -76,   -58,   -42,   -40,   -75,
      53,    64,    68,   -38,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    35,    26,    21,    33,
      51,    52,    15,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    98,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    71,    97,    74,    73,    72,    81,    65,     1,    76,
     101,    92,    10,    88,    27,    89,    11,     1,    10,    28,
      16,    77,    11,    12,    17,    78,    14,    82,    91,    23,
      93,    20,    22,    24,   107,    72,   117,    29,   100,    25,
       2,     3,     4,    72,    36,    72,    72,    72,    72,     2,
       3,     4,   105,    83,    84,    85,    30,     1,    31,   113,
      34,   115,    32,    38,    39,    37,    40,   114,    66,    72,
      67,   120,   121,    41,    18,    19,    83,    84,    42,    43,
      68,    86,    44,    69,    70,    75,    45,     1,    46,     2,
       3,     4,    79,    38,    39,    87,    40,    47,    94,    95,
      96,    90,    48,    41,    49,    50,    17,   106,    42,    43,
     111,   108,    80,   109,   110,    88,    45,     1,    46,     2,
       3,     4,   112,    38,    39,   116,    40,    47,    42,    43,
     118,   119,    48,    41,    49,    50,    45,    13,    42,    43,
     102,     0,    42,    43,     0,     0,    45,    47,    46,     2,
       3,     4,    48,   104,    49,    50,   103,    47,     0,     0,
       0,    47,    48,     0,    49,    50,    48,     0,    49,    50
};

static const yytype_int8 yycheck[] =
{
      42,    41,    77,    43,    42,    47,    53,    35,     3,    47,
      85,    69,     0,    43,    26,    45,     0,     3,     6,    31,
      25,    25,     6,     0,    29,    29,    48,    55,    68,    50,
      70,    26,    16,    48,    92,    77,   111,    48,    78,    32,
      35,    36,    37,    85,    28,    87,    88,    89,    90,    35,
      36,    37,    90,    20,    21,    22,    30,     3,    29,   106,
      32,   108,    27,     9,    10,    50,    12,   107,    48,   111,
      30,   118,   119,    19,    31,    32,    20,    21,    24,    25,
      25,    32,    28,    25,    25,    25,    32,     3,    34,    35,
      36,    37,    48,     9,    10,    47,    12,    43,    32,    26,
      48,    44,    48,    19,    50,    51,    29,    26,    24,    25,
      31,    26,    28,    26,    26,    43,    32,     3,    34,    35,
      36,    37,    30,     9,    10,    32,    12,    43,    24,    25,
      11,    26,    48,    19,    50,    51,    32,     6,    24,    25,
      87,    -1,    24,    25,    -1,    -1,    32,    43,    34,    35,
      36,    37,    48,    89,    50,    51,    88,    43,    -1,    -1,
      -1,    43,    48,    -1,    50,    51,    48,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,    36,    37,    54,    55,    56,    57,    58,
      63,    64,     0,    56,    48,    65,    25,    29,    31,    32,
      26,    61,    64,    50,    48,    32,    60,    26,    31,    48,
      30,    29,    27,    62,    32,    59,    64,    50,     9,    10,
      12,    19,    24,    25,    28,    32,    34,    43,    48,    50,
      51,    63,    64,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    62,    48,    30,    25,    25,
      25,    71,    70,    76,    71,    25,    76,    25,    29,    48,
      28,    67,    62,    20,    21,    22,    32,    47,    43,    45,
      44,    71,    69,    71,    32,    26,    48,    72,    78,    79,
      71,    72,    73,    75,    74,    76,    26,    69,    26,    26,
      26,    31,    30,    67,    71,    67,    32,    72,    11,    26,
      67,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    57,
      59,    58,    60,    58,    61,    61,    61,    61,    62,    62,
      63,    64,    64,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    67,    67,    67,    67,    67,    67,
      67,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     3,     2,
       3,     1,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     0,     2,     7,     5,     5,     7,     3,
       5,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 125 "1805108.y"
    {
     (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
     logFile << "line number" << lineCount << ": " ;
     asmFile << ".model small\n";
     asmFile << ".stack 100h\n\n";
    asmFile << ".data\n\n";
    asmFile << "print_var dw ?\n";

    for(int i = 0; i < var_list_asm.size(); i++){
        if(var_list_asm[i].arraySize == 0 || var_list_asm[i].arraySize == -1){
            asmFile << var_list_asm[i].name << " dw ?\n";
        }
        else{
            asmFile << var_list_asm[i].name << " dw "+ to_string(var_list_asm[i].arraySize)+"\n";
        }
    }

    // for(int i = 0; i < parameter_list_asm.size(); i++){
        
    //         asmFile << parameter_list_asm[i].name << " dw ?\n";
       
    // }
    // for(int i = )

    asmFile << ".code\n\n";

    asmFile << "println proc near\n";
    asmFile << "\tpush ax\n";
    asmFile << "\tpush bx\n";
    asmFile << "\tpush cx\n";
    asmFile << "\tpush dx\n\n";
    // asmFIle << ""

    asmFile << "\tmov ax, print_var\n";
    asmFile << "\tor ax, ax\n";
    asmFile << "\tjge end_if_1\n";
    asmFile << "\tpush ax\n";
    asmFile << "\tmov dl, '-'\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n";
    asmFile << "\tpop ax\n";
    asmFile << "\tneg ax\n\n";
    
    asmFile << "end_if_1:\n";
    asmFile << "\txor cx,cx\n";
    asmFile << "\tmov bx,10d\n\n";

    asmFile << "loop_1:\n";
    asmFile << "\txor dx, dx\n";
    asmFile << "\tdiv bx\n";
    asmFile << "\tpush dx\n";
    asmFile << "\tinc cx\n";
    asmFile << "\tor ax,ax\n";
    asmFile << "\tjne loop_1\n";
    asmFile << "\tmov ah, 2\n\n";

    asmFile << "loop_2:\n";
    asmFile << "\tpop dx\n";
    asmFile << "\tor dl, 30h\n";
    asmFile << "\tint 21h\n";
    asmFile << "\tloop loop_2\n\n";
    
    asmFile << "\tmov dl, 0dh\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n\n";

    asmFile << "\tmov dl, 0ah\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n\n";

    asmFile << "\tpop dx\n";
    asmFile << "\tpop cx\n";
    asmFile << "\tpop bx\n";
    asmFile << "\tpop ax\n";

    asmFile << "\tret\n\n";
    asmFile << "println endp\n\n";

    // asmFile << 
    asmFile << (yyval.symbolInfo)->getAsmCodes();
    logFile << (yyval.symbolInfo)->getAsmCodes() << endl;
    

    logFile << "start: program" << endl;
    // symbolTable.printAllScopes();
    
    }
#line 1765 "1805108.tab.c"
    break;

  case 3: /* program: program unit  */
#line 216 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo( (yyvsp[-1].symbolInfo)->getName() +"\n" +(yyvsp[0].symbolInfo)->getName(),"SYMBOL_PROGRAM");
            (yyval.symbolInfo) -> setAsmCodes((yyvsp[-1].symbolInfo)->getAsmCodes() + (yyvsp[0].symbolInfo)->getAsmCodes());
            logFile << "line number" << lineCount << ": " ;
            logFile << "program: program unit \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1776 "1805108.tab.c"
    break;

  case 4: /* program: unit  */
#line 223 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "program:  unit \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1786 "1805108.tab.c"
    break;

  case 5: /* unit: variable_declaration  */
#line 233 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: variable_declaration \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
        // symbolTable.printAllScopesInFile(logFile);

        }
#line 1798 "1805108.tab.c"
    break;

  case 6: /* unit: function_declaration  */
#line 241 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_declaration \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;

        }
#line 1809 "1805108.tab.c"
    break;

  case 7: /* unit: function_definition  */
#line 248 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_definition \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;


        }
#line 1821 "1805108.tab.c"
    break;

  case 8: /* function_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 258 "1805108.y"
                        {
                        
                      (yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName()+" "+ (yyvsp[-4].symbolInfo)->getName()+"("+(yyvsp[-2].symbolInfo)->getName()+");", "function_declaration");
                        string functionName = (yyvsp[-4].symbolInfo)->getName();
                        string functionType = (yyvsp[-5].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            (yyval.symbolInfo)->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << (yyval.symbolInfo)->getName();
                        logFile << endl << endl;

                        SymbolInfo *temp = symbolTable.search(functionName);
                        if(temp == NULL)
                        {
                            errorFile<<"error: function "<<functionName<<" not found\n";
                        }
                        else
                        {
                            temp->setDefined(false);
                            temp->setArraySize(-2);

                        for(int i = 0; i < parameter_list.size(); i++)
                        {
                            string parameterName = parameter_list[i].name;
                            string parameterType = parameter_list[i].type;
                                    // parameter_list_asm.push_back(parameter_list[i]);
                            // cout << "parameter_list_asm:"<<parameter_list_asm[i].name<<endl;

                            temp->insertParameter(parameterName, parameterType);
                        }
                        }

                      
                       
                        parameter_list.clear();
                        
                        }
#line 1877 "1805108.tab.c"
    break;

  case 9: /* function_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 310 "1805108.y"
                    {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-4].symbolInfo)->getName()+" "+ (yyvsp[-3].symbolInfo)->getName()+"();", "SYMBOL_FUNCTION");
                        string functionName = (yyvsp[-3].symbolInfo)->getName();
                        string functionType = (yyvsp[-4].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setDefined(false);
                            temp->setArraySize(-2);
                            // $$->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        parameter_list.clear();
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << (yyval.symbolInfo)->getName();
                        logFile << endl << endl;

                        }
#line 1911 "1805108.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 344 "1805108.y"
                        {
                        string functionName = (yyvsp[-3].symbolInfo)->getName();
                        string functionType = (yyvsp[-4].symbolInfo)->getName();
                        SymbolInfo* function = symbolTable.search(functionName);
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setArraySize(-2);
                            temp->setDefined(true);
                            // $$->setDefined(true);
                            symbolTable.enterScope(30);
                            // logFile << "size of parameter list: " << parameter_list.size() << endl;
                            for(int i = 0; i < parameter_list.size(); i++)
                            {
                                // logFile << "parameter_list: " << parameter_list[i].name << " " << parameter_list[i].type << endl;
                                string parameterName = parameter_list[i].name;
                                string parameterType = parameter_list[i].type;
                            tempNodeVar.name = parameterName + (symbolTable.getScopeTable())->getShowId();
                                parameter_list_asm.push_back(tempNodeVar);
                                cout << "parameter_list_asm:"<<parameter_list_asm[i].name<<endl;
                                symbolTable.insert(parameterName, parameterType);
                                 SymbolInfo *symbolInfo = symbolTable.search(parameterName);
                            string global_name = tempNodeVar.name;
                            var_list_asm.push_back(tempNodeVar);
                            symbolInfo->setAsmName(global_name);
                            }
                        }
                        else
                        {
                            if(function->getDefined() == false)
                            {
                                symbolTable.insert(functionName, functionType);
                                 function->setArraySize(-2);
                            function->setDefined(true);
                                // $$->setDefined(true);
                            }
                            else
                            {
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "line number" << lineCount << ": " ;
                                
                                errorFile << "error: function "<<functionName<<" already defined\n";
                            }
                        

                        SymbolInfo *temp = symbolTable.search(functionName);
                       symbolTable.enterScope(30);

                       if(temp != NULL){

                        for(int i = 0; i < temp->getParamSize(); i++ ){
                            string declaredParameterName = temp->getParameterName(i);
                            string declaredParameterType = temp->getParameterType(i);                                                 
                            string definedParameterName = parameter_list[i].name;
                            string definedParameterType = parameter_list[i].type;
                            if(declaredParameterType != definedParameterType ){
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n\n";
                                errorFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n";
                            }else{
                             symbolTable.insert(definedParameterName, definedParameterType);
                             
                            }
                            SymbolInfo *symbolInfo = symbolTable.search(definedParameterName);
                            tempNodeVar.name = definedParameterName + (symbolTable.getScopeTable())->getShowId();
                            string global_name = tempNodeVar.name;
                            parameter_list_asm.push_back(tempNodeVar);
                            var_list_asm.push_back(tempNodeVar);
                            symbolInfo->setAsmName(global_name);
                            cout << "----------------------------"<<global_name<<endl;

                        }}
                    }
                        // symbolTable.printAllScopesInFile(logFile);
                        // logFile<<"enterScope";
                        string parameter_code = "";
                        for(int i = 0; i < parameter_list_asm.size(); i++)
                        {
                            parameter_code += "\tpop" + parameter_list_asm[i].name ;
                        }
                        // parameter_list.clear();
                        // logFile << "line number" << lineCount << ": " ;
                        // logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        // logFile <<$$->getName()<< endl<<endl;
                        


                        }
#line 2008 "1805108.tab.c"
    break;

  case 11: /* function_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 436 "1805108.y"
                                          {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-6].symbolInfo)->getName()+" "+(yyvsp[-5].symbolInfo)->getName()+" ( " +(yyvsp[-3].symbolInfo)->getName()+" ) "+(yyvsp[0].symbolInfo)->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = (yyvsp[-5].symbolInfo)->getName();
                        cout << "functionName: " << functionName << endl;
                        string functionType = (yyvsp[-6].symbolInfo)->getName();
                        string asmCodes = "";
                        asmCodes += "; function definition\n";
                        SymbolInfo* function = symbolTable.search(functionName);
                        cout << function;
                        if(function != NULL){
                            if(functionName == "main"){
                                asmCodes    +=   "MAIN PROC\n";
                                asmCodes   += "MOV AX, @DATA\n";
                                asmCodes   += "MOV DS, AX\n";
                                // asmCodes   += "MOV AX, @BSS\n";

                                asmCodes = (yyvsp[0].symbolInfo)->getAsmCodes();
                                asmCodes += "\tMOV AX, 4C00h\n";
                                asmCodes += "\tINT 21h\n";
                                asmCodes += "MAIN ENDP\n";
                                asmCodes += "END MAIN\n";





                            }
                            else{
                                asmCodes    += functionName+ " PROC "+"\n";
                                asmCodes += "\tPOP BP\n";
                                // asmCodes += paramete recieved code
                                for(int i = parameter_list_asm.size()-1; i >= 0; i--)
                                {
                                    asmCodes += "\tPOP " + parameter_list_asm[i].name + "\n";
                                }
                                parameter_list_asm.clear();
                                // asmCodes += parameter_code;
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += (yyvsp[0].symbolInfo)->getAsmCodes();
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += "\tRET\n";
                                asmCodes += functionName+ " ENDP\n";
                                
                                
                            }
                        }
                                parameter_list.clear();
                                (yyval.symbolInfo)->setAsmCodes(asmCodes);
                                // asmFile << $$->getAsmCodes();
                                // asmFile << endl;
                                // asmFile << asmCodes;

                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        logFile <<(yyval.symbolInfo)->getName()<< endl<<endl;
                        }
#line 2069 "1805108.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 494 "1805108.y"
                    {
                        string functionName = (yyvsp[-2].symbolInfo)->getName();
                        string functionType = (yyvsp[-3].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {

                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setDefined(false);
                            temp->setArraySize(-2);

                        }
                        else
                        {
                                if(symbolTable.search(functionName)->getDefined() == false)
                                {
                                    symbolTable.insert(functionName, functionType);
                                    SymbolInfo *temp = symbolTable.search(functionName);
                                    temp->setDefined(false);
                                    temp->setArraySize(-2);
                                }
                                else
                                {
                                    errorCount++;
                                    logFile << "line number" << lineCount << ": " ;
                                    logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "line number" << lineCount << ": " ;

                                    errorFile << "error: function "<<functionName<<" already defined\n";
                                }
                        }
                        symbolTable.enterScope(30);
                        
                    }
#line 2108 "1805108.tab.c"
    break;

  case 13: /* function_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 528 "1805108.y"
                                      {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName()+" "+(yyvsp[-4].symbolInfo)->getName()+" ( ) "+(yyvsp[0].symbolInfo)->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = (yyvsp[-4].symbolInfo)->getName();
                        string asmCodes = "";
                        SymbolInfo* function = symbolTable.search(functionName);
                        
                            if(functionName == "main"){
                                asmCodes    +=   "MAIN PROC\n";
                                asmCodes   += "MOV AX, @DATA\n";
                                asmCodes   += "MOV DS, AX\n";
                                // asmCodes   += "MOV AX, @BSS\n";
                                asmCodes += (yyvsp[0].symbolInfo)->getAsmCodes();
                                asmCodes += "MOV AX, 4C00h\n";
                                asmCodes += "INT 21h\n";
                                asmCodes += "MAIN ENDP\n";
                                asmCodes += "END MAIN\n";

                            }
                            else{
                                asmCodes    += functionName+ " PROC "+"\n";
                                asmCodes += "\tPOP BP\n";
                                // asmCodes += paramete recieved code
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += (yyvsp[0].symbolInfo)->getAsmCodes();
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += "\tRET\n";
                                asmCodes += functionName+ " ENDP\n";
                                
                                
                            }

                            (yyval.symbolInfo)->setAsmCodes(asmCodes);
                            
                        
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl<<endl;
                        logFile <<(yyval.symbolInfo)->getName()<< endl<<endl;
                    }
#line 2151 "1805108.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 571 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName() + "," + (yyvsp[-1].symbolInfo)->getName() + " " + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier ID"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = (yyvsp[0].symbolInfo)->getName();
                    tempNodeParam.type = (yyvsp[-1].symbolInfo)->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 2166 "1805108.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 582 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + "," + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = "";
                    tempNodeParam.type = (yyvsp[0].symbolInfo)->getName();
                    parameter_list.push_back(tempNodeParam);


                    }
#line 2182 "1805108.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 594 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName() + " " + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier ID"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = (yyvsp[0].symbolInfo)->getName();
                    tempNodeParam.type = (yyvsp[-1].symbolInfo)->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 2197 "1805108.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 605 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

                    tempNodeParam.name = "";
                    tempNodeParam.type = (yyvsp[0].symbolInfo)->getType();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 2213 "1805108.tab.c"
    break;

  case 18: /* compound_statement: LCURL statement_list RCURL  */
#line 624 "1805108.y"
                                               {
    (yyval.symbolInfo) = new SymbolInfo("{\n"+(yyvsp[-1].symbolInfo)->getName()+"\n}", "SYMBOL_COMPOUND_STATEMENT");
    (yyval.symbolInfo)->setAsmCodes((yyvsp[-1].symbolInfo)->getAsmCodes());
    // $$->setAsmName($2->getAsmName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL statement_list RCURL"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
    symbolTable.printAllScopesInFile(logFile);
    symbolTable.exitScope();
    
}
#line 2229 "1805108.tab.c"
    break;

  case 19: /* compound_statement: LCURL RCURL  */
#line 635 "1805108.y"
              {
    (yyval.symbolInfo) = new SymbolInfo("{\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL RCURL"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2240 "1805108.tab.c"
    break;

  case 20: /* variable_declaration: type_specifier declaration_list SEMICOLON  */
#line 644 "1805108.y"
                        {

                            string variable_name = (yyvsp[-1].symbolInfo)->getName();
                            string variable_type = (yyvsp[-2].symbolInfo)->getName();
                            if(variable_type == "void"){
                                errorCount++;
                                errorFile << "line number" << lineCount << ": " ;
                                errorFile << "variable_declaration: void type is not allowed" << endl;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "variable_declaration: void type is not allowed" << endl;
                            }
                            else{
                                cout << "#####" << endl;
                                for(int i = 0;i < variable_list.size();i++){
                                    symbolTable.insert(variable_list[i].name, (yyvsp[-2].symbolInfo)->getName());
                                    tempNodeVar.name = variable_list[i].name + (symbolTable.getScopeTable())->getShowId();
                                    var_list_asm.push_back(tempNodeVar);
                                    string global_name = var_list_asm[i].name ;
                                    // + (symbolTable.getScopeTable())->getShowId();
                                        SymbolInfo *temp = symbolTable.search(variable_list[i].name);
                                    if(variable_list[i].arraySize > 0){
                                        if(temp != NULL){
                                            temp->setArraySize(variable_list[i].arraySize);
                                        }
                                        // temp->setArraySize(variable_list[i].arraySize);
                                        logFile << "array size of " << variable_list[i].name << " is " << temp->getArraySize() << endl;
                                    }
                                   
                                        if(temp != NULL){
                                            cout << global_name << endl;
                                            temp->setAsmName(global_name);
                                            cout << "temp-getAsm"<<temp->getAsmName() << endl;
                                            // cout 
                                        }
                                   
                                   
                                }
                            }

                            variable_list.clear();

                       
                        
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + " " +(yyvsp[-1].symbolInfo)->getName()+";", (yyvsp[-2].symbolInfo)->getType());
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;

                        }
#line 2293 "1805108.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 696 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("int", "int");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : INT"<<endl<<endl ;
                logFile << (yyval.symbolInfo)->getName() << endl<<endl;

                }
#line 2305 "1805108.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 704 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("float", "float");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : FLOAT"<<endl<<endl ;
                logFile << (yyval.symbolInfo)->getName() << endl<<endl;

                }
#line 2317 "1805108.tab.c"
    break;

  case 23: /* type_specifier: DOUBLE  */
#line 712 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("double", "double");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : DOUBLE"<<endl<<endl ;
                logFile << (yyval.symbolInfo)->getName() << endl<<endl;

                }
#line 2329 "1805108.tab.c"
    break;

  case 24: /* type_specifier: VOID  */
#line 720 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("void", "VOID");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : VOID"<<endl<<endl ;
                logFile << (yyval.symbolInfo)->getName() << endl<<endl;

                }
#line 2341 "1805108.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID  */
#line 736 "1805108.y"
            {
(yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + "," +(yyvsp[0].symbolInfo)->getName(), (yyvsp[0].symbolInfo)->getType());
   tempNodeVar.name = (yyvsp[0].symbolInfo)->getName();
    tempNodeVar.type = (yyvsp[0].symbolInfo)->getType();
    tempNodeVar.arraySize = -1;
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[0].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[0].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2362 "1805108.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 753 "1805108.y"
{
(yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName() + "," +(yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].symbolInfo)->getName()+"]", (yyvsp[-3].symbolInfo)->getType());
    tempNodeVar.name = (yyvsp[-3].symbolInfo)->getName();
    tempNodeVar.type = "array";

    tempNodeVar.arraySize = stoi((yyvsp[-1].symbolInfo)->getName());
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[-3].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID LTHIRD CONST INT RTHIRD \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2383 "1805108.tab.c"
    break;

  case 27: /* declaration_list: ID  */
#line 770 "1805108.y"
{
(yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), (yyvsp[0].symbolInfo)->getType());
    tempNodeVar.name = (yyvsp[0].symbolInfo)->getName();
    (yyval.symbolInfo)->setAsmName((yyvsp[0].symbolInfo)->getAsmName());
    // SymbolInfo *temp; 
    // temp = symbolTable.search($1->getName());
    string type = "";
    //  type =  temp->getType();
    tempNodeVar.type = type;
    tempNodeVar.arraySize = -1;
        variable_list.push_back(tempNodeVar);
    // SymbolInfo *temp = symbolTable.search($1->getName());
    // temp ->setAsmName($1->getAsmName());
    if(symbolTable.search((yyvsp[0].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[0].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2410 "1805108.tab.c"
    break;

  case 28: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 792 "1805108.y"
                            {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName() + " [" + (yyvsp[-1].symbolInfo)->getName()+"]", (yyvsp[-3].symbolInfo)->getType());
    tempNodeVar.name = (yyvsp[-3].symbolInfo)->getName();
    tempNodeVar.type = "array";
    tempNodeVar.arraySize = stoi((yyvsp[-1].symbolInfo)->getName());
    

    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[-3].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }

   
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID LTHIRD CONST INT RTHIRD \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2435 "1805108.tab.c"
    break;

  case 29: /* statement_list: statement  */
#line 816 "1805108.y"
                    {
                    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    }
#line 2446 "1805108.tab.c"
    break;

  case 30: /* statement_list: statement_list statement  */
#line 823 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName() + "\n" + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_STATEMENT_LIST");
                    (yyval.symbolInfo)->setAsmCodes((yyvsp[-1].symbolInfo)->getAsmCodes() + (yyvsp[0].symbolInfo)->getAsmCodes());
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement_list statement"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    }
#line 2458 "1805108.tab.c"
    break;

  case 31: /* statement: variable_declaration  */
#line 833 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : variable_declaration"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

            }
#line 2470 "1805108.tab.c"
    break;

  case 32: /* statement: expression_statement  */
#line 841 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : expression_statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2481 "1805108.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 847 "1805108.y"
          {symbolTable.enterScope(30);}
#line 2487 "1805108.tab.c"
    break;

  case 34: /* statement: $@3 compound_statement  */
#line 848 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : compound_statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2498 "1805108.tab.c"
    break;

  case 35: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 856 "1805108.y"
    {
    (yyval.symbolInfo) = new SymbolInfo("for("+(yyvsp[-4].symbolInfo)->getName()+(yyvsp[-3].symbolInfo)->getName()+")"+(yyvsp[-2].symbolInfo)->getName(), "SYMBOL_FOR_STATEMENT");
    string asmCodes = "";
    asmCodes += ";for loop\n";
    string initCode = (yyvsp[-4].symbolInfo)->getAsmCodes();
    string conditonAsm = (yyvsp[-3].symbolInfo) -> getAsmName();
    string conditionCode = (yyvsp[-3].symbolInfo) -> getAsmCodes();
    string incrementCode = (yyvsp[-2].symbolInfo) -> getAsmCodes();
    string bodyCode = (yyvsp[0].symbolInfo) -> getAsmCodes();
    // cout << $7 -> getType() << endl;
    // cout << $7-> getAsmCodes() << endl;
    // cout << $3->getName() << endl;
    // cout << $3->getAsmCodes() << endl;
    cout << initCode << endl;


    string firstStatement = (yyvsp[-4].symbolInfo) -> getName();
    string secondStatement = (yyvsp[-3].symbolInfo) -> getName();

    asmCodes += initCode;
    if(firstStatement != ";" && secondStatement != ";"){
        string label1 = newLabel();
        string label2 = newLabel();

        asmCodes += label1 + ": \n" + conditionCode  ;
        asmCodes += "mov ax, " + conditonAsm  + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + label2 + "\n";

        asmCodes += bodyCode;
        asmCodes += incrementCode;
        asmCodes += "jmp " + label1 + "\n";
        asmCodes += label2 + ": \n";

    }

    (yyval.symbolInfo) -> setAsmCodes(asmCodes);

    logFile << "line number" << lineCount << ": " ;
    logFile << "statement : FOR LPAREN expression statement expression statement expression RPAREN statement"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
    }
#line 2545 "1805108.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 899 "1805108.y"
            {

                string bodyCode = (yyvsp[0].symbolInfo) -> getAsmCodes();
                string conditionCode = (yyvsp[-2].symbolInfo) -> getAsmCodes();
                string conditonAsm = (yyvsp[-2].symbolInfo) -> getAsmName();

                string label1 = newLabel();
                string label2 = newLabel();

                string asmCodes = "";

                asmCodes+= ";while loop\n";
                asmCodes += label1 + ": \n" + conditionCode  ;
                asmCodes += "\tmov ax, " + conditonAsm  + "\n";
                asmCodes += "\tcmp ax, 0\n";
                asmCodes += "\tje " + label2 + "\n";

                asmCodes += bodyCode;
                asmCodes += "jmp " + label1 + "\n";
                asmCodes += label2 + ": \n";

            (yyval.symbolInfo) = new SymbolInfo("while("+(yyvsp[-2].symbolInfo)->getName()+")"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_WHILE_STATEMENT");
            (yyval.symbolInfo) -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2577 "1805108.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement  */
#line 927 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo("if("+(yyvsp[-2].symbolInfo)->getName()+")"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_IF_STATEMENT");
            string asmCodes = "";
            string conditionCode = (yyvsp[-2].symbolInfo) -> getAsmCodes();
            string conditonAsm = (yyvsp[-2].symbolInfo) -> getAsmName();
            string bodyCode = (yyvsp[0].symbolInfo) -> getAsmCodes();
            string label = newLabel();
            asmCodes += conditionCode;
            asmCodes += "mov ax, " + conditonAsm  + "\n";
            asmCodes += "\tcmp ax, 0\n";
            asmCodes += "\tje " + label + "\n";
            asmCodes += bodyCode;
            asmCodes += label + ": \n";
            (yyval.symbolInfo) -> setAsmCodes(asmCodes);

            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2601 "1805108.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 947 "1805108.y"
            {
                string asmCodes = "";
                asmCodes += ";if statement\n";
            string conditionCode = (yyvsp[-4].symbolInfo) -> getAsmCodes();
            string conditonAsm = (yyvsp[-4].symbolInfo) -> getAsmName();
            string bodyCodeIf = (yyvsp[-2].symbolInfo) -> getAsmCodes();
            string bodyCodeElse = (yyvsp[0].symbolInfo) -> getAsmCodes();
            string label1 = newLabel();
            string label2 = newLabel();
            asmCodes += conditionCode;
            asmCodes += "mov ax, " + conditonAsm  + "\n";
            asmCodes += "\tcmp ax, 0\n";
            asmCodes += "\tje " + label1 + "\n";
            asmCodes += bodyCodeIf;
            asmCodes += "jmp " + label2 + "\n";
            asmCodes += label1 + ": \n";
            asmCodes += bodyCodeElse;
            asmCodes += label2 + ": \n";
            (yyval.symbolInfo) = new SymbolInfo("if("+(yyvsp[-4].symbolInfo)->getName()+")"+(yyvsp[-2].symbolInfo)->getName()+"else"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_IF_STATEMENT");
            (yyval.symbolInfo) -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2630 "1805108.tab.c"
    break;

  case 39: /* statement: RETURN expression SEMICOLON  */
#line 972 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo ("return "+(yyvsp[-1].symbolInfo)->getName()+";", "SYMBOL_RETURN_STATEMENT");
            string asmCodes = "";
            string expressionCode = (yyvsp[-1].symbolInfo) -> getAsmCodes();
            string expressionAsm = (yyvsp[-1].symbolInfo) -> getAsmName();
            asmCodes += expressionCode;
            asmCodes += "\tpop bp\n";
            asmCodes += "\tpush " + expressionAsm + "\n";
            // asmCodes += "mov ax, " + expressionAsm  + "\n";
            // asmCodes += "\tmov [bp - 4], ax\n";
            // asmCodes += "\tjmp [bp - 8]\n";
            (yyval.symbolInfo) -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2651 "1805108.tab.c"
    break;

  case 40: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 989 "1805108.y"
            {
                SymbolInfo *temp = symbolTable.search((yyvsp[-2].symbolInfo)->getName());
            if(symbolTable.search((yyvsp[-2].symbolInfo)->getName()) == NULL)
            {
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: variable " << (yyvsp[-2].symbolInfo)->getName() << " not declared" << endl;
                errorCount++;
            }
            else
            {
                if(temp != NULL){
               if(temp->getArraySize() == -2){
                    errorFile << "line number" << lineCount << ": " ;
                    errorFile << "error: variable " << (yyvsp[-2].symbolInfo)->getName() << " is a function" << endl;
                    errorCount++;
                }
               }}
            
            string asmCode = "";
            asmCode += " ; println(" + (yyvsp[-2].symbolInfo)->getName() + ")" + "\n";
            asmCode += "\tmov ax, " + temp->getAsmName() + "\n";
            asmCode += "\tmov print_var , ax\n";
            asmCode += "\tcall println\n";

            

            
            (yyval.symbolInfo) = new SymbolInfo ("println("+(yyvsp[-2].symbolInfo)->getName()+");", "statement");
            (yyval.symbolInfo) -> setAsmCodes(asmCode);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : PRINTLN LPAREN expression RPAREN SEMICOLON"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 2689 "1805108.tab.c"
    break;

  case 41: /* expression_statement: SEMICOLON  */
#line 1027 "1805108.y"
                        {
                        (yyval.symbolInfo) = new SymbolInfo(";", "SYMBOL_EXPRESSION_STATEMENT");
                        
                        }
#line 2698 "1805108.tab.c"
    break;

  case 42: /* expression_statement: expression SEMICOLON  */
#line 1032 "1805108.y"
                        {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+";", "SYMBOL_EXPRESSION_STATEMENT");
                        (yyval.symbolInfo) -> setAsmCodes((yyvsp[-1].symbolInfo)->getAsmCodes());
                        (yyval.symbolInfo) -> setAsmName((yyvsp[-1].symbolInfo)->getAsmName());
                        
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "expression_statement : expression SEMICOLON"<<endl<<endl ;
                        logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                        }
#line 2712 "1805108.tab.c"
    break;

  case 43: /* variable: ID  */
#line 1043 "1805108.y"
             {
    SymbolInfo *temp = symbolTable.search((yyvsp[0].symbolInfo)->getName());
    if(temp != NULL){

    (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), temp->getType());
    (yyval.symbolInfo) -> setAsmName(temp->getAsmName());
    }
    else{
        (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "undeclared");
    }
    cout << "variable "<<(yyvsp[0].symbolInfo)->getName()<<": ID" << (yyvsp[0].symbolInfo)->getAsmName()<<endl;
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

}
#line 2733 "1805108.tab.c"
    break;

  case 44: /* variable: ID LTHIRD expression RTHIRD  */
#line 1059 "1805108.y"
                             {
    SymbolInfo *currentId = symbolTable.search((yyvsp[-3].symbolInfo)->getName());
    string globalName;
    if(currentId == NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " not declared" << endl;
        errorCount++;
    }
    else{
     globalName = currentId-> getAsmName();
     if(currentId->getArraySize() < 0)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " is not an array" << endl;
        errorCount++;
    }
    else{
     if(currentId->getArraySize() <= stoi((yyvsp[-1].symbolInfo)->getName()))
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " is out of range. array size: " << currentId->getArraySize() << endl;
        errorCount++; 
    }
     if((yyvsp[-1].symbolInfo)->getType() != "int")
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: index of variable " << (yyvsp[-3].symbolInfo)->getName() << " is not of type INT" << endl;
        errorCount++;
    }}}
    
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].symbolInfo)->getName()+"]", (yyvsp[-3].symbolInfo)->getType());
     string asmCodes = "";
     asmCodes += " ;" + (yyval.symbolInfo)->getName() + "\n";
    string temp = newTemp();
    string expressionCode = (yyvsp[-1].symbolInfo)->getAsmCodes();
    string expressionAsm = (yyvsp[-1].symbolInfo)->getAsmName();
    asmCodes += expressionCode;
   asmCodes += "\tmov si, " + expressionAsm + "\n";
   asmCodes += "\tadd si,si\n";
    asmCodes += "\tmov ax, " + globalName + "[si]\n";
    temp = globalName + "["+ expressionAsm +"]";
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID LTHIRD expression RTHIRD"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2786 "1805108.tab.c"
    break;

  case 45: /* expression: logic_expression  */
#line 1109 "1805108.y"
                             {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : logic expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2797 "1805108.tab.c"
    break;

  case 46: /* expression: variable ASSIGNOP logic_expression  */
#line 1116 "1805108.y"
                                    {
    // logFile << $1->getType()<< $3->getType() << endl;
    // logFile << $3->getName() << endl;
    // logFile << $3->getArraySize() << endl;
    // logFile << $3->getArraySize() << endl;
    // SymbolInfo *leftVar = symbolTable.search($1->getName());
    // SymbolInfo *rightVar = symbolTable.search($3->getName());
    if((yyvsp[-2].symbolInfo)->getType() == "undeclared" || (yyvsp[0].symbolInfo)->getType() == "undeclared")
    {
      if((yyvsp[-2].symbolInfo)->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-2].symbolInfo)->getName() << " not declared" << endl;
        errorCount++;
    }
    if((yyvsp[0].symbolInfo)->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[0].symbolInfo)->getName() << " not declared" << endl;
        errorCount++;
    } 
    }  
    else if((((yyvsp[-2].symbolInfo)->getType() == "int") || ((yyvsp[0].symbolInfo)->getType() == "float")) && (((yyvsp[0].symbolInfo)->getType() == "int") || ((yyvsp[-2].symbolInfo)->getType() == "float"))){
        if((yyvsp[-2].symbolInfo)->getArraySize()>0){
        if((yyvsp[0].symbolInfo) -> getArraySize() == -1){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: variable " << (yyvsp[-2].symbolInfo)->getName()<<" "<<(yyvsp[-2].symbolInfo)->getType() << " is an array and cannot be assigned to a variable" << endl;
            errorCount++;
        }
    }
    else if((yyvsp[-2].symbolInfo)->getType() != (yyvsp[0].symbolInfo)->getType())
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-2].symbolInfo)->getName()<<" "<<(yyvsp[-2].symbolInfo)->getType() << " is not of type " << (yyvsp[0].symbolInfo)->getType() << endl;
        errorCount++;
    }
    }
    
   
    
    
    // if($1->getArraySize() != -1 && $3->getArraySize() == -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
    // if($1->getArraySize() == -1 && $3->getArraySize() != -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is not an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
   
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+"="+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_ASSIGNMENT_EXPRESSION");
     string asmCodes = "";
     asmCodes += " ; assignment expression:" + (yyval.symbolInfo)->getName() + "\n";
    string lefAsm = (yyvsp[-2].symbolInfo)->getAsmName();
    cout << (yyvsp[-2].symbolInfo)->getName() << endl;
    cout << (yyvsp[-2].symbolInfo)->getAsmName() << endl;

    string rightAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string leftCode = (yyvsp[-2].symbolInfo)->getAsmCodes();
    string rightCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    asmCodes += leftCode;
    asmCodes += rightCode;
    asmCodes += "\tmov ax," + rightAsm  + "\n";
    asmCodes += "\tmov " + lefAsm + ", ax\n";

    // string temp = newTemp();
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(lefAsm);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable ASSIGNOP logic expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2876 "1805108.tab.c"
    break;

  case 47: /* logic_expression: rel_expression  */
#line 1192 "1805108.y"
                                  {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : rel_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2887 "1805108.tab.c"
    break;

  case 48: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 1198 "1805108.y"
                                        {
    string type = "int";
    if((yyvsp[-2].symbolInfo)->getType() != "int" || (yyvsp[0].symbolInfo)->getType() != "int")
    {
        type = "error";
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: operands of logical operator are not of type INT" << endl;
        errorCount++;
    }
   
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), type);
     string asmCodes = "";

     asmCodes += " ; logic_expression: "+(yyval.symbolInfo)->getName() + "\n";
    string leftAsm = (yyvsp[-2].symbolInfo)->getAsmName();
    string rightAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string leftCode = (yyvsp[-2].symbolInfo)->getAsmCodes();
    string rightCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    asmCodes += leftCode;
    asmCodes += rightCode;
    string temp = newTemp();
    string return0 = newLabel();
    string return1 = newLabel();
    string logicOperator = (yyvsp[-1].symbolInfo)->getName();
    if(logicOperator == "&&"){
        asmCodes += "\tmov ax, " + leftAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + return0 + "\n";
        asmCodes += "\tmov ax, " + rightAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + return1 + "\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return1 + "\n";
        asmCodes += return0 + ":\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return1 + ":\n";
    }
    else if(logicOperator == "||"){
        asmCodes += "\tmov ax, " + leftAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tjne " + return0 + "\n";
        asmCodes += "\tmov ax, " + rightAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tjne " + return0 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return1 + "\n";
        asmCodes += return0 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return1 + ":\n";
    }

    // string temp = newTemp();
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : logic_expression AND rel_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2954 "1805108.tab.c"
    break;

  case 49: /* rel_expression: simple_expression  */
#line 1264 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2965 "1805108.tab.c"
    break;

  case 50: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1270 "1805108.y"
                                           {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), (yyvsp[-2].symbolInfo)->getType());
     string asmCodes = "";
        asmCodes += " ; Relational Operation: "+(yyval.symbolInfo)->getName()+"\n";
    string temp = newTemp();
    string lefAsm = (yyvsp[-2].symbolInfo)->getAsmName();
    string rightAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string leftCode = (yyvsp[-2].symbolInfo)->getAsmCodes();
    string rightCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    string label_0 = newLabel();
    string label_1 = newLabel();
    asmCodes += leftCode;
    asmCodes += rightCode;
    asmCodes += "\tmov ax, " + lefAsm + "\n";
    asmCodes += "\tcmp ax, " + rightAsm + "\n";

    string relOperator = (yyvsp[-1].symbolInfo)->getName();
    if(relOperator == "=="){
        asmCodes += "\tje " + label_1 + "\n";       
    }
    else if(relOperator == "!="){
        asmCodes += "\tjne " + label_1 + "\n";
        
    }
   
    else if(relOperator == "<"){
        asmCodes += "\tjl " + label_1 + "\n";
        
    }
   else if(relOperator == ">"){
        asmCodes += "\tjg " + label_1 + "\n";
        
    }
    else if(relOperator == "<="){
        asmCodes += "\tjle " + label_1 + "\n";
       
    }
    else if(relOperator == ">="){
        asmCodes += "\tjge " + label_1 + "\n";
       
    }
     asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + label_0 + "\n";
        asmCodes += label_1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += label_0 + ":\n";
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple_expression RELOP simple_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

}
#line 3025 "1805108.tab.c"
    break;

  case 51: /* simple_expression: term  */
#line 1326 "1805108.y"
                        {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : term"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3036 "1805108.tab.c"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 1333 "1805108.y"
{
    //problem in getting the plus and minus
    string type;
    if((yyvsp[-2].symbolInfo)->getType() == "int" && (yyvsp[0].symbolInfo)->getType() == "int")
    {
        type = "int";
    }
    else
    {
        type = "float";
    }
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), type);
     string asmCodes = "";
    
    string lefAsm = (yyvsp[-2].symbolInfo)->getAsmName();
    // cout << "---------------------------------lefAsm " << lefAsm << endl;
    // cout << "---------------------------------rightAsm " << $3->getAsmName() << endl;
    string rightAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string leftCode = (yyvsp[-2].symbolInfo)->getAsmCodes();
    string rightCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    string addOperator = (yyvsp[-1].symbolInfo)->getName();
    asmCodes += leftCode;
        asmCodes += rightCode;
    string temp = newTemp();
    asmCodes += "\tmov ax, " + lefAsm + "\n";
    if(addOperator == "+"){
        
        asmCodes += "\tadd ax, " + rightAsm + "\n";
        
    }
    else if(addOperator == "-"){
        
        asmCodes += "\tsub ax, " + rightAsm + "\n";
    }
        asmCodes += "\tmov " + temp + ", ax\n";


    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : simple_expression ADDOP term"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3084 "1805108.tab.c"
    break;

  case 53: /* term: unary_expression  */
#line 1378 "1805108.y"
                        {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3095 "1805108.tab.c"
    break;

  case 54: /* term: term MULOP unary_expression  */
#line 1384 "1805108.y"
                              {

    string leftType = (yyvsp[-2].symbolInfo)->getType();
    string rightType = (yyvsp[0].symbolInfo)->getType();
    string mulOperator = (yyvsp[-1].symbolInfo)->getName();
    string type;
    if(mulOperator == "%"){
        if(leftType != "int" || rightType != "int"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo mulOperator can only be used with ints" << endl;
            errorCount++;
        }
    }
    else if(mulOperator == "*" || mulOperator == "/"){
        if(leftType != "int" || rightType != "int"){
            type = "float";
            
        }
    }

    if(mulOperator == "/" ){
        if((yyvsp[0].symbolInfo)->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: division by zero" << endl;
            errorCount++;
        }
    }

    if( mulOperator == "%"){
        if((yyvsp[0].symbolInfo)->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo by zero" << endl;
            errorCount++;
        }
    }
    
    
    string asmCodes = "";
    string lefAsm = (yyvsp[-2].symbolInfo)->getAsmName();
    string rightAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string leftCode = (yyvsp[-2].symbolInfo)->getAsmCodes();
    string rightCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    // string mulOperator = $2->getName();
    string temp = newTemp();
    asmCodes += leftCode;
    asmCodes += rightCode;
        asmCodes += " ;" + (yyval.symbolInfo)->getName() + "\n";
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        


    if(mulOperator == "*"){
        
        asmCodes += "\tmov bx, " + rightAsm + "\n";
        asmCodes += "\timul bx\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    else if(mulOperator == "/"){
        
        asmCodes += "\tcwd\n";
        asmCodes += "\tmov bx, " + rightAsm + "\n";
        asmCodes += "\tidiv bx\n";
        // asmCodes += "\tdiv ax, " + rightAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    else if(mulOperator == "%"){
        
        asmCodes += "\tcwd\n";
        asmCodes += "\tmov bx, " + rightAsm + "\n";
        asmCodes += "\tidiv bx\n";
        asmCodes += "\tmov " + temp + ", dx\n";
    }
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), type);
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : term MULOP unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3179 "1805108.tab.c"
    break;

  case 55: /* unary_expression: ADDOP unary_expression  */
#line 1466 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), (yyvsp[0].symbolInfo)->getType());
    string asmCodes = "";
    string temp ;
    string addOperator = (yyvsp[-1].symbolInfo)->getName();
    string unaryExpressionAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string unaryExpressionCode = (yyvsp[0].symbolInfo)->getAsmCodes();
    if(addOperator == "+"){
       temp = unaryExpressionAsm;
       asmCodes = unaryExpressionCode;
    }
    else if(addOperator == "-"){
        temp = newTemp();
        asmCodes += unaryExpressionCode;

        asmCodes += "\tmov ax, " + unaryExpressionAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tneg "+temp+"\n";
    }
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ADDOP unary expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3209 "1805108.tab.c"
    break;

  case 56: /* unary_expression: NOT unary_expression  */
#line 1492 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo(" !"+(yyvsp[0].symbolInfo)->getName(), (yyvsp[0].symbolInfo)->getType());
    string asmCodes = "";
    string temp = newTemp();
    string unaryExpressionAsm = (yyvsp[0].symbolInfo)->getAsmName();
    string unaryExpressionCode = (yyvsp[0].symbolInfo)->getAsmCodes();

    string label_0 = newLabel();
    string label_1 = newLabel();
    asmCodes += "; "+ (yyval.symbolInfo)->getName() + "\n";
    asmCodes += unaryExpressionCode;
    asmCodes += "\tmov ax, " + unaryExpressionAsm + "\n";
    asmCodes += "\tcmp ax, 0\n";
    asmCodes += "\tje " + label_1 + "\n";
    asmCodes += "\tmov ax, 0\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tjmp " + label_0 + "\n";

    asmCodes += label_1 + ":\n";
    asmCodes += "\tmov ax, 1\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += label_0 + ":\n";

    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : NOT unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3243 "1805108.tab.c"
    break;

  case 57: /* unary_expression: factor  */
#line 1522 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "unary_expression : factor"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3254 "1805108.tab.c"
    break;

  case 58: /* factor: variable  */
#line 1532 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable\n\n" ;
    logFile<< (yyval.symbolInfo)->getName() << "\n\n";
}
#line 3265 "1805108.tab.c"
    break;

  case 59: /* factor: ID LPAREN argument_list RPAREN  */
#line 1539 "1805108.y"
{
    // cout << "factor : ID LPAREN argument_list RPAREN"<<endl;
    SymbolInfo *func = symbolTable.searchInGlobalScope((yyvsp[-3].symbolInfo)->getName());
    string type = "";
    if(func == NULL){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: function " << (yyvsp[-3].symbolInfo)->getName() << " not declared" << endl;
        errorCount++;
        type = "undeclared";
    }
    else{
        type = func->getType();
        if(func->getArraySize() != -2){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: " << (yyvsp[-3].symbolInfo)->getName() << " is not a function" << endl;
            errorCount++;
        }
        else{
            string argument_name_list = (yyvsp[-1].symbolInfo)->getName();
            string argument_type_list = (yyvsp[-1].symbolInfo)->getType();
            
            // cout << "argument_name_list: " << argument_name_list << endl;
            // cout << "argument_type_list: " << argument_type_list << endl;
            vector<string> argument_name_vector = split(argument_name_list, ",");
            vector<string> argument_type_vector = split(argument_type_list, ",");
            
           if(argument_name_vector.size() != func->getParamSize()){
                // cout << "argument size:"<<argument_type_vector.size() << endl;
                // cout << func->getParamSize() << endl;
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: function " << (yyvsp[-3].symbolInfo)->getName() << " expects " << func->getParamSize() << " arguments" << endl;
                errorCount++;
            }
            else{
                for(int i = 0; i < argument_name_vector.size(); i++){
                    // cout << "argument_name_vector: " << argument_name_vector[i] << endl;
                    // cout << "argument_type_vector: " << argument_type_vector[i] << endl;
                    // cout << "func->getParameterName"<< func->getParameterName(i) << endl;
                    // cout << "func->getParamType(i): " << func->getParameterType(i) << endl;

                    if(argument_type_vector[i] != func->getParameterType(i)){
                        errorFile << "line number" << lineCount << ": " ;
                        errorFile << "error: function " << (yyvsp[-3].symbolInfo)->getName() << " expects " << func->getParameterType(i) << " as argument " << i+1 << endl;
                        errorCount++;
                    }
                }
            }
           }
        }
        
    
    string argument_asm_list = (yyvsp[-1].symbolInfo)->getAsmName();
    vector<string> argument_asm_vector = split(argument_asm_list, ",");
    cout << argument_asm_list <<endl;
    for(int i = 0;i < argument_asm_vector.size(); i++){
        cout <<"splitted "<< argument_asm_vector[i] <<endl;
    }
    // cout << "argument_asm_vector: " << argument_asm_vector << endl;

    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+" ( "+(yyvsp[-1].symbolInfo)->getName()+" )",type );
    string temp = newTemp();;
    string asmCodes = "";
    asmCodes += "; function call: "+ (yyval.symbolInfo)->getName() + "\n";

    string funcName = (yyvsp[-3].symbolInfo)->getName();

    asmCodes += "\tpush ax\n";
    asmCodes += "\tpush bx\n";
    asmCodes += "\tpush cx\n";
    asmCodes += "\tpush dx\n";

    int asmSize = argument_asm_vector.size();
    for(int i = 0;i < argument_asm_vector.size(); i++){
        // argument_asm_vector[i] += symbolTable.getScopeTable()->getShowId();
        asmCodes += "\tpush " + argument_asm_vector[i] + "\n";
        // asmCodes += "\tmov [bp-" + to_string(i*2) + "], ax\n";
    }
    asmCodes += "\tcall " + funcName + "\n";
    
    asmCodes += "\tpop " + temp + "\n";
    asmCodes += "\tpop dx\n";
    asmCodes += "\tpop cx\n";
    asmCodes += "\tpop bx\n";
    asmCodes += "\tpop ax\n";

    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3361 "1805108.tab.c"
    break;

  case 60: /* factor: LPAREN expression RPAREN  */
#line 1631 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo(" ( "+(yyvsp[-1].symbolInfo)->getName()+" ) ", (yyvsp[-1].symbolInfo)->getType());
    (yyval.symbolInfo)->setAsmCodes((yyvsp[-1].symbolInfo)->getAsmCodes());
    (yyval.symbolInfo)->setAsmName((yyvsp[-1].symbolInfo)->getAsmName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : LPAREN expression RPAREN"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3374 "1805108.tab.c"
    break;

  case 61: /* factor: CONST_INT  */
#line 1640 "1805108.y"
{
    (yyval.symbolInfo) = yylval.symbolInfo;
    (yyval.symbolInfo)-> setAsmName(yylval.symbolInfo->getName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_INT"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3386 "1805108.tab.c"
    break;

  case 62: /* factor: CONST_FLOAT  */
#line 1647 "1805108.y"
             {
    (yyval.symbolInfo) = yylval.symbolInfo;
    (yyval.symbolInfo)-> setAsmName(yylval.symbolInfo->getName());

    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_FLOAT"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3399 "1805108.tab.c"
    break;

  case 63: /* factor: variable INCOP  */
#line 1657 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+"++", (yyvsp[-1].symbolInfo)->getType());
     string asmCodes = "";
     asmCodes += "; increment: " + (yyval.symbolInfo)->getName() + "\n";
    string temp = newTemp();
    string varCode = (yyvsp[-1].symbolInfo)->getAsmCodes();
    string varAsmName = (yyvsp[-1].symbolInfo)->getAsmName();
    asmCodes += varCode;
    asmCodes += "\tmov ax ,"  + varAsmName + "\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tinc "+ varAsmName + "\n";

    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo) -> setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable INCOP"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3422 "1805108.tab.c"
    break;

  case 64: /* factor: variable DECOP  */
#line 1677 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+"--", (yyvsp[-1].symbolInfo)->getType());
    string asmCodes = "";
    asmCodes += "; decrement: " + (yyval.symbolInfo)->getName() + "\n";
    string temp = newTemp();
    string varCode = (yyvsp[-1].symbolInfo)->getAsmCodes();
    string varAsmName = (yyvsp[-1].symbolInfo)->getAsmName();
    asmCodes += varCode;
    asmCodes += "\tmov ax,"  + varAsmName + "\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tdec "+ varAsmName + "\n";

    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo) -> setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable DECOP"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3445 "1805108.tab.c"
    break;

  case 65: /* argument_list: arguments  */
#line 1701 "1805108.y"
                         {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3456 "1805108.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 1708 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo("", "SYMBOL_ARGUMENT_LIST");
    (yyval.symbolInfo) -> setAsmName("");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list :"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3468 "1805108.tab.c"
    break;

  case 67: /* arguments: arguments COMMA logic_expression  */
#line 1718 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+","+(yyvsp[0].symbolInfo)->getName(), (yyvsp[-2].symbolInfo)->getType()+","+(yyvsp[0].symbolInfo)->getType());
    string asmCodes = (yyvsp[-2].symbolInfo)->getAsmCodes()+(yyvsp[0].symbolInfo)->getAsmCodes();
    (yyval.symbolInfo)->setAsmCodes(asmCodes);
    (yyval.symbolInfo)->setAsmName((yyvsp[-2].symbolInfo)->getAsmName()+","+(yyvsp[0].symbolInfo)->getAsmName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3482 "1805108.tab.c"
    break;

  case 68: /* arguments: logic_expression  */
#line 1728 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    // $$ = new SymbolInfo($1->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : logic_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 3494 "1805108.tab.c"
    break;


#line 3498 "1805108.tab.c"

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
          = {yyssp, yytoken};
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
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 1746 "1805108.y"


int main(int argc, char *argv[]) {
    // #ifdef YYDEBUG
    // yydebug = 1;
    // #endif
    	if(argc!=2){
		return 0;
	}
	

    FILE *fin = fopen(argv[1], "r");
	if(fin==NULL){
		return 0;
	}
	
    errorFile.open("error.txt");
    if(!errorFile){
        return 0;
    }

    logFile.open("log.txt");
    if(!logFile){
        return 0;
    }

    asmFile.open("code.asm");
    if(!asmFile){
        return 0;
    }

    



	yyin = fin;
    yyparse();
    symbolTable.printAllScopesInFile(logFile);
    logFile << "total no. of errors: " << errorCount << endl;
    logFile << "total no. of lines" << lineCount << endl;
   
    logFile.close();
    errorFile.close();
    asmFile.close();
    
    return 0;
}
