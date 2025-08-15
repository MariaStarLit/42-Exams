#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/select.h>
#include <netinet/ip.h>

fd_set	rfds, wfds, afds;
char    readbuf[1001];
char    *msgs[65536];
int     ids[65536];
int     maxfd = 0;
int     nbr = 0;
int     sockfd;

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
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = '\0';
	if (buf != 0)
    {
        strcat(newbuf, buf);
	    free(buf);
    }
	strcat(newbuf, add);
	return (newbuf);
}

void	errorMessage()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int countBytes (int n)
{
	if (n < 10 && n >= 0)
		return (1);
	if (n < 100 && n > 9)
		return (2);
	if (n < 1000 && n > 99)
		return (3);
	if (n < 10000 && n > 999)
		return (4);
	if (n < 100000 && n > 9999)
		return (5);
	if (n < 1000000 && n > 99999)
		return (6);
	if (n < 10000000 && n > 999999)
		return (7);
	return (8);
}

void notifyOthers(int senderfd, char *message)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if(FD_ISSET(fd, &wfds) && fd != senderfd && fd != sockfd)
			send(fd, message, strlen(message), 0);
	}
}

void reciveClient(int fd)
{
	ids[fd] = nbr++;
	msgs[fd] = NULL;

	if (maxfd < fd)
		maxfd = fd;

	FD_SET(fd, &afds);

	char *tmp = NULL;
	size_t len = 29 + countBytes(ids[fd]) + 1;
	tmp = malloc(sizeof(char) * len);

	sprintf(tmp,"server: client %d just arrived\n", ids[fd]);
		printf("* client %d arrived *\n", ids[fd]);
	notifyOthers(fd, tmp);
	free(tmp);
}

void removeClient(int fd)
{
	char *tmp = NULL;
	size_t len = 26 + countBytes(ids[fd]) + 1;
	tmp = malloc(sizeof(char) * len);

	sprintf(tmp,"server: client %d just left\n", ids[fd]);
		printf("* client %d left *\n", ids[fd]);
	notifyOthers(fd, tmp);

	free(tmp);
	free(msgs[fd]);
	msgs[fd] = NULL;

	FD_CLR(fd, &afds);
	close(fd);
}

void sendMessage(int fd)
{
	char *tmp_msg = NULL;
	char *full_msg = NULL;

	while (extract_message(&msgs[fd], &tmp_msg))
	{
		size_t len = 9 + countBytes(ids[fd]);
		full_msg = malloc(sizeof(char) * (len + strlen(tmp_msg) + 1));
		if (!full_msg)
			errorMessage();
		sprintf(full_msg,"client %d: %s", ids[fd], tmp_msg);
			printf("* %s", full_msg);
		notifyOthers(fd, full_msg);

		free(tmp_msg);
		free(full_msg);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	FD_ZERO(&afds);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("Socket creation failed :(\n");
		errorMessage();
	}
	printf("Socket sucessfully created ...\n"); 
	
	maxfd = sockfd;
	FD_SET(sockfd, &afds);

	struct	sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
	{
		printf("Socket bind failed :(\n");
		errorMessage();
	}
	printf("Socket sucessfully binded ...\n");

	if (listen(sockfd, SOMAXCONN) != 0)
	{
		printf("Socket not listening :(\n");
		errorMessage();
	}
	printf("Socket listening ...\n");

	while(1)
	{
		rfds = afds; 
		wfds = afds;

		if(select(maxfd + 1, &rfds, &wfds, NULL, NULL) == -1)
			continue;
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if(!FD_ISSET(fd, &rfds))
				continue;
			if(fd == sockfd)
			{	
				socklen_t len = sizeof(servaddr);
				int clifd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (clifd < 0)
				{
					printf("Server accept failed :(\n");
					errorMessage();
				}
				reciveClient(clifd);
				break ;
			}
			else
			{
				ssize_t bytes = recv(fd, readbuf, 1000, 0);
				if (bytes <= 0)
				{
					removeClient(fd);
					break ;
				}
				readbuf[bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], readbuf);
				if (!msgs[fd])
					errorMessage();
				sendMessage(fd);
			}
		}
	}
	return (0);
}