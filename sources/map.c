/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 23:56:36 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 13:58:28 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*sl_read_map(int fd, bool empty)
{
	char	*line;
	char	*temp;

	empty = false;
	temp = ft_strdup("");
	if (temp == NULL)
		return (ft_printf("Error\nMap start error.\n"), close(fd), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line == '\n')
		{
			empty = true;
			close(fd);
			free(temp);
			temp = NULL;
			free(line);
			line = NULL;
		}
		if (temp != NULL)
			temp = sl_strjoin(temp, line);
	}
	return (temp);
}

char	**sl_open_map(char *str)
{
	int		fd;
	char	*temp;
	char	**map;
	bool	empty;

	empty = false;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nMap openning error.\n"), NULL);
	temp = sl_read_map(fd, empty);
	if (temp == NULL || empty == true)
		return (ft_printf("Error\nInvalid map.\n"),
			close(fd), free(temp), NULL);
	map = sl_split(temp, '\n');
	if (map == NULL)
		return (ft_printf("Error\nMap split error.\n"), free(temp), close(fd),
			NULL);
	close(fd);
	free(temp);
	return (map);
}

char	**sl_map_dup(char **map, int length_x, int length_y)
{
	char	**dup_map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	dup_map = ft_calloc(sizeof(char *), (length_y + 1));
	if (dup_map == NULL)
		return (ft_printf("Error\nMap dup.\n"), NULL);
	while (y < length_y && map[y])
	{
		dup_map[y] = ft_calloc(sizeof(char), (length_x + 1));
		if (dup_map[y] == NULL)
			return (ft_printf("Error\nMap dup.\n"), free_matrix(dup_map), NULL);
		while (x < length_x && map[y][x])
		{
			dup_map[y][x] = map[y][x];
			x++;
		}
		dup_map[y][x] = '\0';
		x = 0;
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

t_map	*sl_map_init(char **map)
{
	t_map	*my_map;

	if (!map)
		return (ft_printf("Error\nMap not found.\n"), NULL);
	my_map = ft_calloc(sizeof(t_map), 1);
	if (my_map == NULL)
		return (ft_printf("Error\nMap init error.\n"), NULL);
	my_map->length_x = sl_strlen(map[0]);
	my_map->length_y = count_lines(map);
	my_map->content = NULL;
	my_map->content = sl_map_dup(map, my_map->length_x, my_map->length_y);
	my_map->dup_content = NULL;
	my_map->dup_content = sl_map_dup(map, my_map->length_x, my_map->length_y);
	my_map->e_count = 0;
	my_map->p_count = 0;
	my_map->c_count = 0;
	my_map->player_x = 0;
	my_map->player_y = 0;
	return (my_map);
}
