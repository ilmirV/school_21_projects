#include "cub3d.h"

int	error_map_line(t_game *game, int i, char *line, char key)
{
	ft_printf("Error\n");
	ft_printf("Wrong map line: %d: \n", i, line);
	if (key == 'v')
		ft_printf("vertical\n");
	else
		ft_printf("horizontal\n");
	if (game)
		clear_game(&game);
	exit(-16);
}
