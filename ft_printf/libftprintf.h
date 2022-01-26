#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	int		flag;
	int		width;
	int		precision;
	char	type;
	int		sign;
}				t_arg;
int				ft_printf(const char *fmt, ...);
int				ft_parse(char **fmt, va_list ap);
t_arg			*ft_new_arg(char **fmt, va_list ap);
int				ft_get_flag(char **fmt);
int				ft_get_width(char **fmt, va_list ap);
int				ft_get_precision(char **fmt, va_list ap);
char			ft_get_type(char **fmt);
int				ft_get_number(char **fmt);
int				ft_print_char(t_arg *arg, va_list ap);
int				ft_print_str(t_arg *arg, va_list ap);
int				ft_print_signed(t_arg *arg, va_list ap);
int				ft_print_unsigned(t_arg *arg, va_list ap);
char			*ft_uitoa(unsigned int n);
char			*ft_xitoa(unsigned int num, t_arg *arg);
int				ft_print_ptr(t_arg *arg, va_list ap);
char			*ft_sitoa(int n);
char			*ft_luitoa(unsigned long int num);
int				ft_print_percent(t_arg *arg);
int				ft_print_number(t_arg *arg, char *tmp, int *length);
char			*ft_str_join(char const *s1, char const *s2);
char			*ft_str_cut(char const *s, unsigned int start, size_t len,
				int *flag);

#endif
