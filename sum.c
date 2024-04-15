#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    int fd1[2];
    int fd2[2];
    int n;
    int arr[50];
    int brr[50];
    int sum=0;
    int result=0;
    int temp=0;

    if (pipe(fd1)==-1)
    {
      printf("Error");
    }
    if (pipe(fd2)==-1)
    {
      printf("Error");
    }
    pid = fork();

    if (pid == -1)
    {
        printf("Error");
    }

    if (pid > 0)
    {
        close(fd1[0]);
        close(fd2[1]);
        printf("Enter no.of numbers : ");
        scanf("%d",&n);

        printf("Enter %d numbers : ",n);
        for (int i=0; i<n ; i++)
        {
            scanf("%d",&arr[i]);
        }
        
        write(fd1[1],arr,sizeof(int)*n);
        close(fd1[1]);
        wait(NULL);

        read(fd2[0],&result,sizeof(int));
        printf("sum received from child process : %d",result);
        close(fd2[0]);


    }
    else
    {
        sleep(5);
        close(fd1[1]);
        close(fd2[0]);

        while (read(fd1[0], &temp, sizeof(int)) > 0) {
            sum += temp;
        }
        close(fd1[0]);
        

        write(fd2[1],&sum,sizeof(int));
        close(fd2[1]);


        
    }
}