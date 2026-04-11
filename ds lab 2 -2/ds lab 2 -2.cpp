// ds lab 2 -2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main() {
    int matrix[10][10], triplet[50][3], transpose[50][3];
    int i, j, m, n, k = 1;

    printf("Enter rows and columns: ");
    scanf_s("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {          
        for (j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // Convert to triplet form
    triplet[0][0] = m;
    triplet[0][1] = n;
    triplet[0][2] = 0;

    for (i = 0; i < m; i++) {          
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
                triplet[0][2]++;
            }
        }
    }

    printf("\nTriplet Representation:\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    // Transpose
    transpose[0][0] = triplet[0][1];
    transpose[0][1] = triplet[0][0];
    transpose[0][2] = triplet[0][2];

    k = 1;

    for (i = 0; i < triplet[0][1]; i++) {
        for (j = 1; j <= triplet[0][2]; j++) {
            if (triplet[j][1] == i) {
                transpose[k][0] = triplet[j][1];
                transpose[k][1] = triplet[j][0];
                transpose[k][2] = triplet[j][2];
                k++;
            }
        }
    }

    printf("\nTranspose Triplet:\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

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
