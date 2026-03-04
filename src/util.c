#include "utils.h"
#include "mainHead.h"

void die(const char *s) {
    write(STDERR_FILENO, "\x1b[2J",4);
    write(STDERR_FILENO, "\x1b[H",3);
    perror(s);
    exit(1);
}