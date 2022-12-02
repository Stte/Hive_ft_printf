/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:31:47 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/30 23:20:04 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_check_char(char c)
{

}

// int	ft_printf(const char *str, ...)
int	ft_printf(int max, ...)
{
	va_list	args;
	int		i = 0;
	// char	*s;
	// char	c;
	// int		d;

	va_start(args, max);
	while (i < max)
	{
		printf("%s\n", va_arg(args, char *));
		i++;
	}
	va_end(args);
	return (1);
}
