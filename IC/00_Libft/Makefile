TARGET = libft.a
CC = gcc -Wall -Wextra -Werror -c -o

all: $(TARGET)

$(TARGET): ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o
	ar rc $(TARGET) ./srcs/*.o

./srcs/ft_putchar.o : ./include/ft.h ./srcs/ft_putchar.c
	$(CC) ./srcs/ft_putchar.o ./srcs/ft_putchar.c

./srcs/ft_putstr.o : ./include/ft.h ./srcs/ft_putstr.c
	$(CC) ./srcs/ft_putstr.o ./srcs/ft_putstr.c

./srcs/ft_strcmp.o : ./include/ft.h ./srcs/ft_strcmp.c
	$(CC) ./srcs/ft_strcmp.o ./srcs/ft_strcmp.c

./srcs/ft_strlen.o : ./include/ft.h ./srcs/ft_strlen.c
	 $(CC) ./srcs/ft_strlen.o ./srcs/ft_strlen.c

./srcs/ft_swap.o : ./include/ft.h ./srcs/ft_swap.c
	 $(CC) ./srcs/ft_swap.o ./srcs/ft_swap.c

clean:
	rm -f ./srcs/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
