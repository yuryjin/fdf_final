# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 17:42:14 by zlucan            #+#    #+#              #
#    Updated: 2020/08/15 15:26:23 by zlucan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wextra -Wall -Werror

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c  \
       ft_memchr.c ft_memdel.c ft_memmove.c ft_memset.c \
       ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putnbr.c ft_putstr.c \
       ft_putstr_fd.c ft_strchr.c ft_strclr.c ft_strcmp.c \
       ft_strcpy.c ft_strdel.c ft_strdup.c ft_striter.c \
       ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
       ft_strmapi.c  ft_strncmp.c ft_strncpy.c ft_strnequ.c \
       ft_strnew.c ft_strnstr.c ft_strsplit.c ft_strstr.c \
       ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strlcat.c \
       ft_memcmp.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
       ft_lstdelone.c ft_lstdel.c  ft_lstiter.c ft_lstmap.c \
    	ft_swap.c ft_lstrev.c ft_lstlen.c ft_strrev.c \
	   ft_wdcounter.c \
                     ft_printf.c        \
			a1_formating.c	\
			a2_0_validation.c	\
			a2_1_validation2.c	\
			a3_0_param_processing.c	\
			a3_1_param_processing_flags.c	\
			a3_2_param_processing_width.c	\
			a3_3_param_processing_access.c	\
			a3_4_param_processing_precision.c	\
			a3_5_param_processing_modifiers.c	\
			a3_6_param_processing_conversion.c	\
			a3_7_param_processing_init.c	\
			a3_8_param_processing_conversions_case.c	\
			a4_0_transform.c	\
			a4_2_transform_string.c	\
			a4_3_transform_char.c	\
			a4_4_transform_hex.c	\
			a4_5_transform_percent.c	\
			a5_write_result.c	\
			libft.c	\
			libft2.c	\
			libft3.c	\
                     get_next_line.c  \

OBJECTS = $(SRCS:.c=.o)

INCLUDES = ./

all: $(NAME)

$(NAME): $(OBJECTS)
		#$(OBJECTS)%.o: $(SRCS)%.c
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

%.o : %.c
	gcc -c $< -o $@

clean:
		rm -rf $(OBJECTS)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
