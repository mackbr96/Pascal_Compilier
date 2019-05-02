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
#define MULOP 273
#define STAR 274
#define SLASH 275
#define AND 276
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
    0,   25,   21,   20,   20,   19,   19,   18,   18,   17,
   17,   16,   16,   15,   15,   26,   14,   27,   14,   13,
   13,   12,   12,   11,   10,   10,    9,    9,    8,    8,
    8,   28,   29,    8,    8,    8,    7,    7,    6,    6,
    4,    4,    5,    5,    3,    3,    3,    2,    2,    1,
    1,    1,    1,    1,    1,   30,    1,   22,   23,   24,
};
static const short yylen[] = {                            2,
    1,    0,   11,    1,    3,    6,    0,    1,    8,    1,
    1,    3,    0,    4,    0,    0,    7,    0,    5,    3,
    0,    3,    5,    3,    1,    0,    1,    3,    3,    1,
    1,    0,    0,    8,    4,    8,    1,    4,    1,    4,
    1,    3,    1,    3,    1,    2,    3,    1,    3,    1,
    4,    4,    1,    1,    3,    0,    3,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,   58,    2,    0,    0,    0,    4,    0,
    0,    7,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    0,    0,    0,    0,    0,   30,    0,   27,
    0,    0,   31,    0,   16,   18,    3,    0,   12,    0,
   10,   11,    8,    0,    0,   59,   60,    0,    0,   48,
    0,    0,    0,    0,   53,   54,   32,    0,    0,    0,
    0,   24,    0,    0,    0,    0,    0,    0,    6,   56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,   28,    0,   41,    0,    0,    0,    0,   14,    0,
   57,   55,   49,    0,    0,   35,    0,    0,    0,    0,
   40,    0,   38,    0,    0,    0,   19,    0,   52,   51,
   33,    0,   42,   20,    0,    0,    0,    0,    0,    0,
    0,   22,   17,    0,    0,    0,    0,    0,   34,   36,
   23,    9,
};
static const short yydgoto[] = {                          2,
   50,   51,   52,   83,   84,   28,   29,   30,   31,   32,
   33,  104,   87,   22,   23,   16,   43,   44,   14,    8,
    3,   54,   55,   56,    6,   65,   66,   79,  119,   91,
};
static const short yysindex[] = {                      -229,
 -246,    0,    0,    0,    0,   -6, -246,   50,    0,  -10,
 -246,    0,    0, -244, -246, -211,   20, -242, -246, -246,
    9,    0,   30, -223,  -39,  -39, -246,    0, -202,    0,
   34, -191,    0,  -31,    0,    0,    0, -244,    0,   11,
    0,    0,    0,   53,   -5,    0,    0,   -5,  -39,    0,
 -160, -253, -171,  -21,    0,    0,    0, -146,   25,  -39,
 -242,    0,  -39,  -39,   78,   78, -211, -159,    0,    0,
 -160,   81,   -5,  -39,   -5, -242,  -39,  -39, -164,  -39,
    0,    0,   62,    0,   31, -246,   65,   66,    0, -167,
    0,    0,    0, -170, -160,    0,   67,   36, -242, -174,
    0,  -39,    0,   38,   40, -186,    0, -159,    0,    0,
    0,  -39,    0,    0, -246, -223,   71,   41, -151, -150,
   43,    0,    0, -158, -242, -242, -223, -186,    0,    0,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -57,    0,   79,    0, -122,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -120,    0,    0,  -53,    0,    0,    0,  -57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -36,   -3,    0,  -41,    0,    0,    0,    0, -121,    0,
    0,    0,    0,    0,   83,   84,   79,    0,    0,    0,
  -30,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
   13,  -33,   68,   69,    5,    0,  117,  -49,    0,    0,
    4,    0,   82,    0,    0,  107,  -32,  -28,  125,  -11,
    0,    6,  -46,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 308
static const short yytable[] = {                         50,
   49,   13,   50,   17,   45,   39,    5,   45,   63,   74,
   46,   82,    9,   46,   71,   18,   13,   50,   77,   21,
    9,   90,   45,   34,   35,   36,   96,    1,   46,   53,
   57,    4,   59,    7,   49,    4,   40,   43,   25,   26,
   43,   95,   44,   27,   75,   44,   18,   47,   12,  111,
   47,   50,   15,   72,   37,   43,   45,   70,   60,   64,
   44,  118,   46,   11,   81,   47,   34,   62,   85,   78,
   89,   41,   42,  117,  105,  129,  130,   24,  114,   19,
   20,   34,   98,   11,  100,   93,   11,  122,   39,   43,
   10,    9,   61,   11,   44,  132,  115,  116,  131,   47,
  127,   68,  101,  121,   34,  102,  113,  109,   41,   42,
  102,   69,   73,   76,   80,   64,  120,   86,   99,   46,
    9,   92,  106,  103,  107,  108,  112,   75,  110,  123,
   34,   34,  125,  124,  126,  128,   26,   15,   25,   37,
   21,   94,   21,   58,   67,   97,   38,   88,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   13,    0,    0,    0,    0,   39,    0,   37,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,    0,    0,
    0,   50,   45,    0,    0,    0,   45,    0,   46,    0,
   39,   50,   46,   13,   13,    0,    0,   45,    4,   46,
   47,   50,   50,   50,    0,    0,   45,   45,   45,    0,
    0,    0,   46,   46,   46,   43,   50,    0,   48,   50,
   44,   45,    0,    0,   45,   47,    0,   46,    0,   47,
   46,   45,    4,   46,   47,    0,    0,    0,    0,   43,
   43,   43,    0,    0,   44,   44,   44,    0,    0,   47,
   47,   47,    0,    0,    0,    0,    0,   43,    0,    0,
    0,    0,   44,    0,   47,    0,    0,   47,
};
static const short yycheck[] = {                         41,
   40,   59,   44,   15,   41,   59,    1,   44,   40,  263,
   41,   61,    7,   44,   48,  258,   11,   59,   40,   16,
   15,   68,   59,   18,   19,   20,   76,  257,   59,   25,
   26,  278,   27,   40,   40,  278,  260,   41,  281,  282,
   44,   75,   41,  286,  298,   44,  258,   41,   59,   99,
   44,   93,  297,   49,   46,   59,   93,   45,  261,   91,
   59,  108,   93,   44,   60,   59,   61,  259,   64,   91,
   67,  295,  296,  106,   86,  125,  126,   58,   41,  291,
  292,   76,   78,   44,   80,   73,   44,  116,   59,   93,
   41,   86,   59,   44,   93,  128,   59,   58,  127,   93,
   58,   91,   41,  115,   99,   44,  102,   41,  295,  296,
   44,   59,  273,  285,  261,   91,  112,   40,  283,  279,
  115,   41,   58,   93,   59,  293,  301,  298,   93,   59,
  125,  126,  284,   93,  285,  294,  259,   59,  259,  261,
   58,   74,   59,   27,   38,   77,   22,   66,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,  259,   -1,  261,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,   -1,   -1,
   -1,  263,  259,   -1,   -1,   -1,  263,   -1,  259,   -1,
  284,  273,  263,  291,  292,   -1,   -1,  277,  278,  279,
  280,  283,  284,  285,   -1,   -1,  283,  284,  285,   -1,
   -1,   -1,  283,  284,  285,  259,  298,   -1,  298,  301,
  259,  298,   -1,   -1,  301,  259,   -1,  298,   -1,  263,
  301,  277,  278,  279,  280,   -1,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,  283,  284,  285,   -1,   -1,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,  301,   -1,   -1,
   -1,   -1,  301,   -1,  298,   -1,   -1,  301,
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
"GT","GE","PLUS","MINUS","OR","MULOP","STAR","SLASH","AND","NOT","ID","INUM",
"RNUM","WHILE","IF","THEN","ELSE","DO","FOR","EMPTY","START","PAROP","LISTOP",
"FUNCTION","PROCEDURE","DOTDOT","OF","INTEGER","REAL","VAR","ADDOP","ARROP",
"sign","TO",
};
static const char *yyrule[] = {
"$accept : start",
"start : program",
"$$1 :",
"program : PROGRAM id $$1 '(' identifier_list ')' ';' declarations subprogram_declarations compound_statement '.'",
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
"subprogram_declaration : subprogram_head declarations subprogram_declarations compound_statement",
"subprogram_declaration :",
"$$2 :",
"subprogram_head : FUNCTION id $$2 arguments ':' standard_type ';'",
"$$3 :",
"subprogram_head : PROCEDURE id $$3 arguments ';'",
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
"$$4 :",
"$$5 :",
"statement : IF expression $$4 THEN statement $$5 ELSE statement",
"statement : WHILE expression DO statement",
"statement : FOR variable ASSIGNOP expression TO expression DO statement",
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
"$$6 :",
"factor : NOT factor $$6",
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
#line 415 "pc.y"
int L;
scope *top_scope;
scope* tmp;
stack* rstack;
FILE* outfile;
int main() {
	L = 2;
	outfile = fopen("output.s", "w");
	top_scope = mkscope();
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





#line 430 "y.tab.c"

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
#line 103 "pc.y"
	{ 
			print_scope(top_scope);
			printTree(yystack.l_mark[0].tval, 0);
			fprintf(stderr, "\n");
		}
break;
case 2:
#line 112 "pc.y"
	{add_io_gencode(); main_header_gencode();}
break;
case 3:
#line 117 "pc.y"
	{
		makeProgram(top_scope, yystack.l_mark[-9].tval);
		makeVar(top_scope, yystack.l_mark[-6].tval, strTree(INUM, yystack.l_mark[-10].opval, emptyTree(), emptyTree()));	
		
		yyval.tval = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", yystack.l_mark[-9].tval, yystack.l_mark[-6].tval),
					strTree(PROGRAM, "decls compound_stmt",
						strTree(PROGRAM, "decls sub_decls", yystack.l_mark[-3].tval, yystack.l_mark[-2].tval), yystack.l_mark[-1].tval 
					)
				);

		main_footer_gencode();
		
	}
break;
case 4:
#line 135 "pc.y"
	{yyval.tval = opTree(LISTOP, ",", yystack.l_mark[0].tval, emptyTree());}
break;
case 5:
#line 137 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 6:
#line 144 "pc.y"
	{
			makeVar(top_scope, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			yyval.tval = opTree(LISTOP, ":", opTree(VAR, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].tval);
		}
break;
case 7:
#line 150 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 8:
#line 155 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 9:
#line 157 "pc.y"
	{ yyval.tval = strTree(ARRAY, "array range", opTree(DOTDOT, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[0].tval); }
break;
case 10:
#line 162 "pc.y"
	{yyval.tval = strTree(INTEGER, "INUM TYPE", emptyTree(), emptyTree());}
break;
case 11:
#line 164 "pc.y"
	{ yyval.tval = strTree(REAL, "RNUM TYPE", emptyTree(), emptyTree());}
break;
case 12:
#line 169 "pc.y"
	{yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-2].tval, yystack.l_mark[-1].tval);}
break;
case 13:
#line 171 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 14:
#line 176 "pc.y"
	{

			checkFunction(top_scope, yystack.l_mark[-3].tval, yystack.l_mark[0].tval);
			/*check the function for return statements here*/
			yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-3].tval, 
					opTree(LISTOP, "_", yystack.l_mark[-2].tval, 
						opTree(LISTOP, "_", yystack.l_mark[-1].tval, yystack.l_mark[0].tval)
					)
				 );
				top_scope = pop_scope(top_scope);
		}
break;
case 15:
#line 188 "pc.y"
	{
			yyval.tval =emptyTree();
		}
break;
case 16:
#line 194 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope, yystack.l_mark[0].tval->attribute.sval, FUNCTION); makeFunction(tmp, yystack.l_mark[0].tval); }
break;
case 17:
#line 195 "pc.y"
	{
			updateFunction(tmp, yystack.l_mark[-5].tval, yystack.l_mark[-1].tval, countArgs(top_scope, yystack.l_mark[-3].tval, 0));
			/*addArgs(top_scope, $2->attribute.sval, $4); */
			yyval.tval = strTree(FUNCTION, yystack.l_mark[-5].tval->attribute.sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval ); 
		}
break;
case 18:
#line 200 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope, yystack.l_mark[0].tval->attribute.sval, PROCEDURE); makeProcedure(tmp, yystack.l_mark[0].tval);  }
break;
case 19:
#line 201 "pc.y"
	{
			
			updateProcedure(tmp, yystack.l_mark[-3].tval, countArgs(top_scope, yystack.l_mark[-1].tval, 0));
			yyval.tval = strTree(PROCEDURE, yystack.l_mark[-3].tval->attribute.sval, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
		}
break;
case 20:
#line 210 "pc.y"
	{
			/*makeParms(top_scope, $2);*/
			yyval.tval = yystack.l_mark[-1].tval;
		}
break;
case 21:
#line 215 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 22:
#line 220 "pc.y"
	{
			makeParms(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			yyval.tval = opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
		}
break;
case 23:
#line 225 "pc.y"
	{
			makeParms(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-4].tval, opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));
		}
break;
case 24:
#line 234 "pc.y"
	{ yyval.tval = strTree(BBEGIN, "Begin", yystack.l_mark[-1].tval, emptyTree()); }
break;
case 25:
#line 239 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 26:
#line 241 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 27:
#line 246 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 28:
#line 248 "pc.y"
	{ yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 29:
#line 253 "pc.y"
	{
			sameTypes(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			checkLocal(top_scope, yystack.l_mark[-2].tval);
			yyval.tval = opTree(ASSIGNOP, "Assign", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			assign_gencode(yyval.tval);
		}
break;
case 30:
#line 260 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
			call_procedure_gencode(yystack.l_mark[0].tval);
		}
break;
case 31:
#line 265 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 32:
#line 267 "pc.y"
	{start_if(yystack.l_mark[0].tval);}
break;
case 33:
#line 267 "pc.y"
	{mid_if(yystack.l_mark[0].tval);}
break;
case 34:
#line 268 "pc.y"
	{
			yyval.tval = strTree(IF, "if then-else", yystack.l_mark[-6].tval, strTree(IF, "then else", yystack.l_mark[-3].tval, yystack.l_mark[0].tval)); 
			enforce_type(top_scope, yystack.l_mark[-6].tval, BOOL);
			end_if(yystack.l_mark[0].tval);
		}
break;
case 35:
#line 274 "pc.y"
	{
			yyval.tval = strTree(WHILE, "while do", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			enforce_type(top_scope, yystack.l_mark[-2].tval, BOOL);	
		}
break;
case 36:
#line 279 "pc.y"
	{
			yyval.tval = strTree(FOR, "for",
					opTree(ASSIGNOP, yystack.l_mark[-5].opval, yystack.l_mark[-6].tval, yystack.l_mark[-4].tval),
					strTree(TO, "to do", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));
			sameTypes(top_scope, yystack.l_mark[-6].tval, yystack.l_mark[-4].tval);
			sameTypes(top_scope, yystack.l_mark[-6].tval, yystack.l_mark[-2].tval);
		}
break;
case 37:
#line 290 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 38:
#line 295 "pc.y"
	{
			yyval.tval = opTree(ARROP, yystack.l_mark[-3].tval->attribute.sval, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval); 
		}
break;
case 39:
#line 303 "pc.y"
	{ 
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 40:
#line 308 "pc.y"
	{

			/*checkArgs(top_scope, $1, $3);*/
			checkArgs(top_scope, searchScopeAll(top_scope, yystack.l_mark[-3].tval->attribute.sval), yystack.l_mark[-1].tval);

			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
		}
break;
case 41:
#line 320 "pc.y"
	{
			yyval.tval = opTree(LISTOP, ",", emptyTree(), yystack.l_mark[0].tval); 
			/*$$ = $1;*/
		}
break;
case 42:
#line 325 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 43:
#line 330 "pc.y"
	{
			tree* t = yystack.l_mark[0].tval;
			checkTypes(top_scope, t);
			numberTree(t);
			yyval.tval = t;
		}
break;
case 44:
#line 337 "pc.y"
	{ 
			tree* t = opTree(RELOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			checkTypes(top_scope, t);
			numberTree(t);
			yyval.tval = t;
		}
break;
case 45:
#line 347 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 46:
#line 349 "pc.y"
	{yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, intTree(INUM, 0, emptyTree(), emptyTree()), yystack.l_mark[0].tval);}
break;
case 47:
#line 351 "pc.y"
	{	yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval)	;}
break;
case 48:
#line 356 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 49:
#line 358 "pc.y"
	{ yyval.tval = opTree(MULOP, yystack.l_mark[-1].sval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 50:
#line 363 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval; 
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval); 
		}
break;
case 51:
#line 368 "pc.y"
	{ 
			yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval); 
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
		}
break;
case 52:
#line 373 "pc.y"
	{
			/*checkArgs(top_scope, $1, $3);*/
			checkArgs(top_scope, searchScopeAll(top_scope, yystack.l_mark[-3].tval->attribute.sval), yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			 
		}
break;
case 53:
#line 381 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 54:
#line 383 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 55:
#line 385 "pc.y"
	{ 	
			yyval.tval = yystack.l_mark[-1].tval; 
		}
break;
case 56:
#line 389 "pc.y"
	{ yyval.tval = opTree(NOT, "NOT", yystack.l_mark[0].tval, emptyTree()); }
break;
case 57:
#line 391 "pc.y"
	{ /*sign
	: '+'
		{
	
		}
	| '-'
	;*/
 }
break;
case 58:
#line 401 "pc.y"
	{ yyval.tval = strTree(ID, yystack.l_mark[0].sval, emptyTree(), emptyTree()); }
break;
case 59:
#line 406 "pc.y"
	{ yyval.tval = intTree(INUM, yystack.l_mark[0].ival, emptyTree(), emptyTree()); }
break;
case 60:
#line 410 "pc.y"
	{ yyval.tval = fTree(RNUM, yystack.l_mark[0].fval, emptyTree(), emptyTree()); }
break;
#line 996 "y.tab.c"
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
