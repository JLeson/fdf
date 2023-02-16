/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:48:06 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/16 18:47:53 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void	trans_scale(t_fdf *fdf);
static void	rotation(t_fdf *fdf);
static void	line_w(t_fdf *fdf);

void	update(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->handle);
	fdf_clear_screen(fdf, CLEAR_COLOR);
	rotation(fdf);
	trans_scale(fdf);
	line_w(fdf);
	fdf_draw_wireframe(fdf);
	mlx_image_to_window(fdf->handle, fdf->screen, 0, 0);
}

void	resize(int32_t width, int32_t height, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_delete_image(fdf->handle, fdf->screen);
	fdf->screen = mlx_new_image(fdf->handle, width, height);
}

static void	trans_scale(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->handle, MLX_KEY_A))
		fdf->grid->transform.position.x += MOVE_SPEED
	if (mlx_is_key_down(fdf->handle, MLX_KEY_D))
		fdf->grid->transform.position.x -= MOVE_SPEED;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_W))
		fdf->grid->transform.position.y += MOVE_SPEED;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_S))
		fdf->grid->transform.position.y -= MOVE_SPEED;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_EQUAL))
	{
		fdf->grid->transform.scale.x += SCALING_SPEED;
		fdf->grid->transform.scale.y += SCALING_SPEED;
		fdf->grid->transform.scale.z += SCALING_SPEED;
	}
	if (mlx_is_key_down(fdf->handle, MLX_KEY_MINUS))
	{
		fdf->grid->transform.scale.x -= SCALING_SPEED;
		fdf->grid->transform.scale.y -= SCALING_SPEED;
		fdf->grid->transform.scale.z -= SCALING_SPEED;
	}
}

static void	rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->handle, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_is_key_down(fdf->handle, MLX_KEY_LEFT))
			fdf->grid->transform.rotation.z += ROTATION_SPEED;
		if (mlx_is_key_down(fdf->handle, MLX_KEY_RIGHT))
			fdf->grid->transform.rotation.z -= ROTATION_SPEED;
	}
	else
	{
		if (mlx_is_key_down(fdf->handle, MLX_KEY_LEFT))
			fdf->grid->transform.rotation.y -= ROTATION_SPEED;
		if (mlx_is_key_down(fdf->handle, MLX_KEY_RIGHT))
			fdf->grid->transform.rotation.y += ROTATION_SPEED;
	}
	if (mlx_is_key_down(fdf->handle, MLX_KEY_UP))
		fdf->grid->transform.rotation.x -= ROTATION_SPEED;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_DOWN))
		fdf->grid->transform.rotation.x += ROTATION_SPEED;
}

static void	line_w(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->handle, MLX_KEY_E))
		fdf->grid->line_width += 1;
	if (fdf->grid->line_width == 1)
		return ;
	if (mlx_is_key_down(fdf->handle, MLX_KEY_Q))
		fdf->grid->line_width -= 1;
}
