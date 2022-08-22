/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:52:54 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/22 12:18:59 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

int	ft_addend(t_struct *pipex, char *argv)
{
	t_list_bonus	*last_cmd;
	t_list_bonus	*new_cmd;

	new_cmd = malloc(sizeof(t_list_bonus));
	if (!new_cmd)
		return (0);
	last_cmd = ft_islast(pipex->cmd);
	ft_memset(new_cmd, 0, sizeof(t_list_bonus));
	new_cmd->pid = 0;
	new_cmd->args = ft_split(argv, ' ');
	if (!new_cmd->args)
		return (0);
	new_cmd->path = make_path(pipex, new_cmd);
	new_cmd->next = NULL;
	last_cmd->next = new_cmd;
	return (1);
}

void	wait_all_pid(t_list_bonus *cmd)
{
	while (cmd)
	{
		waitpid(-1, NULL, 0);
		cmd = cmd->next;
	}
}
