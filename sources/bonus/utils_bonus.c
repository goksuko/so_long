/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:08:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 13:02:03 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

char	*sl_strjoin_without_free(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	return (join);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*join;

	join = sl_strjoin_without_free(s1, s2);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (join);
}

void	free_maps(char **map, t_map *my_map)
{
	free_matrix(map);
	if (!my_map)
		return ;
	else
	{
		free_matrix(my_map->content);
		free_matrix(my_map->dup_content);
		free(my_map);
		my_map = NULL;
	}
}

int	count_lines(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string && string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (NULL);
}
