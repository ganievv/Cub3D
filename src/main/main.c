/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/03 12:31:40 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(void)
{
	char	**res;
	int		i;

	i = 0;
	res = open_and_get_all_lines("./src/parser/input.cub");
	print_double_str_array(res);
}
