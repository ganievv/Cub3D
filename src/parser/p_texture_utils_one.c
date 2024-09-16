/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:33:24 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/12 19:36:09 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// bool	is_path(char *str)
// {
// 	return (!ft_strncmp(str, "./", 2) || !ft_strncmp(str, "/", 1)
// 		|| (!ft_strchr(str, ',') && ft_strchr(str, '.')));
// }

// bool	is_valid_path(char *str)
// {
// 	int	fd;

// 	fd = open(str, O_RDONLY);
// 	if (fd >= 0)
// 		close(fd);
// 	return (fd >= 0);
// }

// bool	is_color(char *str)
// {
// 	return (ft_strchr(str, ',') != NULL);
// }
// and save in a two dimentional array the whole input
// making a link list that is creating nodes by \n or \0

//if it's a color
//from str to double dimentional array
// char	**splited_by_comma(char *str)
// {
// 	char	**res;

// 	res = ft_split(str, ',');
// 	if (!res)
// 		return (NULL);
// 	return (res);
// }

// I need a criteria to define it
// the method that I ll use:
//color_variable must be number from 0, 255
// possitive
// integer
// char **unfiltered_str