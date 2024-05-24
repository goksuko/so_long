/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:06:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 09:48:59 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *pointer)
{
	char	*steps_str;
	t_map	*my_map;

	my_map = pointer;
	steps_str = 0;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(my_map->mlx);
	steps_str = ft_itoa(my_map->game.steps);
	if (my_map->game.dead != 1)
	{
		keyboard_down(&keydata, my_map);
		keyboard_up(&keydata, my_map);
		keyboard_right(&keydata, my_map);
		keyboard_left(&keydata, my_map);
	}
	ft_printf("Little Red Riding Hood made %s steps\n", steps_str);
	free(steps_str);
	check_move(my_map);
}

// mlx_put_string: Draws a string on an image and then outputs it to the window.
void	keyboard_down(mlx_key_data_t *keydata, t_map *my_map)
{
	if ((keydata->key == MLX_KEY_S || keydata->key == MLX_KEY_DOWN)
		&& my_map->content[my_map->game.char_y + 1][my_map->game.char_x] != '1')
	{
		my_map->game.steps++;
		my_map->game.char_y++;
		my_map->game.char_img->instances[0].y += 64;
	}
}

void	keyboard_up(mlx_key_data_t *keydata, t_map *my_map)
{
	if ((keydata->key == MLX_KEY_W || keydata->key == MLX_KEY_UP)
		&& my_map->content[my_map->game.char_y - 1][my_map->game.char_x] != '1')
	{
		my_map->game.steps++;
		my_map->game.char_y--;
		my_map->game.char_img->instances[0].y -= 64;
	}
}

void	keyboard_right(mlx_key_data_t *keydata, t_map *my_map)
{
	if ((keydata->key == MLX_KEY_D || keydata->key == MLX_KEY_RIGHT)
		&& my_map->content[my_map->game.char_y][my_map->game.char_x + 1] != '1')
	{
		my_map->game.steps++;
		my_map->game.char_x++;
		my_map->game.char_img->instances[0].x += 64;
	}
}

void	keyboard_left(mlx_key_data_t *keydata, t_map *my_map)
{
	if ((keydata->key == MLX_KEY_A || keydata->key == MLX_KEY_LEFT)
		&& my_map->content[my_map->game.char_y][my_map->game.char_x - 1] != '1')
	{
		my_map->game.steps++;
		my_map->game.char_x--;
		my_map->game.char_img->instances[0].x -= 64;
	}
}
