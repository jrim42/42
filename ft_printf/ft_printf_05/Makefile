TARGET	= 	libftprintf.a

LIB_DIR	= 	./libft
LIB_A	= 	libft.a

CC		= 	gcc -Wall -Wextra -Werror

SRC		= 	ft_printf.c \
			ft_printf_str.c \
			ft_printf_num.c \

BONUS 	=	ft_printf_bonus.c \
			ft_printf_str_bonus.c \
			ft_printf_num_bonus.c \
			ft_printf_parse_bonus.c \
			ft_printf_utils_bonus.c \

OBJ		= 	$(SRC:.c=.o)

BNS_OBJ	= 	$(BONUS:.c=.o)

.c.o:
	$(CC) -c $< -I.

$(TARGET) : $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_A) $(TARGET)
	ar rc $(TARGET) $(OBJ)

all : $(TARGET)

bonus : $(OBJ) $(BNS_OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_A) $(TARGET)
	ar rc $(TARGET) $(OBJ) $(BNS_OBJ)

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJ) $(BNS_OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(TARGET)

re : clean all

.PHONY : all clean fclean re bonus