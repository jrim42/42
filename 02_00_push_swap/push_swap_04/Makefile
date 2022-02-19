NAME	= 	push_swap
LIB_DIR	= 	./libft
LIB_A	= 	libft.a

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

SRC		= 	push_swap.c\
			_input.c\
			_stack.c\
			_cmds.c\
			_cmds_utils.c\
			_pivot.c\
			_sort.c\
			_sort_helper.c\
			_sort_utils.c\

OBJ		= 	$(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_A) $(NAME)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJ) $(BNS_OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus