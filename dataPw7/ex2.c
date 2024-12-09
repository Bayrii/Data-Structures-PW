#include<stdio.h>
#include<stdlib.h>
// Defining SIZE to 100
# define SIZE 100

// Predefined queue components
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;

void enqueue(int x){   //entering element to the end of queue
    int insert_item;
    if (Rear == SIZE - 1){
        printf("Overflow \n");}
    else{
    if (Front == - 1){
        Front = 0;}
    Rear = Rear + 1;
    inp_arr[Rear] = x;
    }
}
void dequeue(){     //deleting element from the front of queue
    if (Front == - 1 || Front > Rear) {
        printf("Underflow \n");
        return ;}
    else{
        printf("\nElement deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;}
}
void show(){          // showing all of the elements of the queue
    if (Front == - 1 || Front > Rear){       
        printf("Empty Queue !!\n");}
    else{
        printf("Queue: ");
        for (int i = Front; i <= Rear; i++){
            printf("%d ", inp_arr[i]);}
}
    printf("\n");
}

int main(int argc, char const *argv[])
{
    printf("Queue practice.\n");
    int l;

    printf("Enter number of elements : ");
    scanf("%d",&l);

    int *elements = (int *)malloc(l * sizeof(int));
    // Checks whether memory was allocated successfully or didn't.
    // !elements ====> elements == NULL
    if (!elements) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < l; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d",&elements[i]);
        enqueue(elements[i]);
    }

    while(Front <= Rear){              // in this loop it deleted the elements of queue one by one until it is empty
        dequeue();
        show();        // this is for showing the queue while deleting the elements
    }
    
    return 0;
}
