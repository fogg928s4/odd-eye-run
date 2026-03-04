/*
* Header file for the functions used in the manipulation
* of the terminal mode...
*/
#include "mainHead.h"

#ifndef MAX_VTIME
#define MAX_VTIME 1
#endif

void initEditor();
void enableRawMode();
void disableRawMode();

struct viewerConfig {
    struct termios orig_termios;
    int screenrows;
    int screencols;
    int cursorX;
    int cursorY;
};

struct viewerConfig V;

struct append_buffer {
    char *b;
    int length;
};