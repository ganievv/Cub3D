/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:18:41 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/18 22:40:51 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_cub3d(t_cub3d *info, int ret, bool mlx_term)
{
	if (ret)
		ft_putstr_fd("Error\n", 2);
	free_cub3d_input(info);
	if (info->img)
		mlx_delete_image(info->mlx, info->img);
	delete_textures_and_imgs(info);
	if (mlx_term)
		mlx_terminate(info->mlx);
	exit(ret);
}

void	init_render_data(t_cub3d *info)
{
	info->mlx = NULL;
	info->img = NULL;
	info->input.ea.texture = NULL;
	info->input.no.texture = NULL;
	info->input.we.texture = NULL;
	info->input.so.texture = NULL;
	info->input.ea.img = NULL;
	info->input.no.img = NULL;
	info->input.we.img = NULL;
	info->input.so.img = NULL;
	info->map.map = NULL;
	info->input.no.path = NULL;
	info->input.so.path = NULL;
	info->input.we.path = NULL;
	info->input.ea.path = NULL;
}

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
		free_cub3d(info, 1, false);
	info->img = mlx_new_image(info->mlx, PLANE_WIDTH, PLANE_HEIGHT);
	if (!info->img)
		free_cub3d(info, 1, true);
	load_textures(info);
	textures_to_img(info);
	resize_imgs(info);
	draw_frame(info);
	if (mlx_image_to_window(info->mlx, info->img, 0, 0) < 0)
		free_cub3d(info, 1, true);
	mlx_close_hook(info->mlx, close_window, info);
	mlx_loop_hook(info->mlx, handle_keys, info);
	mlx_key_hook(info->mlx, handle_esc_key, info);
	mlx_loop(info->mlx);
}
