#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct process{
    int pid;
    int at;
    int wt;
    int bt;
    int tat;
};
int main()
{
    struct process p[20];
    struct process temp;
    int total_waiting_time=0;
    int total_tat_time=0;
    int avg_wt=0;
    int avg_tat=0;
    int n;

    printf("\nEnter no .of processes : ");
    scanf("%d",&n);

    for (int i=0; i<n ; i++)
    {
        printf("Enter pid , arrival time , burst time ");
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
    }

    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n-i-1 ; j++)
        {
            if (p[j].bt<=p[j+1].bt)
            {
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
            }
        }
    }
    
    printf("\nPID\tArrival time\tBusrt Time\tWaiting time\tTurn around time");
    for (int i=0; i<n ; i++)
    {
        if (i==0)
        {
            
        }
        printf("\n%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat)
    }
    



}
