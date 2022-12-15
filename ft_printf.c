/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:47 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 14:50:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Checks the character and returns a string based on the conversion.
static char	*ft_check_char(char c, va_list args)
{
	if (c == 'c')
		return (ft_convert_c(va_arg(args, int)));
	if (c == 's')
		return (ft_convert_s(va_arg(args, char *)));
	if (c == 'p')
		return (ft_convert_p(va_arg(args, void *)));
	if (c == 'd')
		return (ft_convert_d(va_arg(args, int)));
	if (c == 'i')
		return (ft_convert_i(va_arg(args, int)));
	if (c == 'u')
		return (ft_convert_u(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_convert_x(va_arg(args, int)));
	if (c == 'X')
		return (ft_convert_upper_x(va_arg(args, int)));
	if (c == '%')
		return (ft_percent());
	return (NULL);
}

// Does conversion and adds it to result.
static int	ft_converts_to_result(char **result, char *percentage, va_list args)
{
	char	*str;
	char	*tmp;

	str = ft_check_char(*(percentage + 1), args);
	if (!str)
		return (0);
	tmp = ft_strjoin(*result, str);
	free(str);
	if (!tmp)
		return (0);
	free(*result);
	*result = tmp;
	return (1);
}

// Takes the string part from the string not including % conversions
// and adds it to result.
static int	ft_substring_to_result(char **result, int i, const char *str)
{
	char	*substr;
	char	*tmp;

	if (i)
	{
		substr = ft_substr(str, 0, i);
		if (!substr)
			return (0);
		tmp = ft_strjoin(*result, substr);
		free(substr);
		if (!tmp)
			return (0);
		free(*result);
		*result = tmp;
	}
	return (1);
}

// Adds the whole string including % conversions to result.
static int	ft_get_string(char **result, const char *str, va_list args)
{
	char	*percentage;
	int		i;
	char	*tmp;

	percentage = ft_strchr(str, '%');
	while (percentage)
	{
		i = (int)(percentage - str);
		if (!ft_substring_to_result(result, i, str))
			return (0);
		if (!ft_converts_to_result(result, percentage, args))
			return (0);
		str = str + (i + 2);
		percentage = ft_strchr(str, '%');
	}
	tmp = ft_strjoin(*result, str);
	if (!tmp)
		return (0);
	free(*result);
	*result = tmp;
	return (1);
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
	char	*result;
	int		result_len;

	va_start(args, str);
	result = ft_calloc(1, 1);
	if (!result)
		return (-1);
	if (!ft_get_string(&result, str, args))
	{
		free(result);
		result = NULL;
		return (-1);
	}
	va_end(args);
	result_len = ft_strlen(result);
	write(1, result, result_len);
	free(result);
	return (result_len);
}

