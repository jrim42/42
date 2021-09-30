TARGET = libft.a
CC = gcc -Wall -Wextra -Werror -c -o
OBJ = ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rc $(TARGET) $(OBJ)

./srcs/ft_putchar.o : ./includes/ft.h ./srcs/ft_putchar.c
	$(CC) ./srcs/ft_putchar.o ./srcs/ft_putchar.c -I ./includes/

./srcs/ft_putstr.o : ./includes/ft.h ./srcs/ft_putstr.c
	$(CC) ./srcs/ft_putstr.o ./srcs/ft_putstr.c -I ./includes/

./srcs/ft_strcmp.o : ./includes/ft.h ./srcs/ft_strcmp.c
	$(CC) ./srcs/ft_strcmp.o ./srcs/ft_strcmp.c -I ./includes/

./srcs/ft_strlen.o : ./includes/ft.h ./srcs/ft_strlen.c
	 $(CC) ./srcs/ft_strlen.o ./srcs/ft_strlen.c -I ./includes/

./srcs/ft_swap.o : ./includes/ft.h ./srcs/ft_swap.c
	 $(CC) ./srcs/ft_swap.o ./srcs/ft_swap.c -I ./includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
