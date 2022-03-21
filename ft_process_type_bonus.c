/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_type_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:28:07 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 23:51:51 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_process_char(char c, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar_pf(c, 1);
		len += ft_put_width(flags, (flags->width - 1));
	}
	if (flags->minus == 0)
	{
		len += ft_put_width(flags, (flags->width - 1));
		len += ft_putchar_pf(c, 1);
	}
	return (len);
}

int	ft_process_percent(t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar_pf('%', 1);
		len += ft_put_width(flags, (flags->width - 1));
		len++;
	}
	if (flags->minus == 0)
	{
		len += ft_put_width(flags, (flags->width - 1));
		len += ft_putchar_pf('%', 1);
	}
	return (len);
}

int	ft_process_type_b(int type, t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_process_char(va_arg(args, int), flags);
	if (type == 's')
		len += ft_process_str(va_arg(args, char *), flags);
	if (type == 'd' || type == 'i')
		len += ft_process_int(va_arg(args, int), flags);
	if (type == 'u')
		len += ft_process_uint(va_arg(args, unsigned int), flags);
	if (type == '%')
		len += ft_process_percent(flags);
	return (len);
}
