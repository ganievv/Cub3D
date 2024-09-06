/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_horizontal_point.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 16:14:25 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-06 16:14:25 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates the first intersection coordinates (x and y) 
*  for a ray facing upward (0 to 180 degrees).
*
*  'p' - player's pixel coordinates. */
void	calc_up_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->intersec.y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size;
	if (ray->intersec.y > 0)
		ray->intersec.y--;

	if (ray->angle == 90.0)
		ray->intersec.x = p->x;
	else
		ray->intersec.x = p->x + ((p->y - ray->intersec.y)
			/ tan(degrees_to_radians(ray->angle)));
}

/* Calculates the first intersection coordinates (x and y) 
*  for a ray facing downward (180 to 360 degrees).
*
*  'p' - player's pixel coordinates. */
void	calc_down_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->intersec.y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size + info->game_dims.cube_size;
	if (ray->intersec.y != info->game_dims.cube_size * (info->player.coords.y + 1))
		ray->intersec.y++;

	if (ray->angle == 270.0)
		ray->intersec.x = p->x;
	else
	{
		ray->intersec.x = p->x + ((p->y - ray->intersec.y)
			/ tan(degrees_to_radians(ray->angle)));
	}
}

/* Calculates the first horizontal intersection point of a ray. */
void	check_first_point(t_ray *ray, t_coords *p, t_cub3d *info)
{
	if (is_ray_facing_up(ray))
		calc_up_intersec(ray, p, info);
	else if (is_ray_facing_down(ray))
		calc_down_intersec(ray, p, info);
}
