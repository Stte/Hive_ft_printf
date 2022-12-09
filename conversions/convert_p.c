/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:30:38 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/09 22:43:30 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_convert_p(void *ptr)
{
	char	*hex;
	char	*result;

	hex = ft_ulongtohex((unsigned long)ptr);
	if (!hex)
		return (NULL);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}
