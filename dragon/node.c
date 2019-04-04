#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"
#include "tree.h"
#include "externs.h"
#include "y.tab.h"

extern char *strdup( const char * );

node *mknode(char* s) {
    node *p = (node *)malloc(sizeof(node));
    assert(p != NULL);

    p->name = strdup(s);
    p -> next = NULL;

    return p;
}


node *searchNode(node* top, char* s) {
    node *p = top;

    while( p != NULL) {
        if(strcmp(p -> name, s) == 0) {
            return p;
        }
        p = p -> next;
    }

    return NULL;
}

node *insertNode(node* top, char* s) {
    node *p = mknode(s);
    p -> next = top;
    top = p;

    return top;
}


scope *mkscope() {
    scope *p = (scope *)malloc(sizeof(scope));
    assert(p != NULL);

    for (int i = 0; i < HASH_SIZE; i++ ) {
        p -> table[i] = NULL;
    }

    p -> next = NULL;

    return p;
}


void freeScope(scope* s) {

}

scope *push_scope(scope* top) {
    scope *p = mkscope();
    p->next = top;
    return p;
}

scope *pop_scope(scope* top) {
   if(top == NULL) return NULL;
    print_scope(top);
    scope *p = top -> next;
    
    freeScope(top);
    return p;
}



void makeFunction(scope *top, tree* name, tree* type_ptr) {
	node* n = insertScope(top, name->attribute.sval);

	n -> type = FUNCTION; 
	n -> returnType = type_ptr->type;
	//n -> returnType = INUM;
}

void makeProcedure(scope* top, tree* name) {
    node* n = insertScope(top, name->attribute.sval);

	n -> type = PROCEDURE; 
}    

void makeProgram(scope* top, tree* name) {
    node* n = insertScope(top, name->attribute.sval);

    n -> type = PROGRAM;


}

void makeArray(scope* top, char* name, int type, int start_idx, int end_idx) {
	node* n = insertScope(top, name);
	n -> type = ARRAY;
	n -> returnType = type;
	n -> start_idx = start_idx;
	n -> end_idx = end_idx;

}



void makeVar(scope* top, tree* var_ptr, tree* type_ptr) {
    
	if(type_ptr -> type == ARRAY) {
		int var_type = type_ptr -> rightNode -> type;
		type_ptr = type_ptr -> leftNode;

		if(type_ptr -> type != DOTDOT) {
			yyerror("Array index missing DOTDOT");
		}

		if(type_ptr ->leftNode -> type != INUM || type_ptr -> rightNode -> type != INUM) {
			yyerror("Array Index must be intergal");
		}

		int start_idx = type_ptr -> leftNode -> attribute.ival;
		int end_idx = type_ptr -> rightNode -> attribute.ival;
		char* var_name = var_ptr->leftNode->attribute.sval;
		makeArray(top, var_name, var_type, start_idx, end_idx);
	}
	
	 
    else {
        if(var_ptr -> type != LISTOP) {
            node* n = insertScope(top, var_ptr-> attribute.sval );
            n -> type = type_ptr -> type; 
        }
        
        if(var_ptr -> rightNode-> type != EMPTY) {
            makeVar(top, var_ptr->rightNode, type_ptr);
        }

        if(var_ptr -> leftNode -> type != EMPTY) {
            makeVar(top, var_ptr->leftNode, type_ptr);
        }
    }
	 
}


void makeParms(scope* top, tree* var_ptr) {
    tree* type_ptr = var_ptr -> rightNode;
    var_ptr = var_ptr -> leftNode;




   
}


void print_scope(scope* s) {

    fprintf(stderr, "\n\nHASH TABLE\n");

    for(int i = 0; i < 75; i++)
		fprintf(stderr, "_");
    fprintf(stderr, "\n");

    for(int i = 0; i < HASH_SIZE; i++) {
        node* entry = s->table[i];
        if(entry != NULL) {
            switch(entry -> type) {

            case(INUM):
                fprintf(stderr, "Name: %s\t\t Type: Integer\n", entry->name);
                break;
            
            case(RNUM):
                fprintf(stderr, "Name: %s\t\t Type: Real\n", entry->name);
                break;

            case(PROCEDURE):
                 fprintf(stderr, "Name: %s\t Type: Procedure\n", entry->name);
                 break;
			case(FUNCTION):
                fprintf(stderr, "Name: %s\t Type: Function \tReturn Type: %s\n", entry->name, typeToString(entry->returnType));
                break;
            case(PROGRAM):
                 fprintf(stderr, "Name: %s\t Type: Program\n", entry->name);
                 break;
                
            case(ARRAY):
                fprintf(stderr, "Name: %s\t\t Type: ARRAY \t Return Type: %s\n", entry->name, typeToString(entry->returnType));
                break;
                
            default:
                fprintf(stderr, "NOT DONE YET: %s\t%d\n", entry->name, entry->type);
            }
        }
    
    
    }

    fprintf(stderr, "\n\n");

}

node *searchScopeAll(scope* top, char* name) {
    scope *p = top;
    node *tmp;
    while(p != NULL) {
        tmp = searchScope(p, name);
        if(tmp != NULL) {
            return tmp;
        }
        p = p->next;
    }
    return NULL;
}

node *searchScope(scope* top, char* name) {
    int index = hashpjw(name);
    node *tmp = top -> table[index];
    return searchNode(tmp, name);
}

node *insertScope(scope* top, char* name) {
     if(searchScope(top, name) != NULL) {
         char *result = malloc(strlen("Redeclaration: ") + strlen(name) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
        strcpy(result, "Redeclaration: ");
        strcat(result, name);
        yyerror(result);
    }
    int index = hashpjw(name);
    node *tmp = top -> table[index];
    top->table[index] = insertNode(tmp, name);
    return top->table[index];

}

char* stringCat(char *s1, char *s2) {
        char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
        strcpy(result, s1);
        strcat(result, s2);
        return result;
}

char* typeToString(int token)
{
	switch(token)
	{
		case RNUM:
			return "REAL";
		case INUM:
			return "INT";
		case BOOL:
			return "BOOL";
		case PROGRAM:
			return "i/o";
		case EMPTY:
			return "EMPTY";
		case INTEGER:
			return "integer keyword"; // BAD!
		case REAL:
			return "real keyword"; // BAD!
		case ADDOP:
			return "ADDOP";
		case MULOP:
			return "MULOP";
		case RELOP:
			return "RELOP";
		case ASSIGNOP:
			return "ASSIGNOP";
		case NOT:
			return "NOT";
			
		case ARRAY:
			return "ARRAY";
		case PAROP:
			return "PAROP";
		case LISTOP:
			return "LISTOP";

		case ID:
			return "ID";

		default:
			fprintf(stderr, "OTHER: %d\n", token);
			return "other";
	}
}








void checkID(scope* top, char* name) {
    if(searchScopeAll(top, name) == NULL) {
        char* result = stringCat("Undeclared: ", name);
        yyerror(result);
    }
}



int hashpjw( char *s )
{
	char *p; 
	unsigned h = 0, g; 

	for ( p = s; *p != '\0'; p++ ) 
	{ 
		h = (h << 4) + (*p); 
		if ( g = h & 0xf0000000 ) 
		{ 
			h = h ^ ( g >> 24 ); 
			h = h ^ g; 
		} 
	} 
	return h % HASH_SIZE; 
}
