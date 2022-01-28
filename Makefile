NAME	= push_swap

NAME_BONUS = checker

HEAD	= push_swap.h

LIBFT_PATH	= ./libft/

LIBFT	= ${LIBFT_PATH}libft.a

FUNC	= argv_check.c indexation.c lib_for_stack.c main_file.c \
			operation.c sort_less_five.c sorting.c utils_for_sorting.c

BONUS_FUNC	= checker.c get_next_line_utils.c get_next_line.c operation.c \
			checker_utils.c lib_for_stack.c  argv_check.c

OBJS	= ${FUNC:.c=.o}

BONUS_OBJS = ${BONUS_FUNC:.c=.o}

CC	= gcc

CFLAGS 	= -Wall -Wextra -Werror

RM	= rm -rf

.PHONY: all clean fclean re bonus

all:	${NAME} ${NAME_BONUS}

${LIBFT} :
			@ ${MAKE} -sC ${LIBFT_PATH}

${NAME} :	${LIBFT} ${OBJS} ${HEAD}
			@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}


${NAME_BONUS}:  ${LIBFT} ${BONUS_OBJS} ${HEAD}
				@${CC} ${CFLAGS} ${LIBFT} ${BONUS_OBJS} -o ${NAME_BONUS}

clean	:
			${RM} ${OBJS} ${BONUS_OBJS}
			@ ${MAKE} -C ${LIBFT_PATH} clean

fclean	:	clean
			${RM} ${NAME} ${NAME_BONUS}
			@ ${MAKE} -C ${LIBFT_PATH} fclean

re		:	fclean all