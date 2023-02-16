/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:22 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/31 17:49:38 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_transform	transform(t_vec3 position, t_vec3 rotation, t_vec3 scale)
{
	t_transform	transform;

	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;
	return (transform);
}

t_line	line(t_vec2 p0, t_vec2 p1)
{
	t_line	line;

	line.p0 = p0;
	line.p1 = p1;
	return (line);
}
