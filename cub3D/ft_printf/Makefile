SRCS	=	ft_printf.c			\
			ft_parse.c			\
			ft_new_arg.c		\
			ft_get_flag.c		\
			ft_get_width.c		\
			ft_get_precision.c	\
			ft_get_type.c		\
			ft_get_number.c		\
			ft_print_char.c		\
			ft_print_str.c		\
			ft_print_signed.c	\
			ft_print_unsigned.c	\
			ft_uitoa.c			\
			ft_xitoa.c			\
			ft_print_ptr.c		\
			ft_str_join.c		\
			ft_str_cut.c		\
			ft_sitoa.c			\
			ft_luitoa.c			\
			ft_print_number.c	\
			ft_print_percent.c	\

HEAD	=	libftprintf.h

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft

NAME	=	libftprintf.a

GCC		=	gcc
RM		=	rm -f
LIB		=	ar rc

CFLAGS	=	-Wall -Wextra -Werror

OBJS_2	=	libft/*.o

all:		$(NAME)

.c.o:		
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEAD) $(OBJS_2)
			$(LIB) $(NAME) $(OBJS) libft/*.o
			ranlib $(NAME)

$(OBJS_2):	
			make -C "$(LIBFT)"
			make bonus -C "$(LIBFT)"

clean:		
			$(RM) $(OBJS)
			make clean -C "$(LIBFT)"

fclean:		clean
			$(RM) $(NAME)
			 make fclean -C "$(LIBFT)"

re:			fclean all

bonus:

.PHONY:		all clean fclean re bonus
