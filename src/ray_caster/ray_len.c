/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 11:02:25 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-12 11:02:25 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Computes distances between the player and horizontal
*  and vertical ray intersections, and stores the
*  shortest one in ray->dist. */
void	find_ray_len(t_ray *ray, t_coords_d *p)
{
	double		h_dist;
	double		v_dist;
	t_coords_d	h_sides;
	t_coords_d	v_sides;

	h_sides.x = p->x - ray->h_intersec.x;
	h_sides.y = p->y - ray->h_intersec.y;
	h_dist = sqrt((h_sides.x * h_sides.x) + (h_sides.y * h_sides.y));
	v_sides.x = p->x - ray->v_intersec.x;
	v_sides.y = p->y - ray->v_intersec.y;
	v_dist = sqrt((v_sides.x * v_sides.x) + (v_sides.y * v_sides.y));
	if (h_dist < v_dist)
		ray->dist = h_dist;
	else
		ray->dist = v_dist;
}

/* Corrects the ray distance to remove distortion. */
void	remove_distortion(t_ray *ray, t_cub3d *info)
{
	double	angle_offset;

	angle_offset = ray->angle - info->player.viewing_angle;
	ray->dist *= cos(degrees_to_radians(angle_offset));
}
