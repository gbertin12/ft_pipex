/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:45:30 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/04 14:16:49 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_init(t_struct *pipex, char *argv[], char *envp[], int argc)
{
	pipex->path_absolute = get_path_env(envp);
	if (!open_files(pipex, argc, argv))
		return (0);
	if (!ft_fill_list(pipex, argv))
	{
		return (0);
	}
	return (1);
}

int	ft_fill_list(t_struct *pipex, char *argv[])
{
	int	i;

	if (!(ft_strncmp(argv[1], "here_doc", 9) == 0))
		i = 3;
	else
		i = 4;
	if (!ft_init_list(pipex, argv[i - 1]))
		return (0);
	while (argv[i] && argv[i + 1])
	{
		if (!ft_addend(pipex, argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_list(t_struct *pipex, char *argv)
{
	t_list_bonus	*init;

	init = malloc(sizeof(t_list_bonus));
	if (!init)
		return (0);
	ft_memset(init, 0, sizeof(t_list_bonus));
	init->pid = 0;
	init->args = ft_split(argv, ' ');
	if (!init->args)
		return (0);
	init->path = make_path(pipex, init);
	if (!init->path)
		write(2, "Invalid Argument\n", 18);
	init->next = NULL;
	pipex->cmd = init;
	return (1);
}
