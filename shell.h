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

extern char **environ;

typedef struct our_build
{
	char *value;
	void (*cmd)(char **);
}our_build;

void int our_atoi(char *str);
int our_exxit(info_t *exit);
void our_environ(char **curr);
void our_setenv(char **new);
void our_unsetenv(char **rem);

typedef void(*BuiltInCommand)(char **info);
BuiltInCommand checkbuild(char **info);

void our_putchar(char c);
void our_puts (char *string);
int our_strlen(char *len);
char *our_strdup(const char *dup);
char *our_conkatall(char *first, char *second, char *third);

#define END_OF_FILE -2
#define EXIT -3

#endif
