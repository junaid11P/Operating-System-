#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* fun(void *arg)
{
    printf("Hello World\n");

    pthread_exit(NULL);
}

int main(int argc, char** argv){
    pthread_t t_id[3];

    int i=0;
    for(i=0;i<3;i++)
    {
        int x =pthread_create(&t_id[i],NULL,fun,NULL);
        if(x==0)
        {
            printf("Thread %d created successfully\n",(i+1));
        }
        else
        {
            printf("Thread creation failed\n");
        }
        printf("Thread ID: %ld\n",t_id[i]);
    }
    return (EXIT_SUCCESS);
}

