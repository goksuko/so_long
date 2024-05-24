/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/26 19:46:49 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 11:28:39 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	mlx_texture_t	*char_tx;
	mlx_image_t		*char_img;
	mlx_texture_t	*wall_tx;
	mlx_image_t		*wall_img;
	mlx_texture_t	*col_tx;
	mlx_image_t		*col_img;
	mlx_texture_t	*end_tx;
	mlx_image_t		*end_img;
	mlx_texture_t	*wolf_tx;
	mlx_image_t		*wolf_img;
	mlx_texture_t	*gameover_tx;
	mlx_image_t		*gameover_img;
	mlx_image_t		*steps_img;
	int				char_y;
	int				char_x;
	int				steps;
	int				dead;
}					t_game;

typedef struct s_map
{
	int				length_x;
	int				length_y;
	char			**content;
	char			**dup_content;
	int				e_count;
	int				p_count;
	int				c_count;
	int				player_x;
	int				player_y;
	mlx_t			*mlx;
	t_game			game;
}					t_map;

// main.c

t_map				*sl_map_init(char **map);

// map.c

char				**sl_open_map(char *str);
char				**sl_map_dup(char **map, int length_x, int length_y);
t_map				*sl_map_init(char **map);

// map_check.c

bool				sl_check_size_prob(t_map *my_map);
bool				sl_check_character_prob(t_map *my_map);
bool				sl_map_empty_line_prob(t_map *my_map);

// map_check2.c

bool				sl_check_extension_prob(char *str);
bool				sl_check_side_wall_prob(t_map *my_map);
bool				sl_check_up_down_wall_prob(t_map *my_map);

// flood_fill.c

bool				sl_check_floodfill_prob(t_map *my_map);

// game.c

bool				sl_game(t_game *my_game, t_map *my_map);
void				check_move(t_map *my_map);

// images.c

bool				sl_image_init(t_game *my_game, t_map *my_map);
bool				sl_text_to_img(t_map *my_map, t_game *my_game);
void				sl_place_wall_and_col(t_map *my_map, t_game *my_game);
void				sl_place_end_and_char(t_map *my_map, t_game *my_game);
void				sl_place_wolf(t_map *my_map, t_game *my_game);

// keyboard.c

void				my_keyhook(mlx_key_data_t keydata, void *my_map);
void				keyboard_down(mlx_key_data_t *key, t_map *my_map,
						char *steps_str);
void				keyboard_up(mlx_key_data_t *key, t_map *my_map,
						char *steps_str);
void				keyboard_right(mlx_key_data_t *key, t_map *my_map,
						char *steps_str);
void				keyboard_left(mlx_key_data_t *key, t_map *my_map,
						char *steps_str);

// utils_game.c

void				sl_clean_window(t_game *my_game, t_map *my_map);

// utils.c

char				*sl_strjoin(char *s1, char *s2);
void				free_maps(char **map, t_map *my_map);
int					count_lines(char **matrix);
void				*free_matrix(char **string);

// utils2.c

int					sl_strlen(char *str);
char				**sl_split(char const *s, char c);

#endif
