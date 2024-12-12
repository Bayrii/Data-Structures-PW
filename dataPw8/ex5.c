#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"linkedlist.h"

// In this code I used my own linkedlist.h library to make code more readible and look clean
// linkedlist.h header file contains all the funcstions for PW8, additionally add_node, create_node and sort_list functions

int main(int argc, char const *argv[])
{
    
    Node *head = NULL;
    Node *last = NULL; 

    // Creating first node (head) of list
    head = create_node();
    int nodeCount = 0;
    int data;
    while (true)
    {   
        // Asking new element for the list
        // If user press -1 loop will stop
        printf("Enter node %d (press -1 to stop) : ", nodeCount + 2);
        scanf("%d",&data);
        if (data == -1)
        {
            break;
        }
        // Adding new node with the entered data
        add_node(head, data);
        nodeCount++;
    }
    
    // Displaying whole list
    printf("\nYour linked list : ");
    print_list(head);
    
    int choice;
    printf("\nHow do you want to reverse it ? ");
    printf("\n(1) Iterative way or (2) recursive way ");
    printf("\n(1) or (2) : ");
    scanf("%d", &choice);
    
    if (choice == 1)
    {
        // Reversing itarative way
        last = reverse_list(head);
    }else if (choice == 2)
    {
        // Reversing recursive way
        last = reverse_list_recursive(head);
    }else{
        printf("\nInvalid choice.\n");
    }

    // Displaying
    printf("\nReversed linked list : ");
    print_list(last);

    // Free memory for all nodes
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
