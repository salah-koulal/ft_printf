/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:23:49 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/16 11:18:30 by skoulal          ###   ########.fr       */
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

int	ft_put_addr(void *p)
{
	int				c;
	unsigned long	address;

	c = 0;
	address = (unsigned long)p;
	if (p == NULL)
		return (ft_putstr("0x0"));
	c = ft_putstr("0x");
	c += into_hex(address, "0123456789abcdef");
	return (c);
}
