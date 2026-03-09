#include<stdlib.h>
#include<stdio.h>
int main() {
    int n, i, j, pos;
    printf("Enter the number of process:");
    scanf("%d",&n);
    int bt[n], wt[n], tat[n], p[n];

    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter burst time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j] < bt[pos])
                pos=j;
        }

        int temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);

    return 0;
}
