/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_upper_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:09:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 21:54:29 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_item_to_upper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	ft_convert_upper_x(t_vec *result, int i)
{
	char	*hex;
	t_vec	tmp;
	int		ret;
	char	*upper_hex;

	hex = ft_ulongtohex((unsigned int)i);
	if (!hex)
		return (-1);
	upper_hex = ft_strmapi(hex, ft_item_to_upper);
	free(hex);
	if (!upper_hex)
		return (-1);
	if (vec_from(&tmp, upper_hex, ft_strlen(upper_hex), sizeof(char)) < 0)
	{
		free(upper_hex);
		return (-1);
	}
	free(upper_hex);
	ret = vec_append(result, &tmp);
	vec_free(&tmp);
	return (ret);
}
