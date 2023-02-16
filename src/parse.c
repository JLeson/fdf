/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:18:28 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/03 16:14:25 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

char	*get_data(char *map)
{
	int		fd;
	char	*next_line;
	char	*line;
	char	*temp_ln;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
		exit (EXIT_FAILURE);
	while (next_line)
	{
		temp_ln = ft_strjoin(line, next_line);
		free(line);
		free(next_line);
		line = temp_ln;
		next_line = get_next_line(fd);
	}
	close(fd);
	return (line);
}

int	get_width(char *data)
{
	int				width;
	unsigned int	offset;

	width = 0;
	offset = 0;
	while (*(data + offset) != '\n' && *(data + offset))
	{
		if (ft_isdigit(*(data + offset)))
			width++;
		while (ft_isdigit(*(data + offset)))
			offset++;
		if (*(data + offset) == ',')
			offset += 3;
		while (ft_ishdigit(*(data + offset)))
			offset++;
		while (!ft_isdigit(*(data + offset)))
		{
			if (*(data + offset) == '\n')
				break ;
			if (*(data + offset) == '\0')
				break ;
			offset++;
		}
	}
	return (width);
}

int	get_height(char *data)
{
	int				height;
	unsigned int	offset;

	height = 0;
	offset = 0;
	while (*(data + offset))
	{
		if (*(data + offset) == '\n')
			height++;
		offset++;
	}
	if (*(data + offset - 1) != '\n')
		height++;
	return (height);
}

static t_vec3	vert(char *start_vertex, unsigned int voffset,
	int width, int height)
{
	t_vec3	vertex_position;
	int		idx;

	idx = (int) voffset;
	vertex_position.x = (idx % width) - width / 2;
	vertex_position.y = ft_atoi(start_vertex);
	vertex_position.z = (idx / width) - height / 2;
	return (vertex_position);
}

t_vertex	*init_vertices(char	*data, int width, int height)
{
	static unsigned int	di = 0;
	unsigned int		voffset;
	t_vertex			*verts;

	voffset = 0;
	verts = (t_vertex *)malloc(width * height * sizeof(t_vertex));
	while (*(data + di))
	{
		(verts + voffset)->position = vert(data + di, voffset, width, height);
		while (ft_isdigit(*(data + di)) || *(data + di) == '-')
			di++;
		if (*(data + di) == ',')
		{
			(verts + voffset)->color = ft_htoi(data + ++di);
			di += 2;
		}
		else
			(verts + voffset)->color = DEFAULT_COLOR;
		while (ft_ishdigit(*(data + di)))
			di++;
		while (ft_isspace(*(data + di)))
			di++;
		voffset++;
	}
	return (verts);
}
