#include "cub3d.h"

void	clear_sprites(t_game *game)
{
	t_sprite	*tmp1;
	t_sprite	*tmp2;

	if (!(game->map->sprites))
		return ;
	tmp1 = game->map->sprites;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	game->map->sprites = NULL;
}

void	clear_array(t_game *game)
{
	int i;

	if (!(game->map->map))
		return ;
	i = 0;
	while (i < game->map->map_h)
	{
		if (game->map->map[i])
			free(game->map->map[i]);
		i++;
	}
	free(game->map->map);
	game->map->map = NULL;
}

void	clear_map(t_game *game)
{
	int i;

	if (!(game->map))
		return ;
	clear_sprites(game);
	clear_array(game);
	if (game->map->tex_path)
	{
		i = 0;
		while (i < 5)
		{
			if (game->map->tex_path[i])
				free(game->map->tex_path[i]);
			i++;
		}
		free(game->map->tex_path);
	}
	free(game->map);
	game->map = NULL;
}

void	clear_game(t_game **game)
{
	if (*game)
	{
		clear_textures(*game);
		clear_map(*game);
		clear_player(*game);
		clear_settings(*game);
		clear_mlx(*game);
		free(*game);
		*game = NULL;
	}
}
