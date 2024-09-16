/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:33:24 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/16 23:58:29 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// bool	is_path(char *str)
// {
// 	return (!ft_strncmp(str, "./", 2) || !ft_strncmp(str, "/", 1)
// 		|| (!ft_strchr(str, ',') && ft_strchr(str, '.')));
// }

// bool	is_valid_path(char *str)
// {
// 	int	fd;

// 	fd = open(str, O_RDONLY);
// 	if (fd >= 0)
// 		close(fd);
// 	return (fd >= 0);
// }

// bool	is_color(char *str)
// {
// 	return (ft_strchr(str, ',') != NULL);
// }
// and save in a two dimentional array the whole input
// making a link list that is creating nodes by \n or \0

//if it's a color
//from str to double dimentional array
// char	**splited_by_comma(char *str)
// {
// 	char	**res;

// 	res = ft_split(str, ',');
// 	if (!res)
// 		return (NULL);
// 	return (res);
// }

// I need a criteria to define it
// the method that I ll use:
//color_variable must be number from 0, 255
// possitive
// integer
// char **unfiltered_str
void	print_node_list(t_node *parse_node)
{
	printf("Prasing Node List:\n");
	while (parse_node)
	{
		printf("{[%d], [%s]}-->", parse_node->type, parse_node->path_or_color);
		parse_node = parse_node->next;
	}
	printf("{[NULL], [NULL]}\n");
}

static void	skip_by_type(t_compass_dir type, char *str, int *i)
{
	if (type != NON)
		while (ft_isspace(str[*i]))
			(*i)++;
}

char	*take_out_all_spaces(t_compass_dir type, char *str)
{
	int	start;
	int	end;
	int	i;

	if (!str)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	skip_by_type(type, str, &i);
	start = i;
	if (type == NON)
		while (str[i] && str[i] != '\n')
			i++;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '\n')
		i++;
	end = i;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] != '\n' && str[i] != '\0')
		return (NULL);
	if (end - start > 0)
		return (ft_strndup(str + start, end - start));
	else
		return (NULL);
}

t_node	*node_new(t_compass_dir type, char *path_or_color)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->type = type;
	new->path_or_color = take_out_all_spaces(type, path_or_color);
	if (!new->path_or_color)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
