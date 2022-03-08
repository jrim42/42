# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:14:48 by jrim              #+#    #+#              #
#    Updated: 2022/03/08 16:29:08 by jrim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	so_long

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

LIB_DIR	= 	./libft/
LIB_A	= 	libft.a
LIB 	=	$(addprefix $(LIB_DIR), $(LIB_A))

RED		=	\033[0;31m
GRN		= 	\033[0;32m
YLW		=	\033[0;33m
BLU		= 	\033[0;36m
DFT		= 	\033[0;37m

SRC		= 	src/*.c
OBJ		= 	$(SRC:.c=.o)

all : $(LIB_A) $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A) :
	@$(MAKE) -C $(LIB_DIR)

$(NAME) : $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(NAME) is $(GRN)ready$(DFT)" 

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)
	@echo "$(RED)cleaned$(DFT)"

fclean : clean
	@$(MAKE) fclean -C $(LIB_DIR) 
	@rm -f $(NAME)
	@echo "$(RED)fcleaned$(DFT)"

re : fclean all

.PHONY : all clean fclean re bonus