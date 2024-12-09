#include <stdio.h>

void secondto_minut_and_second(int sec){
    if(sec < 60){
        printf("\nIt is equal to 0 minute, %d second\n",sec);
    }else{
        int min;
        min = sec / 60;
        sec = sec % 60;
        printf("\nIt is equal to %d minute, %d second\n",min,sec);
    }
}
int main() {
    
    int second;
    printf("Enter seconds : ");
    scanf("%d",&second);
    
    secondto_minut_and_second(second);
    
    return 0;
}