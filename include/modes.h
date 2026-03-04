/*
* Header file for the functions used in the manipulation
* of the terminal mode...
*/
#include <termios.h>

void initEditor();
void enableRawMode();
void disableRawMode();

struct editorConfig {
    struct termios orig_termios;
    int screenrows;
    int screencols;
    int cursorX;
    int cursorY;
};

struct append_buffer {
    char *b;
    int length;
};