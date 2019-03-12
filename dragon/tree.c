#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "tree.h"
#include "externs.h"
#include "y.tab.h"

#define DEBUG 0

tree *intTree(int type, int ival, tree *leftNode, tree *rightNode) {
	tree *t;
	t = malloc(sizeof(struct tree));
	
	

	t -> type = type;
	t -> leftNode = leftNode;
	t -> rightNode = rightNode;
	t -> attribute.ival = ival;

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nN: %p\t\t%d", t, t->attribute.ival);
		fprintf(stderr, "\n  T  %d", t->type);
		fprintf(stderr, "\n  L: %p", t->leftNode);
		fprintf(stderr, "\n  R: %p\n", t->rightNode);
	}

	return t;
}

tree *fTree(int type, float fval, tree *leftNode, tree *rightNode) {
	tree *t;
	t = malloc(sizeof(struct tree));

	t -> type = type;
	t -> leftNode = leftNode;
	t -> rightNode = rightNode;
	t -> attribute.fval = fval;

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nN: %p\t\t%f", t, t->attribute.fval);
		fprintf(stderr, "\n  T  %d", t->type);
		fprintf(stderr, "\n  L: %p", t->leftNode);
		fprintf(stderr, "\n  R: %p\n", t->rightNode);
	}

	return t;
}


tree *strTree(int type, char* sval, tree *leftNode, tree *rightNode) {
	tree *t;
	t = malloc(sizeof(struct tree));
	t -> type = type;
	t -> leftNode = leftNode;
	t -> rightNode = rightNode;
	t -> attribute.sval = strdup(sval);

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nN: %p\t\t%s", t, t->attribute.sval);
		fprintf(stderr, "\n  T  %d", t->type);
		fprintf(stderr, "\n  L: %p", t->leftNode);
		fprintf(stderr, "\n  R: %p\n", t->rightNode);
	}

	return t;
}

tree *opTree(int type, char *opval, tree* leftNode, tree *rightNode) {
	tree *t;
	t = malloc(sizeof(struct tree));

	t -> type = type;
	t -> leftNode = leftNode;
	t -> rightNode = rightNode;
	t -> attribute.opval = strdup(opval);

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nN: %p\t\t%", t, t->attribute.opval);
		fprintf(stderr, "\n  T  %d", t->type);
		fprintf(stderr, "\n  L: %p", t->leftNode);
		fprintf(stderr, "\n  R: %p\n", t->rightNode);
	}
	return t;
}


tree *emptyTree() {
	tree *t;
	t = malloc(sizeof(struct tree));

	t -> type = EMPTY;
	t -> leftNode = NULL;
	t -> rightNode = NULL;
	t -> attribute.sval = " ";

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nE: %p\t\t%s", t, t->attribute.sval);
	}
	return t;
}




void printTree(tree *t, int spaces)
{
	if( t == NULL || t -> type == EMPTY  ) {
		return;
	}

	if(spaces == 0)
		fprintf(stderr, "\n\n\nSYNTAX TREE\n___________\n\n");
	
	for(int i = 0; i < spaces; i++)
		fprintf(stderr, "| ");

	switch( t -> type ) {
		case INUM: 		fprintf(stderr, "[INUM %d]", t->attribute.ival); break;
		case ID: 		fprintf(stderr, "[ID %s]", t->attribute.sval); break;
		case RNUM: 		fprintf(stderr, "[RNUM %f]", t->attribute.fval); break;
		case ADDOP: 	fprintf(stderr, "[ADDOP %d]", t->attribute.ival); break;
		case MULOP: 	fprintf(stderr, "[MULOP %s]", t->attribute.sval); break;
		case RELOP: 	fprintf(stderr, "[RELOP %s]", t->attribute.opval); break;
		case ASSIGNOP: 	fprintf(stderr, "[ASSIGNOP %s]", t->attribute.opval); break;
		case NOT: 		fprintf(stderr, "[NOT %s]", t->attribute.opval); break;
		case PROGRAM: 	fprintf(stderr, "[PROGRAM %s]", t->attribute.sval); break;
		case FUNCTION: 	fprintf(stderr, "[FUNCTION %d]", t->attribute.ival); break;
		case PROCEDURE: fprintf(stderr, "[PROCEDURE %d]", t->attribute.ival); break;
		case VAR: 		fprintf(stderr, "[VAR %s]", t->attribute.sval); break;
		case ARRAY: 	fprintf(stderr, "[ARRAY %s]", t->attribute.sval); break;
		case OF: 		fprintf(stderr, "[OF %s]", t->attribute.sval); break;
		case DOTDOT: 	fprintf(stderr, "[DOTDOT %s]", t->attribute.sval); break;
		case INTEGER: 	fprintf(stderr, "[INTEGER %s]", t->attribute.sval); break;
		case REAL: 		fprintf(stderr, "[REAL %s]", t->attribute.sval); break;
		case BBEGIN: 		fprintf(stderr, "[BBEGIN %s]", t->attribute.sval); break;
		case END: 		fprintf(stderr, "[END %s]", t->attribute.sval); break;
		case IF: 		fprintf(stderr, "[IF %s]", t->attribute.sval); break;
		case THEN: 		fprintf(stderr, "[THEN %s]", t->attribute.sval); break;
		case ELSE: 		fprintf(stderr, "[ELSE %s]", t->attribute.sval); break;
		case DO: 		fprintf(stderr, "[DO %s]", t->attribute.sval); break;
		case WHILE: 	fprintf(stderr, "[WHILE %s]", t->attribute.sval); break;
		case FOR: 		fprintf(stderr, "[FOR %s]", t->attribute.sval); break;
		case PAROP:		fprintf(stderr, "[PAROP]"); break;
		case ARROP: 	fprintf(stderr, "[ARRAYOP %s]", t->attribute.opval); break;
		case LISTOP: 	fprintf(stderr, "[LISTOP %s]", t->attribute.opval); break;
		case EMPTY:		fprintf(stderr, "[EMPTY]"); break;

		default:
			fprintf(stderr, "[UNKNOWN %d]\n", t->type);
			fprintf(stderr, "\nN: %p\t\t%f", t, t->attribute.fval);
		fprintf(stderr, "\n  T  %d", t->type);
		fprintf(stderr, "\n  L: %p", t->leftNode);
		fprintf(stderr, "\n  R: %p\n", t->rightNode);
			//exit(1);
	}
	
	fprintf(stderr, "\n");

	printTree(t->leftNode, spaces+1);
	printTree(t->rightNode, spaces+1);
			
}
