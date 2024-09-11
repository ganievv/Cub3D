/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:55 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/03 21:03:49 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
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
bool	is_valid_splited_color_arg( char **splited)
{
	bool	is_valid;
	int		i;

	is_valid = true;
	i = -1;
	while (splited[++i] && is_valid)
		is_valid = is_valid_color_arg(splited[i]);
	return (is_valid && (i == 3));
}

void	skip_spaces(char	*str, int *j)
{
	if (!str)
		return ;
	*j = *j - 1;
	while (str && ft_isspace(str[++(*j)]))
		;
}

void	skip_spaces_and_empty_lines(char	**arr, int *i, int *j)
{
	if (!arr || !(*arr))
		return ;
	*j = *j - 1;
	while (arr[*i] && ft_isspace(arr[*i][++(*j)]))
	{
		if (arr[*i] && (arr[*i][*j] == '\0' || arr[*i][*j] == '\n'))
		{
			(*i)++;
			(*j) = 0;
		}
	}
}
