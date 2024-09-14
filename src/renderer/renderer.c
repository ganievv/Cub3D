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
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->handle = mlx_init(PLANE_WIDTH, PLANE_HEIGHT, "cub3d", true);
	if (!info->handle)
		exit(1);

	info->img = mlx_new_image(info->handle, PLANE_WIDTH, PLANE_HEIGHT);
	if (!info->img)
		exit(1);

	render_wall_slices(info);
	if (mlx_image_to_window(info->handle, info->img, 0, 0) < 0)
		exit(1);

	mlx_close_hook(info->handle, close_window, info);
	mlx_key_hook(info->handle, handle_keys, info);
	mlx_loop(info->handle);
	mlx_delete_image(info->handle, info->img);
	mlx_terminate(info->handle);
}
