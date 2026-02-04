/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:44:21 by afons             #+#    #+#             */
/*   Updated: 2025/11/06 18:55:01 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_puthexa(unsigned long nb, char *base);
int		ft_printpercent(void);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_putnbr(int nb);
int		ft_putptr(unsigned long ptr, char *base);

#endif