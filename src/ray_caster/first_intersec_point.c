/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_intersec_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 13:29:37 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 13:29:37 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates the x-coordinate of the first ray intersection
*  in the northeast sector (0 to 90 degrees). */
void	northeast_sector(int p_y, t_coords *point, t_cub3d *info)
{
	int	p_x;

	p_x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	point->x = p_x + ((p_y - point->y)
		/ tan(degrees_to_radians(info->player.viewing_angle)));
}

/* Calculates the x-coordinate of the first ray intersection
*  in the northwest sector (90 to 180 degrees). */
void	northwest_sector(int p_y, t_coords *point, t_cub3d *info)
{
	double	new_angle;
	int		p_x;

	new_angle = 180.0 - info->player.viewing_angle;
	p_x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	point->x = p_x - ((p_y - point->y)
		/ tan(degrees_to_radians(new_angle)));
}

/* Calculates the x-coordinate of the first ray intersection
*  in the southwest sector (180 to 270 degrees). */
void	southwest_sector(int p_y, t_coords *point, t_cub3d *info)
{
	double	new_angle;
	int		p_x;

	new_angle = info->player.viewing_angle - 180.0;
	p_x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	point->x = p_x - ((point->y - p_y)
		/ tan(degrees_to_radians(new_angle)));
}

/* Calculates the x-coordinate of the first ray intersection
*  in the southeast sector (270 to 360 degrees). */
void	southeast_sector(int p_y, t_coords *point, t_cub3d *info)
{
	double	new_angle;
	int		p_x;

	new_angle = 360.0 - info->player.viewing_angle;
	p_x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	point->x = p_x + ((point->y - p_y)
		/ tan(degrees_to_radians(new_angle)));
}
