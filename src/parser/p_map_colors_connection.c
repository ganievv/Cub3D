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

int	find_line_len(char *line)
{
	int	i;

	i = (int)ft_strlen(line);
	while (i)
	{
		if (line[i - 1] == '1')
			return (i);
		i--;
	}
	return (0);
}

int	find_map_width(char **map)
{
	int	length;
	int	tmp;
	int	i;

	i = -1;
	length = 0;
	while (map[++i])
	{
		tmp = find_line_len(map[i]);
		if (length < tmp)
			length = tmp;
	}
	return (length);
}
