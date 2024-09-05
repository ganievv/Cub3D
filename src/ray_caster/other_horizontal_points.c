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

/* Moves the ray's intersection point to the next grid
*  line, to calculate the next intersection. */
void	move_to_new_point(t_ray *ray, t_cub3d *info)
{
	int	y_a;
	int	x_a;

	if (is_northeast_s(ray) || is_northwest_s(ray))
		y_a = -info->game_dims.cube_size;
	else if (is_southwest_s(ray) || is_southeast_s(ray))
		y_a = info->game_dims.cube_size;
	else
		x_a = y_a / tan(degrees_to_radians(ray->angle));

	ray->intersec.x = ray->intersec.x + x_a;
	ray->intersec.y = ray->intersec.y + y_a;
}
