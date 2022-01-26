#include "cub3d.h"

int		key_press(int keycode, t_game *game)
{
	if (keycode < 0 || !game)
		return (0);
	if (keycode == 13)
		game->player->move_flag |= W;
	else if (keycode == 1)
		game->player->move_flag |= S;
	else if (keycode == 2)
		game->player->move_flag |= A;
	else if (keycode == 0)
		game->player->move_flag |= D;
	else if (keycode == 123)
		game->player->move_flag |= L;
	else if (keycode == 124)
		game->player->move_flag |= R;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode < 0 || !game)
		return (0);
	if (keycode == 53)
		return (exit_game(game, EXIT_SUCCESS));
	else if (keycode == 13)
		game->player->move_flag &= ~(W);
	else if (keycode == 1)
		game->player->move_flag &= ~(S);
	else if (keycode == 2)
		game->player->move_flag &= ~(A);
	else if (keycode == 0)
		game->player->move_flag &= ~(D);
	else if (keycode == 123)
		game->player->move_flag &= ~(L);
	else if (keycode == 124)
		game->player->move_flag &= ~(R);
	return (0);
}
