#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* fun(void *arg)
{
    int *marks = (int*)arg;  
    int sum = 0, i;
    for(i = 0; i < 5; i++)   
    {
        sum += marks[i];
    }
    return (void*)(long)sum; 
}

int main() {
    int stu1[5] = {56, 45, 78, 34, 65};
    int stu2[5] = {100, 66, 100, 99, 60};
    int result[2];
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, fun, stu1);
    pthread_join(tid1, (void*)&result[0]);

    pthread_create(&tid2, NULL, fun, stu2);
    pthread_join(tid2, (void*)&result[1]);

    if(result[0] > result[1]) {
        printf("stu1 has highest marks\n");
    }
    else if(result[1] > result[0]) {
        printf("stu2 has highest marks\n");
    }
    else {
        printf("Both students have equal marks\n");
    }
    
    pthread_exit(NULL);
    return 0;
}