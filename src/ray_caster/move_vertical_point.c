/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vertical_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 20:27:15 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-06 20:27:15 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_movement_len_v(t_coords *move, t_ray *ray, t_cub3d *info)
{
	if (is_ray_facing_right(ray))
		move->x = info->game_dims.cube_size;
	else if (is_ray_facing_left(ray))
		move->x = -info->game_dims.cube_size;

	move->y = info->game_dims.cube_size * tan(degrees_to_radians(ray->angle));
}

void	move_to_new_point_v(t_coords *move, t_ray *ray)
{
	ray->v_intersec.x = ray->v_intersec.x + move->x;
	ray->v_intersec.y = ray->v_intersec.y + move->y;
}
