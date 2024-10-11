/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:07:21 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/11 03:26:06 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_empty_line(char *str)
{
	int	is_empty;
	int	i;

	is_empty = 1;
	i = 0;
	while (str[i] && (str[i] != '\0' || str[i] != '\n'))
	{
		if (ft_isspace(str[i]) == 0)
			is_empty = 0;
		i++;
	}
	return (is_empty);
}

static void	arr_strcpy(char ***dest, char **src, int *i, char **next_line)
{
	int	j;

	j = -1;
	if (src)
	{
		j = -1;
		while (++j < *i)
			(*dest)[j] = ft_strdup(src[j]);
		free_double_array(src);
	}
	(*dest)[*i] = ft_strdup(*next_line);
	if (!(*dest)[*i])
	{
		free(*next_line);
		free_double_array((*dest));
		return ;
	}
	(*dest)[++(*i)] = NULL;
}

static void	unfiltered_lines_loop(char **next_line, char ***unf_input, int fd)
{
	char	**temp;
	int		i;

	temp = NULL;
	i = 0;
	while (*next_line)
	{
		temp = arr_strdup((*unf_input), i);
		free_double_array((*unf_input));
		(*unf_input) = (char **)malloc(sizeof(char *) * (i + 2));
		if (!(*unf_input))
		{
			free(*next_line);
			free_double_array(temp);
			return ;
		}
		arr_strcpy(unf_input, temp, &i, next_line);
		free(*next_line);
		*next_line = get_next_line(fd);
	}
}

char	**open_and_get_all_lines(char	*path_to_the_file)
{
	int		fd;
	char	*next_line;
	char	**unf_input;

	unf_input = NULL;
	fd = open(path_to_the_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);
	unfiltered_lines_loop(&next_line, &unf_input, fd);
	close(fd);
	return (unf_input);
}
