/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 15:18:42 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-11 15:18:42 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Determines if the current intersection is a wall. */
bool	is_wall(t_coords *i, t_cub3d *info)
{
	return (info->map.map[i->y][i->x] == '1');
}

/* Checks if a intersection is outside the boundaries of the map. */
bool	is_out_of_map(t_coords *i, t_cub3d *info)
{
	return (i->x < 0 || i->y < 0
		|| i->x >= info->map.width || i->y >= info->map.height);
}

/* Determines if the current intersection is a wall. */
bool	is_whitespace(t_coords *i, t_cub3d *info)
{
	return (info->map.map[i->y][i->x] == ' '
		|| info->map.map[i->y][i->x] == '\t'
		|| info->map.map[i->y][i->x] == '\n');
}
