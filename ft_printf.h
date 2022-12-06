/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:54 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/06 14:50:59 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

char	*ft_convert_c(int c);
char	*ft_convert_p(void *ptr);
char	*ft_convert_s(char *str);
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


// add to libft

/**
 * @brief Unsigned long to hexadecimal.
 *
 * Returns given unsigned long (e.g. casted pointer) to hexadecimal string.
 *
 * @param n Unsigned long
 * @return char Hexadecimal
 * @attention Allocates memory
 */
char	*ft_ulongtohex(unsigned long n);

#endif
