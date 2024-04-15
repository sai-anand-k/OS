#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc , char *argv[])
{
    char *c = (char*)calloc(100,sizeof(char));
    int size;
    int fd = open(argv[1],O_RDONLY);
    int dest = open(argv[2],O_WRONLY | O_CREAT);
    printf("fd = %d\n", fd);

    if (fd == -1) {
        printf("Error opening file ");
    }

    size = read(fd,c,100);
    c[size]='\0';

    printf("\nread words are :%s",c);
    write(dest,c,strlen(c));
    return 0;


}