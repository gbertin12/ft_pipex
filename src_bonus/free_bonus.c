/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:24:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/26 14:31:45 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_free_struct(t_struct *pipex, t_list_bonus *cmd)
{
    if (pipex)
        free (pipex);
    if (cmd)
        free (cmd);
    return (0);
}