/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:25:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/10/18 23:13:36 by tnakas           ###   ########.fr       */
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
		t_node *map, t_node *c_dir)
{
	info->map.map = node_to_array(map, node_len(map));
	info->map.height = find_map_height(info->map.map);
	info->input.no.path = ft_strdup(c_dir->p_or_c);
	info->input.so.path = ft_strdup(c_dir->next->p_or_c);
	info->input.we.path = ft_strdup(c_dir->next->next->p_or_c);
	info->input.ea.path = ft_strdup(c_dir->next->next->next->p_or_c);
	info->input.ceilling.color
		= char_to_hex(c_dir->next->next->next->next->p_or_c);
	info->input.floor.color
		= char_to_hex(c_dir->next->next->next->next->next->p_or_c);
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

static void	r_rc_free(t_cub3d *info)
{
	ray_caster_init(info);
	cast_rays(info);
	rendering(info);
}

void	n_scs_inf(t_cub3d *info, t_node *map, t_node *c_dir)
{
	n_clear(map);
	n_clear(c_dir);
	if (info->map.map == NULL || info->input.no.path == NULL
		|| info->input.so.path == NULL || info->input.we.path == NULL
		|| info->input.ea.path == NULL)
	{
		free_cub3d_input(info);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

//./src/parser/input.cub
//res = open_and_get_all_lines("./src/parser/input.cub");
int	main(int argc, char **argv)
{
	t_cub3d	info;
	char	**res;
	t_node	*map;
	t_node	*c_dir;

	init_render_data(&info);
	if (!cub_name_is_valid(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	res = open_and_get_all_lines(argv[1]);
	if (!res)
		return (ft_putstr_fd("Error\n", 2), res = NULL, 1);
	map = NULL;
	c_dir = NULL;
	array_to_list(res, &c_dir, &map);
	free_double_array(res);
	if (!c_dir || !map)
		return (ft_putstr_fd("Error\n", 2), n_clear(map), n_clear(c_dir), 1);
	if (valid_map(map) && valid_textures(c_dir))
		pass_cub_file(&info, map, c_dir);
	else
		return (ft_putstr_fd("Error\n", 2),
			n_clear(map), n_clear(c_dir), 1);
	return (n_scs_inf(&info, map, c_dir), r_rc_free(&info), 0);
}

/* apt-get update -y
*  apt-get install cmake -y
*  apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev -y */
