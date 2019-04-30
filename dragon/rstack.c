#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rstack.h"
#include "externs.h"


char* getReg(int i) {
	static char* regStrings[] = {"r11","r10","r9","r8"};

	return regStrings[i];
}

int pop(stack* s) {
    s->idx--;
    return s->reg[s->idx + 1];
}

int top(stack* s) {
	return s->reg[s->idx];
}

void swap(stack* s) {
   int old = s->reg[s->idx];
	int new = s->reg[s->idx-1];
	
	s->reg[s->idx-1] = old;
	s->reg[s->idx] = new;
}

void push(int new, stack* s) {
    s->idx++;
    s->reg[s->idx] = new;
}
