#include "Experession.h"

void insert(char c) {
	expr[p++] = c;
}

void print_e(char* expr) {
    printf("Expression:");
    for (int i = 0; i <= p; i++) {
        printf("%c", expr[i]);
    }
    printf("\n");
}

int ipow(int a, int b)
{
    int sum = 1;
    for (int c = 0; c <b; c++)
        sum *= a;
    return sum;
}

int calculate(char* expr) {
    Stack2 oper;
    oper.top = -1;
    int temp[10] = {0,};
    int i = 0;
    int n = 0;
    int op1, op2;
    int num = 0;
    char e;
    while ((e=expr[i++]) != '\0')
    {
        
        if (isdigit(e))
            temp[n++] = (e-'0');

        else if (isop(e))
        {
            op1 = pop2(&oper);
            print_st2(&oper);
            op2 = pop2(&oper);
            print_st2(&oper);

            switch (e)
            {
            case '+': {push2(&oper, op1 + op2); print_st2(&oper); break; }
            case '-': {push2(&oper, op2 - op1); print_st2(&oper); break; }
            case '*': {push2(&oper, op2 * op1); print_st2(&oper); break; }
            case '/': {push2(&oper, op2 / op1); print_st2(&oper); break; }
            default:break;
            }
        }
        else if(isspace(e)&&temp[0]!=0)
        {
            for (int k = 1; k <= n; k++)
            {
                num += temp[k-1] * ipow(10, n - k);
            }
            push2(&oper, num);
            print_st2(&oper);
            num = 0;
            for (int t = 0; t < 10; t++)
                temp[t] = 0;
            n = 0;
        }
        
    }    
    return pop2(&oper);

}
