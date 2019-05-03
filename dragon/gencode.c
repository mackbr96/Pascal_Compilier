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
			sprintf(str, "$%d", n->attribute.ival);
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
	char str[20];
	sprintf(str, "(%rbp)");
	char num[50];
	sprintf(num, "%d", (offset-base + 2)*8);
	fprintf(stderr, "NUM IS %s\n", num); 	// store above base pointer,
	strcat(num, str);
	char final[150];
	sprintf(final, "-");
	strcat(final, num);						// leaving room for return value
	return strdup(final);
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
	fprintf(outfile, "\tmov\t\t%s, %s\n", getReg(top(rstack)), getValue(n->leftNode));
}


void print_code(char* opval, char* right, char* left) {
	if(!strcmp(opval, "mov"))
		fprintf(outfile, "\tmovq\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "+"))
		fprintf(outfile, "\taddq\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "-"))
		fprintf(outfile, "\tsubq\t\t%s, %s\n", left, right);
	else if(!strcmp(opval, "*"))
		fprintf(outfile, "\timul\t\t%s, %s\n", left, right);
	else {
		if(!strcmp(opval, "=")) {
			fprintf(outfile, "\tcmpq\t\t%s, %s\n", left, right);
			fprintf(outfile, "\tjne\t\t.L%d\n", L);
		}
		else if(!strcmp(opval, ">" )) {
			fprintf(outfile, "\tcmpq\t\t%s, %s\n", left, right);
			fprintf(outfile, "\tjle\t\t.L%d\n", L);
		}
		else if(!strcmp(opval, "<")) {
			fprintf(outfile, "\tcmpq\t\t%s, %s\n", left, right);
			fprintf(outfile, "\tjge\t\t.L%d\n", L);
		}
		else if(!strcmp(opval, "<=")) {
			fprintf(outfile, "\tcmpq\t\t%s, %s\n", left, right);
			fprintf(outfile, "\tjg\t\t.L%d\n", L);
		}
		else if(!strcmp(opval, ">=")) {
			fprintf(outfile, "\tcmpq\t\t%s, %s\n", left, right);
			fprintf(outfile, "\tjl\t\t.L%d\n", L);
		}


		else {
			fprintf(stderr, "You forgot to add %s in Print Code\n", opval);
			//exit(0);
		}
	}

}


void main_header_gencode() {
	fprintf(outfile, "main:\n");
	fprintf(outfile, "\tpushq\t\t%rbp\n");
	fprintf(outfile, "\tmovq\t\t%rsp, %rbp\n");
	fprintf(outfile, "\tpushq\t\t$0\n");
	fprintf(outfile, "\tpushq\t\t%rbp\n");



	//fprintf(outfile, "\tsub\t\trsp, %d\n", 8*(top_table()->num_locals));

}

void main_footer_gencode() {
	fprintf(outfile, "\tmovl\t\t$0, %%eax\n");
	fprintf(outfile, "\tleave\n");
	fprintf(outfile, "\tret\n");
	fprintf(outfile, "\n\t.size\tmain, .-main\n\n\n");

}

void add_io_gencode() {
	
	fprintf(outfile, ".LC0: # reading\n");
	fprintf(outfile, "\t.string \"%%d\"\n");
	fprintf(outfile, "\t.text\n");
	fprintf(outfile, "\t.global\tmain\n");
	fprintf(outfile, "\t.type main, @function\n");
	fprintf(outfile, ".LC1: # writing\n");
	fprintf(outfile, "\t.string \"%%d\\n\"\n");
	fprintf(outfile, "\t.text\n");
	fprintf(outfile, "\t.global\tmain\n");
	fprintf(outfile, "\t.type main, @function\n");
}


void file_footer_gencode() {
	fprintf(outfile, "\t.ident\t\"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609\"\n");
	fprintf(outfile, "\n\t.section\t.note.GNU-stack,\"\",@progbits\n");
}


void file_header_gencode() {
	fprintf(outfile, "\t.file\t\"output.s\"\n");
	fprintf(outfile, "\t.section\t.rodata\n");
}

void call_procedure_gencode(tree* t) {
	char* name = strdup(t->leftNode->attribute.sval);


	if(!strcmp(name, "write")) {
		tree* var_ptr = t->rightNode->rightNode;
		char* var_name = t->rightNode->rightNode->attribute.sval;
		fprintf(outfile, "\n# evaluate 'write' arguments\n");
		fprintf(outfile, "\tmovl\t\t%s, %%edx\n", var_to_assembly(var_name));
		fprintf(outfile, "\n# call 'write' using fprintf\n");
		fprintf(outfile, "\tmovq\t\tstderr(%rip), %rax\n");
		fprintf(outfile, "\tmovl\t\t$.LC1, %%esi\n");
		fprintf(outfile, "\tmovq\t\t%rax, %rdi\n");
		fprintf(outfile, "\tmovl\t\t$0, %%eax\n");
		fprintf(outfile, "\tcall\tfprintf\n\n");	
	}
	else if(!strcmp(name, "read")) {
		char* var_name = t->rightNode->rightNode->attribute.sval;
		fprintf(outfile, "\n# call 'read' using fscanf\n");
		fprintf(outfile, "\tleaq\t\t%s, %rax\n", var_to_assembly(var_name));
		fprintf(outfile, "\tmovq\t\t%rax, %rsi\n");
		fprintf(outfile, "\tmovl\t\t$.LC0, %%edi\n");
		fprintf(outfile, "\tmovl\t\t$0, %%eax\n");
		fprintf(outfile, "\tcall __isoc99_scanf\n");
	}
	else
	{	
		char* name = strdup(t->leftNode->attribute.sval);
		fprintf(outfile, "# Evaluating Procedure Argsuments\n");

		node* n = searchScopeAll(top_scope, name);
		tree* args = t -> rightNode;

		for(int i = 0; i < n -> args; i++) {
			genCode(args->rightNode);
			fprintf(outfile, "\tpushq\t\t%s\n", getReg(top(rstack)));
			args = args -> leftNode;
		}

		fprintf(outfile, "\n# call procedure '%s'\n", name);
		fprintf(outfile, "\tcall\t%s\n\n", name);
	}
}

void print_args(tree* t, int args) {
	if(t -> type == EMPTY) {
		return;
	}
	
	else if(t -> type == ID) {
		fprintf(outfile, "\tmovq\t\t\%d(%rbp), %s\n", (16 + (offBase * 8)), getReg(top(rstack)));
		fprintf(outfile, "\tmovq\t\t%s, %s\n", getReg(top(rstack)), getValue(t));
		offBase = offBase + 1;
	}

	else {
		print_args(t->leftNode, args);
		print_args(t->rightNode, args);
	}



}

void start_if(tree* t) {
	fprintf(outfile, "# Start IF\n");
	genCode(t);
}
void mid_if(tree* t) {
	fprintf(outfile, "\tjmp\t\t.L%d\n", L + 2);
	fprintf(outfile, ".L%d:\n", L);
	
}
void end_if(tree* t) {
	fprintf(outfile, "# END IF\n");
	fprintf(outfile, ".L%d:\n", L + 2);
	L = L + 6;

}

void start_while(tree* t) {
	fprintf(outfile, "# Start while\n");
	fprintf(outfile, ".L%d:\n", L);
	L = L + 2;
	genCode(t);
	L = L -2;

}

void end_while(tree* t) {
	
	fprintf(outfile, "# End While\n");
	fprintf(outfile, "\tjmp\t\t .L%d\n", L);
	fprintf(outfile, ".L%d:\n", L+2);
	
}


void function_header(tree* t) {

	tree* name_ptr = t->leftNode;
	if(name_ptr->type == PAROP)
		name_ptr = name_ptr->leftNode;
	if(name_ptr->type != ID)
	{
		fprintf(stderr, "\nERROR, LINE %d: function name expected.\n", yylineno);
		exit(1);
	}

	fprintf(outfile, "# FUNCTION HEADER\n");
	fprintf(outfile, "%s:\n", name_ptr->attribute.sval);
	fprintf(outfile, "\tpushq\t\t%rbp\n");
	fprintf(outfile, "\tmovq\t\t%rsp, %rbp\n");
	offBase = 0;
	print_args(t->rightNode, searchScopeAll(top_scope, name_ptr->attribute.sval) -> args);
	offBase = 0;


}

void function_footer(tree* t) {
	fprintf(outfile, "# Function Footer\n");
	fprintf(outfile, "\tmovq\t\t%rbp, %rsp\n");
	fprintf(outfile, "\tpopq\t\t%rbp\n");
	fprintf(outfile, "\tret\n");

}


