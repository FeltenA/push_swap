DIRP	=	src_push_swap

SRCSP	=	${DIRP}/push_swap.c\
			${DIRP}/parse_input.c\
			${DIRP}/sort_simple.c\
			${DIRP}/sort_complex.c\
			${DIRP}/sort_utils.c\
			${DIRP}/sort_utils2.c\
			${DIRP}/chunk_utils.c\
			${DIRP}/str_utils.c\
			${DIRP}/commands.c\
			${DIRP}/run_commands.c\
			${DIRP}/list_utils.c\
			${DIRP}/quick_sort.c\
			${DIRP}/median.c\
			${DIRP}/quick_sort_utils.c

DIRC	=	src_checker

SRCSC	=	${DIRC}/checker.c\
			${DIRC}/parse_input.c\
			${DIRC}/commands.c\
			${DIRC}/commands_utils.c\
			${DIRC}/get_next_line.c\
			${DIRC}/get_next_line_utils.c\
			${DIRC}/list_utils.c\
			${DIRC}/run_commands.c\
			${DIRC}/str_utils.c

OBJSP	= ${SRCSP:.c=.o}

OBJSC	= ${SRCSC:.c=.o}

HEAD	= includes

NAME	= push_swap

NAMEC	= checker

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:		%.c
		${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJSP}
		gcc ${OBJSP} -o ${NAME}

${NAMEC}:	${OBJSC}
		gcc	${OBJSC} -o ${NAMEC}

bonus:		${NAME} ${NAMEC}

all:		${NAME}

clean:
		${RM} ${OBJSP} ${OBJSC}

fclean:		clean
		${RM} ${NAME} ${NAMEC}

re:		fclean
		make all

.PHONY:		all clean fclean re bonus
