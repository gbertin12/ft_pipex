# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:47:30 by gbertin           #+#    #+#              #
#    Updated: 2022/07/21 12:09:29 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
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
		sources/ft_strncmp.c 

HEAD = includes/pipex->h

OBJ=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEAD)
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):$(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re