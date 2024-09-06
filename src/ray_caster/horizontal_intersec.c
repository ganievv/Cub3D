/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 13:51:49 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 13:51:49 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates the coordinates where the
*  ray intersects a wall.
*
*  'p' - player's pixel coordinates. */
void	check_horizontal_points(t_ray *ray, t_cub3d *info)
{
	t_coords	p;
	t_coords	move;

	p.x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	p.y = grid_to_pixel(info->player.coords.y, info->game_dims.cube_size);
	if (ray->angle != 0.0 && ray->angle != 180.0)
	{
		check_first_h_point(ray, &p, info);
		set_movement_len(&move, ray, info);
		while (!is_wall(ray, info))
			move_to_new_point(&move, ray);
	}
}

/* Checks if the intersection point is a wall */
bool	is_wall(t_ray *ray, t_cub3d *info)
{
	int	x;
	int	y;

	x = pixel_to_grid(ray->h_intersec.x, info->game_dims.cube_size);
	y = pixel_to_grid(ray->h_intersec.y, info->game_dims.cube_size);
	return (info->map.map[y][x] == '1');
}
