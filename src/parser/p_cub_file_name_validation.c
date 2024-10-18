/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub_file_name_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:48 by tnakas            #+#    #+#             */
/*   Updated: 2024/10/19 00:09:40 by tnakas           ###   ########.fr       */
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

void	free_cub3d_input(t_cub3d *info)
{
	if (info->map.map)
		free_double_array(info->map.map);
	if (info->input.no.path)
		free(info->input.no.path);
	if (info->input.so.path)
		free(info->input.so.path);
	if (info->input.we.path)
		free(info->input.we.path);
	if (info->input.ea.path)
		free(info->input.ea.path);
}
