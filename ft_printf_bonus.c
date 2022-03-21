/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:02:13 by brickard          #+#    #+#             */
/*   Updated: 2021/12/18 22:57:27 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_format(const char *format, va_list args)
{
	int		len;
	int		i;
	t_flags	flags;

	len = 0;
	i = 0;
	while (format[i])
	{
		flags = ft_init_flags(&flags);
		if (format[i] == '%')
		{
			i = ft_parse_flags(format, ++i, &flags, args);
			if (ft_check_type(format[i]))
				len += ft_process_type_b(format[i], &flags, args);
			else
				len += ft_putchar_pf(format[i], 1);
		}
		else
			len += ft_putchar_pf(format[i], 1);
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
