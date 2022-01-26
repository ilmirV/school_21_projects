#include "cub3d.h"

static	t_sprite	*sprt_add_sorted(t_sprite **sorted, t_sprite *sprite)
{
	t_sprite	*tmp;
	t_sprite	*prev;

	if (!*sorted)
		return ((*sorted = sprite));
	tmp = *sorted;
	prev = NULL;
	while (*sorted && sprite->dist < (*sorted)->dist)
	{
		prev = *sorted;
		*sorted = (*sorted)->sorted;
	}
	if (!prev)
	{
		sprite->sorted = *sorted;
		*sorted = sprite;
	}
	else
	{
		sprite->sorted = prev->sorted;
		prev->sorted = sprite;
		*sorted = tmp;
	}
	return (sprite);
}

t_sprite			*sort_sprites(t_game *game, t_sprite *sprites)
{
	t_sprite	*sorted;

	sorted = NULL;
	while (sprites)
	{
		sprites->dist = pow(game->player->pos_x - sprites->pos_x, 2) +
				pow(game->player->pos_y - sprites->pos_y, 2);
		sprites->sorted = NULL;
		sprt_add_sorted(&sorted, sprites);
		sprites = sprites->next;
	}
	return (sorted);
}
