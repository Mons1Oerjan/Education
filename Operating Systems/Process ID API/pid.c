#include <stdio.h>
#include <stdlib.h>
#include "pid.h"

/**
 * Creates and initializes a data structure representing pids.
 * Returns —1 if unsuccessful, 1 if successful.
 */
int allocate_map(void) {
	//initialize the pidmap and allocate space for it in memory:
	pidmap = calloc(RANGE, sizeof(int));

	if (pidmap != NULL)
		return 1;

	return -1;
}

/**
 * Allocates and returns a pid.
 * Returns -1 if unable to allocate a pid (all pids are in use).
 * Returns pid if able to allocate a pid.
 */
int allocate_pid(void) {
	int i = 0;

	//Increment i until we find an empty spot in the map:
	while (pidmap[i] != 0) {
		i++;
	}

	//Check if we are able to allocate the pid, or if we are out of bounds:
	if (i + PID_MIN > PID_MAX) {
		return -1;
	}

	//Allocate the pid:
	pidmap[i] = 1;

	//return the pid:
	return i + PID_MIN;
}

/**
 * Function that releases a pid.
 */
void release_pid(int pid) {
	if (pid < PID_MIN || pid > PID_MAX) {
		printf("Error: Invalid pid. It must be inside the interval {%i - %i}\n", PID_MIN, PID_MAX);
		return;
	}
	pidmap[pid - PID_MIN] = 0;
}
