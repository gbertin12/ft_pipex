/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex->h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:38:27 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/21 11:57:51 by gbertin          ###   ########.fr       */
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
	int 	pipe[2];
	int		inputfile;
	int		outputfile;
	char	**path_absolute;
	char 	*path;
	char	**args;
}              t_list;

typedef struct t_struct
{
	int		inputfile;
	int		outputfile;
	char	**path_absolute;
	
}			t_struct;

typedef struct t_list_bonus
{
	pid_t			pid;
	int				pipe[2];
	char			**args;
	char			*path;
	void			*next;
}			t_list_bonus;

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char 	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

void	*ft_memalloc(size_t size);
void	ft_free_close(t_list *pipex);
int		ft_print_error(char *msg_error);
void	ft_free_child(t_list *pipex);


char	**ft_fill_path_env(char *env[]);
void	ft_exec_second(t_list *pipex, char *argv[], char *envp[]);
void	ft_exec_first(t_list *pipex, char *argv[], char *envp[]);
char	*ft_get_path(t_list *pipex);

/// BONUS

int		ft_free_struct(t_struct *pipex, t_list_bonus *cmd);
int 	ft_init(t_struct *pipex, t_list_bonus *cmd, char *argv[], char *envp[]);
int		ft_init_list(t_struct *pipex, t_list_bonus *cmd, char *argv);
int		ft_fill_list(t_struct *pipex, t_list_bonus *cmd, char *argv[]);
char	*ft_get_path_bonus(t_struct *pipex, t_list_bonus *cmd);
int		ft_addend(t_struct *pipex, t_list_bonus *cmd, char *argv);



void    ft_print_args(t_list_bonus *cmd);
#endif