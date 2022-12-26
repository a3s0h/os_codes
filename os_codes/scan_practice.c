#include<stdio.h>

int main()
{
    int TotalHeadMove=0,rq[100],initial,i,j,n,size,move;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the seq: ");
    for(int i=0;i<n;i++)
        scanf("%d",&rq[i]);
    printf("Enter the initial head : ");
    scanf("%d",&initial);
    printf("Enter the size of disk: ");
    scanf("%d",&size);
    printf("Enter the move : ");
    scanf("%d",&move);

    for(int i = 0; i < n; i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(rq[j] > rq[j+1])
            {
                int temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }

    int index;
    for(int i = 0; i <n;i++)
    {
        if(index < rq[i])
        {
            index = i;
            break;
        }
    }

    // for high move 
    if(move ==1 )
    {
        for(int  i=index ; i<n;i++)
        {
            TotalHeadMove += abs(rq[i] - initial);
            initial = rq[i];
        }
        TotalHeadMove += abs(size - rq[i-1]-1);
        initial=size-1;
        for(int i=index-1;i>=0;i--)
        {
            TotalHeadMove += abs(rq[i] - initial);
            initial=rq[i];
        }
    }
    else
    {
        for(int  i=index-1 ; i>=0;i--)
        {
            TotalHeadMove += abs(rq[i] - initial);
            initial = rq[i];
        }
        TotalHeadMove += abs(rq[i+1]-0);
        initial=0;
        for(int i=index;i<n;i++)
        {
            TotalHeadMove += abs(rq[i] - initial);
            initial=rq[i];
        }
    }
    printf("TotalHeadMove : %d ",TotalHeadMove);
    return 0;
}