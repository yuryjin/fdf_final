# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 11:54:19 by zlucan            #+#    #+#              #
#    Updated: 2020/08/15 15:52:47 by zlucan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=main.c draw.c read_file.c
INCLUDES=libft/libft.a minilibx_macos/libmlx.a
OBJ = $(SRC:.c=.o)

#.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)

%.o : %.c
	gcc -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push
