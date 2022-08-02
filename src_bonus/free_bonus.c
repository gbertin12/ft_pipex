/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:24:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/01 14:04:18 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_free_struct(t_struct *pipex)
{
    if (pipex)
        free (pipex);
    return (0);
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

void	ft_free_close_bonus(t_struct *pipex, t_list_bonus *cmd, char **argv)
{
	int 			i;

	i = 0;
	while (pipex->path_absolute[i])
	{
		free(pipex->path_absolute[i]);
		i++;
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		unlink(".heredoc");
	free(pipex->path_absolute);
	close(pipex->inputfile);
	close(pipex->outputfile);
	ft_free_list(cmd);
	free(pipex);
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

void	ft_waitpid(t_list_bonus *cmd)
{
	while (cmd)
	{
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
}
