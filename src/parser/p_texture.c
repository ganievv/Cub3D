/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:55 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/18 13:41:05 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	order_is_valid(t_node *dir)
{
	while (dir && dir->next)
	{
		if (dir->next->type != dir->type + 1)
			return (0);
		dir = dir->next;
	}
	return (dir->type == 5);
}

int	paths_are_valid(t_node *compass_dir)
{
	while (compass_dir && compass_dir->type <= 3)
	{
		if (open(compass_dir->p_or_c, O_RDONLY) < 0)
			return (0);
		compass_dir = compass_dir->next;
	}
	return (1);
}

int	colors_are_valid(t_node *compass_dir)
{
	char	**splitted_colors;

	splitted_colors = NULL;
	while (compass_dir && compass_dir->type <= 3)
		compass_dir = compass_dir->next;
	while (compass_dir && compass_dir->type <= 5)
	{
		if (splitted_colors)
			free_double_array(splitted_colors);
		splitted_colors = ft_split(compass_dir->p_or_c, ',');
		if (!splitted_colors)
			return (0);
		if (!is_valid_splited_color_arg(splitted_colors))
			return (0);
		compass_dir = compass_dir->next;
	}
	return (1);
}

int	valid_textures(t_node *compass_dir)
{
	return (order_is_valid(compass_dir)
		&& paths_are_valid(compass_dir)
		&& colors_are_valid(compass_dir));
}
