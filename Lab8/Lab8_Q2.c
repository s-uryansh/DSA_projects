#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void bblSort(int array[], int n);
void print(int arr[], int n);
//Swapping the elemtns
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//Displaying elements in array
void Display(int arr[], int n){
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    printf("Size: \n");
    int n;
    scanf("%d", &n);
    int array[n];

    printf("Enter elements for array: ");

    for (int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    Display(array, n);

    bblSort(array, n);

    Display(array, n);
}



void bblSort(int arr[], int n)//requisite function as per method
{
    for (int i = 0; i < n-1; i++)//incrementing dual arrays
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])//checking adjacent elements
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}