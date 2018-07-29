# Process ID Manager API
An API managing process_ids tested using multithreaded programming in C.
Sample output is provided in `output.txt`.

## Compile and Run steps:
1. cd into the directory where all the files are stored using the CLI.
2. run the command: make testpid
3. run the command: ./testpid
4. (optional) if you want to write the output to a specific file, run the command: ./testpid > file_name.txt

Note: all files (Makefile, pid.h, pid.c, and test.c) must be in the same directory for this to work.

## Further testing:
I defined all testing values inside "pid.h". You can test this program by changing the values of NUM_THREADS, NUM_SLEEP_SECS, etc... 
