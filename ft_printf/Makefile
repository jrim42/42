TARGET = libftprintf.a

CC = gcc -Wall -Wextra -Werror -c -o

SRC = ft_printf.c
	  ft_printf_num.c
	  ft_printf_str.c
	  ft_printf_utils.c
OBJ = $(SRC:.c=.o)

BONUS = 
BONUS_OBJ = $(BONUS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rc $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(TARGET) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
