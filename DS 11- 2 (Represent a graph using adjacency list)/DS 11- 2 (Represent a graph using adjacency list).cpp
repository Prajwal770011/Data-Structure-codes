// DS 11- 2 (Represent a graph using adjacency list).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node
{
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];

// Create new node
struct Node* createNode(int v)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Add edge
void addEdge(int src, int dest)
{
    struct Node* newNode;

    // Add edge src -> dest
    newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge dest -> src (Undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Display adjacency list
void display(int vertices)
{
    int i;
    struct Node* temp;

    printf("\nAdjacency List:\n");

    for (i = 0; i < vertices; i++)
    {
        printf("%d -> ", i);

        temp = adjList[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int vertices, edges;
    int i, src, dest;

    printf("Enter number of vertices: ");
    scanf_s("%d", &vertices);

    // Initialize adjacency list
    for (i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf_s("%d", &edges);

    // Input edges
    for (i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf_s("%d %d", &src, &dest);

        addEdge(src, dest);
    }

    display(vertices);

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
