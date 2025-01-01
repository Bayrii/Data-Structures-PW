#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int num;
    struct node* next;
};

int create(struct node** head) {
    struct node *temp, *new_node;
    int count = 0, data;

    while (true) {
        // Asking new element for the list
        // If user press -1 loop will stop
        printf("Enter node %d (-1 to stop) : ", count + 1);
        scanf("%d", &data);
        if (data == -1) break;

        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->num = data;
        new_node->next = NULL;

        // If *head == NULL, it means it is out first node it is equal to head node  
        if (!*head) {
            *head = new_node;
        }
        // Adding as a next node 
        else{
            temp = *head;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = new_node;
        }
        count++;
    }
    return count;
}

int palin_check(struct node* head, int count) {
    // Creating array with pointer
    int *arr =(int*)malloc(count * sizeof(int));  
    int i = 0;
    struct node* temp = head;
    // Adding each node to array
    while (temp) {
        arr[i++] = temp->num;
        temp = temp->next;
    }
    // Checking if array is palindrome or not
    for (i = 0; i < count / 2; i++) {
        if (arr[i] != arr[count - 1 - i]) return 0;
    }
    return 1;
}

int main() {
    struct node* p = NULL;
    int result, count;

    printf("Enter data into the list\n");
    count = create(&p);
    result = palin_check(p, count);

    if (result == 1)
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
