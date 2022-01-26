#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf/libftprintf.h"
# include "ft_printf/libft/libft.h"
# include "get_next_line.h"
# define W 1<<0
# define S 1<<1
# define A 1<<2
# define D 1<<3
# define L 1<<4
# define R 1<<5

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				b_p_p;
	int				l_l;
	int				endian;
	int				img_w;
	int				img_h;
}					t_img;

typedef struct		s_sprite
{
	struct s_sprite	*next;
	struct s_sprite	*sorted;
	double			pos_x;
	double			pos_y;
	double			dist;
	int				scr_x;
	int				spr_w;
	int				spr_h;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				tex_x;
}					t_sprite;

typedef struct		s_map
{
	char			**map;
	char			**tex_path;
	t_img			**textures;
	t_sprite		*sprites;
	int				map_w;
	int				map_h;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_mlx;

typedef struct		s_settings
{
	int				scr_w;
	int				scr_h;
	int				floor_color;
	int				ceil_color;
	double			*z_buf;
	int				parse_finds;
	int				save;
	double			coef;
	double			diff;
}					t_settings;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			old_dir_x;
	double			plane_x;
	double			plane_y;
	double			old_plane_x;
	double			rot_spd;
	double			move_spd;
	char			move_flag;
	int				count;
}					t_player;

typedef struct		s_raycast
{
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			p_w_d;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	int				index;
}					t_raycast;

typedef struct		s_game
{
	t_map			*map;
	t_mlx			*mlx;
	t_player		*player;
	t_settings		*sets;
	t_raycast		*ray;
}					t_game;

t_settings			*set_default(void);
int					abort_game(t_game *game);
int					draw_game(t_game *game);
t_game				*init_game(void);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					exit_game(t_game *game, int code);
int					exit_game_2(t_game *game, int code);
void				refresh_window(t_game *game);
t_map				*load_file(t_game *game, char *filename);
int					get_resolution(t_game *game, char *line);
char				*get_line(t_list *file, char *key);
int					parse_map(t_game *game, t_list *file);
int					get_player_position(t_game *game);
int					get_colors(t_game *game, char *line);
t_img				*init_image(t_game *game);
void				clear_game(t_game **game);
void				clear_mlx(t_game *game);
void				clear_image(t_game *game, t_img **img);
void				clear_map(t_game *game);
void				clear_textures(t_game *game);
void				clear_player(t_game *game);
void				clear_settings(t_game *game);
void				clear_file(t_list *file);
int					clear_splitted(char ***splitted);
int					count_splitted(char **splitted);
int					get_texture_path(t_game *game, char *line);
int					validate_map(t_game *game, t_map *map);
int					error_map_line(t_game *game, int i, char *line, char key);
int					load_textures(t_game *game);
void				create_image(t_game *game);
void				calculate_delta(t_game *game, int x);
void				calculate_side_dist(t_game *game);
void				calculate_hit(t_game *game);
void				calculate_wall(t_game *game);
void				calculate_tex_x(t_game *game);
int					movements(t_game *game);
void				draw_textures(t_game *game, int x, int index);
int					save_picture(t_game *game);
int					screenshot(t_game *game);
void				get_sprites(t_game *game);
t_sprite			*sort_sprites(t_game *game, t_sprite *sprites);
void				draw_sprites(t_game *game);
int					check_params(char **number);
int					read_line(t_game *game, char *line);
int					count_commas(char *line);

#endif
