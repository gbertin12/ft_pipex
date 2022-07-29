/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:13 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/29 11:07:37 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void    ft_print_args(t_list_bonus *cmd, t_struct *pipex)
{
    //int i = 0;
    while (cmd)
	{
		// i = 0;
		// while (cmd->args[i] != 0)
        // {
        //      printf("%s\n", cmd->args[i]);
        //      i++;
        //  }
		printf("%s\n", cmd->path);
		cmd = cmd->next;
	}
	printf("inputfile : %d || outfile : %d\n", pipex->inputfile, pipex->outputfile);
}

void	ft_wait_pid(t_list_bonus *cmd)
{
	while (cmd)
	{
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
}

void	ft_free_close_bonus(t_struct *pipex, t_list_bonus *cmd)
{
	int 			i;

	i = 0;
	while (pipex->path_absolute[i])
	{
		free(pipex->path_absolute[i]);
		i++;
	}
	free(pipex->path_absolute);
	close(pipex->inputfile);
	close(pipex->outputfile);
	ft_free_list(cmd);
	free(pipex);
}

void ft_free_list(t_list_bonus *cmd)
{
	t_list_bonus 	*temp;

	while (cmd)
	{
		free(cmd->path);
		ft_free_args(cmd);
		free(cmd->args);

		temp = cmd;
		cmd = cmd->next;
		free(temp);
	}
}

void ft_free_args(t_list_bonus *cmd)
{
	int 			i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
}

int main(int argc, char* argv[], char *envp[])
{
    t_struct        *pipex;

    if (argc < 5)
	{
		  return (0);
	}
	pipex = malloc(sizeof(*pipex));
    if (!pipex)
	{
		return (0);
	}
	ft_memset(pipex, 0, sizeof(t_struct));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		printf("here_doc\n");
	}
	else
	{
		if (!ft_init(pipex, argv, envp, argc))
			return (0);
		if (!ft_browse_args(pipex, pipex->cmd, envp))
			return (0);
	}
	ft_free_close_bonus(pipex, pipex->cmd);
    return (0);
}

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
	waitpid(pid, NULL, 0);
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
		waitpid(pid, NULL, 0);
	}
	return (1);
}
