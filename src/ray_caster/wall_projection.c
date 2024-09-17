/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-14 16:08:46 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-14 16:08:46 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates the projected wall slice length for a ray. */
void	calc_proj_slice_len(t_ray *ray, t_cub3d *info)
{
	ray->proj_slice_len = (info->game_dims.cube_size / ray->dist)
		* info->game_dims.len_to_plane_center;
	if (ray->proj_slice_len > info->plane.height)
		ray->proj_slice_len = info->plane.height;
}

/* Calculates the top position where the wall slice should be drawn */
void	calc_top_wall_y(t_ray *ray, t_cub3d *info)
{
	ray->top_wall_y = (info->plane.height / 2) - (ray->proj_slice_len / 2);
}
