#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter a integer : ");
    scanf("%d",&num);

    if (num%7)
    {
        printf("It is not divisible by 7.");
    }else
    {
        printf("It is divisible by 7.");
    }
    
    
    return 0;
}
