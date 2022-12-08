/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:09:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/08 17:15:35 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h" // check this

char	*ft_convert_x(int i)
{
	char	*hex;

	hex = ft_ulongtohex((unsigned int)i);
	return (hex);
}



