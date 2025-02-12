
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
 
#define N 5          // Number of philosophers
#define HUNGRY 1
#define THINKING 2
#define EATING 0
#define LEFT (phnum + N - 1) % N // Left philosopher
#define RIGHT (phnum + 1) % N    // Right philosopher
 
int state[N];        // State of philosophers
int phil[N] = {0,1,2,3,4};         // Philosopher IDs
 
sem_t mutex;         // Semaphore to protect critical sections
sem_t s[N];          // Semaphore for each philosopher
 
void test(int phnum) {
   if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
       state[phnum] = EATING;
       printf("Philosopher %d takes forks %d and %d\n", phnum + 1, LEFT + 1, RIGHT + 1);
       printf("Philosopher %d is eating\n", phnum + 1);
       sleep(1); // Simulate eating
       sem_post(&s[phnum]); // Allow philosopher to proceed
   }
}
 
void take_fork(int phnum) {
   sem_wait(&mutex);        // Enter critical section
   state[phnum] = HUNGRY;
   printf("Philosopher %d is Hungry\n", phnum + 1);
   test(phnum);             // Try to acquire forks
   sem_post(&mutex);        // Exit critical section
   sem_wait(&s[phnum]);     // Wait until forks are available
}
 
void put_fork(int phnum) {
   sem_wait(&mutex);        // Enter critical section
   state[phnum] = THINKING;
   printf("Philosopher %d puts down forks %d and %d\n", phnum + 1, LEFT + 1, RIGHT + 1);
   printf("Philosopher %d is thinking\n", phnum + 1);
   test(LEFT);               // Notify left philosopher
   test(RIGHT);              // Notify right philosopher
   sem_post(&mutex);        // Exit critical section
}
 
void *philosopher(void *num) {
   int *phnum = (int *)num;
   sleep(1);             // Thinking
   take_fork(*phnum);   // Try to eat
   sleep(1);             // Eating
   put_fork(*phnum);    // Release forks
   return NULL;
}
 
int main() {
   pthread_t thread_id[N];
 
   sem_init(&mutex, 0, 1);  // Initialize mutex semaphore
   for (int i = 0; i < N; i++) {
       sem_init(&s[i], 0, 0); // Initialize semaphores for each philosopher
       phil[i] = i;          // Set philosopher IDs
       state[i] = THINKING;   // Initialize states
   }
 
   // Create philosopher threads
   for (int i = 0; i < N; i++) {
       pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
   }
 
   // Wait for all threads to finish
   for (int i = 0; i < N; i++) {
       pthread_join(thread_id[i], NULL);
   }
 
   return 0;
}
 