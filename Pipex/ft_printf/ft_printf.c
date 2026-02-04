/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:35:47 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 23:30:22 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'x')
		count += ft_puthexa(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_puthexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'p')
		count += ft_putptr(va_arg(arg, unsigned long), "0123456789abcdef");
	else if (c == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	argument;

	if (!str)
		return (-1);
	va_start (argument, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_is_type(argument, str[i]);
		}
		else
		{
			write(2, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(argument);
	return (count);
}
