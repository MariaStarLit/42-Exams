#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>

typedef struct s_client
{
	int		id;
	char	*msg;
}t_client;

int count = 0;
int max_fd = 0;
int id[65536];
char *msg[65536];

int maxfd = 0, sockfd = 0, next_id = 0;
char    buf_read[1001];

void fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

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