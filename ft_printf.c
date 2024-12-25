/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:31:46 by aben-dri          #+#    #+#             */
/*   Updated: 2024/11/25 11:13:12 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cheacker_fun(va_list arg, int c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'u')
		return (ft_unnumber(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_put_hexa(va_arg(arg, unsigned int), c));
	else if (c == 'p')
		return (ft_ptr(va_arg(arg, void *)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;
	int		a;

	cnt = 0;
	a = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			a = cheacker_fun(args, *format);
			if (a == -1)
				return (-1);
			cnt += a;
		}
		else
			cnt += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (cnt);
}
