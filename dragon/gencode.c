#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "gencode.h"
#include "node.h"


/*
      REGISTER STACK
   --------------------
								
   -------------------
   |       r8        | 7		Start filling here at idx 0
   -------------------			
   |       r9        | 6
   -------------------
   |       r10       | 5
   -------------------
   |       r11       | 4
   -------------------
   |       r12       | 3
   -------------------
   |       r13       | 2
   -------------------
   |       r14       | 1
   -------------------
   |       r15       | 0
-------------------------		
            .
   			.
			.
*/



char* getValue(tree* n)
{
	char str[100];
	switch(n->type)
	{
		case INUM:
			sprintf(str, "%d", n->attribute.ival);
			return strdup(str);
		
		case RNUM:
			sprintf(str, "%f", n->attribute.fval);
			return strdup(str);
		
		case ID:
			return var_to_assembly(n->attribute.sval);
		case PAROP: // function call
			return strdup("rax");
		default:
			fprintf(stderr, "Error unkown case in getVale\n");
			exit(0);
	}
}


char* var_to_assembly(char* name) {
	node* n = searchScopeAll(top_scope, name);
	int offset = n -> offset;
	int base = top_scope -> varNum;	
	fprintf(stderr, "Offet = %d base = %d\n", offset, base);
	char str[150];
	sprintf(str, "QWORD PTR [rbp - ");
	char num[20];
	sprintf(num, "%d", (offset-base + 2)*8); 	// store above base pointer,
	strcat(str, num);						// leaving room for return value
	strcat(str, "]");						// and static parent pointer
	return strdup(str);
}

void genCode(tree* n) {
	static int r = 10;
	

	if(empty(n)) 
		return;

	if(leafNode(n) && n -> ershov_num == 1) {
		fprintf(stderr, "1 gencode\n");
		//print mov name , top(rstack)
		print_code("mov", getReg(top(rstack)), getValue(n));
		//fprintf(outfile, "\tmov\t\t%s, 3\n", getReg(top(rstack))); 
	}
	else if(!empty(n->rightNode) && leafNode(n->rightNode) && n -> rightNode -> ershov_num == 0) {
		fprintf(stderr, "2 gencode\n");
		genCode(n -> leftNode);
		fprintf(outfile, "# Printing operation\n");
		print_code(n->attribute.opval, getReg(top(rstack)),getValue(n->rightNode)); 
		//print op name , top(rstack)
		//fprintf(outfile, "\tmov\t\rdx, %d\n", n->attribute.ival);
	}
	else if(1 <= n->leftNode->ershov_num < n->rightNode->ershov_num && n->leftNode->ershov_num < r) {
		fprintf(stderr, "3 gencode\n");
		swap(rstack);
		genCode(n->rightNode);
		int R = pop(rstack);
		genCode(n->leftNode);
		fprintf(stderr, "Opval %s\n", n->attribute.opval);
		print_code(n->attribute.opval, getReg(top(rstack)), getReg(R)); 
		//print op top(rstack) , R
		push (R, rstack);
		swap(rstack);
	}
	else if(1 <= n->rightNode->ershov_num <= n->leftNode->ershov_num && n->rightNode->ershov_num < r) {
		fprintf(stderr, "4 gencode\n");
		fprintf(stderr, "Type: %s\n", typeToString(n->type));
		fprintf(stderr, "number: %d\n", n->ershov_num);
		genCode(n->leftNode);
		int R = pop(rstack);
		genCode(n->rightNode);
		print_code(n->attribute.opval, getReg(top(rstack)), getReg(R)); 
		push(R, rstack);
	}
	else {
		fprintf(stderr, "5 gencode\n");
		genCode(n->rightNode);
		//T = pop(tstack);
		//print MOV top(rstack);
		genCode(n->leftNode);
		//push(tstack, T)
		//print op T , top(rstack);
	}
}

char* assign_gencode(tree* n) {
	fprintf(outfile, "\n# Assignment Evaluation\n");
	genCode(n->rightNode);
	fprintf(outfile, "# assign gencode\n");
	fprintf(outfile, "\tmov\t\t%s, %s\n", getValue(n->leftNode), getReg(top(rstack)));
}


void print_code(char* opval, char* left, char* right) {
	if(!strcmp(opval, "mov"))
		fprintf(outfile, "\tmov\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "+"))
		fprintf(outfile, "\tadd\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "-"))
		fprintf(outfile, "\tsub\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "*"))
		fprintf(outfile, "\timul\t\t%s, %s\n", left, right);
	else {
		fprintf(stderr, "You forgot to add %s in Print Code\n", opval);
		exit(0);
	}

}


void main_header_gencode() {
	fprintf(outfile, "\t.globl\tmain\n");
	fprintf(outfile, "\t.type\tmain, @function\n");
	fprintf(outfile, "main:\n");
	fprintf(outfile, "\tpush\trbp\n");
	fprintf(outfile, "\tmov\t\trbp, rsp\n");

	fprintf(outfile, "\tpush\t0\n");
	fprintf(outfile, "\tpush\trbp\n");
	//fprintf(outfile, "\tsub\t\trsp, %d\n", 8*(top_table()->num_locals));

}

void main_footer_gencode() {
	fprintf(outfile, "\tmov\t\teax, 0\n");
	fprintf(outfile, "\tleave\n");
	fprintf(outfile, "\tret\n");
	fprintf(outfile, "\n\t.size\tmain, .-main\n\n\n");

}

void add_io_gencode() {
	fprintf(outfile, "\t.section\t.rodata\n");
	fprintf(outfile, ".LC0: # reading\n");
	fprintf(outfile, "\t.string \"%%lld\"\n");
	fprintf(outfile, ".LC1: # writing\n");
	fprintf(outfile, "\t.string \"%%lld\\n\"\n");
	fprintf(outfile, "\t.text\n\n\n");
}


void file_footer_gencode() {
	fprintf(outfile, "\t.ident\t\"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609\"\n");
	fprintf(outfile, "\n\t.section\t.note.GNU-stack,\"\",@progbits\n");
}


void file_header_gencode() {
	fprintf(outfile, "\t.file\t\"output.s\"\n");
	fprintf(outfile, "\t.intel_syntax noprefix\n\n");
}

void call_procedure_gencode(tree* t) {
	char* name = strdup(t->leftNode->attribute.sval);


	if(!strcmp(name, "write")) {
		tree* var_ptr = t->rightNode->rightNode;
		fprintf(outfile, "\n# evaluate 'write' arguments\n");
		genCode(var_ptr);
		fprintf(outfile, "\n# call 'write' using fprintf\n");
		fprintf(outfile, "\tmov\t\trdx, %s\n", getReg(top(rstack)));
		fprintf(outfile, "\tmov\t\trax, QWORD PTR stderr[rip]\n");
		fprintf(outfile, "\tmov\t\tesi, OFFSET FLAT:.LC1\n");
		fprintf(outfile, "\tmov\t\trdi, rax\n");
		fprintf(outfile, "\tmov\t\teax, 0\n");
		fprintf(outfile, "\tcall\tfprintf\n\n");	
	}
	else if(!strcmp(name, "read")) {
		char* var_name = t->rightNode->rightNode->attribute.sval;
		fprintf(outfile, "\n# call 'read' using fscanf\n");
		fprintf(outfile, "\tmov\t\trax, QWORD PTR fs:40\n");
		fprintf(outfile, "\txor\t\teax, eax\n");
		fprintf(outfile, "\tmov\t\trax, QWORD PTR stdin[rip]\n");
		fprintf(outfile, "\tlea\t\trdx, %s\n", var_to_assembly(var_name));
		fprintf(outfile, "\tmov\t\tesi, OFFSET FLAT:.LC0\n");
		fprintf(outfile, "\tmov\t\trdi, rax\n");
		fprintf(outfile, "\tmov\t\teax, 0\n");
		fprintf(outfile, "\tcall\t__isoc99_fscanf\n\n");
			//fprintf(outfile, "\tmov\t\t%s, 3\n", getReg(top(rstack))); 
	}
}
