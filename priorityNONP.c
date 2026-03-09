#include <stdio.h>

int main()
{
    int n=4;
    int at[4], bt[4], pr[4], wt[4], tat[4], ct[4], done[4]={0};
    int i, time=0, completed=0, highest;
    int min;

    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Enter Priority of P%d: ",i+1);
        scanf("%d",&pr[i]);
    }

    while(completed!=n)
    {
        min=9999;
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0 && pr[i]<min)
            {
                min=pr[i];
                highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
            continue;
        }

        time+=bt[highest];
        ct[highest]=time;

        tat[highest]=ct[highest]-at[highest];
        wt[highest]=tat[highest]-bt[highest];

        done[highest]=1;
        completed++;
    }

    printf("\nProcess AT BT PR WT TAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d %d %d %d %d %d\n",i+1,at[i],bt[i],pr[i],wt[i],tat[i]);
    }

    return 0;
}