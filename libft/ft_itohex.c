/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:20:01 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/03 17:14:18 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_hex_char_count(long num)
{
	int		i;

	i = 1;
	while (num >= 16)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static char	ft_decimal16_to_hex(int dec)
{
	if (dec < 10)
		return (dec + '0');
	if (dec == 10)
		return ('a');
	if (dec == 11)
		return ('b');
	if (dec == 12)
		return ('c');
	if (dec == 13)
		return ('d');
	if (dec == 14)
		return ('e');
	if (dec == 15)
		return ('f');
	return (0);
}

char	*ft_itohex(unsigned int n)
{
	char	*str;
	long	num;
	int		len;
	int		hex;

	num = n;
	len = ft_hex_char_count(num);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len)
	{
		hex = ft_decimal16_to_hex(num % 16);
		str[len - 1] = hex;
		num = num / 16;
		len--;
	}
	return (str);
}
