#include <stdio.h>

int main() {
    int n=4, at[4], bt[4], rt[4], wt[4], tat[4];
    int i, time=0, completed=0, shortest;
    int min;

    for(i=0;i<n;i++){
        printf("Enter arrival time of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    while(completed!=n){
        min=9999;
        shortest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && rt[i]<min)
            {
                min=rt[i];
                shortest=i;
            }
        }

        if(shortest==-1){
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest]==0){
            completed++;
            tat[shortest]=time-at[shortest];
            wt[shortest]=tat[shortest]-bt[shortest];
        }
    }
printf("\nProcess AT BT WT TAT\n");
float total_wt=0, total_tat=0;
for(i=0;i<n;i++){
    total_wt+=wt[i];
    total_tat+=tat[i];
        printf("P%d %d %d %d %d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);
    return 0;
}