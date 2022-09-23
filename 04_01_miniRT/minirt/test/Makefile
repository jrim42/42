NAME		=	miniRT

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

INC			=	include/minirt.h \
				inlcude/mlx_hook.h \
				include/mlx_key.h \
				include/objects.h \
				include/ray.h \
				include/scene.h \
				include/structs.h \
				include/utils.h

SRC			=	src/core/main.c \
				src/hook/create.c \
				src/hook/destroy.c \
				src/hook/hook_1.c \
				src/hook/hook_2.c \
				src/hook/hook_3.c \
				src/hook/hook_utils.c \
				src/hook/msg_loop.c \
				src/object/hit_cy_1.c \
				src/object/hit_cy_2.c \
				src/object/hit_pl.c \
				src/object/hit_sp.c \
				src/object/hit.c \
				src/object/obj_setup_1.c \
				src/object/obj_setup_2.c \
				src/object/obj_utils.c \
				src/scene/graphic_render.c \
				src/scene/graphic_setup.c \
				src/scene/graphic_utils.c \
				src/scene/ray_color.c \
				src/scene/ray_phong.c \
				src/scene/ray_utils.c \
				src/utils/main_utils.c \
				src/utils/setup_utils.c \
				src/utils/vec_utils_1.c \
				src/utils/vec_utils_2.c \
				src/utils/vec_utils_3.c \
				src/utils/vec_utils_4.c \

INC_DIR		=	include

LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
MLX_DIR		=	./mlx/

MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework Appkit

CC			=	gcc
C_INCS		= 	$(foreach include, $(INC_DIR), -I $(include))
CFLAGS		=	$(C_INCS) -Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

OBJ			=	$(SRC:.c=.o)

all : $(NAME) 

%.o : %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(MLX_FLAGS)
	@echo "$(NAME) is $(GRN)ready$(DFT)"

clean :
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJ)
	@echo "$(RED)cleaned$(DFT)"

fclean : clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)fcleaned$(DFT)"

re : clean all

PHONY	: all clean fclean re
