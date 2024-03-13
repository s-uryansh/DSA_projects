
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
//To swap two element for sorting
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void slctSort(int arr[], int n);
void display(int arr[], int n);
//Display elements in array
void display(int arr[], int n){
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    printf("Size: "); // Enter number of elements in array (size for the array)
    int n;
    scanf("%d", &n);
    int array[n];
    //Inserting number in array to sort them

    printf("Enter elements for array: ");
    for (int i=0; i<n; i++){

        scanf("%d", &array[i]);
    }

    printf("Unsorted :\n");
    //printing the unsorted array first

    display(array, n);

    slctSort(array, n);

    printf("Sorted :\n");
    //printing elements in array after sorting
    display(array, n);
}
//Sorting the array
void slctSort(int array[], int n){
    int index;

    for (int i = 0; i < n-1; i++)
    {
        index = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[index])
            {
                index = j;
            }
        }
        swap(&array[index], &array[i]);
    }
}
