/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:44:25 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 12:43:00 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_2/mlx.h"
# include "utils/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define BUFFER_SIZE 1

//*Structs
typedef struct s_window
{
	void			*mlx;
	void			*win;
	void			*wall_img;
	void			*sprite_img[6];
	void			*back_img;
	void			*w_sprite_img;
	void			*lp_sprite_img;
	void			*rp_sprite_img;
	void			*sh_sprite_img;
	void			*clct_img[2];
	void			*exit_img;
	int				widht;
	int				heigth;
}					t_window;
typedef struct s_map
{
	char			**map;
	int				cols;
	int				rows;

}					t_map;
typedef struct s_sprite
{
	int				width;
	int				height;
	int				p_x;
	int				p_y;
	int				side;
	int				frame_r;
	int				frame_l;
	int				step_counter;
	char			*steps_str;
}					t_sprite;
typedef struct s_wall
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				exit;
}					t_wall;
typedef struct s_back
{
	int				width;
	int				height;
	int				x;
	int				y;
}					t_back;
typedef struct w_sprite
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				move_up;
	int				frame;
}					t_wsprite;
typedef struct l_en_sprite
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				flag;
	int				left_wall;
	int				left_ex;
	int				left_c;
	int				shoot_switch;
	int				first_shoot_on_side;
	int				first_shoot;
	int				back;
	int				stuck;
	int				stuck_w;
}					t_lp_sprite;
typedef struct r_en_sprite
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				flag;
	int				right_wall;
}					t_rp_sprite;
typedef struct sh_sprite
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				arrived;
}					t_sht_sprite;
typedef struct s_clct
{
	int				width;
	int				height;
	int				coint_c;
	// int				x;
	// int				y;
}					t_clct;
typedef struct s_exit
{
	int				width;
	int				height;
	// int				x;
	// int				y;
}					t_exit;
typedef struct s_asset
{
	t_sprite		sprite;
	t_wall			wall;
	t_back			back;
	t_wsprite		w_sprite;
	t_lp_sprite		lp_sprite;
	t_rp_sprite		rp_sprite;
	t_sht_sprite	sh_sprite;
	t_clct			clct;
	t_exit			exit;

}					t_asset;
typedef struct s_game
{
	int				count_p;
	int				count_c;
	int				count_e;
	int				start_flag;
	int				count_w_en;
	int				count_lp_en;
	int				count_rp_en;
	t_window		window;
	t_map			map;
	t_asset			asset;
	struct timeval	curr_tm;

}					t_game;

//* Functions
size_t				ft_strlen(char *s);
int					destroy_win(t_game *game_s);
int					move_sprite(int key, t_game *game_s);
int					check_wall(t_game *game_s);
char				*get_first_str(int fd, char *str);
char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*clean_str(char *str);
char				*new_line(char *str);
char				*ft_strdup(char *src);
char				*ft_itoa(int n);
void				*ft_calloc(size_t nmeb, size_t size);
void				convert_map(t_game *game_struct, char *av);
void				check_game_edge(t_game *game_s);
void				check_shape(t_game *game_s);
void				print_matrix(int cols, int rows, char **map);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_free_mem(t_game *game_s);
void				check_values(t_game *game_s);
void				check_necessary_values(t_game *game_s);
void				load_win(t_game *game_s);
void				preload_map(t_game *game_s);
void				load_map(t_game *game_s);
void				put_tile_ed(t_game *game_s, int i, int j);
void				put_r_sprite_frame0(t_game *game_s, int i, int j);
void				put_r_sprite_frame1(t_game *game_s, int i, int j);
void				put_l_sprite_frame0(t_game *game_s, int i, int j);
void				put_l_sprite_frame1(t_game *game_s, int i, int j);
void				put_dead_sprite_l(t_game *game_s, int i, int j);
void				put_dead_sprite_r(t_game *game_s, int i, int j);
void				put_tile_c_dead(t_game *game_s, int i, int j);
void				put_chsaw_en(t_game *game_s, int i, int j);
void				put_wall(t_game *game_s, int i, int j);
void				check_side(int key, t_game *game_s);
void				get_coin(t_game *game_s);
void				move_up(int key, t_game *game_s);
void				move_down(int key, t_game *game_s);
void				move_left(int key, t_game *game_s);
void				move_right(int key, t_game *game_s);
void				modify_val(t_game *game_s, int key);
void				put_back(t_game *game_s, int i, int j);
void				put_tile_c(t_game *game_s, int i, int j);
void				put_tile_ex(t_game *game_s, int i, int j);
void				put_left_police(t_game *game_s, int i, int j);
void				put_right_police(t_game *game_s, int i, int j);
void				put_shoot_sprite(t_game *game_s, int i, int j);
void				load_map_x(t_game *game_s);
void				load_map_y(t_game *game_s, int i);
void				move_w_sprite_up(t_game *game_s);
void				move_w_sprite_down(t_game *game_s);
void				shoot_sprite_l(t_game *game_s);
void				shoot_sprite_r(t_game *game_s);
int					animations(t_game *game_s);
int					ft_gettimestamp(t_game *game_s);
void				start_animation(t_game *game_s);
void				print_matrix(int cols, int rows, char **map);
void				update_sprite_frame(t_game *game_s);
void				ft_put_str(t_game *game_s);
void				chainsaw_move_up(t_game *game_s);
void				chainsaw_move_down(t_game *game_s);
int					ft_gettimestamp(t_game *game_s);
void				r_police_animation(t_game *game_s);
int					whats_on_right(t_game *game_s);
int					shoot_obstacle(t_game *game_s);
void				r_police_animation1(t_game *game_s);
void				kill_player(t_game *game_s);
void				put_police_man(t_game *game_s);
void				refresh_string(t_game *game_s);
void				reset_right_shoot(t_game *game_s);
int					whats_on_left(t_game *game_s);
int					check_right_shoot_obstacle(t_game *game_s);
void				check_format_map(char *str);
void				shoot_right(t_game *game_s);
void				shoot_left(t_game *game_s);
int					check_left_shoot_obstacle(t_game *game_s);
void				turn_policeman_to_right(t_game *game_s);
void				check_w_on_col(t_game *game_s, int col_num);
void				police_man_control(t_game *game_s);
int					where_shoot_could_kill_player(t_game *game_s);
#endif