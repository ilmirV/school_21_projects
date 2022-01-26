#include "cub3d.h"

int	exit_game(t_game *game, int code)
{
	if (code < 0)
		ft_printf("Error\n");
	if (code == -1)
		ft_printf("Too few/many arguments\n");
	if (code == -2)
		ft_printf("Invalid file name\n");
	if (code == -3)
		ft_printf("Failed to load texture(s)\n");
	if (code == -4)
		ft_printf("Invalid identifier(s)\n");
	if (code == -5)
		ft_printf("Duplicate identifier(s)\n");
	if (code == -6)
		ft_printf("Duplicate player's start position\n");
	if (code == -7)
		ft_printf("Empty line after map\n");
	if (code == -8)
		ft_printf("Player's start position hasn't been initialized\n");
	if (code == -9)
		ft_printf("Resolution must be greater than zero\n");
	ft_printf("Exiting with code: %d\n", code);
	if (game)
		clear_game(&game);
	exit(code);
	return (code);
}

int	exit_game_2(t_game *game, int code)
{
	if (code < 0)
		ft_printf("Error\n");
	if (code == -10)
		ft_printf("Empty file or file doesn't exist\n");
	if (code == -11)
		ft_printf("Color values must be in range 0-255\n");
	if (code == -12)
		ft_printf("Too few/many color values\n");
	if (code == -13)
		ft_printf("Too few/many values in resolution\n");
	if (code == -14)
		ft_printf("Invalid color value\n");
	if (code == -15)
		ft_printf("Invalid resolution value\n");
	if (code == -16)
		ft_printf("Space(s) in the end of the line\n");
	if (code == -17)
		ft_printf("Space(s) before comma in color value\n");
	ft_printf("Exiting with code: %d\n", code);
	if (game)
		clear_game(&game);
	exit(code);
	return (code);
}
