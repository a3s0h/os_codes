#include<stdio.h>
#include<stdbool.h>
#define MAX 100
struct process{
    int max[MAX] ,allocation[MAX] ,need[MAX];
};

int main()
{
    int n,r;
    printf("Enter the number of processe : ");
    scanf("%d",&n );
    printf("Enter the max instancs : ");
    scanf("%d",&r);
    int a[n];
    bool ft[n];
    for(int i=0;i<r;i++)
    {
        scanf("%d",&a[i]);
    }
    struct process p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the max needs : ");
        for(int j=0;j<r;j++)
        {
            scanf("%d",&p[i].max[j]);
        }
        printf("Enter the allocations : ");
        for(int j=0;j<r;j++)
        {
            scanf("%d",&p[i].allocation[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
            a[j] -= p[i].allocation[j];
        }
        ft[i] = true;
    }

    int np=0,sq[n],sqi=0;
    bool flag=true;
    while(np<n)
    {
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            if(ft[i] == true)
            {
                continue;
            }
            for(j=0;j<r;j++)
            {
                if(a[j]<p[i].need[j])
                {
                    break;
                }
            }
            if(j==r)
            {
                ft[i] = true;
                break;
            }
        }
        if(i==n)
        {
            flag = false;
            break;
        }
        np++;
        for(int k=0;k<r;k++)
        {
            a[k] += p[i].allocation[k];
        }
        sq[sqi++] = i+1;

    }
    for(int i =0;i<n;i++)
    {
        printf("Process %d ",i+1);
        for(int j=0;j<r;j++)
            printf(" %d ",p[i].max[j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf(" %d ",p[i].allocation[j]);
        printf("\t");
        for(int j=0;j<r;j++)
        {
            printf(" %d ",p[i].need[j]);
        }
        printf("\n");
    }
    if(flag)
    {
        printf("Safe sequence \n");
        printf("The sequence is : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",sq[i]);
        }
    }
    else{
        printf("Not a safe sequence ");
    }
    return 0;
}