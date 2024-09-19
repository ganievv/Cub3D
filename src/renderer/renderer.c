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

void	draw_frame(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < info->plane.width)
	{
		draw_ceiling(i, &info->ray[i], info);
		draw_wall_slice(i, &info->ray[i], info);
		draw_floor(i, &info->ray[i], info);
	}
}

void	rendering(t_cub3d *info)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->mlx = mlx_init(PLANE_WIDTH, PLANE_HEIGHT, "cub3d", true);
	if (!info->mlx)
		exit(1);
	info->img = mlx_new_image(info->mlx, PLANE_WIDTH, PLANE_HEIGHT);
	if (!info->img)
		exit(1);
	load_textures(info);
	textures_to_img(info);
	resize_imgs(info);
	draw_frame(info);
	if (mlx_image_to_window(info->mlx, info->img, 0, 0) < 0)
		exit(1);
	mlx_close_hook(info->mlx, close_window, info);
	mlx_loop_hook(info->mlx, handle_keys, info);
	mlx_key_hook(info->mlx, handle_esc_key, info);
	mlx_loop(info->mlx);
}
