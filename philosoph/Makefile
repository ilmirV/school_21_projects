SRCS =		philo.c \
			utils.c \
			print_error.c \
			activities.c \
			print_status.c \
			watcher.c \
			parser.c

OBJS =		$(SRCS:.c=.o)

INCL =		philo.h

NAME =		philo

GCC =		gcc
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(INCL)
			$(GCC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
