#include "cub3d.h"

static double	trans_xy(t_player *player, t_settings *sets, t_sprite *sorted)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trans_x;
	double	trans_y;

	sprite_x = sorted->pos_x - player->pos_x;
	sprite_y = sorted->pos_y - player->pos_y;
	inv_det = 1.0 / (player->plane_x * player->dir_y -
			player->dir_x * player->plane_y);
	trans_x = inv_det * (player->dir_y * sprite_x - player->dir_x * sprite_y);
	trans_y = inv_det * (-player->plane_y * sprite_x +
			player->plane_x * sprite_y);
	sorted->scr_x = (int)((sets->scr_w / 2) * (1 + trans_x / trans_y));
	sorted->spr_h = abs((int)((sets->scr_h / trans_y) * sets->diff));
	sorted->start_y = -sorted->spr_h / 2 + sets->scr_h / 2;
	sorted->end_y = sorted->spr_h / 2 + sets->scr_h / 2;
	sorted->spr_w = abs((int)((sets->scr_w / trans_y) / sets->coef));
	sorted->start_x = -sorted->spr_w / 2 + sorted->scr_x;
	if (sorted->start_x < 0)
		sorted->start_x = 0;
	sorted->end_x = sorted->spr_w / 2 + sorted->scr_x;
	if (sorted->end_x >= sets->scr_w)
		sorted->end_x = sets->scr_w;
	return (trans_y);
}

void			draw_sprites(t_game *game)
{
	int			stripe;
	t_sprite	*sorted;
	double		y;

	sorted = sort_sprites(game, game->map->sprites);
	while (sorted)
	{
		y = trans_xy(game->player, game->sets, sorted);
		stripe = sorted->start_x - 1;
		while (++stripe < sorted->end_x)
		{
			if (y > 0 && stripe >= 0 && stripe < game->sets->scr_w &&
					y < game->sets->z_buf[stripe])
			{
				sorted->tex_x = (int)((stripe - (-sorted->spr_w / 2 +
					sorted->scr_x)) * game->map->textures[4]->img_w /
						sorted->spr_w);
				game->ray->draw_start = sorted->start_y;
				game->ray->draw_end = sorted->end_y;
				game->ray->tex_x = sorted->tex_x;
				draw_textures(game, stripe, 4);
			}
		}
		sorted = sorted->sorted;
	}
}
