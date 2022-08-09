/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:06:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/09 12:59:22 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*pipex;

	if (argc == 5)
	{
		pipex = malloc(sizeof(*pipex));
		if (!pipex)
			return (0);
		ft_memset(pipex, 0, sizeof(t_list));
		if (!open_files(argv, pipex))
			return (1);
		if (!execute_cmd(pipex, argv, envp))
			return (1);
		close_prog(pipex);
	}
	return (1);
}
