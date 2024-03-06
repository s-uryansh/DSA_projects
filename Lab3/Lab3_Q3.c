#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

struct Node
{
    int data;
    struct Node*next;
};

int main()
{
    int n1, n2;

    scanf("%d", &n1);

    int *array1=(int*)malloc(n1*sizeof(int));

    
    if (n1!=0)
    {
        for (int i=0; i<n1; i++)
        {
            scanf("%d", &array1[i]);
        }
    }

    scanf("%d", &n2);

    int *array2=(int*)malloc(n2*sizeof(int));

    for (int j=0; j<n2; j++)
    {
        scanf("%d", &array2[j]);
    }

    struct Node*NodeArray1[n1];
    struct Node*NodeArray2[n2];
    
    if (n1!=0)
    {
        for (int k=0; k<n1; ++k)//creating first ll
            {
            NodeArray1[k]=(struct Node*)malloc(sizeof(struct Node));
            NodeArray1[k]->data=array1[k];
            NodeArray1[k]->next=NULL;
            if (k>0)
                {
                NodeArray1[k-1]->next=NodeArray1[k];
                }
            }
    }
    else
    {
        NodeArray1[0]=(struct Node*)malloc(sizeof(struct Node));
        NodeArray1[0]->data=0;
        NodeArray1[0]->next=NULL;
    }

    for (int l=0; l<n2; ++l)
    {
        NodeArray2[l]=(struct Node*)malloc(sizeof(struct Node));
        NodeArray2[l]->data=array2[l];
        NodeArray2[l]->next=NULL;
        if (l>0)
        {
            NodeArray2[l-1]->next=NodeArray2[l];
        }        
    }

    if (n1!=0)
    {
        NodeArray1[n1-1]->next=NodeArray2[0];
    }
    else
    {
        NodeArray1[0]->next=NodeArray2[0];
    }
    struct Node*current=NodeArray1[0];

    int *sort=(int*)malloc((n1+n2)*sizeof(int));
    int z=0;

    while (current!=NULL)
    {
        if (n1==0&&current->data==NodeArray1[0]->data)
        {
            current=current->next;
            continue;
        }
        sort[z++]=current->data;
        current=current->next;
    }

    qsort(sort, n1+n2, sizeof(int), compare);

    struct Node*current1=NodeArray1[0];
    int x=0;

    while (current1!=NULL)
    {
        if (n1==0&&current1->data==NodeArray1[0]->data)
        {
            current1=current1->next;
            continue;
        }
        current1->data=sort[x++];
        current1=current1->next;
    }

    struct Node*current2=NodeArray1[0];

    while (current2!=NULL)
    {
        if (n1==0&&current2->data==NodeArray1[0]->data)
        {
            current2=current2->next;
            continue;
        }
        printf("%d ", current2->data);
        current2=current2->next;
    }

    free(array1);
    free(array2);
    for (int u=0; u<n1; u++)
    {
        free(NodeArray1[u]);
    }
    for (int v=0; v<n2; v++)
    {
        free(NodeArray2[v]);
    }
}

int compare(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}