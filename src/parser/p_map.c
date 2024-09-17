/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:22 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 02:51:39 by tnakas           ###   ########.fr       */
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

int	is_compass_dir_letter(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
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
