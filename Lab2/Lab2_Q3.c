#include <stdio.h>
#include<stdlib.h>
int constant(const void *a , const void *b);
void sort(int* nums , int m);
int compare(int* nums , int* nums1 , int l);
int main(void)
{
    int nums[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}
	int nums1[100];
	for(int j = 0 ; j<n ; j++){
	    nums1[j] = nums[j];
	}
	qsort(nums1 , n , sizeof(int) , constant);
	int rotations;
	for(rotations =0; rotations<10*n ; rotations++){
	    if (compare(nums , nums1 , n)==1){
	        break;
	    }
	    sort(nums , n);
	}
	printf("%d\n" ,rotations);
	return 0;
	
    return 0;
}

int constant(const void *a , const void *b){
    return (*(int *)a - *(int *)b );
}
void sort(int* nums , int m){
    int temp = nums[0];
    for(int d =1 ; d<m ; d++){
        nums[d-1] = nums[d];
    }
    nums[m-1] = temp;
}

int compare(int* nums , int* nums1 , int l){
    for(int n =0 ; n<l ; n++){
        if(nums1[n] != nums[n] ){
            return 0;
        }
    }
    return 1;
}