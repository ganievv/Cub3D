/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/16 23:00:23 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(void)
{
	char	**res;
	t_node	*parse_node;
	t_node	*parse_map;

	res = open_and_get_all_lines("./src/parser/input.cub");
	array_to_list(res, &parse_node, &parse_map);
	print_node_list(parse_node);
	print_node_list(parse_map);
	return (0);
}
