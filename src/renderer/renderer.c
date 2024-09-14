/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 13:18:41 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-12 13:18:41 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Calculates the projected wall slice length for each ray. */
void	calc_proj_slice_len(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < info->plane.width)
	{
		info->ray[i].proj_slice_len = (info->game_dims.cube_size
			/ info->ray[i].dist) * info->game_dims.len_to_plane_center;
		if (info->ray[i].proj_slice_len > info->plane.height)
			info->ray[i].proj_slice_len = info->plane.height;
	}
}

/* Calculates the top position where
*  the wall slice should be drawn */
void	calc_top_wall_y(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < info->plane.width)
	{
		info->ray[i].top_wall_y = (info->plane.height / 2)
			- ((int)info->ray[i].proj_slice_len / 2);
	}
}

/* print function for debugging */
void	print_p_wall_len_and_top_wall_y(t_cub3d *info)
{
	int		i;
	FILE	*fp;

	i = -1;
	fp = fopen("proj_wall_len_test.txt", "w");
	if (fp == NULL)
		return (perror("Error opening file for writing"));
	while (++i < info->plane.width)
	{
		fprintf(fp, "%3d-ray (angle: %6.1f): proj_slice_len: %4d\n", i,
			info->ray[i].angle, info->ray[i].proj_slice_len);
	}
	fclose(fp);
}

/* Renders vertical wall slices on the projection plane */
void	render_wall_slices(t_cub3d *info)
{
	int	i;

	i = 0;
	while (++i < info->plane.width)
	{
		while (info->ray[i].proj_slice_len)
		{
			mlx_put_pixel(info->img, i,
				info->ray[i].top_wall_y, 0xE0E0E0E0);
			info->ray[i].top_wall_y++;
			info->ray[i].proj_slice_len--;
		}
	}
}

void	rendering(t_cub3d *info)
{
	calc_proj_slice_len(info);
	calc_top_wall_y(info);
	print_p_wall_len_and_top_wall_y(info);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->handle = mlx_init(PLANE_WIDTH, PLANE_HEIGHT, "cub3d", true);
	if (!info->handle)
		exit(1);

	info->img = mlx_new_image(info->handle, PLANE_WIDTH, PLANE_HEIGHT);
	if (!info->img || (mlx_image_to_window(info->handle, info->img, 0, 0) < 0))
		exit(1);

	render_wall_slices(info);

	mlx_loop(info->handle);
	mlx_delete_image(info->handle, info->img);
	mlx_terminate(info->handle);
}
