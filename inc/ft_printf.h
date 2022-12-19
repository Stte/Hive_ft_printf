/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:54 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/19 15:07:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_convert_c(t_vec *result, int c);
int	ft_convert_d(t_vec *result, int c);
int	ft_convert_i(t_vec *result, int c);
int	ft_convert_p(t_vec *result, void *ptr);
int	ft_convert_s(t_vec *result, char *str);
int	ft_convert_u(t_vec *result, unsigned int c);
int	ft_convert_upper_x(t_vec *result, int i);
int	ft_convert_x(t_vec *result, int i);
int	ft_percent(t_vec *result);
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
int	ft_printf(const char *str, ...);

#endif
