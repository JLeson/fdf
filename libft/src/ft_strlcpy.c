/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:00:05 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/26 17:22:40 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		offset;

	if (!dstsize)
		return (ft_strlen(src));
	offset = 0;
	while (*(src + offset) && offset < dstsize - 1)
	{	
		*(dst + offset) = *(src + offset);
		offset++;
	}
	*(dst + offset) = 0;
	return (ft_strlen(src));
}
