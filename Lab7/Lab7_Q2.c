#include<stdio.h>

void qsort(int* ar,int n);
void display(int* ar ,int n);
void swap(int* n1 , int* n2);


int main(){
    int n;
    scanf("%d" , &n);
    int ar[n];

//assigning values in the array

    for(int i =0 ; i <n ; i++){
        scanf("%d", &ar[i]);
    }
    

    
    qsort(ar,n);

    display(ar,n);

    return 0;
}

//display current elements of array
void display(int* ar,int n){

    if(n == 0){ //checking if array is empty or not
        printf("Array is empty");
    }else{
        for(int i =0; i< n ; i++){
            printf("%d ", ar[i]);
        }
    }
}

void swap(int* n1, int* n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


// Sorting elements in array from last to first

void qsort(int* ar, int n) {

    for (int i = n - 1; i >= 0; i--) { // going from last element to first element sorting them out

        for (int j = n - 1; j > n - i - 1; j--) { //making sure only unsorted part is taken 

            if (ar[j] < ar[j - 1]) {
                swap(&ar[j], &ar[j - 1]);

            }
        }
    }
}
