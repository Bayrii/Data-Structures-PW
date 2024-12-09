#include<stdio.h>
#include <stdbool.h> 

bool isnumber(char c){
    return ('0' <= c && c <= '9');

}

bool isLower(char c){
    return ('a' <= c && c <= 'z');
}

bool isUpper(char c){
    return ('A' <= c && c <= 'Z');
}
int main(int argc, char const *argv[])
{

    char c;
    printf("Enter a character: ");
    scanf("%c",&c);
    if (isUpper(c)) {
        printf("The character is uppercase.\n");
    } else if (isLower(c)) {
        printf("The character is lowercase.\n");
    } else if (isnumber(c)) {
        printf("The character is a number.\n");
    } else {
        printf("The character is neither uppercase, lowercase, nor a number.\n");
    }
        
    return 0;
}
