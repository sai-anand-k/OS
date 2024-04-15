#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

#define BUFFER_SIZE 100
int main()
{
    int fd[2];
    pid_t pid;
    int arr[50];
    int brr[50];
    int n;

    if (pipe(fd)==-1)
    {
        printf("pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Error occured ");
        return 1;
    }

    if (pid > 0)
    {


        printf("Enter size : ");
        scanf("%d",&n);
                         
        printf("Enter all elements : ");
        for (int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        close(fd[0]);
        
        int i=0;
        for (i=0;i<n;i++)
        {
           write(fd[1],arr,BUFFER_SIZE);
        }
        close(fd[1]);
        
    }
    else
    {
       sleep(5);
       
       close(fd[1]);
       int i=0;

       while (read(fd[0], brr, BUFFER_SIZE) > 0)
              {            
               printf("\n %d", brr[i]);  
               i=i+1;
              }
        printf("\n");
    }

    return 0;
}