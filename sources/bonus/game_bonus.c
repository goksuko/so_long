/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 20:35:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 12:01:25 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

bool	sl_place_images(t_map *my_map, t_game *my_game)
{
	sl_place_wall_and_col(my_map, my_game);
	sl_place_end_and_char(my_map, my_game);
	sl_place_wolf(my_map, my_game);
	my_game->steps_img = mlx_put_string(my_map->mlx, "0", 1, 2);
	if (my_game->steps_img == NULL)
		return (false);
	return (true);
}

static void	remove_collectible(t_map *my_map)
{
	const int		x = my_map->game.char_x * 64;
	const int		y = my_map->game.char_y * 64;
	int				i;
	mlx_instance_t	*check;

	i = 0;
	while (1)
	{
		check = &my_map->game.col_img->instances[i];
		if (check->x == x && check->y == y)
		{
			check->enabled = false;
			return ;
		}
		i++;
	}
}

static void	game_over(t_map *my_map)
{
	int				x;
	int				y;
	mlx_instance_t	*player;

	x = 0;
	y = 0;
	player = &my_map->game.char_img->instances[0];
	player->enabled = false;
	while (x < my_map->length_x)
	{
		y = 0;
		while (y < my_map->length_y)
		{
			mlx_image_to_window(my_map->mlx, my_map->game.gameover_img, x * 64,
				y * 64);
			y++;
		}
		x++;
	}
	my_map->game.steps = 0;
	my_map->game.dead = 1;
}

void	check_move(t_map *my_map)
{
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'C')
	{
		my_map->c_count--;
		my_map->content[my_map->game.char_y][my_map->game.char_x] = '0';
		remove_collectible(my_map);
	}
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'E')
	{
		if (my_map->c_count != 0)
			return ;
		else
			mlx_close_window(my_map->mlx);
	}
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'F')
		game_over(my_map);
}

bool	sl_game(t_game *my_game, t_map *my_map)
{
	mlx_t	*mlx;

	mlx = mlx_init(my_map->length_x * 64, my_map->length_y * 64, "so_long",
			false);
	if (mlx == NULL)
		return (false);
	my_map->mlx = mlx;
	my_map->game.steps = 0;
	if (!sl_image_init(my_game, my_map))
		return (sl_clean_window(my_game, my_map), false);
	if (!sl_text_to_img(my_map, my_game))
		return (sl_clean_window(my_game, my_map), false);
	if (!sl_place_images(my_map, my_game))
		return (sl_clean_window(my_game, my_map), false);
	my_game->char_y = my_map->player_y;
	my_game->char_x = my_map->player_x;
	my_map->game.dead = 0;
	mlx_key_hook(mlx, &my_keyhook, my_map);
	mlx_loop(my_map->mlx);
	sl_clean_window(my_game, my_map);
	return (true);
}
