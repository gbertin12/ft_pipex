/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:38:27 by gbertin           #+#    #+#             */
/*   Updated: 2022/03/09 14:22:24 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct t_list
{
	pid_t	pid1;
	pid_t	pid2;
	int 	fd[2];
	int		inputfile;
	int		outputfile;
	char	*path_command;
	char	*args[];
}              t_list;

void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
#endif