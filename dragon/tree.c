#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <string.h>
#include "tree.h"
#include "externs.h"
#include "y.tab.h"

extern char *strdup( const char * );

#define DEBUG 0

tree *intTree(int type, int ival, tree *leftNode, tree *rightNode) {
	tree *t;
	t = (tree *)malloc(sizeof(struct tree));
	
	

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
	t = (tree *)malloc(sizeof(struct tree));

	t -> type = type;
	t -> leftNode = leftNode;
	t -> rightNode = rightNode;
	t -> attribute.fval = fval;
	t->attribute.sval = NULL;
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


tree* nodeTree(int type, char *name, node* nval) {
	tree *t;
	t = malloc(sizeof(struct tree));

	t -> type = type;
	t -> leftNode = emptyTree();
	t -> rightNode = emptyTree();
	t -> attribute.nval = nval;
	t -> attribute.sval = strdup(name);

	if(DEBUG == 1)
	{
		fprintf(stderr, "\nN: %p\t\t%", t, t->attribute.sval);
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


int checkTypes(scope *top, tree* t) {
	node *var_ptr;

	switch(t -> type) {
		case (INUM):
		case (RNUM):
		case (EMPTY):
		case (BOOL):
			return t->type;
			break;
		case (NOT):
			if(checkTypes(top, t->leftNode) != BOOL) {
				yyerror("'NOT' must take a boolean argument.");
			}
			return BOOL;
			break;
		case (ID):
			var_ptr = searchScopeAll(top, t->attribute.sval);

			if(var_ptr == NULL) {
				fprintf(stderr, "ERROR variable %s undeclared\n on line:%d\n", t->attribute.sval, yylineno);
				exit(0);
			}
			if(var_ptr -> type == FUNCTION ) {
				return var_ptr -> returnType;
				break;
			}
			return var_ptr -> type;
			break;

		
		
		
		case (RELOP):
			if(checkTypes(top, t->leftNode) != checkTypes(top, t->rightNode)) {
				fprintf(stderr, "Type mismatch expected %s but got %s on line:%d\n", typeToString(checkTypes(top, t->leftNode)), typeToString(checkTypes(top, t->rightNode)), yylineno);
				exit(0);

			}

			return BOOL;
			break;

		case(MULOP):
		case (ADDOP):
			if(!strcmp(t->attribute.opval, "+") || !strcmp(t->attribute.opval, "-") ||
			!strcmp(t->attribute.opval, "*") || !strcmp(t->attribute.opval, "/"))
			{
				sameTypes(top, t->leftNode, t->rightNode);
				if(checkTypes(top, t->leftNode) == BOOL)
				{
					yyerror("Something wrong 1");
					exit(0);
				}
				return checkTypes(top, t->leftNode);
			}

			else //using a boolean expression (AND or OR)
			{
				sameTypes(top, t->leftNode, t->rightNode);	
				if(checkTypes(top, t->leftNode) != BOOL)
				{
					yyerror("Something wrong 2");
					exit(0);
				}
				return BOOL;
			}  
			break;

		case (PAROP):
			var_ptr = searchScopeAll(top, t->leftNode->attribute.sval);

			if(var_ptr == NULL) yyerror("Undeclared variable");

			if(var_ptr -> type == PROCEDURE) yyerror("Procedures do not return a value");

			if(var_ptr -> type != FUNCTION) yyerror(stringCat(t->leftNode->attribute.sval, " is not a function"));

			//check args
			return var_ptr->returnType;
			break;


		case (ARROP):
			var_ptr = searchScopeAll(top, t-> leftNode->attribute.sval);

			if( var_ptr == NULL) {
				yyerror(stringCat(t->leftNode->attribute.sval, " :Undeclared"));
			}

			if(var_ptr->type != ARRAY) {
				yyerror(stringCat(t->leftNode->attribute.sval, " Is not a array "));
			}

			if(checkTypes(top, t->rightNode) != INUM) {
				yyerror(stringCat(t->rightNode->attribute.sval, " Index must be an integer type"));
			}

			return var_ptr->returnType;
			break;

		// case(LISTOP):
		// 	return checkTypes(top, t->leftNode);
		// 	break;

		default:
			fprintf(stderr, "Unexpected tree node type %d", t->type);
			//yyerror("Unexpected Tree node type in checkType");
	}
}


void sameTypes(scope* top, tree* left, tree* right) {
	if(checkTypes(top, left) != checkTypes(top, right)) {

		if(checkTypes(top, left) == PROCEDURE) {
			fprintf(stderr, "Error %s is a 'Procedure' and should not return a value on line %d\n", left->attribute.sval, yylineno);
			exit(0);
		}

		if(checkTypes(top, right) == PROCEDURE) {
			fprintf(stderr, "Error %s is a 'Procedure' and should not return a value on line %d\n", right->attribute.sval, yylineno);
			exit(0);
		}

		fprintf(stderr, "Type mismatch expected '%s' but got '%s'", typeToString(checkTypes(top, left)), typeToString(checkTypes(top, right)));
		yyerror("Type mismatch");
	}


}
void checkLocal(scope* top, tree* t) {
	 if(searchScope(top, t->attribute.sval) == NULL && strcmp(t->attribute.sval,top->name) && top -> type == FUNCTION) {
		 fprintf(stderr, "Error cannot change non local variable %s in %s on line %d\n", t->attribute.sval, top->name, yylineno);
		exit(0);
	 }
 }

void enforce_type(scope* top, tree* t, int type) {
	if(checkTypes(top, t) != type)
	{
		fprintf(stderr, "Error: Type mismatch expected '%s' but got '%s' on line: %d\n",  typeToString(type),typeToString(checkTypes(top, t)), yylineno);
		exit(0);
	}
}


tree* checkForReturn(char* name, tree* t) {
	if(t == NULL || t -> type == EMPTY) {
		return NULL;
	}

	if(t -> type == ASSIGNOP) {
		if(!strcmp(t->leftNode->attribute.sval, name)) { 
			//found a return statement
			return t;
		} 
	} else {
		tree* left = checkForReturn(name, t -> leftNode);
		tree* right = checkForReturn(name, t -> rightNode);

		if(left != NULL) 
			return left;
		if(right != NULL) 
			return right;
	}
	return NULL;
}



void checkFunction(scope* top, tree* head_ptr, tree* t) {

    if(head_ptr -> type == FUNCTION) {
        //int returnType = head_ptr -> returnType;
        char* name = head_ptr->attribute.sval;
		  tree* test = checkForReturn(name, t);
			if(test == NULL) {
				fprintf(stderr, "Error %s is a function and requires a return statement on line %d\n", name, yylineno);
				exit(0);
			}
            //enforce_type(top, test, searchScopeAll(top, name)->returnType);
			if(checkTypes(top, test-> rightNode) != searchScopeAll(top, name)->returnType) {
				fprintf(stderr, "Error %s returns type %s but recivied type %s\n", name, typeToString(searchScopeAll(top, name)->returnType), typeToString(checkTypes(top, test-> rightNode)) );
			}

    }
	if (head_ptr -> type == PROCEDURE) {
		char* name = head_ptr->attribute.sval;
		  tree* test = checkForReturn(name, t);
			if(test != NULL) {
				fprintf(stderr, "Error %s is a 'Procedure' and should not return a value on line %d\n", name, yylineno);
				exit(0);
			}
	}
}


int countArgs(scope* top, tree* t, int args) {
	if(t == NULL || t -> type == EMPTY) 
		return args;
		
	//if(t -> type  == ID || (t -> type == INUM && t->attribute.sval == NULL)  || (t-> type == RNUM && t->attribute.sval == NULL) || t -> type == ARROP ) {
	if(t->type != LISTOP && (checkTypes(top, t) == ID || (checkTypes(top, t) == INUM && t->attribute.ival != -9191) || checkTypes(top, t) == RNUM )) {
		args ++;
	}
	
	if(t -> leftNode != NULL && t -> leftNode -> type != EMPTY && t -> type != ARROP && t->type != ADDOP) {
		args += countArgs(top, t->leftNode, 0);
	}

	if(t -> rightNode != NULL && t -> rightNode -> type != EMPTY && t -> type != ARROP && t->type != ADDOP) {
		args += countArgs(top, t->rightNode, 0);
	}

	return args;
}


void checkArgs(scope* top,tree* fnc_ptr, tree* args_ptr) {
	node* fnc_node = searchScopeAll(top, fnc_ptr -> attribute.sval);
	int fnc_args = fnc_node->args;
	fprintf(stderr, "The number of args: %d\n", fnc_args);
	if(countArgs(top, args_ptr, 0) != fnc_args) {
		fprintf(stderr, "Error %s requires %d arguments given %d on line %d\n", fnc_node->name, fnc_node->args, countArgs(top, args_ptr, 0), yylineno);
		//exit(0);
	}
	tree* left = args_ptr -> leftNode;
	tree* right = args_ptr -> rightNode;
	types* t = findTypes(top, args_ptr);

	while(fnc_node -> arg_types -> type != 0 && t -> type != 0) {
		if(fnc_node -> arg_types -> type != t->type) {
			fprintf(stderr, "ERROR wrong argument types for %s %s requires %s but recived %s on line %d\n", typeToString(fnc_node->type), fnc_node->name, typeToString(fnc_node -> arg_types -> type), typeToString(t->type), yylineno);
			//exit(0);
		break;
		}
		else {
			fnc_node -> arg_types = fnc_node -> arg_types -> next;
			t = t -> next;
		}
	}


}

types* findTypes(scope* top, tree* arg_ptr) {
	types* t;
	if(arg_ptr -> type != LISTOP) {
		if(arg_ptr -> type == ID || arg_ptr -> type == ARROP) {
			node* n = searchScopeAll(top, arg_ptr -> attribute.sval);
			return mkType(checkTypes(top, arg_ptr));
		} else {
			 return mkType(arg_ptr->type);
		}
	}
	if(arg_ptr -> rightNode -> type != LISTOP) {

		if(arg_ptr -> rightNode -> type == ID || arg_ptr -> leftNode -> type == ARROP) {
			t = mkType(checkTypes(top, arg_ptr -> rightNode));
		} else {
			t = mkType(checkTypes(top, arg_ptr->rightNode));
		}

		if(arg_ptr -> leftNode -> type == LISTOP) {
			t = linkTypes(t, findTypes(top, arg_ptr->leftNode));
		}
		else {
			if(arg_ptr -> leftNode -> type == ID || arg_ptr -> leftNode -> type == ARROP) {
				t = addType(t , checkTypes(top, arg_ptr -> leftNode));
			} else {
				t = addType(t, checkTypes(top, arg_ptr->leftNode));
			}
		}
		return t;
	}
	return NULL;
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
		case ADDOP: 	fprintf(stderr, "[ADDOP %s]", t->attribute.opval); break;
		case MULOP: 	fprintf(stderr, "[MULOP %s]", t->attribute.sval); break;
		case RELOP: 	fprintf(stderr, "[RELOP %s]", t->attribute.opval); break;
		case ASSIGNOP: 	fprintf(stderr, "[ASSIGNOP %s]", t->attribute.opval); break;
		case NOT: 		fprintf(stderr, "[NOT %s]", t->attribute.opval); break;
		case PROGRAM: 	fprintf(stderr, "[PROGRAM %s]", t->attribute.sval); break;
		case FUNCTION: 	fprintf(stderr, "[FUNCTION %s]", t->attribute.sval); break;
		case PROCEDURE: fprintf(stderr, "[PROCEDURE %s]", t->attribute.sval); break;
		case VAR: 		fprintf(stderr, "[VAR %s]", t->attribute.sval); break;
		case ARRAY: 	fprintf(stderr, "[ARRAY %s]", t->attribute.sval); break;
		case DOTDOT: 	fprintf(stderr, "[DOTDOT %s]", t->attribute.sval); break;
		case OF: 		fprintf(stderr, "[OF %s]", t->attribute.sval); break;
		case INTEGER: 	fprintf(stderr, "[INTEGER %s]", t->attribute.sval); break;
		case REAL: 		fprintf(stderr, "[REAL %s]", t->attribute.sval); break;
		case BBEGIN: 		fprintf(stderr, "[BBEGIN %s]", t->attribute.sval); break;
		case END: 		fprintf(stderr, "[END %s]", t->attribute.sval); break;
		case IF: 		fprintf(stderr, "[IF %s]", t->attribute.sval); break;
		case THEN: 		fprintf(stderr, "[THEN %s]", t->attribute.sval); break;
		case ELSE: 		fprintf(stderr, "[ELSE %s]", t->attribute.sval); break;
		case WHILE: 	fprintf(stderr, "[WHILE %s]", t->attribute.sval); break;
		case DO: 		fprintf(stderr, "[DO %s]", t->attribute.sval); break;
		case TO: 		fprintf(stderr, "[TO %s]", t->attribute.sval); break;
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
			exit(1);
	}
	
	fprintf(stderr, "\n");

	printTree(t->leftNode, spaces+1);
	printTree(t->rightNode, spaces+1);
			
}

