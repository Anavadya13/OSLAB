#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,x=0;
void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n Producer produces " "item %d",x);
    ++mutex;
}
void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consumes " " item %d",x);
    x--;
    ++mutex;
}
void main(){
    int n,i=1;
    printf("\nPress 1 for Producer \nPress 2 for Consumer \nPress 3 for Exit");
    while(i>0){
        printf("\nEnter your choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:if((mutex==1) &&(empty!=0)){
                producer();
            }
            else{
                printf("Buffer is full");
            }
            break;
            case 2:if((mutex==1) && (full!=0)){
                consumer();
            }
            else{
                printf("Buffer is empty");
            }
            break;
            case 3:exit(0);
            break;
        }
        i++;
    }	} 
 
