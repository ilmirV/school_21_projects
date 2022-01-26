#include "cub3d.h"

static int	check_params_2(t_game *game, char **colors)
{
	int		i;
	char	**num;

	i = 0;
	while (colors[i])
	{
		if (colors[i][ft_strlen(colors[i]) - 1] == ' ')
			return (exit_game_2(game, -17));
		num = ft_split(colors[i], ' ');
		if (!num || count_splitted(num) != 1)
		{
			clear_splitted(&num);
			return (exit_game_2(game, -14));
		}
		clear_splitted(&num);
		i++;
	}
	return (0);
}

static int	get_color(t_game *game, char *line)
{
	char	**colors;
	int		red;
	int		green;
	int		blue;

	colors = ft_split(line + 2, ',');
	if (!colors || count_splitted(colors) != 3)
	{
		clear_splitted(&colors);
		return (exit_game_2(game, -12));
	}
	check_params_2(game, colors);
	if (check_params(colors) == -1)
	{
		clear_splitted(&colors);
		return (exit_game_2(game, -14));
	}
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255 ||
			blue < 0 || blue > 255)
		return (clear_splitted(&colors) - 1);
	clear_splitted(&colors);
	return (red << 16 | green << 8 | blue);
}

static int	get_ceil_color(t_game *game, char *line)
{
	int		color;

	game->sets->parse_finds++;
	if (!count_commas(line))
		return (exit_game_2(game, -12));
	color = get_color(game, line);
	if (color == -1)
		return (exit_game_2(game, -11));
	game->sets->ceil_color = color;
	return (1);
}

static int	get_floor_color(t_game *game, char *line)
{
	int		color;

	game->sets->parse_finds++;
	if (!count_commas(line))
		return (exit_game_2(game, -12));
	color = get_color(game, line);
	if (color == -1)
		return (exit_game_2(game, -11));
	game->sets->floor_color = color;
	return (1);
}

int			get_colors(t_game *game, char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		get_floor_color(game, line);
	else if (!ft_strncmp(line, "C ", 2))
		get_ceil_color(game, line);
	return (1);
}
