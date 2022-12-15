/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:13:30 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 21:22:06 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_d(t_vec *result, int c)
{
	char	*num;
	t_vec	tmp;
	int		ret;

	num = ft_itoa(c);
	if (!num)
		return (-1);
	if (vec_from(&tmp, num, ft_strlen(num), sizeof(char)) < 0)
	{
		free(num);
		return (-1);
	}
	ret = vec_append(result, &tmp);
	vec_free(&tmp);
	free(num);
	return (ret);
}
