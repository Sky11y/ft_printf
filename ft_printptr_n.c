/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:52:59 by jpiensal          #+#    #+#             */
/*   Updated: 2024/12/02 18:44:44 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr_n(void *ptr)
{
	int		count;
	int		check;
	char	*str;

	if (!(uintptr_t)ptr)
	{
		count = ft_putstr_n("(nil)");
		return (count);
	}
	count = ft_putstr_n("0x");
	if (count == -1)
		return (count);
	str = ft_xtoa((uintptr_t)ptr, 39);
	check = ft_putstr_n(str);
	if (check == -1)
		return (check);
	count += check;
	free(str);
	return (count);
}
