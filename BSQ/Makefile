GWW = gcc -Wall -Wextra -Werror
SRCS = check_map.c find_and_display.c find_map.c get_copy.c get_ch_map.c
OBJS = ${SRCS:.c=.o}
NAME = bsq

.c.o:
	${GWW} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${GWW} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean clean re
