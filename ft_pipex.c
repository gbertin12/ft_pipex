/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:06:46 by gbertin           #+#    #+#             */
/*   Updated: 2022/03/10 12:24:29 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void ft_exec_first(t_list pipex, *argv[], char *envp[])
{
	pipex.args = ft_split(argv[2], ' ');
	dup2(pipex.inputfile, STDOUT_FILENO);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	execve("ping", "ping", envp);
}

void ft_exec_second(t_list pipex, char *argv[], char *envp[])
{
	pipex.args = ft_split(argv[3], ' ');
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	execve("grep", "grep", envp);
}

char	*ft_strjoin(char const *s1, char const *s2) // vérifier si c'est la bonne
{
	unsigned int	len_s;
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len_s = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = (char *)ft_memalloc(len_s);
	if (!new_s)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (new_s);
}

int	main(int argc, char* argv[])
{
	t_list pipex;
	if (argc == 5)
	{
		pipex.inputfile = open(argv[1], O_RDONLY);
		if (pipex.inputfile < 0)
			return ("Error inputfile");
		pipex.outputfile = open(argv[4]) // manque des arguments
		if (pipe(pipex.fd) == -1)
		return (1);
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		if (pipex.pid1 == 0)
		{
			ft_exec_first(pipex.fd, pipex, argv);
		}
		pipex.pid2 = fork();
		if (pipex.pid2 < 0)
			return (3);
		if (pipex.pid2 == 0)
		{
			ft_exec_second(pipex.fd, pipex, argv);
		}
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
	}
	else
		return("Error argument");
}