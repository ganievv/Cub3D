/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:55 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/16 21:23:22 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	array_to_list(char **res, t_node **parse_node, char ***map)
{
	int		i;
	int		j;
	t_node	*temp;
	int		not_a_dir;

	i = -1;
	not_a_dir = 0;
	while (res[++i])
	{
		temp = *parse_node;
		while (is_empty_line(res[i]))
			i++;
		j = -1;
		while (ft_isspace(res[i][++j]))
			;
		define_the_type(res[i] + j, parse_node, &not_a_dir);
		if (not_a_dir)
			break ;
	}
	if (res[i] != NULL)
		*map = res + i;
}

void	define_the_type(char *str, t_node **parse_node, int *f)
{
	if (!ft_strncmp("N ", str, 2))
			node_add_back(parse_node, node_new(NORTH, str + 2));
		else if (!ft_strncmp("NO ", str, 3))
			node_add_back(parse_node, node_new(NORTH, str + 3));
		else if (!ft_strncmp("S ", str, 2))
			node_add_back(parse_node, node_new(SOUTH, str + 2));
		else if (!ft_strncmp("SO ", str, 3))
			node_add_back(parse_node, node_new(SOUTH, str + 3));
		else if (!ft_strncmp("W ", str, 2))
			node_add_back(parse_node, node_new(WEST, str + 2));
		else if (!ft_strncmp("WE ", str, 3))
			node_add_back(parse_node, node_new(WEST, str + 3));
		else if (!ft_strncmp("E ", str, 2))
			node_add_back(parse_node, node_new(EAST, str + 2));
		else if (!ft_strncmp("EA ", str, 3))
			node_add_back(parse_node, node_new(EAST, str + 3));
		else if (!ft_strncmp("F ", str, 2))
			node_add_back(parse_node, node_new(FLOOR, str + 2));
		else if (!ft_strncmp("C ", str, 2))
			node_add_back(parse_node, node_new(CIELLING, str + 2));
		else
			*f = 1;
}
//positive
//numeric
//integers
//mod 256
long	ft_pos_atol(char *str)
{
	long	l;
	int		i;

	i = 0;
	l = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] && ft_isdigit(str[i]))
	{
		l = l * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	if (l > INT_MAX)
		return (-1);
	return (l % (256));
}

bool	is_valid_color_arg(char	*str)
{
	return (ft_pos_atol(str) != -1);
}

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
