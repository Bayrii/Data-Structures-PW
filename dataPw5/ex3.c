#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"functions.h"

int main(int argc, char const *argv[])
{
    int l, choice;
    bool find = false;


    printf("\n---SEARCHING A NUMBER---\n");
    printf("Do you want do it with 'search' function or for loop.\n");
    printf("(1) Search()\n");
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
    if (!elements){
        printf("Memory allocation failed\n");
        return 1;
    }

    // Getting array from user;
    get_arr(l, elements);
    
    int s_el;

    printf("Enter the element you are looking for: ");
    scanf("%d",&s_el);
    
    switch (choice)
    {
    case 1:
        if (search(l,elements,s_el) != -1)
        {
            printf("Element found.\n");
            printf("Element[%d] : %d ", search(l,elements,s_el), s_el);
        }else{
            printf("Element couldn't found.\n");
        }    
        break;
    case 2:
        for (int i = 0; i < l; i++)
        {
            if (s_el == elements[i])
            {
                printf("Element found.\n");
                printf("Element[%d] : %d ", i, s_el);   
                find = true;
            }
        }
        if (!find)
        {
            printf("Element couldn't found.\n");
        }
        
        break;
    default:
        printf("Invalid choice");
        break;
    }
    
    return 0;
}
