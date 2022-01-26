#include "get_next_line.h"

char	*str_trim(char *s)
{
	char	*buff;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*get_remainder(char *s)
{
	char	*buff;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (!(buff = malloc(sizeof(char) * (gnl_strlen(s) - i))))
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		buff[j++] = s[i++];
	buff[j] = '\0';
	free(s);
	return (buff);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buff;
	int			ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!gnl_strchr(str, '\n') && ret != 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		str = gnl_strjoin(str, buff);
	}
	free(buff);
	*line = str_trim(str);
	str = get_remainder(str);
	return ((ret == 0) ? 0 : 1);
}
