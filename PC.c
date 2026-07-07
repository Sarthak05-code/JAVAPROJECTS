#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define  BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0 , out = 0;
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void* arg) {
    int item = 1;
    while (1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;

        printf("Producer produced item: %d at position %d\n", item, in);
        fflush(stdout);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer consumed item: %d at position: %d\n", item, out);
        fflush(stdout);
        out = (out + 1) % BUFFER_SIZE; 

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t prod , cons;
    sem_init(&empty , 0 , BUFFER_SIZE);
    sem_init(&full , 0 , 0);
    pthread_mutex_init(&mutex , NULL);

    pthread_create(&prod , NULL , producer, NULL);
    pthread_create(&cons , NULL, consumer, NULL);

    pthread_join(prod , NULL);
    pthread_join(cons , NULL);

    return 0;
}
