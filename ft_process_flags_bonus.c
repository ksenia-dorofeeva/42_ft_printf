/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:02:14 by brickard          #+#    #+#             */
/*   Updated: 2021/12/20 00:08:31 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	ft_process_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (*flags);
}

t_flags	ft_process_width(va_list args, t_flags *flags)
{
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	return (*flags);
}

t_flags	ft_process_width_digit(char c, t_flags *flags)
{
	flags->width = (flags->width * 10) + (c - '0');
	return (*flags);
}

int	ft_process_precision(const char *format, int start,
	t_flags *flags, va_list args)
{
	int	i;

	i = start;
	if (format[i] == '*')
	{
		flags->precision = va_arg(args, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(format[i]))
		{
			flags->precision = flags->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_put_width(t_flags *flags, int length)
{
	int	len;

	len = 0;
	while (length > 0)
	{
		if (flags->zero)
			ft_putchar_pf('0', 1);
		else
			ft_putchar_pf(' ', 1);
		length--;
		len++;
	}
	return (len);
}
