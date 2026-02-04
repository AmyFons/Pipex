/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:59:04 by afons             #+#    #+#             */
/*   Updated: 2025/11/06 18:49:45 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 15)
	{
		count += ft_puthexa(nb / 16, base);
		count += ft_puthexa(nb % 16, base);
	}
	else
		count += ft_putchar(base[nb % 16]);
	return (count);
}
