CC = gcc
RM = rm -rf
CFLAGS = -fsanitize=address -g
SRC = main.c check_funct.c dda.c draw_func.c init.c key_handling.c render.c

OBJ = $(SRC:%c=%o)

NAME = cube3d
 
all: $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)
re: fclean all