/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 13:23:14 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 13:23:14 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Converts degrees to radians
*  Formula: radians = degrees * (π / 180) */
double	degrees_to_radians(double degrees)
{
	double	rad;

	rad = degrees * (M_PI / 180.0);
	return (rad);
}

/* Converts grid coordinates to pixel coordinates
*  based on the cube size. */
int	grid_to_pixel(int grid, int cube_size)
{
	return (grid * cube_size + (cube_size / 2));
}

/* Converts pixel coordinates to grid coordinates
*  based on the cube size. */
int	pixel_to_grid(int pixel, int cube_size)
{
	return (pixel / cube_size);
}
