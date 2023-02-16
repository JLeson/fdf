/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:37:12 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/16 19:33:42 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_grid	*grid;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!ft_strnstr(*(argv + 1), ".fdf", ft_strlen(*(argv + 1))))
		exit(EXIT_FAILURE);
	fdf = init_fdf(*(argv + 1), 1800, 1100);
	if (!fdf)
		exit(EXIT_FAILURE);
	grid = init_grid(fdf);
	if (!grid)
	{
		free(fdf);
		exit(EXIT_FAILURE);
	}
	fdf->grid = grid;
	mlx_image_to_window(fdf->handle, fdf->screen, 0, 0);
	mlx_loop_hook(fdf->handle, &update, fdf);
	mlx_resize_hook(fdf->handle, &resize, fdf);
	mlx_loop(fdf->handle);
	mlx_terminate(fdf->handle);
	exit(EXIT_SUCCESS);
}
