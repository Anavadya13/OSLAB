#include <stdio.h>

void main()
{
    int pno,bno,i,j;
    printf("Enter number of processes");
    scanf("%d",&pno);
    printf("Enter number of blocks");
    scanf("%d",&bno);
    printf("Enter sizes of Process");
    int psize[pno],bsize[bno],alloct[pno];
    for(i=0;i<pno;i++)
    {
        alloct[i]=-1;
    }
    for(i=0;i<pno;i++)
    {
        scanf("%d",&psize[i]);
    }
    
    printf("Enter sizes of Blocks");
    for(i=0;i<bno;i++)
    {
        scanf("%d",&bsize[i]);
    }
    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++)
        {
            if(bsize[j]>=psize[i]){
                        alloct[i]=j;
                        bsize[j]-=psize[i];
                        break;
                    }   }  } 
    printf("\tProcessNo\tProcessSize\tBlocknumber\n");
    for(i=0;i<pno;i++)
    {
        printf("%d\t%d\t\t",i+1,psize[i]);
        if(alloct[i]!=-1){
            printf("%d\n",alloct[i]+1);
        }
        else{
            printf("not allocated\n");
        }	 
   }}
