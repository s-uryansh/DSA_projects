#include <stdio.h>
#include <stdlib.h>

//merge sort is an efficient, general-purpose, and comparison-based sorting algorithm

void mergeSort(int arr[], int low, int high);
void merging(int arr[], int left, int middle, int right); //merging array back after sorting

int main(){
    int size = 0;
    scanf("%d",&size); // Enter size of array
    int arr[size];
    int temp;
    for(unsigned int i = 0; i<size;i++){    // take inputs in the array
        scanf("%d",&temp);
        arr[i] = temp;
    }
    mergeSort(arr, 0, size - 1); //passing array to sort and merge

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    } //printing sorted array
    printf("\n");
    
    return 0;
}

//Merger sort uses divide and rule to complete it's sorting
void merging(int arr[], int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    
    for (j = 0; j < n2; j++){    
        R[j] = arr[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;


        mergeSort(arr, left, middle); // sorting first and last part of array 
        mergeSort(arr, middle + 1, right);

    //merge sort uses recursion to sort array ^ ^ ^ ^ ^  

        merging(arr, left, middle, right);
    }
}