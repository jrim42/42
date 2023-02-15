NAME		=	ft_container

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f

SRC			=	src/test_vector.cpp \
				# src/main.cpp \
				
OBJ			=	$(SRC:.cpp=.o)

all : $(NAME) 

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)
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