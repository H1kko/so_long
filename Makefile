NAME = so_long

CFLAGS = -Werror -Wall -Wextra -g

RM = rm -rf

HDIR = includes/push_swap.h\

OBJ = $(SRC:.c=.o)

SRCS =	src/main.c\
		src/so_long_utils.c\
		src/mapchecker.c\
		src/map_parsing.c\
		src/map_utils.c\
		src/get_next_line/get_next_line.c\
		src/get_next_line/get_next_line_utils.c\
		libft/libft.a\


$(NAME) : $(OBJ)
	make -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME) -I $(HDIR)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

.PHONY : re clean all

