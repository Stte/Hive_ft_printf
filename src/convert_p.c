/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:30:38 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 21:38:36 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_p(t_vec *result, void *ptr)
{
	char	*hex;
	t_vec	tmp;
	int		ret;
	char	*address;

	hex = ft_ulongtohex((unsigned long)ptr);
	if (!hex)
		return (-1);
	address = ft_strjoin("0x", hex);
	free(hex);
	if (!address)
		return (-1);
	if (vec_from(&tmp, address, ft_strlen(address), sizeof(char)) < 0)
	{
		free(address);
		return (-1);
	}
	ret = vec_append(result, &tmp);
	free(address);
	vec_free(&tmp);
	return (ret);
}
