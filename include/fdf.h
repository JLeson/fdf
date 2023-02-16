/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:37:27 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/16 19:04:55 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define CLEAR_COLOR 0x000000FF
# define DEFAULT_COLOR 0xFFFFFFFF
# define MOVE_SPEED 17;
# define ROTATION_SPEED 0.05;
# define SCALING_SPEED 1;

# include <stddef.h>
# include "MLX42.h"

typedef struct gradient
{
	uint32_t	from;
	uint32_t	to;
}	t_gradient;

typedef struct vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct mat2x3
{
	t_vec3	v0;
	t_vec3	v1;
}	t_mat2x3;

typedef struct mat3x3
{
	t_vec3	v0;
	t_vec3	v1;
	t_vec3	v2;
}	t_mat3x3;

typedef struct rotationmatrix
{
	t_mat3x3	x;
	t_mat3x3	y;
	t_mat3x3	z;
}	t_rmatrix;

typedef struct vertex
{
	t_vec3		position;
	uint32_t	color;
}	t_vertex;

typedef struct transform
{
	t_vec3	position;
	t_vec3	rotation;
	t_vec3	scale;	
}	t_transform;

typedef struct line
{
	t_vec2	p0;
	t_vec2	p1;
}	t_line;

typedef struct grid
{
	t_vertex	*vertices;
	int			width;
	int			height;
	int			line_width;
	t_transform	transform;
}	t_grid;

typedef struct fdf
{
	mlx_t		*handle;
	mlx_image_t	*screen;
	char		*map;
	t_grid		*grid;
	t_mat2x3	projection;
}	t_fdf;

//	init.c

t_fdf		*init_fdf(char	*map, int screen_width, int screen_height);
t_grid		*init_grid(t_fdf *fdf);

//	parse.c

char		*get_data(char *map);
int			get_width(char *data);
int			get_height(char *data);
t_vertex	*init_vertices(char	*data, int width, int height);

//	screen.c

void		fdf_set_pixel(uint32_t *pixel, uint32_t color);
void		fdf_clear_screen(t_fdf *fdf, uint32_t color);

//	draw.c

void		fdf_draw_point(t_fdf *fdf, t_vec2 p, uint32_t p_color,
				unsigned int size);
void		fdf_draw_line(t_fdf *fdf, t_line line, uint32_t color,
				int width);
void		fdf_draw_gradient_line(t_fdf *fdf, t_line line, t_gradient gradient,
				int width);

//	hooks.c

void		update(void *param);
void		resize(int32_t width, int32_t height, void *param);

//		wireframe.c

void		fdf_draw_wireframe(t_fdf *fdf);

//	UTILITY FUNCTIONS ------------------------------------------
//		math.c

t_vec2		projectpoint(t_mat2x3 projmatrix, t_vec3 point);
t_vec3		transformvertex(t_vec3 point, t_transform transform);

//		matrices.c

t_mat2x3	mat3x2(t_vec3 v0, t_vec3 v1);
t_mat3x3	mat3x3(t_vec3 v0, t_vec3 v1, t_vec3 v2);
t_rmatrix	rotationmatrix(double x, double y, double z);

//		vectors.c

t_vec2		vec2(double x, double y);
t_vec3		vec3(double x, double y, double z);

//		grid.c

int			grid_pointtoidx(t_grid *grid, int x, int z);
t_vec3		grid_idxtopoint(t_grid *grid, int idx);

//		misc.c

t_transform	transform(t_vec3 position, t_vec3 rotation, t_vec3 scale);
t_line		line(t_vec2 p0, t_vec2 p1);

// color.c

t_gradient	gradient(uint32_t from, uint32_t to);
uint32_t	interpolcol(t_gradient gradient, float factor);
#endif