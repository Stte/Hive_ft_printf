/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:09:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 20:04:43 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_x(t_vec *result, int i)
{
	char	*hex;
	t_vec	tmp;
	int		ret;

	hex = ft_ulongtohex((unsigned int)i);
	if (!hex)
		return (-1);
	if (vec_from(&tmp, hex, ft_strlen(hex), sizeof(char)) < 0)
	{
		free(hex);
		return (-1);
	}
	free(hex);
	ret = vec_append(result, &tmp);
	vec_free(&tmp);
	return (ret);
}
