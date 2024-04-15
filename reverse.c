#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc , char *argv[])
{
    char c;
    char *b = (char*)calloc(100,sizeof(char));
    int size;
    int fd = open(argv[1],O_RDONLY);
    int dest = open(argv[2],O_RDWR | O_CREAT);
    printf("fd = %d\n", fd);

    if (fd == -1) {
        printf("Error opening file ");
    }
    
    off_t filesize = lseek(fd,0 , SEEK_END);
    for (off_t i = filesize - 1 ; i>=0; i--)
    {
        lseek(fd,i,SEEK_SET);
        read(fd,&c,1);
        write(dest,&c,1);
    }
    //close(dest); // Close the destination file

    // Reopen the destination file for reading
    //dest = open(argv[2], O_RDONLY);
    //if (dest == -1) {
        //printf("Error opening destination file ");
        //return 1; // Exit with error
    //}
    lseek(dest,0,SEEK_SET);
    // Read from the destination file into buffer 'b'
    size = read(dest, b, 100);
    
    if (size == -1) {
    perror("Error reading from file");
    return 1;
}
    // Null-terminate the string
    b[size] = '\0';
    
    printf("Written words are as follows: %s\n", b);
    return 0;


}
