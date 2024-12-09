#include<stdio.h>
#include<string.h>
int my_strlen(char string[]){
    
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }

    return len;
    
}

int main(int argc, char const *argv[])
{
    char str[100];
    printf("Enter a string : ");
    scanf("%s",&str);
    // fgets(str, sizeof(str), stdin);

    int l = my_strlen(str);

    printf("Lentgh of your string is %d",l);

    if (l==strlen(str))
    {
        printf("\nProgram working well.\nTrue....");
    }else
    {
        printf("\nProgram is not working well.\nFalse....");
    }
    
    

    return 0;
}
