#pragma once
#define MAX 1000
#include <stdio.h>

typedef struct stack_info {
	int top;
	char st[MAX];
}Stack;

typedef struct stack_info2 {
	int top;
	int st[MAX];
}Stack2;

void pop(Stack*);
void push(Stack*,char);
int pop2(Stack2*);
void push2(Stack2*, int);
int prior(char);
int isop(char);
int ispa(char);
void print_st(Stack*);
void print_st2(Stack2*);


