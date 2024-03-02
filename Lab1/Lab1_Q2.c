#include <stdio.h>

int main(){
    int N;
    int M;
    scanf("%d",&N);
    int max;
    for(M =0 ; (M*M) < N ; M++){
        max = M;
    }
    printf("%d" , max);
    return 0;
}

