#include "cub3d.h"

static t_img	*load_texture(t_game *game, char *filename)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = game->mlx;
	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx->mlx, filename, &(img->img_w),
			&(img->img_h));
	if (!(img->img))
	{
		free(img);
		exit_game(game, -3);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->b_p_p), &(img->l_l),
			&(img->endian));
	return (img);
}

static int		abort_l(t_game *game)
{
	clear_textures(game);
	return (0);
}

int				load_textures(t_game *game)
{
	t_img	*img;
	int		i;

	i = 0;
	while (i < 5)
	{
		img = load_texture(game, game->map->tex_path[i]);
		if (!img)
			return (abort_l(game));
		game->map->textures[i] = img;
		i++;
	}
	return (1);
}
