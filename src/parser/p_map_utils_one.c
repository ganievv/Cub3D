/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:22 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/18 23:27:30 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	node_len(t_node	*map)
{
	int	i;

	i = 0;
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

char	**node_to_array(t_node *map, int len)
{
	char	**tested_map;

	tested_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tested_map)
		return (NULL);
	len = 0;
	while (map && map->p_or_c)
	{
		tested_map[len] = ft_strdup(map->p_or_c);
		if (!tested_map[len])
		{
			free_double_array(tested_map);
			return (NULL);
		}
		len++;
		map = map->next;
	}
	tested_map[len] = NULL;
	return (tested_map);
}

void	n_clear(t_node *lst)
{
	t_node	*temp;

	temp = NULL;
	while (lst)
	{
		temp = lst->next;
		free(lst->p_or_c);
		free(lst);
		lst = temp;
	}
}
