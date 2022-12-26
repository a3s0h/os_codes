#include <stdio.h>
struct process
{
    int WT, AT, BT, TAT, PT, ST, RT;
};
struct process arr[10];
int main()
{
    int n, tempbt[10], t, count = 0, short_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d", &n);
    printf("Enter the AT , BT and priority of the process\n");
    printf("AT BT PT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &arr[i].AT, &arr[i].BT, &arr[i].PT);
        tempbt[i] = arr[i].BT;
    }
    arr[9].PT = 10000;
    for (t = 0; count != n; t++)
    {
        short_p = 9;
        for (int i = 0; i < n; i++)
        {
            if (arr[short_p].PT > arr[i].PT && arr[i].AT <= t && tempbt[i] > 0)
            {
                short_p = i;
            }
        }
        if (arr[short_p].BT == tempbt[short_p])
            arr[short_p].ST = t;
        tempbt[short_p]--;
        if (tempbt[short_p] == 0)
        {
            count++;
            arr[short_p].WT = t + 1 - arr[short_p].AT - arr[short_p].BT;
            arr[short_p].TAT = t + 1 - arr[short_p].AT;
            arr[short_p].RT = arr[short_p].ST - arr[short_p].AT;
            total_WT = total_WT + arr[short_p].WT;
            total_TAT = total_TAT + arr[short_p].TAT;
        }
    }
    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;
    printf("\nID AT BT WT TAT RT\n");
    for (int i = 0; i < n; i++)
    {
 printf("%d %d %d %d %d %d\n",i+1,arr[i].AT,arr[i].BT,arr[i].WT,arr[i].TAT,arr[i].RT);
    }
    printf("Avg waiting time of the process is %f\n", Avg_WT);
    printf("Avg turn around time of the process is %f\n", Avg_TAT);
    return 0;
}
