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

// void	ft_exec_first_bonus(t_struct *pipex, t_list_bonus *cmd, char *envp[])
// {
// 	printf("FIRST pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
// 	dup2(cmd->pipe[1], 1);
// 	close(cmd->pipe[0]);
// 	dup2(pipex->inputfile, 0);
// 	if (cmd->path != NULL)
// 		execve(cmd->path, cmd->args, envp);
// 	else
// 	{
// 		//free
// 		write(1, "Error command\n", 15);
// 		exit(1);
// 	}
// }

// void	ft_exec_cmd(t_list_bonus *cmd, t_list_bonus *cmd_before, char *envp[])
// {
// 	printf("NORMAL pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
// 	printf("NORMAL pid_before : %d || arg : %s\n", cmd_before->pipe[1], cmd_before->args[0]);
// 	dup2(cmd_before->pipe[0], 0);
// 	printf("FF15 : %d || arg : %s\n", cmd_before->pipe[1], cmd_before->args[0]);
// 	close(cmd_before->pipe[1]); 
// 	dup2(cmd->pipe[1], 1); //close 6
// 	if (cmd->path != NULL)
// 		execve (cmd->path, cmd->args, envp);
// 	else
// 	{
// 		//free
// 		write(1, "Error command\n", 15);
// 		exit(1);
// 	}
// }

// void	ft_exec_last_cmd(t_struct *pipex, t_list_bonus *cmd, t_list_bonus *cmd_before, char *envp[])
// {
// 	printf("LAST pid_before : %d || arg : %s\n", cmd_before->pipe[0], cmd_before->args[0]);
// 	printf("LAST pid : %d || arg : %s\n", cmd->pid, cmd->args[0]);
// 	dup2(cmd_before->pipe[0], 0);
// 	close(cmd_before->pipe[1]); // close 8
// 	dup2(pipex->outputfile, 1);
// 	if (cmd->path != NULL)
// 		execve(cmd->path, cmd->args, envp);
// 	else
// 	{
// 		//free
// 		write(1, "Error command\n", 15);
// 		exit(1);
// 	}
// }

// int	ft_exec_argss(t_struct *pipex, t_list_bonus *cmd, char *envp[])
// {
// 	t_list_bonus *cmd_before;
// 	cmd->pid = fork();
// 	if (cmd->pid < 0)
// 		return (0);
// 	if (pipe(cmd->pipe) < 0)
// 		return (0);
// 	if (cmd->pid == 0)
// 		ft_exec_first_bonus(pipex, cmd, envp);
// 	cmd_before = cmd;
// 	cmd = cmd->next;
// 	while (cmd)
// 	{
// 		if (pipe(cmd->pipe) < 0)
// 			return (0);
// 		cmd->pid = fork();
// 		if (cmd->pid < 0)
// 			return (0);
// 		if (cmd->next && cmd->pid == 0)
// 		{
// 			ft_exec_cmd(cmd, cmd_before, envp);
// 		}
// 		if (!cmd->next && cmd->pid == 0)
// 			ft_exec_last_cmd(pipex, cmd, cmd_before, envp);
// 		close(cmd_before->pipe[0]);
// 		cmd_before = cmd;
// 		printf("%d\n", cmd->pid);
// 		waitpid(cmd->pid, NULL, 0);
// 		cmd = cmd->next;

// 	}
// 	return (1);
// }

