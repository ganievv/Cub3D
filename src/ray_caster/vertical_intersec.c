/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 18:19:18 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-06 18:19:18 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calc_right_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->v_intersec.x = floor(p->x / info->game_dims.cube_size)
		* info->game_dims.cube_size + info->game_dims.cube_size;
	ray->v_intersec.x++;

	if (ray->angle == 0.0)
		ray->v_intersec.y = p->y;
	else
		ray->v_intersec.y = p->y + (p->x - ray->v_intersec.x)
				* tan(degrees_to_radians(ray->angle));
}

void	calc_left_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->v_intersec.x = floor(p->x / info->game_dims.cube_size)
		* info->game_dims.cube_size;
	if (ray->v_intersec.x > 0)
		ray->v_intersec.x--;

	if (ray->angle == 180.0)
		ray->v_intersec.y = p->y;
	else
		ray->v_intersec.y = p->y + (p->x - ray->v_intersec.x)
				* tan(degrees_to_radians(ray->angle));
}

/* Calculates the first vertical intersection point of a ray. */
void	check_first_point_v(t_ray *ray, t_coords *p, t_cub3d *info)
{
	if (is_ray_facing_right(ray))
		calc_right_intersec(ray, p, info);
	else if (is_ray_facing_left(ray))
		calc_left_intersec(ray, p, info);
}

/* Calculates the coordinates where the
*  ray intersects a wall vertically.
*
*  'p' - player's pixel coordinates. */
void	check_points_v(t_ray *ray, t_coords *p, t_cub3d *info)
{
	t_coords	move;

	if (ray->angle != 90.0 && ray->angle != 270.0)
	{
		check_first_point_v(ray, p, info);
		set_movement_len_v(&move, ray, info);
		while (!is_wall(ray, info))
			move_to_new_point_v(&move, ray);
	}
}
