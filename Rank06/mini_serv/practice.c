#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/select.h>
#include <netinet/ip.h>

fd_set rfds, wfds, afds; 
char    read_buf[1001];
char    *msgs[65536];
int     ids[65536];
int	    max_fd = 0;
int	    id_nbr = 0;
int	    sockfd;

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

void    errorMessage()
{
    write(2, "Fatal error\n", 11);
    exit(1);
}

int countBytes(int n)
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

void    notifyOthers(int fd_sender, char *message)
{
    for(int fd = 0; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &wfds) && fd != sockfd && fd != fd_sender)
            send(fd, message, strlen(message), 0);
    }
}

void    registerClient(int fd)
{
    ids[fd] = id_nbr++;
    msgs[fd] = NULL;

    if (max_fd < fd)
        max_fd = fd;

    FD_SET(fd, &afds);
    char    *tmp_msg = NULL;
    int     len = 29 + countBytes(ids[fd]);

    tmp_msg = malloc(sizeof(char) * len);

    sprintf(tmp_msg, "server: client %d just arrived\n", ids[fd]);
        printf("Server accepted the client %d!\n", ids[fd]);
    notifyOthers(fd, tmp_msg);

    free (tmp_msg);
}

void    removeClient(int fd)
{
    char    *tmp_msg = NULL;
    int     len = 26 + countBytes(ids[fd]);

    tmp_msg = malloc(sizeof(char) * len);

    sprintf(tmp_msg, "server: client %d just left\n", ids[fd]);
        printf("Client %d just left\n", ids[fd]);
    notifyOthers(fd, tmp_msg);

    free(tmp_msg);
    free(msgs[fd]);
    msgs[fd] = NULL;
    
    FD_CLR(fd, &afds);
    close(fd);
}

void    sendMessage(int fd_sender)
{
    char    *message = NULL;
    char    *full_msg = NULL;

    while (extract_message(&msgs[fd_sender], &message ))
    {
        size_t  len = 9 + countBytes(ids[fd_sender]);
        size_t  total_len = len + strlen(message);
        full_msg = malloc(sizeof(char) * total_len);
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
	int		    cli_fd;
	struct	    sockaddr_in servaddr;
    socklen_t   len;

    if(ac != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    FD_ZERO(&afds);
	//socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("Socket creation failed ...\n");
		errorMessage();
	}
	printf("Socket sucessfully created.\n");

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
	printf("Socket sucessfully binded.\n"); 
	if (listen(sockfd, SOMAXCONN) != 0)
	{
		printf("Socket not listening ...\n");
		errorMessage();
	}
    printf("Socket listening.\n");

    while (1)
    {
        rfds = afds;
        wfds = afds;

        if(select(sockfd, &rfds, &wfds, NULL, NULL) == -1)
            continue ;

        for(int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &rfds))
                continue ;

            if(fd == sockfd)
            {	
                len = sizeof(servaddr);
                cli_fd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                if (cli_fd < 0)
                {
                    printf("Server accept failed ...\n");
                    errorMessage();
                }
                registerClient(cli_fd);
                break ;
            }
            else
            {
                ssize_t bytes = recv(fd, read_buf, 1000, 0);
                if (bytes <= 0)
                {
                    removeClient(fd);
                    break ;
                }
                read_buf[bytes] = '\0';
                msgs[fd] = str_join(msgs[fd], read_buf);
                if (!msgs[fd])
                    errorMessage();
                sendMessage(fd);
            }
        }
    }
    return(0);
}
