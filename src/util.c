#include "utils.h"

void die(const char *s) {
    write(STDERR_FILENO, "\x1b[2J",4);
    write(STDERR_FILENO, "\x1b[H",3);
    perror(s);
    exit(1);
}

int getWindowSize(int *rows, int *cols) {
    struct winsize ws;
	
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col ==0){
        //moves the cursor C, down B a lot of lines 999
		if(write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) 
			return -1;
		//since we always return -1 editorReadKey was called to give ius time before die comes and ruins the fun
		return getCursorPosition(rows,cols);
	}
	else {
		*cols = ws.ws_col;
		*rows = ws.ws_row; 
		return 0;
	}
}

int getCursorPosition(int *rows, int *cols) {
    char buf[32];
	unsigned int i = 0;
	
	if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) //n gives us status on terminal 6 for cursor pos
		return -1;
	
	while(i < sizeof(buf) - 1) {
		if(read(STDIN_FILENO, &buf[i], 1) != 1) 
            break;
		if(buf[i] == 'R') 
            break;
		i++;
	}
	buf[i] = '\0';
	if(buf[0] != '\x1b' || buf[1] != '[')
		return -1;
	
	//sscanf from stdio
	if(sscanf(&buf[2], "%d;%d", rows, cols) != 2)
		return -1;
	
	return 0;
}