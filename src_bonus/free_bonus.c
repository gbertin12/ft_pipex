/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:24:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/10 11:40:50 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_free_close_bonus(t_struct *pipex, t_list_bonus *cmd)
{
	int	i;

	i = 0;
	(void)cmd;
	if (pipex->path_absolute)
	{
		while (pipex->path_absolute[i])
		{
			free(pipex->path_absolute[i]);
			i++;
		}
		free(pipex->path_absolute);
	}
	close(pipex->inputfile);
	close(pipex->outputfile);
	ft_free_list(pipex->cmd);
	free(pipex);
}

int	ft_free_struct(t_struct *pipex)
{
	if (pipex)
		free (pipex);
	return (0);
}

void	ft_free_args(t_list_bonus *cmd)
{
	int	i;

	i = 0;
	if (cmd != NULL)
	{
		while (cmd->args[i] != NULL)
		{
			if (cmd->args[i])
				free(cmd->args[i]);
			cmd->args[i] = NULL;
			i++;
		}
	}
	free(cmd->args);
}

void	ft_free_list(t_list_bonus *cmd)
{
	t_list_bonus	*temp;

	while (cmd)
	{
		if (cmd->path)
			free(cmd->path);
		cmd->path = NULL;
		ft_free_args(cmd);
		temp = cmd;
		cmd = cmd->next;
		free(temp);
		temp = NULL;
	}
}

int	free_bad_files(t_struct *pipex)
{
	int	i;

	i = 0;
	if (pipex->path_absolute)
	{
		while (pipex->path_absolute[i])
		{
			free(pipex->path_absolute[i]);
			i++;
		}
		free(pipex->path_absolute);
	}
	free(pipex);
	return (0);
}
