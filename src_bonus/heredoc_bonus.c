/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:57:41 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/09 18:10:15 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void ft_write_on_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

int	heredoc(t_struct *pipex, char *heredoc)
{
    char    *append;

    pipex->inputfile = open(".heredoc",  O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (pipex->inputfile < 0)
        return (0);
    write(1, "here_doc>", 10);
    append = get_next_line(0);
    while (!ft_strcmp(append, heredoc))
    {
        write(1, "pipe heredoc>", 14);
        ft_write_on_fd(append, pipex->inputfile);
        free(append);
        append = get_next_line(0);
    }
    free(append);
    return (1);
}
