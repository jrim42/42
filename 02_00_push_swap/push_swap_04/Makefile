NAME	= 	push_swap
LIB_DIR	= 	./libft/
LIB_A	= 	libft.a

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

SRC		= 	push_swap.c\
			_input.c\
			_stack_1.c\
			_stack_2.c\
			_cmds.c\
			_cmds_utils.c\
			_pivot.c\
			_sort.c\
			_sort_helper.c\
			_sort_utils.c\

LIB 	=	$(addprefix $(LIB_DIR), $(LIB_A))
OBJ		= 	$(SRC:.c=.o)

# .c.o:
# 	$(CC) $(CFLAGS) $^ -0 -@

all : $(LIB_A) $(NAME)

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)

$(NAME) : $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus