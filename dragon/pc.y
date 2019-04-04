%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"
#include "externs.h"
#include "node.h"

extern void updateVars(scope* , tree*, tree*);
extern void makeFunction(scope*, tree*, tree* );
extern void makeProgram(scope*, tree* ) ;
extern void makeArray(scope* , char*, int, int, int );
extern void makeVar(scope*, tree*, tree* );
extern void makeProcedure(scope*, tree*);


%}



%union {
	int ival;
	float fval;
	char *sval;
	char *opval;

	tree *tval;
}

%token <opval> PROGRAM
%token BBEGIN END ARRAY 

%token <opval> ASSIGNOP
%token <opval> BOOL
%token <opval> RELOP EQ NQ LT LE GT GE

%token  PLUS MINUS OR

%token <sval> MULOP STAR SLASH AND
%token <opval> NOT
%token <sval> ID
%token <ival> INUM 
%token <fval> RNUM
%token <sval> WHILE
%token <sval> IF
%token THEN ELSE  DO FOR
%token EMPTY 
%token START
%token PAROP
%token <sval> LISTOP
%token <ival> FUNCTION
%token <ival> PROCEDURE
%token <sval> DOTDOT 
%token <sval> OF
%token <sval> INTEGER
%token <sval> REAL
%token <sval> VAR
%token <opval> ADDOP



%token <sval> ARROP
%token <sval> LISTOP
%type <tval> factor
%type <tval> term
%type <tval> simple_expression
%type <tval> expression_list
%type <tval> expression
%type <tval> procedure_statement
%type <tval> variable
%type <tval> statement
%type <tval> statement_list
%type <tval> optional_statements
%type <tval> compound_statement
%type <tval> parameter_list
%type <tval> arguments
%type <tval> subprogram_head
%type <tval> subprogram_declaration
%type <tval> subprogram_declarations
%type <tval> standard_type
%type <tval> type
%type <tval> declarations
%type <tval> identifier_list
%type <tval> program
%type <tval> id
%type <tval> sign
%type <tval> inum
%type <tval> rnum


%%

start
	: program
		{ 
			print_scope(top_scope);
			printTree($1, 0);
			fprintf(stderr, "\n");
		}
	;


program 
	: PROGRAM id  '(' identifier_list ')'  ';' 
	declarations
	subprogram_declarations
	compound_statement
	'.'
	{
		makeProgram(top_scope, $2);
		makeVar(top_scope, $4, strTree(INUM, $1, emptyTree(), emptyTree()));	
		
		$$ = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", $2, $4),
					strTree(PROGRAM, "decls compound_stmt",
						strTree(PROGRAM, "decls sub_decls", $7, $8), $9 
					)
				);


		
	}
	;

identifier_list
	:  id
		{$$ = opTree(LISTOP, ",", $1, emptyTree());}
	|  identifier_list ',' id
		{ $$ = opTree(LISTOP, ",", $1, $3);}
	

	;

declarations
	: declarations VAR identifier_list ':' type ';'
		{
			makeVar(top_scope, $3, $5);
			$$ = opTree(LISTOP, ":", opTree(VAR, $2, $1, $3), $5);
		}

	| /* EMPTY */
		{ $$ = emptyTree();}
	;

type
	: standard_type
		{ $$ = $1;}
	| ARRAY '[' inum DOTDOT inum ']' OF standard_type
		{ $$ = strTree(ARRAY, "array range", opTree(DOTDOT, $4, $3, $5), $8); }
	;

standard_type
	: INTEGER
		{$$ = strTree(INUM, $1, emptyTree(), emptyTree());}
	| REAL
		{ $$ = strTree(RNUM, $1, emptyTree(), emptyTree());}
	;

subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'
		{$$ = opTree(LISTOP, "_", $1, $2);}
	| 
		{$$ = emptyTree();}
	;

subprogram_declaration
	: subprogram_head declarations subprogram_declarations compound_statement
		{

			checkFunction(top_scope, $1, $4);
			//check the function for return statements here
			$$ = opTree(LISTOP, "_", $1, 
					opTree(LISTOP, "_", $2, 
						opTree(LISTOP, "_", $3, $4)
					)
				 );
				top_scope = pop_scope(top_scope);
		}
	| 
		{
			$$ =emptyTree();
		}
	;

subprogram_head
	: FUNCTION id { tmp = top_scope; top_scope = push_scope(top_scope);} arguments ':' standard_type ';'
		{
			makeFunction(tmp, $2, $6); 
			$$ = strTree(FUNCTION, $2->attribute.sval, $2, $4 ); 
		}
	| PROCEDURE id { tmp = top_scope; top_scope = push_scope(top_scope);   } arguments ';'
		{
			
			makeProcedure(tmp, $2);
			$$ = strTree(PROCEDURE, $2->attribute.sval, $2, $4);
		}
	;

arguments 
	: '(' parameter_list ')'
		{
			//makeParms(top_scope, $2);
			$$ = $2;
		}
	|
		{ $$ = emptyTree();}
	;

parameter_list
	: identifier_list ':' type
		{
			makeVar(top_scope, $1, $3);
			$$ = opTree(LISTOP, ":", $1, $3);
		}
	| parameter_list ';' identifier_list ':' type
		{
			makeVar(top_scope, $3, $5); 
			$$ = opTree(LISTOP, ";", $1, opTree(LISTOP, ":", $3, $5));
		}
	;



compound_statement
	: BBEGIN optional_statements END
		{ $$ = strTree(BBEGIN, "Begin", $2, emptyTree()); }
	;

optional_statements
	: statement_list
		{ $$ = $1;}
	| 
		{$$ = emptyTree();}
	;

statement_list
	: statement
		{ $$ = $1;}
	| statement_list ';' statement
		{ $$ = opTree(LISTOP, ";", $1, $3);}
	;

statement
	: variable ASSIGNOP expression
		{
			sameTypes(top_scope, $1, $3);
			$$ = opTree(ASSIGNOP, "Assign", $1, $3); 
		}
	| procedure_statement
		{
			$$ = $1;
		}
	| compound_statement
		{$$ = $1;}
	| IF expression THEN statement
		{
			$$ = strTree(IF, "If-Then", $2, $4); 
			enforce_type(top_scope, $2, BOOL);
		}
		
	| IF expression THEN statement ELSE statement
		{
			$$ = strTree(IF, "if then-else", $2, strTree(IF, "then else", $4, $6)); 
			enforce_type(top_scope, $2, BOOL);
		}
	| WHILE expression DO statement
		{
			$$ = strTree(WHILE, "while do", $2, $4);
			enforce_type(top_scope, $2, BOOL);	
		}
	| FOR variable ASSIGNOP expression TO expression DO statement
		{
			$$ = strTree(FOR, "for",
					opTree(ASSIGNOP, $3, $2, $4),
					strTree(TO, "to do", $6, $8));
		}
	;

variable
	: id 
		{
			$$ = $1;
			checkID(top_scope, $1->attribute.sval);
		}
	| id '[' expression ']'
		{
			$$ = opTree(ARROP, "[]", $1, $3);
			checkID(top_scope, $1->attribute.sval); 
		}
	;

procedure_statement
	: id 
		{ 
			$$ = $1;
			checkID(top_scope, $1->attribute.sval);
		}
	| id '('  expression_list ')'
		{ 
			$$ = opTree(PAROP, "()", $1, $3);
			checkID(top_scope, $1->attribute.sval);
		}
	;

expression_list
	: expression
		{$$ = $1;}
	| expression_list ',' expression
		{ $$ = opTree(LISTOP, ",", $1, $3); }
	;

expression
	: simple_expression
		{
			tree* t = $1;
			checkTypes(top_scope, t);
			$$ = t;
		}
	| simple_expression RELOP simple_expression 
		{ 
			tree* t = opTree(RELOP, $2, $1, $3);
			checkTypes(top_scope, t);
			$$ = t;
		}
	;

simple_expression
	: term
		{$$ = $1;}
	| ADDOP term
		{$$ = opTree(ADDOP, $1, intTree(INUM, 0, emptyTree(), emptyTree()), $2);}
	| simple_expression ADDOP term
		{	$$ = opTree(ADDOP, $2, $1, $3)	;}
	;

term
	: factor
		{$$ = $1;}
	| term MULOP factor
		{ $$ = opTree(MULOP, $2, $1, $3); }
	;

factor
	: id
		{
			$$ = $1; 
			checkID(top_scope, $1->attribute.sval); 
		}
	| id '[' expression ']'
		{ 
			$$ = opTree(ARROP, "[]", $1, $3); 
			checkID(top_scope, $1->attribute.sval);
		}
	| id '(' expression_list ')'
		{
			$$ = opTree(PAROP, "()", $1, $3);
			checkID(top_scope, $1->attribute.sval); 
		}
	| inum
		{ $$ = $1; }
	| rnum
		{ $$ = $1; }
	| '(' expression ')'
		{ $$ = $2; }
	| NOT factor
		{ $$ = opTree(NOT, "NOT", $2, emptyTree()); }
		
 { /*sign
	: '+'
		{
	
		}
	| '-'
	;*/
 }
id
	: ID
		 { $$ = strTree(ID, $1, emptyTree(), emptyTree()); }
	;

inum
	: INUM
		{ $$ = intTree(INUM, $1, emptyTree(), emptyTree()); }
	;
rnum
	: RNUM
		{ $$ = fTree(RNUM, $1, emptyTree(), emptyTree()); }
	;


%%

scope *top_scope;
scope* tmp;
int main() {
	top_scope = mkscope();
	// tree *t = intTree(ADDOP, 4, emptyTree(), emptyTree());
	// tree *y = intTree(ADDOP, 5, emptyTree(), emptyTree());
	// tree *r = intTree(ADDOP, 6, t, y);
	// printTree(r, 0);
	yyparse();

	//print_scope(top_scope);

}





