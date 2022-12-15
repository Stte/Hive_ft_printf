/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:30:38 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 22:35:24 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_s(t_vec *result, char *str)
{
	t_vec	tmp;
	int		ret;

	if (!str)
	{
		if (vec_from(&tmp, "(null)", 6, sizeof(char)) < 0)
			return (-1);
		ret = vec_append(result, &tmp);
		vec_free(&tmp);
		return (1);
	}
	if (!*str)
		return (1);
	if (vec_from(&tmp, str, ft_strlen(str), sizeof(char)) < 0)
		return (-1);
	ret = vec_append(result, &tmp);
	vec_free(&tmp);
	return (ret);
}
