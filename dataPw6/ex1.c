#include<stdio.h>
#include<stdlib.h>
#include"sortfunctions.h"
#include"functions.h" 

// In this code I used my own sortfunctions.h and functions.h libraries to make code more readible and look clean
// functions.h header file contains all the funcstions from PW5 for array
// sortfunctions.h header file contains selection sort; Bubble sort; Insertion sort; Merge sort and quick sort

int main(int argc, char const *argv[])
{
    int l;

    printf("Enter number of elements : ");
    scanf("%d",&l);

    int *elements = (int *)malloc(l * sizeof(int));
    // Checks whether memory was allocated successfully or didn't.
    // !elements ====> elements == NULL
    if (!elements) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Getting
    get_arr(l,elements);

    // Display
    printf("\n\nYour unsorted array : ");
    display(l,elements);

    int choice;
    printf("\n---SORTING ELEMENTS---\n");
    printf("In which way do you want to do it.\n");
    printf("(1) Selection sort\n");
    printf("(2) Bubble sort\n");
    printf("(3) Insertion sort\n");
    printf("(4) Merge sort\n");
    printf("(5) Quick sort\n");
    printf("Enter (ID) of the sorting way : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        selectionSort(l, elements);
        printf("\n\nYour sorted array : ");
        display(l, elements);
        break;
    case 2:
        bubbleSort(l, elements);
        printf("\n\nYour sorted array : ");
        display(l, elements);
        break;
    case 3:
        insertionSort(l, elements);
        printf("\n\nYour sorted array : ");
        display(l, elements);
        break;
    case 4:
        mergeSort(elements, 0, l - 1);
        printf("\n\nYour sorted array : ");
        display(l, elements);
        break;
    case 5:
        quickSort_ascennding(elements, 0, l-1);
        printf("\n\nYour sorted array : ");
        display(l, elements);
        break;
    
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}
