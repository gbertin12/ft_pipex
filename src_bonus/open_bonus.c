/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:40:26 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/04 14:21:50 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	open_files(t_struct *pipex, int argc, char *argv[])
{
	if ((ft_strncmp(argv[1], "here_doc", 9) == 0))
	{
		pipex->inputfile = open(".heredoc", O_RDONLY);
		if (pipex->inputfile < 0)
			perror("");
		pipex->outputfile = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pipex->outputfile < 0)
			perror("");
		if (unlink(".heredoc"))
			return (0);
		return (1);
	}
	pipex->inputfile = open(argv[1], O_RDONLY);
	if (pipex->inputfile < 0)
		perror("");
	pipex->outputfile = open(argv[argc - 1],
			O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->outputfile < 0)
	{
		perror("");
	}
	return (1);
}
