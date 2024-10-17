/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:38:18 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/17 22:33:27 by tnakas           ###   ########.fr       */
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

// static void	updating_the_map(char ***map, int i, int j, int *is_valid)
// {
// 	if (!ft_isspace((*map)[i][j]))
// 		(*map)[i][j] = ' ';
// 	replace_the_chars_with_s(map, i, j, is_valid);
// }

void	replace_the_chars_with_s(char ***map, int i, int j, int	*is_valid)
{
	if (i < 0 || j < 0 || !(*map)[i] || !(*map)[i][j] || (*map)[i][j] == 'V'
		|| ft_isspace((*map)[i][j]) || (*map)[i][j] == '\0'
		|| (*map)[i][j] == '1' || is_valid == 0)
	{
		if (ft_isspace((*map)[i][j]) || (*map)[i][j] == '\0')
			*is_valid = 0;
		return ;
	}
	(*map)[i][j] = 'V';
	replace_the_chars_with_s(map, i + 1, j, is_valid);
	replace_the_chars_with_s(map, i, j + 1, is_valid);
	replace_the_chars_with_s(map, i - 1, j, is_valid);
	replace_the_chars_with_s(map, i, j - 1, is_valid);
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
