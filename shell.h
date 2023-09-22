#ifndef _SHELL_H_
#define _SHELL_H_

#ifndef MY_LIST_H
#define MY_LIST_H

#ifndef PATH_HANDLING_H
#define PATH_HANDLING_H

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
/**
 * struct list_node - List of Nodes
 * @data: parameter
 * @next: Next pointer
 */
typedef struct list_node
{
	char *readfd;
	struct list_node *next;
} list_t;

void execute(char **command);

char **splitstring(char *split, const char *delim);
void *_realloc(void *prv, unsigned int prev_size, unsigned int curr_size);
void freearray(char **array);


extern char **environ;

/**
 * struct ourbuild - Buildin cmd
 * @value: command
 * @cmd: Building execution
 */
typedef struct ourbuild
{
	char *value;
	void (*cmd)(char **);
} ourbuild;

void (*checkbuild(char **info))(char **info);

int _atoi(char *str);
void _exxit(char **exxit);
void _env(char **curr __attribute__ ((unused)));
void _unsetenv(char **rmv);
void _setenv(char **set);

/**
 * struct list_path - Utilities list
 * @dir: Path Directory
 * @n: Represents pointer
 */

typedef struct list_path
{
	char *dir;
	struct list_path *n;
} list_path;

int interact(list_t *arv);
int our_delimiter(char n, char *delimiter);
 int _isalpha(int arv);
void _putchar(char c);
void _puts(char *string);
int _strlen(char *len);
char *_strdup(const char *dup);
char *_concat_all(char *first, char *second, char *third);

char *_getenv(const char *valoue);
list_path *add_node_end(list_path **head, char *add);
list_path *linkpath(char *link);
char *_which(char *f_name, list_path *pointer);
void free_list(list_path *list);

#define END_OF_FILE -2
#define EXIT -3

#endif
#endif
#endif
