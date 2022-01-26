#include "cub3d.h"

static t_list	*read_file(char *filename)
{
	t_list	*file;
	int		fd;
	char	*line;
	t_list	*tmp;

	file = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_lstnew((void *)line);
		ft_lstadd_back(&file, tmp);
	}
	tmp = ft_lstnew((void *)line);
	ft_lstadd_back(&file, tmp);
	close(fd);
	return (file);
}

static t_map	*init_map(t_game *game)
{
	int		i;
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->map = NULL;
	map->sprites = NULL;
	if (!(map->tex_path = (char **)malloc(sizeof(char *) * 5)))
	{
		clear_map(game);
		return (NULL);
	}
	i = 0;
	while (i++ < 5)
		map->tex_path[i - 1] = NULL;
	if (!(map->textures = (t_img **)malloc(sizeof(t_img *) * 5)))
	{
		clear_map(game);
		return (NULL);
	}
	i = 0;
	while (i++ < 5)
		map->textures[i - 1] = NULL;
	return (map);
}

static t_map	*abort_l(t_game *game, t_list *file)
{
	clear_textures(game);
	clear_map(game);
	clear_file(file);
	return (NULL);
}

t_map			*load_file(t_game *game, char *filename)
{
	t_list	*file;

	file = read_file(filename);
	if (!file)
		return (NULL);
	if (!(game->map = init_map(game)))
	{
		clear_file(file);
		return (NULL);
	}
	if (parse_map(game, file) && get_player_position(game) &&
		validate_map(game, game->map))
	{
		free(game->sets->z_buf);
		game->sets->z_buf = ft_calloc(game->sets->scr_w, sizeof(double));
		get_sprites(game);
		clear_file(file);
		return (game->map);
	}
	else
		return (abort_l(game, file));
}
