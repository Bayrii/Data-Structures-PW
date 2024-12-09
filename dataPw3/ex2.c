#include<stdio.h>

int main(int argc, char const *argv[])
{
    int year;
    printf("Enter a year : ");
    scanf("%d",&year);

    if (year % 100 == 0 && year % 4 == 0)
    {
        printf("It is not a leap year.");

    }else if (year % 400 == 0 && year % 4 == 0)
    {
        printf("It is a leap year.");
    }

    return 0;
}
