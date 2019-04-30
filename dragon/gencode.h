#ifndef GENCODE_H
#define GENCODE_H
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include "node.h"
#include "rstack.h"
#include "y.tab.h"

char* getValue(tree* n);

void main_header_gencode();
void main_footer_gencode();
void file_footer_gencode();
void add_io_gencode();
void file_header_gencode();

void gencode(tree*);

char* var_to_assembly(char* name);
char* assign_gencode(tree* n);
void print_code(char*, char*, char* );
void call_procedure_gencode(tree*);
void getVar(char*);
#endif
