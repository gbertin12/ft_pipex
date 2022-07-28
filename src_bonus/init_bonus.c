/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:45:30 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/28 09:15:10 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_init(t_struct *pipex, char *argv[], char *envp[], int argc)
{
	pipex->path_absolute = ft_fill_path_env(envp);
	if (!ft_open_files(pipex, argc, argv))
		return (0);
    if (!ft_fill_list(pipex, argv))
	{
        return (0);
	}
	return (1);
}

int ft_fill_list(t_struct *pipex, char *argv[])
{
    int i;
	
    i = 3;
    if (!ft_init_list(pipex, argv[2]))
        return (0);
    while (argv[i] && argv[i + 1])
    {
		//check problem
		//check licks
		if (!ft_addend(pipex, argv[i]))
		{
			//printf("here2\n");
			return (0);
		}
		i++;
    }
    return (1);
}

int ft_init_list(t_struct *pipex, char *argv)
{
	t_list_bonus *init;

	init = malloc(sizeof(t_list_bonus));
	if (!init)
		return (0);
    ft_memset(init, 0, sizeof(t_list_bonus));
    init->pid = 0;
    init->args = ft_split(argv, ' ');
	init->path = ft_get_path_bonus(pipex, init);
    init->next = NULL;
	pipex->cmd = init;
	return (1);
}

int	ft_addend(t_struct *pipex, char *argv)
{
	t_list_bonus *last_cmd;
	t_list_bonus *new_cmd;

	new_cmd = malloc(sizeof(t_list_bonus));
	if (!new_cmd)
		return (0);
	last_cmd = ft_islast(pipex->cmd);
	ft_memset(new_cmd, 0, sizeof(t_list_bonus));
    new_cmd->pid = 0;
    new_cmd->args = ft_split(argv, ' ');
	new_cmd->path = ft_get_path_bonus(pipex, new_cmd);
    new_cmd->next = NULL;
	last_cmd->next = new_cmd;
	return (1);
}


char *ft_get_path_bonus(t_struct *pipex, t_list_bonus *cmd)
{
	int i;
	char *tmp;
	char *path;

	i = 0;
	if (pipex->path_absolute[0] == NULL)
		return (NULL);
	while (pipex->path_absolute[i] != NULL)
	{
		tmp = ft_strjoin(pipex->path_absolute[i], "/");
		path = ft_strjoin(tmp, cmd->args[0]);
		free(tmp);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		i++;
	}
	printf("not found : %s\n", cmd->args[0]);
	return (NULL);
}
