#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - This reallocates a memory block using malloc and free.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: size in bytes of the allocated space for ptr.
 * @new_size: size in bytes for the new memory block.
 * Return: ptr if new_size == old_size, or new_size == 0 and ptr is not NULL -
 *  NULL, Else a pointer to reallocated memory block.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *memm;
	char *ptr_copy, *filler;
	unsigned int sign;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		memm = malloc(new_size);
		if (memm == NULL)
			return (NULL);

		return (memm);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	memm = malloc(sizeof(*ptr_copy) * new_size);
	if (memm == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = memm;

	for (sign = 0; sign < old_size && sign < new_size; sign++)
		filler[sign] = *ptr_copy++;

	free(ptr);
	return (memm);
}

/**
 * assign_lineptr -The function to reassign the lineptr variable for _getline.
 * @lineptr:The  buffer to store an input string.
 * @n: The lineptr size
 * @buffer:The  string assigned to lineptr.
 * @b: The buffer size
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline -The function to reads input from a stream.
 * @lineptr: The buffer to store the input.
 * @n:The lineptr size
 * @stream:The stream
 * Return:  returns bytes number present
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t fill;
	ssize_t ret;
	char c = 'x', *buffer;
	int j;

	if (fill == 0)
		fflush(stream);
	else
		return (-1);
	fill = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		j = read(STDIN_FILENO, &c, 1);
		if (j == -1 || (j == 0 && fill == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j == 0 && fill != 0)
		{
			fill++;
			break;
		}

		if (fill >= 120)
			buffer = _realloc(buffer, fill, fill + 1);

		buffer[fill] = c;
		fill++;
	}
	buffer[fill] = '\0';

	assign_lineptr(lineptr, n, buffer, fill);

	ret = fill;
	if (j != 0)
		fill = 0;
	return (ret);
}
