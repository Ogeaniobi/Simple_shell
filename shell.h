#ifndef _SHELL_H_
#define _SHELL_H_

#ifndef MY_LIST_H
#define MY_LIST_H

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

typedef struct list_node 
{
	char *data;
	struct list_node *next;
} list_t;

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

int our_atoi(char *str);
void our_exxit(char **exxit);
void our_environ(char **curr __attribute__ ((unused)));
void our_unsetenv(char *set);
void our_setenv(char *new, char *set);

void(*checkbuild(char **info))(char **info);

void our_putchar(char c);
void our_puts (char *string);
int our_strlen(char *len);
char *our_strdup(const char *dup);
char *our_conkatall(char *first, char *second, char *third);

char *our_getenv(const char *valoue);
list_t *add_node_end(list_t **head, const char *add, int n);
list_t *linkpath(char *link);
char *our_which(char *f_name, list_t *pointer);
void free_list(list_t *list);

#define END_OF_FILE -2
#define EXIT -3

#endif 
#endif
