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

void	set_player_coordinates(t_cub3d *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->map.height)
	{
		x = -1;
		while (++x < info->map.width)
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

void	set_player_direction(t_cub3d *info)
{
	if (info->map.map[info->player.coords.y][info->player.coords.x] == 'E')
		info->player.direction = EAST;
	else if (info->map.map[info->player.coords.y][info->player.coords.x] == 'N')
		info->player.direction = NORTH;
	else if (info->map.map[info->player.coords.y][info->player.coords.x] == 'W')
		info->player.direction = WEST;
	else
		info->player.direction = SOUTH;
}

void	set_player_viewing_angle(t_cub3d *info)
{
	if (info->player.direction == EAST)
		info->player.viewing_angle = 0.0;
	else if (info->player.direction == NORTH)
		info->player.viewing_angle = 90.0;
	else if (info->player.direction == WEST)
		info->player.viewing_angle = 180.0;
	else
		info->player.viewing_angle = 270.0;
}
