#pragma once
#include <stdio.h>
#include <ctype.h>
#include "Stack.h"
#define MAX 1000
int p;
char expr[MAX];

int calculate(char*);
void insert(char);
void print_e(char*);
int ipow(int, int);
