/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:44:01 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/03 13:34:10 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_double_str_array(char	**array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		printf("%s", array[i]);
}

// I will use the open and read with get_next_line
void	free_double_array(char **str)
{
	int	i;

	i = -1;
	if (!str || !(*str))
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	**arr_strdup(char **arr, int size)
{
	char	**res;
	int		i;

	i = 0;
	if (!arr || !(*arr))
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	while (i < size)
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
		{
			free_double_array(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}