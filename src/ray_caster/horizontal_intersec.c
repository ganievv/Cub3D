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

/* Calculates the ray intersection coordinates.
*
*  'intersect_point' - variable to store the x and y
*   				   coordinates of the intersection.
*                'p' - player's pixel coordinates.	 */
void	cast_ray(t_ray *ray, t_cub3d *info)
{
	t_coords	intersect_point;
	t_coords	p;

	p.x = grid_to_pixel(info->player.coords.x, info->game_dims.cube_size);
	p.y = grid_to_pixel(info->player.coords.y, info->game_dims.cube_size);
	check_first_point(ray, &p, &intersect_point, info);
	while (!is_wall(&intersect_point, info))
		move_to_new_point(&intersect_point, ray, info);
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
		cast_ray(&info->ray[i], info);
}
