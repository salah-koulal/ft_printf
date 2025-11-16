/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:38:30 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/16 11:05:33 by skoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	into_hex(unsigned int nb, char *base)
{
	int	c;

	c = 0;
	if (nb >= 16)
		c = into_hex(nb / 16, base);
	c += ft_putchar(base[nb % 16]);
	return (c);
}

int	ft_put_hex(unsigned int num, char c)
{
	int	count;

	count = 0;
	if (c == 'X')
		count = into_hex(num, "0123456789ABCDEF");
	else if (c == 'x')
		count = into_hex(num, "0123456789abcdef");
	return (count);
}
