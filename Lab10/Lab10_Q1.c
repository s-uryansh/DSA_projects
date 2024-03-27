#include<stdio.h>

void display(int *arr , int N);
void do_heap(int *arr , int   N , int i);
void heapSort(int *arr , int N);
int swap(int* a , int* b);
int main(){
    int size = 0 ;
    scanf("%d" , &size);

    int arr[size];
    int temp;
    for(unsigned int i = 0; i <size; i++ ){
        scanf("%d" , &temp);
        arr[i] = temp;
    }

    heapSort(arr , size);
    display(arr , size);
    return 0;
}



int swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
 
}

//Heap sort is a comparison-based sorting technique based on Binary Heap data structure. 
//It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning.
//Repeat the same process for the remaining elements



void heapSort(int *arr , int N){

    //Doing max-heap 

    for(int i = N/ 2 - 1 ; i >= 0; i--){
        do_heap(arr , N , i);
    }

    //passing values to sort them using heap_sort

    for(int i = N -1 ; i >= 0 ; i--){
        swap(&arr[0] , &arr[i]);

// HeapSort root element for highest element at root again

        do_heap(arr , i , 0);
    }

}

void do_heap(int *arr , int   N , int i){
    int big = i;

    int left = 2 *i +1 ;
    int right = 2 *i +2 ;

// Line 23 - 29 checking if left or right child is bigger than root

    if(left < N && arr[left] > arr[big]){
        big = left;
    }

    if(right < N && arr[right] > arr[big]){
        big = right;
    }


// Loop in line 34 -37 if root is not largest - swap and continue Heap Sort

    if(big != i){
        swap(&arr[i] , &arr[big]);
        do_heap(arr , N , big);
    }
}





/*How Heap sort works:

First convert the array into heap data structure using do_heap ,
then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. 
Repeat this process until size of heap is greater than 1.

Build a heap from the given input array.
Repeat the following steps until the heap contains only one element:
Swap the root element of the heap (which is the largest element) with the last element of the heap.
Remove the last element of the heap (which is now in the correct position).
Heapify the remaining elements of the heap.
The sorted array is obtained by reversing the order of the elements in the input array.

*/

//Printing Array
void display(int *arr, int N){
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}