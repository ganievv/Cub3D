/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:10:50 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/11 04:08:51 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	load_textures(t_cub3d *info)
{
	info->input.ea.texture = mlx_load_png(info->input.ea.path);
	if (!info->input.ea.texture)
		free_cub3d(info, 1, true);
	info->input.no.texture = mlx_load_png(info->input.no.path);
	if (!info->input.no.texture)
		free_cub3d(info, 1, true);
	info->input.we.texture = mlx_load_png(info->input.we.path);
	if (!info->input.we.texture)
		free_cub3d(info, 1, true);
	info->input.so.texture = mlx_load_png(info->input.so.path);
	if (!info->input.so.texture)
		free_cub3d(info, 1, true);
}

void	delete_textures_and_imgs(t_cub3d *info)
{
	if (info->input.ea.texture)
		mlx_delete_texture(info->input.ea.texture);
	if (info->input.no.texture)
		mlx_delete_texture(info->input.no.texture);
	if (info->input.we.texture)
		mlx_delete_texture(info->input.we.texture);
	if (info->input.so.texture)
		mlx_delete_texture(info->input.so.texture);
	if (info->input.ea.img)
		mlx_delete_image(info->mlx, info->input.ea.img);
	if (info->input.no.img)
		mlx_delete_image(info->mlx, info->input.no.img);
	if (info->input.we.img)
		mlx_delete_image(info->mlx, info->input.we.img);
	if (info->input.so.img)
		mlx_delete_image(info->mlx, info->input.so.img);
}

void	textures_to_img(t_cub3d *info)
{
	info->input.ea.img = mlx_texture_to_image(info->mlx,
			info->input.ea.texture);
	info->input.no.img = mlx_texture_to_image(info->mlx,
			info->input.no.texture);
	info->input.we.img = mlx_texture_to_image(info->mlx,
			info->input.we.texture);
	info->input.so.img = mlx_texture_to_image(info->mlx,
			info->input.so.texture);
}

void	resize_imgs(t_cub3d *info)
{
	mlx_resize_image(info->input.ea.img, info->game_dims.cube_size,
		info->game_dims.cube_size);
	mlx_resize_image(info->input.no.img, info->game_dims.cube_size,
		info->game_dims.cube_size);
	mlx_resize_image(info->input.so.img, info->game_dims.cube_size,
		info->game_dims.cube_size);
	mlx_resize_image(info->input.we.img, info->game_dims.cube_size,
		info->game_dims.cube_size);
}
