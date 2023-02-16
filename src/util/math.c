/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:51:56 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/31 16:36:05 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	projectpoint(t_mat2x3 projmatrix, t_vec3 point)
{
	t_vec2	vec2;

	vec2.x = (projmatrix.v0.x * point.x)
		+ (projmatrix.v0.y * point.y)
		+ (projmatrix.v0.z * point.z);
	vec2.y = (projmatrix.v1.x * point.x)
		+ (projmatrix.v1.y * point.y)
		+ (projmatrix.v1.z * point.z);
	return (vec2);
}

static t_vec3	rotpoint(t_mat3x3 rotmatrix, t_vec3 point)
{
	t_vec3	vec3;

	vec3.x = (rotmatrix.v0.x * point.x)
		+ (rotmatrix.v0.y * point.y)
		+ (rotmatrix.v0.z * point.z);
	vec3.y = (rotmatrix.v1.x * point.x)
		+ (rotmatrix.v1.y * point.y)
		+ (rotmatrix.v1.z * point.z);
	vec3.z = (rotmatrix.v2.x * point.x)
		+ (rotmatrix.v2.y * point.y)
		+ (rotmatrix.v2.z * point.z);
	return (vec3);
}

t_vec3	transformvertex(t_vec3 point, t_transform transform)
{
	t_rmatrix	rmatrix;

	rmatrix = rotationmatrix(transform.rotation.x,
			transform.rotation.y, transform.rotation.z);
	point.x *= transform.scale.x;
	point.y *= transform.scale.y;
	point.z *= transform.scale.z;
	point = rotpoint(rmatrix.x, point);
	point = rotpoint(rmatrix.y, point);
	point = rotpoint(rmatrix.z, point);
	point.x += transform.position.x;
	point.y += transform.position.y;
	return (point);
}
