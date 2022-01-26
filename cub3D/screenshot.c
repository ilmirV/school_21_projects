#include "cub3d.h"

int	screenshot(t_game *game)
{
	game->mlx->mlx = mlx_init();
	load_textures(game);
	game->mlx->win = mlx_new_window(game->mlx->mlx,
			game->sets->scr_w, game->sets->scr_h, "Fake 3D");
	create_image(game);
	save_picture(game);
	clear_game(&game);
	ft_printf("Screenshot saved\n");
	return (0);
}
