#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

int main(int argc, char const *argv[])
{
    int l;

    // Asking number of elements.
    printf("Enter number of elements : ");
    scanf("%d",&l);

    // In this part, I used malloc to allocate memory for the arrays.
    int *elements = (int *)malloc(l * sizeof(int));
    int *odd_el = (int *)malloc(l * sizeof(int));
    int *even_el = (int *)malloc(l * sizeof(int));

    // Checks whether memory was allocated successfully or didn't.
    // !elements ====> elements == NULL
    
    if (!elements && !odd_el && !even_el){
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Getting array from user
    get_arr(l, elements);

    // Displaying array
    printf("\n---Elements of Main array---\n");   
    display(l,elements);

    // Splitting and displaying arrays
    splitting(elements,odd_el,even_el,l);
      
    return 0;
}
