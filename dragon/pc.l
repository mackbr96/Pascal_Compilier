
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "node.h"
#include "y.tab.h"

#define DEBUG 1

extern char *strdup( const char * );
int lineNum = 1;

int yyerror(char* msg);

%}

number 	[0-9]+
ident		[A-Za-z][A-Za-z0-9]*
comment	[(][*][^*]*[*][)]
div [/][^/]
whitespace [ \t]+


%option yylineno

%%

"if"			{if(DEBUG == 1) fprintf(stderr, "[IF]");  yylval.sval = strdup(yytext); return IF;}
"to"			{if(DEBUG == 1) fprintf(stderr, "[TO]");  yylval.sval = strdup(yytext); return TO;}
"then"		{if(DEBUG == 1) fprintf(stderr, "[THEN]");  yylval.sval = strdup(yytext); return THEN;}
"while"		{if(DEBUG == 1) fprintf(stderr, "[WHILE]");  yylval.sval = strdup(yytext); return WHILE;}
"do"			{if(DEBUG == 1) fprintf(stderr, "[DO]");  yylval.sval = strdup(yytext); return DO;}
"else"		{if(DEBUG == 1) fprintf(stderr, "[ELSE]");  yylval.sval = strdup(yytext); return ELSE;}
"for"			{if(DEBUG == 1) fprintf(stderr, "[FOR]");  yylval.sval = strdup(yytext); return FOR;}

"integer"	{if(DEBUG == 1) fprintf(stderr, "[INTEGER]"); yylval.sval = strdup(yytext); return INTEGER;}
"real"		{if(DEBUG == 1) fprintf(stderr, "[REAL]"); yylval.sval = strdup(yytext); return REAL;}

":="			{if(DEBUG == 1) fprintf(stderr, "[ASSIGNOP]"); yylval.opval = strdup(yytext); return ASSIGNOP;}
"<>"			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", NQ); yylval.opval = strdup(yytext); return RELOP;}
"="			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", EQ); yylval.opval = strdup(yytext); return RELOP;}
"<"			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", LT); yylval.opval = strdup(yytext); return RELOP;}
">"			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", GT); yylval.opval = strdup(yytext); return RELOP;}
"<="			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", LE); yylval.opval = strdup(yytext); return RELOP;}
">="			{if(DEBUG == 1) fprintf(stderr, "[RELOP:%d]", LE); yylval.opval = strdup(yytext); return RELOP;}
"+"			{if(DEBUG == 1) fprintf(stderr, "[ADDOP:%d]", PLUS); yylval.opval = strdup(yytext); return ADDOP;}
"-"			{if(DEBUG == 1) fprintf(stderr, "[ADDOP:%d]", MINUS); yylval.opval = strdup(yytext); return ADDOP;}
"/"			{if(DEBUG == 1) fprintf(stderr, "[MULOP:%d]", SLASH); yylval.opval = strdup(yytext); return MULOP;}
"div"			{if(DEBUG == 1) fprintf(stderr, "[MULOP:%d]", SLASH); yylval.opval = "/"; return MULOP;}
"mod"			{if(DEBUG == 1) fprintf(stderr, "[MULOP:%d]", SLASH); yylval.opval = "%"; return MULOP;}
"or"			{if(DEBUG == 1) fprintf(stderr, "[ADDOP:%d]", OR); yylval.opval= strdup(yytext); return ADDOP;}


"*"			{if(DEBUG == 1) fprintf(stderr, "[MULOP:%d]", STAR);  yylval.sval = strdup(yytext); return MULOP;}
"and"			{if(DEBUG == 1) fprintf(stderr, "[MULOP:%d]", AND);  yylval.sval = strdup(yytext); return RELOP;}
"array"		{if(DEBUG == 1) fprintf(stderr, "[ARRAY]");  yylval.sval = strdup(yytext); return ARRAY;}

"("			{if(DEBUG == 1) fprintf(stderr, "{(}"); return '(';}
")"			{if(DEBUG == 1) fprintf(stderr, "{)}"); return ')';}
";"			{if(DEBUG == 1) fprintf(stderr, "{;}"); return ';';}
"]"			{if(DEBUG == 1) fprintf(stderr, "{]}"); return ']';}
"["			{if(DEBUG == 1) fprintf(stderr, "{[}"); return '[';}
","			{if(DEBUG == 1) fprintf(stderr, "{,}"); return ',';}
":"			{if(DEBUG == 1) fprintf(stderr, "{:}"); return ':';}
"."			{if(DEBUG == 1) fprintf(stderr, "{.}"); return '.';}

"//".*\n		{if(DEBUG == 1) fprintf(stderr, "[COMMENT]\n"); lineNum++;}


"program"	{if(DEBUG == 1) fprintf(stderr, "TOKENIZER\n\n_________\n\n1. [PROGRAM]");  yylval.sval = strdup(yytext); return PROGRAM;}
"var"			{if(DEBUG == 1) fprintf(stderr, "[VAR]");  yylval.sval = strdup(yytext); return VAR;}
"of"			{if(DEBUG == 1) fprintf(stderr, "[OF]");  yylval.sval = strdup(yytext); return OF;}
".."			{if(DEBUG == 1) fprintf(stderr, "[DOTDOT]");  yylval.sval = strdup(yytext); return DOTDOT;}
"procedure" {if(DEBUG == 1) fprintf(stderr, "[PROCEDURE]");  yylval.sval = strdup(yytext); return PROCEDURE;}
"function"  {if(DEBUG == 1) fprintf(stderr, "[FUNCTION]");  yylval.sval = strdup(yytext); return FUNCTION;}
"begin"		{if(DEBUG == 1) fprintf(stderr, "[BEGIN %s]", yytext);  yylval.sval = strdup(yytext); return BBEGIN;}
"end"			{if(DEBUG == 1) fprintf(stderr, "[END]");  yylval.sval = strdup(yytext); return END;}

{comment} {if(DEBUG == 1) fprintf(stderr, "[COMMENT]"); }
{number}		{if(DEBUG == 1) fprintf(stderr, "[INUM:%d]", atoi(yytext)); yylval.ival = atoi(yytext); return INUM;	}
{number}"."{number} {if(DEBUG == 1) fprintf(stderr, "[RNUM:%f]", atof(yytext)); yylval.fval = atof(yytext); return RNUM; }
{ident}		{if(DEBUG == 1) fprintf(stderr, "[ID:%s]", yylval.sval = strdup(yytext)); yylval.sval = strdup(yytext); return ID;		}

		
{whitespace} ;
\n				{if(DEBUG == 1) fprintf(stderr, "\n%d. ", yylineno);lineNum++;}

.				{if(DEBUG == 1) fprintf(stderr, "Unknown char [ %s ] on line %d", yytext, lineNum); yyerror("Unkown Char");}

%%

int yyerror(char *msg) {
	fprintf(stderr, "\nError: %s on line: %d\n", msg, yylineno);
	exit(1);
}


