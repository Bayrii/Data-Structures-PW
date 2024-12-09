#include<stdio.h>
#include<stdlib.h>
#include"functions.h" 

// In this code I used my own functions.h library to make code more readible and look clean
// functions.h header file contains all the funcstions from PW5 for array

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
    printf("\nYour array : ");
    display(l,elements);


    int N;
    printf("How many times do you want to rotate : ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        // saves first elements
        int temp = elements[0];
        for (int j = 0; j < l - 1; j++)
        {
            elements[j] = elements[j + 1];
        }
        // then we equalize last element to the first element
        elements[l - 1] = temp;
        
    }
    
    // Display
    printf("Your array after rotating %d times : ", N);
    display(l,elements);

    return 0;
}