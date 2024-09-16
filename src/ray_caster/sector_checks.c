/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 14:52:27 by sganiev           #+#    #+#             */
/*   Updated: 2024-09-05 14:52:27 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_ray_northeast(double angle)
{
	return (angle > 0.0 && angle < 90.0);
}

bool	is_ray_northwest(double angle)
{
	return (angle > 90.0 && angle < 180.0);
}

bool	is_ray_southwest(double angle)
{
	return (angle > 180.0 && angle < 270.0);
}

bool	is_ray_southeast(double angle)
{
	return (angle > 270.0 && angle < 360.0);
}
