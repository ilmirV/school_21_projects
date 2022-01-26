#include "cub3d.h"

static int	is_hole(char c)
{
	return (c == ' ' || c == 0);
}

static int	is_floor(char c)
{
	return (c == '0' || c == '2' ||
			c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

static int	validate_v(t_game *game, t_map *map)
{
	char	cur;
	char	prev;
	int		i;
	int		j;

	i = 0;
	while (i < map->map_w)
	{
		j = 1;
		prev = map->map[0][i];
		while (j < map->map_h)
		{
			cur = map->map[j][i];
			if ((is_hole(prev) && is_floor(cur)) ||
					(is_hole(cur) && is_floor(prev)) ||
					(is_floor(cur) && j == map->map_h - 1) ||
					(is_floor(prev) && j == 1))
				return (error_map_line(game, j, map->map[j], 'v'));
			prev = cur;
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_h(t_game *game, t_map *map)
{
	char	cur;
	char	prev;
	int		i;
	int		j;

	i = 0;
	while (i < map->map_h)
	{
		j = 1;
		prev = map->map[i][0];
		while (j < map->map_w)
		{
			cur = map->map[i][j];
			if ((is_hole(prev) && is_floor(cur)) ||
					(is_hole(cur) && is_floor(prev)) ||
					(is_floor(prev) && j == 1))
				return (error_map_line(game, i, map->map[i], 'h'));
			prev = cur;
			j++;
		}
		i++;
	}
	return (1);
}

int			validate_map(t_game *game, t_map *map)
{
	return (validate_h(game, map) && validate_v(game, map));
}
