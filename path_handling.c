#include "shell.h"

/**
 *our_getenv - string copy of our environmenr
 *@valoue: Global variable
 *Return: Valoue string
 *
 */

char *our_getenv(const char *valoue)
{
	if (!valoue)
	return (NULL);

	int g = 0;

	while (environ[g] != NULL)
	{

	int e = 0;

	while (valoue[e] != '\0' && name[e] == environ[g][e])
	{
	e++;
	}
	if (valoue[e] == '\0')
		return (environ[g] + e + 1);
	g++;
	}
	return (NULL);
}

/**
 * add_node_end - Adds new node at the end of a linked list
 * @head: pointer address
 * @add: new node
 * @n: index
 * Return: No. of Nodes
 */

list_t *add_node_end(list_t **head, const char *add, int n)
{
	if (!head || !add)
		return (NULL);

	list_t *new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->dir = strdup(add);

	if (!new->dir)
	{
		free(new);
		return (NULL);
	}

	new->n = NULL;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		list_t *tmp = *head;

		while (tmp->)
		{
			tmp = tmp->n;
		}

		tmp->n = new;
	}

	return (*head);
}

/**
 * linkpath - link for path directories
 * @link: path line
 * Return: List pointer
 */
list_t *linkpath(char *link)
{
	list_t *head = '\0';
	char *index;
	char *clink = strdup(link);

	index = strto(clink, ":");
	while (index)
	{
		head = add_node_end(&head, index);
		index = strtok(NULL, ":");
	}

	return (head);

}

/**
 * our_which - Function that finds filename path
 * @f_name: File name
 * @pointer: pointer to the head of linked list
 * Return: F. name | NULL
 */
char *our_which(char *f_name, list_t *pointer)
{
	struct stat st;
	char *path;

	list_path *tmp = pointer;

	while (tmp)
	{
		path = concat_all(tmp->dir, "/", f_name);
		if (stat(path, &st) == 0)
	{
		return (path);
	}
		free(path);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list - frees linked list
 * @list: pointer to the list
 */
void free_list(list_t *list)
{
	list_path *container;

	while (list)
	{
		container = list->p;
		free(list->dir);
		free(list);
		list = container;
	}
}
