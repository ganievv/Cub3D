/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:33:24 by tnakas            #+#    #+#             */
/*   Updated: 2024/09/17 06:55:11 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_node_list(t_node *parse_node)
{
	printf("Prasing Node List:\n");
	while (parse_node)
	{
		printf("{[%d], [%s]}-->", parse_node->type, parse_node->p_or_c);
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

t_node	*node_new(t_compass_dir type, char *p_or_c)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->type = type;
	new->p_or_c = take_out_all_spaces(type, p_or_c);
	if (!new->p_or_c)
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
