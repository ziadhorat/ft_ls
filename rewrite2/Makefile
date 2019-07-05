NAME = ft_ls
LIBFT_PATH = ./libft/
FLAGS = -Wall -Werror -Wextra
INC =  -I ./includes/ft_ls.h -I $(LIBFT_PATH)libft.h
SRCS = ft_ls.c \
	   handle_list.c \
	   handle_error.c \
	   handle_print.c \
	   main.c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT_PATH)libft.a

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf *.o

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)

re: fclean all
