#include <stdio.h>

int main()
{
    int n=4;
    int at[4], bt[4], pr[4], rt[4], wt[4], tat[4];
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

        rt[i]=bt[i];
    }

    while(completed!=n)
    {
        min=9999;
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && pr[i]<min)
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

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            completed++;

            tat[highest]=time-at[highest];
            wt[highest]=tat[highest]-bt[highest];
        }
    }

    printf("\nProcess AT BT PR WT TAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d %d %d %d %d %d\n",i+1,at[i],bt[i],pr[i],wt[i],tat[i]);
    }

    return 0;
}