
FLAGS = -g -std=c99 -D_XOPEN_SOURCE=700 
LEX = lex
YACC = yacc

mypc: y.tab.o lex.yy.o node.o tree.o types.o
	$(CC) $(FLAGS) -o mypc y.tab.o node.o tree.o types.o lex.yy.o -ll -ly

types.o: types.c
	$(CC) $(FLAGS) -c types.c
node.o: node.c
	$(CC) $(FLAGS) -c node.c
tree.o: tree.c
	$(CC) $(FLAGS) -c tree.c

y.tab.o: y.tab.c
	$(CC) $(FLAGS) -c y.tab.c

y.tab.c: pc.y
	$(YACC) -y -dv pc.y

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c

lex.yy.c: pc.l
	$(LEX) -l pc.l

clean:
	rm -f mypc *.o y.tab.* lex.yy.* 
