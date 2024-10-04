NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror

MY_SOURCE = ft_printf.c \
			ft_characters.c \
			ft_numbers.c \

OBJ := $(MY_SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.o: .cc
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: clean fclean re all
