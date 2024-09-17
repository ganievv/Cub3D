/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/17 09:42:47 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
//find_player
void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map && map->map[++i])
	{
		j = -1;
		while (map->map[i] && map->map[i][++j])
		{
			if (is_compass_dir_letter(map->map[i][j]))
			{
				map->i_player = i;
				map->j_player = j;
				if (map->map[i][j] == 'N')
					map->dir = NORTH;
				else if (map->map[i][j] == 'S')
					map->dir = SOUTH;
				else if (map->map[i][j] == 'E')
					map->dir = EAST;
				else
					map->dir = WEST;
				return ;
			}
		}
	}
}

// int	main(void)
// {
// 	t_cub3d	info;
// 	char	**res;
// 	t_node	*compass_dir;
// 	t_node	*map;

// 	res = open_and_get_all_lines("./src/parser/input.cub");
// 	array_to_list(res, &compass_dir, &map);
// 	if (valid_map(map) && valid_textures(compass_dir))
// 	{
// 		info.map.map = node_to_array(map, node_len(map));
// 		find_player(&info.map);
// 	}
// 	else
// 		ft_putstr_fd("Error\n", 2);
// 	return (0);
// }
