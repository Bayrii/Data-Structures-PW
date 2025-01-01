#if !defined(DOUBLYLL_H)
#define DOUBLYLL_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Structure for Node//
typedef struct Node {
    int data;             
    struct Node* next;    
    struct Node* prev;   
} Node;

// Function Prototypes //
void find_min_max(Node* head, int* min, int* max);
Node* create_doubly_node(void);
Node* add_node(Node* head, int data);
void print_list(Node* head);
bool is_palindrome(Node* head);

//------------------------------------------------ FUNCTIONS ------------------------------------------------//

/**
 * Function to find the minimum and maximum elements in a doubly linked list.
 * Iterates through the list to compare and find the minimum and maximum values.
 * @param head pointer to the head of the list
 * @param min pointer to store the minimum value
 * @param max pointer to store the maximum value
 */
void find_min_max(Node* head, int* min, int* max) {
    if (!head) {
        printf("The list is empty.\n");
        *min = *max = -1;
        return;
    }

    Node* current = head;
    *min = current->data;
    *max = current->data;

    while (current) {
        if (current->data < *min) *min = current->data;
        if (current->data > *max) *max = current->data;
        current = current->next;
    }
}

/**
 * Function to create a new node for a doubly linked list.
 * Prompts the user to enter a value for the node and initializes it.
 * @return pointer to the newly created node
 */
Node* create_doubly_node(void) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Enter first value of List : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/**
 * Function to add a new node with given data to the end of a doubly linked list.
 * Allocates memory for a new node and appends it to the list.
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
    new_node->next = NULL;
    new_node->prev = NULL;

    if (!head) {
        return new_node; // New node becomes the head if the list is empty
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;

    return head;
}

/**
 * Function to print all elements of a doubly linked list.
 * Traverses the list and prints each node's data in order.
 * @param head pointer to the head of the list
 */
void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * Function to check if a doubly linked list is a palindrome.
 * Uses two pointers, `left` starting from the head and `right` starting from the tail,
 * to compare values until they meet in the middle.
 * @param head pointer to the head of the list
 * @return true if the list is a palindrome, false otherwise
 */
bool is_palindrome(Node* head) {
    if (!head) return true; // An empty list is a palindrome

    Node* left = head;
    Node* right = head;

    // Move `right` to the end of the list
    while (right->next) {
        right = right->next;
    }

    // Compare nodes from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

#endif // DOUBLYLL_H
