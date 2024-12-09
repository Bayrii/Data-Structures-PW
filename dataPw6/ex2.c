#include<stdio.h>
#include<stdlib.h>
#include"sortfunctions.h"
#include"functions.h" 

// In this code I used my own sortfunctions.h and functions.h libraries to make code more readible and look clean
// functions.h header file contains all the funcstions from PW5 for array
// sortfunctions.h header file contains Selection sort, Bubble sort, Insertion sort, Merge sort and Quick sort

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

    // Sorting array in descending order
    quickSort_decennding(elements, 0, l - 1);

    // Display
    printf("\nYour array in a descending order : ");
    display(l,elements);
    printf("\n");

    return 0;
}
