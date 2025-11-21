/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulal <skoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:43:04 by skoulal           #+#    #+#             */
/*   Updated: 2025/11/20 21:17:27 by skoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_format(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (format == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		len = ft_put_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len = ft_putchar('%');
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		len = ft_put_address(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_find_format(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
