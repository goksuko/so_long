/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:07:57 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 11:49:28 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	sl_check_size_prob(t_map *my_map)
{
	int	y;

	y = 0;
	while (y < my_map->length_y && my_map->content[y])
	{
		if (sl_strlen(my_map->content[y]) != my_map->length_x)
			return (1);
		y++;
	}
	return (0);
}

void	sl_put_player(t_map *my_map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < my_map->length_y && my_map->content[y] && my_map->content[y][x])
	{
		while (x < my_map->length_x && my_map->content[y][x])
		{
			if (my_map->content[y][x] == 'P')
			{
				my_map->player_x = x;
				my_map->player_y = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

bool	sl_find_numbers(t_map *my_map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < my_map->length_y && my_map->content[y] && my_map->content[y][x])
	{
		while (x < my_map->length_x && my_map->content[y][x])
		{
			if (my_map->content[y][x] == 'P')
				my_map->p_count++;
			else if (my_map->content[y][x] == 'E')
				my_map->e_count++;
			else if (my_map->content[y][x] == 'C')
				my_map->c_count++;
			else if (my_map->content[y][x] != '1'
					&& my_map->content[y][x] != '0')
				return (1);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

bool	sl_check_character_prob(t_map *my_map)
{
	if (sl_find_numbers(my_map))
		return (ft_printf("Error\nWrong charachter found.\n"), 1);
	sl_put_player(my_map);
	if (my_map->p_count == 0)
		return (ft_printf("Error\nPlayer not found.\n"), 1);
	if (my_map->e_count == 0)
		return (ft_printf("Error\nExit not found.\n"), 1);
	if (my_map->c_count == 0)
		return (ft_printf("Error\nCollectible not found.\n"), 1);
	if (my_map->p_count > 1)
		return (ft_printf("Error\nMultiple players found.\n"), 1);
	if (my_map->e_count > 1)
		return (ft_printf("Error\nMultiple exits found.\n"), 1);
	else
		return (0);
}

bool	sl_map_empty_line_prob(t_map *my_map)
{
	int	y;

	y = 0;
	while (y < my_map->length_y && my_map->content[y])
	{
		if (sl_strlen(my_map->content[y]) == 0)
			return (1);
		y++;
	}
	return (0);
}
