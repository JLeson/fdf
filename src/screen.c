/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:28 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/02 15:47:31 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	fdf_set_pixel(uint32_t *pixel, uint32_t color)
{
	uint8_t	*channels;

	channels = (uint8_t *)pixel;
	*(channels) = (uint8_t)(color >> 24);
	*(channels + 1) = (uint8_t)(color >> 16);
	*(channels + 2) = (uint8_t)(color >> 8);
	*(channels + 3) = (uint8_t)(color & 0xFF);
}

void	fdf_clear_screen(t_fdf *fdf, uint32_t color)
{
	unsigned int	offset;
	unsigned int	size;
	uint32_t		*pixels;

	pixels = (uint32_t *)fdf->screen->pixels;
	size = fdf->screen->width * fdf->screen->height;
	offset = 0;
	while (offset < size)
	{
		fdf_set_pixel(pixels + offset, color);
		offset++;
	}
}
