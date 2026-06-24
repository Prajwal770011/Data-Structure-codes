// DS 12(Implement graph traversal BFS and DFS).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int vertices;

// Queue operations for BFS
void enqueue(int value)
{
    queue[++rear] = value;
}

int dequeue()
{
    return queue[++front];
}

// BFS Traversal
void BFS(int start)
{
    int i;

    printf("BFS Traversal: ");

    visited[start] = 1;
    enqueue(start);

    while (front != rear)
    {
        int node = dequeue();

        printf("%d ", node);

        for (i = 0; i < vertices; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// DFS Traversal
void DFS(int start)
{
    int i;

    printf("%d ", start);

    visited[start] = 1;

    for (i = 0; i < vertices; i++)
    {
        if (graph[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges;
    int i, src, dest;
    int start;

    printf("Enter number of vertices: ");
    scanf_s("%d", &vertices);

    // Initialize graph
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf_s("%d", &edges);

    // Input edges
    for (i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf_s("%d %d", &src, &dest);

        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf_s("%d", &start);

    // BFS
    BFS(start);

    // Reset visited array for DFS
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");

    // DFS
    DFS(start);

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
