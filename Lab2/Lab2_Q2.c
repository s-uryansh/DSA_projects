#include <stdio.h> 
int store();
// Driver Code 
int main() 
{ 
    int price[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &price[i]);
	}
	
	store(price , n);
	return 0; 
}	
 // for this ques firstly profit got from day i+1 & i is stored in array output
 //and total_profit is calculated with another for loop
int store(int* price , int n){
    int output[n];
    int profit =0;
    for(int i = 1; i< n ; i++){
        profit = price[i+1] - price[i];
        output[i-1] = profit;
        i++;
    }
    
    int total_profit = 0;
    int size =0;
    size = sizeof(output) / sizeof(int);
    
    for(int i =0; i <size ; i++ ){
        total_profit += output[i];
    }
    printf("%d" , total_profit);
}