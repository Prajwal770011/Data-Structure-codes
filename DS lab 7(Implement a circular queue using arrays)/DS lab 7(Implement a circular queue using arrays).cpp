// DS lab 7(Implement a circular queue using arrays).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Insert element
void enqueue(int value)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

// Delete element
void dequeue()
{
    struct Node* temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;

        printf("%d deleted\n", front->data);

        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

// Display queue
void display()
{
    struct Node* temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;

        printf("Queue Elements:\n");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}

int main()
{
    enqueue(1645);
    enqueue(20984);
    enqueue(306541);

    display();

    dequeue();

    display();

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
