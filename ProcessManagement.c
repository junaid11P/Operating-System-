#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int num1=20,num2=60;
    pid_t p1,p2,p3,p4;
    p1=fork();
    if(p1==0){
        printf("child id %d and parent id %d\n",getpid(),getppid());
        printf("Add-->%d\n",num1+num2);
        exit(0);
    }
    else{
        wait(NULL);
        p2=fork();
        if(p2==0){
        printf("child id %d and parent id %d\n",getpid(),getppid());
        printf("sub-->%d\n",num2-num1);
        exit(0);
        }
        else{
            wait(NULL);
            p3=fork();
        if(p3==0){
            printf("child id %d and parent id %d\n",getpid(),getppid());
            printf("mul-->%d\n",num1*num2);
            exit(0);
        }else{
            wait(NULL);
            p4=fork();
        if(p4==0){
            printf("child id %d and parent id %d\n",getpid(),getppid());
            printf("division-->%d\n",num2/num1);
            exit(0);
        }else{
            wait(NULL);
        }
        }
        }
    }
    return 0;
}