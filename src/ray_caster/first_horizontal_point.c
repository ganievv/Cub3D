/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_intersec_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 13:29:37 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 13:29:37 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates x and y coordinates of the first ray intersection
*  in the northeast sector (0 to 90 degrees).
*
*  'intersec' - variable to store the x and y
*				coordinates of the intersection.
*		  'p' - player's pixel coordinates.	 */
void	xy_northeast_calc(t_ray *ray, t_coords *p,
	t_coords *intersec, t_cub3d *info)
{
	intersec->y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size;
	if (intersec->y > 0)
		intersec->y--;

	intersec->x = p->x + ((p->y - intersec->y)
		/ tan(degrees_to_radians(ray->angle)));
}

/* Calculates x and y coordinates of the first ray intersection
*  in the northwest sector (90 to 180 degrees). */
void	xy_northwest_calc(t_ray *ray, t_coords *p,
	t_coords *intersec, t_cub3d *info)
{
	double	new_angle;

	intersec->y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size;
	if (intersec->y > 0)
		intersec->y--;

	new_angle = 180.0 - ray->angle;
	intersec->x = p->x - ((p->y - intersec->y)
		/ tan(degrees_to_radians(new_angle)));
}

/* Calculates x and y coordinates of the first ray intersection
*  in the southwest sector (180 to 270 degrees). */
void	xy_southwest_calc(t_ray *ray, t_coords *p,
	t_coords *intersec, t_cub3d *info)
{
	double	new_angle;

	intersec->y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size + info->game_dims.cube_size;
	if (intersec->y != info->game_dims.cube_size * (info->player.coords.y + 1))
		intersec->y++;

	new_angle = ray->angle - 180.0;
	intersec->x = p->x - ((intersec->y - p->y)
		/ tan(degrees_to_radians(new_angle)));
}

/* Calculates x and y coordinates of the first ray intersection
*  in the southeast sector (270 to 360 degrees). */
void	xy_southeast_calc(t_ray *ray, t_coords *p,
	t_coords *intersec, t_cub3d *info)
{
	double	new_angle;

	intersec->y = floor(p->y / info->game_dims.cube_size)
		* info->game_dims.cube_size + info->game_dims.cube_size;
	if (intersec->y != info->game_dims.cube_size * (info->player.coords.y + 1))
		intersec->y++;

	new_angle = 360.0 - ray->angle;
	intersec->x = p->x + ((intersec->y - p->y)
		/ tan(degrees_to_radians(new_angle)));
}

void	check_first_point(t_ray *ray, t_coords *p,
	t_coords *intersect_point, t_cub3d *info)
{
	if (is_northeast_s(ray))
		xy_northeast_calc(ray, p, intersect_point, info);
	else if (is_northwest_s(ray))
		xy_northwest_calc(ray, p, intersect_point, info);
	else if (is_southwest_s(ray))
		xy_southwest_calc(ray, p, intersect_point, info);
	else
		xy_southeast_calc(ray, p, intersect_point, info);
}
