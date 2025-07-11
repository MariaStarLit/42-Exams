#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/ip.h>

int count = 0;
int max_fd = 0;
int	sockfd;
int ids[65536];
int *msgs[65536];
char buf_read[1001];
fd_set readfds, writefds, activefds;



int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int		i = 0;

	*msg = 0;
	if (*buf == 0)
		return (0);
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = '\0';
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	size_t	len;

    if (buf == 0)
		{len = 0;}
    else
		{len = strlen(buf);}
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = '\0';
	if (buf)
	{
		strcat(newbuf, buf);
    	free(buf);
	}
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int 

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}

    //socket create and verification
	FD_ZERO(&activefds);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal_error();
	max_fd = sockfd;
	FD_SET(sockfd, &activefds);

	struct  sockaddr_in servaddr; 
	bzero(&servaddr, sizeof(servaddr));

    //assign IP, Port
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

    //Binding newly created socket to given IP and verifivation
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
		fatal_error();

	if (listen(sockfd, SOMAXCONN) < 0)
		fatal_error();

 

	while (1)
	{
		readfds = activefds;
		writefds = activefds;
		if (select(max_fd + 1, &readfds, &writefds, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &readfds))
			continue;

			if (fd == sockfd)
			{
				socklen_t len = sizeof(servaddr);
				int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (client_fd < 0)
					continue;
				register_client(client_fd);
				break;
			}
			else
			{
				
			}
		}






	}
    if (connfd < 0)
    {
        printf("Server accept failed ...\n");
        exit(0);
    }
    else
       printf("Server accepted the client ...\n");
	return (0);
}