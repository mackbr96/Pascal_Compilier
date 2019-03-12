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
