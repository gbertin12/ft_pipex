/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:56:18 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/09 12:54:49 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_files(t_list *pipex)
{
	free(pipex);
	return (0);
}

int	error(t_list *pipex)
{
	free_child(pipex);
	return (0);
}
