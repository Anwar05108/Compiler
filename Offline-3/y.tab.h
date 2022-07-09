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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADDOP = 278,                   /* ADDOP  */
    MULOP = 279,                   /* MULOP  */
    RELOP = 280,                   /* RELOP  */
    BITOP = 281,                   /* BITOP  */
    LOGICOP = 282,                 /* LOGICOP  */
    LOGICNOT = 283,                /* LOGICNOT  */
    NOT = 284,                     /* NOT  */
    LPAREN = 285,                  /* LPAREN  */
    RPAREN = 286,                  /* RPAREN  */
    LCURL = 287,                   /* LCURL  */
    RCURL = 288,                   /* RCURL  */
    LTHIRD = 289,                  /* LTHIRD  */
    RTHIRD = 290,                  /* RTHIRD  */
    COMMA = 291,                   /* COMMA  */
    SEMICOLON = 292,               /* SEMICOLON  */
    COLON = 293,                   /* COLON  */
    INT = 294,                     /* INT  */
    FLOAT = 295,                   /* FLOAT  */
    DOUBLE = 296,                  /* DOUBLE  */
    CHAR = 297,                    /* CHAR  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    SLASH = 300,                   /* SLASH  */
    ASTERISK = 301,                /* ASTERISK  */
    ID = 302,                      /* ID  */
    CONST_CHAR = 303,              /* CONST_CHAR  */
    CONST_INT = 304,               /* CONST_INT  */
    CONST_FLOAT = 305              /* CONST_FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define NEWLINE 259
#define NUMBER 260
#define LESS 261
#define GREATER 262
#define EQUAL 263
#define IF 264
#define FOR 265
#define ELSE 266
#define WHILE 267
#define BREAK 268
#define CONTINUE 269
#define CASE 270
#define DEFAULT 271
#define SWITCH 272
#define DO 273
#define RETURN 274
#define INCOP 275
#define DECOP 276
#define ASSIGNOP 277
#define ADDOP 278
#define MULOP 279
#define RELOP 280
#define BITOP 281
#define LOGICOP 282
#define LOGICNOT 283
#define NOT 284
#define LPAREN 285
#define RPAREN 286
#define LCURL 287
#define RCURL 288
#define LTHIRD 289
#define RTHIRD 290
#define COMMA 291
#define SEMICOLON 292
#define COLON 293
#define INT 294
#define FLOAT 295
#define DOUBLE 296
#define CHAR 297
#define PLUS 298
#define MINUS 299
#define SLASH 300
#define ASTERISK 301
#define ID 302
#define CONST_CHAR 303
#define CONST_INT 304
#define CONST_FLOAT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "1805108.y"

    SymbolInfo *symbolInfo;

#line 171 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
