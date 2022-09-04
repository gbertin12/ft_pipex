/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:38:27 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/04 14:05:07 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
#include <errno.h>

//https://github.com/vfurmane/pipex-tester
typedef struct t_list
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		inputfile;
	int		outputfile;
	char	**path_absolute;
	char	*path;
	char	**args;
}				t_list;

// LIBS
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			**ft_split(char *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
void			*ft_memalloc(size_t size);
int				search_char(char *s);

// EXECUTE CMD
int				execute_cmd(t_list *pipex, char **argv, char **envp);
void			ft_exec_second(t_list *pipex, char *argv[], char *envp[]);
void			ft_exec_first(t_list *pipex, char *argv[], char *envp[]);

// FREE 
void			ft_free_close(t_list *pipex);
void			free_child(t_list *pipex);
void			close_prog(t_list *pipex);

// MSG ERROR
int				error_files(t_list *pipex);
int				error(t_list *pipex);

// OPEN
int				open_files(char **argv, t_list *pipex);

//UTILS 
int				ft_search_char(char *str);
char			*ft_get_path(t_list *pipex);
char			**get_path_env(char *env[]);

#endif