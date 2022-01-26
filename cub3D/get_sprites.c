#include "cub3d.h"

static t_sprite	*sprt_new(int x, int y)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	sprite->next = NULL;
	sprite->sorted = NULL;
	sprite->pos_x = x + 0.5;
	sprite->pos_y = y + 0.5;
	sprite->dist = 0.0;
	return (sprite);
}

static void		sprt_add_front(t_sprite **list, t_sprite *new)
{
	if (*list)
	{
		new->next = *list;
		*list = new;
	}
	else
		*list = new;
}

void			get_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	*sprites;

	sprites = NULL;
	i = 0;
	while (i < game->map->map_h)
	{
		j = 0;
		while (j < game->map->map_w)
		{
			if (game->map->map[i][j] == '2')
				sprt_add_front(&sprites, sprt_new(i, j));
			j++;
		}
		i++;
	}
	game->map->sprites = sprites;
}
