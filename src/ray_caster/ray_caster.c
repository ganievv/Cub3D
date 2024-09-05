/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:05 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 21:43:03 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//if (ray->angle == 0.0)
//{
//	intersec->y = p->y;
//	intersec->x = p->x + (info->game_dims.cube_size / 2);
//}

void	cast_rays_preparation(t_cub3d *info)
{
	ray_caster_init(info);
	check_horizontal_intersect(info);
}
