# Network Emulator
Alternating Bit Protocol - Assignment 2 for Network Computing

## Assignment Version:
I chose the "Alternating Bit Protocol" version of this assignment.
I built on the program provided by the course webpage "prog2.c". Hence, this program is written in C. The program design and architecture was prebuilt, and all I had to do was fill out some empty functions, including `A_output(message)`, `A_input(packet)`, `A_timerinterrupt()`, `A_init()`, and `B_input(packet)`. For the Alternating Bit Protocol problem, I could leave `B_init()` and `B_timerinterrupt()` blank.

## Compiling and running the program:
- To compile, run the command `make` or `make all`
- To run the program, run the command `./rtp`
- To clean the directory, run `make clean`

When running the program, you are asked for some input. If you put the
TRACE input value as an int > 2, you will see the program's debug print
statements as well as the functionality.

I provided a sample output text file (see sampleoutput.txt).
