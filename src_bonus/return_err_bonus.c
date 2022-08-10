/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_err_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:07:42 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/10 11:43:48 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	free_all(t_list_bonus *cmd, t_struct *pipex)
{
	ft_free_close_bonus(pipex, cmd);
	return (0);
}
