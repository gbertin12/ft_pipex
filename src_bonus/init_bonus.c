/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:45:30 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/27 15:40:23 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_init(t_struct *pipex, t_list_bonus *cmd, char *argv[], char *envp[])
{
	pipex->path_absolute = ft_fill_path_env(envp);
    if (!ft_fill_list(pipex, cmd, argv))
	{
        return (0);
	}
	return (1);
}

int ft_fill_list(t_struct *pipex, t_list_bonus *cmd, char *argv[])
{
    int i;

    i = 2;
    if (!ft_init_list(pipex, cmd, argv[3]))
        return (0);
    while (argv[i] && argv[i + 2])
    {
		//check problem
		//check licks
		if (ft_addend(pipex, cmd, argv[i]))
			return (0);
		i++;
    }
    return (1);
}

t_list_bonus	*ft_islast(t_list_bonus *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_addend(t_struct *pipex, t_list_bonus *cmd, char *argv)
{
	t_list_bonus *last_cmd;
	t_list_bonus *new_cmd;

	new_cmd = malloc(sizeof(t_list_bonus));
	if (!new_cmd)
		return (0);
	last_cmd = ft_islast(cmd);
	ft_memset(cmd, 0, sizeof(t_list_bonus));
    new_cmd->pid = 0;
    new_cmd->args = ft_split(argv, ' ');
	new_cmd->path = ft_get_path_bonus(pipex, cmd);
    new_cmd->next = NULL;
	last_cmd->next = new_cmd;
	return (1);
}

int ft_init_list(t_struct *pipex, t_list_bonus *cmd, char *argv)
{
    ft_memset(cmd, 0, sizeof(t_list_bonus));
    cmd->pid = 0;
    cmd->args = ft_split(argv, ' ');
	cmd->path = ft_get_path_bonus(pipex, cmd);
    cmd->next = NULL;
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
	return (NULL);
}
