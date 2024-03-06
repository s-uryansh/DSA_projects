#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

int main()
{
    int n;
    scanf("%d", &n);
    int *array=(int*)malloc(n*sizeof(int));
    for (int a=0; a<n; a++)
    {
        scanf("%d", &array[a]);
    }
    struct node*nodeArray[n];
    for (int b=0; b<n; b++)
    {
        nodeArray[b]=(struct node*)malloc(sizeof(struct node));
        if (b!=n-1)
        {
            nodeArray[b]->next=nodeArray[b+1];
        }
        else
        {
            nodeArray[b]->next=NULL;
        }
        nodeArray[b]->data=array[b];
    }
    int flag=0;
    for (int k=0; k<n/2; k++)
    {
        if (n%2!=0)
        {
            if (k==(n+1)/2)
            {
                break;
            }
        }
        if (nodeArray[k]->data==nodeArray[n-1-k]->data)
        {
            ;
        }
        else
        {
            flag=1;
            break;
        }    
    }
    if (flag==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}