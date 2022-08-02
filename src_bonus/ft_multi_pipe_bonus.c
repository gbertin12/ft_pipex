/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_pipe_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:41 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/01 08:40:07 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_browse_args(t_struct *pipex, t_list_bonus *cmd, char *envp[])
{
	int	pid;

	if (dup2(pipex->inputfile, 0) == -1)
		return (0);
	while (cmd)
	{
		ft_exec_cmd(cmd, envp);
		cmd = cmd->next;
		if (!cmd->next)
			break;
	}
	if (dup2(pipex->outputfile, 1) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		execve(cmd->path, cmd->args, envp);
	return (1);
}

int	ft_exec_cmd(t_list_bonus *cmd, char *envp[])
{
	int pip[2];
	int pid;

	if (pipe(pip) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	cmd->pid = pid;
	if (pid == 0)
	{
		close(pip[0]);
		if(dup2(pip[1], 1) == -1)
			return (0);
		close(pip[1]);
		if (execve(cmd->path, cmd->args, envp) == -1)
			return (0);
	}
	else
	{
		close(pip[1]);
		if (dup2(pip[0], 0) == -1)
			return (0);
		close(pip[0]);
	}
	return (1);
}
