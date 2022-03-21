/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uint_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:57:23 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 20:38:41 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_put_flags_u1(char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	if (flags->width <= len_str && flags->precision <= len_str)
		len += ft_putstr_precision(str, len_str);
	if (flags->precision >= flags->width && flags->precision > len_str)
	{
		flags->width = flags->precision;
		flags->zero = 1;
		len += ft_put_width(flags, (flags->width - len_str));
		len += ft_putstr_precision(str, len_str);
	}
	return (len);
}

static int	ft_put_flags_u2(char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	if (flags->precision != -1)
		flags->zero = 0;
	if (flags->minus == 0)
	{	
		len += ft_put_width(flags, (flags->width - len_str));
		len += ft_putstr_precision(str, len_str);
	}
	else
	{
		len += ft_putstr_precision(str, len_str);
		len += ft_put_width(flags, (flags->width - len_str));
	}
	return (len);
}

static int	ft_put_flags_u3(char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	flags->zero = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar_pf('0', flags->precision - len_str);
		len += ft_putstr_precision(str, len_str);
		len += ft_put_width(flags, (flags->width - flags->precision));
	}
	if (flags->minus == 0)
	{
		len += ft_put_width(flags, (flags->width - flags->precision));
		len += ft_putchar_pf('0', flags->precision - len_str);
		len += ft_putstr_precision(str, len_str);
	}
	return (len);
}

static int	ft_put_flags_uint(char *str, t_flags *flags)
{
	int	len;
	int	len_str;

	len = 0;
	len_str = ft_strlen(str);
	if (flags->width <= len_str && flags->precision <= len_str)
		len += ft_put_flags_u1(str, flags, len_str);
	if (flags->precision >= flags->width && flags->precision > len_str)
		len += ft_put_flags_u1(str, flags, len_str);
	if (flags->width > len_str && flags->precision <= len_str)
		len += ft_put_flags_u2(str, flags, len_str);
	if (flags->precision < flags->width && flags->precision > len_str)
		len += ft_put_flags_u3(str, flags, len_str);
	return (len);
}

int	ft_process_uint(unsigned int i, t_flags *flags)
{
	char	*str;
	int		len;

	len = 0;
	if (flags->precision == 0 && i == 0)
	{
		flags->zero = 0;
		len += ft_put_width(flags, flags->width);
		return (len);
	}
	str = ft_l_itoa(i);
	len += ft_put_flags_uint(str, flags);
	free(str);
	return (len);
}
