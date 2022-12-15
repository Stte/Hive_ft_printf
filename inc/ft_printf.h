/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:54 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/15 15:22:52 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*ft_convert_c(int c);
char	*ft_convert_d(int c);
char	*ft_convert_i(int c);
char	*ft_convert_p(void *ptr);
char	*ft_convert_s(char *str);
char	*ft_convert_u(unsigned int c);
char	*ft_convert_upper_x(int i);
char	*ft_convert_x(int i);
char	*ft_percent(void);
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
int		ft_printf(const char *str, ...);

#endif