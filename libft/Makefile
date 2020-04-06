# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:38:51 by qdang             #+#    #+#              #
#    Updated: 2019/11/07 22:47:58 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

PRINTF_PATH = ./ft_printf

$(NAME):
	@gcc $(FLAGS) -c *.c -c $(PRINTF_PATH)/*.c -I *.h
	@ar rc $(NAME) *.o

all: $(NAME)

clean:
	@rm -f *.o
	@rm -f *.gch

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
