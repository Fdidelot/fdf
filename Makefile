#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 22:22:27 by fdidelot          #+#    #+#              #
#    Updated: 2017/10/03 06:07:53 by fdidelot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 		fdf

SRCS = 		fdf.c \
			map.c \
			draw.c \
			key.c

OBJS = 		$(SRCS:.c=.o)

SRCPATH = 	./srcs/

FLAGS = 	-Wall -Wextra -Werror

all : 		$(NAME)

$(NAME) :	$(addprefix $(SRCPATH), $(SRCS))
			@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) -I includes/
			@make -C libft
			@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) \
				-L. -lmlx -framework OpenGL -framework AppKit
			@rm $(OBJS)

clean :
			@make -C libft clean
			@rm -rf $(OBJS)

fclean :	clean
			@make -C libft fclean
			@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re