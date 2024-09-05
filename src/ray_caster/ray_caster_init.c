/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:24:44 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 23:29:02 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_caster_init(t_cub3d *info)
{
	info->game_dims.wall_floor_angle = 90.0;
	info->game_dims.cube_size = CUBE_SIZE; /*64x64x64*/

	info->player.fov_angle = FOV_ANGLE;
	info->player.height = info->game_dims.cube_size / 2;
	set_player_coordinates(info);
	set_player_viewing_angle(info);

	info->plane.height = PLANE_HEIGHT;
	info->plane.width = PLANE_WIDTH;
	info->plane.center.x = info->plane.width / 2;  // 160
	info->plane.center.y = info->plane.height / 2; // 100

	info->game_dims.len_to_plane_center = calc_len_to_plane_center(info);
	info->game_dims.ray_angle_step = calc_ray_angle_step(info);
}

/* Calculates the distance from the player to the center of 
*  the projection plane.								 */
static double	calc_len_to_plane_center(t_cub3d *info)
{
	double	res;

	res = ((double)info->plane.width / 2) /
		tan(degrees_to_radians(info->player.fov_angle / 2));
	return (res);
}

/* Calculates the angle between each ray in the player's field
*  of view (FOV) based on the width of the projection plane. This
*  determines how much the angle changes from one ray to the next. */
static double	calc_ray_angle_step(t_cub3d *info)
{
	return (info->player.fov_angle / (double)info->plane.width);
}
