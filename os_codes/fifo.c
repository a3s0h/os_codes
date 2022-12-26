#include<stdio.h>

int main()
{
    int n; // no of page 
    int frame ;// frame 
     


    printf("Enter th numeber of pages : ");
    scanf("%d",&n);
    printf("Enter the number of frames : ");
    scanf("%d",&frame);
    int p[n]; // ref string
    printf("Enter the ref string : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    int len=0;
    int completed = 0;
    int pf= 0 , ph=0;
    while(completed)
    {
        if(len<frame)
        {
            
        }
    }
    return 0;
}