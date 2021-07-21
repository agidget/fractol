NAME	= fractol
LIB		= libmlx.dylib
CC		= gcc
HEADER	= fractol.h
SRCS	= *.c
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra
OBJS	= *.o

all:		${NAME}

$(NAME):	$(SRCS) $(HEADER)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			clean all
.PHONY:		all clean fclean re