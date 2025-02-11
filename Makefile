PROJECT = atl
OBJS = main.o parser.o scanner.o symbol_structs.o symbol_table.o syntax_tree.o kv_tree.o util.o
GEN = parser.c scanner.c y.tab.h y.output
CFLAGS = -g -Wall
LIBS = -ll
BIN=/bin
all: $(PROJECT) testscan

$(PROJECT): $(OBJS)
	gcc -o $(PROJECT) $(CFLAGS) $(OBJS) $(LIBS)

install: $(PROJECT)
	cp $(PROJECT) $(BIN)

parser.c: atl.y
	byacc -dvt atl.y 
	mv y.tab.c parser.c

scanner.c: scanner.l y.tab.h
	flex scanner.l
	mv lex.yy.c scanner.c

clean:
	rm -f $(OBJS) atl.out atl.hcs *.atl

realclean: clean	
	rm -f $(PROJECT) $(GEN) testscan

testscan: parser.o util.o symbol_table.o symbol_structs.o syntax_tree.o kv_tree.o scanner.c main.c
	gcc -o testscan $(CFLAGS) -DTESTSCAN \
	main.c scanner.c parser.o util.o symbol_table.o symbol_structs.o syntax_tree.o kv_tree.o $(LIBS)


y.tab.h: atl.y parser.c
parser.o: definitions.h globals.h 
scanner.o: y.tab.h
util.o: definitions.h globals.h
main.o: definitions.h globals.h
#idk if symbol_structs will depend on globals/defs
#leaving it for now!
symbol_structs.o: symbol_structs.h definitions.h globals.h
#will including symbol_table or symbol_struct
#multiple times cause errors?
#ex: definitions.h includes symbol_structs already
#will double check and adjust later.
symbol_table.o: definitions.h symbol_structs.h globals.h
syntax_tree.o: definitions.h globals.h
kv_tree.o: kv_tree.h