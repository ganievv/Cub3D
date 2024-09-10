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

/* Calculates the first intersection coordinates (x and y) 
*  for a ray facing upward (0 to 180 degrees).
*
*  'p' - player's pixel coordinates. */
void	calc_up_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->h_intersec.y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size;
	ray->h_intersec.y--;

	if (ray->angle == 90.0)
		ray->h_intersec.x = p->x;
	else
		ray->h_intersec.x = p->x + ((p->y - ray->h_intersec.y)
				/ tan(degrees_to_radians(ray->angle)));
}

/* Calculates the first intersection coordinates (x and y) 
*  for a ray facing downward (180 to 360 degrees).
*
*  'p' - player's pixel coordinates. */
void	calc_down_intersec(t_ray *ray, t_coords *p, t_cub3d *info)
{
	ray->h_intersec.y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size + info->game_dims.cube_size;
	ray->h_intersec.y++;

	if (ray->angle == 270.0)
		ray->h_intersec.x = p->x;
	else
	{
		ray->h_intersec.x = p->x + ((p->y - ray->h_intersec.y)
				/ tan(degrees_to_radians(ray->angle)));
	}
}

/* Determines if the current horizontal
*  intersection is with a wall. */
bool	is_wall(t_ray *ray, t_cub3d *info)
{
	int	x;
	int	y;

	x = pixel_to_grid(ray->h_intersec.x, info->game_dims.cube_size);
	y = pixel_to_grid(ray->h_intersec.y, info->game_dims.cube_size);
	return (info->map.map[y][x] == '1');
}

/* Determines the first horizontal intersection point.
*
*  'p' - player's pixel coordinates. */
void	check_first_point_h(t_ray *ray, t_coords *p, t_cub3d *info)
{
	if (is_ray_facing_up(ray))
		calc_up_intersec(ray, p, info);
	else if (is_ray_facing_down(ray))
		calc_down_intersec(ray, p, info);
}

/* Iterates through horizontal intersections
*  to find where the ray hits a wall.
*
* 'p' - player's pixel coordinates. */
void	check_points_h(t_ray *ray, t_coords *p, t_cub3d *info)
{
	t_coords	move;

	if (ray->angle != 0.0 && ray->angle != 180.0)
	{
		check_first_point_h(ray, p, info);
		set_movement_len_h(&move, ray, info);
		while (!is_wall(ray, info))
			move_to_new_point(&move, ray);
	}
}
