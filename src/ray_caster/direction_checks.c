/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-18 14:03:34 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-18 14:03:34 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_ray_up(double angle)
{
	return (angle >= 0.0 && angle < 180.0);
}

bool	is_ray_down(double angle)
{
	return (angle >= 180.0 && angle < 360.0);
}

bool	is_ray_left(double angle)
{
	return (angle >= 90.0 && angle < 270.0);
}

bool	is_ray_right(double angle)
{
	return ((angle >= 270.0 && angle < 360.0)
		|| (angle >= 0.0 && angle < 90.0));
}
