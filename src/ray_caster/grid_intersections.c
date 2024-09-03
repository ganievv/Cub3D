/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 21:24:35 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-02 21:24:35 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cast_ray(int ray_index, t_cub3d *info)
{
	t_coords	intersect_point;
	int			p_y;
	int			p_x;

	p_y = convert_grid_to_pixel(info->player.coords.y, info->game_dims.cube_size);
	if (is_ray_facing_up(&info->ray[ray_index]))
		intersect_point.y = floor(p_y / info->game_dims.cube_size)
			* info->game_dims.cube_size - 1;
	else
		intersect_point.y = floor(p_y / info->game_dims.cube_size)
			* info->game_dims.cube_size + info->game_dims.cube_size;
	p_x = convert_grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	intersect_point.x = p_x + (p_y - intersect_point.y)
		/ tan(degrees_to_radians(info->player.viewing_angle));
}

/* Converts grid coordinates to pixel coordinates
*  based on the cube size. */
int	convert_grid_to_pixel(int point, int cube_size)
{
	return (point * cube_size + (cube_size / 2));
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
