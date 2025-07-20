#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/select.h>
#include <netinet/ip.h>

fd_set	rfds, wfds, afds;
char	read_buf[1001];
char	*msgs[65536];
int		ids[65536];
int		max_fd = 0;
int		count_ids = 0;
int		sockfd;

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

int countBytes(int n_digits)
{
	if (n_digits < 10 && n_digits >= 0)
		return (1);
	if (n_digits < 100 && n_digits > 9)
		return (2);
	if (n_digits < 1000 && n_digits > 99)
		return (3);
	if (n_digits < 10000 && n_digits > 999)
		return (4);
	if (n_digits < 100000 && n_digits > 9999)
		return (5);
	if (n_digits < 1000000 && n_digits > 99999)
		return (6);
	if (n_digits < 10000000 && n_digits > 999999)
		return (7);
	return (8);
}

void	errorMessage()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

void	notifyOthers(int fd_sender, char *message)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != fd_sender && fd != sockfd)
			send(fd, message, strlen(message), 0);
	}
}

void	registerClient(int cli_fd)
{
	ids[cli_fd] = count_ids++;
	msgs[cli_fd] = NULL;

	FD_SET(cli_fd, &afds);
	
	if (max_fd < cli_fd)
		max_fd = cli_fd;
	
	char	*tmp_msg = NULL;
	int		len = 29 + (countBytes(ids[cli_fd]));
	tmp_msg = malloc(sizeof(char) * len);

	sprintf(tmp_msg, "server: client %d just arrived\n", ids[cli_fd]);
		printf("Server accepted the client %d!\n", ids[cli_fd]);
	notifyOthers(cli_fd, tmp_msg);
	
	free(tmp_msg);
}

void	removeClient(int cli_fd)
{
	char	*tmp_msg = NULL;
	int		len = 26 + (countBytes(ids[cli_fd]));
	tmp_msg = malloc(sizeof(char) * len);

	sprintf(tmp_msg, "server: client %d just left\n", ids[cli_fd]);
		printf("Client %d left the Server.\n", ids[cli_fd]);
	notifyOthers(cli_fd, tmp_msg);
	
	free(tmp_msg);
	free(msgs[cli_fd]);
	msgs[cli_fd] = NULL;
	
	FD_CLR(cli_fd, &afds);
	close(cli_fd);
}

void	sendMessage(int fd_sender)
{
	char	*message;
	while (extract_message(&msgs[fd_sender], &message))
	{
		int		len_std = 9 + countBytes(ids[fd_sender]);
		int		len_total = len_std + strlen(message);
		char	*full_msg = malloc(sizeof(char) * len_total);
		if (!full_msg)
			errorMessage();
		
		sprintf(full_msg, "client %d: %s", ids[fd_sender], message);
			printf("%s", full_msg);
		notifyOthers(fd_sender, full_msg);

		free(message);
		free(full_msg);
	}
}

int main(int ac, char **av)
{
	struct	sockaddr_in servaddr;

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	FD_ZERO(&afds);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("Socket creation failed ...\n");
		errorMessage();
	}
	else
		printf("Socket sucessfully created ...\n");

	max_fd = sockfd;
	FD_SET(sockfd, &afds);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	//Binding newly created socket to given IP and verifivation
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
	{
		printf("Socket bind failed ...\n");
		errorMessage();
	}
	printf("Socket sucessfully binded ...\n"); 
	
	if (listen(sockfd, SOMAXCONN) != 0)
	{
		printf("Socket not listening.\n");
		errorMessage();
	}
	printf("Socket listening.\n");

	while (1)
	{
		rfds = afds;
		wfds = afds;

		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			continue;
		for(int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;

			if (fd == sockfd)
			{
				socklen_t len = sizeof(servaddr);
				int cli_fd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (cli_fd < 0)
				{
					printf("Server accept failed ...\n");
					errorMessage();
				}
				registerClient(cli_fd);
				break;
			}
			else
			{
				int bytes = recv(fd, read_buf, 1000, 0);
				if (bytes <= 0)
				{
					removeClient(fd);
					break;
				}
				read_buf[bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], read_buf);
				if (!msgs[fd])
					errorMessage();
				sendMessage(fd);
			}
		}
	}
	return (0);
}
