TARGET = libft.a
CC = gcc -Wall -Wextra -Werror -c -o

all: $(TARGET)

$(TARGET): *.o
	ar rc $(TARGET) *.o

*.o : libft.h *.c
	$(CC) *.o *.c

#./srcs/ft_putchar.o : ./include/ft.h ./srcs/ft_putchar.c
#	$(CC) ./srcs/ft_putchar.o ./srcs/ft_putchar.c

clean:
	rm -f ./srcs/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

#bonus _bonus 이용하기