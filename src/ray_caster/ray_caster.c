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

void	cast_rays(t_cub3d *info)
{
	int	i;

	i = -1;
	ray_caster_init(info);
	while (++i < info->plane.width)
	{
		set_ray_angle(i, info);
		check_horizontal_points(&info->ray[i], info);
		check_vertical_points(&info->ray[i], info);
	}
}

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

//char	**set_map(void)
//{
//	char	**map;

//	map = (char **)malloc(sizeof(char *) * 4);
//	map[0] = ft_strdup("1111");
//	map[1] = ft_strdup("0000");
//	map[2] = ft_strdup("0000");
//	map[3] = ft_strdup("0N00");
//	return (map);
//}

int	main(void)
{
	t_cub3d info;

	info.map.map = set_map();
	info.map.height = 4;
	info.map.width = 6;
	cast_rays(&info);
}

//if (ray->angle == 0.0)
//{
//	intersec->y = p->y;
//	intersec->x = p->x + (info->game_dims.cube_size / 2);
//}


/* apt-get update
*  apt-get install cmake
*  apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
*  MLX42FLAGS		:= -lglfw #-framework Cocoa -framework OpenGL -framework IOKit */
