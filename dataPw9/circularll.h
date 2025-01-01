#if !defined(CIRCULARLL_H)
#define CIRCULARLL_H

#include<stdio.h>
#include<stdlib.h>

// Structure for Node//
typedef struct Node {
    int data;             
    struct Node* next;    
} Node;

// Function Prototypes //
Node* create_circular_node(void);
Node* add_node(Node* head, int data);
Node* reverse_circular_list(Node* head);
void display_list(Node* head);

//------------------------------------------------ FUNCTIONS ------------------------------------------------//

/**
 * Function to create a new circular linked list node.
 * Prompts the user to enter a value for the node and links the node to itself.
 * @return pointer to the newly created node
 */
Node* create_circular_node(void) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Enter first value of List : ");
    scanf("%d", &new_node->data);
    new_node->next = new_node; // Point to itself (circularity for a single node)
    return new_node;
}

/**
 * Additional function to add a new node with given data to the end of the list.
 * Allocates memory for a new node and links it to the current list.
 * @param head pointer to the head of the list
 * @param data value to be added to the new node
 * @return pointer to the updated head of the list
 */
Node* add_node(Node* head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = data;

    if (head == NULL) {
        // If the list is empty, the new node points to itself
        new_node->next = new_node;
        return new_node; // New node becomes the head
    }

    // Traverse to the last node
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    // Insert the new node at the end of the list and make it circular
    current->next = new_node;
    new_node->next = head;

    return head;
}

/**
 * Function to reverse a circular linked list.
 * Iteratively reverses the links between nodes, maintaining circularity.
 * @param head pointer to the head of the list
 * @return pointer to the new head of the reversed list
 */
Node* reverse_circular_list(Node* head) {
    if (!head || !head->next) return head;

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;

    return head;
}

/**
 * Function to display the elements of a circular linked list.
 * Traverses the list and prints each node's data, maintaining circularity.
 * @param head pointer to the head of the list
 */
void display_list(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(back to head)\n");
}

#endif // CIRCULARLL_H
