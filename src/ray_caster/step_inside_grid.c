/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_inside_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 13:47:49 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-11 13:47:49 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	step_inside_grid(t_coords_d *intersec, t_ray *ray)
{
	if (is_ray_northeast(ray) || (ray->angle == 0.0))
	{
		intersec->x++;
		if (ray->angle != 0.0)
			intersec->y--;
	}
	else if (is_ray_northwest(ray) || (ray->angle == 180.0)
		|| (ray->angle == 90.0))
	{
		if (ray->angle != 90.0)
			intersec->x--;
		if (ray->angle != 180.0)
			intersec->y--;
	}
	else if (is_ray_southwest(ray) || (ray->angle == 270.0))
	{
		if (ray->angle != 270.0)
			intersec->x--;
		intersec->y++;
	}
	else if (is_ray_southeast(ray))
	{
		intersec->x++;
		intersec->y++;
	}
}
