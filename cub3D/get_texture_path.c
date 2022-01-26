#include "cub3d.h"

static int	get_index(char *key)
{
	if (!ft_strcmp(key, "NO "))
		return (0);
	else if (!ft_strcmp(key, "SO "))
		return (1);
	else if (!ft_strcmp(key, "WE "))
		return (2);
	else if (!ft_strcmp(key, "EA "))
		return (3);
	else if (!ft_strcmp(key, "S "))
		return (4);
	return (-1);
}

static int	get_path(t_game *game, char *line, char *key)
{
	char	**path;
	int		index;

	index = get_index(key);
	game->sets->parse_finds++;
	path = ft_split(line + ft_strlen(key), ' ');
	if (!path || count_splitted(path) != 1)
		return (clear_splitted(&path));
	game->map->tex_path[index] = ft_strdup(path[0]);
	clear_splitted(&path);
	return (1);
}

int			get_texture_path(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		get_path(game, line, "NO ");
	else if (!ft_strncmp(line, "SO ", 3))
		get_path(game, line, "SO ");
	else if (!ft_strncmp(line, "WE ", 3))
		get_path(game, line, "WE ");
	else if (!ft_strncmp(line, "EA ", 3))
		get_path(game, line, "EA ");
	else if (!ft_strncmp(line, "S ", 2))
		get_path(game, line, "S ");
	return (1);
}
