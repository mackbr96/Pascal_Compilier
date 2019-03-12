%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.c"
#include "y.tab.h"
#include "externs.h"


%}



%union {
	int ival;
	float fval;
	char *sval;
	char *opval;

	tree *tval;
}

%token <pval> PROGRAM
%token BBEGIN END ARRAY 

%token <opval> ASSIGNOP

%token <opval> RELOP EQ NQ LT LE GT GE

%token  PLUS MINUS OR

%token <sval> MULOP STAR SLASH AND
%token <opval> NOT
%token <sval> ID
%token <ival> INUM 
%token <sval> RNUM
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
%token <ival> ADDOP



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
		{ printTree($1, 0); }
	;


program 
	: PROGRAM id  '(' identifier_list ')'  ';' 
	declarations
	subprogram_declarations
	compound_statement
	'.'
	{
		$$ = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", $2, $4),
					strTree(PROGRAM, "decls compound_stmt",$7,
						strTree(PROGRAM, "decls sub_decls", $9, $8)
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
		{$$ = opTree(LISTOP, ":", opTree(VAR, $2, $1, $3), $5);}
	| /* EMPTY */
		{ $$ = emptyTree();}
	;

type
	: standard_type
		{ $$ = $$ = $1;}
	| ARRAY '[' inum DOTDOT inum ']' OF standard_type
		{$$ = strTree(ARROP, "array range", opTree(DOTDOT, $4, $3, $5), $7); }
	;

standard_type
	: INTEGER
		{$$ = strTree(INTEGER, $1, emptyTree(), emptyTree());}
	| REAL
		{ $$ = strTree(REAL, $1, emptyTree(), emptyTree());}
	;

subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'
		{$$ = opTree(LISTOP, "_", $1, $2);}
	| 
		{$$ = emptyTree();}
	;

subprogram_declaration
	: subprogram_head declarations subprogram_declarations compound_statement
		{$$ = opTree(LISTOP, "_", $1, 
					opTree(LISTOP, "_", $2, 
						opTree(LISTOP, "_", $3, $4)
					)
				 );}
	| {fprintf(stderr,"pop_current_scope()");}
		{$$ =emptyTree();}
	;

subprogram_head
	: FUNCTION id { fprintf(stderr, "push_new_scope()"); } arguments ':' standard_type ';'
		{ $$ = intTree(FUNCTION, $1, $2, $3 ); }
	| PROCEDURE id arguments ';'
		{ $$ = intTree(PROCEDURE, $1, $2, $3);}

	;

arguments 
	: '(' parameter_list ')'
		{$$ = $2;}
	|
		{ $$ = emptyTree();}
	;

parameter_list
	: identifier_list ':' type
		{$$ = opTree(LISTOP, ":", $1, $3);}
	| parameter_list ';' identifier_list ':' type
		{ $$ = opTree(LISTOP, ";", $1, opTree(LISTOP, ":", $3, $5));}
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
		{ $$ = opTree(ASSIGNOP, "Assign", $1, $3); }
	| procedure_statement
		{$$ = $1;}
	| compound_statement
		{$$ = $1;}
	| IF expression THEN statement
		{$$ = strTree(IF, "If-Then", $2, $4); }
		
	| IF expression THEN statement ELSE statement
		{ $$ = strTree(IF, "if then-else", $2, strTree(IF, "then else", $4, $6)); }
	| WHILE expression DO expression
		{$$ = strTree(WHILE, "while do", $2, $4);}
	| FOR declaration ';' expression ';' DO expression
	;

variable
	: id 
		{$$ = $1;}
	| id '[' expression ']'
		{$$ = opTree(ARROP, "[]", $1, $3);}
	;

procedure_statement
	: id 
		{ $$ = $1;}
	| id '('  expression_list ')'
		{ $$ = opTree(PAROP, "()", $1, $3);}
	;

expression_list
	: expression
		{$$ = $1;}
	| expression_list ',' expression
		{ $$ = opTree(LISTOP, ",", $1, $3); }
	;

expression
	: simple_expression
		{$$ = $1;}
	| simple_expression RELOP simple_expression 
		{ $$ = opTree(RELOP, "simple expression", $1, $3);}
	;

simple_expression
	: term
		{$$ = $1;}
	| ADDOP term
		{$$ = opTree(ADDOP, $1, intTree(INUM, 0, emptyTree(), emptyTree()), $2);}
	| simple_expression ADDOP term
		{	$$ = opTree(ADDOP, "Simple expression", $1, $3)	;}
	;

term
	: factor
		{$$ = $1;}
	| term MULOP factor
		{ $$ = opTree(MULOP, $2, $1, $3); }
	;

factor
	: id
		{ $$ = $1; }
	| id '[' expression ']'
		{ $$ = opTree(ARROP, "[]", $1, $3); }
	| id '(' expression_list ')'
		{
			$$ = opTree(PAROP, "()", $1, $3);
		}
	| inum
		{ $$ = $1; }
	| rnum
		{ $$ = $1; }
	| '(' expression ')'
		{ $$ = $2; }
	| NOT factor
		{ $$ = opTree(NOT, $1, $2, emptyTree()); }
		
sign
	: '+'
	| '-'
	;

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
		{ $$ = intTree(RNUM, $1, emptyTree(), emptyTree()); }
	;


%%

int main() {

	// tree *t = intTree(ADDOP, 4, emptyTree(), emptyTree());
	// tree *y = intTree(ADDOP, 5, emptyTree(), emptyTree());
	// tree *r = intTree(ADDOP, 6, t, y);
	// printTree(r, 0);
	yyparse();

}






