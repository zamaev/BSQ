INC_DIR	= includes/

SRC_DIR	= srcs/

SRC_F	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRCS	= $(foreach sfn,${SRC_F},${SRC_DIR}${sfn})

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

FLAGS	= -Wall -Werror -Wextra

.c.o:
		gcc ${FLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm ${NAME}

re:		fclean all
