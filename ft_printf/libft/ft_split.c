#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			wc++;
		s++;
	}
	return (wc);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static void		*ft_leaks(char **splitted, int words)
{
	while (words--)
		free(*(splitted++));
	free(splitted);
	return (NULL);
}

static char		**ft_fill(const char *s, int words, char c, char **splitted)
{
	int		i;
	size_t	j;
	size_t	len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = ft_word_len(s, c);
		if (!(splitted[i] = (char*)malloc(sizeof(char) * (len + 1))))
			return (ft_leaks(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *s++;
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char			**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = ft_words_count(s, c);
	if (!(splitted = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	splitted = ft_fill(s, wc, c, splitted);
	return (splitted);
}
