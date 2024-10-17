/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:55 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 06:55:21 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	map_list_version(char **res, t_node	**map, int *dir)
{
	while (*res)
	{
		while (*res && is_empty_line(*res))
			res++;
		if (*res)
			define_the_type(*res, map, dir);
		else
			break ;
		res++;
	}
}

void	array_to_list(char **res, t_node **parse_node, t_node **map)
{
	int		i;
	int		j;
	int		not_a_dir;

	i = -1;
	not_a_dir = 0;
	while (res[++i])
	{
		while (res[i] && is_empty_line(res[i]))
			i++;
		j = -1;
		while (ft_isspace(res[i][++j]))
			;
		define_the_type(res[i] + j, parse_node, &not_a_dir);
		if (not_a_dir)
			break ;
	}
	map_list_version(res + i, map, &not_a_dir);
}

static void	define_helper(char *str, t_node **parse_node, int *f)
{
	if (*f == 1)
		node_add_back(parse_node, node_new(NON, str));
	*f = 1;
}

void	define_the_type(char *str, t_node **parse_node, int *f)
{
	if (!ft_strncmp("N ", str, 2))
		node_add_back(parse_node, node_new(NORTH, str + 2));
	else if (!ft_strncmp("NO ", str, 3))
		node_add_back(parse_node, node_new(NORTH, str + 3));
	else if (!ft_strncmp("S ", str, 2))
		node_add_back(parse_node, node_new(SOUTH, str + 2));
	else if (!ft_strncmp("SO ", str, 3))
		node_add_back(parse_node, node_new(SOUTH, str + 3));
	else if (!ft_strncmp("W ", str, 2))
		node_add_back(parse_node, node_new(WEST, str + 2));
	else if (!ft_strncmp("WE ", str, 3))
		node_add_back(parse_node, node_new(WEST, str + 3));
	else if (!ft_strncmp("E ", str, 2))
		node_add_back(parse_node, node_new(EAST, str + 2));
	else if (!ft_strncmp("EA ", str, 3))
		node_add_back(parse_node, node_new(EAST, str + 3));
	else if (!ft_strncmp("F ", str, 2))
		node_add_back(parse_node, node_new(FLOOR, str + 2));
	else if (!ft_strncmp("C ", str, 2))
		node_add_back(parse_node, node_new(CIELLING, str + 2));
	else
		define_helper(str, parse_node, f);
}
