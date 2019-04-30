#ifndef NODE_H
#define NODE_H
#define HASH_SIZE 211


typedef struct node node;

typedef struct scope {
	char* name;
	int type;

	int varNum;
	

	node *table[HASH_SIZE];
	struct scope *next;
} scope;


struct node{
	char* name;

	int offset;
	int type;
	int returnType;

	int start_idx;
	int end_idx;
	int args;
	struct types* arg_types;
	struct node* next;
};


char* stringCat(char*, char*);
char* typeToString(int);

int hashpjw( char *s );


node* mknode(char *);
node *searchNode(node *, char *);
node *insertNode(node *, char *);
node *searchScopeAll(scope *top, char *name);
node *searchScope(scope *top, char *name);
node *insertScope(scope *top, char *name);


scope *push_scope(scope* top, char* name, int type);
scope *pop_scope(scope *);
scope *mkscope();

void print_scope(scope* s);
void freeScope(scope *);
void checkID(scope* top, char* name);



//table* pushTable(char* name, int class);
//void popTable();



#endif
