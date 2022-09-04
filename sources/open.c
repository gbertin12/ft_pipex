/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:02:04 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/03 14:34:52 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_files(char **argv, t_list *pipex)
{
	pipex->inputfile = open(argv[1], O_RDONLY);
	pipex->outputfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outputfile < 0 || pipex->inputfile < 0)
	{
		if (pipex->inputfile < 0)
		{
			perror("");
			return (error_files(pipex));
		}
		if (pipex->outputfile < 0)
		{
			perror("");
			return (error_files(pipex));
		}
	}
	return (1);
}
