/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:36:33 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/09 23:50:57 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = ft_strlen(src);
	if (dstsize > 0)
	{
		if (n < dstsize)
			ft_memcpy(dst, src, n + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (n);
}
