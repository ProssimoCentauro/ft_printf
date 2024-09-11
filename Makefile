NAME = libftprintf.a

SRCS = ft_printf.c libc_utils.c print_functions.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar crs
RM = rm -rf

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	$(AR) $@ $^

all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
