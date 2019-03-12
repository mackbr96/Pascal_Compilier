#ifndef NODE_H
#define NODE_H


#define TABLE_SIZE 100

typedef union {
	int ival;
	float fval;
	char *sval;

} value;

typedef struct Node Node;
typedef struct table table;

struct Node{
	char* entryName;
	int type;
	value entryValue;
	int lineNum;
	int returnType;
	int id;
	
	struct Node* nextNode;
};

struct table {
	Node *hashTable[TABLE_SIZE];
	int id;
	int size;

	char *tableName;

	

	struct table *parent;
	struct table *prev;
	struct table *next;



} table;


void add(Node* n, char* id_, int type_, int lineNum_, int value_);
Node* rootNode(char* id_, int type_, int lineNum, int value_);


//int hashpjw( char *s );
//table* pushTable(char* name, int class);
//void popTable();





#endif
