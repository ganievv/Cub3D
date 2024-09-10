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

/* Checks if the ray is facing up */
bool	is_ray_facing_up(t_ray *ray)
{
	return (ray->angle > 0.0 && ray->angle < 180.0);
}

/* Checks if the ray is facing down */
bool	is_ray_facing_down(t_ray *ray)
{
	return (ray->angle > 180.0 && ray->angle < 360.0);
}

/* Checks if the ray is facing right */
bool	is_ray_facing_right(t_ray *ray)
{
	return ((ray->angle >= 0.0 && ray->angle < 90.0)
		|| ray->angle > 270.0 && ray->angle < 360.0);
}

/* Checks if the ray is facing left */
bool	is_ray_facing_left(t_ray *ray)
{
	return (ray->angle > 90.0 && ray->angle < 270.0);
}
