/*
 * Sleeping Teaching Assistant problem.
 * Uses multithreading and semaphores.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "sleepingta.h"

/*
* Main function that tests the Sleeping TA problem
*/
int main(int argc, char *argv[]) {

    //threads:
    pthread_t ta_thread;
    pthread_t *student_threads;

    //local variables:
    int i, numStudents;
    int *studentIds;

    //make sure the user provided the correct input:
    if (argc != 2) {
        printf("Usage: sleepingta <num students>\n");
        exit(-1);
    }

    //get number of students from CL arg:
    numStudents = atoi(argv[1]);

    printf("Sleeping TA Problem - Demonstration:\n");
    printf("%d students are programming today.\n\n", numStudents);

    //init student threads and allocate space for all students:
    student_threads = (pthread_t*)malloc(sizeof(pthread_t) * numStudents);

    //init student ids and allocate space for all students:
	studentIds = (int*)malloc(sizeof(int) * numStudents);

    //init semaphores:
    sem_init(&student_threads, 0, 0);
    sem_init(&ta_thread, 0, 1);

    //init random number generator:
    srand(time(NULL));

    //init semaphore mutex:
    pthread_mutex_init(&mutex, NULL);

    //create the TA thread:
    pthread_create(&ta_thread, NULL, simulate_ta_helping, NULL);

    //create the student threads:
    for (i = 0; i < numStudents; i++) {
        studentIds[i] = i+1; //start at id = 1
        pthread_create(&student_threads[i], NULL, simulate_student_programming, (void *)&studentIds[i]);
    }

    //wait for TA thread to finish:
    pthread_join(ta_thread, NULL);

    //wait for student threads to finish:
    for (i = 0; i < numStudents; i++) {
        pthread_join(student_threads[i], NULL);
    }

    //Exit program:
    return 0;
}
