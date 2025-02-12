#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    char buf[]=" ";
    int fd1 = open("CSE.text",O_RDONLY);
    int fd2 = open("ISE.text",O_WRONLY);

    if(fd1 == -1){
        printf("Error opening first file\n");
        return 1;
    }
    if(fd2 == -1){
        printf("Error opening second file\n");
        return 1;
    }

    while(read(fd1, buf, 1)){
        write(fd2,buf,1);
    }
    printf("copied successfully\n");

    close(fd1);
    close(fd2);
    return 0;

}