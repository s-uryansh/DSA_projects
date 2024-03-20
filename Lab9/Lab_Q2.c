#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);
void swap(int *a, int *b); // Swap function to help sorting
void print(int arr[], int size); //printing array


int main(){
    int size = 0;
    scanf("%d",&size);  //Enter size of array
    int arr[size];
    int temp;
    for(unsigned int i = 0; i<size;i++){    // take inputs in the array
        scanf("%d",&temp);
        arr[i] = temp;
    }

    quickSort(arr, 0, size - 1); // passing high , low and array to quicksort
    
    print(arr, size); // printing array
    return 0;

    
    return 0;
}

//swapping two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//quicksort uses divide-and-conquer, and so it's a recursive algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);  

    for (int j = low; j < high; j++) 
    {
       
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); //swapping elements if element in array is less than pivot
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
    //choosing a pivot element and use the divide and conquer rule
}


//sorting array
void quickSort(int arr[], int low, int high){
    if (low < high) {
        
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        //use of recursion as quicksort is based on recursive algorithm
    }
}

//displaying array
void print(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}