/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:57:41 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/01 17:08:06 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_print_fd(int fd)
{
    char *line;
    
    close(fd);
    fd = open(".heredoc", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
}

void ft_write_on_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

int	ft_heredoc(t_struct *pipex, char *heredoc)
{
    char    *append;

    pipex->inputfile = open(".heredoc",  O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (pipex->inputfile < 0)
        return (0);
    append = ft_strdup(get_next_line(0));
    printf("append : %s size = %ld\nheredoc : %s size = %ld\n", append, ft_strlen(append) - 1, heredoc, ft_strlen(heredoc));
    while (ft_strncmp(append, heredoc, ft_strlen(heredoc)) != 0 && ft_strlen(append) -1 == ft_strlen(heredoc))
    {
        // && ((ft_strlen(append) -1) != ft_strlen(heredoc))
        //printf("append : %s size = %ld\nheredoc : %s size = %ld\n", append, ft_strlen(append), heredoc, ft_strlen(heredoc));
        //printf("append : size = %ld\nheredoc  size = %ld\n", ft_strlen(append) - 1, ft_strlen(heredoc));
        ft_write_on_fd(append, pipex->inputfile);
        free(append);
        append = ft_strdup(get_next_line(0));
        printf("next = %s\n", append);
    }
    //printf("append : %s size = %ld\nheredoc : %s size = %ld\n", append, ft_strlen(append) -1, heredoc, ft_strlen(heredoc));
    free(append);
    //ft_print_fd(pipex->inputfile);
    return (1);
}
