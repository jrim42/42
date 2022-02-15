NAME	= 	push_swap
LIB_DIR	= 	./libft
LIB_A	= 	libft.a

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

SRC		= 	push_swap.c\
			psw_input.c\
			psw_cmds.c\
			psw_cmds_utils.c\
			psw_pivot.c\
			psw_sort.c\
			psw_sort_utils.c\
			unnecessary.c
			
BONUS 	=

OBJ		= 	$(SRC:.c=.o)
BNS_OBJ	= 	$(BONUS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_A) $(NAME)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

bonus : 

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJ) $(BNS_OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus