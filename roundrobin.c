#include <stdio.h>
void main(){
    int n,i,temp,j,t;
    printf("Enter Number of Processes");
    scanf("%d",&n);
    int at[n],bt[n],tt[n],wt[n],id[n],remaining[n];
    for(i=0;i<n;i++){
        printf("Enter Arrival Time of Process %d \n",i+1);
        scanf("%d",&at[i]);
        printf("Enter Burst Time of Process %d \n",i+1);
        scanf("%d",&bt[i]);
        id[i]=i+1;    }
    printf("Enter Time slice");
    scanf("%d",&t);
    int time1=0,complete=0;
     for(i=0;i<n;i++){
         remaining[i]=bt[i];     }  
    while(complete<n){
        int flag=0;
        for(i=0;i<n;i++){
            if(at[i]<=time1 && remaining[i]!=0){
            flag=1;
            if(remaining[i]<=t){
            time1+=remaining[i];
            tt[i]=time1-at[i];
            wt[i]=tt[i]-bt[i];
            remaining[i]=0;
            complete++;         }
            else{
                remaining[i]-=t;
                time1+=t;
            }            }          }
        
        if(!flag){
            time1++;
        }    }
    printf("Process No\tArrival time\tBurst Time\tWaiting time\tTurnAroundtime\n");
    for(i=0;i<n;i++){
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",id[i],at[i],bt[i],wt[i],tt[i]);
    }
    float ttsum=0,wtsum=0;
    for(i=0;i<n;i++){
        ttsum+=tt[i];
        wtsum+=wt[i];    }
    printf("average turn around time=%f\n",ttsum/n);
    printf("average waiting time=%f\n",wtsum/n);	}
