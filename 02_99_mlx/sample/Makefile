NAME		=	so_long

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
MLX_DIR		=	./mlx/

INCS		=	-I include
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	map_sample.c
OBJ			=	$(SRC:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJ) -L $(LIB_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re bonus
