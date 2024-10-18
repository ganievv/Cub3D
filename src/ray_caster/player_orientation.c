/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 20:39:36 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-02 20:39:36 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Sets player coordinates based on their
*  position ('N', 'S', 'E', 'W') on the map. */
void	set_player_coordinates(t_cub3d *info)
{
	int	x;
	int	y;
	int	map_width;

	y = -1;
	while (++y < info->map.height)
	{
		x = -1;
		map_width = find_map_row_len(info->map.map[y]);
		while (++x < map_width)
		{
			if (info->map.map[y][x] == 'N' || info->map.map[y][x] == 'S'
				|| info->map.map[y][x] == 'E' || info->map.map[y][x] == 'W')
			{
				info->player.coords.x = x;
				info->player.coords.y = y;
				return ;
			}
		}
	}
}

/* Sets the player's initial viewing angle
*  based on their starting position in the map.
*  Replaces the player's starting position on
*  the map with an empty space ('0'). */
void	set_player_viewing_angle(t_cub3d *info)
{
	int	x;
	int	y;

	x = info->player.coords.x;
	y = info->player.coords.y;
	if (info->map.map[y][x] == 'E')
		info->player.viewing_angle = 0.0;
	else if (info->map.map[y][x] == 'N')
		info->player.viewing_angle = 90.0;
	else if (info->map.map[y][x] == 'W')
		info->player.viewing_angle = 180.0;
	else
		info->player.viewing_angle = 270.0;
	info->map.map[y][x] = '0';
}
