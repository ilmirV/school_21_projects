#include "cub3d.h"

static int	is_valid_line(t_game *game, char *line)
{
	char	*tmp;
	int		count;

	if (!(*line))
		return (0);
	tmp = line;
	count = 0;
	while (*tmp)
	{
		if (!(ft_strchr("NEWS012 ", *tmp)))
		{
			read_line(game, line);
			return (0);
		}
		tmp++;
	}
	if (game->sets->parse_finds == 8)
		return (1);
	if (game->sets->parse_finds > 8)
		return (exit_game(game, -5));
	read_line(game, line);
	return (0);
}

static int	get_map_size(t_list *file, t_list **map_begin, t_game *game)
{
	t_list	*tmp;
	int		size;

	tmp = file;
	while (tmp && !is_valid_line(game, (char *)(tmp->content)))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	*map_begin = tmp;
	game->map->map_h = 0;
	game->map->map_w = ft_strlen((char *)(tmp->content));
	while (tmp && is_valid_line(game, (char *)(tmp->content)))
	{
		size = ft_strlen((char *)(tmp->content));
		game->map->map_w = size > game->map->map_w ? size : game->map->map_w;
		game->map->map_h++;
		tmp = tmp->next;
	}
	if (tmp)
		tmp = tmp->next;
	if (tmp)
		return (exit_game(game, -7));
	return (1);
}

static int	abort_l(char **array, t_game *game)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < game->map->map_h)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	}
	return (0);
}

int			parse_map(t_game *game, t_list *file)
{
	t_list	*map_begin;
	t_list	*tmp;
	char	**map_array;
	int		i;

	if (!get_map_size(file, &map_begin, game))
		return (0);
	if (!(map_array = (char **)malloc(sizeof(char *) * game->map->map_h)))
		return (0);
	tmp = map_begin;
	i = 0;
	while (i++ < game->map->map_h)
		map_array[i - 1] = NULL;
	i = 0;
	while (i < game->map->map_h)
	{
		if (!(map_array[i] = ft_calloc(game->map->map_w + 1, sizeof(char))))
			return (abort_l(map_array, game));
		ft_strcpy(map_array[i], (char *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
	game->map->map = map_array;
	return (1);
}
