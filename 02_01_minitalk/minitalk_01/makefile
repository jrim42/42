SRV		=	server
CLT		= 	client

S_SRC	=	_server.c
S_OBJ	=	$(S_SRC:.c=.o)
C_SRC	=	_client.c
C_OBJ	=	$(C_SRC:.c=.o)

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

LIB_DIR	= 	./libft/
LIB_A	= 	libft.a
LIB		=	$(addprefix $(LIB_DIR), $(LIB_A))

RED		=	\033[0;31m
GRN		= 	\033[0;32m
YLW		=	\033[0;33m
BLU		= 	\033[0;36m
DFT		= 	\033[0;37m

all : $(LIB_A) $(SRV) $(CLT)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)

$(SRV) : $(S_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(SRV) is $(GRN)ready$(DFT)" 

$(CLT) : $(C_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(CLT) is $(GRN)ready$(DFT)" 

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f *.o
	@echo "$(RED)cleaned$(DFT)"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	@rm -f $(SRV) $(CLT)
	@echo "$(RED)fcleaned$(DFT)"

re : fclean all

.PHONY : all clean fclean re bonus