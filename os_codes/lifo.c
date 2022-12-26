#include<stdio.h>
int main()
{
    int pagefault = 0,refstring[100],n,pages,frames,s;
    printf("Enter the number of pages : ");
    scanf("%d",&pages);
    printf("Enter the pages : ");
    for(int i=0;i<pages;i++)
        scanf("%d",&refstring[i]);
    printf("Enter the frames : ");
    scanf("%d",&frames);
    int temp[frames];
    for(int i=0;i<frames;i++)
        temp[i] = -1;
    
    for(int i=0;i<pages;i++)
    {
        s=0;
        for(int j=0;j<frames;j++)
        {
            if(refstring[i] == temp[j])
            {
                s++;
                pagefault--;
            }
        }
        pagefault++;
        if((pagefault<=frames) && (s==0))
        {
            temp[i] = refstring[i];
        }
        else if(s==0)
        {
            temp[(pagefault-1)%frames] = refstring[i];

        }
        printf("\n");
        for(int i=0; i<frames; i++)
        {
            printf("%d ",temp[i]);
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pagefault);
    return 0;
    
}