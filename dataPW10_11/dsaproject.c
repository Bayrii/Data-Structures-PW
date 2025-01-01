#include "dsaproject.h"

T_Elector creationelector(void) {
    T_Elector new_voter = (T_Elector)malloc(sizeof(struct elector));
    if (!new_voter) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    printf("Enter name: ");
    scanf("%s", new_voter->name);
    printf("Enter ID number: ");
    scanf("%ld", &new_voter->cin_num);
    printf("Enter choice (1-5): ");
    scanf("%d", &new_voter->choice);
    new_voter->next = NULL;
    return new_voter;
}

void displaylist(T_Elector head) {
    T_Elector temp = head;
    while (temp) {
        printf("Name: %s, ID: %ld, Choice: %d\n", temp->name, temp->cin_num, temp->choice);
        temp = temp->next;
    }
}

void addelector(T_Elector* head, char name[], long cin_num, int choice) {
    T_Elector new_voter = (T_Elector)malloc(sizeof(struct elector));
    if (!new_voter) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(new_voter->name, name);
    new_voter->cin_num = cin_num;
    new_voter->choice = choice;
    new_voter->next = NULL;

    if (!*head || strcmp(name, (*head)->name) < 0) {
        new_voter->next = *head;
        *head = new_voter;
        return;
    }

    T_Elector current = *head;
    while (current->next && strcmp(name, current->next->name) > 0) {
        current = current->next;
    }
    new_voter->next = current->next;
    current->next = new_voter;
}

int countelector(T_Elector head) {
    int count = 0;
    T_Elector temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int findelector(T_Elector head, long cin_num) {
    T_Elector temp = head;
    while (temp) {
        if (temp->cin_num == cin_num) {
            printf("Name: %s, ID: %ld, Choice: %d\n", temp->name, temp->cin_num, temp->choice);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void deletelector(T_Elector* head, long cin_num) {
    if (!*head) return;

    T_Elector temp = *head;

    if (temp->cin_num == cin_num) {
        *head = temp->next;
        free(temp);
        return;
    }

    T_Elector prev = NULL;
    while (temp && temp->cin_num != cin_num) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Voter with ID %ld not found.\n", cin_num);
    }
}

void decomposelist(T_Elector head, T_Elector* left, T_Elector* right, T_Elector* white) {
    while (head) {
        T_Elector next = head->next;
        head->next = NULL;
        if (head->choice == 1 || head->choice == 3) {
            head->next = *left;
            *left = head;
        } else if (head->choice == 2 || head->choice == 4) {
            head->next = *right;
            *right = head;
        } else {
            head->next = *white;
            *white = head;
        }
        head = next;
    }
}

void sortlist(T_Elector head) {
    if (!head || !head->next) return;

    for (T_Elector i = head; i->next; i = i->next) {
        for (T_Elector j = i->next; j; j = j->next) {
            if (i->cin_num > j->cin_num) {
                // Swap data
                char temp_name[50];
                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                long temp_cin = i->cin_num;
                i->cin_num = j->cin_num;
                j->cin_num = temp_cin;

                int temp_choice = i->choice;
                i->choice = j->choice;
                j->choice = temp_choice;
            }
        }
    }
}

T_Elector mergelists(T_Elector left, T_Elector right) {
    T_Elector merged = NULL, tail = NULL;

    while (left && right) {
        T_Elector* smaller = (left->cin_num < right->cin_num) ? &left : &right;
        if (!merged) {
            merged = *smaller;
        } else {
            tail->next = *smaller;
        }
        tail = *smaller;
        *smaller = (*smaller)->next;
    }

    if (left) tail->next = left;
    if (right) tail->next = right;

    return merged;
}

int countLR(T_Elector head) {
    int count = 0;
    while (head) {
        if (head->choice == 1 || head->choice == 3) {
            count++;
        }
        head = head->next;
    }
    return count;
}

void freelist(T_Elector head) {
    while (head) {
        T_Elector temp = head;
        head = head->next;
        free(temp);
    }
}
