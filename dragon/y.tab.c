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
#include "tree.c"
#include "y.tab.h"
#include "externs.h"


#line 14 "pc.y"
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
#line 44 "y.tab.c"

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
#define RELOP 262
#define EQ 263
#define NQ 264
#define LT 265
#define LE 266
#define GT 267
#define GE 268
#define PLUS 269
#define MINUS 270
#define OR 271
#define MULOP 272
#define STAR 273
#define SLASH 274
#define AND 275
#define NOT 276
#define ID 277
#define INUM 278
#define RNUM 279
#define WHILE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define DO 284
#define FOR 285
#define EMPTY 286
#define START 287
#define PAROP 288
#define LISTOP 289
#define FUNCTION 290
#define PROCEDURE 291
#define DOTDOT 292
#define OF 293
#define INTEGER 294
#define REAL 295
#define VAR 296
#define ADDOP 297
#define ARROP 298
#define declaration 299
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   21,   20,   20,   19,   19,   18,   18,   17,   17,
   16,   16,   15,   26,   15,   27,   14,   14,   13,   13,
   12,   12,   11,   10,   10,    9,    9,    8,    8,    8,
    8,    8,    8,    8,    7,    7,    6,    6,    4,    4,
    5,    5,    3,    3,    3,    2,    2,    1,    1,    1,
    1,    1,    1,    1,   23,   23,   22,   24,   25,
};
static const short yylen[] = {                            2,
    1,   10,    1,    3,    6,    0,    1,    8,    1,    1,
    3,    0,    4,    0,    1,    0,    7,    4,    3,    0,
    3,    5,    3,    1,    0,    1,    3,    3,    1,    1,
    4,    6,    4,    7,    1,    4,    1,    4,    1,    3,
    1,    3,    1,    2,    3,    1,    3,    1,    4,    4,
    1,    1,    3,    2,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,   57,    0,    0,    0,    3,    0,    0,
    6,    4,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,   15,    0,    0,    0,    0,   29,    0,   26,
    0,    0,   30,    0,   16,    0,    2,    0,   11,    0,
    9,   10,    7,    0,    0,   58,   59,    0,    0,   46,
    0,    0,    0,    0,   51,   52,    0,    0,    0,    0,
   23,    0,    0,    0,    0,    0,    0,    0,    5,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,   27,    0,   39,    0,    0,    0,    0,   18,   13,
    0,   53,   47,    0,    0,   33,    0,    0,    0,    0,
   38,    0,   36,    0,   19,    0,    0,    0,   50,   49,
    0,    0,   40,    0,    0,   21,    0,   32,    0,   17,
    0,    0,   34,   22,    0,    8,
};
static const short yydgoto[] = {                          2,
   50,   51,   52,   83,   84,   28,   29,   30,   31,   32,
   33,   87,   66,   21,   22,   15,   43,   44,   13,    7,
    3,   54,    0,   55,   56,   23,   64,
};
static const short yysindex[] = {                      -234,
 -251,    0,    0,    0,  -10, -251,   39,    0,    1, -251,
    0,    0, -220, -251, -212,  -29, -176, -251, -251,   40,
    0,   32,    0, -223,  -40,  -40, -206,    0, -164,    0,
   43, -160,    0,  -22,    0,   63,    0, -220,    0,   15,
    0,    0,    0,   49,   -7,    0,    0,   -7,  -40,    0,
 -162, -248, -173,  -21,    0,    0, -169,   55,  -40, -176,
    0,  -40,  -40,   63, -251,   56, -212, -161,    0,    0,
 -162,   75,   -7,  -40,   -7,  -40,  -40,  -40, -176,  -40,
    0,    0,   44,    0,   25,   61,  -25,  -13,    0,    0,
 -171,    0,    0, -175, -162,    0,   51,   30, -159,   66,
    0,  -40,    0, -243,    0, -251, -223, -161,    0,    0,
 -176, -157,    0,   69,   29,    0,   36,    0,  -40,    0,
 -223, -163,    0,    0, -243,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -56,    0,   72,    0, -127,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -126,    0,    0,  -58,    0,   76,    0,  -56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -35,  -19,    0,  -39,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   78,    0,    0,   72,    0,    0,    0,
  -31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -9,   -3,    0,    0,    0,  -55,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -18,  -36,   60,   62,   18,    0,    0,  -43,    0,    0,
   -4,    0,   74,    0,    0,  102,  -83,  -32,  120,   -6,
    0,   47,    0,  -61,    0,    0,    0,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         49,
   37,   48,   12,   31,   48,   43,   91,   16,   43,   44,
   20,   71,   44,   74,   10,  105,   82,   62,   77,   48,
  114,   41,    1,   43,   41,    4,   70,   44,   24,    6,
   10,   42,   49,  106,   42,   99,   40,   45,   95,   41,
   45,  126,   53,   57,  107,   17,  117,    5,   75,   42,
   41,   42,    8,   48,   93,   45,   12,   43,   88,   11,
    8,   44,   90,   34,   35,   36,   72,  118,   63,   78,
   41,   42,   10,   41,  116,   14,   81,   18,   19,    9,
   85,   17,   10,   42,  101,   37,  121,  102,  124,   45,
   39,  109,   58,   96,  102,   98,   59,  100,   61,  115,
    4,   60,   65,   25,   26,   68,   34,   69,   27,   73,
   76,    8,   79,   80,   89,   92,   46,  103,  104,  113,
  108,   75,  110,  111,  112,   34,  119,  120,  122,  125,
   14,   25,   24,   94,   20,   20,  123,   86,   97,   67,
   38,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    8,    0,    0,    0,    0,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,   12,   35,   31,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   48,
    0,    0,   48,   43,   37,    0,   43,   44,    0,    0,
   44,    0,   48,   12,   12,   45,    4,   46,   47,   41,
    0,    0,   48,   48,   48,    0,   43,   43,   43,   42,
   44,   44,   44,    0,    0,   45,   48,   48,   45,    0,
    0,   43,   41,   41,   41,   44,    0,    0,   45,    4,
   46,   47,   42,   42,   42,    0,    0,    0,   45,   45,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   45,
};
static const short yycheck[] = {                         40,
   59,   41,   59,   59,   44,   41,   68,   14,   44,   41,
   15,   48,   44,  262,   44,   41,   60,   40,   40,   59,
  104,   41,  257,   59,   44,  277,   45,   59,   58,   40,
   44,   41,   40,   59,   44,   79,  260,   41,   75,   59,
   44,  125,   25,   26,   58,  258,  108,    1,  297,   59,
  294,  295,    6,   93,   73,   59,   10,   93,   65,   59,
   14,   93,   67,   17,   18,   19,   49,  111,   91,   91,
  294,  295,   44,   93,  107,  296,   59,  290,  291,   41,
   63,  258,   44,   93,   41,   46,   58,   44,  121,   93,
   59,   41,  299,   76,   44,   78,  261,   80,  259,  106,
  277,   59,   40,  280,  281,   91,   60,   59,  285,  272,
  284,   65,  282,   59,   59,   41,  278,   93,   58,  102,
  292,  297,   93,  283,   59,   79,  284,   59,   93,  293,
   59,  259,  259,   74,   59,   58,  119,   64,   77,   38,
   21,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  106,   -1,   -1,   -1,   -1,  111,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  259,  258,  261,  259,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
   -1,   -1,  262,  259,  283,   -1,  262,  259,   -1,   -1,
  262,   -1,  272,  290,  291,  276,  277,  278,  279,  259,
   -1,   -1,  282,  283,  284,   -1,  282,  283,  284,  259,
  282,  283,  284,   -1,   -1,  259,  297,  297,  262,   -1,
   -1,  297,  282,  283,  284,  297,   -1,   -1,  276,  277,
  278,  279,  282,  283,  284,   -1,   -1,   -1,  282,  283,
  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  297,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,"'+'","','","'-'","'.'",0,0,0,0,0,0,0,0,0,0,0,"':'",
"';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,
"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"PROGRAM","BBEGIN","END","ARRAY","ASSIGNOP","RELOP","EQ","NQ","LT",
"LE","GT","GE","PLUS","MINUS","OR","MULOP","STAR","SLASH","AND","NOT","ID",
"INUM","RNUM","WHILE","IF","THEN","ELSE","DO","FOR","EMPTY","START","PAROP",
"LISTOP","FUNCTION","PROCEDURE","DOTDOT","OF","INTEGER","REAL","VAR","ADDOP",
"ARROP","declaration",
};
static const char *yyrule[] = {
"$accept : start",
"start : program",
"program : PROGRAM id '(' identifier_list ')' ';' declarations subprogram_declarations compound_statement '.'",
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
"$$1 :",
"subprogram_declaration : $$1",
"$$2 :",
"subprogram_head : FUNCTION id $$2 arguments ':' standard_type ';'",
"subprogram_head : PROCEDURE id arguments ';'",
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
"statement : IF expression THEN statement",
"statement : IF expression THEN statement ELSE statement",
"statement : WHILE expression DO expression",
"statement : FOR declaration ';' expression ';' DO expression",
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
"factor : NOT factor",
"sign : '+'",
"sign : '-'",
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
#line 299 "pc.y"

int main() {

	// tree *t = intTree(ADDOP, 4, emptyTree(), emptyTree());
	// tree *y = intTree(ADDOP, 5, emptyTree(), emptyTree());
	// tree *r = intTree(ADDOP, 6, t, y);
	// printTree(r, 0);
	yyparse();

}






#line 393 "y.tab.c"

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
#line 88 "pc.y"
	{ printTree(yystack.l_mark[0].tval, 0); }
break;
case 2:
#line 98 "pc.y"
	{
		yyval.tval = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", yystack.l_mark[-8].tval, yystack.l_mark[-6].tval),
					strTree(PROGRAM, "decls compound_stmt",yystack.l_mark[-3].tval,
						strTree(PROGRAM, "decls sub_decls", yystack.l_mark[-1].tval, yystack.l_mark[-2].tval)
					)
				);
	}
break;
case 3:
#line 110 "pc.y"
	{yyval.tval = opTree(LISTOP, ",", yystack.l_mark[0].tval, emptyTree());}
break;
case 4:
#line 112 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 5:
#line 119 "pc.y"
	{yyval.tval = opTree(LISTOP, ":", opTree(VAR, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].tval);}
break;
case 6:
#line 121 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 7:
#line 126 "pc.y"
	{ yyval.tval = yyval.tval = yystack.l_mark[0].tval;}
break;
case 8:
#line 128 "pc.y"
	{yyval.tval = strTree(ARROP, "array range", opTree(DOTDOT, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].sval); }
break;
case 9:
#line 133 "pc.y"
	{yyval.tval = strTree(INTEGER, yystack.l_mark[0].sval, emptyTree(), emptyTree());}
break;
case 10:
#line 135 "pc.y"
	{ yyval.tval = strTree(REAL, yystack.l_mark[0].sval, emptyTree(), emptyTree());}
break;
case 11:
#line 140 "pc.y"
	{yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-2].tval, yystack.l_mark[-1].tval);}
break;
case 12:
#line 142 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 13:
#line 147 "pc.y"
	{yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-3].tval, 
					opTree(LISTOP, "_", yystack.l_mark[-2].tval, 
						opTree(LISTOP, "_", yystack.l_mark[-1].tval, yystack.l_mark[0].tval)
					)
				 );}
break;
case 14:
#line 152 "pc.y"
	{fprintf(stderr,"pop_current_scope()");}
break;
case 15:
#line 153 "pc.y"
	{yyval.tval =emptyTree();}
break;
case 16:
#line 157 "pc.y"
	{ fprintf(stderr, "push_new_scope()"); }
break;
case 17:
#line 158 "pc.y"
	{ yyval.tval = intTree(FUNCTION, yystack.l_mark[-6].ival, yystack.l_mark[-5].tval, yystack.l_mark[-4].tval ); }
break;
case 18:
#line 160 "pc.y"
	{ yyval.tval = intTree(PROCEDURE, yystack.l_mark[-3].ival, yystack.l_mark[-2].tval, yystack.l_mark[-1].tval);}
break;
case 19:
#line 166 "pc.y"
	{yyval.tval = yystack.l_mark[-1].tval;}
break;
case 20:
#line 168 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 21:
#line 173 "pc.y"
	{yyval.tval = opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 22:
#line 175 "pc.y"
	{ yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-4].tval, opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));}
break;
case 23:
#line 182 "pc.y"
	{ yyval.tval = strTree(BBEGIN, "Begin", yystack.l_mark[-1].tval, emptyTree()); }
break;
case 24:
#line 187 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 25:
#line 189 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 26:
#line 194 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 27:
#line 196 "pc.y"
	{ yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 28:
#line 201 "pc.y"
	{ yyval.tval = opTree(ASSIGNOP, "Assign", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 29:
#line 203 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 30:
#line 205 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 31:
#line 207 "pc.y"
	{yyval.tval = strTree(IF, "If-Then", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 32:
#line 210 "pc.y"
	{ yyval.tval = strTree(IF, "if then-else", yystack.l_mark[-4].tval, strTree(IF, "then else", yystack.l_mark[-2].tval, yystack.l_mark[0].tval)); }
break;
case 33:
#line 212 "pc.y"
	{yyval.tval = strTree(WHILE, "while do", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 35:
#line 218 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 36:
#line 220 "pc.y"
	{yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);}
break;
case 37:
#line 225 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 38:
#line 227 "pc.y"
	{ yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);}
break;
case 39:
#line 232 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 40:
#line 234 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 41:
#line 239 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 42:
#line 241 "pc.y"
	{ yyval.tval = opTree(RELOP, "simple expression", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 43:
#line 246 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 44:
#line 248 "pc.y"
	{yyval.tval = opTree(ADDOP, yystack.l_mark[-1].ival, intTree(INUM, 0, emptyTree(), emptyTree()), yystack.l_mark[0].tval);}
break;
case 45:
#line 250 "pc.y"
	{	yyval.tval = opTree(ADDOP, "Simple expression", yystack.l_mark[-2].tval, yystack.l_mark[0].tval)	;}
break;
case 46:
#line 255 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 47:
#line 257 "pc.y"
	{ yyval.tval = opTree(MULOP, yystack.l_mark[-1].sval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 48:
#line 262 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 49:
#line 264 "pc.y"
	{ yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval); }
break;
case 50:
#line 266 "pc.y"
	{
			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
		}
break;
case 51:
#line 270 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 52:
#line 272 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 53:
#line 274 "pc.y"
	{ yyval.tval = yystack.l_mark[-1].tval; }
break;
case 54:
#line 276 "pc.y"
	{ yyval.tval = opTree(NOT, yystack.l_mark[-1].opval, yystack.l_mark[0].tval, emptyTree()); }
break;
case 57:
#line 285 "pc.y"
	{ yyval.tval = strTree(ID, yystack.l_mark[0].sval, emptyTree(), emptyTree()); }
break;
case 58:
#line 290 "pc.y"
	{ yyval.tval = intTree(INUM, yystack.l_mark[0].ival, emptyTree(), emptyTree()); }
break;
case 59:
#line 294 "pc.y"
	{ yyval.tval = intTree(RNUM, yystack.l_mark[0].sval, emptyTree(), emptyTree()); }
break;
#line 836 "y.tab.c"
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
