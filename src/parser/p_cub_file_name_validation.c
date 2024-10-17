/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file_name_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:48 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/17 16:09:06 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_name_is_valid(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (perror("Error\n"), 1);
	i = ft_strlen(argv[1]);
	while (--i > 0 && ft_isspace(argv[1][i]))
		;
	if (i > 4)
		i -= 4;
	ft_strfltr(&argv[1], "\t\n\v\f\r");
	return (1);
	if (!ft_strncmp(argv[1] + i, ".cub", 4)
		|| open(argv[i], O_RDONLY) < 0)
		return (perror("Error\n"), 1);
	return (1);
}
