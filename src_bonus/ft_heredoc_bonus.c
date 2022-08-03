/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:57:41 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/03 10:17:53 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void    ft_print_fd(int fd)
// {
//     char *line;
    
//     close(fd);
//     fd = open(".heredoc", O_RDONLY);
//     line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);
//     }
// }

void ft_write_on_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

// char *ft_rm_n(char *str)
// {
//     char	*ret;
//     int		i;
// 	int		size;

// 	i = 0;
// 	size = ft_strlen(str);
// 	if (str[size - 1] != '\n')
// 		return (str);
// 	ret = malloc(sizeof(char *) * size);
// 	while (i < size - 1)
// 	{
// 		ret[i] = str[i];
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	free(str);
// 	return (ret);
// }

int	ft_heredoc(t_struct *pipex, char *heredoc)
{
    char    *append;

    pipex->inputfile = open(".heredoc",  O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (pipex->inputfile < 0)
        return (0);
    write(1, "here_doc>", 10);
    append = ft_strdup(get_next_line(0));
    while (!ft_strcmp(append, heredoc))
    {
        write(1, "here_doc>", 10);
        ft_write_on_fd(append, pipex->inputfile);
        free(append);
        append = ft_strdup(get_next_line(0));
    }
    free(append);
    // ft_print_fd(pipex->inputfile);
    return (1);
}
