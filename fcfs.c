#include <stdio.h>

void main() {
    int n, i, temp, j;
    printf("Enter Number of Processes");
    scanf("%d", &n);
    int at[n], bt[n], tt[n], wt[n], id[n];
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d\n", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d\n", i + 1);
        scanf("%d", &bt[i]);
        id[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                temp = id[j + 1];
                id[j + 1] = id[j];
                id[j] = temp;     }    }  }
    int time1 = 0, completed = 0;
    while (completed < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time1) {
                time1 += bt[i];
                tt[i] = time1 - at[i];
                wt[i] = tt[i] - bt[i];
                flag = 1;
                completed++;  } else {
                time1++;    }  }
               if (!flag) {
               time1++;   }	}
printf("Process No\tArrival time\tBurst Time\tWaiting time\tTurnAroundtime\n");
    	for (i = 0; i < n; i++) {
        	printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], at[i], bt[i], wt[i], tt[i]);
   	 }
   	float ttsum = 0, wtsum = 0;
   for (i = 0; i < n; i++) {
        ttsum += tt[i];
        wtsum += wt[i];
    }
    printf("average turn around time=%f\n", ttsum / n);
    printf("average waiting time=%f\n", wtsum / n);
}
