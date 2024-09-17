/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:38:18 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 06:49:54 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_compass_dir_letter(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

int	char_not_one(char c)
{
	return (c == ('0') || is_compass_dir_letter(c));
}

void	replace_the_chars_with_s(char ***map, int i, int j)
{
	if (i < 0 || j < 0 || !(*map)[i] || !(*map)[i][j])
		return ;
	if ((*map)[i][j] == ' ')
	{
		if (i - 1 >= 0 && (*map)[i - 1] && char_not_one((*map)[i - 1][j]))
		{
			(*map)[i - 1][j] = ' ';
			replace_the_chars_with_s(map, i - 1, j);
		}
		if ((*map)[i + 1] && char_not_one((*map)[i + 1][j]))
		{
			(*map)[i + 1][j] = ' ';
			replace_the_chars_with_s(map, i + 1, j);
		}
		if (j - 1 >= 0 && char_not_one((*map)[i][j - 1]))
		{
			(*map)[i][j - 1] = ' ';
			replace_the_chars_with_s(map, i, j - 1);
		}
		if (char_not_one((*map)[i][j + 1]))
		{
			(*map)[i][j + 1] = ' ';
			replace_the_chars_with_s(map, i, j + 1);
		}
	}
}

int	count_zeros(char **map)
{
	int	zeros_and_dirs;
	int	i;
	int	j;

	i = -1;
	zeros_and_dirs = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (char_not_one(map[i][j]))
				zeros_and_dirs++;
	}
	return (zeros_and_dirs);
}
