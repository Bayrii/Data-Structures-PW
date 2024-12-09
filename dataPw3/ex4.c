#include<stdio.h>
#include<stdbool.h>

bool my_isalpha(char c){
    return ('A' <= c <= 'Z') || ('a' <= c <= 'z');    
}

bool my_isdigit(char c){
    return ('0' <= c <= '9');
}

int main(int argc, char const *argv[])
{
    printf("Enter a character : ");

    char chr;
    scanf("%c",&chr);

    if (my_isalpha(chr))
    {
        printf("Your character is alpha. ");
    }else if (my_isdigit(chr))
    {
        printf("Your character is digit. ");
    }else{
        printf("Your character is undefined. ");
    }
    
    
    return 0;
}
 