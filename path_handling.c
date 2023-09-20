#include "shell.h"

/**
 *our_getenv - string copy of our environmenr
 *@valoue: Global variable
 *Return: Valoue string
 *
 */

char *our_getenv(const char *valoue)
{
	int g, e;

	g = 0;
	e = 0;

	if (!valoue)
	return (NULL);

	while (environment[g] != NULL)
	{

	while (valoue[e] != '\0' && valoue[e] == environment[g][e])
	{
	e++;
	}
	if (valoue[e] == '\0')
		return (environment[g] + e + 1);
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

list_path *add_node_end(list_path **head, char *add, int n)
{
	list_path *new = malloc(sizeof(list_t));

	if (!head || !add)
		return (NULL);

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
		list_path *tmp = *head;

		while (tmp->n)
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
list_path *linkpath(char *link)
{
	list_path *head = '\0';
	char *index;
	char *clink = strdup(link);

	index = strtok(clink, ":");
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
char *our_which(char *f_name, list_path *pointer)
{
	struct stat st;
	char *path;

	list_path *tmp = pointer;

	while (tmp)
	{
		path = our_conkatall(tmp->dir, "/", f_name);
		if (stat(path, &st) == 0)
	{
		return (path);
	}
		free(path);
		tmp = tmp->n;
	}

	return (NULL);
}

/**
 * free_list - frees linked list
 * @list: pointer to the list
 */
void free_list(list_path *list)
{
	list_path *container;

	while (list)
	{
		container = list->n;
		free(list->dir);
		free(list);
		list = container;
	}
}
