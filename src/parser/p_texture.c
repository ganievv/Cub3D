/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:32 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 00:56:58 by tnakas           ###   ########.fr       */
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

void	set_color(t_color *c, char	**splited)
{
	if (!splited || *splited)
		return ;
	if (is_valid_splited_color_arg(splited))
	{
		c->red = (uint8_t)ft_pos_atol(splited[0]);
		c->green = (uint8_t)ft_pos_atol(splited[1]);
		c->blue = (uint8_t)ft_pos_atol(splited[2]);
	}
	else
		ft_putstr_fd("Error: invalid color fields", 2);
}

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

// void	set_path(char **path, char *str)
// {
// 	if (!str[0] || str[0] == '\0')
// 		return ;
// 	if (is_valid_path(str))
// 	{
// 		*(path) = ft_strdup(str);
// 		if (!(*(path)))
// 			ft_putstr_fd("Error: failed memory allocation", 2);
// 		return ;
// 	}
// 	else
// 		ft_putstr_fd("Error: invalid path", 2);
// 	*path = NULL;
// }

// void	texture_node_update(t_texture *t, char *str)
// {
// 	char		**splited;

// 	t->defined = true;
// 	splited = NULL;
// 	if (is_path(str))
// 	{
// 		t->is_path = 1;
// 		set_path(&(t->path), str);
// 		if (str && t->path == NULL)
// 			return ;
// 	}
// 	else if (is_color(str))
// 	{
// 		t->is_color = 1;
// 		splited = splited_by_comma(str);
// 		if (!splited)
// 			return ;
// 		set_color(&(t->color), splited);
// 	}
// 	free_double_array(splited);
// }
