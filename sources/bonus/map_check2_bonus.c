/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/26 20:21:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/14 12:01:41 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

bool	sl_check_extension_prob(char *str)
{
	int		len;
	int		i;
	int		j;
	char	*ber;

	len = sl_strlen(str);
	ber = ".ber";
	if (len < 5)
		return (1);
	i = 0;
	j = len - 4;
	while (str[j] && ber[i] && str[j] == ber[i])
	{
		i++;
		j++;
	}
	if (i == 4)
		return (0);
	else
		return (1);
}

bool	sl_check_side_wall_prob(t_map *my_map)
{
	int	y;

	y = 0;
	while (y < my_map->length_y && my_map->content[y])
	{
		if (my_map->content[y][0] != '1' || my_map->content[y][my_map->length_x
			- 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

bool	sl_check_up_down_wall_prob(t_map *my_map)
{
	int	x;

	x = 0;
	while (x < my_map->length_x && my_map->content[0][x])
	{
		if (my_map->content[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < my_map->length_x && my_map->content[my_map->length_y - 1][x])
	{
		if (my_map->content[my_map->length_y - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}
