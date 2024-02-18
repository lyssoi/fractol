# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 15:22:14 by soljeong          #+#    #+#              #
#    Updated: 2024/02/18 19:06:00 by soljeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

SRCS	=  fractol.c\
			ft_atof.c\
			mlx_utils.c

OBJS = $(SRCS:.c=.o)
SUBDIRS = libft

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-lmlx -framework OpenGL -framework Appkit
MAKE = make

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJS)
	make -C $(SUBDIRS)
	cp $(SUBDIRS)/libft.a $(NAME)
	$(CC) $(CFLAGS) -I. $(CLIB) $(OBJS) -o $(NAME) -lft -L$(SUBDIRS)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	make -C $(SUBDIRS) clean
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(SUBDIRS)/libft.a
	rm -rf	$(NAME)

re		: fclean all