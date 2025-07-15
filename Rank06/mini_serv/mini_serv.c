#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <sys/select.h>

int		count = 0, max_fd = 0;
int		ids[65536];
char	*msgs[65536];

fd_set	rfds, wfds, afds;
char	buf_read[1001];
int sockfd;

//                   &msgs[fd]
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int		i = 0;

	*msg = 0;
	if (!*buf)
		return (0);
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, strlen(*buf + i + 1) + 1);
			if (!newbuf)
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
	int		len = buf ? strlen(buf) : 0;

	newbuf = malloc(len + strlen(add) + 1);
	if (!newbuf)
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

void notify_other(int sender_fd, char *msg)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != sender_fd && fd != sockfd)
			send(fd, msg, strlen(msg), 0);
	}
}

int countBytes(int i)
{
	if(i < 10 && i >= 0)
		return 1;
	if(i < 100 && i >= 9)
		return 2;
	if(i < 1000 && i >= 99)
		return 3;
	if(i < 10000 && i >= 999)
		return 4;
	if(i < 100000 && i >= 9999)
		return 4;
	if(i < 1000000 && i >= 99999)
		return 5;
	if(i < 10000000 && i >= 999999)
		return 6;
	return 7;
} //the return is the nbr digits of nbr of clients

void register_client(int fd)
{
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	if (fd > max_fd)
		max_fd = fd;

	int len = 29 + (countBytes(ids[fd]));
	char *wbuf = NULL;
	wbuf = malloc(len * sizeof(char));

	sprintf(wbuf, "server: client %d just arrived\n", ids[fd]);
		printf("Server accepted the client %d!\n",fd);
	notify_other(fd, wbuf);
	free(wbuf);
}

void remove_client(int fd)
{
	int len = 26 + countBytes(ids[fd]);
	char *wbuf = NULL;
	wbuf =  malloc(len * sizeof(char));
	sprintf(wbuf, "server: client %d just left\n", ids[fd]);
		printf("Client %d left the Server.\n", fd);
	notify_other(fd, wbuf);
	free(wbuf);
	free(msgs[fd]);
	msgs[fd] = NULL;
	FD_CLR(fd, &afds);
	close(fd);
}

void send_msg(int fd)
{
	char *msg;
	while (extract_message(&msgs[fd], &msg))
	{
		int len_prefix = 9 + countBytes(ids[fd]);
		int len_total = len_prefix + strlen(msg) + 1;
		char *full_msg = malloc(len_total);
		if (!full_msg)
			fatal_error();
		sprintf(full_msg, "client %d: %s", ids[fd], msg);
			printf("Client %d send_msg: <%s>\n", fd, full_msg);
		notify_other(fd, full_msg);
		free(msg);
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
	if (sockfd < 0)
	{
		printf("Socket creation failed!\n");
		fatal_error();
	}
	printf("Socket sucessfully created!\n"); 

	max_fd = sockfd;
	FD_SET(sockfd, &afds);

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("Socket bind failed!\n");
		fatal_error();
	}
	printf("Socket sucessfully binded!\n"); 

	if (listen(sockfd, SOMAXCONN) < 0)
	{
		printf("Socket not listening!\n");
		fatal_error();
	}
	printf("Socket listening!\n");

	while (1)
	{
		rfds = afds;
		wfds = afds;
		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;

			if (fd == sockfd)
			{
				socklen_t len = sizeof(servaddr);
				int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (client_fd < 0)
				{
					printf("Server accept failed!\n");
					continue;
				}
				register_client(client_fd);
				break;
			}
			else
			{
				int bytes = recv(fd, buf_read, 1000, 0);
				if (bytes <= 0)
				{
					remove_client(fd);
					break;
				}
				buf_read[bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				if (!msgs[fd])
					fatal_error();
				send_msg(fd);
			}
		}
	}
	return (0);
}