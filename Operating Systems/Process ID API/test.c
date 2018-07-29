#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "pid.h"

pthread_mutex_t mutex; //mutually exclusive: can never be owned by 2 threads at the same time.

/**
 * Function that tests allocate_pid and release_pid using multithreading.
 */
void *allocator(void *parameter) {
    //get a random sleep time from 0-9 seconds:
    int sleepTime = rand() % MAX_SLEEP_SECS;

    int pid = -1;
    while(pid == -1) {
        pthread_mutex_lock(&mutex);
        pid = allocate_pid();
        if (pid == -1) {
            printf("Error: Can't allocate pid (out of bounds).\n");
        }
        pthread_mutex_unlock(&mutex);
    }

    printf("pid %i is active. Sleeps for %i seconds\n", pid, sleepTime);
    sleep(sleepTime);

    printf("pid %i has finished sleeping. Releasing this pid...\n", pid);
    release_pid(pid);

    return NULL;
}


/**
 * Main function that tests the pid manager API.
 */
int main(void) {
    int i;
    pthread_t thread_ids[NUM_THREADS];
    srand(time(NULL)); //seed random function generator

    pthread_mutex_init(&mutex, NULL);

    //initialize the data structure and detect a possible error:
    if (allocate_map() == -1) {
        printf("Error: Could not initialize the pidmap. Terminating program...\n");
        return -1;
    }

    //Create new threads:
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_ids[i], NULL, allocator, NULL);
    }

    //wait for thread termination:
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    //Free space in memory:
    if (pidmap != NULL) {
        free(pidmap);
    }

    printf("Testing finished. Terminating program...\n");
    return 0;
}
