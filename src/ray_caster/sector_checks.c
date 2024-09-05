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

/* Checks if the ray is in the northeast sector */
bool	is_northeast_s(t_ray *ray)
{
	return (ray->angle > 0.0 && ray->angle < 90.0);
}

/* Checks if the ray is in the northwest sector */
bool	is_northwest_s(t_ray *ray)
{
	return (ray->angle > 90.0 && ray->angle < 180.0);
}

/* Checks if the ray is in the southwest sector */
bool	is_southwest_s(t_ray *ray)
{
	return (ray->angle > 180.0 && ray->angle < 270.0);
}

/* Checks if the ray is in the southeast sector */
bool	is_southeast_s(t_ray *ray)
{
	return (ray->angle > 270.0);
}
