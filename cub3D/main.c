#include "cub3d.h"

int			abort_game(t_game *game)
{
	if (game)
		clear_game(&game);
	return (0);
}

static int	check_filename(char *filename)
{
	int length;

	length = ft_strlen(filename);
	if (ft_strcmp(filename + (length - 4), ".cub") || length <= 4)
		return (0);
	return (1);
}

static int	exit_hook(t_game *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

static void	start_game(t_game *game)
{
	load_textures(game);
	game->mlx->win = mlx_new_window(game->mlx->mlx,
		game->sets->scr_w, game->sets->scr_h, "Fake 3D");
	create_image(game);
	mlx_hook(game->mlx->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->mlx->win, 17, 0, &exit_hook, game);
	mlx_loop_hook(game->mlx->mlx, &movements, game);
	mlx_loop(game->mlx->mlx);
}

int			main(int argc, char **argv)
{
	t_game	*game;
	int		save;

	game = NULL;
	save = (argc == 3 && !ft_strcmp(argv[2], "--save"));
	if (argc != 2 && argc != 3)
		exit_game(game, -1);
	if (!check_filename(argv[1]))
		exit_game(game, -2);
	if (!(game = init_game()))
		return (abort_game(game));
	game->sets->save = save;
	mlx_get_screen_size(game->mlx->mlx, &game->sets->scr_w, &game->sets->scr_h);
	if (!(game->map = load_file(game, argv[1])))
		return (exit_game_2(game, -10));
	if (save)
		return (screenshot(game));
	start_game(game);
	return (0);
}
