/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:28:13 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 00:07:29 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct s_player
{
	int			x;
	int			y;
	bool		right;
	bool		left;
	bool		forward;
	bool		backward;
	double		angle;
	bool		rot_right;
	bool		rot_left;
	bool		rot_up;
	bool		rot_down;
	float		view_plane;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	dist;
	bool	is_wall;
}	t_ray;

typedef struct s_map
{
	char	**map_array_input;
	int		width;
	int		height;
	int		x_pos_player;
	int		y_pos_player;
}	t_map;

typedef struct s_cub3d
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_map		*map;
	t_player	*player;
}	t_cub3d;

#endif