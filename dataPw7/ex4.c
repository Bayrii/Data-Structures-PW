#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
// Defining max length for strings
#define MAX 100

// predefined stack components
int top=-1;
int item;
int stack[MAX];

/**
 * Checking if the size of stack is full or not.
 * @return 1 if it is full.
 * @return 0 if it is not full.
 */

int is_full(){  

    if(top == MAX - 1){
            return 1;
    }
    return 0;
}

/**
 * Adding element to the top of the stack.
 */
void push(int x){   

    if(is_full()){
        printf("THE STACK IS FULL!\n");
        return;
    }
    top=top+1;
    stack[top]=x;
}

/**
 * Checking if the stack is empty or not
 * @return 1 if it is empty.
 * @return 0 if it is not empty.
 */
int is_empty(){    
    if(top == -1){
        return 1;
    }
    return 0;
}

/**
 * Deleting element from top of the stack.
 * @return removed element 
 */
int pop(){  
    if(is_empty()){
        printf("THE STACK IS EMPTY!\n");
        return 0;
    }
    item=stack[top];
    top--;
    return item;
}

/**
 * Showing the full stack to the user.
 */

void display(){      
    if(is_empty()){
        printf("THE STACK IS EMPTY!\n");
    }
    else{
        printf("The stack: ");
        for(int i=0;i<top+1;i++){
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int l;

    printf("Enter number of elements : ");
    scanf("%d",&l);

    int *elements = (int *)malloc(l * sizeof(int));
    int *nge = (int *)malloc(l * sizeof(int));
    // Checks whether memory was allocated successfully or didn't.
    // !elements ====> elements == NULL
    if (!elements || !nge) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < l; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d",&elements[i]);
    }

    push(elements[l - 1]);
    nge[l - 1] = -1;

    for (int i = l - 2; i >= 0; i--)
    {
        // Remove elements from stack if top element smaller than current element
        while (!is_empty() && stack[top] <= elements[i])
        {
            pop();
        }

        // If stack empty we have to assign -1 to the current element of nge array
        if (is_empty())
        {
            nge[i] = -1;
        }// Otherwise top element of stack
        else
        {
            nge[i] = stack[top];
        }

        // Every time push the current element 
        push(elements[i]);
    }
    
    printf("Next Greater Element array: ");
    for (int i = 0; i < l; i++) {
        printf("%d ", nge[i]);
    }
    printf("\n");
    display();
    return 0;
}
