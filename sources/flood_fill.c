/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:07:27 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/08 23:14:38 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**sl_breadth_first_search(char **content, int x, int y)
{
	if (content[y][x] != '1')
	{
		if (content[y][x] == '0' || content[y][x] == 'P' || content[y][x] == 'E'
			|| content[y][x] == 'C' || content[y][x] == 'F')
			content[y][x] = '1';
		else
			return (content);
		sl_breadth_first_search(content, x + 1, y);
		sl_breadth_first_search(content, x - 1, y);
		sl_breadth_first_search(content, x, y + 1);
		sl_breadth_first_search(content, x, y - 1);
	}
	return (content);
}

bool	check_map_after_ff(char **map_after_ff, int length_x, int length_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < length_y && map_after_ff[y])
	{
		x = 0;
		while (x < length_x && map_after_ff[y][x])
		{
			if (map_after_ff[y][x] != '0' && map_after_ff[y][x] != '1')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	sl_check_floodfill_prob(t_map *my_map)
{
	char	**map_after_ff;

	map_after_ff = sl_breadth_first_search(my_map->dup_content,
			my_map->player_x, my_map->player_y);
	if (check_map_after_ff(map_after_ff, my_map->length_x, my_map->length_y))
		return (0);
	else
		return (1);
}
