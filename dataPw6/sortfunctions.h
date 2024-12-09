#if !defined(SORTFUNCTIONS_H)
#define SORTFUNCTIONS_H

#include<stdlib.h>
// Function Prototypes //
void selectionSort(int, int*);
void bubbleSort(int, int*);
void insertionSort(int, int*);
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void quickSort_ascennding(int*, int, int);
int partition_ascending(int*, int, int);
void quickSort_decennding(int*, int, int);
int partition_decending(int*, int, int);
void swap(int*, int*);

//------------------------------------------------ FUNCTIONS ------------------------------------------------//

/**
 * Swaps the values of two integers.
 * With the pointer, when we change the value of a and b inside of functions, it will to outside of function directly
 * @param a pointer to the first integer
 * @param b pointer to the second integer
 */

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* Selection sort function
* Sort elements by for loops searching  the minimum element 
* and moving it to the first index of the array  
* Time Complexity O(n^2)
* @param count length of array
* @param arr pointer for the array
*/

void selectionSort(int count, int* arr){
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[j], &arr[i]);
                // int temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
            }
            
        }
        
    }
    
}

/**
* Bubble sort function
* Sort elements by comparing adjancent elemenents and swaps if needed, until end of array
* and puts largest element to top  
* Time Complexity O(n^2)
* @param count length of array
* @param arr pointer for the array
 */

void bubbleSort(int count, int* arr){

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
            
        }
        
    }
    
}

/**
 * Insertion sort function.
 * Sorts the array by building a sorted array element by element and every time length of sorted array increase one by one.
 * Time Complexity O(n^2)
 * @param count length of array
 * @param arr pointer to the array
 */

void insertionSort(int count, int* arr){
    int temp;

    for (int i = 1; i < count; i++)
    {
        int trnum = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > trnum)
        {
            arr[j + 1] = arr[j];  
            j--; 
        }
        
        arr[j + 1] = trnum;
    }
    
}

/**
 * Merge two sorted subarrays into one sorted array.
 * Time Complexity O(n)
 * @param arr pointer to the array
 * @param left starting index of the first subarray
 * @param mid ending index of the first subarray
 * @param right ending index of the second subarray
 */

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;    
    int n2 = right - mid;

    int *LeftArr = (int*)malloc(n1 * sizeof(int));
    int *RightArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) LeftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) RightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            arr[k] = LeftArr[i];
            i++;
        }else
        {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = LeftArr[i]; i++; k++;
    }

    while (j < n2)
    {
        arr[k] = RightArr[j]; j++; k++;
    }
    
}

/**
 * Merge sort function.
 * Everytime divides the array into subarrays and sorts them using merge() and then can itself again repeat.
 * Time Complexity O(n log n)
 * @param arr pointer to the array
 * @param left starting index of the array
 * @param right ending index of the array
 */

void mergeSort(int* arr, int left, int right){
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right);
    }
    
}

/**
 * Quick sort function (ascending order).
 * Partitions the array and recursively sorts the partitions.
 * Time Complexity O(n log n) 
 * @param arr pointer to the array
 * @param low starting index
 * @param high ending index
 */

void quickSort_ascennding(int* arr, int low, int high){

    if (low < high)
    {
        int position = partition_ascending(arr, low, high);
        quickSort_ascennding(arr, low, position - 1);
        quickSort_ascennding(arr, position + 1, high);
    }
    
}

/**
 * Quick sort function (descending order).
 * Partitions the array and recursively sorts the partitions.
 * Time Complexity O(n log n)
 * @param arr pointer to the array
 * @param low starting index
 * @param high ending index
 */

void quickSort_decennding(int* arr, int low, int high){

    if (low < high)
    {
        int position = partition_decending(arr, low, high);
        quickSort_decennding(arr, low, position - 1);
        quickSort_decennding(arr, position + 1, high);
    }
    
}

/**
 * Partition function for Quick Sort (ascending order).
 * Rearranges elements based on a pivot value.
 * @param arr pointer to the array
 * @param low starting index
 * @param high ending index
 * @return new pivot index
 */

int partition_ascending(int* arr, int low, int high){
    
    int pivot = arr[high];

    int i =  low;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        
    }
    swap(&arr[i], &arr[high]);
    return i;
}

/**
 * Partition function for Quick Sort (descending order).
 * Rearranges elements based on a pivot value.
 * @param arr pointer to the array
 * @param low starting index
 * @param high ending index
 * @return new pivot index
 */

int partition_decending(int* arr, int low, int high){
    
    int pivot = arr[high];

    int i =  low;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        
    }
    swap(&arr[i], &arr[high]);
    return i;
}


#endif // SORTFUNCTIONS_H
