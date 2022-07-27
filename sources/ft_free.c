/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:33:09 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/26 11:50:17 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_close(t_list *pipex)
{
	int i;

	i = 0;
	while (pipex->path_absolute[i])
	{
		free(pipex->path_absolute[i]);
		i++;
	}
	free(pipex->path_absolute);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->inputfile);
	close(pipex->outputfile);
}

void ft_free_child(t_list *pipex)
{
	int i;

	i = 0;
	while (pipex->args[i])
	{
		free(pipex->args[i]);
		i++;
	}
	free(pipex->args);
	free(pipex->path);
}

int	ft_print_error(char *msg_error)
{
    write(1, msg_error, ft_strlen(msg_error));
    return (0);
}