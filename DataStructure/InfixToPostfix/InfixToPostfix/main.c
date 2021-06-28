#include <stdio.h>
#include <windows.h>
#include "Stack.h"
#include "Experession.h"



int main() {

    char c;
    p = 0;
    Stack op;
    op.top = -1;

    
    printf("Input: ");
    while ((c = getchar()) != '\n')
    {
        if (isdigit(c))
        {
            insert(c);
        }

        else if (isop(c))
        {   
            if (op.top==-1)
            {
                print_e(expr);
                print_st(&op);
                push(&op, c);
                print_e(expr);
                print_st(&op);
                continue;
             }
            else if (prior(c) > prior(op.st[op.top]))
            {
                print_e(expr);
                print_st(&op);
                push(&op, c);
                print_e(expr);
                print_st(&op);
            }
            else if (prior(c) <= prior(op.st[op.top]))
            {
                while (prior(c) <= prior(op.st[op.top]))
                {
                    print_e(expr);
                    print_st(&op);
                    pop(&op);
                }
                push(&op, c);
                print_e(expr);
                print_st(&op);
            }

        }

        else if (ispa(c))
        {
            switch (ispa(c))
            {
            case 1: {push(&op, c); print_e(expr);
                print_st(&op); break; }
            case 2:
            {
                while (op.top > -1)
                {
                    if (op.st[op.top] == '(')
                    {
                        op.top--;
                        break;
                    }
                        pop(&op);
                        print_e(expr);
                        print_st(&op);
                }
                break;
            }
            }
        }
        else
            continue;
    }

    while (op.top > -1)
    {
        print_e(expr);
        print_st(&op);
        pop(&op);
        print_e(expr);
        print_st(&op);
    }
    printf("----------------------------------\n");
    print_e(expr);
    int answer = 0;
    answer = calculate(expr);
    printf("계산결과:%d\n",answer);
    
    

    system("pause");
}

