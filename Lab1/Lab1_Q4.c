#include <stdio.h> 
int max();
int steal();
// Driver function
int main() 
{ 
	int nums[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}
    int robbed;
    robbed = steal(nums , n);
    printf("%d" , robbed);
	return 0; 
}
int max(int a , int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int steal(int num[100] , int n){
    int max_steal[n];
    max_steal[0] = num[0];
    max_steal[1] = max(num[0] , num[1]);
    
    for(int i=2 ; i <n ; i++){
        max_steal[i] = max( (max_steal[i-2] + num[i]) , max_steal[i-1]);
     } 
    return max_steal[n-1];
    
}