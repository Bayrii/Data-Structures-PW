#include <stdio.h>
int find_gcd(int a, int b, int divisor){
    if (a % divisor == 0 && b % divisor == 0) {
        return divisor; 
    }
    return find_gcd(a, b, divisor - 1); 
}
int main() {
    int m, n, i, gcd, choise;
    printf("\n---FINDING GCD OF TWO NUMBERS---\n");
    printf("Do you want do it with recursive function or for loop.\n");
    printf("(1) Recursive\n");
    printf("(2) For loop\n");
    printf("(1) or (2) : ");
    scanf("%d",&choise);

    printf("Enter two integers: ");
    scanf("%d%d",&m,&n);

    switch (choise)
    {
    case 1:
        gcd = (m < n) ? m : n;
        gcd = find_gcd(m,n,gcd);
        break;
    case 2:
        for(i=1;i<=m && i <=n;i++){

            if(m % i == 0 && n % i == 0)gcd = i;
        }
        break;
    default:
        printf("Invalid choise.");
        break;
    }
    
    
    printf("G.C.D of %d and %d is %d", m, n, gcd);
    return 0;
    }
