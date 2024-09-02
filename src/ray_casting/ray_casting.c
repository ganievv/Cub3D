/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:05 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 18:41:43 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Represents a 2D point
*  with x and y coordinates. */
typedef struct s_coords
{
	int			x;
	int			y;
}	t_coords;

typedef struct s_dimensions
{
	char			**map;
	double			wall_floor_angle;
	int				cube_size;
	double			player_fov_angle; /* a field of view */
	int				player_height;
	t_coords		player_coords;
	double			player_viewing_angle;
	
	int				plane_height;
	int				plane_width;
	t_coords		plane_center_coords;
	double			len_to_plane_center;

	double			ray_angle_step;
}	t_dimensions;

/*
*
*  1111
*  0001
*  0N01
*
*
**/

void	cub3d_init(t_dimensions *game_dims)
{
	game_dims->wall_floor_angle = 90.0;
	game_dims->cube_size = 64; /*64x64x64*/
	game_dims->player_fov_angle = 60.0;
	game_dims->player_height = game_dims->cube_size / 2;

	game_dims->player_coords.x = 1; //|
	game_dims->player_coords.y = 2; //|-> (96,160) in unit coordinate
	game_dims->player_viewing_angle = 45.0;

	game_dims->plane_height = 200;
	game_dims->plane_width = 320;
	game_dims->plane_center_coords.x = game_dims->plane_width / 2;  // 160
	game_dims->plane_center_coords.y = game_dims->plane_height / 2; // 100
	game_dims->len_to_plane_center = calc_len_to_plane_center(game_dims);

	game_dims->ray_angle_step = calc_ray_angle_step(game_dims);
}

/* Calculates the distance from the player to the center of 
*  the projection plane.								 */
double	calc_len_to_plane_center(t_dimensions *game_dims)
{
	double	res;

	res = (double)game_dims->plane_center_coords.x /
		tan(degrees_to_radians(game_dims->player_fov_angle / 2));
	return (res);
}

/* Converts degrees to radians
*  Formula: radians = degrees * (π / 180) */
double	degrees_to_radians(double degrees)
{
	double	rad;

	rad = degrees * (M_PI / 180.0);
	return (rad);
}

/* Calculates the angle between each ray in the player's field
*  of view (FOV) based on the width of the projection plane. This
*  determines how much the angle changes from one ray to the next. */
double	calc_ray_angle_step(t_dimensions *game_dims)
{
	return (game_dims->player_fov_angle / game_dims->plane_width);
}

void	cast_rays(void)
{
	t_dimensions	game_dims;

	cub3d_init(&game_dims);
}
