// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.

(START)
	//check for key pressed
	@KBD
	D=M
	@KEY_PRESSED
	D;JNE
	@NO_KEY_PRESSED
	0;JMP
	
(KEY_PRESSED)
	@0
	D=A-1	// @ command only stores 15 bits (MSB is 0)
		// have to produce the 16bit 0xFFFF differently
	@filler
	M=D	// filler = 65535 = 0xFFFF

(SCREEN_FILL_LOOP_START)
	@8192	// # of words for the screen I/O map (32*256)
	D=A
	@remainingWords
	M=D	// remainingWords = 8192
	@SCREEN
	D=A
	@position
	M=D	// position = SCREEN

(SCREEN_FILL_LOOP)
	// begin loop condition
	@remainingWords
	D=M
	@START
	D;JLE	// if remainingWords <= 0 goto START
	// end loop condition
	
	// begin loop body

	// begin  set current screen word
	@filler
	D=M
	@position
	A=M
	M=D
	// end set current screen word
	
	// begin decrease remainingWords and increase position
	@remainingWords
	M=M-1
	@position
	M=M+1
	// end decrease remainingWords and increase position
	
	// end loop body
	
	@SCREEN_FILL_LOOP
	0;JMP	// jump to begin loop

(NO_KEY_PRESSED)
	@0
	D=A
	@filler
	M=D	// filler = 0 = 0x0000
	@SCREEN_FILL_LOOP_START
	0;JMP	// jump to (SCREEN_FILL_LOOP) 
