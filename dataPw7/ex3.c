#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
// Defining max length for strings
#define MAX 100

// predefined stack components
int top=-1;
char item;
char stack_string[MAX];

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
void push(char x){   

    if(is_full()){
        printf("THE STACK IS FULL!\n");
        return;
    }
    top=top+1;
    stack_string[top]=x;
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
char pop(){  
    if(is_empty()){
        printf("THE STACK IS EMPTY!\n");
        return 0;
    }
    item=stack_string[top];
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
            printf("%c ",stack_string[i]);
        }
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    char str[MAX];
    printf("Enter the string: ");
    fgets(str,100,stdin);
    // entering all of string's elements to stack one by one.    
    for(int i=0;i<strlen(str)-1;i++){  
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char popped = pop();
            if (( popped != '(' && str[i] == ')') ||
            ( popped != '{' && str[i] == '}') ||
            ( popped != '[' && str[i] == ']'))
            {
                printf("Not Balanced");
                return 0;
            }
        }
    }

    if (!is_empty())
    {
        printf("Not Balanced");
            return 0;
    }
        
    printf("Balanced");

    return 0;
}
