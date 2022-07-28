/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:13 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/28 16:28:42 by gbertin          ###   ########.fr       */
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

void	ft_exec_first_bonus(t_struct *pipex, t_list_bonus *cmd, char *envp[])
{
	printf("FIRST pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
	dup2(cmd->pipe[1], 1);
	close(cmd->pipe[0]);
	dup2(pipex->inputfile, 0);
	if (cmd->path != NULL)
		execve(cmd->path, cmd->args, envp);
	else
	{
		//free
		write(1, "Error command\n", 15);
		exit(1);
	}
}

void	ft_exec_cmd(t_list_bonus *cmd, t_list_bonus *cmd_before, char *envp[])
{
	printf("NORMAL pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
	printf("NORMAL pid_before : %d || arg : %s\n", cmd_before->pipe[1], cmd_before->args[0]);
	dup2(cmd_before->pipe[0], 0);
	printf("FF15 : %d || arg : %s\n", cmd_before->pipe[1], cmd_before->args[0]);
	close(cmd_before->pipe[1]); 
	dup2(cmd->pipe[1], 1); //close 6
	if (cmd->path != NULL)
		execve (cmd->path, cmd->args, envp);
	else
	{
		//free
		write(1, "Error command\n", 15);
		exit(1);
	}
}

void	ft_exec_last_cmd(t_struct *pipex, t_list_bonus *cmd, t_list_bonus *cmd_before, char *envp[])
{
	printf("LAST pid_before : %d || arg : %s\n", cmd_before->pipe[0], cmd_before->args[0]);
	printf("LAST pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
	dup2(cmd_before->pipe[0], 0);
	close(cmd_before->pipe[1]); // close 8
	dup2(pipex->outputfile, 1);
	if (cmd->path != NULL)
		execve(cmd->path, cmd->args, envp);
	else
	{
		//free
		write(1, "Error command\n", 15);
		exit(1);
	}
}

int	ft_exec_argss(t_struct *pipex, t_list_bonus *cmd, char *envp[])
{
	t_list_bonus *cmd_before;
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (0);
	if (pipe(cmd->pipe) < 0)
		return (0);
	if (cmd->pid == 0)
		ft_exec_first_bonus(pipex, cmd, envp);
	cmd_before = cmd;
	cmd = cmd->next;
	while (cmd)
	{
		if (pipe(cmd->pipe) < 0)
			return (0);
		cmd->pid = fork();
		if (cmd->pid < 0)
			return (0);
		if (cmd->next && cmd->pid == 0)
		{
			ft_exec_cmd(cmd, cmd_before, envp);
		}
		if (!cmd->next && cmd->pid == 0)
			ft_exec_last_cmd(pipex, cmd, cmd_before, envp);
		close(cmd_before->pipe[0]);
		cmd_before = cmd;
		printf("%d\n", cmd->pid);
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;

	}
	return (1);
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
	t_list_bonus 	*temp;

	i = 0;
	while (pipex->path_absolute[i])
	{
		free(pipex->path_absolute[i]);
		i++;
	}
	free(pipex->path_absolute);
	close(pipex->inputfile);
	close(pipex->outputfile);
	while (cmd)
	{
		temp = cmd;
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		cmd = cmd->next;
		free(cmd);
	}
}

int main(int argc, char* argv[], char *envp[])
{
    t_struct        *pipex;

    if (argc < 5)
        return (0);
    pipex = malloc(sizeof(*pipex));
    if (!pipex)
        return (0);
	ft_memset(pipex, 0, sizeof(t_list_bonus));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		printf("here_doc\n");
	}
	else
	{
		if (!ft_init(pipex, argv, envp, argc))
			return (0);
		if (!ft_exec_args(pipex, pipex->cmd, envp))
			return (0);
	}
	//ft_free_close_bonus(pipex, pipex->cmd);
    return (0);
}

int	ft_browse_args(t_struct *pipex, t_list_bonus *cmd, char *envp[])
{
	if (dup2(pipex->inputfile, 0) == -1)
		return (0);
	while (cmd)
	{
		ft_exec_cmd(pipex, cmd, envp);
		cmd = cmd->next;
		if (!cmd->next)
			break;
	}
	if (dup2(pipex->outputfile, 1) == -1)
		return (0);
	if (execve(cmd->path, cmd->args, envp) == -1)
		return (0);
}

int	ft_exec_cmd(t_struct *pipex, t_list_bonus *cmd, char *envp[])
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
