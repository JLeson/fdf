/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:07:28 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/31 17:49:35 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	grid_pointtoidx(t_grid *grid, int x, int z)
{	
	if (x >= grid->width || z >= grid->height)
		return (-1);
	return (z * grid->width + x);
}

// t_vec3	grid_idxtopoint(t_grid *grid, int idx)
// {
// 	t_vec3		point;

// 	point.x = (idx % grid->width) - grid->width / 2;
// 	point.y = (grid->vertices + idx)->position.y;
// 	point.z = idx / grid->width - grid->height / 2;
// 	return (point);
// }
