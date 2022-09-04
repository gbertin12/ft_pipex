/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:37:54 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/04 14:14:23 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*make_path(t_struct *pipex, t_list_bonus *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	if (!cmd->args[0])
		return (NULL);
	if (pipex->path_absolute == NULL || ft_search_char(cmd->args[0]))
	{
		if (access(cmd->args[0], 0) == 0)
			return (ft_strdup(cmd->args[0]));
		return (NULL);
	}
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

char	**get_path_env(char *env[])
{
	char	**all_path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			while (*env[i] != '/' && *env[i] != '\0')
				env[i]++;
			all_path = ft_split(env[i], ':');
			return (all_path);
		}
		i++;
	}
	return (NULL);
}

int	ft_search_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
