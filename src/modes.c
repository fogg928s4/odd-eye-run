/*** includes ***/
#include "modes.h"
#include "utils.h"

void initViewer() {
    V.cursorX = 0;
    V.cursorY = 0;
    if(getWindowSize(&V.screenrows, &V.screencols) == -1)
        die("getWindowSize");   
}

/* sets the attribute for the terminal to the original form */
void disableRawMode() {
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &V.orig_termios) == -1)
		die("tcsetattr");
}

void enableRawMode() {
	/* 
	*  gets the current termios state and saves it in orig
    */
	if(tcgetattr(STDIN_FILENO, &V.orig_termios) == -1)
		die("tcgetattr");
	
	atexit(disableRawMode);
    
	struct termios raw = V.orig_termios;

	//flags that determine what is outpute or input
	//&= for and, |= for not

	//input flag
	raw.c_iflag &= ~(ICRNL | IXON | BRKINT | INPCK | ISTRIP);
	
	//output flags
	raw.c_oflag &= ~(OPOST);
	
	//local or misc flags
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw.c_lflag |= (CS8); // sets the char size to 8 bytes

	/* From this point read will wait for input indef
	*  these come from termios and aare ctrl chars that control settings
	*  VTIME is the max time to wait before read() retrns whatever it read 
    *  and is in tenth of secs
    */ 
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = MAX_VTIME;

	// sets the attributes established in raw
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		die("tcsetattr");
}