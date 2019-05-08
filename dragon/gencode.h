#ifndef GENCODE_H
#define GENCODE_H
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include "node.h"
#include "rstack.h"
#include "y.tab.h"

char* getValue(tree* n);
void print_args(tree*, int);

void main_header_gencode();
void main_footer_gencode();
void file_footer_gencode();
void add_io_gencode();
void file_header_gencode();

void function_header(tree* t);
void function_footer(tree* t);


void gencode(tree*);

void start_if_else(tree*);
void mid_if_else(tree*);
void end_if_else(tree*);

void start_if(tree*);
void mid_if(tree*);
void end_if(tree*);


void start_while(tree*);
void end_while(tree*);

void start_do_while();
void end_do_while(tree*);


void start_for(tree* var, tree* t1, tree* t2);
void end_for(tree* var);

char* var_to_assembly(char* name);
void nonlocal_var(char* name);

char* assign_gencode(tree* n);
void print_code(char*, char*, char* );
void call_procedure_gencode(tree*);
void getVar(char*);

int child(char* name);
#endif
