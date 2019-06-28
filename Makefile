NAME = ft_ls

SRCS = 	ft_ls.c \
		main.c \
		ft_lib.c

INC = ft_ls.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@/bin/rm -f $(OUTPUT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
