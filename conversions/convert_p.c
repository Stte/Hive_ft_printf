/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:30:38 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/08 16:30:01 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h" // check that includes are correct. Probably have to remove this.

char	*ft_convert_p(void *ptr)
{
	char	*hex;
	char	*result;

	hex = ft_ulongtohex((unsigned long)ptr);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}
