#include<stdio.h>
int main()
{
    int p[10],at[10],bt[10],tat[10],wt[0],ct[0],n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Arrival time : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        p[i] = i+1;
    }

    printf("Enter the burst time : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    //sorting 
    for(int i =0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                int temp = p[j];
                p[j] = p[i];
                p[i] = temp;

                temp = at[j];
                at[j] = at[i];
                at[i] = temp;

                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
            }
            if(at[i] == at[j])
            {
                if(bt[i] > bt[j])
                {
                    int temp = p[j];
                p[j] = p[i];
                p[i] = temp;

                temp = at[j];
                at[j] = at[i];
                at[i] = temp;

                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                }
            }
        }
    }
    
    return 0;

}