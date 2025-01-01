#include "dsaproject.h"

int main() {
    T_Elector voters = NULL, left = NULL, right = NULL, white = NULL;
    int choice;
    char name[50];
    long id;
    int vote;
    do {
        printf("\n--- Election Menu ---\n");
        printf("1. Enter voters\n");
        printf("2. Add voter\n");
        printf("3. Delete voter\n");
        printf("4. Search voter\n");
        printf("5. Display voters\n");
        printf("6. Count voters\n");
        printf("7. Split and process lists\n");
        printf("8. Calculate percentages\n");
        printf("9. Free lists\n");
        printf("10. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enter voters
                voters = creationelector();
                break;
            case 2: // Add voter

                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter ID: ");
                scanf("%ld", &id);
                printf("Enter vote (1-5): ");
                scanf("%d", &vote);
                addelector(&voters, name, id, vote);
                break;
            case 3: // Delete voter
                printf("Enter ID to delete: ");
                scanf("%ld", &id);
                deletelector(&voters, id);
                break;
            case 4: // Search voter
                printf("Enter ID to search: ");
                scanf("%ld", &id);
                if (!findelector(voters, id)) {
                    printf("Voter not found.\n");
                }
                break;
            case 5: // Display voters
                displaylist(voters);
                break;
            case 6: // Count voters
                printf("Number of voters: %d\n", countelector(voters));
                break;
            case 7: // Split and process lists
                decomposelist(voters, &left, &right, &white);
                printf("List split into left, right, and white lists.");

                // Sorting the sub-lists
                sortlist(left);
                sortlist(right);
                sortlist(white);

                printf("\nSorted Left List:\n");
                displaylist(left);

                printf("\nSorted Right List:\n");
                displaylist(right);

                printf("\nWhite List (No sorting needed):\n");
                displaylist(white);

                // Merging the left and right lists
                T_Elector merged_list = mergelists(left, right);
                printf("\nMerged Left and Right List:\n");
                displaylist(merged_list);
                break;
            case 8: // Calculate percentages
                printf("Left voters: %d\n", countLR(left));
                break;
            case 9: // Free lists
                freelist(voters);
                freelist(left);
                freelist(right);
                freelist(white);
                printf("All lists freed.\n");
                break;
        }
    } while (choice != 10);

    return 0;
}
