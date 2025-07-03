#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client
{
	int		id;
	char	*msg;
}t_client;

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}
	write(1, "Hi! mini server in progress.\n", strlen("Hi! mini server in progress.\n"));
	return (0);
}