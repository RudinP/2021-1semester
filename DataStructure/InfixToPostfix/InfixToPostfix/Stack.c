#include "Stack.h"
#include "Experession.h"

void pop(Stack* st ) 
{
    if (st->top <= -1)
    {
        printf("Empty Stack");
    }
    else
    {
        insert(' ');
        insert(st->st[st->top--]);
    }
}

void push(Stack* st,char c) 
{   
    if(c!='(')
        insert(' ');
    if (st->top >= MAX - 1)
        printf("Stack Full, Cannot Push");
    else
    {
        st->st[++st->top] = c;
    }
}

int pop2(Stack2* st)
{
    if (st->top <= -1)
    {
        printf("Empty Stack");
    }
    else
    {
        return (st->st[st->top--]);
    }
}

void push2(Stack2* st, int c)
{
    if (st->top >= MAX - 1)
        printf("Stack Full, Cannot Push");
    else
    {
        st->st[++st->top] = c;
    }
}

int prior(char c) 
{
    switch (c) {
    case '+':case '-': return 1;
    case '*':case '/': return 2;
    case '(':return 0;
    default: return -1;
    }
}

int isop(char c) 
{
    switch (c) {
    case '+':case'-':case'/':case'*': return 1;
    default: return 0;
    }
}

int ispa(char c) 
{
    switch (c) {
    case'(':return 1;
    case')':return 2;
    default:return 0;
    }
}

void print_st(Stack* st)
{
    printf("Operator Stack:");
    for (int i = 0; i <= st->top; i++)
        printf("%c ", st->st[i]);
    printf("\n\n");
}

void print_st2(Stack2* st)
{
    printf("Operand Stack:");
        for (int i = 0; i <= st->top; i++)
            printf("%d ", st->st[i]);
    printf("\n\n");
}

