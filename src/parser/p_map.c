/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:22 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 06:51:38 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	skip_zeros_ones_spaces(t_node *map, int *i)
{
	while (map && map->p_or_c[(*i)]
		&& (map->p_or_c[(*i)] == '0'
			|| map->p_or_c[(*i)] == '1'
			|| (ft_isspace(map->p_or_c[(*i)]))))
		(*i)++;
}

int	map_valid_by_chars(t_node *map)
{
	int	player_found;
	int	i;

	i = 0;
	player_found = 0;
	while (map && map->p_or_c)
	{
		i = 0;
		skip_zeros_ones_spaces(map, &i);
		if (map && map->p_or_c[i])
		{
			if (is_compass_dir_letter(map->p_or_c[i]))
			{
				if (player_found == 1)
					return (0);
				else
					player_found = 1;
			}
			else
				return (0);
		}
		skip_zeros_ones_spaces(map, &i);
		map = map->next;
	}
	return (player_found);
}

int	success_to_cover(t_node *map)
{
	char	**tested_map;
	int		before;
	int		after;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tested_map = from_list_to_array(map, counting_the_len(map));
	before = count_zeros(tested_map);
	if (!tested_map)
		return (0);
	while (tested_map && tested_map[++i])
	{
		j = -1;
		while (tested_map[i] && tested_map[i][++j])
			if (ft_isspace(tested_map[i][j]))
				replace_the_chars_with_s(&tested_map, i, j);
	}
	after = count_zeros(tested_map);
	free_double_array(tested_map);
	return (before == after);
}

int	valid_map(t_node *map)
{
	return (map_valid_by_chars(map) && success_to_cover(map));
}
