# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 15:22:14 by soljeong          #+#    #+#              #
#    Updated: 2024/02/16 15:22:16 by soljeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

SRCS	=  fractol.c

OBJS = $(SRCS:%.c=%.o)


CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-lmlx -framework OpenGL -framework Appkit
MAKE = make

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all