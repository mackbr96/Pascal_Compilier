%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "externs.h"
#include "node.h"
#include "gencode.h"
#include "types.h"
#include "rstack.h"
#include "y.tab.h"


extern void updateVars(scope* , tree*, tree*);
extern void makeFunction(scope*, tree*);
extern void updateFunction(scope*, tree*, tree* , int);
extern void makeProgram(scope*, tree* );
extern void makeArray(scope* , char*, int, int, int );
extern void makeProcedure(scope*, tree*);
extern void updateProcedure(scope*, tree*, int);
extern void makeVar(scope*, tree*, tree* );
extern void makeParms(scope*, tree*, tree* );


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

%token <sval> STAR SLASH AND
%token <opval> MULOP
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
			//printTree($1, 0);
			fprintf(stderr, "\n");
		}
	;


program 
	: PROGRAM id {add_io_gencode();} '(' identifier_list ')'  ';' 
	declarations
	subprogram_declarations { main_header_gencode(); }
	compound_statement
	'.'
	{
		makeProgram(top_scope, $2);
		makeVar(top_scope, $5, strTree(INUM, $1, emptyTree(), emptyTree()));	
		
		$$ = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", $2, $5),
					strTree(PROGRAM, "decls compound_stmt",
						strTree(PROGRAM, "decls sub_decls", $8, $9), $11 
					)
				);

		main_footer_gencode();
		
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
		{$$ = strTree(INTEGER, "INUM TYPE", emptyTree(), emptyTree());}
	| REAL
		{ $$ = strTree(REAL, "RNUM TYPE", emptyTree(), emptyTree());}
	;

subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'
		{$$ = opTree(LISTOP, "_", $1, $2);}
	| 
		{$$ = emptyTree();}
	;

subprogram_declaration
	: subprogram_head declarations subprogram_declarations { function_header($1);} compound_statement
		{

			checkFunction(top_scope, $1, $5);
			//check the function for return statements here
			$$ = opTree(LISTOP, "_", $1, 
					opTree(LISTOP, "_", $2, 
						opTree(LISTOP, "_", $3, $5)
					)
				 );
			function_footer($1);
			top_scope = pop_scope(top_scope);
			
		}
	| 
		{
			$$ =emptyTree();
		}
	;

subprogram_head
	: FUNCTION id { tmp = top_scope; top_scope = push_scope(top_scope, $2->attribute.sval, FUNCTION); makeFunction(tmp, $2); } arguments ':' standard_type ';'
		{
			updateFunction(tmp, $2, $6, countArgs(top_scope, $4, 0));
			/*addArgs(top_scope, $2->attribute.sval, $4); */
			$$ = strTree(FUNCTION, $2->attribute.sval, $2, $4 ); 
		}
	| PROCEDURE id { tmp = top_scope; top_scope = push_scope(top_scope, $2->attribute.sval, PROCEDURE); makeProcedure(tmp, $2);  } arguments ';'
		{
			
			updateProcedure(tmp, $2, countArgs(top_scope, $4, 0));
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
			makeParms(top_scope, $1, $3);
			$$ = opTree(LISTOP, ":", $1, $3);
		}
	| parameter_list ';' identifier_list ':' type
		{
			makeParms(top_scope, $3, $5); 
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
			checkLocal(top_scope, $1);
			$$ = opTree(ASSIGNOP, "Assign", $1, $3); 
			assign_gencode($$);
		}
	| procedure_statement
		{
			$$ = $1;
			call_procedure_gencode($1);
		}
	| compound_statement
		{$$ = $1;}
	
	| IF expression {start_if($2);} THEN statement {mid_if($5);} ELSE statement
		{
			$$ = strTree(IF, "if then-else", $2, strTree(IF, "then else", $5, $8)); 
			enforce_type(top_scope, $2, BOOL);
			end_if($8);
		}
	| WHILE expression {start_while($2);} DO statement
		{
			$$ = strTree(WHILE, "while do", $2, $5);
			enforce_type(top_scope, $2, BOOL);	
			end_while($5);
		}
	| FOR variable ASSIGNOP expression TO expression DO statement
		{
			$$ = strTree(FOR, "for",
					opTree(ASSIGNOP, $3, $2, $4),
					strTree(TO, "to do", $6, $8));
			sameTypes(top_scope, $2, $4);
			sameTypes(top_scope, $2, $6);
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
			$$ = opTree(ARROP, $1->attribute.sval, $1, $3);
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

			//checkArgs(top_scope, $1, $3);
			fprintf(stderr, "NAME IS %s", $1->attribute.sval);
			checkArgs(top_scope, searchScopeAll(top_scope, $1->attribute.sval), $3);

			$$ = opTree(PAROP, "()", $1, $3);
			checkID(top_scope, $1->attribute.sval);
		}
	;

expression_list
	: expression
		{
			$$ = opTree(LISTOP, ",", emptyTree(), $1); 
			/*$$ = $1;*/
		}
	| expression_list ',' expression
		{ $$ = opTree(LISTOP, ",", $1, $3); }
	;

expression
	: simple_expression
		{
			tree* t = $1;
			checkTypes(top_scope, t);
			numberTree(t);
			$$ = t;
		}
	| simple_expression RELOP simple_expression 
		{ 
			tree* t = opTree(RELOP, $2, $1, $3);
			checkTypes(top_scope, t);
			numberTree(t);
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
			//checkArgs(top_scope, $1, $3);
			checkArgs(top_scope, searchScopeAll(top_scope, $1->attribute.sval), $3);
			checkID(top_scope, $1->attribute.sval);
			$$ = opTree(PAROP, "()", $1, $3);
			call_procedure_gencode($$);
			 
		}
	| inum
		{ $$ = $1; }
	| rnum
		{ $$ = $1; }
	| '(' expression ')'
		{ 	
			$$ = $2; 
		}
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
int L;
int offBase;
scope *top_scope;
scope* tmp;
stack* rstack;
FILE* outfile;
int main() {
	L = 2;
	offBase = 0;
	outfile = fopen("output.s", "w");
	top_scope = mkscope();
	top_scope->name = "main";
	top_scope -> parent = top_scope;
	insertScope(top_scope, "read");
	updateProcedure(top_scope, strTree(PROCEDURE, "read", emptyTree(), emptyTree()),  1);
	insertScope(top_scope, "write");
	updateProcedure(top_scope, strTree(PROCEDURE, "write", emptyTree(), emptyTree()),  1);


	rstack = (stack*)malloc(sizeof(stack));
	for(int i = 0; i < MAX_REGS; i++) {
		rstack->reg[i] = i;
	}
	rstack->idx = MAX_REGS - 1;
	file_header_gencode();
	yyparse();
	file_footer_gencode();

}





