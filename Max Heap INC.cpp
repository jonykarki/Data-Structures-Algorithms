#include <iostream>
#include <tgmath.h>
#include <cmath>

using namespace std;

int heapH[] = {};

void maxheap_build(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        heapH[i] = a[i];
        int j = i;
        while (j > 0)
        {
            int parent = j / 2;
            if (heapH[j] <= heapH[parent])
            {
                break;
            }
            else
            {
                int temp = heapH[j];
                heapH[j] = heapH[parent];
                heapH[parent] = temp;
                j = parent;
            }
        }
    }
}

void delete_heap_root(int a[], int n)
{
    int arr[n - 1];
    maxheap_build(a, n);
    for (int i = 1; i < n; i++)
    {
        arr[i] = heapH[i];
    }
    maxheap_build(arr, n - 1);
}

void print_heap(int n)
{
    int current = 0;
    int heap_size = n;
    int levels = log2(heap_size);
    for (int i = 0; i <= levels; i++)
    {
        if (i == levels)
        {
            for (int j = current; j < heap_size; j++)
            {
                cout << heapH[j] << " ";
            }
        }
        else
        {
            for (int j = 0; j < pow(2, i); j++)
            {
                cout << heapH[current] << " ";
                current++;
            }
        }
        cout << endl;
    }
}

int main()
{
    int option;
    do
    {
        int a[] = {28, 12, 17, 5, 7, 22, 13, 4, 11, 16};

        printf("\n\n *******  MAIN MENU   *******"); // printf() displays output inside quotation
        printf("\n 1:  Build a Max Heap");
        printf("\n 2:  Delete the heap root");
        printf("\n 3:  Print the heap");
        printf("\n 4. Exit \n ");
        printf("Choose the number from 1-3 to perform the function or press 4 to exit: ");
        scanf("%d", &option);

        switch (option) // Using switch to display the message based on user's instructions
        {
        case 1:
            maxheap_build(a, sizeof(a) / sizeof(a[0]));
            printf("\n Heap Created");
            break;
        case 2:
            delete_heap_root(a, sizeof(a) / sizeof(a[0]));
            break;
        case 3:
            print_heap(sizeof(a) / sizeof(a[0]));
            break;
        }

    } while (option != 4);
}