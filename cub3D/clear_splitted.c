#include "cub3d.h"

int	clear_splitted(char ***splitted)
{
	char	**tmp;

	if (!splitted || !(*splitted))
		return (0);
	tmp = *splitted;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*splitted);
	(splitted = NULL);
	return (0);
}
