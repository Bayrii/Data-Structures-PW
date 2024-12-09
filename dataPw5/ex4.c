#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"functions.h"

int main() {
    int l,choice;

    printf("\n---REVERSING ARRAY---\n");
    printf("Do you want do reverse string array or integer array? \n");
    printf("(1) String array\n");
    printf("(2) Integer array\n");
    printf("(1) or (2) : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter the number of strings: ");
        scanf("%d", &l);

        // In this part, I used malloc to allocate memory for the array.
        char **arr = (char **)malloc(l * sizeof(char *));
        // Checks whether memory was allocated successfully or didn't.
        if (!arr) {
            printf("Memory allocation failed for string array.\n");
            return 1;
        }
        for (int i = 0; i < l; i++) {
            // Allocate memory for each array
            arr[i] = (char *)malloc(100 * sizeof(char));
            // Checks memory was allocated successfullt or didn't
            if (!arr[i]) {
                printf("Memory allocation failed for string %d.\n", i + 1);
                return 1;
            }
        }

        // Getting array from user
        get_arr_string(l,arr);

        // Displaying array
        printf("\n---Original Array---\n");
        display_string(l, arr);


        // Calling reverse function to reverse array
        reverse_string(l, arr);

        // Displaying array
        printf("\n---Reversed Array---\n");
        display_string(l, arr);
        break;
    case 2:
        // Asking number of elements.
        printf("Enter number of elements : ");
        scanf("%d",&l);

        // In this part, I used malloc to allocate memory for the array.
        int *elements = (int *)malloc(l * sizeof(int));

        // Checks whether memory was allocated successfully or didn't.
        // !elements ====> elements == NULL
        if (!elements){
            printf("Memory allocation failed\n");
            return 1;
        }

        // Getting array from user
        get_arr(l,elements);

        // Displaying array
        printf("\n---Original Array---\n");
        display(l, elements);
        
        // Calling reverse function to reverse array
        reverse(l, elements);

        // Displaying array
        printf("\n---Reversed Array---\n");
        display(l, elements);
        break;
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}
