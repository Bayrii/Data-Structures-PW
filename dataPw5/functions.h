#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Functions
void get_arr(int, int *);
void get_arr_string(int, char **);
void display(int, int *);
void display_string(int, char **);
void reverse(int, int *);
void reverse_string(int, char **);
void splitting(int *, int *, int *, int);
int search(int, int *, int );
int find_max(int, int *);
int sumelet(int, int *);



void display(int count, int *arr){

    if (!arr || count == 0)
    {
        printf("Array is empty.");
        return ;
    }
    printf("[ ");
    for (int i = 0; i < count; i++){
        if (i < count - 1)
        {
            printf("%d, ", arr[i]); 
        }else{
            printf("%d ]\n",arr[i]);  
        }
    }
        
}

void display_string(int count,char **arr){
    if (!arr || count == 0)
    {
        printf("Array is empty.");
        return ;
    }
    printf("[ ");
    for (int i = 0; i < count; i++) {
        if (i < count - 1)
        {
            printf("\"%s\", ", arr[i]);
        }else
        {
            printf("\"%s\" ]\n", arr[i]);
            
        }
    }
}

void get_arr(int count, int *arr){

    for (int i = 0; i < count; i++){
        printf("Enter element %d : ", i + 1);
        scanf("%d",&arr[i]);
    }
}

void get_arr_string(int count, char **arr){

    for (int i = 0; i < count; i++){
        printf("Enter string %d : ", i + 1);
        scanf("%s", arr[i]);
    }
}

void reverse(int count, int *arr){
    int temp;
    for (int i = 0; i < count/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[count - i - 1];
        arr[count - i - 1] = temp;
    }
    
}

void reverse_string(int count, char **arr){
    char temp[100];
    for (int i = 0; i < count / 2; i++) {
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[count - i - 1]);
        strcpy(arr[count - i - 1], temp);
    }
}

void splitting(int *elements, int *arr1, int *arr2, int count){
    int odd = 0, even = 0;

    for (int i = 0; i < count; i++)
    {
        if (elements[i] % 2 == 0)
        {
            arr1[even] = elements[i];
            even ++;
        }else{
            arr2[odd] = elements[i];
            odd++;
        }
    }
    printf("\n---Even elements---\n");
    display(even, arr1);
    printf("\n---Odd elements---\n");
    display(odd, arr2);
}

int search(int count, int *arr, int search){
    for (int i = 0; i < count; i++)
    {
        if (search == arr[i])
        {
            return i;
        }
    }
    return -1;
    
}

int find_max(int count, int *arr){
    int mmax = arr[0];

    for (int i = 1; i < count; i++)
    {
        if (mmax <= arr[i])
        {
            mmax = arr[i];
        }
    }
    return mmax;   
}

int sumelet(int count, int *arr){
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    return sum;
    
}

#endif