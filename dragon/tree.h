#ifndef TREE_H
#define TREE_H

#define NUM 257

//typedef struct tree tree;

typedef struct tree{
	int type;
	union {
		int ival;
		float fval;
		char* sval;
		char* opval;
	} attribute;
	struct tree *leftNode;
	struct tree *rightNode;
} tree;


tree *intTree(int type, int ival, tree *leftNode, tree *rightNode);
tree *fTree(int type, float fval, tree *leftNode, tree *rightNode);
tree *strTree(int type, char* sval, tree *leftNode, tree *rightNode);
tree *opTree(int type, char *opval, tree* leftNode,tree *rightNode);
tree *emptyTree();


void printTree(tree* t, int spaces);



int treeEval(tree * t);


#endif
