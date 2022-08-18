#!/bin/bash

bison -v --debug --defines=y.tab.h -Wconflicts-sr 1805108.y
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o 1805108.tab.c
echo 'Generated the parser object file'
flex 1805108.l
echo 'Generated the scanner C file'
# g++ -w -c -o l.o lex.yy.c
g++ -fpermissive -w -c -o l.o lex.yy.c 
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
g++  y.o l.o -lfl -o 1805108 
echo 'All ready, running'
./1805108 $1
