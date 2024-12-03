/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:47:03 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/29 13:55:11 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long nbr)
{
	char	*str;
	int		len;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		*str = '-';
	}
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

static int	ft_hexlen(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_xtoa(uintptr_t nbr, int shift)
{
	char	*str;
	char	temp;
	int		len;

	len = ft_hexlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		temp = nbr % 16;
		if (temp > 9)
			str[--len] = temp + shift + '0';
		else
			str[--len] = temp + '0';
		nbr /= 16;
	}
	return (str);
}
