#include "cub3d.h"

static t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	return (mlx);
}

static t_settings	*init_sets(void)
{
	t_settings	*sets;

	if (!(sets = (t_settings *)malloc(sizeof(t_settings))))
		return (NULL);
	sets->scr_w = 800;
	sets->scr_h = 600;
	sets->ceil_color = 0x69CCE2;
	sets->floor_color = 0x6B3714;
	sets->z_buf = ft_calloc(sets->scr_w, sizeof(double));
	sets->parse_finds = 0;
	sets->save = 0;
	sets->coef = 1.0;
	sets->diff = 1.0;
	return (sets);
}

static t_player		*init_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->pos_x = 5.6;
	player->pos_y = 7.2;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->rot_spd = 0.04;
	player->move_spd = 0.1;
	player->move_flag = 0;
	player->count = 0;
	return (player);
}

static t_raycast	*init_raycast(void)
{
	t_raycast	*ray;

	if (!(ray = (t_raycast *)malloc(sizeof(t_raycast))))
		return (NULL);
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->p_w_d = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	return (ray);
}

t_game				*init_game(void)
{
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	if (!(game->mlx = init_mlx()))
		return (NULL);
	game->mlx->mlx = mlx_init();
	if (!(game->sets = init_sets()))
		return (NULL);
	if (!(game->player = init_player()))
		return (NULL);
	game->map = NULL;
	game->ray = init_raycast();
	return (game);
}
