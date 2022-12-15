/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:42:33 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 15:29:14 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_c(int c)
{
	char	*str;

	str = ft_calloc(2, 1);
	if (!str || !ft_isalnum(c))
		return (NULL);
	return (ft_memset(str, c, 1));
}
