/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_intersec_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-10 14:03:57 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-10 14:03:57 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Sets the movement length (x and y) for the ray 
*  as it steps through horizontal grid lines */
void	set_movement_len_h(t_coords *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_facing_up(ray))
		move->y = -info->game_dims.cube_size;
	else if (is_ray_facing_down(ray))
		move->y = info->game_dims.cube_size;

	if (ray->angle == 90.0 || ray->angle == 270.0)
		move->x = 0;
	else
	{
		move->x = info->game_dims.cube_size
			/ tan(degrees_to_radians(ray->angle));
		if (is_ray_facing_down(ray))
			move->x *= -1;
	}
}

/* Sets the movement length (x and y) for the ray 
*  as it steps through vertical grid lines */
void	set_movement_len_v(t_coords *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_facing_right(ray))
		move->x = info->game_dims.cube_size;
	else if (is_ray_facing_left(ray))
		move->x = -info->game_dims.cube_size;

	if (ray->angle == 0.0 || ray->angle == 180.0)
		move->y = 0;
	else
		move->y = info->game_dims.cube_size
				* tan(degrees_to_radians(ray->angle));
}

/* Moves the ray's current intersection to the next one */
void	move_to_new_point(t_coords *move, t_ray *ray)
{
	ray->h_intersec.x = ray->h_intersec.x + move->x;
	ray->h_intersec.y = ray->h_intersec.y + move->y;
}
