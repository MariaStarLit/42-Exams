#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void error_message(char *msg, char *plus)
{
	int i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
	if (plus != NULL)
	{
		i = 0;
		while (plus[i])
		{
			write (2, &plus[i], 1);
			i++;
		}
	}
	write (2, "\n", 1);
}

int ft_cd(char *path, int i)
{
	if (i != 2)
	{
		error_message("error: cd: bad arguments", NULL);
		return (1);
	}
	else if (chdir(path) == -1)
	{
		error_message("error: cd: cannot change directory to ", path);
		return (1);
	}
	return (0);
}

int ft_execute(char **av, char **envp, int i)
{
	int fd[2];
	int exit;
	int haspipe = av[i] && !strcmp(av[i], "|");

	if (haspipe && pipe(fd) == -1)
	{
		error_message("error: fatal", NULL);
		return (1);
	}
	int pid = fork();
	if(!pid)
	{
		av[i] = 0;
		if(haspipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		{
			error_message("error: fatal", NULL);
			return (1);
		}
		execve(*av, av, envp);
		error_message("error: cannot execute ", *av);
		return (1);
	}
	waitpid(pid, &exit, 0);
	if(haspipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		error_message("error: fatal", NULL);
		return (1);
	}
	return WIFEXITED(exit) && WEXITSTATUS(exit);
}

int main(int ac, char **av, char **envp)
{
    int exit = 0;
    int i = 0;

    if (ac > 1)
    {
        while (av[i] && av[++i])
        {
            av += i;
            i = 0;
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            if (!strcmp(*av, "cd"))
                exit = ft_cd(av[i - 1], i);
            else if (i)
                exit = ft_execute(av, envp, i);
        }
    }
    return (exit);
}