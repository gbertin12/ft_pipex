# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:47:30 by gbertin           #+#    #+#              #
#    Updated: 2022/08/01 15:52:48 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = 	ft_pipex.c \
		sources/ft_bzero.c \
		sources/ft_free.c \
		sources/ft_split.c \
		sources/ft_memset.c \
		sources/ft_strjoin.c \
		sources/ft_strlen.c \
		sources/ft_utils.c \
		sources/ft_strncmp.c 

SRCS_BONUS = 	ft_pipex_bonus.c \
				src_bonus/ft_bzero_bonus.c \
				src_bonus/ft_free_bonus.c \
				src_bonus/ft_split_bonus.c \
				src_bonus/ft_memset_bonus.c \
				src_bonus/ft_strjoin_bonus.c \
				src_bonus/ft_strlen_bonus.c \
				src_bonus/free_bonus.c \
				src_bonus/init_bonus.c \
				src_bonus/init2_bonus.c \
				src_bonus/ft_multi_pipe_bonus.c \
				src_bonus/get_next_line_bonus.c \
				src_bonus/ft_heredoc_bonus.c \
				src_bonus/ft_strdup_bonus.c \
				src_bonus/get_next_line_utils_bonus.c \
				src_bonus/ft_strncmp_bonus.c 

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