#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int palindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i]!=str[len - i -1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    pid_t pid;
    int fd1[2];
    int fd2[2];
    char buffer1[100];
    char buffer2[100];
    char result[100];
    int n;

    if (pipe(fd1)<0)
    {
        printf("Error in pipe");
    }
     if (pipe(fd2)<0)
    {
        printf("Error in pipe");
    }
    pid = fork();
    if (pid<0)
    {
        printf("error in fork");
    }
    if (pid > 0)
    {
        close(fd1[0]);
        close(fd2[1]);

        printf("Enter no.of strings : ");
        scanf("%d",&n);
        
        printf("Enter %d strings : ",n);
        for (int i = 0; i < n; i++) 
        {
            scanf("%s", buffer1); 
            write(fd1[1], buffer1, 100);        
        }
        
         
        close(fd1[1]);

        wait(NULL);
         
        printf("palindromes received from child\n");
        while (read(fd2[0], result, 100) > 0)
        {
            printf("%s ", result); 
        }
        close(fd2[0]);
    }
    else
    {
        sleep(5);
        close(fd1[1]);
        close(fd2[0]);

        while (read(fd1[0], buffer2, 100) > 0) 
        { 
            if (palindrome(buffer2)) 
            {
                write(fd2[1], buffer2, 100); 
            }
        }
        
        close(fd2[1]);
    }
    
}
