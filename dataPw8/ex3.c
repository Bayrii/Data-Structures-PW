#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"linkedlist.h"

// In this code I used my own linkedlist.h library to make code more readible and look clean
// linkedlist.h header file contains all the funcstions for PW8, additionally add_node, create_node and sort_list functions

int main(int argc, char const *argv[])
{
    
    Node *head = NULL;
    Node *front = NULL;
    Node *back = NULL;

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

    // Splitting and displaying both lists
    front_back_split(head, &front, &back);      
    printf("\nList1 : ");
    print_list(front);
    printf("\nList2 : ");
    print_list(back);

    // Using sort merge, sorting both lists and then merging sorted lists
    front = merge_sort(front);
    back = merge_sort(back);
    head = sorted_merge(front,back);

    // Displaying sorted list
    printf("\nMerged list : ");
    print_list(head);

    // Free memory for all nodes
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
