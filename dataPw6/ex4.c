#include<stdio.h>
#include<string.h>
 
// Defining max length of string
#define MAX_LENGTH 100 


int main(int argc, char const *argv[])
{

    char string[MAX_LENGTH];
    printf("Enter your string : ");
    scanf("%s", &string);

    for (int i = 0; i < strlen(string) - 1; i++)
    {
        for (int j = i + 1; j < strlen(string); j++)
        {
            if (string[i] > string[j])
            {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
            
        }
        
    }

    printf("Your sorted string : %s",string);
    
    int count = 1;

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == string[i + 1])
        {
            count++;
        }else
        {
            printf("\n%c %d",string[i], count);
            count = 1;
        }
        
        
    }
    
    return 0;

}