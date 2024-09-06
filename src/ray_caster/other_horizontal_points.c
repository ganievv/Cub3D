/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_horizontal_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 16:21:08 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 16:21:08 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_movement_len(t_coords *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_facing_up(ray))
		move->y = -info->game_dims.cube_size;
	else if (is_ray_facing_down(ray))
		move->y = info->game_dims.cube_size;

	if (ray->angle == 90.0 || ray->angle == 270.0)
		move->x = 0;
	else
	{
		move->x = info->game_dims.cube_size / tan(degrees_to_radians(ray->angle));
		if (is_ray_facing_down(ray))
			move->x *= -1;
	}
}

/* Moves the ray's intersection point to the next grid
*  line, to calculate the next intersection. */
void	move_to_new_point(t_coords *move, t_ray *ray)
{
	ray->intersec.x = ray->intersec.x + move->x;
	ray->intersec.y = ray->intersec.y + move->y;
}
