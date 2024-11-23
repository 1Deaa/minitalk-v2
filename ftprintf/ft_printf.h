/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:12:21 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/16 15:41:40 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_choose(const char *s, va_list args, int index);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_dectohex_c(unsigned int num);
int	ft_dectohex_s(unsigned int num);
int	ft_print_ptr(unsigned long long int num);

#endif
