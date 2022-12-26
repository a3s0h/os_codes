#include <stdio.h>

int main()
{
    int p[10], at[10], n, bt[10], tat[10], wt[10], ct[10],start_time[10];
    printf("Enter the nunebr of processes: ");
    scanf("%d", &n);
    printf("Enter the processses: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter the arrival time : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);
    printf("Enter the burst time : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    // sorting
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (at[i] > at[j])
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
    printf("\nProcess\tArrival Time \tBurst time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", p[i], at[i], bt[i]);
    }
    ct[0] =at[0] + bt[0];
    tat[0] = ct[0]-at[0];
    wt[0] = 0;
    // start_time[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(at[i] <= ct[i-1] )
        ct[i] = ct[i-1] + bt[i];
        else{
            ct[i] = at[i] + bt[i];
        }
        tat[i] = (ct[i] -at[i] );
        wt[i] = tat[i] - bt[i];

    }

    printf("Full table\n\n");
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i],ct[i],wt[i],tat[i]);
    }
    return 0;
}
