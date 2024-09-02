/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:28:13 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/02 18:47:42 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define WIDTH 900
# define HEIGHT 450
# define ROTATION_SPEED 0.015
# define MOVE_SPEED 2
# define VIEW_PLANE 60
// here is a struct for the player
// x, y are the coordinates
// right left forword right are the flags that they will 
// help us in the keyhooks to move the player
//====
// the current angle that the view of our player it is
// rot_right rot_left rot_up rot_down are flags for 
// the rotation of the plane_view
//====
//view_plane is the total range of the view in grades
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
// ahelping struct for the ray not necessayry to keep it until the end
// the angle is includes in the total range of the view plane (ex. -60 to 60)
// the dist  is the distance from the plane
//=========
// is_wall is a flag that is notifing us if it's a wall
// in the player to not move if the is in the wall
typedef struct s_ray
{
	double	angle;
	double	dist;
	bool	is_wall;
}	t_ray;
// here is the struct for the map
// not necessayry to keep it as it is
typedef struct s_map
{
	char	**map_array_input;
	int		width;
	int		height;
	int		x_pos_player;
	int		y_pos_player;
}	t_map;
//here is the struct that is including all the other structs
typedef struct s_cub3d
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_map		*map;
	t_player	*player;
}	t_cub3d;

//===============PARSING_CUBE3D_FILE=========================
void	free_double_array(char **str);
char	**arr_strdup(char **arr, int size);
char	**open_and_get_all_lines(char	*path_to_the_file);
#endif