/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:33:09 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/09 12:57:39 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_close(t_list *pipex)
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
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->inputfile);
	close(pipex->outputfile);
}

void	free_child(t_list *pipex)
{
	int	i;

	i = 0;
	while (pipex->args[i])
	{
		free(pipex->args[i]);
		i++;
	}
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
	free(pipex->args);
	free(pipex->path);
	free(pipex);
}

void	close_prog(t_list *pipex)
{
	ft_free_close(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
}
