# CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
PSRC = parcing/remain.c parcing/Validation.c parcing/Phase01.c parcing/Phase02.c parcing/Phase03.c parcing/PassData.c
ESRC = exec/main.c exec/check_funct.c exec/dda.c exec/draw_func.c exec/init.c exec/key_handling.c exec/render.c
OBJ = $(ESRC:.c=.o) $(PSRC:.c=.o)
LIBFT = libft/libft.a
OLIBFT = libft/*.c
NAME = cub3D

all: $(LIBFT) $(NAME)
	-@# -Lmlx -lmlx -framework OpenGL -framework AppKit
	-@echo "Cub3D is ready to play!"

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit

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
