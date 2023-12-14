CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRC = checks.c main.c 
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
OLIBFT = libft/*.c
NAME = cub3D

all: $(LIBFT) $(NAME)
	-@# -Lmlx -lmlx -framework OpenGL -framework AppKit
	-@echo "Cub3D is ready to play!"

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT) : $(OLIBFT)
	-@echo "Compiling libft..."
	@make -C libft -s

clean :
	-@echo "Cleaning up object files..."
	@make clean -C libft -s
	@rm -f $(OBJ)

fclean : clean
	-@echo "Cleaning up..."
	@make fclean -C libft -s
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

