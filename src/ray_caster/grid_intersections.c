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
}

/* This function sets the initial ray angle by adjusting the
*  viewing angle to the left edge of the player's FOV.	  */
void	set_initial_ray_angle(t_cub3d *info)
{
	info->ray[0].angle = info->player.viewing_angle - (info->player.fov_angle / 2);
}

/* This function checks and calculates horizontal
*  intersections for raycasting to find walls. */
void	check_horizontal_intersect(t_cub3d *info)
{
	int	i;

	set_initial_ray_angle(info);
	i = -1;
	while (++i < info->plane.width)
		cast_ray(i, info);
}
