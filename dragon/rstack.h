#ifndef RSTACK_H
#define RSTACK_H

#define MAX_REGS 4

typedef struct stack {
    int reg[MAX_REGS];
    int idx;

    
} stack;


extern stack* rstack;

char* getReg(int);

int pop(stack*);
int top(stack*);
void swap(stack*);
void push(int, stack*);

#endif
