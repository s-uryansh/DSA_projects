#include <stdio.h>
int finder();
int main(void)
{
    
    int nums[100], n, target;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}
	scanf("%d", &target);
   
    finder(nums , 0 , n-1 , target);
   

    return 0;
}	

int finder(int* nums , int i , int n , int target){
    
    int mid;
    if(i == n){
        if(nums[i] == target){
            printf("%d", i);
        }else{
            printf("-1");
        }
    }else{
        mid = (i+n)/2;
        if(nums[mid] == target){
            printf("%d" , mid);
        }else{
            if(nums[mid] > target){
                finder(nums, i , mid-1 , target);
            }else{
                finder(nums , mid+1 , n , target);
            }
        }
    }
    return 0;
}