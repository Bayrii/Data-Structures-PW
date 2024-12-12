#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// Structure for Node // 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function Prototypes //
Node* create_node(void);
Node* add_node(Node* head, int data);
void print_list(Node* head);
void front_back_split(Node* source, Node** front, Node** back);
Node* sorted_merge(Node* list1, Node* list2);
Node* merge_sort(Node* head);
void remove_duplicates(Node* head);
Node* reverse_list(Node* head);
Node* reverse_list_recursive(Node* head);
Node* sort_list(Node* head);


//------------------------------------------------ FUNCTIONS ------------------------------------------------//

/**
 * Additional function to sort
 * Sorts a linked list using Bubble Sort.
 * Compares and swaps data values to arrange the list in ascending order.
 * @param head pointer to the head of the list
 * @return pointer to the sorted list
 */

Node* sort_list(Node* head){
    if (!head)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node* current = head;
    for (Node* i = current; i->next != NULL; i = i->next)
    {
        for (Node* j = i->next; j != NULL ; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            
        }
        
    }
    
    return head;

}

/**
 * Additional function to create a new node with user input.
 * Allocates memory for a node and assigns a value to its data field.
 * @return pointer to the newly created node
 */
Node* create_node(void) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memorary allocation failed\n");
        return NULL;
    }
    printf("Enter first value of List : ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;
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
    new_node->next = NULL; 
    // Copying
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    return head;
}

/**
 * Additional function to print the elements of a linked list.
 * Iterates through the list and prints each node's data.
 * @param head pointer to the head of the list
 */
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * Exercise 1
 * Splits a linked list into two halves.
 * Uses the slow and fast pointer technique to find the midpoint of the list.
 * @param source pointer to the original list
 * @param front pointer to store the first half of the list
 * @param back pointer to store the second half of the list
 */
void front_back_split(Node* source, Node** front, Node** back) {
    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

/**
 * Exercise 2
 * Merges two sorted linked lists into one sorted list.
 * Recursively compares elements of both lists and arranges them in order.
 * @param list1 pointer to the first sorted list
 * @param list2 pointer to the second sorted list
 * @return pointer to the merged sorted list
 */
Node* sorted_merge(Node* list1, Node* list2) {
    if (!list1) 
        return list2;
    if (!list2) 
        return list1;

    Node* result;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = sorted_merge(list1->next, list2);
    } else {
        result = list2;
        result->next = sorted_merge(list1, list2->next);
    }
    return result;
}

/**
 * Exercise 2
 * Implements Merge Sort to sort a linked list.
 * Divides the list into halves, sorts each half, and merges them back.
 * @param head pointer to the head of the list
 * @return pointer to the sorted list
 */
Node* merge_sort(Node* head) {
    if (!head || !head->next) return head;

    Node* front;
    Node* back;
    front_back_split(head, &front, &back);

    front = merge_sort(front);
    back = merge_sort(back);

    return sorted_merge(front, back);
}


/**
 * Exercise 4
 * Removes duplicate elements from a sorted linked list.
 * Traverses the list and deletes nodes with duplicate data values.
 * @param head pointer to the head of the sorted list
 */

void remove_duplicates(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

/**
 * Exercise 5
 * Reverses a linked list iteratively.
 * Reverses the links between nodes to point in the opposite direction.
 * @param head pointer to the head of the list
 * @return pointer to the new head of the reversed list
 */

Node* reverse_list(Node* head) {
    Node* previous = NULL;
    Node* current = head;
    Node* following;

    while (current != NULL) {
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    return previous;
}

/**
 * Exercise 5
 * Reverses a linked list recursively.
 * Changes the links between nodes recursively until the list is reversed.
 * @param head pointer to the head of the list
 * @return pointer to the new head of the reversed list
 */

Node* reverse_list_recursive(Node* head) {
    if (!head || !head->next) return head;

    Node* reversed_list = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversed_list;
}

#endif // LINKEDLIST_H
