/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-16 11:27:40 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-16 11:27:40 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Adjusts the player's viewing angle based on left or
*  right arrow key presses and normalizes the angle */
int	rotate_keys(t_cub3d *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->player.viewing_angle += ROTATION_SPEED;
	else if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->player.viewing_angle -= ROTATION_SPEED;
	else
		return (1);
	info->player.viewing_angle = normalize_angle(info->player.viewing_angle);
	return (1);
}

/* Calculates the movement vector */
void	calculate_move(t_coords_d *move, double rad,
	double angle_offset, int sign)
{
	move->x = cos(rad + angle_offset) * MOVE_SPEED * sign;
	move->y = sin(rad + angle_offset) * MOVE_SPEED * sign;
}

int	check_grid(double x, double y, t_cub3d *info)
{
	t_coords	grid;

	grid.x = pixel_to_grid(x, info->game_dims.cube_size);
	grid.y = pixel_to_grid(y, info->game_dims.cube_size);
	if (is_out_of_map(&grid, info) || is_wall(&grid, info)
		|| is_whitespace(&grid, info))
		return (0);
	return (1);
}

int	check_new_position(t_coords_d *new_p, t_cub3d *info)
{
	if (!check_grid(new_p->x, new_p->y, info))
		return (0);
	if (!check_grid(new_p->x - PIXEL_BUFFER, new_p->y, info))
		return (0);
	if (!check_grid(new_p->x + PIXEL_BUFFER, new_p->y, info))
		return (0);
	if (!check_grid(new_p->x, new_p->y - PIXEL_BUFFER, info))
		return (0);
	if (!check_grid(new_p->x, new_p->y + PIXEL_BUFFER, info))
		return (0);
	return (1);
}

/* Handles player movements */
int	move_keys(t_coords_d *new_p, t_cub3d *info)
{
	t_coords_d	move;
	double		rad;

	rad = degrees_to_radians(info->player.viewing_angle);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		calculate_move(&move, rad, 0, 1);
	else if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		calculate_move(&move, rad, 0, -1);
	else if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		calculate_move(&move, rad, M_PI_2, 1);
	else if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		calculate_move(&move, rad, -M_PI_2, 1);
	else
		return (1);
	new_p->x += move.x;
	new_p->y -= move.y;
	if (!check_new_position(new_p, info))
		return (0);
	info->player.pixel = *new_p;
	return (1);
}
