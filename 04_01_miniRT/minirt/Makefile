#--------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
MLX				= libmlx.dylib
NAME			= miniRT

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries (Can be changed).

LFT_DIR			= libft
LMLX_DIR		= mlx

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= include
INCS_DIR		+= libft
INCS_DIR		+= mlx

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= hook
OBJS_SUBDIRS	+= object
OBJS_SUBDIRS	+= scene
OBJS_SUBDIRS	+= utils

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)
LMLX			= $(LMLX_DIR)/$(MLX)

# Used header at each compilation to check file integrity (Can be changed).

INCS			=	include/minirt.h \
					include/mlx_hook.h \
					include/mlx_key.h \
					include/objects.h \
					include/ray.h \
					include/scene.h \
					include/structs.h \
					include/utils.h

# Source files (Can be changed)

SRCS_MANDA		=	core/main.c \
					hook/create.c \
					hook/destroy.c \
					hook/hook_1.c \
					hook/hook_2.c \
					hook/hook_3.c \
					hook/hook_utils.c \
					hook/msg_loop.c \
					object/hit_cy_1.c \
					object/hit_cy_2.c \
					object/hit_pl.c \
					object/hit_sp.c \
					object/hit.c \
					object/obj_setup_1.c \
					object/obj_setup_2.c \
					object/obj_utils_1.c \
					object/obj_utils_2.c \
					scene/graphic_render.c \
					scene/graphic_setup.c \
					scene/graphic_utils.c \
					scene/ray_color.c \
					scene/ray_phong.c \
					scene/ray_utils.c \
					scene/scene_setup_1.c \
					scene/scene_setup_2.c \
					scene/scene_utils_1.c \
					scene/scene_utils_2.c \
					utils/main_utils.c \
					utils/setup_utils.c \
					utils/vec_utils_1.c \
					utils/vec_utils_2.c \
					utils/vec_utils_3.c \
					utils/vec_utils_4.c \

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS_MANDA	= $(addprefix $(D_OBJS), $(OBJS_MANDA))
C_OBJS_BONUS	= $(addprefix $(D_OBJS), $(OBJS_BONUS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

ifeq ($(BONUS_FLAG),1)
	C_OBJS		= $(C_OBJS_BONUS)
else
	C_OBJS		= $(C_OBJS_MANDA)
endif

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= cc
OBJS_MANDA		= $(SRCS_MANDA:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

# Linked libraries at compile time (Can be changed).

LIBS			:= -L$(LFT_DIR) -lft
LIBS			+= -L$(LMLX_DIR) -lmlx
LIBS			+= -lm

# Compilation flags (Can be changed).

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

bonus:
	@make BONUS_FLAG=1

$(NAME): $(LFT) $(LMLX) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@install_name_tool -change $(MLX) $(LMLX) $(NAME)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installion using their own Makefile (Can be changed).

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LMLX):
	@make -sC $(LMLX_DIR)

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files. (Can't be changed).

clean:
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

# Deleting all executables and libraries after cleaning up
# all .o files (Can't be changed).

fclean:
	@make clean
	@make -sC $(LFT_DIR) fclean
	@make -sC $(LMLX_DIR) clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-build libs (Can't be changed).

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@install_name_tool -change $(MLX) $(LMLX) $(NAME)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
