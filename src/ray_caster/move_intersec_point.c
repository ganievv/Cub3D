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
void	set_movement_len_h(t_coords_d *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_northeast(ray) || is_ray_northwest(ray) || ray->angle == 90.0)
		move->y = -info->game_dims.cube_size;
	else if (is_ray_southwest(ray) || is_ray_southeast(ray)
		|| ray->angle == 270.0)
		move->y = info->game_dims.cube_size;

	if (ray->angle == 90.0 || ray->angle == 270.0)
		move->x = 0;
	else
	{
		move->x = info->game_dims.cube_size
			/ tan(degrees_to_radians(ray->angle));
		if (is_ray_southwest(ray) || is_ray_southeast(ray))
			move->x *= -1;
	}
}

/* Sets the movement length (x and y) for the ray 
*  as it steps through vertical grid lines */
void	set_movement_len_v(t_coords_d *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_northeast(ray) || is_ray_southeast(ray) || ray->angle == 0.0)
		move->x = info->game_dims.cube_size;
	else if (is_ray_northwest(ray) || is_ray_southwest(ray)
		|| ray->angle == 180.0)
		move->x = -info->game_dims.cube_size;

	if (ray->angle == 0.0 || ray->angle == 180.0)
		move->y = 0;
	else
	{
		move->y = info->game_dims.cube_size
			* tan(degrees_to_radians(ray->angle));
		if (is_ray_southeast(ray))
			move->y *= -1;
	}
}

/* Moves the ray's current intersection to the next one */
void	move_to_new_point(t_coords_d *move, t_coords_d *intersec)
{
	intersec->x = intersec->x + move->x;
	intersec->y = intersec->y + move->y;
}
