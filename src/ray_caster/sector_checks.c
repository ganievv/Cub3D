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

bool	is_ray_northeast(t_ray *ray)
{
	return (ray->angle > 0.0 && ray->angle < 90.0);
}

bool	is_ray_northwest(t_ray *ray)
{
	return (ray->angle > 90.0 && ray->angle < 180.0);
}

bool	is_ray_southwest(t_ray *ray)
{
	return (ray->angle > 180.0 && ray->angle < 270.0);
}

bool	is_ray_southeast(t_ray *ray)
{
	return (ray->angle > 270.0 && ray->angle < 360.0);
}
