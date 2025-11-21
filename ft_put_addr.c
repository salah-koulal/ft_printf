/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:23:49 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/20 19:27:06 by skoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	into_hex(unsigned long nb, char *base)
{
	int	c;

	c = 0;
	if (nb >= 16)
		c = into_hex(nb / 16, base);
	c += ft_putchar(base[nb % 16]);
	return (c);
}

int	ft_put_address(unsigned long p)
{
	int				c;

	c = 0;
	if (p == 0)
		return (ft_putstr("(nil)"));
	c = ft_putstr("0x");
	c += into_hex(p, "0123456789abcdef");
	return (c);
}
