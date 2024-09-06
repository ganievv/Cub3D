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
void	cast_horizontal_ray(t_ray *ray, t_cub3d *info)
{
	t_coords	p;
	t_coords	move;

	p.x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	p.y = grid_to_pixel(info->player.coords.y, info->game_dims.cube_size);
	if (ray->angle != 0.0 && ray->angle != 180.0)
	{
		check_first_point(ray, &p, info);
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

	x = pixel_to_grid(ray->intersec.x, info->game_dims.cube_size);
	y = pixel_to_grid(ray->intersec.y, info->game_dims.cube_size);
	return (info->map.map[y][x] == '1');
}

/* Sets the angle for the i-th ray. For the first ray, 
*  the angle is based on the player's viewing angle
*  and FOV. For subsequent rays, the angle is adjusted
*  based on the ray angle step. The angle is then
*  normalized  to be within 0 to 360 degrees. */
void	set_ray_angle(int i, t_cub3d *info)
{
	if (i == 0)
		info->ray[i].angle = info->player.viewing_angle
			+ (info->player.fov_angle / 2);
	else
		info->ray[i].angle = info->ray[i - 1].angle
			- info->game_dims.ray_angle_step;
	info->ray[i].angle = fmod(info->ray[i].angle, 360.0);
	if (info->ray[i].angle < 0.0)
		info->ray[i].angle += 360.0;
}

/* Checks and calculates horizontal intersections
*  for raycasting to find walls. */
void	check_horizontal_intersect(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < info->plane.width)
	{
		set_ray_angle(i, info);
		cast_horizontal_ray(&info->ray[i], info);
	}
}
