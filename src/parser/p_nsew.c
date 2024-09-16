/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nsew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:40:40 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/12 17:48:05 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// the thought is that I will take the input from the get_next_line
//trying to find the dirretions one by one
// their relative path files
// void	define_input_per_line(t_input *in, char *str)
// {
// 	int				i;
// 	int				k;
// 	char			*path_or_color;
// 	t_texture		texture;

// 	k = 0;
// 	i = 0;
// 	if (str && (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "N ", 2)))
// 		set_type(&texture, str, &i, NORTH, "NO ");
// 	else if (str && (!ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "S ", 2)))
// 		set_type(&texture, str, &i, SOUTH, "SO ");
// 	else if (str && (!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "W ", 2)))
// 		set_type(&texture, str, &i, WEST, "WE ");
// 	else if (str && (!ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "E ", 2)))
// 		set_type(&texture, str, &i, EAST, "EA ");
// 	else if (str && (!ft_strncmp(str, "F ", 2)))
// 		set_type(&texture, str, &i, FLOOR, "F ");
// 	else if (str && (!ft_strncmp(str, "C ", 2)))
// 		set_type(&texture, str, &i, CIELLING, "C ");
// 	k = i;
// 	while (str[i] && !ft_isspace(str[i])
// 		&& (str[i] != '\n' || str[i] != '\0'))
// 		i++;
// 	path_or_color = ft_strndup(str + k, i - k);
// 	if (!path_or_color)
// 	{
// 		ft_putstr_fd("Error: memory allocation failure", 2);
// 		return ;
// 	}
// 	skip_spaces(str + i, &i);
// 	if (str[i] != '\n' || str[i] != '\0')
// 	{
// 		free(path_or_color);
// 		ft_putstr_fd("Error: Invalid Input", 2);
// 		return ;
// 	}
// 	texture_update_per_direction(in, &texture, path_or_color);
// 	free(path_or_color);
// }

// void	texture_update_per_direction(t_input *in,
// 	t_texture *texture, char *path_or_color)
// {
// 	if (texture->dir == NORTH)
// 		texture_node_update(&(in->no), path_or_color);
// 	else if (texture->dir == SOUTH)
// 		texture_node_update(&(in->so), path_or_color);
// 	else if (texture->dir == EAST)
// 		texture_node_update(&(in->ea), path_or_color);
// 	else if (texture->dir == WEST)
// 		texture_node_update(&(in->we), path_or_color);
// 	else if (texture->dir == FLOOR)
// 		texture_node_update(&(in->floor), path_or_color);
// 	else if (texture->dir == CIELLING)
// 		texture_node_update(&(in->ceilling), path_or_color);
// }

// void	set_type(t_texture *texture, char *str, int *i,
// 	t_compass_dir dir, char *check_str)
// {
// 	if (!check_str)
// 	{
// 		ft_putstr_fd("Error: memory allocation failure", 2);
// 		return ;
// 	}
// 	if (dir >= 0 && dir <= 3 && !ft_strncmp(str, check_str, 3))
// 		*i += 3;
// 	if (!ft_strncmp(str, check_str, 2))
// 		*i += 2;
// 	skip_spaces(str + (*i), i);
// 	if (!str[*i] || str[*i] == '\n')
// 	{
// 		ft_putstr_fd("Error: Invalid Input", 2);
// 		return ;
// 	}
// 	texture->dir = dir;
// }
