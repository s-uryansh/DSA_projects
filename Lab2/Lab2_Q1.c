#include <stdio.h>
int check();
// Driver code
int main()
{
    int nums[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}     
     check(nums , n);
    
}

int check(int* nums , int n){
    int miss =0;
    for(int a = 0; a<n ; a++){
        while( nums[a] != a+1 && nums[a] != nums[nums[a] - 1]){
            int temp = nums[a];
            nums[a] = nums[temp -1];
            nums[temp-1] = temp;
        }
    }
    //while loop is used to do sorting of array in correct position 
    //from { 1 ,3 , 4 ,5 , 5 ,5} to {1 , 4 ,3 ,5, 5 ,5} 5s are replaced it just looks same
    for(int i=0 ; i < n ; i++){
        if(nums[i] != i+1){
            miss = i +1;
            printf("%d " , miss);
        }else{
            continue;
        }
    }
    //for loops goes through whole array and find missing number example in { 1 ,3 ,4 ,5  5,5} 2 and 6 are missing .
    // so these missing number are stored in new variable miss and printed for ques to be completed
}