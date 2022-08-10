/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:41 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/10 11:30:10 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_browse_cmd(t_struct *pipex, t_list_bonus *cmd, char *envp[])
{
	if (dup2(pipex->inputfile, 0) == -1)
		return (0);
	while (cmd)
	{
		ft_exec_cmd(cmd, pipex, envp);
		cmd = cmd->next;
	}
	return (1);
}

int	ft_exec_cmd(t_list_bonus *cmd, t_struct *pipex, char *envp[])
{
	int	pip[2];

	if (pipe(pip) == -1)
		return (0);
	if (cmd->next)
		execmid_cmd(pip, cmd, pipex, envp);
	else
		exec_last_cmd(cmd, pipex, envp, pip);
	close(pip[1]);
	return (1);
}

int	execmid_cmd(int pip[2], t_list_bonus *cmd, t_struct *pipex, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	cmd->pid = pid;
	if (pid == 0)
	{
		close(pip[0]);
		if (dup2(pip[1], 1) == -1)
			return (0);
		if (cmd->path != NULL)
			execve(cmd->path, cmd->args, envp);
		ft_free_close_bonus(pipex, cmd);
		exit (0);
	}
	else
	{
		close(pip[1]);
		if (dup2(pip[0], 0) == -1)
			return (0);
	}
	return (1);
}

int	exec_last_cmd(t_list_bonus *cmd, t_struct *pipex, char *envp[], int pip[2])
{
	int	pid;

	if (dup2(pipex->outputfile, 1) == -1)
		return (0);
	pid = fork();
	cmd->pid = pid;
	if (pid == 0)
	{
		close(pip[1]);
		if (cmd->path != NULL)
			execve(cmd->path, cmd->args, envp);
		ft_free_close_bonus(pipex, cmd);
		exit (0);
	}
	return (0);
}
