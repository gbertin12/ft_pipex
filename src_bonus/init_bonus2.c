/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:04:52 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/28 09:15:47 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_open_files(t_struct *pipex, int argc, char *argv[])
{
	pipex->inputfile = open(argv[1], O_RDONLY);
	if (pipex->inputfile < 0)
		return (0);
	pipex->outputfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (pipex->outputfile < 0)
			return (0);
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
