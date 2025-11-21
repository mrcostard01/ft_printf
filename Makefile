# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wipion <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 16:11:45 by wipion            #+#    #+#              #
#    Updated: 2025/10/16 17:46:11 by wipion           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=  ft_hexadecimal.c ft_pointeradress.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:		  
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re

