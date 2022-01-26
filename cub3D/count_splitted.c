#include "cub3d.h"

int	count_splitted(char **splitted)
{
	int	number;

	number = 0;
	while (splitted[number])
		number++;
	return (number);
}
