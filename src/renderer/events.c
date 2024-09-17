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
	mlx_delete_image(info->mlx, info->img);
	delete_textures_and_imgs(info);
	mlx_terminate(info->mlx);
	//free_map();
	exit(0);
}

/* Clears the entire image by setting every pixel to black*/
void	clear_image(t_cub3d *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->plane.height)
	{
		x = -1;
		while (++x < info->plane.width)
			mlx_put_pixel(info->img, x, y, 0x00000000);
	}
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
	{
		mlx_delete_image(info->mlx, info->img);
		delete_textures_and_imgs(info);
		mlx_terminate(info->mlx);
		exit(0);
	}
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
	clear_image(info);
	render_wall_slices(info);
}
