#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 21
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

#endif
