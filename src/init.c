/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:16:23 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/16 15:13:06 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

t_fdf	*init_fdf(char	*map, int screen_width, int screen_height)
{
	t_fdf		*fdf;
	mlx_t		*mlx;
	mlx_image_t	*screen;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	mlx = mlx_init(screen_width, screen_height, "fdf", true);
	if (!mlx)
	{
		free(fdf);
		return (NULL);
	}
	screen = mlx_new_image(mlx, screen_width, screen_height);
	if (!screen)
	{
		free(fdf);
		free(screen);
		return (NULL);
	}
	fdf->handle = mlx;
	fdf->screen = screen;
	fdf->map = map;
	fdf->projection = mat3x2(vec3(1, 0, 0), vec3(0, 1, 0));
	return (fdf);
}

t_grid	*init_grid(t_fdf *fdf)
{
	t_grid	*grid;
	char	*data;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	data = get_data(fdf->map);
	if (!data)
		return (NULL);
	grid->width = get_width(data);
	grid->height = get_height(data);
	grid->vertices = init_vertices(data, grid->width, grid->height);
	grid->transform = transform(
			vec3(fdf->screen->width / 2, fdf->screen->height / 2, 0),
			vec3(10.5, 0.45, 0.65),
			vec3(30, 30, 30));
	grid->line_width = 1;
	free(data);
	return (grid);
}
