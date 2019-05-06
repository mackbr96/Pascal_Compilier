#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pc.y"
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


#line 29 "pc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int ival;
	float fval;
	char *sval;
	char *opval;

	tree *tval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 59 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PROGRAM 257
#define BBEGIN 258
#define END 259
#define ARRAY 260
#define ASSIGNOP 261
#define BOOL 262
#define RELOP 263
#define EQ 264
#define NQ 265
#define LT 266
#define LE 267
#define GT 268
#define GE 269
#define PLUS 270
#define MINUS 271
#define OR 272
#define STAR 273
#define SLASH 274
#define AND 275
#define MULOP 276
#define NOT 277
#define ID 278
#define INUM 279
#define RNUM 280
#define WHILE 281
#define IF 282
#define THEN 283
#define ELSE 284
#define DO 285
#define FOR 286
#define EMPTY 287
#define START 288
#define PAROP 289
#define LISTOP 290
#define FUNCTION 291
#define PROCEDURE 292
#define DOTDOT 293
#define OF 294
#define INTEGER 295
#define REAL 296
#define VAR 297
#define ADDOP 298
#define ARROP 299
#define sign 300
#define TO 301
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   25,   26,   21,   20,   20,   19,   19,   18,   18,
   17,   17,   16,   16,   27,   15,   15,   28,   14,   29,
   14,   13,   13,   12,   12,   11,   10,   10,    9,    9,
    8,    8,    8,   30,   31,    8,   32,    8,   33,    8,
    7,    7,    6,    6,    4,    4,    5,    5,    3,    3,
    3,    2,    2,    1,    1,    1,    1,    1,    1,   34,
    1,   22,   23,   24,
};
static const short yylen[] = {                            2,
    1,    0,    0,   12,    1,    3,    6,    0,    1,    8,
    1,    1,    3,    0,    0,    5,    0,    0,    7,    0,
    5,    3,    0,    3,    5,    3,    1,    0,    1,    3,
    3,    1,    1,    0,    0,    8,    0,    5,    0,    9,
    1,    4,    1,    4,    1,    3,    1,    3,    1,    2,
    3,    1,    3,    1,    4,    4,    1,    1,    3,    0,
    3,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,   62,    2,    0,    0,    0,    5,    0,
    0,    8,    6,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,   18,   20,    0,   13,    0,    0,    0,
   11,   12,    9,    0,    0,    0,    0,    0,    0,    0,
   32,    0,   29,    0,    0,   33,    0,    4,    0,    7,
    0,    0,    0,    0,    0,   63,   64,    0,    0,   52,
    0,    0,   37,    0,   57,   58,   34,    0,    0,    0,
    0,   26,    0,    0,    0,    0,    0,    0,   21,   16,
   60,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   31,   30,    0,   45,    0,    0,   22,    0,    0,
    0,   61,   59,   53,    0,    0,    0,    0,    0,    0,
    0,   44,    0,   42,    0,    0,   24,   19,   38,   56,
   55,   35,    0,   46,    0,    0,    0,    0,    0,   25,
    0,   39,   10,   36,    0,   40,
};
static const short yydgoto[] = {                          2,
   60,   61,   62,   94,   95,   41,   42,   43,   44,   45,
   46,   76,   52,   20,   21,   16,   33,   34,   14,    8,
    3,   64,   65,   66,    6,   22,   54,   35,   36,   90,
  127,   87,  135,  102,
};
static const short yysindex[] = {                      -231,
 -246,    0,    0,    0,    0,   13, -246,  -17,    0,    6,
 -246,    0,    0, -217, -246, -261,  -29, -246, -246,    0,
   33, -157, -223,    0,    0, -217,    0, -204,   56,   12,
    0,    0,    0,   45,   67,   67, -261,  -39,  -39, -246,
    0, -153,    0,   51, -148,    0,  -21,    0, -167,    0,
 -246,   55,   57, -157,   -6,    0,    0,   -6,  -39,    0,
 -162, -256,    0,  -20,    0,    0,    0, -146,   26,  -39,
 -204,    0,  -39,  -39, -175,  -24,  -19, -209,    0,    0,
    0, -162,   79,   -6,  -39,   -6, -164,  -39,  -39, -160,
  -39,    0,    0,   50,    0,   32, -167,    0, -246, -223,
   65,    0,    0,    0, -172, -162, -204,   52,   34, -204,
 -173,    0,  -39,    0,   36,   31,    0,    0,    0,    0,
    0,    0,  -39,    0, -163, -223, -154, -152, -209,    0,
 -204,    0,    0,    0, -204,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -55,    0,  -57,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -55,    0, -125,    0,    0,
    0,    0,    0,    0,   77,   78,  -48,    0,    0,    0,
    0,    0,    0, -123,    0,    0,  -53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -36,   -3,    0,  -41,    0,    0,    0,    0, -122,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -31,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,   -8,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -34,   11,   53,   54,    9,    0,  100,  -26,    0,    0,
  -10,    0,  105,    0,    0,  117,  -69,  -86,  124,    7,
    0,   48,  -33,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 303
static const short yytable[] = {                         54,
   59,   17,   54,   14,   49,   43,   85,   49,  101,   50,
   17,   29,   50,  117,   11,   75,   98,   54,   73,   88,
   81,   17,   49,   10,   11,    1,   11,   50,   23,   18,
   19,    4,   51,   59,   99,   51,   30,   47,  100,  130,
   47,   86,   48,   80,   93,   48,   63,   67,    5,  104,
   51,   54,    7,   28,    9,   47,   49,   77,   13,  133,
   48,   50,    9,  115,   12,   24,   25,   83,   82,   74,
   89,   31,   32,    4,   11,   47,   38,   39,   92,   15,
  119,   40,   96,  122,   51,   31,   32,   69,  126,   47,
  112,   27,  120,  113,   48,  113,  106,  109,    9,  111,
   28,   48,   49,   50,  134,  116,   51,   70,  136,   71,
   72,   56,   78,   84,   91,   79,   74,   97,   47,  103,
  107,  124,  110,  118,  114,   86,  121,  123,  125,  131,
  129,  128,  132,   28,   23,   27,   23,  105,   41,   68,
   53,  108,   37,   26,    0,    0,    9,    0,    0,    0,
    0,    0,    0,    0,   47,    0,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   47,    0,
    0,    0,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,   14,    0,    0,   43,    0,   41,    0,   15,
    0,    0,    0,    0,    0,    0,    0,   54,    0,    0,
    0,   54,   49,    0,    0,    0,   49,   50,    0,    0,
   43,   50,    0,    0,   54,   14,   14,   55,    4,   56,
   57,   54,   54,   54,    0,    0,   49,   49,   49,    0,
   51,   50,   50,   50,   51,   47,   54,    0,   58,   54,
   48,   49,    0,    0,   49,    0,   50,    0,    0,   50,
   55,    4,   56,   57,   51,   51,   51,    0,    0,   47,
   47,   47,    0,    0,   48,   48,   48,    0,    0,   51,
    0,    0,   51,    0,    0,    0,    0,   47,    0,    0,
    0,    0,   48,
};
static const short yycheck[] = {                         41,
   40,   59,   44,   59,   41,   59,  263,   44,   78,   41,
   59,   22,   44,  100,   44,   49,   41,   59,   40,   40,
   55,   15,   59,   41,   44,  257,   44,   59,   58,  291,
  292,  278,   41,   40,   59,   44,  260,   41,   58,  126,
   44,  298,   41,   54,   71,   44,   38,   39,    1,   84,
   59,   93,   40,  258,    7,   59,   93,   51,   11,  129,
   59,   93,   15,   97,   59,   18,   19,   59,   58,   91,
   91,  295,  296,  278,   44,   28,  281,  282,   70,  297,
  107,  286,   74,  110,   93,  295,  296,   40,   58,   93,
   41,   59,   41,   44,   93,   44,   86,   89,   51,   91,
  258,   46,   91,   59,  131,   99,   40,  261,  135,   59,
  259,  279,   58,  276,  261,   59,   91,  293,   71,   41,
  285,  113,  283,   59,   93,  298,   93,  301,   93,  284,
  294,  123,  285,  259,   58,  259,   59,   85,  261,   40,
   36,   88,   26,   20,   -1,   -1,   99,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  107,   -1,   -1,  110,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  131,   -1,
   -1,   -1,  135,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  258,   -1,  258,   -1,   -1,  259,   -1,  261,   -1,  258,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,   -1,   -1,
   -1,  263,  259,   -1,   -1,   -1,  263,  259,   -1,   -1,
  284,  263,   -1,   -1,  276,  291,  292,  277,  278,  279,
  280,  283,  284,  285,   -1,   -1,  283,  284,  285,   -1,
  259,  283,  284,  285,  263,  259,  298,   -1,  298,  301,
  259,  298,   -1,   -1,  301,   -1,  298,   -1,   -1,  301,
  277,  278,  279,  280,  283,  284,  285,   -1,   -1,  283,
  284,  285,   -1,   -1,  283,  284,  285,   -1,   -1,  298,
   -1,   -1,  301,   -1,   -1,   -1,   -1,  301,   -1,   -1,
   -1,   -1,  301,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"PROGRAM","BBEGIN","END","ARRAY","ASSIGNOP","BOOL","RELOP","EQ","NQ","LT","LE",
"GT","GE","PLUS","MINUS","OR","STAR","SLASH","AND","MULOP","NOT","ID","INUM",
"RNUM","WHILE","IF","THEN","ELSE","DO","FOR","EMPTY","START","PAROP","LISTOP",
"FUNCTION","PROCEDURE","DOTDOT","OF","INTEGER","REAL","VAR","ADDOP","ARROP",
"sign","TO",
};
static const char *yyrule[] = {
"$accept : start",
"start : program",
"$$1 :",
"$$2 :",
"program : PROGRAM id $$1 '(' identifier_list ')' ';' declarations subprogram_declarations $$2 compound_statement '.'",
"identifier_list : id",
"identifier_list : identifier_list ',' id",
"declarations : declarations VAR identifier_list ':' type ';'",
"declarations :",
"type : standard_type",
"type : ARRAY '[' inum DOTDOT inum ']' OF standard_type",
"standard_type : INTEGER",
"standard_type : REAL",
"subprogram_declarations : subprogram_declarations subprogram_declaration ';'",
"subprogram_declarations :",
"$$3 :",
"subprogram_declaration : subprogram_head declarations subprogram_declarations $$3 compound_statement",
"subprogram_declaration :",
"$$4 :",
"subprogram_head : FUNCTION id $$4 arguments ':' standard_type ';'",
"$$5 :",
"subprogram_head : PROCEDURE id $$5 arguments ';'",
"arguments : '(' parameter_list ')'",
"arguments :",
"parameter_list : identifier_list ':' type",
"parameter_list : parameter_list ';' identifier_list ':' type",
"compound_statement : BBEGIN optional_statements END",
"optional_statements : statement_list",
"optional_statements :",
"statement_list : statement",
"statement_list : statement_list ';' statement",
"statement : variable ASSIGNOP expression",
"statement : procedure_statement",
"statement : compound_statement",
"$$6 :",
"$$7 :",
"statement : IF expression $$6 THEN statement $$7 ELSE statement",
"$$8 :",
"statement : WHILE expression $$8 DO statement",
"$$9 :",
"statement : FOR variable ASSIGNOP expression TO expression DO $$9 statement",
"variable : id",
"variable : id '[' expression ']'",
"procedure_statement : id",
"procedure_statement : id '(' expression_list ')'",
"expression_list : expression",
"expression_list : expression_list ',' expression",
"expression : simple_expression",
"expression : simple_expression RELOP simple_expression",
"simple_expression : term",
"simple_expression : ADDOP term",
"simple_expression : simple_expression ADDOP term",
"term : factor",
"term : term MULOP factor",
"factor : id",
"factor : id '[' expression ']'",
"factor : id '(' expression_list ')'",
"factor : inum",
"factor : rnum",
"factor : '(' expression ')'",
"$$10 :",
"factor : NOT factor $$10",
"id : ID",
"inum : INUM",
"rnum : RNUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 423 "pc.y"
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





#line 442 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 104 "pc.y"
	{ 
			print_scope(top_scope);
			/*printTree($1, 0);*/
			fprintf(stderr, "\n");
		}
break;
case 2:
#line 113 "pc.y"
	{add_io_gencode();}
break;
case 3:
#line 115 "pc.y"
	{ main_header_gencode(); }
break;
case 4:
#line 118 "pc.y"
	{
		makeProgram(top_scope, yystack.l_mark[-10].tval);
		makeVar(top_scope, yystack.l_mark[-7].tval, strTree(INUM, yystack.l_mark[-11].opval, emptyTree(), emptyTree()));	
		
		yyval.tval = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", yystack.l_mark[-10].tval, yystack.l_mark[-7].tval),
					strTree(PROGRAM, "decls compound_stmt",
						strTree(PROGRAM, "decls sub_decls", yystack.l_mark[-4].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].tval 
					)
				);

		main_footer_gencode();
		
	}
break;
case 5:
#line 136 "pc.y"
	{yyval.tval = opTree(LISTOP, ",", yystack.l_mark[0].tval, emptyTree());}
break;
case 6:
#line 138 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 7:
#line 145 "pc.y"
	{
			makeVar(top_scope, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			yyval.tval = opTree(LISTOP, ":", opTree(VAR, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].tval);
		}
break;
case 8:
#line 151 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 9:
#line 156 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 10:
#line 158 "pc.y"
	{ yyval.tval = strTree(ARRAY, "array range", opTree(DOTDOT, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[0].tval); }
break;
case 11:
#line 163 "pc.y"
	{yyval.tval = strTree(INTEGER, "INUM TYPE", emptyTree(), emptyTree());}
break;
case 12:
#line 165 "pc.y"
	{ yyval.tval = strTree(REAL, "RNUM TYPE", emptyTree(), emptyTree());}
break;
case 13:
#line 170 "pc.y"
	{yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-2].tval, yystack.l_mark[-1].tval);}
break;
case 14:
#line 172 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 15:
#line 176 "pc.y"
	{ function_header(yystack.l_mark[-2].tval);}
break;
case 16:
#line 177 "pc.y"
	{

			checkFunction(top_scope, yystack.l_mark[-4].tval, yystack.l_mark[0].tval);
			/*check the function for return statements here*/
			yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-4].tval, 
					opTree(LISTOP, "_", yystack.l_mark[-3].tval, 
						opTree(LISTOP, "_", yystack.l_mark[-2].tval, yystack.l_mark[0].tval)
					)
				 );
			function_footer(yystack.l_mark[-4].tval);
			top_scope = pop_scope(top_scope);
			
		}
break;
case 17:
#line 191 "pc.y"
	{
			yyval.tval =emptyTree();
		}
break;
case 18:
#line 197 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope, yystack.l_mark[0].tval->attribute.sval, FUNCTION); makeFunction(tmp, yystack.l_mark[0].tval); }
break;
case 19:
#line 198 "pc.y"
	{
			updateFunction(tmp, yystack.l_mark[-5].tval, yystack.l_mark[-1].tval, countArgs(top_scope, yystack.l_mark[-3].tval, 0));
			/*addArgs(top_scope, $2->attribute.sval, $4); */
			yyval.tval = strTree(FUNCTION, yystack.l_mark[-5].tval->attribute.sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval ); 
		}
break;
case 20:
#line 203 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope, yystack.l_mark[0].tval->attribute.sval, PROCEDURE); makeProcedure(tmp, yystack.l_mark[0].tval);  }
break;
case 21:
#line 204 "pc.y"
	{
			
			updateProcedure(tmp, yystack.l_mark[-3].tval, countArgs(top_scope, yystack.l_mark[-1].tval, 0));
			yyval.tval = strTree(PROCEDURE, yystack.l_mark[-3].tval->attribute.sval, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
		}
break;
case 22:
#line 213 "pc.y"
	{
			/*makeParms(top_scope, $2);*/
			yyval.tval = yystack.l_mark[-1].tval;
		}
break;
case 23:
#line 218 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 24:
#line 223 "pc.y"
	{
			makeParms(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			yyval.tval = opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
		}
break;
case 25:
#line 228 "pc.y"
	{
			makeParms(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-4].tval, opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));
		}
break;
case 26:
#line 237 "pc.y"
	{ yyval.tval = strTree(BBEGIN, "Begin", yystack.l_mark[-1].tval, emptyTree()); }
break;
case 27:
#line 242 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 28:
#line 244 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 29:
#line 249 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 30:
#line 251 "pc.y"
	{ yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 31:
#line 256 "pc.y"
	{
			sameTypes(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			checkLocal(top_scope, yystack.l_mark[-2].tval);
			yyval.tval = opTree(ASSIGNOP, "Assign", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			assign_gencode(yyval.tval);
		}
break;
case 32:
#line 263 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
			call_procedure_gencode(yystack.l_mark[0].tval);
		}
break;
case 33:
#line 268 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 34:
#line 270 "pc.y"
	{start_if(yystack.l_mark[0].tval);}
break;
case 35:
#line 270 "pc.y"
	{mid_if(yystack.l_mark[0].tval);}
break;
case 36:
#line 271 "pc.y"
	{
			yyval.tval = strTree(IF, "if then-else", yystack.l_mark[-6].tval, strTree(IF, "then else", yystack.l_mark[-3].tval, yystack.l_mark[0].tval)); 
			enforce_type(top_scope, yystack.l_mark[-6].tval, BOOL);
			end_if(yystack.l_mark[0].tval);
		}
break;
case 37:
#line 276 "pc.y"
	{start_while(yystack.l_mark[0].tval);}
break;
case 38:
#line 277 "pc.y"
	{
			yyval.tval = strTree(WHILE, "while do", yystack.l_mark[-3].tval, yystack.l_mark[0].tval);
			enforce_type(top_scope, yystack.l_mark[-3].tval, BOOL);	
			end_while(yystack.l_mark[0].tval);
		}
break;
case 39:
#line 282 "pc.y"
	{ start_for(yystack.l_mark[-5].tval,yystack.l_mark[-3].tval,yystack.l_mark[-1].tval);}
break;
case 40:
#line 283 "pc.y"
	{
			yyval.tval = strTree(FOR, "for",
					opTree(ASSIGNOP, yystack.l_mark[-6].opval, yystack.l_mark[-7].tval, yystack.l_mark[-5].tval),
					strTree(TO, "to do", yystack.l_mark[-3].tval, yystack.l_mark[0].tval));
			sameTypes(top_scope, yystack.l_mark[-7].tval, yystack.l_mark[-5].tval);
			sameTypes(top_scope, yystack.l_mark[-7].tval, yystack.l_mark[-3].tval);
			end_for(yystack.l_mark[-7].tval);
		}
break;
case 41:
#line 295 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 42:
#line 300 "pc.y"
	{
			yyval.tval = opTree(ARROP, yystack.l_mark[-3].tval->attribute.sval, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval); 
		}
break;
case 43:
#line 308 "pc.y"
	{ 
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 44:
#line 313 "pc.y"
	{

			/*checkArgs(top_scope, $1, $3);*/
			fprintf(stderr, "NAME IS %s", yystack.l_mark[-3].tval->attribute.sval);
			checkArgs(top_scope, searchScopeAll(top_scope, yystack.l_mark[-3].tval->attribute.sval), yystack.l_mark[-1].tval);

			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
			
		}
break;
case 45:
#line 327 "pc.y"
	{
			yyval.tval = opTree(LISTOP, ",", emptyTree(), yystack.l_mark[0].tval); 
			/*$$ = $1;*/
		}
break;
case 46:
#line 332 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 47:
#line 337 "pc.y"
	{
			tree* t = yystack.l_mark[0].tval;
			checkTypes(top_scope, t);
			numberTree(t);
			yyval.tval = t;
		}
break;
case 48:
#line 344 "pc.y"
	{ 
			tree* t = opTree(RELOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			checkTypes(top_scope, t);
			numberTree(t);
			yyval.tval = t;
		}
break;
case 49:
#line 354 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 50:
#line 356 "pc.y"
	{yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, intTree(INUM, 0, emptyTree(), emptyTree()), yystack.l_mark[0].tval);}
break;
case 51:
#line 358 "pc.y"
	{	yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval)	;}
break;
case 52:
#line 363 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 53:
#line 365 "pc.y"
	{ yyval.tval = opTree(MULOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 54:
#line 370 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval; 
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval); 
		}
break;
case 55:
#line 375 "pc.y"
	{ 
			yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval); 
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
		}
break;
case 56:
#line 380 "pc.y"
	{
			/*checkArgs(top_scope, $1, $3);*/
			checkArgs(top_scope, searchScopeAll(top_scope, yystack.l_mark[-3].tval->attribute.sval), yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			call_procedure_gencode(yyval.tval);
			 
		}
break;
case 57:
#line 389 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 58:
#line 391 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 59:
#line 393 "pc.y"
	{ 	
			yyval.tval = yystack.l_mark[-1].tval; 
		}
break;
case 60:
#line 397 "pc.y"
	{ yyval.tval = opTree(NOT, "NOT", yystack.l_mark[0].tval, emptyTree()); }
break;
case 61:
#line 399 "pc.y"
	{ /*sign
	: '+'
		{
	
		}
	| '-'
	;*/
 }
break;
case 62:
#line 409 "pc.y"
	{ yyval.tval = strTree(ID, yystack.l_mark[0].sval, emptyTree(), emptyTree()); }
break;
case 63:
#line 414 "pc.y"
	{ yyval.tval = intTree(INUM, yystack.l_mark[0].ival, emptyTree(), emptyTree()); }
break;
case 64:
#line 418 "pc.y"
	{ yyval.tval = fTree(RNUM, yystack.l_mark[0].fval, emptyTree(), emptyTree()); }
break;
#line 1031 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
