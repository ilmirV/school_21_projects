#include "cub3d.h"

void	clear_textures(t_game *game)
{
	int	i;

	if (!(game->map && game->map->textures))
		return ;
	i = 0;
	while (i < 5)
	{
		if (game->map->textures[i])
			clear_image(game, &(game->map->textures[i]));
		i++;
	}
	free(game->map->textures);
	game->map->textures = NULL;
}

void	clear_image(t_game *game, t_img **img)
{
	if (*img)
	{
		mlx_destroy_image(game->mlx->mlx, (*img)->img);
		free(*img);
		*img = NULL;
	}
}

void	clear_player(t_game *game)
{
	if (!(game->player))
		return ;
	free(game->player);
	game->player = NULL;
}

void	clear_settings(t_game *game)
{
	if (!(game->sets))
		return ;
	if (game->sets->z_buf)
		free(game->sets->z_buf);
	free(game->sets);
	game->sets = NULL;
}

void	clear_mlx(t_game *game)
{
	if (!(game->mlx))
		return ;
	if (game->mlx->img)
		clear_image(game, &(game->mlx->img));
	if (game->mlx->mlx && game->mlx->win)
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	free(game->mlx);
	game->mlx = NULL;
}
