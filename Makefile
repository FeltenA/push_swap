SRCS	=	push_swap.c\
			parse_input.c\
			sort_simple.c\
			sort_complex.c\
			sort_utils.c\
			sort_utils2.c\
			chunk_utils.c\
			str_utils.c\
			commands.c\
			run_commands.c\
			list_utils.c\
			test.c

OBJS	= ${SRCS:.c=.o}

HEAD	= includes

NAME	= push_swap

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:		%.c
		${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
		gcc ${OBJS} -o ${NAME}

all:		${NAME}

clean:
		${RM} ${OBJS} ${OBJSB}

fclean:		clean
		${RM} ${NAME}

re:		fclean
		make all

.PHONY:		all clean fclean re
