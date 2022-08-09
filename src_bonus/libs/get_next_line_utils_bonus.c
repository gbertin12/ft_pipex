/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:49:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/09 15:11:46 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/pipex_bonus.h"

int	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat_gnl(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (ft_strcat_gnl(s1, s2));
}
