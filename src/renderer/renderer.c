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
	}
}

void	rendering(t_cub3d *info)
{
	calc_proj_slice_len(info);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->handle = mlx_init(PLANE_WIDTH, PLANE_HEIGHT, "cub3d", true);
	if (!info->handle)
		exit(1);

	info->img = mlx_new_image(info->handle, PLANE_WIDTH, PLANE_HEIGHT);
	if (!info->img || (mlx_image_to_window(info->handle, info->img, 0, 0) < 0))
		exit(1);
	mlx_put_pixel(info->img,  PLANE_WIDTH / 2,  PLANE_HEIGHT / 2, 0xFF0000FF);
	mlx_loop(info->handle);
	mlx_terminate(info->handle);
}
