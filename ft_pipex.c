/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:06:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/21 12:02:26 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_get_path(t_list *pipex)
{
	int i;
	char *tmp;
	char *path;

	i = 0;
	if (pipex->path_absolute[0] == NULL)
		return (NULL);
	while (pipex->path_absolute[i] != NULL)
	{
		tmp = ft_strjoin(pipex->path_absolute[i], "/");
		path = ft_strjoin(tmp, pipex->args[0]);
		free(tmp);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void ft_exec_first(t_list *pipex, char *argv[], char *envp[])
{
	pipex->args = ft_split(argv[2], ' ');
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->inputfile, 0);
	pipex->path = ft_get_path(pipex);
	if(pipex->path != NULL)
		execve(pipex->path, pipex->args, envp);
	else
	{
		ft_free_child(pipex);
		write(1, "Error command\n", 15);
		exit(1);
	}
}

void ft_exec_second(t_list *pipex, char *argv[], char *envp[])
{
	pipex->args = ft_split(argv[3], ' ');
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->outputfile, 1);
	pipex->path = ft_get_path(pipex);
	if(pipex->path != NULL)
		execve(pipex->path, pipex->args, envp);
	else
	{
		ft_free_child(pipex);
		write(1, "Error command\n", 15);
		exit(1);
	}
}

int	main(int argc, char* argv[], char *envp[])
{
	t_list *pipex;
	
	pipex = malloc(sizeof(*pipex));
	if (!pipex)
		return (0);
	ft_memset(pipex, 0, sizeof(t_list));
	if (argc == 5)
	{
		pipex->inputfile = open(argv[1], O_RDONLY);
		if (pipex->inputfile < 0)
			return (ft_print_error("Infile Error\n"));
		pipex->outputfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (pipex->outputfile < 0)
			return (ft_print_error("Output Error\n"));
		if (pipe(pipex->pipe) < 0)
			return (ft_print_error("Pipe Error\n"));
		pipex->path_absolute = ft_fill_path_env(envp);
		pipex->pid1 = fork();
		if (pipex->pid1 < 0)
			return (0);
		if (pipex->pid1 == 0)
			ft_exec_first(pipex, argv, envp);
		pipex->pid2 = fork();
		if (pipex->pid2 == 0)
			ft_exec_second(pipex, argv, envp);
		ft_free_close(pipex);
		waitpid(pipex->pid1, NULL, 0);
		waitpid(pipex->pid2, NULL, 0);
		free(pipex);
	}
	return (0);
}