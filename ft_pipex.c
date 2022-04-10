/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:06:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/04/10 15:21:30 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_get_path(t_list pipex)
{
	int i;
	char *tmp;
	char *path;

	i = 0;
	if (pipex.path_absolute[0] == NULL)
		return (NULL);
	while (pipex.path_absolute[i] != NULL)
	{
		tmp = ft_strjoin(pipex.path_absolute[i], "/");
		path = ft_strjoin(tmp, pipex.args[0]);
		free(tmp);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		i++;
	}
	printf("failure");
	return (NULL);
}

void ft_exec_first(t_list pipex, char *argv[], char *envp[])
{
	pipex.args = ft_split(argv[2], ' ');
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.inputfile, 0);
	pipex.path = ft_get_path(pipex);
	if(pipex.path != NULL)
	{
		
		execve(pipex.path, pipex.args, envp);
	}
	else
	{
		//free child
		write(1, "Error command", 14);
		exit(1);
	}
}

void ft_exec_second(t_list pipex, char *argv[], char *envp[])
{
	pipex.args = ft_split(argv[3], ' ');
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outputfile, 1);
	pipex.path = ft_get_path(pipex);
	if(pipex.path != NULL)
	{
		execve(pipex.path, pipex.args, envp);
	}
	else
	{
		//free child
		write(1, "Error command", 14);
		exit(1);
	}
}

char	**ft_fill_path_env(t_list pipex, char *env[])
{
	char *path;
	char **all_path;
	int i;
	
	i = 0;
	path = "PATH";
	while (env[i])
	{
		if (ft_strncmp(path, env[i], 4) == 0)
		{
			while (*env[i] != '/' && *env[i] != '\0')
				env[i]++;
			all_path = ft_split(env[i], ':');
            	return (all_path);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char* argv[], char *envp[])
{
	t_list pipex;
	
	if (argc == 5)
	{
		pipex.inputfile = open(argv[1], O_RDONLY);
		if (pipex.inputfile < 0)
			return (0);
		pipex.outputfile = open(argv[4], O_RDWR | O_CREAT);
		if (pipe(pipex.fd) < 0)
			return (0);
		pipex.path_absolute = ft_fill_path_env(pipex, envp);


		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
		{
			printf("in first child\n");
			ft_exec_first(pipex, argv, envp);
		}
			
		
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
		{
			printf("in second child\n");
			ft_exec_second(pipex, argv, envp);
		}

		
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		// close(pipex.inputfile);
		// close(pipex.outputfile);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
	}
	else
		return(0);
}