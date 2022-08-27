NAME		=	philo

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
# CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=thread
AR			=	ar rcs
RM			=	rm -f

SRC			=	philo.c \
				_monitor.c \
				_param.c \
				_routine.c \
				_utils.c
				
OBJ			=	$(SRC:.c=.o)

all : $(NAME) 

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
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
