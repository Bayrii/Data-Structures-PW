#include <stdio.h>
#include <stdbool.h> 
int main() {
    
    int count = 0;
    
    int ch;
    printf("Enter character : ");
    scanf("%d",&ch);
    
    while (true) {
        if (0 <= ch && ch <= 9){
            scanf("%d",&ch);
            count++;
        }else{
            printf("%d",count);
            break;
        }
    }

    return 0;
}