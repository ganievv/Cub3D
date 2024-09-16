/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/12 17:47:21 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(void)
{
	char	**res;
	int		i;
	// t_input	in;

	i = 0;
	res = open_and_get_all_lines("./src/parser/input.cub");
	print_double_str_array(res);
	skip_spaces(res[5], &i);
	// define_input(&in, res[5] + i);
}

// void	define_input_per_line(t_input *in, char *str)
// {
// 	int				i;
// 	int				k;
// 	char			*path_or_color;
// 	t_texture		texture;

// 	k = 0;
// 	i = 0;
// 	if (str && (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "N ", 2)))
// 	{
// 		if (!ft_strncmp(str, "NO ", 3))
// 			i += 3;
// 		else
// 			i += 2;
// 		skip_spaces(str + i, &i);
// 		if (!str[i] || str[i] == '\n')
// 		{
// 			ft_putstr_fd("Error: Invalid Input", 2);
// 			return ;
// 		}
// 		texture.dir = NORTH;
// 	}
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
// 	if (texture.dir == NORTH)
// 		texture_node_update(&(in->no), path_or_color);
// 	else if (texture.dir == SOUTH)
// 		texture_node_update(&(in->so), path_or_color);
// 	else if (texture.dir == EAST)
// 		texture_node_update(&(in->ea), path_or_color);
// 	else if (texture.dir == WEST)
// 		texture_node_update(&(in->we), path_or_color);
// 	else if (texture.dir == FLOOR)
// 		texture_node_update(&(in->floor), path_or_color);
// 	else if (texture.dir == CIELLING)
// 		texture_node_update(&(in->ceilling), path_or_color);
// 	free(path_or_color);
// }
