/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:05 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 21:43:03 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cub3d_init(t_dimensions *game_dims, t_cub3d *info)
{
	game_dims->wall_floor_angle = 90.0;
	game_dims->cube_size = 64; /*64x64x64*/

	info->player.fov_angle = 60.0;
	info->player.height = game_dims->cube_size / 2;
	info->player.coords.x = 1; //|
	info->player.coords.y = 2; //|-> (96,160) in unit coordinate
	info->player.direction = NORTH;
	info->player.viewing_angle = 45.0;

	info->plane.height = 200;
	info->plane.width = 320;
	info->plane.center_coords.x = info->plane.width / 2;  // 160
	info->plane.center_coords.y = info->plane.height / 2; // 100

	game_dims->len_to_plane_center = calc_len_to_plane_center(info);
	game_dims->ray_angle_step = calc_ray_angle_step(info);
}

/* Calculates the distance from the player to the center of 
*  the projection plane.								 */
static double	calc_len_to_plane_center(t_cub3d *info)
{
	double	res;

	res = (double)info->plane.center_coords.x /
		tan(degrees_to_radians(info->player.fov_angle / 2));
	return (res);
}

/* Calculates the angle between each ray in the player's field
*  of view (FOV) based on the width of the projection plane. This
*  determines how much the angle changes from one ray to the next. */
static double	calc_ray_angle_step(t_cub3d *info)
{
	return (info->player.fov_angle / info->plane.width);
}

/* Converts degrees to radians
*  Formula: radians = degrees * (π / 180) */
static double	degrees_to_radians(double degrees)
{
	double	rad;

	rad = degrees * (M_PI / 180.0);
	return (rad);
}

void	cast_rays(t_cub3d *info)
{
	t_dimensions	game_dims;

	cub3d_init(&game_dims, info);
}
