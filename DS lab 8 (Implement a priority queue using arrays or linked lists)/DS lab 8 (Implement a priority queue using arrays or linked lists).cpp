// DS lab 8 (Implement a priority queue using arrays or linked lists).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#define MAX 5

int pq[MAX];
int size = 0;

// Insert element in sorted order
void enqueue(int value)
{
    int i;

    if (size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    // Insert based on priority (smaller number = higher priority)
    for (i = size - 1; i >= 0 && pq[i] > value; i--)
    {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = value;
    size++;

    printf("%d inserted\n", value);
}

// Delete highest priority element
void dequeue()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", pq[0]);

    for (i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display elements
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty\n");
    }
    else
    {
        printf("Priority Queue Elements:\n");

        for (i = 0; i < size; i++)
        {
            printf("%d ", pq[i]);
        }
    }

    printf("\n");
}

int main()
{
    enqueue(3450);
    enqueue(1084);
    enqueue(5087);
    enqueue(2075);

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
