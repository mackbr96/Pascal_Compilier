#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "symbolTable.h"


void add(Node *n, char* id_, int type_, int lineNum_, int value_) {
	Node *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode -> id = id_;
	newNode -> type = type_;
	newNode -> lineNum = lineNum_;
	newNode -> nextNode = NULL;
	newNode -> value = value_;
	n -> nextNode = newNode;
}

Node* rootNode(char* id_, int type_, int lineNum_, int value_) {
	Node *n;
	n = malloc(sizeof(struct Node));
	n -> id = id_;
	n -> type = type_;
	n -> lineNum = lineNum_;
	n -> nextNode = NULL;
	n -> value = value_;
	return n;
}
