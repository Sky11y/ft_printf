/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:18 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/29 13:50:48 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/********** EXTERNAL LIBS **********/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

/********** DEFINES **********/

# define SPECIFIERS "cspdiuxX%"

/********** FUNCTIONS **********/

int		ft_printf(const char *fmt, ...);
int		ft_printnbr_n(long nbr);
int		ft_printptr_n(void *ptr);
int		ft_printhex_n(uintptr_t nbr, int shift);
int		ft_putchar_n(int c);
int		ft_putstr_n(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_ltoa(long nbr);
char	*ft_xtoa(unsigned long nbr, int shift);

#endif
