/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:31:51 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/18 13:04:22 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose(const char *s, va_list args, int index)
{
	int	counter;

	counter = 0;
	if (s[index] == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (s[index] == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (s[index] == 'd' || s[index] == 'i')
		counter = ft_putnbr(va_arg(args, int));
	else if (s[index] == '%')
		counter = ft_putchar('%');
	else if (s[index] == 'u')
		counter = ft_putunsigned(va_arg(args, unsigned int));
	else if (s[index] == 'X')
		counter = ft_dectohex_c(va_arg(args, unsigned int));
	else if (s[index] == 'x')
		counter = ft_dectohex_s(va_arg(args, unsigned int));
	else if (s[index] == 'p')
		counter = ft_print_ptr(va_arg(args, unsigned long long));
	return (counter);
}
