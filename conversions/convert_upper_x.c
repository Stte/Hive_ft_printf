/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_upper_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:09:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/09 23:56:12 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	ft_item_to_upper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

char	*ft_convert_upper_x(int i)
{
	char	*hex;
	char	*result;

	hex = ft_ulongtohex((unsigned int)i);
	if (!hex)
		return (NULL);
	result = ft_strmapi(hex, ft_item_to_upper);
	free(hex);
	return (result);
}
