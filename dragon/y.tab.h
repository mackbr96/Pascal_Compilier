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
extern YYSTYPE yylval;
