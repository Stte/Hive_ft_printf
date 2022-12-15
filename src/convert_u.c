/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:52:16 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 21:22:56 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_u(t_vec *result, unsigned int c)
{
	char	*num;
	t_vec	tmp;
	int		ret;

	num = ft_ltoa(c);
	if (!num)
		return (-1);
	if (vec_from(&tmp, num, ft_strlen(num), sizeof(char)) < 0)
	{
		free(num);
		return (-1);
	}
	ret = vec_append(result, &tmp);
	free(num);
	vec_free(&tmp);
	return (ret);
}
