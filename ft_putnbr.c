/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:52:23 by aben-dri          #+#    #+#             */
/*   Updated: 2024/11/24 16:44:22 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	number;

	number = 0;
	if (n == INT_MIN)
	{
		number += write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		number += write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		return (write(1, "0", 1));
	if (n > 9)
		number += ft_putnbr(n / 10);
	number += ft_putchar(n % 10 + '0');
	return (number);
}
