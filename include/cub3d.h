/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:28:13 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/03 16:21:25 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define PLANE_WIDTH 320
# define PLANE_HEIGHT 200
# define FOV_ANGLE 60.0
# define CUBE_SIZE 64
# define ROTATION_SPEED 0.015
# define MOVE_SPEED 2
# define VIEW_PLANE 60

/* Compass directions */
typedef enum e_compass_dir
{
	SPACE,
	EAST,
	NORTH,
	WEST,
	SOUTH,
	FLOOR,
	CIELLING
}	t_compass_dir;

/* Represents a 2D point
*  with x and y coordinates. */
typedef struct s_coords
{
	int			x;
	int			y;
}	t_coords;

typedef struct s_color
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
}	t_color;

//====
//orientation and texture path if is existing or color if is existing
//or: NO or N, SO or S, WE or W, EA or E
//path: path for texture
typedef struct s_texture
{
	t_compass_dir			dir;
	bool					is_path;
	char					*path;
	bool					is_color;
	t_color					color;
	struct t_texture		*next;
}	t_texture;

// here is the struct for the map
// not necessayry to keep it as it is
typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	int				x_player;
	int				y_player;
	t_compass_dir	dir;
}	t_map;

typedef struct s_input
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;

	t_texture	floor;
	t_texture	ceilling;

	t_map		map;
}	t_input;

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
	t_coords	coords;
	double		fov_angle;
	double		viewing_angle;
	int			height;

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

/* projection plane */
typedef struct s_plane
{
	int			height;
	int			width;
	t_coords	center;
}	t_plane;

/* Required values for the ray_caster */
typedef struct s_dimensions
{
	int				cube_size;
	double			wall_floor_angle;
	double			len_to_plane_center;
	double			ray_angle_step;
}	t_dimensions;

// ahelping struct for the ray not necessayry to keep it until the end
// the angle is includes in the total range of the view plane (ex. -60 to 60)
// the dist  is the distance from the plane
//=========
// is_wall is a flag that is notifing us if it's a wall
// in the player to not move if the is in the wall
/* 'h_intersec' - horizontal intersection with a wall
*  'v_intersec' - vertical intersection with a wall */
typedef struct s_ray
{
	t_coords	h_intersec;
	t_coords	v_intersec;
	double		angle;
	double		dist;
	bool		is_wall;
}	t_ray;

//here is the struct that is including all the other structs
typedef struct s_cub3d
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_ray			ray[PLANE_WIDTH];
	t_map			map;
	t_player		player;
	t_plane			plane;
	t_dimensions	game_dims;
}	t_cub3d;

/*===========================RAY_CASTER===========================*/
void	cast_rays(t_cub3d *info);
void	set_ray_angle(int i, t_cub3d *info);
/*------------------------ray_caster_init-------------------------*/
void	ray_caster_init(t_cub3d *info);
double	calc_len_to_plane_center(t_cub3d *info);
double	calc_ray_angle_step(t_cub3d *info);
/*-----------------------player_orientation-----------------------*/
void	set_player_coordinates(t_cub3d *info);
void	set_player_viewing_angle(t_cub3d *info);
/*----------------------------convert-----------------------------*/
double	degrees_to_radians(double degrees);
int		grid_to_pixel(int grid, int cube_size);
int		pixel_to_grid(int pixel, int cube_size);
/*-------------------------sector_checks--------------------------*/
bool	is_ray_facing_up(t_ray *ray);
bool	is_ray_facing_down(t_ray *ray);
bool	is_ray_facing_right(t_ray *ray);
bool	is_ray_facing_left(t_ray *ray);
/*----------------------horizontal_intersec-----------------------*/
bool	is_wall(t_ray *ray, t_cub3d *info);
void	check_points_h(t_ray *ray, t_coords *p, t_cub3d *info);
void	check_first_point_h(t_ray *ray, t_coords *p, t_cub3d *info);
void	calc_up_intersec(t_ray *ray, t_coords *p, t_cub3d *info);
void	calc_down_intersec(t_ray *ray, t_coords *p, t_cub3d *info);
/*---------------------move_horizontal_point----------------------*/
void	set_movement_len_h(t_coords *move, t_ray *ray, t_cub3d *info);
void	move_to_new_point_h(t_coords *move, t_ray *ray);
/*-----------------------vertical_intersec------------------------*/
void	check_points_v(t_ray *ray, t_coords *p, t_cub3d *info);
void	check_first_point_v(t_ray *ray, t_coords *p, t_cub3d *info);
void	calc_right_intersec(t_ray *ray, t_coords *p, t_cub3d *info);
void	calc_left_intersec(t_ray *ray, t_coords *p, t_cub3d *info);
/*----------------------move_vertical_point-----------------------*/
void	set_movement_len_v(t_coords *move, t_ray *ray, t_cub3d *info);
void	move_to_new_point_v(t_coords *move, t_ray *ray);

//===============PARSING_CUBE3D_FILE=========================
void		print_double_str_array(char	**array);
void		free_double_array(char **str);
char		**arr_strdup(char **arr, int size);
char		**open_and_get_all_lines(char	*path_to_the_file);
//--------------Parsing_texture------------------------------
t_texture	*texture_node_create(t_compass_dir dir, char *str);
//--------------Parsing_texture_utils_one--------------------
bool		is_valid_path(char *str);
bool		is_color(char *str);
char		**splited_by_comma(char *str);
//--------------Parsing_texture_utils_two--------------------
long		ft_pos_atol(char *str);
bool		is_valid_color_arg(char	*str);
bool		is_valid_splited_color_arg( char **splited);

#endif