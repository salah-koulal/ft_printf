/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:12:37 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/16 11:18:08 by skoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int nb)
{
	int	len;
	int	ld;

	len = 0;
	if (nb > 9)
		len = ft_put_unsigned(nb / 10);
	ld = nb % 10 + 48;
	len += ft_putchar(ld);
	return (len);
}
