NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft

$(NAME):
	@make -C $(LIB_PATH)
	@gcc -c *.c -I *.h
	@gcc $(FLAGS) $(LIB_PATH)/libft.a *.o -o $(NAME)

all: $(NAME)

clean: 
	@make clean -C $(LIB_PATH)
	@rm -f *.gch *.o

fclean: clean
	@rm -f $(LIB_PATH)/libft.a
	@rm -f $(NAME)

re: fclean all