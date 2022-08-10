/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:44:42 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/10 12:25:14 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list_bonus
{
	pid_t				pid;
	char				**args;
	char				*path;
	struct s_list_bonus	*next;
}			t_list_bonus;

typedef struct s_struct
{
	int				inputfile;
	int				outputfile;
	char			**path_absolute;
	t_list_bonus	*cmd;
}			t_struct;
// LIBS
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			**ft_split(char *s, char c);
int				ft_strcmp(char *str1, char *str2);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memalloc(size_t size);
// GNL
int				ft_strlen_gnl(char *s);
char			*ft_strcat_gnl(char *s1, char *s2);
char			*ft_strjoin_gnl(char *s1, char *s2);
int				ft_strchr_gnl(char *s, int c);
char			*ft_saveline(char *str);
char			*ft_cutline(char *str);
char			*get_next_line(int fd);
// CREATE LIST
int				ft_init(t_struct *pipex, char *argv[], char *envp[], int argc);
int				ft_init_list(t_struct *pipex, char *argv);
int				ft_fill_list(t_struct *pipex, char *argv[]);
// FREE 
int				ft_free_struct(t_struct *pipex);
void			ft_free_list(t_list_bonus *cmd);
int				free_bad_files(t_struct *pipex);
void			ft_free_close_bonus(t_struct *pipex, t_list_bonus *cmd);
void			ft_free_args(t_list_bonus *pipex);
// HEREDOC
void			ft_write_on_fd(char *str, int fd);
int				heredoc(t_struct *pipex, char *heredoc);
// MULTI PIPE
int				ft_exec_cmd(t_list_bonus *cmd, t_struct *pipex, char *envp[]);
int				ft_browse_cmd(t_struct *pipex, t_list_bonus *cmd, char *envp[]);
int				execmid_cmd(int fd[2], t_list_bonus *cmd,
					t_struct *pipex, char *envp[]);
int				exec_last_cmd(t_list_bonus *cmd,
					t_struct *pipex, char *envp[], int fd[2]);
// OPEN
int				open_files(t_struct *pipex, int argc, char *argv[]);
// RETURN ERROR
int				free_all(t_list_bonus *cmd, t_struct *pipex);
// SEARCH PATH
char			*make_path(t_struct *pipex, t_list_bonus *cmd);
char			**get_path_env(char *env[]);
int				ft_search_char(char *str);
// MSG ERROR
int				ft_error(t_list_bonus *pipex);
int				ft_error_open_infile(t_list_bonus *pipex);
// UTILS LIST
int				ft_addend(t_struct *pipex, char *argv);
t_list_bonus	*ft_islast(t_list_bonus *lst);
void			wait_all_pid(t_list_bonus *cmd);

#endif