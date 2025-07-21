# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 15:10:20 by mtran-nh          #+#    #+#              #
#    Updated: 2025/07/21 20:39:38 by mtran-nh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_hex.c ft_function.c ft_printf.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc
CFlAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re