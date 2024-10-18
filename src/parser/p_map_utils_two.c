/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:38:18 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/18 22:10:33 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_c_dir_letter(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

int	char_not_one(char c)
{
	return (c == ('0') || is_c_dir_letter(c));
}

void	recursive_check(char ***map, int i, int j, int	*is_valid)
{
	int	i_max;

	i_max = 0;
	while ((*map)[i_max] != NULL)
		i_max++;
	if (is_valid == 0 || !(*map)[i] || j > (int)ft_strlen((*map)[i])
		|| i >= i_max || i < 0 || j < 0)
		return ;
	if ((i == 0 || j == 0 || i == i_max - 1) && char_not_one((*map)[i][j]))
		*is_valid = 0;
	if (*is_valid == 0 || (*map)[i][j] == 'V' || ft_isspace((*map)[i][j])
	|| (*map)[i][j] == '\0' || (*map)[i][j] == '1')
	{
		if ((ft_isspace((*map)[i][j]) || (*map)[i][j] == '\0'))
			*is_valid = 0;
		return ;
	}
	(*map)[i][j] = 'V';
	recursive_check(map, i + 1, j, is_valid);
	recursive_check(map, i, j + 1, is_valid);
	recursive_check(map, i - 1, j, is_valid);
	recursive_check(map, i, j - 1, is_valid);
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
