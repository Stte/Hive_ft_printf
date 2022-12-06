/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:47 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/06 15:12:23 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// Checks the character and returns a string based on the conversion.
static char	*ft_check_char(char c, va_list args)
{
	if (c == 'c')
		return (ft_convert_c(va_arg(args, int)));
	if (c == 's')
		return (ft_convert_s(va_arg(args, char *)));
	if (c == 'p')
		return (ft_convert_p(va_arg(args, void *)));
	return (NULL);
}

/**
 * @brief Print.
 *
 * Handles the following conversions: cspdiuxX%
 *
 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %p The void * pointer argument has to be printed in hexadecimal format.
 * %d Prints a decimal (base 10) number.
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %% Prints a percent sign.
 *
 * @param str Text to print
 * @param ... Values to convert to string
 * @return int Length of the returned string
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*percentage;
	char	*result;
	int		i;
	int		result_len;
	char	*tmp;

	va_start(args, str);
	percentage = ft_strchr(str, '%');
	if (!percentage)
		result = (char *)str;
	result = ft_calloc(1,1);
	if (!result)
		return (0);
	while (percentage)
	{
		i = (int)(percentage - str); // index of percent start
		if (i)
		{
			tmp = ft_strjoin(result, ft_substr(str, 0, i)); // takes the chars till % and joins that into result
			free(result);
			result = tmp;
		}
		if (!result)
			return (0);
		tmp = ft_strjoin(result, ft_check_char(*(percentage + 1), args)); // does conversion and store into result
		free(result);
		result = tmp;
		if (!result)
			return (0);
		str = str + (i + 2); // moves str to character after the conversion
		percentage = ft_strchr(str, '%'); // finds next %
		if (!percentage)
		{
			tmp = ft_strjoin(result, str);
			free(result);
			result = tmp;
		}
	}
	va_end(args);
	result_len = ft_strlen(result);
	write(1, result, result_len);
	free(result);
	return (result_len);
}
