// DS lab 3 b (stack using list).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<stdlib.h>

//Define node structure
struct Node
{
	int data;
	struct Node* next;
};
struct Node* top = NULL;

void push(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL); {
		printf("Stack overflow(Memory not avaliable)\n");
		return;
	}
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	printf("%d pushed to stack\n", value);

}

void pop()
{
	if (top == NULL)
	{
		printf("Stack Underflow (Empty stack)\n");
		return;
	}
	struct Node* temp = top;
	printf("%d popped from stack\n", top->data);
	top
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
