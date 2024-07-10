#include <stdio.h>
void main() {
    int n, i, temp, j;
    printf("Enter Number of Processes");
    scanf("%d", &n);
    int at[n], bt[n], tt[n], wt[n], id[n], completed[n],p[n];
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d\n", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d\n", i + 1);
        scanf("%d", &bt[i]);
        id[i] = i + 1;
        printf("Enter Priority of Process %d\n", i + 1);
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j] > p[j + 1]) {
             temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                temp = id[j + 1];
                id[j + 1] = id[j];
                id[j] = temp;
                temp = p[j + 1];
p[j + 1] = p[j];
                p[j] = temp;
            }   }    }
    int time1 = 0, complete = 0;
    for (i = 0; i < n; i++) {
        completed[i] = bt[i];    }
    while (complete < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time1 && completed[i] != -1) {
                time1 += bt[i];
                tt[i] = time1 - at[i];
                wt[i] = tt[i] - bt[i];
                flag = 1;
                completed[i] = -1;
                complete++;
                break;        }        }
        if (!flag) {
            time1++;
        }    }
    printf("Process No\tPriority\tArrival time\tBurst Time\tWaiting time\tTurnAroundtime\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], p[i],at[i],bt[i],wt[i],tt[i]);
    }
    float ttsum = 0, wtsum = 0;
    for (i = 0; i < n; i++) {
        ttsum += tt[i];
        wtsum += wt[i];
    }
    printf("average turn around time=%f\n", ttsum / n);
    printf("average waiting time=%f\n", wtsum / n);
}
