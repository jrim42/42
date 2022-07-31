NAME		=	philo

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

SRC			=	main.c \
				_init.c \
				_monitor.c \
				_philo.c \
				_utile.c \
				
OBJ			=	$(SRC:.c=.o)

all : $(NAME) 

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(NAME) is $(GRN)ready$(DFT)"

clean :
	@$(RM) $(OBJ)
	@echo "$(RED)cleaned$(DFT)"

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(RED)fcleaned$(DFT)"

re : 
	@$(MAKE) fclean
	@$(MAKE) all

PHONY : all clean fclean re
