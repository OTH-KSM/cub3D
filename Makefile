CFLAGS = #-fsanitize=address -g3
PSRC = parc/remain.c parc/Validation.c parc/Phase01.c parc/Phase02.c parc/Phase03.c parc/PassData.c parc/Phase01_ut.c parc/add_fun01.c parc/add_fun02.c
ESRC = exec/check_funct.c exec/dda.c exec/draw_func.c exec/init.c exec/key_handling.c exec/render.c exec/dda_init.c
GSRC = main.c #global variables
OBJ = $(ESRC:.c=.o) $(PSRC:.c=.o) $(GSRC:.c=.o)
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
