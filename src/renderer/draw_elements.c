/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:24:31 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/11 02:34:52 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	calc_texture_x(t_ray *ray, t_cub3d *info)
{
	int	x;

	if (ray->is_v_intersec)
		x = (int)ray->v_intersec.y % info->game_dims.cube_size;
	else
		x = (int)ray->h_intersec.x % info->game_dims.cube_size;
	return (x);
}

uint32_t	calc_texture_color(int x, int y, t_ray *ray, t_cub3d *info)
{
	mlx_image_t	*img;
	uint32_t	index;
	uint32_t	color;
	uint8_t		rgba[4];

	if (ray->is_v_intersec && is_ray_right(ray->angle))
		img = info->input.ea.img;
	else if (ray->is_v_intersec && is_ray_left(ray->angle))
		img = info->input.we.img;
	else if (!ray->is_v_intersec && is_ray_up(ray->angle))
		img = info->input.no.img;
	else if (!ray->is_v_intersec && is_ray_down(ray->angle))
		img = info->input.so.img;
	else
		return (0x000000FC);
	index = (y * img->width + x) * BYTES_PER_PIXEL;
	rgba[0] = img->pixels[index];
	rgba[1] = img->pixels[index + 1];
	rgba[2] = img->pixels[index + 2];
	rgba[3] = img->pixels[index + 3];
	color = (rgba[0] << 24) | (rgba[1] << 16) | (rgba[2] << 8) | rgba[3];
	return (color);
}

void	draw_floor(int i, t_ray *ray, t_cub3d *info)
{
	while (ray->top_wall_y < info->plane.height)
		mlx_put_pixel(info->img, i, ray->top_wall_y++,
			info->input.floor.color);
}

void	draw_ceiling(int i, t_ray *ray, t_cub3d *info)
{
	int			start;

	start = 0;
	while (start < ray->top_wall_y)
		mlx_put_pixel(info->img, i, start++,
			info->input.ceilling.color);
}

void	draw_wall_slice(int i, t_ray *ray, t_cub3d *info)
{
	t_coords_d	texture;
	double		step;

	texture.y = 0;
	texture.x = calc_texture_x(ray, info);
	step = (double)info->game_dims.cube_size / (double)ray->proj_slice_len;
	if (ray->proj_slice_len > info->plane.height)
		texture.y = (ray->proj_slice_len - info->plane.height) / 2 * step;
	while (ray->proj_slice_len && (ray->top_wall_y < info->plane.height))
	{
		mlx_put_pixel(info->img, i, ray->top_wall_y,
			calc_texture_color((int)texture.x, (int)texture.y, ray, info));
		ray->proj_slice_len--;
		ray->top_wall_y++;
		texture.y += step;
	}
}
