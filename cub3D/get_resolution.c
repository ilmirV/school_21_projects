#include "cub3d.h"

int			check_params(char **number)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (number[i++])
	{
		j = 0;
		while ((j < (int)ft_strlen(number[i - 1]) - 1) &&
				(number[i - 1][j] == '0' || number[i - 1][j] == ' '))
			j++;
		if (ft_strlen(number[i - 1] + j) > 6)
			number[i - 1][j + 5] = '\0';
		count = 0;
		while (number[i - 1][j++])
		{
			if (!ft_isdigit(number[i - 1][j - 1]))
				return (-1);
			if (ft_isdigit(number[i - 1][j - 1]))
				count++;
		}
		if (count == 0)
			return (-1);
	}
	return (0);
}

void		is_save(t_game *game, int width, int height)
{
	if (game->sets->save)
	{
		game->sets->scr_w = width > 17000 ? 17000 : width;
		game->sets->scr_h = height > 17000 ? 17000 : height;
		if (game->sets->scr_w < game->sets->scr_h)
			game->sets->coef = 1.0 * game->sets->scr_w / game->sets->scr_h;
	}
	else
	{
		game->sets->scr_w =
			width < game->sets->scr_w ? width : game->sets->scr_w;
		game->sets->scr_h =
			height < game->sets->scr_h ? height : game->sets->scr_h;
		if (game->sets->scr_w < game->sets->scr_h)
			game->sets->coef = 1.0 * game->sets->scr_w / game->sets->scr_h;
	}
}

int			get_resolution(t_game *game, char *line)
{
	char	**sizes;
	int		width;
	int		height;

	if (!line)
		return (0);
	game->sets->parse_finds++;
	sizes = ft_split(line + 2, ' ');
	if (!sizes || count_splitted(sizes) != 2)
	{
		clear_splitted(&sizes);
		return (exit_game_2(game, -13));
	}
	if (check_params(sizes) == -1)
	{
		clear_splitted(&sizes);
		return (exit_game_2(game, -15));
	}
	width = ft_atoi(sizes[0]);
	height = ft_atoi(sizes[1]);
	clear_splitted(&sizes);
	if (width <= 0 || height <= 0)
		return (exit_game(game, -9));
	is_save(game, width, height);
	return (1);
}
