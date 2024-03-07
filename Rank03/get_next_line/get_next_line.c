/*
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
*/

#include "get_next_line.h"

size_t	strlen_gnl(char const *str)
{
	size_t	i = 0;

	if (!str)
		return (i);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*strjoin_gnl(char const *line, char const *buffer)
{
	char	*new_line;
	int		i = 0;
	int		j = 0;
	size_t	len_l = strlen_gnl(line);
	size_t	len_b = strlen_gnl(buffer);

	if (!buffer)
		return (NULL);
	new_line = malloc(sizeof(char *) * (len_b + len_l + 1));
	if (!new_line)
		return (NULL);
	while (i < (int)len_l)
	{
		new_line[i] = line[i]; 
		i++;
	}
	while (j < (int)len_b)
	{
		new_line[i] = buffer[j];
		i++; 
		j++;
	}
	new_line[i] = '\0';
	free((void *)line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char		*line = NULL;
	int			flag = 0;
	size_t		i = 0;
	size_t		j;

	while ((read(fd, 0, 0) < 0) || BUFFER_SIZE < 1)
	{
		while (buf[i])
		{
			buf[i] = 0;
			i++;
		}
		return (NULL);
	}
	while (!flag && (buf[0] || read(fd, buf, BUFFER_SIZE)))
	{
		i = 0;
		j = 0;
		line = strjoin_gnl(line, buf);
		while (buf[i])
		{
			if (flag)
			{
				buf[j] = buf[i];
				j++;
			}
			if (buf[i] == '\n')
				flag = 1;
			buf[i] = 0;
			i++;
		}
	}
	return (line);
}

/*
int	main(void)
{
	int		fd1;
	char	*line;

	fd1 = open("text1.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("line 1: %s", line);
	free(line);
		line = get_next_line(fd1);
	printf("line 2: %s", line);
	free(line);
		line = get_next_line(fd1);
	printf("line 3: %s", line);
	free(line);
		line = get_next_line(fd1);
	printf("line 4: %s", line);
	free(line);
		line = get_next_line(fd1);
	printf("line 5: %s", line);
	free(line);
}
*/