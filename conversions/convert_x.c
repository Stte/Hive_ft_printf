/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:09:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/09 23:04:50 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_convert_x(int i)
{
	char	*hex;

	hex = ft_ulongtohex((unsigned int)i);
	return (hex);
}
