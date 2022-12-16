/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:47 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/16 15:06:10 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

// Does conversion and adds it to result.
static int	ft_converts_to_result(t_vec *result, char c, va_list args)
{
	if (c == 'c')
		return (ft_convert_c(result, va_arg(args, int)));
	if (c == 's')
		return (ft_convert_s(result, va_arg(args, char *)));
	if (c == 'p')
		return (ft_convert_p(result, va_arg(args, void *)));
	if (c == 'd')
		return (ft_convert_d(result, va_arg(args, int)));
	if (c == 'i')
		return (ft_convert_i(result, va_arg(args, int)));
	if (c == 'u')
		return (ft_convert_u(result, va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_convert_x(result, va_arg(args, int)));
	if (c == 'X')
		return (ft_convert_upper_x(result, va_arg(args, int)));
	if (c == '%')
		return (ft_percent(result));
	return (-1);
}

// Takes the string part from the string not including % conversions
// and adds it to result.
static int	ft_substring_to_result(t_vec *result, int i, const char *str)
{
	char	*substr;
	t_vec	tmp;
	int		ret;

	if (i)
	{
		substr = ft_substr(str, 0, i);
		if (!substr)
			return (-1);
		ret = vec_from(&tmp, substr, ft_strlen(substr), sizeof(char));
		free(substr);
		if (ret < 0)
			return (-1);
		ret = vec_append(result, &tmp);
		vec_free(&tmp);
		if (ret < 0)
			return (-1);
	}
	return (1);
}

// Adds the whole string including % conversions to result.
static int	ft_get_string(t_vec *result, const char *str, va_list args)
{
	char	*percentage;
	int		i;
	t_vec	tmp;
	int		ret;

	percentage = ft_strchr(str, '%');
	while (percentage)
	{
		i = (int)(percentage - str);
		if (ft_substring_to_result(result, i, str) < 0)
			return (-1);
		if (ft_converts_to_result(result, *(percentage + 1), args) < 0)
			return (-1);
		str = str + (i + 2);
		percentage = ft_strchr(str, '%');
	}
	if (!*str)
		return (1);
	if (vec_from(&tmp, (void *)str, ft_strlen(str), sizeof(char)) < 0)
		return (-1);
	ret = vec_append(result, &tmp);
	vec_free(&tmp);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_vec	result;
	size_t	res_len;

	va_start(args, str);
	if (vec_new(&result, 10, sizeof(char)) < 0)
		return (-1);
	if (ft_get_string(&result, str, args) < 0)
	{
		vec_free(&result);
		return (-1);
	}
	va_end(args);
	write(1, result.memory, result.len);
	res_len = result.len;
	vec_free(&result);
	return (res_len);
}
