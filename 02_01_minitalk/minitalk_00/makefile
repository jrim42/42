SRV		=	server
CLT		= 	client

SRV_SRC	=	_server.c
SRV_OBJ	=	$(SRV_SRC:.c=.o)
CLT_SRC	=	_client.c
CLT_OBJ	=	$(CLT_SRC:.c=.o)

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

LIB_DIR	= 	./libft/
LIB_A		= 	libft.a
LIB			=	$(addprefix $(LIB_DIR), $(LIB_A))

CLR_RD	=	\033[0;31m
CLR_GR	= 	\033[0;32m
CLR_DF	= 	\033[0;37m

all : $(LIB_A) $(SRV) $(CLT)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)

$(SRV) : $(SRV_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(SRV) $(CLR_GR)ready$(CLR_DF)" 

$(CLT) : $(CLT_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(CLT) $(CLR_GR)ready$(CLR_DF)" 

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f *.o
	@echo "$(CLR_RD)cleaned$(CLR_DF)"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	@rm -f $(SRV) $(CLT)
	@echo "$(CLR_RD)fcleaned$(CLR_DF)"

re : fclean all

.PHONY : all clean fclean re bonus