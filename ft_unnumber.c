/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:53:37 by aben-dri          #+#    #+#             */
/*   Updated: 2024/11/24 16:45:16 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unnumber(unsigned int n)
{
	int	number;

	number = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n > 9)
		number += ft_unnumber(n / 10);
	number += ft_putchar(n % 10 + '0');
	return (number);
}
