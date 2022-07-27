/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:13 by gbertin           #+#    #+#             */
/*   Updated: 2022/07/27 22:47:36 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void    ft_print_args(t_list_bonus *cmd)
{
    //int i = 0;
    // while (cmd)
	// {
		printf("print : %s\n",cmd->path);
		// while (cmd->args[i] != 0)
        // {
        //     printf("%d\n", cmd->pid);
        //     i++;
        // }
	// 	cmd = cmd->next;
	// }
}

int main(int argc, char* argv[], char *envp[])
{
    t_struct        *pipex;
    t_list_bonus    *cmd;

    if (argc < 5)
        return (0);
    pipex = malloc(sizeof(*pipex));
    if (!pipex)
        return (0);
    cmd = malloc(sizeof(*cmd));
    if (!cmd)
        return (0);
    if(!ft_init(pipex, cmd, argv, envp))
		return (0);
	printf("after init : %s\n", cmd->path);
    ft_print_args(cmd);
    return (0);
}