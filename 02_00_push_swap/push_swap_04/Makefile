NAME	= 	push_swap
LIB_DIR	= 	./libft/
LIB_A	= 	libft.a

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

CLR_RD	=	\033[0;31m
CLR_YL	=	\033[0;33m
CLR_GR	= 	\033[0;32m
CLR_BL	= 	\033[0;36m
CLR_DF	= 	\033[0;37m

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
			_utils.c\

LIB 	=	$(addprefix $(LIB_DIR), $(LIB_A))
OBJ		= 	$(SRC:.c=.o)

all : $(LIB_A) $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(CLR_GR)[created]$(CLR_DF) : $(LIB_A)" 

$(NAME) : $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(CLR_GR)[created]$(CLR_DF) : $(NAME)" 

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)
	@echo "$(CLR_RD)[removed]$(CLR_DF) : $(LIB_A) (obj files)"
	@echo "$(CLR_RD)[removed]$(CLR_DF) : $(NAME) (obj files)"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	@rm -f $(NAME)
	@echo "$(CLR_RD)[removed]$(CLR_DF) : $(LIB_A)"
	@echo "$(CLR_RD)[removed]$(CLR_DF) : $(NAME)"

re : fclean all

.PHONY : all clean fclean re bonus