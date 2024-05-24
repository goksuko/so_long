/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:08:03 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 13:02:30 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	**clean(char **matrix, size_t string_no)
{
	while (string_no--)
		free(matrix[string_no]);
	free(matrix);
	return (NULL);
}

static int	sl_count_strings(const char *s, char delimiter)
{
	size_t	string_nb;

	string_nb = 0;
	while (*s)
	{
		if (*s == delimiter && *s)
			s++;
		string_nb++;
		if (*s != delimiter && *s)
		{
			string_nb++;
			while (*s != delimiter && *s)
				s++;
		}
	}
	return (string_nb);
}

static char	**sl_fill_matrix(char **matrix, const char *s, char c)
{
	size_t	i;
	size_t	string_no;
	size_t	string_len;
	size_t	start;

	i = 0;
	string_no = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		string_len = i - start;
		matrix[string_no] = ft_substr(s, start, string_len);
		if (matrix[string_no] == NULL)
			return (clean(matrix, string_no));
		string_no++;
	}
	matrix[string_no] = NULL;
	return (matrix);
}

char	**sl_split(char const *s, char c)
{
	int		string_nb;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	string_nb = sl_count_strings(s, c);
	matrix = (char **)ft_calloc(sizeof(char *), (string_nb + 1));
	if (matrix == NULL)
		return (NULL);
	matrix = sl_fill_matrix(matrix, s, c);
	if (matrix == NULL)
		return (NULL);
	matrix[string_nb] = NULL;
	return (matrix);
}
