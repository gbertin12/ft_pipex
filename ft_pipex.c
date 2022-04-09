/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:06:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/04/09 21:44:08 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void ft_exec_first(t_list pipex, *argv[], char *envp[])
{
	pipex.args = ft_split(argv[2], ' ');
	dup2(pipex.inputfile, STDOUT_FILENO);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	if(ft_check_exist(pipex))
	{
		execve("grep", "grep", envp);
		return (1);
	}
	return (0);
}

int ft_exec_second(t_list pipex, char *argv[])
{
	pipex.args = ft_split(argv[3], ' ');
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	if(ft_check_exist(pipex))
	{
		execve("grep", "grep", envp);
		return (1);
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	t_list pipex;
	
	if (argc == 5)
	{
		pipex.inputfile = open(argv[1], O_RDONLY);
		if (pipex.inputfile < 0)
			return ("Error inputfile");
		pipex.outputfile = open(argv[4], O_RDWR, O_CREAT)
		if (pipe(pipex.fd) == -1)
			return (1);
		ft_fill_path_env(pipex, env);
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		if (pipex.pid1 == 0)
		{
			ft_exec_first(pipex, argv);
		}
		pipex.pid2 = fork();
		if (pipex.pid2 < 0)
			return (3);
		if (pipex.pid2 == 0)
		{
			ft_exec_second(pipex, argv);
		}
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
	}
	else
		return("Error argument");
}