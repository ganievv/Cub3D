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
	ray_caster_init(info);
	check_horizontal_intersect(info);
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
