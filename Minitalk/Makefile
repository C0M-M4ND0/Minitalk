# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:52:30 by oabdelha          #+#    #+#              #
#    Updated: 2021/12/20 17:33:54 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = server.c client.c



INCLUDE = minitalk.h

all: $(NAME)

$(NAME) :  $(INCLUDE)
	@cd ft_printf; make;
	@gcc -W -W -W client.c ft_printf/libftprintf.a -o client
	@gcc -W -W -W server.c ft_printf/libftprintf.a -o server


clean:	
	@rm -rf server.o client.o ft_printf/*.o
	@rm -rf server client ft_printf/libftprintf.a

fclean: clean
	@rm -rf $(NAME)

re: fclean all
