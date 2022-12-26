#include<stdio.h>

int main()
{
    int TotalHeadMove=0,ReadyQueue[100],initial,i,n;
    printf("Enter the number of requets : ");
    scanf("%d",&n);
    printf("Enter the requests in sequence: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ReadyQueue[i]);
    }
    printf("Enter initial Head: ");
    scanf("%d",&initial);
    for(int i=0; i<n; i++)
    {
        TotalHeadMove += abs(ReadyQueue[i] - initial);
        initial = ReadyQueue[i];
    }
    printf("Total number of head moves : %d",TotalHeadMove);
    return 0;
}