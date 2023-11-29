CFLAGS = -Wall -Wextra -Werror
SRCP1 =	ft_memcpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c
SRCP2 = ft_striteri.c ft_strmapi.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c
GNL = get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRCP1:.c=.o) $(SRCP2:.c=.o) $(GNL:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
clean :
	rm -fr $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all
