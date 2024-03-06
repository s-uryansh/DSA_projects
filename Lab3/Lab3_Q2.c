#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node*nxtptr;
} *stnode;

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    struct node*nodeArray[n];
    for (int k=0; k<n; k++)
    {
        nodeArray[k]=(struct node*)malloc(sizeof(struct node));
        if (k!=n-1)
        {
            nodeArray[k]->nxtptr=nodeArray[k+1];
        }
        else
        {
            nodeArray[k]->nxtptr=NULL;
        }
        nodeArray[k]->num=array[k];
    }

    struct node*current=nodeArray[n-1];

    for (int j=n-1; j>0; --j)
    {
        if  (j!=0)
        {
            nodeArray[j]->nxtptr=nodeArray[j-1];
        }
        else
        {
            nodeArray[j]->nxtptr=NULL;
        }
    }

    while (current != NULL) 
    {
        printf("%d ", current->num);
        current = current->nxtptr;
    }

    for (int v=0; v<n; v++)
    {
        free(nodeArray[v]);
    }    
}