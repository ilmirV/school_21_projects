#include "cub3d.h"

static void	my_texel_put(t_game *game, int x, int y, int index)
{
	char	*src;
	char	*dst;
	int		tx;
	int		ty;

	src = NULL;
	dst = game->mlx->img->addr + (y * game->mlx->img->l_l +
			x * (game->mlx->img->b_p_p / 8));
	tx = game->ray->tex_x;
	ty = game->ray->tex_y;
	src = game->map->textures[index]->addr +
		(ty * game->map->textures[index]->l_l +
		tx * (game->map->textures[index]->b_p_p / 8));
	if (index == 4)
		if (*(unsigned int *)src == 0x000000)
			return ;
	*(unsigned int *)dst = *(unsigned int *)src;
}

void		draw_textures(t_game *game, int x, int index)
{
	double	coef;
	double	start;
	double	y;

	coef = (double)(game->ray->draw_end - game->ray->draw_start) /
		(double)(game->map->textures[index]->img_h);
	start = -1;
	if (game->ray->draw_start + start < 0)
	{
		start += abs(game->ray->draw_start);
		game->ray->draw_start = 0;
	}
	y = 0;
	while (game->ray->draw_start <= game->ray->draw_end)
	{
		y = ++start / coef;
		if ((int)y == game->map->textures[index]->img_h)
			y = game->map->textures[index]->img_h - 1;
		if (game->ray->draw_start >= game->sets->scr_h)
			break ;
		game->ray->tex_y = (int)y;
		my_texel_put(game, x, game->ray->draw_start++, index);
	}
}
