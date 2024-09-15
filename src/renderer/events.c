/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-14 15:15:16 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-14 15:15:16 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Deletes the allocated data
*  and closes the screen.  */
void	close_window(void *param)
{
	t_cub3d	*info;

	info = (t_cub3d *)param;
	(void)info;
	/*clean_up_functions*/
	exit(0);
}

/* Handles key press events for movement and exit. */
void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_cub3d		*info;
	t_coords_d	new_p;

	info = (t_cub3d *)param;
	new_p = info->player.pixel;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		new_p.y = info->player.pixel.y - MOVE_SPEED;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		new_p.x = info->player.pixel.x - MOVE_SPEED;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		new_p.y = info->player.pixel.y + MOVE_SPEED;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		new_p.x = info->player.pixel.x + MOVE_SPEED;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		;
	else
		return ;
	if (new_p.x > 0 && new_p.y > 0
		&& new_p.x < info->plane.width && new_p.y < info->plane.height)
	{
		printf("old: player.x: %f, player.y: %f\n", info->player.pixel.x, info->player.pixel.y);
		info->player.pixel = new_p;
		printf("new: player.x: %f, player.y: %f\n\n", info->player.pixel.x, info->player.pixel.y);
		cast_rays(info);
		render_wall_slices(info);
		if (mlx_image_to_window(info->handle, info->img, 0, 0) < 0)
			exit(1);
	}
}
