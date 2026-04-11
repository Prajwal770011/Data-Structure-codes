// ds lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
int main()
{
	int arr[100],i,pos,value,choice,found;
	int n;
	printf("Enter number of elements");
	scanf_s("%d",& n);
	printf("Enter elements \n");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	do {
		printf("\n----MENU---\n");
		printf("l.Transversal\n2.Insertion\n3.deletion\n4.Searching\n5.Exit\n");
		printf("Enter your choice");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1://transversal
			printf("Array elements are:");
			for (i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			break;

		case 2://insersion
			printf("entern possion and value");
			scanf_s("%d %d", &pos, &value);

			for (i = n; i >= pos; i--)
			{
				arr[i] = arr[i - 1];
			}
				arr[pos - 1] = value;
				n++;
					break;
		case 3://Delation
			printf("Enter possition to delete");
			scanf_s("%d", &pos);

			for (i = pos - 1; i < n - 1; i++) {
				arr[i] = arr[i - 1];
			}
			n--;
			break;

		case 4://searching
			printf("Enter elements to search");
			scanf_s("%d", &value);
			found = 0;
			for (i = 0; i < n; i++)
			{
				if (arr[i] = value)
				{
					printf("Element found at possion:%d/n", i + 1);
					found = 1;
					break;
				}
			}
			if (found == 0)
				printf("Element not found\n");
			break;

		case 5:
			printf("Exeting,,,\n");
			break;
		default:
			printf("Invalide choice");
		}
	} while (choice != 5);
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
