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
#include "y.tab.h"
#include "externs.h"
#include "node.h"

extern void updateVars(scope* , tree*, tree*);
extern void makeFunction(scope*, tree*, tree* );
extern void makeProgram(scope*, tree* ) ;
extern void makeArray(scope* , char*, int, int, int );
extern void makeVar(scope*, tree*, tree* );
extern void makeProcedure(scope*, tree*);


#line 22 "pc.y"
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
#line 52 "y.tab.c"

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
    0,   21,   20,   20,   19,   19,   18,   18,   17,   17,
   16,   16,   15,   15,   25,   14,   26,   14,   13,   13,
   12,   12,   11,   10,   10,    9,    9,    8,    8,    8,
    8,    8,    8,    8,    7,    7,    6,    6,    4,    4,
    5,    5,    3,    3,    3,    2,    2,    1,    1,    1,
    1,    1,    1,   27,    1,   22,   23,   24,
};
static const short yylen[] = {                            2,
    1,   10,    1,    3,    6,    0,    1,    8,    1,    1,
    3,    0,    4,    0,    0,    7,    0,    5,    3,    0,
    3,    5,    3,    1,    0,    1,    3,    3,    1,    1,
    4,    6,    4,    8,    1,    4,    1,    4,    1,    3,
    1,    3,    1,    2,    3,    1,    3,    1,    4,    4,
    1,    1,    3,    0,    3,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,   56,    0,    0,    0,    3,    0,    0,
    6,    4,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    0,    0,    0,    0,   29,    0,   26,    0,
    0,   30,    0,   15,   17,    2,    0,   11,    0,    9,
   10,    7,    0,    0,   57,   58,    0,    0,   46,    0,
    0,    0,    0,   51,   52,    0,    0,    0,    0,    0,
   23,    0,    0,    0,    0,    0,    0,    5,   54,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   27,    0,   39,    0,    0,    0,    0,   13,    0,   55,
   53,   47,    0,    0,   33,    0,    0,    0,    0,   38,
    0,   36,    0,    0,    0,   18,    0,   50,   49,    0,
    0,   40,   19,    0,    0,    0,    0,   32,    0,    0,
   21,   16,    0,    0,    0,    0,   34,   22,    8,
};
static const short yydgoto[] = {                          2,
   49,   50,   51,   82,   83,   27,   28,   29,   30,   31,
   32,  103,   86,   21,   22,   15,   42,   43,   13,    7,
    3,   53,   54,   55,   64,   65,   90,
};
static const short yysindex[] = {                      -240,
 -256,    0,    0,    0,   -1, -256,   57,    0,  -22, -256,
    0,    0, -239, -256, -222,   33, -199, -256, -256,   35,
    0,   26, -241,  -39,  -39, -256,    0, -168,    0,   38,
 -150,    0,  -31,    0,    0,    0, -239,    0,   20,    0,
    0,    0,   53,   -5,    0,    0,   -5,  -39,    0, -160,
 -253, -171,  -27,    0,    0, -167, -146,   28,  -39, -199,
    0,  -39,  -39,   77,   77, -222, -161,    0,    0, -160,
   79,   -5,  -39,   -5, -199,  -39,  -39, -199,  -39,    0,
    0,   62,    0,   29, -256,   63,   66,    0, -170,    0,
    0,    0, -169, -160,    0,   64,   34, -154, -166,    0,
  -39,    0,   27,   36, -224,    0, -161,    0,    0, -199,
  -39,    0,    0, -256, -241,   72,   39,    0, -152,   52,
    0,    0, -157, -199, -241, -224,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -57,    0,   75,    0, -120,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -119,
    0,    0,  -53,    0,    0,    0,  -57,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -36,
   -3,    0,  -41,    0,    0,    0,    0, -118,    0,    0,
    0,    0,    0,   83,   85,   75,    0,    0,    0,  -30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    7,    0,    0,    0,  -55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    3,  -21,   69,   70,   25,    0,  119,  -48,    0,    0,
    1,    0,   82,    0,    0,  111,  -84,  -81,  128,   -7,
    0,   14,  -42,    0,    0,    0,    0,
};
#define YYTABLESIZE 308
static const short yytable[] = {                         48,
   48,   12,   48,   31,   43,   37,   16,   43,   62,   73,
   44,   81,   76,   44,    5,   20,    1,   48,   39,    8,
  116,    4,   43,   12,   89,   70,   95,    8,   44,   98,
   33,   34,   35,  121,   48,   17,   11,   41,    6,   58,
   41,  129,   42,  128,   74,   42,   69,   45,   52,   56,
   45,   48,   94,   40,   41,   41,   43,   14,   17,   63,
   42,  118,   44,   77,  117,   45,   88,  113,   18,   19,
   40,   41,   71,   33,   92,  127,   10,  104,    4,   10,
   36,   24,   25,   80,   38,  114,   26,   84,   33,   41,
   23,   33,   59,  115,   42,   10,   60,    9,    8,   45,
   10,   97,  100,   99,  108,  101,  120,  101,   61,  125,
   67,   68,   72,   75,   79,   78,   85,   45,   63,   91,
  105,  102,  107,   33,  106,  112,  109,    8,   74,  110,
  122,  123,  124,   14,  111,  119,  126,   33,   25,   24,
   20,   93,   35,   20,   57,   96,   87,   66,   37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   12,    0,    0,   31,    0,   37,    0,   35,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,    0,
    0,   48,   43,    0,    0,    0,   43,    0,   44,    0,
   37,   48,   44,   12,   12,    0,    0,   44,    4,   45,
   46,   48,   48,   48,    0,    0,   43,   43,   43,    0,
    0,    0,   44,   44,   44,   41,   48,    0,   47,   48,
   42,   43,    0,    0,   43,   45,    0,   44,    0,   45,
   44,   44,    4,   45,   46,    0,    0,    0,    0,   41,
   41,   41,    0,    0,   42,   42,   42,    0,    0,   45,
   45,   45,    0,    0,    0,    0,    0,   41,    0,    0,
    0,    0,   42,    0,   45,    0,    0,   45,
};
static const short yycheck[] = {                         41,
   40,   59,   44,   59,   41,   59,   14,   44,   40,  263,
   41,   60,   40,   44,    1,   15,  257,   59,  260,    6,
  105,  278,   59,   10,   67,   47,   75,   14,   59,   78,
   17,   18,   19,  115,   40,  258,   59,   41,   40,   26,
   44,  126,   41,  125,  298,   44,   44,   41,   24,   25,
   44,   93,   74,  295,  296,   59,   93,  297,  258,   91,
   59,  110,   93,   91,  107,   59,   66,   41,  291,  292,
  295,  296,   48,   60,   72,  124,   44,   85,  278,   44,
   46,  281,  282,   59,   59,   59,  286,   63,   75,   93,
   58,   78,  261,   58,   93,   44,   59,   41,   85,   93,
   44,   77,   41,   79,   41,   44,  114,   44,  259,   58,
   91,   59,  273,  285,  261,  283,   40,  279,   91,   41,
   58,   93,  293,  110,   59,  101,   93,  114,  298,  284,
   59,   93,  285,   59,  301,  111,  294,  124,  259,  259,
   58,   73,  261,   59,   26,   76,   65,   37,   21,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  258,   -1,   -1,  259,   -1,  259,   -1,  261,   -1,   -1,
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
"subprogram_declaration :",
"$$1 :",
"subprogram_head : FUNCTION id $$1 arguments ':' standard_type ';'",
"$$2 :",
"subprogram_head : PROCEDURE id $$2 arguments ';'",
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
"$$3 :",
"factor : NOT factor $$3",
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
#line 393 "pc.y"

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





#line 407 "y.tab.c"

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
#line 96 "pc.y"
	{ 
			print_scope(top_scope);
			printTree(yystack.l_mark[0].tval, 0);
			fprintf(stderr, "\n");
		}
break;
case 2:
#line 110 "pc.y"
	{
		makeProgram(top_scope, yystack.l_mark[-8].tval);
		makeVar(top_scope, yystack.l_mark[-6].tval, strTree(INUM, yystack.l_mark[-9].opval, emptyTree(), emptyTree()));	
		
		yyval.tval = strTree(PROGRAM, "head body",
					opTree(PAROP, "()", yystack.l_mark[-8].tval, yystack.l_mark[-6].tval),
					strTree(PROGRAM, "decls compound_stmt",
						strTree(PROGRAM, "decls sub_decls", yystack.l_mark[-3].tval, yystack.l_mark[-2].tval), yystack.l_mark[-1].tval 
					)
				);


		
	}
break;
case 3:
#line 128 "pc.y"
	{yyval.tval = opTree(LISTOP, ",", yystack.l_mark[0].tval, emptyTree());}
break;
case 4:
#line 130 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 5:
#line 137 "pc.y"
	{
			makeVar(top_scope, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			yyval.tval = opTree(LISTOP, ":", opTree(VAR, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[-1].tval);
		}
break;
case 6:
#line 143 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 7:
#line 148 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 8:
#line 150 "pc.y"
	{ yyval.tval = strTree(ARRAY, "array range", opTree(DOTDOT, yystack.l_mark[-4].sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval), yystack.l_mark[0].tval); }
break;
case 9:
#line 155 "pc.y"
	{yyval.tval = strTree(INUM, yystack.l_mark[0].sval, emptyTree(), emptyTree());}
break;
case 10:
#line 157 "pc.y"
	{ yyval.tval = strTree(RNUM, yystack.l_mark[0].sval, emptyTree(), emptyTree());}
break;
case 11:
#line 162 "pc.y"
	{yyval.tval = opTree(LISTOP, "_", yystack.l_mark[-2].tval, yystack.l_mark[-1].tval);}
break;
case 12:
#line 164 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 13:
#line 169 "pc.y"
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
case 14:
#line 181 "pc.y"
	{
			yyval.tval =emptyTree();
		}
break;
case 15:
#line 187 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope);}
break;
case 16:
#line 188 "pc.y"
	{
			makeFunction(tmp, yystack.l_mark[-5].tval, yystack.l_mark[-1].tval); 
			yyval.tval = strTree(FUNCTION, yystack.l_mark[-5].tval->attribute.sval, yystack.l_mark[-5].tval, yystack.l_mark[-3].tval ); 
		}
break;
case 17:
#line 192 "pc.y"
	{ tmp = top_scope; top_scope = push_scope(top_scope);   }
break;
case 18:
#line 193 "pc.y"
	{
			
			makeProcedure(tmp, yystack.l_mark[-3].tval);
			yyval.tval = strTree(PROCEDURE, yystack.l_mark[-3].tval->attribute.sval, yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
		}
break;
case 19:
#line 202 "pc.y"
	{
			/*makeParms(top_scope, $2);*/
			yyval.tval = yystack.l_mark[-1].tval;
		}
break;
case 20:
#line 207 "pc.y"
	{ yyval.tval = emptyTree();}
break;
case 21:
#line 212 "pc.y"
	{
			makeVar(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			yyval.tval = opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
		}
break;
case 22:
#line 217 "pc.y"
	{
			makeVar(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-4].tval, opTree(LISTOP, ":", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));
		}
break;
case 23:
#line 227 "pc.y"
	{ yyval.tval = strTree(BBEGIN, "Begin", yystack.l_mark[-1].tval, emptyTree()); }
break;
case 24:
#line 232 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 25:
#line 234 "pc.y"
	{yyval.tval = emptyTree();}
break;
case 26:
#line 239 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval;}
break;
case 27:
#line 241 "pc.y"
	{ yyval.tval = opTree(LISTOP, ";", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);}
break;
case 28:
#line 246 "pc.y"
	{
			sameTypes(top_scope, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			yyval.tval = opTree(ASSIGNOP, "Assign", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
		}
break;
case 29:
#line 251 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
		}
break;
case 30:
#line 255 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 31:
#line 257 "pc.y"
	{
			yyval.tval = strTree(IF, "If-Then", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			enforce_type(top_scope, yystack.l_mark[-2].tval, BOOL);
		}
break;
case 32:
#line 263 "pc.y"
	{
			yyval.tval = strTree(IF, "if then-else", yystack.l_mark[-4].tval, strTree(IF, "then else", yystack.l_mark[-2].tval, yystack.l_mark[0].tval)); 
			enforce_type(top_scope, yystack.l_mark[-4].tval, BOOL);
		}
break;
case 33:
#line 268 "pc.y"
	{
			yyval.tval = strTree(WHILE, "while do", yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			enforce_type(top_scope, yystack.l_mark[-2].tval, BOOL);	
		}
break;
case 34:
#line 273 "pc.y"
	{
			yyval.tval = strTree(FOR, "for",
					opTree(ASSIGNOP, yystack.l_mark[-5].opval, yystack.l_mark[-6].tval, yystack.l_mark[-4].tval),
					strTree(TO, "to do", yystack.l_mark[-2].tval, yystack.l_mark[0].tval));
		}
break;
case 35:
#line 282 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 36:
#line 287 "pc.y"
	{
			yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval); 
		}
break;
case 37:
#line 295 "pc.y"
	{ 
			yyval.tval = yystack.l_mark[0].tval;
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval);
		}
break;
case 38:
#line 300 "pc.y"
	{ 
			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
		}
break;
case 39:
#line 308 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 40:
#line 310 "pc.y"
	{ yyval.tval = opTree(LISTOP, ",", yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 41:
#line 315 "pc.y"
	{
			tree* t = yystack.l_mark[0].tval;
			checkTypes(top_scope, t);
			yyval.tval = t;
		}
break;
case 42:
#line 321 "pc.y"
	{ 
			tree* t = opTree(RELOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval);
			checkTypes(top_scope, t);
			yyval.tval = t;
		}
break;
case 43:
#line 330 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 44:
#line 332 "pc.y"
	{yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, intTree(INUM, 0, emptyTree(), emptyTree()), yystack.l_mark[0].tval);}
break;
case 45:
#line 334 "pc.y"
	{	yyval.tval = opTree(ADDOP, yystack.l_mark[-1].opval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval)	;}
break;
case 46:
#line 339 "pc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 47:
#line 341 "pc.y"
	{ yyval.tval = opTree(MULOP, yystack.l_mark[-1].sval, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 48:
#line 346 "pc.y"
	{
			yyval.tval = yystack.l_mark[0].tval; 
			checkID(top_scope, yystack.l_mark[0].tval->attribute.sval); 
		}
break;
case 49:
#line 351 "pc.y"
	{ 
			yyval.tval = opTree(ARROP, "[]", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval); 
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval);
		}
break;
case 50:
#line 356 "pc.y"
	{
			yyval.tval = opTree(PAROP, "()", yystack.l_mark[-3].tval, yystack.l_mark[-1].tval);
			checkID(top_scope, yystack.l_mark[-3].tval->attribute.sval); 
		}
break;
case 51:
#line 361 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 52:
#line 363 "pc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 53:
#line 365 "pc.y"
	{ yyval.tval = yystack.l_mark[-1].tval; }
break;
case 54:
#line 367 "pc.y"
	{ yyval.tval = opTree(NOT, "NOT", yystack.l_mark[0].tval, emptyTree()); }
break;
case 55:
#line 369 "pc.y"
	{ /*sign
	: '+'
		{
	
		}
	| '-'
	;*/
 }
break;
case 56:
#line 379 "pc.y"
	{ yyval.tval = strTree(ID, yystack.l_mark[0].sval, emptyTree(), emptyTree()); }
break;
case 57:
#line 384 "pc.y"
	{ yyval.tval = intTree(INUM, yystack.l_mark[0].ival, emptyTree(), emptyTree()); }
break;
case 58:
#line 388 "pc.y"
	{ yyval.tval = fTree(RNUM, yystack.l_mark[0].fval, emptyTree(), emptyTree()); }
break;
#line 947 "y.tab.c"
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
