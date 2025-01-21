NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g

MLX			= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

RM = rm -rf

HDIR = includes

LIB = libft/libft.a

MLXDIR = MLX42/include/MLX42

OBJ = $(SRC:.c=.o)

SRC =	src/main.c \
		src/manage_texture.c \
		src/so_long_utils.c \
		src/mapchecker.c \
		src/map_parsing.c \
		src/map_utils.c \
		src/manage_movement.c \
		src/get_next_line/get_next_line.c \
		src/get_next_line/get_next_line_utils.c 

all : $(NAME)

$(NAME) : libft $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

libft :
	make -C libft

%.o : %.c
	cc $(CFLAGS) -c $< -o $@ -I $(HDIR)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(OBJ)
	make clean -C libft

re : fclean all

.PHONY : re clean all fclean libft

