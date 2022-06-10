
//designing a lexer using flex and bison
%option noyywrap

%{

#include <iostream>
#include <string>


#include <fstream>


#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstdarg>
#include <cstddef>



%}


// %token <yylex> INTEGER

//operators


%token <yylex> PLUS
%token <yylex> MINUS
%token <yylex> MULTIPLY
%token <yylex> DIVIDE
%token <yylex> MODULO
%token <yylex> POWER
%token <yylex> EQUAL
%token <yylex> NOT_EQUAL
%token <yylex> LESS_THAN
%token <yylex> LESS_THAN_EQUAL
%token <yylex> GREATER_THAN
%token <yylex> GREATER_THAN_EQUAL
%token <yylex> AND
%token <yylex> OR
%token <yylex> NOT
%token <yylex> XOR
%token <yylex> AND_NOT
%token <yylex> OR_NOT
%token <yylex> AND_AND
%token <yylex> OR_OR
%token <yylex> LEFT_SHIFT
%token <yylex> RIGHT_SHIFT
%token <yylex> LEFT_SHIFT_EQUAL
%token <yylex> RIGHT_SHIFT_EQUAL
%token <yylex> BITWISE_AND
%token <yylex> BITWISE_OR
%token <yylex> BITWISE_XOR
%token <yylex> BITWISE_NOT
%token <yylex> BITWISE_AND_NOT
%token <yylex> BITWISE_OR_NOT
%token <yylex> BITWISE_XOR_NOT
%token <yylex> BITWISE_AND_AND
%token <yylex> BITWISE_OR_OR
%token <yylex> BITWISE_XOR_XOR
%token <yylex> BITWISE_AND_EQUAL
%token <yylex> BITWISE_OR_EQUAL


//keywords


%token <yylex> IF
