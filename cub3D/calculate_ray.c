#include "cub3d.h"

void	calculate_delta(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)(game->sets->scr_w) - 1;
	game->ray->ray_dir_x = game->player->dir_x +
		game->player->plane_x * camera_x;
	game->ray->ray_dir_y = game->player->dir_y +
		game->player->plane_y * camera_x;
	game->ray->map_x = (int)(game->player->pos_x);
	game->ray->map_y = (int)(game->player->pos_y);
	game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
	game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
}

void	calculate_side_dist(t_game *game)
{
	if (game->ray->ray_dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->player->pos_x -
			game->ray->map_x) * game->ray->delta_dist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = (game->ray->map_x + 1.0 -
			game->player->pos_x) * game->ray->delta_dist_x;
	}
	if (game->ray->ray_dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->player->pos_y -
			game->ray->map_y) * game->ray->delta_dist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = (game->ray->map_y + 1.0 -
			game->player->pos_y) * game->ray->delta_dist_y;
	}
}

void	calculate_hit(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_dist_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_dist_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map->map[game->ray->map_x][game->ray->map_y] == '1')
			hit = 1;
	}
}

void	calculate_wall(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->p_w_d = (game->ray->map_x - game->player->pos_x +
		(1 - game->ray->step_x) / 2) / game->ray->ray_dir_x;
	else
		game->ray->p_w_d = (game->ray->map_y - game->player->pos_y +
		(1 - game->ray->step_y) / 2) / game->ray->ray_dir_y;
	game->ray->line_height = (int)(game->sets->scr_h / game->ray->p_w_d * 0.8);
	if (game->sets->scr_w > game->sets->scr_h)
	{
		game->sets->diff = 1.0 * game->sets->scr_w / game->sets->scr_h;
		game->ray->line_height *= game->sets->diff;
		game->ray->line_height = (int)game->ray->line_height;
	}
	game->ray->draw_start = -game->ray->line_height / 2 +
		game->sets->scr_h / 2;
	game->ray->draw_end = game->ray->line_height / 2 +
		game->sets->scr_h / 2;
	if (game->ray->side == 0 && game->ray->ray_dir_x < 0)
		game->ray->index = 0;
	else if (game->ray->side == 0 && game->ray->ray_dir_x > 0)
		game->ray->index = 1;
	else if (game->ray->side == 1 && game->ray->ray_dir_y < 0)
		game->ray->index = 2;
	else if (game->ray->side == 1 && game->ray->ray_dir_y > 0)
		game->ray->index = 3;
}

void	calculate_tex_x(t_game *game)
{
	double	wall_x;

	if (game->ray->side == 0)
		wall_x = game->player->pos_y + game->ray->p_w_d *
			game->ray->ray_dir_y;
	else
		wall_x = game->player->pos_x + game->ray->p_w_d *
			game->ray->ray_dir_x;
	game->ray->tex_x = (wall_x * 100);
	game->ray->tex_x %= 100;
	if (game->ray->index == 0)
		game->ray->tex_x /= (double)(100.0 / game->map->textures[0]->img_w);
	else if (game->ray->index == 1)
		game->ray->tex_x /= (double)(100.0 / game->map->textures[1]->img_w);
	else if (game->ray->index == 2)
		game->ray->tex_x /= (double)(100.0 / game->map->textures[2]->img_w);
	else if (game->ray->index == 3)
		game->ray->tex_x /= (double)(100.0 / game->map->textures[3]->img_w);
}
