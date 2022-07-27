# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:47:30 by gbertin           #+#    #+#              #
#    Updated: 2022/07/27 15:20:48 by gbertin          ###   ########.fr        #
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
				sources/ft_bzero.c \
				sources/ft_free.c \
				sources/ft_split.c \
				sources/ft_memset.c \
				sources/ft_strjoin.c \
				sources/ft_strlen.c \
				sources/ft_utils.c \
				src_bonus/free_bonus.c \
				src_bonus/init_bonus.c \
				sources/ft_strncmp.c 

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
			$(RM) $(NAME)

OBJ_BONUS=$(SRCS_BONUS:.c=.o)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

bonus: $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus