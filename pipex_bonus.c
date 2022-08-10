/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:13 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/10 11:40:20 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_struct		*pipex;
	int				status;

	if (argc < 5)
		return (0);
	pipex = malloc(sizeof(*pipex));
	if (!pipex)
		return (0);
	ft_memset(pipex, 0, sizeof(t_struct));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		heredoc(pipex, argv[2]);
	if (!ft_init(pipex, argv, envp, argc))
		return (free_all(pipex->cmd, pipex));
	if (!ft_browse_cmd(pipex, pipex->cmd, envp))
		return (free_all(pipex->cmd, pipex));
	waitpid(-1, &status, 0);
	ft_free_close_bonus(pipex, pipex->cmd);
	return (0);
}
