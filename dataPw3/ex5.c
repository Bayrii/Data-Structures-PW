#include<stdio.h>
#include<stdbool.h>

int my_strlen(char *string){
    
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }

    return len;
    
}

bool my_isalpha(char c){
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');    
}

bool my_isdigit(char c){
    return ('0' <= c && c <= '9');
}

char my_toupper(char c){

    if (my_isalpha(c))
    {
        if ('a' <= c && c <= 'z')
        {
            return ( c - ('a' - 'A'));
        }else{
            return c;
        }
    }else
    {
        printf("\nIt is not alpha. ");
        return c;
    }
}

char my_tolower(char c){

    if (my_isalpha(c))
    {
        if ('A' <= c && c <= 'Z')
        {
            return ( c + ('a' - 'A'));
        }else{
            return c;
        }
    }else
    {
        printf("\nIt is not alpha. ");
        return c;
    }
}

bool my_strcmp(char *str1, char *str2){

    if (my_strlen(str1) != my_strlen(str2))
    {
        return false;
    }else{
        int i = 0;
        while (str1[i] != '\0')
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
}

char* my_strcat(char *destination, const char *source){

    char *start = destination;
    while (*destination) {
        destination++;
    }

    int i = 0;
    while (*(source + i) != '\0')
    {
        *(destination + i) = *(source + i);
        i++;
    }
    *(destination + i) = '\0';
    
    return start;
    
}

char* my_strcpy(const char *source, char *destination ){

    int i = 0;
    while (*(source + i) != '\0')
    {
        *(destination + i) = *(source + i);
        i++;
    }
    *(destination + i) = '\0';

    return destination;
}

int main(int argc, char const *argv[])
{
    char test1, test2, test3;

    test1 = 'c';
    test2 = 'B';
    test3 = '4';

    // printf("Enter your character : ");
    // scanf(" %c",&chr);

    printf("\nBefore the function : %c After the toUpper : %c ", test1 ,my_toupper(test1));

    printf("\nBefore the function : %c After the toLower : %c ", test2 ,my_tolower(test2));

    printf("If it is not alpha : %c \n",my_toupper(test3));

    // Test my_strcmp
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    printf("Are '%s' and '%s' equal? %s\n", str1, str2, my_strcmp(str1, str2) ? "Yes" : "No");
    printf("Are '%s' and '%s' equal? %s\n", str1, str3, my_strcmp(str1, str3) ? "Yes" : "No");

    // Test my_strcat
    char dest[50] = "Good ";
    char src[] = "Morning";
    printf("Concatenation result: %s\n", my_strcat(dest, src));

    // Test my_strcpy
    char source[] = "Copy this!";
    char destination[50];
    printf("Copied string: %s\n", my_strcpy(source, destination));

    return 0;
}




