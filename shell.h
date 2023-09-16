#ifndef _SHELL_H_
#define _SHELL_H_

#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>

void our_print(const char *my_shell);
void show_promptme(void);
void get_input(char *input, size_t len);
void exec_mycommand(const char *execute);

#define END_OF_FILE -2
#define EXIT -3

#endif
