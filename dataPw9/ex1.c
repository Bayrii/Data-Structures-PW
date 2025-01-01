#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doublyll.h"

// In this code I used my own doublyll.h library to make code more readible and look clean
// doublyll.h header file contains all the doubly linked list funcstions for PW9, additionally add_node, create_doubly_node and print_list functions

int main() {
    Node* head = NULL;
    int min, max;

    // Creating first node (head) of list
    head = create_doubly_node();
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
    printf("\nYour Doubly Linked List: ");
    print_list(head);

    // Finding and displaying minimum and maximum
    find_min_max(head, &min, &max);
    printf("Minimum: %d, Maximum: %d\n", min, max);

    return 0;
}
