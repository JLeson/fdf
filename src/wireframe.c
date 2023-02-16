/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:11:32 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/31 18:42:30 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_relative_vertex(t_fdf *fdf, int idx, int x, int z)
{
	int	vert_x;
	int	vert_z;

	vert_x = idx % fdf->grid->width + x;
	vert_z = idx / fdf->grid->width + z;
	return (grid_pointtoidx(fdf->grid, vert_x, vert_z));
}

static t_vertex	transform_vertex(t_fdf *fdf, int idx)
{
	t_vertex	vertex;

	vertex = *(fdf->grid->vertices + idx);
	vertex.position = transformvertex(vertex.position, fdf->grid->transform);
	return (vertex);
}

static void	draw_line(t_fdf *fdf, int idx, int x, int z)
{
	t_line		drawnline;
	t_vertex	start;
	t_vertex	end;
	int			vidx;

	vidx = get_relative_vertex(fdf, idx, x, z);
	if (vidx == -1)
		return ;
	start = transform_vertex(fdf, idx);
	end = transform_vertex(fdf, vidx);
	drawnline = line(projectpoint(fdf->projection, start.position),
			projectpoint(fdf->projection, end.position));
	fdf_draw_gradient_line(fdf, drawnline, gradient(start.color, end.color),
		fdf->grid->line_width);
}

void	fdf_draw_wireframe(t_fdf *fdf)
{
	t_grid	*grid;
	int		offset;

	grid = fdf->grid;
	offset = 0;
	while (offset < grid->width * grid->height)
	{
		draw_line(fdf, offset, 1, 0);
		draw_line(fdf, offset, 0, 1);
		offset++;
	}
}
