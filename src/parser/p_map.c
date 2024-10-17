/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:22 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/17 22:14:58 by tnakas           ###   ########.fr       */
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
	int		i;
	int		j;
	int		is_valid;

	i = -1;
	j = 0;
	is_valid = 1;
	tested_map = node_to_array(map, node_len(map));
	print_double_str_array(tested_map);
	if (!tested_map)
		return (0);
	while (tested_map && tested_map[++i] && is_valid == 1)
	{
		j = -1;
		while (tested_map[i] && tested_map[i][++j])
		{
			if (char_not_one(tested_map[i][j]))
				replace_the_chars_with_s(&tested_map, i, j, &is_valid);
		}
	}
	free_double_array(tested_map);
	return (is_valid);
}

int	valid_map(t_node *map)
{
	return (map_valid_by_chars(map) && success_to_cover(map));
}
