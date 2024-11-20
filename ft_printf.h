/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:18 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/20 14:12:42 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/********** EXTERNAL LIBS **********/

# include <unistd.h>
# include <stdarg.h>

/********** DEFINES **********/

# define NUMS_LOW "0123456789abcdef"
# define NUMS_UP "0123456789ABCDEF"
# define SPECIFIERS "cspdiuxX%"

/********** FUNCTIONS **********/

int	ft_printf(const char *fmt, ...);
int	ft_putnbr_base_n(long nbr, char *str, int base);
int	ft_putptr_n(void *ptr);
int	ft_putchar_n(int c);
int	ft_putstr_n(const char *s);

#endif
