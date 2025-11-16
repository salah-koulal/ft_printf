/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:55:43 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/16 10:58:29 by skoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	len;
	int	ld;

	len = 0;
	if (nb == -2147483648)
	{
		len = ft_putstr("-2147483648");
		return (len);
	}
	if (nb < 0)
	{
		len = ft_putstr("-");
		nb = -nb;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	ld = nb % 10 + 48;
	len += ft_putchar(ld);
	return (len);
}
