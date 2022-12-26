#include <stdio.h>

int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int frame, pages, temp[10], refstring[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of temp: ");
    scanf("%d", &frame);
    printf("Enter number of refstring: ");
    scanf("%d", &pages);
    printf("Enter reference string: ");

    for (i = 0; i < pages; ++i)
    {
        scanf("%d", &refstring[i]);
    }
    for (i = 0; i < frame; ++i)
    {
        temp[i] = -1;
    }

    for (i = 0; i < pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < frame; ++j)
        {
            if (temp[j] == refstring[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < frame; ++j)
            {
                if (temp[j] == -1)
                {
                    counter++;
                    faults++;
                    temp[j] = refstring[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            pos = findLRU(time, frame);
            counter++;
            faults++;
            temp[pos] = refstring[i];
            time[pos] = counter;
        }

        printf("\n");

        for (j = 0; j < frame; ++j)
        {
            printf("%d\t", temp[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}