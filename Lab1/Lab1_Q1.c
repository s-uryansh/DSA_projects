#include <stdio.h>
int function();
int p2 ;
int q2 ;
int main(){
    int P,Q;
    scanf("%d%d",&P,&Q);

    
    function(P , Q);
    
    printf("%d %d %d %d" , P , Q , p2 , q2);
   return 0;
}

int function(int x , int y){
    int a , b;
    p2 = x * x;
    q2 = y * y;
    return 0;
}