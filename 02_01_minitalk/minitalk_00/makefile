SRC		= 	client.c\
			server.c
OBJ		= 	$(SRC:.c=.o)

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

LIB_DIR	= 	./libft/
LIB_A	= 	libft.a
LIB 	=	$(addprefix $(LIB_DIR), $(LIB_A))

CLR_RD	=	\033[0;31m
CLR_YL	=	\033[0;33m
CLR_GR	= 	\033[0;32m
CLR_BL	= 	\033[0;36m
CLR_DF	= 	\033[0;37m

all : $(LIB_A) server client 

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)

$(NAME) : $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(CLR_GR)ready$(CLR_DF)" 

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)
	@echo "$(CLR_RD)cleaned$(CLR_DF)"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	@rm -f server client
	@echo "$(CLR_RD)fcleaned$(CLR_DF)"

re : fclean all

.PHONY : all clean fclean re bonus