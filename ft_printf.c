/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:39:40 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 22:09:04 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_type(int type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar_p(va_arg(args, int));
	if (type == 's')
		len += ft_putstr(va_arg(args, char *));
	if (type == 'p')
		len += ft_process_ptr(va_arg(args, unsigned long));
	if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (type == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	if (type == 'x')
		len += ft_process_x(va_arg(args, unsigned int));
	if (type == 'X')
		len += ft_process_upper(va_arg(args, unsigned int));
	if (type == '%')
		len += ft_putchar_p('%');
	return (len);
}

int	ft_check_type(int i)
{
	if (i == 'c' || i == 's' || i == 'p' || i == 'd'
		|| i == 'i' || i == 'u' || i == 'x' || i == 'X' || i == '%')
		return (i);
	return (0);
}

int	ft_parse_format(const char *format, va_list args)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_check_type(format[++i]))
				len += ft_process_type(format[i], args);
			else
				len += ft_putchar_p(format[i]);
		}
		else
			len += ft_putchar_p(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	len += ft_parse_format(format, args);
	va_end(args);
	return (len);
}
