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

/* Calculates the first vertical intersection point of a ray. */
void	check_first_v_point(t_ray *ray, t_coords *p, t_cub3d *info)
{
	if (is_ray_facing_right(ray))
		calc_right_intersec(ray, p, info);
	else if (is_ray_facing_left(ray))
		calc_left_intersec(ray, p, info);
}

void	check_vertical_points(t_ray *ray, t_cub3d *info)
{
}
