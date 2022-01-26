#include "cub3d.h"

static void	move_up_down(t_game *game)
{
	t_player	*player;
	char		**map;
	double		delta_x;
	double		delta_y;

	player = game->player;
	map = game->map->map;
	delta_x = player->dir_x * player->move_spd;
	delta_y = player->dir_y * player->move_spd;
	if (player->move_flag & W)
	{
		if (map[(int)(player->pos_x + delta_x * 2)][(int)player->pos_y] != '1')
			player->pos_x += delta_x;
		if (map[(int)player->pos_x][(int)(player->pos_y + delta_y * 2)] != '1')
			player->pos_y += delta_y;
	}
	if (player->move_flag & S)
	{
		if (map[(int)(player->pos_x - delta_x * 2)][(int)player->pos_y] != '1')
			player->pos_x -= delta_x;
		if (map[(int)player->pos_x][(int)(player->pos_y - delta_y * 2)] != '1')
			player->pos_y -= delta_y;
	}
}

static void	move_left_right(t_game *game)
{
	t_player	*player;
	char		**map;
	double		delta_x;
	double		delta_y;

	player = game->player;
	map = game->map->map;
	delta_x = player->dir_y * player->move_spd;
	delta_y = player->dir_x * player->move_spd;
	if (player->move_flag & D)
	{
		if (map[(int)(player->pos_x - delta_x * 2)][(int)player->pos_y] != '1')
			player->pos_x -= delta_x;
		if (map[(int)player->pos_x][(int)(player->pos_y + delta_y * 2)] != '1')
			player->pos_y += delta_y;
	}
	else if (player->move_flag & A)
	{
		if (map[(int)(player->pos_x + delta_x * 2)][(int)player->pos_y] != '1')
			player->pos_x += delta_x;
		if (map[(int)player->pos_x][(int)(player->pos_y - delta_y * 2)] != '1')
			player->pos_y -= delta_y;
	}
}

static void	rotate_left(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(player->rot_spd) -
		player->dir_y * sin(player->rot_spd);
	player->dir_y = player->old_dir_x * sin(player->rot_spd) +
		player->dir_y * cos(player->rot_spd);
	player->old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->rot_spd) -
		player->plane_y * sin(player->rot_spd);
	player->plane_y = player->old_plane_x * sin(player->rot_spd) +
		player->plane_y * cos(player->rot_spd);
}

static void	rotate_right(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-player->rot_spd) -
		player->dir_y * sin(-player->rot_spd);
	player->dir_y = player->old_dir_x * sin(-player->rot_spd) +
		player->dir_y * cos(-player->rot_spd);
	player->old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-player->rot_spd) -
		player->plane_y * sin(-player->rot_spd);
	player->plane_y = player->old_plane_x * sin(-player->rot_spd) +
		player->plane_y * cos(-player->rot_spd);
}

int			movements(t_game *game)
{
	if (game->player->move_flag & W || game->player->move_flag & S)
		move_up_down(game);
	if (game->player->move_flag & A || game->player->move_flag & D)
		move_left_right(game);
	if (game->player->move_flag & L)
		rotate_left(game);
	if (game->player->move_flag & R)
		rotate_right(game);
	mlx_destroy_image(game->mlx->mlx, game->mlx->img->img);
	free(game->mlx->img);
	create_image(game);
	return (0);
}
