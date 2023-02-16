/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:02 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/27 19:30:57 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_mat2x3	mat3x2(t_vec3 v0, t_vec3 v1)
{
	t_mat2x3	mat;

	mat.v0 = v0;
	mat.v1 = v1;
	return (mat);
}

t_mat3x3	mat3x3(t_vec3 v0, t_vec3 v1, t_vec3 v2)
{
	t_mat3x3	mat;

	mat.v0 = v0;
	mat.v1 = v1;
	mat.v2 = v2;
	return (mat);
}

t_rmatrix	rotationmatrix(double x, double y, double z)
{
	t_rmatrix	rmat;
	t_mat3x3	x_mat;
	t_mat3x3	y_mat;
	t_mat3x3	z_mat;

	x_mat = mat3x3(vec3(1, 0, 0),
			vec3(0, cos(x), -sin(x)),
			vec3(0, sin(x), cos(x)));
	y_mat = mat3x3(vec3(cos(y), 0, sin(y)),
			vec3(0, 1, 0),
			vec3(-sin(y), 0, cos(y)));
	z_mat = mat3x3(vec3(cos(z), -sin(z), 0),
			vec3(sin(z), cos(z), 0),
			vec3(0, 0, 1));
	rmat.x = x_mat;
	rmat.y = y_mat;
	rmat.z = z_mat;
	return (rmat);
}
