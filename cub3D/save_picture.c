#include "cub3d.h"

static void	write_header_1(t_game *game, int fd)
{
	int				i;
	unsigned char	header[14];

	i = 0;
	while (i < 14)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	i = game->sets->scr_w * game->sets->scr_h * 4 + 54;
	header[2] = (unsigned char)(i);
	header[3] = (unsigned char)(i >> 8);
	header[4] = (unsigned char)(i >> 16);
	header[5] = (unsigned char)(i >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

static void	write_header_2(t_game *game, int fd)
{
	int				i;
	unsigned char	header[40];

	i = 0;
	while (i < 40)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	i = game->sets->scr_w;
	header[4] = (unsigned char)(i);
	header[5] = (unsigned char)(i >> 8);
	header[6] = (unsigned char)(i >> 16);
	header[7] = (unsigned char)(i >> 24);
	i = game->sets->scr_h;
	header[8] = (unsigned char)(i);
	header[9] = (unsigned char)(i >> 8);
	header[10] = (unsigned char)(i >> 16);
	header[11] = (unsigned char)(i >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

static void	fill_color(t_game *game, int fd)
{
	int		i;
	char	*img;

	i = game->sets->scr_h;
	img = game->mlx->img->addr;
	while (--i)
		img += game->mlx->img->l_l;
	while (i < game->sets->scr_h)
	{
		write(fd, img, game->sets->scr_w * 4);
		img -= game->mlx->img->l_l;
		i++;
	}
}

int			save_picture(t_game *game)
{
	int	fd;

	fd = open("picture.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write_header_1(game, fd);
	write_header_2(game, fd);
	fill_color(game, fd);
	close(fd);
	return (1);
}
