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

void	cast_ray(int ray_index, t_cub3d *info)
{
	t_coords	intersect_point;
	int			p_y;

	p_y = grid_to_pixel(info->player.coords.y, info->game_dims.cube_size);
	if (is_ray_facing_up(&info->ray[ray_index]))
		intersect_point.y = floor(p_y / info->game_dims.cube_size)
			* info->game_dims.cube_size - 1;
	else
		intersect_point.y = floor(p_y / info->game_dims.cube_size)
			* info->game_dims.cube_size + info->game_dims.cube_size;
	if (info->ray[ray_index].angle > 0.0 && info->ray[ray_index].angle < 90.0)
		northeast_sector(p_y, &intersect_point, info);
	else if (info->ray[ray_index].angle > 90.0 && info->ray[ray_index].angle < 180.0)
		northwest_sector(p_y, &intersect_point, info);
	else if (info->ray[ray_index].angle > 180.0 && info->ray[ray_index].angle < 270.0)
		southwest_sector(p_y, &intersect_point, info);
	else
		southeast_sector(p_y, &intersect_point, info);
	while (!is_wall(&intersect_point, info))
		;
}

/* Checks if the intersection point is a wall */
bool	is_wall(t_coords *intersect_point, t_cub3d *info)
{
	int	x;
	int	y;

	x = pixel_to_grid(intersect_point->x, info->game_dims.cube_size);
	y = pixel_to_grid(intersect_point->y, info->game_dims.cube_size);
	return (info->map.map[y][x] == '1');
}

/* Checks if the ray is facing upward */
bool	is_ray_facing_up(t_ray *ray)
{
	return (ray->angle >= 0.0 && ray->angle <= 180.0);
}

/* Sets the initial ray angle by adjusting the viewing angle to
*  the left edge of the player's FOV. The angle then is normalized
*  to ensure it falls within the 0 to 360-degree range.	*/
void	set_initial_ray_angle(t_cub3d *info)
{
	info->ray[0].angle = info->player.viewing_angle + (info->player.fov_angle / 2);
	info->ray[0].angle = fmod(info->ray[0].angle, 360.0);
	if (info->ray[0].angle < 0.0)
		info->ray[0].angle += 360.0;
}

/* Checks and calculates horizontal intersections
*  for raycasting to find walls. */
void	check_horizontal_intersect(t_cub3d *info)
{
	int	i;

	set_initial_ray_angle(info);
	i = -1;
	while (++i < info->plane.width)
		cast_ray(i, info);
}
