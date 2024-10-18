/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file_name_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:48 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/18 19:46:16 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_name_is_valid(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!is_x_filetype(argv[1], ".cub")
		|| open(argv[1], O_RDONLY) < 0)
		return (0);
	return (1);
}
