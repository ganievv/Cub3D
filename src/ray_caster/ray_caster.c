/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:05 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/17 09:42:58 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* you need to add checking of return values of mlx functions */

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

/* Normalizes the angle to be within 0 to 360 degrees */
double	normalize_angle(double angle)
{
	angle = fmod(angle, 360.0);
	if (angle < 0.0)
		angle += 360.0;
	return (angle);
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
	info->ray[i].angle = normalize_angle(info->ray[i].angle);
}

/* Casts rays and checks both horizontal
*  and vertical intersections.
*
* 'step' - var for step_inside_grid() in
*  check_points_h() and check_points_v() */
void	cast_rays(t_cub3d *info)
{
	int	i;

	i = -1;
	//info->player.viewing_angle = 45.0;
	while (++i < info->plane.width)
	{
		set_ray_angle(i, info);
		check_points_h(&info->ray[i], &info->player.pixel, info);
		check_points_v(&info->ray[i], &info->player.pixel, info);
		find_ray_len(&info->ray[i], &info->player.pixel);
		remove_distortion(&info->ray[i], info);
		calc_proj_slice_len(&info->ray[i], info);
		calc_top_wall_y(&info->ray[i], info);
	}
}

// If I change this one will continue t
char	**set_map(void)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * 10);
	if (!map)
		exit(1);
	map[0] = ft_strdup(" 111 111111         11");
	map[1] = ft_strdup("101011000011      1100111");
	map[2] = ft_strdup("1010110000001111111100111");
	map[3] = ft_strdup("1000110001000000000S00111");
	map[4] = ft_strdup("1000000000000000000000111");
	map[5] = ft_strdup("1000000000000000000010111");
	map[6] = ft_strdup("1000000000000000000110111");
	map[7] = ft_strdup("1111111111111111111000111");
	map[8] = ft_strdup("                   111");
	map[9] = NULL;
	return (map);
}

//map[0] = ft_strdup(" 1 11 1111 11         11");
//map[1] = ft_strdup("10 1011000 011      1100111");
//map[2] = ft_strdup("10 1011000 0001111111100111");
//map[3] = ft_strdup("10 0011000 1000000000S00111");
//map[4] = ft_strdup("10 0000000 0000000000000111");
//map[5] = ft_strdup("11 1111111 1111111111111111");
//map[6] = ft_strdup("                         ");
//map[7] = ft_strdup("11 1111111 1111111111111111");
//map[8] = ft_strdup("                         ");
//map[9] = ft_strdup("                         ");
//map[10] = ft_strdup("10 0000000 0000000000010111");
//map[11] = ft_strdup("10 0000000 0000000000110111");
//map[12] = ft_strdup("11 1111111 1111111111000111");
//map[13] = ft_strdup("                   111");
//map[14] = NULL;

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

/* function for debugging */
void	save_calculated_data(t_cub3d *info)
{
	FILE	*fp;
	int		i;

	i = -1;
	fp = fopen("calc_data.txt", "w");
	if (!fp)
		return (perror("Error opening file for writing"));
	while (++i < info->plane.width)
	{
		fprintf(fp, "%3d-ray (angle: %6.1f): h_pixel.x: %4.1f, h_pixel.y: %4.1f"
			"\th_grid.x: %d, h_grid.y: %d", i, info->ray[i].angle,
			info->ray[i].h_intersec.x, info->ray[i].h_intersec.y,
			pixel_to_grid(info->ray[i].h_intersec.x, info->game_dims.cube_size),
			pixel_to_grid(info->ray[i].h_intersec.y,
				info->game_dims.cube_size));
		fprintf(fp, "\n\t\t\t\t\t\t v_pixel.x: %4.1f, v_pixel.y: %4.1f"
			"\tv_grid.x: %d, v_grid.y: %d",
			info->ray[i].v_intersec.x, info->ray[i].v_intersec.y,
			pixel_to_grid(info->ray[i].v_intersec.x, info->game_dims.cube_size),
			pixel_to_grid(info->ray[i].v_intersec.y,
				info->game_dims.cube_size));
		fprintf(fp, "\n\t\t\t\t\t\t ray_dist:       %4.1f", info->ray[i].dist);
		fprintf(fp, "\n\t\t\t\t\t\t proj_slice_len:%4d\n\n",
			info->ray[i].proj_slice_len);
	}
	fclose(fp);
}

int	main(void)
{
	t_cub3d	info;

	info.map.map = set_map();
	info.map.height = 9;
	info.map.width = 25;
	ray_caster_init(&info);
	cast_rays(&info);
	save_calculated_data(&info);
	rendering(&info);
	free_map(&info.map.map);
	return (0);
}

/* apt-get update -y
*  apt-get install cmake -y
*  apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev -y */
