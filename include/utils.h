/*
* Header file for the util functions used in different 
* purposes
*/

#include "mainHead.h"

/* Preprocessors */
#ifndef ABUF_INIT
#define ABUF_INIT {NULL, 0}
#endif

#define CTRL_KEY(K) ((k) & 0x1f)

/* Structs */
/* Append Buffer*/
struct appBuff {
    char *b;
    int length;
};


void die(const char *s);
void appendBufferFree(struct appBuff *ab);

int readKeypress();
void processKeypress();
int getCursorPosition(int *rows, int *cols);

int getWindowSize(int *rows, int *cols);
void initViewer();
void drawRows(struct appBuff *ab);