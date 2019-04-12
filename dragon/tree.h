#ifndef TREE_H
#define TREE_H
#include <string.h>
#include "node.h"
#include "types.h"

//typedef struct tree tree;

typedef struct tree{
	int type;
	union {
		int ival;
		float fval;
		char* sval;
		char* opval;
		node *nval;
	} attribute;
	int num;
	struct tree *leftNode;
	struct tree *rightNode;
} tree;

tree *intTree(int type, int ival, tree *leftNode, tree *rightNode);
tree *fTree(int type, float fval, tree *leftNode, tree *rightNode);
tree *strTree(int type, char* sval, tree *leftNode, tree *rightNode);
tree *opTree(int type, char *opval, tree* leftNode,tree *rightNode);
tree* checkForReturn(char*, tree*);
tree *emptyTree();

int checkTypes(scope *top, tree* t);
int countArgs(scope* top, tree* t, int args);


tree* nodeTree(int type, char *name, node* nval);

void checkArgs(scope* top,tree* fnc_ptr, tree* args_ptr);
void printTree(tree* t, int spaces);
void sameTypes(scope* top, tree* left, tree* right);
void enforce_type(scope* top, tree* t, int type);
void checkFunction(scope*, tree*, tree*);
void addArgs(scope*, char*, tree*);
void checkLocal(scope*, tree*);
types* findTypes(scope* top, tree* arg_ptr);
#endif
