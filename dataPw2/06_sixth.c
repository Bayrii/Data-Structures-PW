#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n1, n2, n3;

    // Step 1: Ask the user to enter three numbers
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);
    printf("Enter the third number: ");
    scanf("%d", &n3);
    
    if (n3 <= n1 && n3 <= n2)
    {
        printf("Smallest number is : %d",n3);
    }else if (n1 <= n2)
    {
        printf("Smallest number is : %d",n1);
    }else{
        printf("Smallest number is : %d",n2);
    }

    if (n3 >= n1 && n3 >= n2)
    {
        printf("Largest number is : %d",n3);
    }else if (n1 >= n2)
    {
        printf("Largest number is : %d",n1);
    }else{
        printf("Largest number is : %d",n2);
    }
    
    printf("Sum of numbers : %d", (n1 + n2 + n3));

    return 0;
}
