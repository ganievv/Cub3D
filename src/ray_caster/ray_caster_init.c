/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 20:24:44 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-02 20:24:44 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_caster_init(t_dimensions *game_dims, t_cub3d *info)
{
	game_dims->wall_floor_angle = 90.0;
	game_dims->cube_size = 64; /*64x64x64*/

	info->player.fov_angle = 60.0;
	info->player.height = game_dims->cube_size / 2;
	set_player_coordinates(info);
	set_player_direction(info);
	set_player_viewing_angle(info);

	info->plane.height = 200;
	info->plane.width = 320;
	info->plane.center_coords.x = info->plane.width / 2;  // 160
	info->plane.center_coords.y = info->plane.height / 2; // 100

	game_dims->len_to_plane_center = calc_len_to_plane_center(info);
	game_dims->ray_angle_step = calc_ray_angle_step(info);
}

/* Converts degrees to radians
*  Formula: radians = degrees * (π / 180) */
double	degrees_to_radians(double degrees)
{
	double	rad;

	rad = degrees * (M_PI / 180.0);
	return (rad);
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
	return (info->player.fov_angle / (double)info->plane.width);
}
