/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/17 17:17:17 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* maps to check:
*  ./cub3D maps/bad/map_missing.cub
*  ./cub3D maps/bad/file_letter_end.cub
*  ./cub3D maps/bad/player_on_edge.cub
*  ./cub3D maps/bad/textures_dir.cub
*  ./cub3D maps/bad/textures_none.cub
*  ./cub3D maps/bad/wall_hole_east.cub
*  ./cub3D maps/bad/wall_hole_north.cub
*  ./cub3D maps/bad/wall_hole_south.cub
*  ./cub3D maps/bad/wall_hole_west.cub
*  ./cub3D maps/bad/wall_none.cub */

//finding the height
static uint32_t	char_to_hex(char *c)
{
	int		int_colors[3];
	char	**char_colors;

	char_colors = ft_split(c, ',');
	int_colors[0] = ft_pos_atol(char_colors[0]) % 256;
	int_colors[1] = ft_pos_atol(char_colors[1]) % 256;
	int_colors[2] = ft_pos_atol(char_colors[2]) % 256;
	free_double_array(char_colors);
	return ((int_colors[0] << 24) | (int_colors[1] << 16)
		| (int_colors[2] << 8) | 0xFF);
}

static void	pass_cub_file(t_cub3d *info,
		t_node *map, t_node *compass_dir)
{
	info->map.map = node_to_array(map, node_len(map));
	node_clear(map);
	info->map.height = find_map_height(info->map.map);
	info->map.width = find_map_width(info->map.map);
	info->input.no.path = ft_strdup(compass_dir->p_or_c);
	info->input.so.path = ft_strdup(compass_dir->next->p_or_c);
	info->input.we.path = ft_strdup(compass_dir->next->next->p_or_c);
	info->input.ea.path = ft_strdup(compass_dir->next->next->next->p_or_c);
	info->input.ceilling.color
		= char_to_hex(compass_dir->next->next->next->next->p_or_c);
	info->input.floor.color
		= char_to_hex(compass_dir->next->next->next->next->next->p_or_c);
	node_clear(compass_dir);
}

void	free_cub3d_input(t_cub3d *info)
{
	free_double_array(info->map.map);
	free(info->input.no.path);
	free(info->input.so.path);
	free(info->input.we.path);
	free(info->input.ea.path);
}

static void	raycast_render_free(t_cub3d *info)
{
	ray_caster_init(info);
	cast_rays(info);
	rendering(info);
	free_cub3d_input(info);
}

//./src/parser/input.cub
//res = open_and_get_all_lines("./src/parser/input.cub");
int	main(int argc, char **argv)
{
	t_cub3d	info;
	char	**res;
	t_node	*map;
	t_node	*compass_dir;

	if (!cub_name_is_valid(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	res = open_and_get_all_lines(argv[1]);
	if (!res)
		return (ft_putstr_fd("Error\n", 2), 1);
	array_to_list(res, &compass_dir, &map);
	if (!compass_dir || !map)
		return (ft_putstr_fd("Error\n", 2), 1);
	free(res);
	if (valid_map(map) && valid_textures(compass_dir))
		pass_cub_file(&info, map, compass_dir);
	else
		return (ft_putstr_fd("Error\n", 2),
			node_clear(map), node_clear(compass_dir), 1);
	raycast_render_free(&info);
	return (0);
}

/* apt-get update -y
*  apt-get install cmake -y
*  apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev -y */
