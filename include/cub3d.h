/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:28:13 by sganiev           #+#    #+#             */
/*   Updated: 2024/09/17 09:09:04 by tnakas           ###   ########.fr       */
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

# define PLANE_WIDTH 1920
# define PLANE_HEIGHT 1080
# define FOV_ANGLE 60.0
# define CUBE_SIZE 1080
# define MOVE_SPEED CUBE_SIZE / 16
//# define MOVE_SPEED 15
# define ROTATION_SPEED 2.0
# define PIXEL_BUFFER 220

/* Compass directions */
typedef enum e_compass_dir
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CIELLING,
	NON,
}	t_compass_dir;

/*
	my though is to create a link list with the type and the path or color
	-type according to the enum
	-path or color
	-connection with the next
*/
typedef struct s_node
{
	t_compass_dir	type;
	char			*p_or_c;
	struct s_node	*next;
}	t_node;

/* Represents a 2D point
*  with x and y coordinates. */
typedef struct s_coords
{
	int			x;
	int			y;
}	t_coords;

/* Represents a 2D point (double type)
*  with x and y coordinates. (for intersec calc) */
typedef struct s_coords_d
{
	double		x;
	double		y;
}	t_coords_d;

typedef struct s_color
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
}	t_color;

/* ====
*  orientation and texture path if is existing or color if is existing
*  or: NO or N, SO or S, WE or W, EA or E
*  path: path for texture */
typedef struct s_texture
{
	mlx_texture_t			*texture;
	mlx_image_t				*img;
	bool					defined;
	t_compass_dir			dir;
	bool					is_path;
	char					*path;
	bool					is_color;
	t_color					color;
}	t_texture;

/* here is the struct for the map
*  not necessayry to keep it as it is */
typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	int				i_player;
	int				j_player;
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

/* here is a struct for the player
*  x, y are the coordinates
*  right left forword right are the flags that they will 
*  help us in the keyhooks to move the player
*  ====
*  the current angle that the view of our player it is
*  rot_right rot_left rot_up rot_down are flags for 
*  the rotation of the plane_view
*  ====
*  view_plane is the total range of the view in grades
*  ====
*  'coords' represents the player's coordinates in the grid system
*  'pixel' represents the player's coordinates in the pixel system */
typedef struct s_player
{
	t_coords	coords;
	t_coords_d	pixel;
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
	double			min_dist_x;
	double			min_dist_y;
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
	t_coords_d	h_intersec;
	t_coords_d	v_intersec;
	double		angle;
	double		dist;
	int			proj_slice_len;
	int			top_wall_y;
	bool		is_wall;
	bool		is_v_intersec;
}	t_ray;

//here is the struct that is including all the other structs
typedef struct s_cub3d
{
	t_input			input;
	t_ray			ray[PLANE_WIDTH];
	t_map			map;
	t_player		player;
	t_plane			plane;
	t_dimensions	game_dims;
	mlx_t			*mlx;
	mlx_image_t		*img;
}	t_cub3d;

/*==============================RAY_CASTER===============================*/
void		cast_rays(t_cub3d *info);
void		set_ray_angle(int i, t_cub3d *info);
double		normalize_angle(double angle);
/*----------------------------ray_caster_init----------------------------*/
void		ray_caster_init(t_cub3d *info);
double		calc_len_to_plane_center(t_cub3d *info);
double		calc_ray_angle_step(t_cub3d *info);
/*--------------------------player_orientation---------------------------*/
void		set_player_coordinates(t_cub3d *info);
void		set_player_viewing_angle(t_cub3d *info);
/*--------------------------------convert--------------------------------*/
double		degrees_to_radians(double degrees);
double		grid_to_pixel(int grid, int cube_size);
int			pixel_to_grid(double pixel, int cube_size);
/*-----------------------------sector_checks-----------------------------*/
bool		is_ray_northeast(double angle);
bool		is_ray_northwest(double angle);
bool		is_ray_southwest(double angle);
bool		is_ray_southeast(double angle);
/*-----	---------------------horizontal_intersec--------------------------*/
void		check_points_h(t_ray *ray, t_coords_d *p,
				t_coords_d *step, t_cub3d *info);
void		check_first_point_h(t_ray *ray, t_coords_d *p, t_cub3d *info);
void		calc_up_intersec(t_ray *ray, t_coords_d *p, t_cub3d *info);
void		calc_down_intersec(t_ray *ray, t_coords_d *p, t_cub3d *info);
/*---------------------------vertical_intersec---------------------------*/
void		check_points_v(t_ray *ray, t_coords_d *p,
				t_coords_d *step, t_cub3d *info);
void		check_first_point_v(t_ray *ray, t_coords_d *p, t_cub3d *info);
void		calc_right_intersec(t_ray *ray, t_coords_d *p, t_cub3d *info);
void		calc_left_intersec(t_ray *ray, t_coords_d *p, t_cub3d *info);
/*--------------------------move_intersec_point--------------------------*/
void		set_movement_len_h(t_coords_d *move, t_ray *ray, t_cub3d *info);
void		set_movement_len_v(t_coords_d *move, t_ray *ray, t_cub3d *info);
void		move_to_new_point(t_coords_d *move, t_coords_d *intersec);
/*----------------------------step_inside_grid---------------------------*/
void		step_inside_grid(t_coords_d *coords,
				double angle, t_coords_d *step);
/*----------------------------boundary_checks----------------------------*/
bool		is_wall(t_coords *i, t_cub3d *info);
bool		is_out_of_map(t_coords *i, t_cub3d *info);
bool		is_whitespace(t_coords *i, t_cub3d *info);
/*--------------------------------ray_len--------------------------------*/
void		find_ray_len(t_ray *ray, t_coords_d *p);
void		remove_distortion(t_ray *ray, t_cub3d *info);
/*----------------------------wall_projection----------------------------*/
void		calc_proj_slice_len(t_ray *ray, t_cub3d *info);
void		calc_top_wall_y(t_ray *ray, t_cub3d *info);
/*===============================RENDERER================================*/
void		rendering(t_cub3d *info);
void		render_wall_slices(t_cub3d *info);
/*--------------------------------events---------------------------------*/
void		close_window(void *param);
void		handle_keys(void *param);
void		handle_esc_key(mlx_key_data_t keydata, void *param);
int			check_keys(t_cub3d *info);
/*-------------------------------move_keys-------------------------------*/
int			move_keys(t_coords_d *new_p, t_cub3d *info);
int			rotate_keys(t_cub3d *info);
/*----------------------------handle_textures----------------------------*/
void		load_textures(t_cub3d *info);
void		delete_textures_and_imgs(t_cub3d *info);
void		textures_to_img(t_cub3d *info);
void		resize_imgs(t_cub3d *info);

//===============PARSING_CUBE3D_FILE=========================
//--------------Parsing_cub_file_unfiltered------------------
void		print_empty_or_not(char	**res);
void		print_double_str_array(char	**array);
void		print_splited_str(char	**array);
void		free_double_array(char **str);
char		**arr_strdup(char **arr, int size);
//--------------Parsing_cub_file-----------------------------
int			is_empty_line(char *str);
char		**open_and_get_all_lines(char	*path_to_the_file);
//--------------Parsing_texture------------------------------
int			order_is_valid(t_node *dir);
int			paths_are_valid(t_node *compass_dir);
int			colors_are_valid(t_node *compass_dir);
int			valid_textures(t_node *compass_dir);
//--------------Parsing_texture_utils_one--------------------
void		print_node_list(t_node *parse_node);
char		*take_out_all_spaces(t_compass_dir type, char *str);
t_node		*node_new(t_compass_dir type, char *p_or_c);
void		node_add_back(t_node **lst, t_node *new);
//--------------Parsing_texture_utils_two--------------------
void		array_to_list(char **res, t_node **parse_node, t_node **map);
void		define_the_type(char *str, t_node **parse_node, int *f);
long		ft_pos_atol(char *str);
bool		is_valid_color_arg(char	*str);
//--------------Parsing_texture_three------------------------
bool		is_valid_splited_color_arg( char **splited);
void		set_color(t_color *c, char	**splited);
long		ft_pos_atol(char *str);
bool		is_valid_color_arg(char	*str);
//--------------Parsing_map------------------------------------
int			map_valid_by_chars(t_node *map);
int			success_to_cover(t_node *map);
int			valid_map(t_node *map);
//--------------Parsing_map_utils_one--------------------------
int			node_len(t_node	*map);
char		**node_to_array(t_node *map, int len);
//--------------Parsing_map_utils_two--------------------------
int			is_compass_dir_letter(char c);
int			char_not_one(char c);
void		replace_the_chars_with_s(char ***map, int i, int j);
int			count_zeros(char **map);

#endif
