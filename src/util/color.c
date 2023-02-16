/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:50 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/31 18:37:34 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_gradient	gradient(uint32_t from, uint32_t to)
{
	t_gradient	gradient;

	gradient.from = from;
	gradient.to = to;
	return (gradient);
}

uint32_t	interpolcol(t_gradient gradient, float factor)
{
	uint32_t		color;
	uint8_t			*current_channel;
	uint8_t			*from;
	uint8_t			*to;
	unsigned int	offset;

	offset = 0;
	while (offset < 4)
	{
		current_channel = ((uint8_t *)&color) + offset;
		from = ((uint8_t *)&gradient.from) + offset;
		to = ((uint8_t *)&gradient.to) + offset;
		*current_channel = *from + (*to - *from) * factor;
		offset++;
	}
	return (color);
}
