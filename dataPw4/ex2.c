#include<stdio.h>
int find_fac(int n){
    if (n == 0)
    {
        return 1;
    }
    return n*find_fac(n - 1);
    
}
int main(int argc, char const *argv[])
{   
    int n, fac = 1, choise;
    printf("\n---FINDING FACTORIAL OF A NUMBER---\n");
    printf("Do you want do it with recursive function or for loop.\n");
    printf("(1) Recursive\n");
    printf("(2) For loop\n");
    printf("(1) or (2) : ");
    scanf("%d",&choise);

    printf("Enter a number : ");
    scanf("%d",&n);
    switch (choise)
    {
    case 1:
        fac = find_fac(n);
        break;
    case 2:
        for (int i = 2; i <= n; i++){
            fac = fac * i;
        }
        break;
    default:
        printf("Invalid choise");
        break;
    }
    
    printf("\nFactorial of %d is %d.", n, fac);
    
    return 0;
}
