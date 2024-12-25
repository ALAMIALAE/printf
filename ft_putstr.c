/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:52:52 by aben-dri          #+#    #+#             */
/*   Updated: 2024/11/24 16:44:49 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (write(1, "(null)", 6));
	while (ptr[i])
	{
		ft_putchar(ptr[i]);
		i++;
	}
	return (i);
}
