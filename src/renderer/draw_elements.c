/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-18 18:24:31 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-18 18:24:31 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_floor(int i, t_cub3d *info)
{
	while (info->ray[i].top_wall_y < info->plane.height)
		mlx_put_pixel(info->img, i, info->ray[i].top_wall_y++, FLOOR_COLOR);
}

void	draw_ceiling(int i, t_cub3d *info)
{
	int	start;

	start = 0;
	while (start < info->ray[i].top_wall_y)
		mlx_put_pixel(info->img, i, start++, CEILING_COLOR);
}

void	draw_wall_slice(int i, double step,
	t_coords_d *texture, t_cub3d *info)
{
	while (info->ray[i].proj_slice_len
		&& info->ray[i].top_wall_y < info->plane.height)
	{
		mlx_put_pixel(info->img, i, info->ray[i].top_wall_y,
			calc_texture_color((int)texture->x, (int)texture->y,
				&info->ray[i], info));
		info->ray[i].proj_slice_len--;
		info->ray[i].top_wall_y++;
		texture->y += step;
	}
}
