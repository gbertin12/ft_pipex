#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include "includes/pipex.h"

// char **ft_fill_path_env(t_list pipex, char *env[])
// {
// 	char *path;
// 	char **all_path;
// 	int i;
	
// 	i = 0;
// 	path = "PATH";
// 	while (env[i])
// 	{
// 		if (ft_strncmp(path, env[i], 4) == 0)
// 		{
// 			while (*env[i] != '/' && *env[i] != '\0')
// 				env[i]++;
// 			all_path = ft_split(env[i], ':');
//             	return (all_path);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

int main()
{
	int pid;
	int fd[2];

	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		dup2(1, 1);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return (0);
}


