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
NAME            = libftprintf.a

CC              = gcc
CFLAGS          = -Wall -Wextra -Werror
AR              = ar
ARFLAGS         = rcs
RM              = rm -rf

SRC             = ft_printf.c ft_pointeradress.c flags.c flags2.c

OBJ_DIR         = obj
OBJS            = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a

all:            $(NAME)

$(NAME):        $(LIBFT) $(OBJ_DIR) $(OBJS)
			cp $(LIBFT) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)

fclean: 		clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re