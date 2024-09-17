/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:55 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 02:12:12 by tnakas           ###   ########.fr       */
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
// int	compass_dir_p_or_c_are_valid(t_node	*dir)
// {
// 	while (dir)
// 	{
// 		if (dir->type <= 3
// 			&& open(dir->p_or_c, O_RDONLY) == -1)
// 			return (0);
// 		if (dir->type > 3 && non_valid_color_input(dir->p_or_c))
// 			return (0);
// 	}
// 	return (1);
// }

//positive
//numeric
//integers
//mod 256

// the arguments for colors must be:
//tree
//numeric
//possitive
//integers
// bool	is_valid_splited_color_arg( char **splited)
// {
// 	bool	is_valid;
// 	int		i;

// 	is_valid = true;
// 	i = -1;
// 	while (splited[++i] && is_valid)
// 		is_valid = is_valid_color_arg(splited[i]);
// 	return (is_valid && (i == 3));
// }

// void	skip_spaces(char	*str, int *j)
// {
// 	if (!str)
// 		return ;
// 	*j = *j - 1;
// 	while (str && ft_isspace(str[++(*j)]))
// 		;
// }

// void	skip_spaces_and_empty_lines(char	**arr, int *i, int *j)
// {
// 	if (!arr || !(*arr))
// 		return ;
// 	*j = *j - 1;
// 	while (arr[*i] && ft_isspace(arr[*i][++(*j)]))
// 	{
// 		if (arr[*i] && (arr[*i][*j] == '\0' || arr[*i][*j] == '\n'))
// 		{
// 			(*i)++;
// 			(*j) = 0;
// 		}
// 	}
// }
