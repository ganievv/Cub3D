/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:32 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/03 16:17:18 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_texture	*texture_node_create(t_compass_dir dir, char *str)
{
	t_texture	*t;

	t = (t_texture *)malloc(sizeof(t_texture));
	if (!t)
		return (NULL);
	t->dir = dir;
	if (is_valid_path(str))
	{
		t->is_path = 1;
		t->path = str;
	}
}
