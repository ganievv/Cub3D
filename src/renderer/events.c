/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:15:16 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/11 04:09:17 by tnakas           ###   ########.fr       */
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
	free_cub3d(info, 0, true);
}

/* Checks if any movement or rotation keys are pressed */
int	check_keys(t_cub3d *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_W)
		|| mlx_is_key_down(info->mlx, MLX_KEY_A)
		|| mlx_is_key_down(info->mlx, MLX_KEY_S)
		|| mlx_is_key_down(info->mlx, MLX_KEY_D)
		|| mlx_is_key_down(info->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		return (1);
	else
		return (0);
}

/* Handles the ESC key press event to terminate
*  the program and clean up resources */
void	handle_esc_key(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*info;

	info = (t_cub3d *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_cub3d(info, 0, true);
}

/* Handles key press events for movements and rotations*/
void	handle_keys(void *param)
{
	t_cub3d		*info;
	t_coords_d	new_p;

	info = (t_cub3d *)param;
	new_p = info->player.pixel;
	if (!check_keys(info))
		return ;
	if (move_keys(&new_p, info) == 0)
		return ;
	rotate_keys(info);
	cast_rays(info);
	info->img->enabled = false;
	draw_frame(info);
	info->img->enabled = true;
}
