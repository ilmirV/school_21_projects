#include "cub3d.h"

int	read_line(t_game *game, char *line)
{
	if (line[ft_strlen(line) - 1] == ' ' && game->sets->parse_finds < 8)
		return (exit_game_2(game, -16));
	if (!ft_strncmp(line, "R ", 2))
		return (get_resolution(game, line));
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
			!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3) ||
			!ft_strncmp(line, "S ", 2))
		return (get_texture_path(game, line));
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (get_colors(game, line));
	else if (*line != '\0')
		return (exit_game(game, -4));
	return (0);
}
