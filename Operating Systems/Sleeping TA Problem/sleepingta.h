/*
 * Header file for sleepingta.c and test.c
 */

/* constants: */
#define TRUE 1
#define FALSE 0
#define NUM_CHAIRS 3
#define SLEEP_MAX_SECS 3

/* define semaphores: */
sem_t semaphore_student;
sem_t semaphore_ta;

/* mutually exclusive (for critical sections): */
pthread_mutex_t mutex;

/* prototype functions: */
void *simulate_student_programming(void *studentId);
void *simulate_ta_helping();
