//Constants:
#define PID_MIN 500
#define PID_MAX 600
#define RANGE (PID_MAX - PID_MIN + 1)
#define NUM_THREADS 100
#define MAX_SLEEP_SECS 10

//Variable declarations:
int *pidmap;

//API functions:
int allocate_map();
int allocate_pid();
void release_pid(int pid);
