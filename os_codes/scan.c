#include<stdio.h>

int main()
{
    int rq[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&rq[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);

    // logic of SCAN

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(rq[j] > rq[j+1])
            {
                int temp=rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = rq[j];
            }
        }
    }
    int index;
    for(int i=0;i<n;i++)
    {
        if(initial < rq[i])
        {
            index = i;
            break;
        }
    }

    // if high move
    if(move == 1)
    {
        for(int i=index;i<n;i++)
        {
            TotalHeadMoment += abs(rq[i]-initial);
            initial = rq[i];

        }
        TotalHeadMoment += abs(size-rq[i-1]-1);
        initial = size-1;
        for(int i=index-1;i>=0;i--)
        {
            TotalHeadMoment += abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    // if low move
    else
    {
        for(int i=index-1;i>=0;i--)
        {
            TotalHeadMoment += abs(rq[i]-initial);
            initial = rq[i];

        }
        TotalHeadMoment += abs(rq[i+1]-0);
        initial = 0;
        for(int i=index;i<n;i++)
        {
            TotalHeadMoment += abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}