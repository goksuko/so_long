/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/02 23:53:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 12:17:01 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

bool	sl_image_init(t_game *my_game, t_map *my_map)
{
	my_game->char_tx = mlx_load_png("textures/char.png");
	my_game->wall_tx = mlx_load_png("textures/wall.png");
	my_game->col_tx = mlx_load_png("textures/col.png");
	my_game->end_tx = mlx_load_png("textures/end.png");
	my_game->wolf_tx = mlx_load_png("textures/wolf.png");
	my_game->gameover_tx = mlx_load_png("textures/gameover.png");
	my_game->steps_img = mlx_new_image(my_map->mlx, 64, 64);
	if (my_game->char_tx == NULL || my_game->wall_tx == NULL
		|| my_game->col_tx == NULL || my_game->end_tx == NULL
		|| my_game->wolf_tx == NULL || my_game->gameover_tx == NULL
		|| my_game->steps_img == NULL)
		return (false);
	return (true);
}

bool	sl_text_to_img(t_map *my_map, t_game *my_game)
{
	my_game->char_img = mlx_texture_to_image(my_map->mlx, my_game->char_tx);
	my_game->wall_img = mlx_texture_to_image(my_map->mlx, my_game->wall_tx);
	my_game->col_img = mlx_texture_to_image(my_map->mlx, my_game->col_tx);
	my_game->end_img = mlx_texture_to_image(my_map->mlx, my_game->end_tx);
	my_game->wolf_img = mlx_texture_to_image(my_map->mlx, my_game->wolf_tx);
	my_game->gameover_img = mlx_texture_to_image(my_map->mlx,
			my_game->gameover_tx);
	if (my_game->char_img == NULL || my_game->wall_img == NULL
		|| my_game->col_img == NULL || my_game->end_img == NULL
		|| my_game->wolf_img == NULL || my_game->gameover_img == NULL)
		return (false);
	return (true);
}

void	sl_place_wall_and_col(t_map *my_map, t_game *my_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < my_map->length_y)
	{
		x = 0;
		while (x < my_map->length_x)
		{
			if (my_map->content[y][x] == '1')
				mlx_image_to_window(my_map->mlx, my_game->wall_img, x * 64, y
					* 64);
			if (my_map->content[y][x] == 'C')
				mlx_image_to_window(my_map->mlx, my_game->col_img, x * 64, y
					* 64);
			x++;
		}
		y++;
	}
}

void	sl_place_end_and_char(t_map *my_map, t_game *my_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < my_map->length_y)
	{
		x = 0;
		while (x < my_map->length_x)
		{
			if (my_map->content[y][x] == 'E')
				mlx_image_to_window(my_map->mlx, my_game->end_img, x * 64, y
					* 64);
			if (my_map->content[y][x] == 'P')
			{
				my_game->char_y = y;
				my_game->char_x = x;
				mlx_image_to_window(my_map->mlx, my_game->char_img, x * 64, y
					* 64);
			}
			x++;
		}
		y++;
	}
}

void	sl_place_wolf(t_map *my_map, t_game *my_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < my_map->length_y)
	{
		x = 0;
		while (x < my_map->length_x)
		{
			if (my_map->content[y][x] == 'F')
				mlx_image_to_window(my_map->mlx, my_game->wolf_img, x * 64, y
					* 64);
			x++;
		}
		y++;
	}
}
