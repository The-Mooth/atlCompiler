PROJECT = atl1
OBJS = main.o kv_tree.o syntree.o symtab.o 
GENERATED = parser.c scanner.c y.tab.h
CC = gcc
CFLAGS = -g -Wall
LIBS = -ll

YACC = byacc

all: $(PROJECT) testscan

$(PROJECT): $(OBJS)
	$(CC) -o $(PROJECT) $(CFLAGS) $(OBJS) $(LIBS)

parser.c: atl.y
	byacc -d atl.y 
	mv y.tab.c parser.c 

scannner.c: scanner.l 
	flex scanner.l 
	mv lex.yy.c scanner.c 

clean: 
	rm -f $(OBJS) atl.out atl.hcs .atl.*

realclean: clean
	rm -f $(PROJECT) $(GENERATED) testscan


y.tab.h: atl.y parser.c
parser.o: definitions.h globals.h
scanner.o: y.tab.h
main.o: definitions.h symbol_table.h global.h



