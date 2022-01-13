TARGET	= 	libftprintf.a

LIB_DIR	= 	./libft
LIB_A	= 	libft.a

CC		= 	gcc -Wall -Wextra -Werror

SRC		= 	ft_printf.c \
			ft_printf_str.c \
			ft_printf_num.c \
			ft_printf_parse.c \
			ft_printf_utils.c \

BONUS 	=

OBJ		= 	$(SRC:.c=.o)
BNS_OBJ	= 	$(BONUS:.c=.o)

.c.o:
	$(CC) -c $< -I.

$(TARGET) : $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_A) $(TARGET)
	ar rc $@ $?

all : $(TARGET)

bonus : 

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJ) $(BNS_OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(TARGET)

re : clean all

.PHONY : all clean fclean re bonus
