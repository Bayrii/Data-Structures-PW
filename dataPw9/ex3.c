#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circularll.h"

// In this code I used my own circularll.h library to make code more readible and look clean
// circularll.h header file contains all the circular linked list funcstions for PW9, additionally add_node, create_circular_node and print_list functions

int main() {
    Node* head = NULL;
    int min, max;

    // Creating first node (head) of list
    head = create_circular_node();
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
        head = add_node(head, data);
        nodeCount++;
    }

    // Displaying whole list
    printf("\nYour Circular Linked List: ");
    display_list(head);

    // Creating a node reversed list
    Node* last = NULL;
    
    // Reversing and displaying the list
    last = reverse_circular_list(head);
    display_list(last);

    return 0;
}

