NAME		=	miniRT

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

INC			=	include/print.h \
				include/scene.h \
				include/structures.h \
				include/trace.h \
				include/utils.h

SRC			=	src/canvas.c \
				src/print.c \
				src/ray.c \
				src/hit.c \
				src/obj_create.c \
				src/obj_utils.c \
				src/vt_utils.c \
				src/phong.c \
				src/cylinder.c \
				main/main_scene2.c
				
OBJ			=	$(SRC:.c=.o)

all : $(NAME) 

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(RLFLAGS)
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

PHONY	: all clean fclean re