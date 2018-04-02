/*
 * Sleeping Teaching Assistant problem.
 * Uses multithreading and semaphores.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include "sleepingta.h"

/* global variables: */
int occupiedChairs = 0;
int taBusy = FALSE;

/*
 * Simulates the students programming
 */
void *simulate_student_programming(void *studentId) {
    //get the studentId:
    int id = *(int *)studentId;

    //set the random programming time:
    pthread_mutex_lock(&mutex); //lock this thread
    int programmingSecs = rand() % SLEEP_MAX_SECS + 1;
    pthread_mutex_unlock(&mutex); //unlock this thread
    printf("\tStudent %d is programming for %d seconds\n", id, programmingSecs);

    while(TRUE) {
        sleep(programmingSecs);
        pthread_mutex_lock(&mutex); //lock this thread
        //check if there's an available chair:
        if (occupiedChairs < NUM_CHAIRS) {
            //there is an available chair, so the student sits down:
            occupiedChairs++;
            printf("\t\tStudent %d takes a seat waiting = %d\n", id, occupiedChairs);
            //the student wakes up the TA:
            sem_post(&semaphore_student);
            pthread_mutex_unlock(&mutex); //unlock this thread

            pthread_mutex_lock(&mutex); //lock this thread
            if (taBusy == FALSE){
                printf("Student %d receiving help\n", id);
                taBusy = TRUE;
            }
            pthread_mutex_unlock(&mutex); //unlock this thread
            //wait for the student to finish getting help:
            sem_wait(&semaphore_ta);
        } else {
            //no available chairs.
            //set the random programming time:
            programmingSecs = rand() % SLEEP_MAX_SECS + 1;
            pthread_mutex_unlock(&mutex); //unlock this thread
            printf("\t\t\tStudent %d will try later\n", id);
            printf("\tStudent %d is programming for %d seconds\n", id, programmingSecs);
        }
    }
}

/*
 * Simulates the TA helping students
 */
void *simulate_ta_helping() {
    while(TRUE) {
        //the TA sleeps until a student arrives:
        sem_wait(&semaphore_student);

        pthread_mutex_lock(&mutex); //lock this thread
        //check if students are waiting to get help:
        if (occupiedChairs > 0) {
            //the student walks into the TA's office to get help:
            occupiedChairs --;
            //get the random TA helping time:
            int helpingSecs = rand() % SLEEP_MAX_SECS + 1;
            printf("Helping a student for %d seconds, waiting students = %d\n", helpingSecs, occupiedChairs);
            taBusy = TRUE;
            //TA helps student for a random amount of time:
            sleep(helpingSecs);
            pthread_mutex_unlock(&mutex); //unlock this thread
            //TA finished helping the student:
            taBusy = FALSE;
            sem_post(&semaphore_ta);
        } else {
            //no students are waiting for help
            pthread_mutex_unlock(&mutex); //unlock this thread
        }
    }
}
