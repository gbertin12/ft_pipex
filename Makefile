# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:47:30 by gbertin           #+#    #+#              #
#    Updated: 2022/08/09 17:50:36 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
SRCS = 	pipex.c \
		sources/free.c \
		sources/msg_err.c \
		sources/open.c \
		sources/utils.c \
		sources/execute_cmd.c \
		sources/libs/ft_split.c \
		sources/libs/ft_bzero.c \
		sources/libs/ft_memset.c \
		sources/libs/ft_strjoin.c \
		sources/libs/ft_strlen.c \
		sources/libs/ft_strncmp.c 

		

SRCS_BONUS = 	pipex_bonus.c \
				src_bonus/create_list_bonus.c \
				src_bonus/free_bonus.c \
				src_bonus/heredoc_bonus.c \
				src_bonus/msg_err_bonus.c \
				src_bonus/multi_pipe_bonus.c \
				src_bonus/open_bonus.c \
				src_bonus/search_path_bonus.c \
				src_bonus/utils_list_bonus.c \
				src_bonus/libs/ft_strcmp_bonus.c \
				src_bonus/libs/ft_strdup_bonus.c \
				src_bonus/libs/ft_bzero_bonus.c \
				src_bonus/libs/ft_split_bonus.c \
				src_bonus/libs/ft_memset_bonus.c \
				src_bonus/libs/ft_strjoin_bonus.c \
				src_bonus/libs/ft_strlen_bonus.c \
				src_bonus/libs/get_next_line_bonus.c \
				src_bonus/libs/get_next_line_utils_bonus.c \
				src_bonus/libs/ft_strncmp_bonus.c 

HEAD = includes/pipex.h

OBJ=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEAD)
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):$(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
			$(RM) $(NAME) $(NAME_BONUS) 

OBJ_BONUS=$(SRCS_BONUS:.c=.o)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

bonus: $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus