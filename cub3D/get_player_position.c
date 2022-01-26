#include "cub3d.h"

static void	set_player(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66 * game->sets->coef;
		if (c == 'N')
			game->player->dir_x *= -1;
		if (c == 'S')
			game->player->plane_y *= -1;
	}
	else if (c == 'W' || c == 'E')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = 0.66 * game->sets->coef;
		game->player->plane_y = 0;
		if (c == 'W')
		{
			game->player->dir_y *= -1;
			game->player->plane_x *= -1;
		}
	}
}

static int	player_position(t_game *game, int i, int j, char c)
{
	if (c && ft_strchr("NEWS", c))
	{
		set_player(game, c);
		game->player->pos_x = i + 0.5;
		game->player->pos_y = j + 0.5;
		game->player->count += 1;
	}
	return (0);
}

int			get_player_position(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < game->map->map_h)
	{
		j = 0;
		while (j < game->map->map_w)
		{
			c = game->map->map[i][j];
			if ((player_position(game, i, j, c)) == -1)
				return (0);
			j++;
		}
		i++;
	}
	if (game->player->count > 1)
		return (exit_game(game, -6));
	if (game->player->count == 0)
		return (exit_game(game, -8));
	return (1);
}
