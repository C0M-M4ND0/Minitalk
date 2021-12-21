# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:52:30 by oabdelha          #+#    #+#              #
#    Updated: 2021/12/21 10:45:43 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CM = cc
FLAG = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	@cd ft_printf; make;
	@$(CM) $(FLAG) client.c ft_printf/libftprintf.a -o client
	
$(SERVER) :
	@$(CM) $(FLAG) server.c ft_printf/libftprintf.a -o server

clean:	
	@rm -rf ft_printf/*.o
	@rm -rf server client ft_printf/libftprintf.a

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)

re: fclean all
