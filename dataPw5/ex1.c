#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

int main(int argc, char const *argv[])
{
    int l, sum = 0, choice;

    printf("\n---FINDING SUM OF NUMBERS---\n");
    printf("Do you want do it with 'sumelet' function or for loop.\n");
    printf("(1) Sumelet()\n");
    printf("(2) For loop\n");
    printf("(1) or (2) : ");
    scanf("%d",&choice);

    // Asking number of elements.
    printf("Enter number of elements : ");
    scanf("%d",&l);

    // In this part, I used malloc to allocate memory for the array.
    int *elements = (int *)malloc(l * sizeof(int));
    // Checks whether memory was allocated successfully or didn't.
    // !elements ====> elements == NULL
    if (!elements) {
        printf("Memory allocation failed\n");
        return 1;
    }

    switch (choice)
    {
    case 1:
        sum = sumelet(l,elements);
        break;
    case 2:
        for (int i = 0; i < l; i++){
            printf("Enter element %d : ", i + 1);
            scanf("%d",&elements[i]);
            sum += elements[i];
        }
    default:
        printf("Invalid choice");
        break;
    }

    printf("\nSum of elements : %d", sum);
    
    return 0;
}
