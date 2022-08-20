/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:54:42 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/20 12:03:53 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	ft_isprint(int c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int	search_char(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ft_isprint(s[i]))
			return (1);
		i++;
	}
	return (0);
}