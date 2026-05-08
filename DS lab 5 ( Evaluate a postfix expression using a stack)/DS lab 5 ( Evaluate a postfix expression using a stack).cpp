// DS lab 5 ( Evaluate a postfix expression using a stack).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    top++;
    stack[top] = value;
}

// Pop operation
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    scanf_s("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If character is operand
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        // If character is operator
        else
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;

            case '%':
                result = op1 % op2;
                break;

            default:
                printf("Invalid operator");
                return 1;
            }

            push(result);
        }
    }

    printf("Result = %d", pop());

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
