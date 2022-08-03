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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//https://github.com/vfurmane/pipex-tester
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

typedef struct t_list_bonus
{
	pid_t			pid;
	char			**args;
	char			*path;
	void			*next;
}			t_list_bonus;

typedef struct t_struct
{
	int				inputfile;
	int				outputfile;
	char			**path_absolute;
	t_list_bonus 	*cmd;
	
}			t_struct;

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char 	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *str1, char *str2);
int		ft_search_char(char *str);

void	*ft_memalloc(size_t size);
void	ft_free_close(t_list *pipex);
int		ft_error(t_list *pipex);
void	ft_free_child(t_list *pipex);


char	**ft_fill_path_env(char *env[]);
void	ft_exec_second(t_list *pipex, char *argv[], char *envp[]);
void	ft_exec_first(t_list *pipex, char *argv[], char *envp[]);
char	*ft_get_path(t_list *pipex);

/// BONUS

int		ft_free_struct(t_struct *pipex);

// INIT 
int 			ft_init(t_struct *pipex, char *argv[], char *envp[], int argc);
int				ft_init_list(t_struct *pipex, char *argv);
int				ft_fill_list(t_struct *pipex, char *argv[]);
char			*ft_get_path_bonus(t_struct *pipex, t_list_bonus *cmd);
int				ft_addend(t_struct *pipex, char *argv);
t_list_bonus	*ft_islast(t_list_bonus *lst);
int				ft_open_files(t_struct *pipex, int argc, char *argv[]);

// MULTI PIPE
void	ft_exec_first_bonus(t_struct *pipex, t_list_bonus *cmd, char *envp[]);
int		ft_exec_cmd(t_list_bonus *cmd, char *envp[]);
void	ft_exec_last_cmd(t_struct *pipex, t_list_bonus *cmd, t_list_bonus *cmd_before, char *envp[]);
int		ft_browse_args(t_struct *pipex, t_list_bonus *cmd, char *envp[]);
int		ft_exec_args(t_struct *pipex, t_list_bonus *cmd, char *envp[]);

// FREE 
void	ft_free_close_bonus(t_struct *pipex, t_list_bonus *cmd, char **argv);
void	ft_free_list(t_list_bonus *cmd);
void	ft_free_args(t_list_bonus *cmd);
void	ft_waitpid(t_list_bonus *cmd);

// GNL
int		ft_strlen_gnl(char *s);
char	*ft_strcat_gnl(char *s1, char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);

char	*ft_saveline(char *str);
char	*ft_cutline(char *str);
char	*get_next_line(int fd);

// HEREDOC
void	ft_print_fd(int fd);
void	ft_write_on_fd(char *str, int fd);
int		ft_heredoc(t_struct *pipex, char *heredoc);
char	*ft_strdup(char *s1);

#endif