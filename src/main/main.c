/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/17 02:53:10 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(void)
{
	char	**res;
	t_node	*compass_dir;
	t_node	*map;

	res = open_and_get_all_lines("./src/parser/input.cub");
	array_to_list(res, &compass_dir, &map);
	// printf("%d\n", valid_textures(compass_dir));
	printf("%d\n", map_valid_by_chars(map));
	// print_node_list(compass_dir);
	// print_node_list(map);
	return (0);
}
