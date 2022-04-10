/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:38:27 by gbertin           #+#    #+#             */
/*   Updated: 2022/04/10 09:46:15 by gbertin          ###   ########.fr       */
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
#include <fcntl.h>

typedef struct t_list
{
	pid_t	pid1;
	pid_t	pid2;
	int 	fd[2];
	int		inputfile;
	int		outputfile;
	char	**path_absolute;
	char 	*path;
	char	**args;
}              t_list;

void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char 	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memalloc(size_t size);

#endif