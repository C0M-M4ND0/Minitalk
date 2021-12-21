# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:15:27 by oabdelha          #+#    #+#              #
#    Updated: 2021/11/28 12:05:22 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c

CNVRT = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME) : $(CNVRT) $(INCLUDE)
	@ar rcs $(NAME) $(CNVRT) $(INCLUDE)

%.o : %.c $(INCLUDE)
	@$(CM) $(FLAG) -o $@ -c $<

clean:	
	@rm -rf $(CNVRT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
