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

/*---Used_coordinate_systems----*/
/*  1:                          */
/*         90°                  */
/*          N                   */
/*          |                   */
/* 180°     |                   */
/*  W ------+----------- E 0°   */
/*          |                   */
/*          |                   */
/*         270°                 */
/*          S                   */
/*  2:                          */
/*          Y                   */
/*          ^                   */
/*          |         increases */
/*  (0,0) --+----------> X      */
/*          |                   */
/*          |                   */
/*          v                   */
/*     Y increases              */
/*------------------------------*/

/* Sets the angle for the i-th ray. For the first ray, 
*  the angle is based on the player's viewing angle
*  and FOV. For subsequent rays, the angle is adjusted
*  based on the ray angle step. The angle is then
*  normalized  to be within 0 to 360 degrees. */
void	set_ray_angle(int i, t_cub3d *info)
{
	if (i == 0)
		info->ray[i].angle = info->player.viewing_angle
			+ (info->player.fov_angle / 2);
	else
		info->ray[i].angle = info->ray[i - 1].angle
			- info->game_dims.ray_angle_step;
	info->ray[i].angle = fmod(info->ray[i].angle, 360.0);
	if (info->ray[i].angle < 0.0)
		info->ray[i].angle += 360.0;
}

/* Casts rays and checks both horizontal
*  and vertical intersections.
*
* 'p' - player's pixel coordinates. */
void	cast_rays(t_cub3d *info)
{
	t_coords	p;
	int			i;

	i = -1;
	ray_caster_init(info);
	p.x = grid_to_pixel(info->player.grid.x, info->game_dims.cube_size);
	p.y = grid_to_pixel(info->player.grid.y, info->game_dims.cube_size);
	while (++i < info->plane.width)
	{
		set_ray_angle(i, info);
		//if (i == 0)
		//	info->ray[i].angle = 95.0;
		check_points_h(&info->ray[i], &p, info);
		check_points_v(&info->ray[i], &p, info);
	}
}

char	**set_map(void)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * 6);
	if (!map)
		exit(1);
	map[0] = ft_strdup("111111");
	map[1] = ft_strdup("100001");
	map[2] = ft_strdup("100001");
	map[3] = ft_strdup("10N001");
	map[4] = ft_strdup("111111");
	map[5] = NULL;
	return (map);
}

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

void	print_intersec_points(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < info->plane.width)
	{
		printf("%3d-ray (angle: %6.1f): h_pixel.x: %4d, h_pixel.y: %4d"
			"\th_grid.x:  %4d, h_grid.y:  %4d", i, info->ray[i].angle,
			info->ray[i].h_intersec.x, info->ray[i].h_intersec.y,
			pixel_to_grid(info->ray[i].h_intersec.x, info->game_dims.cube_size),
			pixel_to_grid(info->ray[i].h_intersec.y, info->game_dims.cube_size));
		printf("\n\t\t\t\t\t\t ");
		printf("v_pixel.x: %4d, v_pixel.y: %4d"
			"\tv_grid.x:  %4d, v_grid.y:  %4d\n\n",
			info->ray[i].v_intersec.x, info->ray[i].v_intersec.y,
			pixel_to_grid(info->ray[i].v_intersec.x, info->game_dims.cube_size),
			pixel_to_grid(info->ray[i].v_intersec.y, info->game_dims.cube_size));
	}
}

int	main(void)
{
	t_cub3d	info;

	info.map.map = set_map();
	info.map.height = 5;
	info.map.width = 6;
	cast_rays(&info);
	print_intersec_points(&info);
	free_map(&info.map.map);
	return (0);
}

/* apt-get update
*  apt-get install cmake
*  apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
*  MLX42FLAGS		:= -lglfw #-framework Cocoa -framework OpenGL -framework IOKit */
