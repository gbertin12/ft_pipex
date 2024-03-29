/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:07:03 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/01 10:01:55 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	execute_cmd(t_list *pipex, char **argv, char **envp)
{
	pipex->path_absolute = get_path_env(envp);
	if (pipe(pipex->pipe) < 0)
		return (error(pipex));
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (error(pipex));
	if (pipex->pid1 == 0)
		ft_exec_first(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		return (error(pipex));
	if (pipex->pid2 == 0)
		ft_exec_second(pipex, argv, envp);
	return (1);
}

void	ft_exec_first(t_list *pipex, char *argv[], char *envp[])
{
	if (argv[2] && search_char(argv[2]))
		pipex->args = ft_split(argv[2], ' ');
	else 
		pipex->args = NULL;
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->inputfile, 0);
	pipex->path = ft_get_path(pipex);
	if (pipex->path != NULL && pipex->args != NULL)
		execve(pipex->path, pipex->args, envp);
	else
	{
		perror("");
		free_child(pipex);
		exit(errno);
	}
}

void	ft_exec_second(t_list *pipex, char *argv[], char *envp[])
{
	if (argv[3] && search_char(argv[3]))
		pipex->args = ft_split(argv[3], ' ');
	else 
		pipex->args = NULL;
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->outputfile, 1);
	pipex->path = ft_get_path(pipex);
	if (pipex->path != NULL && pipex->args != NULL)
		execve(pipex->path, pipex->args, envp);
	else
	{
		perror("");
		free_child(pipex);
		exit(errno);
	}
}
