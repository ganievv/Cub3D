/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:44:01 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/02 21:44:05 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	print_double_str_array(char	**array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		printf("%s", array[i]);
}

char	**open_and_get_all_lines(char	*path_to_the_file)
{
	int		fd;
	int		i;
	int		j;
	char	*next_line;
	char	**unfiltered_array_of_lines;
	char	**temp;

	unfiltered_array_of_lines = NULL;
	temp = NULL;
	fd = open(path_to_the_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	next_line = get_next_line(fd);
	i = 0;
	j = 0;
	while (next_line)
	{
		temp = arr_strdup(unfiltered_array_of_lines, i);
		free_double_array(unfiltered_array_of_lines);
		unfiltered_array_of_lines = (char **)malloc(sizeof(char *) * (i + 2));
		if (!unfiltered_array_of_lines)
		{
			free(next_line);
			free_double_array(temp);
			return (NULL);
		}
		if (temp)
		{
			j = -1;
			while (++j < i)
				unfiltered_array_of_lines[j] = ft_strdup(temp[j]);
		}
		free_double_array(temp);
		unfiltered_array_of_lines[i] = ft_strdup(next_line);
		free(next_line);
		unfiltered_array_of_lines[++i] = NULL;
		next_line = get_next_line(fd);
	}
	close(fd);
	print_double_str_array(unfiltered_array_of_lines);
	return (unfiltered_array_of_lines);
}

int	main(void)
{
	char	**res;
	int		i;

	i = 0;
	res = open_and_get_all_lines("./src/parser/input.cub");
}
// and save in a two dimentional array the whole input
// the method that I ll use:
// char **unfiltered_str