#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

int main(int argc, char const *argv[]){
    int l;

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

    //Getting array from user
    get_arr(l, elements);

    //Finding maximum
    int mmax = find_max(l, elements);
    printf("The maximum element in the array is: %d\n", mmax);

    return 0;
}