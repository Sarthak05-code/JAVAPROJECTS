#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];

void think(int id) {
    printf("Philosopher %d is thinking...\n", id);
    fflush(stdout);
    sleep(1);
}

void eat(int id) {
    printf("Philosopher %d is eating...\n", id);
    fflush(stdout);
    sleep(1);
}

void pick_up_forks(int id) {
    int left  = id;
    int right = (id + 1) % N;

    
    if (id == N - 1) {
        pthread_mutex_lock(&forks[right]);
        pthread_mutex_lock(&forks[left]);
    } else {
        pthread_mutex_lock(&forks[left]);
        pthread_mutex_lock(&forks[right]);
    }

    printf("Philosopher %d picked up forks %d and %d\n", id, left, right);
    fflush(stdout);
}

void put_down_forks(int id) {
    int left  = id;
    int right = (id + 1) % N;

    pthread_mutex_unlock(&forks[left]);
    pthread_mutex_unlock(&forks[right]);

    printf("Philosopher %d put down forks %d and %d\n", id, left, right);
    fflush(stdout);
}

void *philosopher(void *arg) {
    int id = *(int *)arg;

    while (1) {
        think(id);
        pick_up_forks(id);
        eat(id);
        put_down_forks(id);
    }

    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    return 0;
}