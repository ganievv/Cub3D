/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_colors_connection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:56:58 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/11 03:10:04 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_map_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		;
	return (i);
}

int	find_map_width(char **map)
{
	int	length;
	int	i;

	i = -1;
	length = 0;
	while (map[++i])
	{
		if (length < (int)ft_strlen(map[i]))
			length = (int)ft_strlen(map[i]);
	}
	return (length);
}
