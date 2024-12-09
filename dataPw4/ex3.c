/*
Prog1:
#include<stdio.h>
void swap(int *p, int *q);

int main(void){
    int a = 3, b = 7;
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
void swap(int *p, int *q){
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}
*/
/**
 * Prog1
 * First program is for swapping number.
 * It uses swap function for that.
 * In this function we are using gloabal variables, that is why in the main() we need to give address of variables. 
 * @param tmp A temporary variable used to temporarily store a number during the swapping process.
 */


/*
Prog2:
#include <stdio.h>
int min(int a, int b);

int main(void) {
    int j, k, m;
    printf("Input two integers: ");
    scanf("%d%d", &j, &k);
    m = min(j, k);
    printf("\n Of the two values %d and %d, the minumum is %d.\n\n", j, k, m);
    return 0;
}
int min(int a, int b) {
    if (a < b)
    return a;
    else
    return b;
}

*/

/**
 * Prog2
 * Second program finds the smallest of two numbers.
 * It uses a min function for comparing.
 * It checks numbers and @return  @param a or @param b.
 */


/*
Prog3:
#include <stdio.h>
int main(){
    int *px;
    int x;
    px = &x;
    *px = 0;
    printf(" x = %d \n", x);
    printf(" *px = %d \n", *px);
    *px += 5;
    printf(" x = %d\n", x);
    printf(" *px = %d\n", *px);
    (*px)++;
    printf(" x = %d\n", x);
    printf(" *px = %d\n", *px);
    return 0;
}
*/

/**
 * Prog3
 * Third program show the use of pointers in C.
 * It changes a variable using its pointer.
 * @param px A pointer to the integer variable x.
 * @param x An integer variable.
 * When we change the value of @param px, the value of @param x also changes.    
 */
