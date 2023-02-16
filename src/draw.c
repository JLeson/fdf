/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:33 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/02 15:44:14 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "fdf.h"

static void	fdf_put_pixel(t_fdf *fdf, t_vec2 p, uint32_t color)
{
	uint32_t	*pixel;

	if (p.x < 0 || p.y < 0)
		return ;
	if (fdf->screen->width - 1 < p.x || fdf->screen->height - 1 < p.y)
		return ;
	pixel = (uint32_t *)fdf->screen->pixels
		+ ((int)p.y * fdf->screen->width + (int)p.x);
	fdf_set_pixel(pixel, color);
}

void	fdf_draw_point(t_fdf *fdf, t_vec2 p, uint32_t p_color,
				unsigned int size)
{
	unsigned int	x;
	unsigned int	y;

	if (!size)
		return ;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			fdf_put_pixel(fdf, vec2(p.x + x, p.y + y), p_color);
			x++;
		}
		y++;
	}
}

void	fdf_draw_line(t_fdf *fdf, t_line line, uint32_t color,
				int width)
{
	float	interpol_factor;
	int		steps;
	int		x;
	int		y;
	int		i;

	steps = ft_max(ft_abs(line.p1.x - line.p0.x),
			ft_abs(line.p1.y - line.p0.y)) + 1;
	i = 0;
	while (i < steps)
	{
		interpol_factor = (float)i / (float)steps;
		x = line.p0.x + (line.p1.x - line.p0.x) * interpol_factor;
		y = line.p0.y + (line.p1.y - line.p0.y) * interpol_factor;
		fdf_draw_point(fdf, vec2(round(x), round(y)), color, width);
		i++;
	}
}

void	fdf_draw_gradient_line(t_fdf *fdf, t_line line, t_gradient gradient,
				int width)
{
	float	interpol_factor;
	int		steps;
	int		x;
	int		y;
	int		i;

	steps = ft_max(ft_abs(line.p1.x - line.p0.x),
			ft_abs(line.p1.y - line.p0.y)) + 1;
	i = 0;
	while (i < steps)
	{
		interpol_factor = (float)i / (float)steps;
		x = line.p0.x + (line.p1.x - line.p0.x) * interpol_factor;
		y = line.p0.y + (line.p1.y - line.p0.y) * interpol_factor;
		fdf_draw_point(fdf, vec2(round(x), round(y)),
			interpolcol(gradient, interpol_factor), width);
		i++;
	}
}
