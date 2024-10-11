/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:32 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/11 00:20:46 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

// void	set_color(t_color *c, char	**splited)
// {
// 	if (!splited || *splited)
// 		return ;
// 	if (is_valid_splited_color_arg(splited))
// 	{
// 		c->red = (uint8_t)ft_pos_atol(splited[0]);
// 		c->green = (uint8_t)ft_pos_atol(splited[1]);
// 		c->blue = (uint8_t)ft_pos_atol(splited[2]);
// 	}
// }

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
