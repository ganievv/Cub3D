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

void	step_inside_grid(t_coords_d *coords, double angle)
{
	if (is_ray_northeast(angle) || (angle == 0.0))
	{
		coords->x++;
		if (angle != 0.0)
			coords->y--;
	}
	else if (is_ray_northwest(angle) || (angle == 180.0)
		|| (angle == 90.0))
	{
		if (angle != 90.0)
			coords->x--;
		if (angle != 180.0)
			coords->y--;
	}
	else if (is_ray_southwest(angle) || (angle == 270.0))
	{
		if (angle != 270.0)
			coords->x--;
		coords->y++;
	}
	else if (is_ray_southeast(angle))
	{
		coords->x++;
		coords->y++;
	}
}
