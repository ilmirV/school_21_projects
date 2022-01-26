#include "cub3d.h"

static void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx->img->addr + (y * game->mlx->img->l_l +
		x * (game->mlx->img->b_p_p / 8));
	*(unsigned int *)dst = color;
}

static void	draw_map(t_game *game)
{
	int	x;
	int	ceil;
	int	floor;

	x = 0;
	while (x < game->sets->scr_w)
	{
		calculate_delta(game, x);
		calculate_side_dist(game);
		calculate_hit(game);
		calculate_wall(game);
		calculate_tex_x(game);
		ceil = 0;
		floor = game->ray->draw_end;
		while (ceil < game->ray->draw_start)
			my_mlx_pixel_put(game, x, ceil++, game->sets->ceil_color);
		draw_textures(game, x, game->ray->index);
		while (floor < game->sets->scr_h)
			my_mlx_pixel_put(game, x, floor++, game->sets->floor_color);
		game->sets->z_buf[x] = game->ray->p_w_d;
		x++;
	}
}

void		create_image(t_game *game)
{
	game->mlx->img = (t_img *)malloc(sizeof(t_img));
	game->mlx->img->img = mlx_new_image(game->mlx->mlx, game->sets->scr_w,
		game->sets->scr_h);
	game->mlx->img->addr = mlx_get_data_addr(game->mlx->img->img,
		&(game->mlx->img->b_p_p), &(game->mlx->img->l_l),
		&(game->mlx->img->endian));
	draw_map(game);
	draw_sprites(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->mlx->img->img, 0, 0);
}
