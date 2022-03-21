/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:37:15 by brickard          #+#    #+#             */
/*   Updated: 2021/12/20 13:15:52 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_put_flags_1(int i, char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	if (flags->width <= len_str && flags->precision <= len_str)
	{
		if (i < 0)
			len += ft_putchar_pf('-', 1);
		len += ft_putstr_precision(str, len_str);
	}
	if (flags->precision >= flags->width && flags->precision > len_str)
	{
		flags->width = flags->precision;
		flags->zero = 1;
		if (i < 0)
			len += ft_putchar_pf('-', 1);
		len += ft_put_width(flags, (flags->width - len_str));
		len += ft_putstr_precision(str, len_str);
	}
	return (len);
}

static int	ft_put_flags_2(int i, char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	if (flags->precision != -1)
		flags->zero = 0;
	if (flags->minus == 1)
	{
		if (i < 0)
			len += ft_putchar_pf('-', 1);
		len += ft_putstr_precision(str, len_str);
		len += ft_put_width(flags, (flags->width - len_str));
	}
	else
	{
		if (i < 0 && flags->zero == 1)
			len += ft_putchar_pf('-', 1);
		len += ft_put_width(flags, (flags->width - len_str));
		if (i < 0 && flags->zero == 0)
			len += ft_putchar_pf('-', 1);
		len += ft_putstr_precision(str, len_str);
	}
	return (len);
}

static int	ft_put_flags_3(int i, char *str, t_flags *flags, int len_str)
{
	int	len;

	len = 0;
	flags->zero = 0;
	if (flags->minus == 1)
	{
		if (i < 0)
			len += ft_putchar_pf('-', 1);
		len += ft_putchar_pf('0', flags->precision - len_str);
		len += ft_putstr_precision(str, len_str);
		len += ft_put_width(flags, (flags->width - flags->precision));
	}
	if (flags->minus == 0)
	{
		len += ft_put_width(flags, (flags->width - flags->precision));
		if (i < 0)
			len += ft_putchar_pf('-', 1);
		len += ft_putchar_pf('0', flags->precision - len_str);
		len += ft_putstr_precision(str, len_str);
	}
	return (len);
}

static int	ft_put_flags(int i, char *str, t_flags *flags)
{
	int	len;
	int	len_str;

	len = 0;
	len_str = ft_strlen(str);
	if (flags->precision == 0 && i == 0)
	{
		flags->zero = 0;
		len += ft_put_width(flags, flags->width);
		return (len);
	}
	if (flags->width <= len_str && flags->precision <= len_str)
		len += ft_put_flags_1(i, str, flags, len_str);
	if (flags->precision >= flags->width && flags->precision > len_str)
		len += ft_put_flags_1(i, str, flags, len_str);
	if (flags->width > len_str && flags->precision <= len_str)
		len += ft_put_flags_2(i, str, flags, len_str);
	if (flags->precision < flags->width && flags->precision > len_str)
		len += ft_put_flags_3(i, str, flags, len_str);
	return (len);
}

int	ft_process_int(int i, t_flags *flags)
{
	char	*str;
	int		len;
	long	n;

	n = i;
	len = 0;
	if (i < 0)
	{	
		n = -n;
		flags->width--;
	}
	str = ft_l_itoa(n);
	len += ft_put_flags(i, str, flags);
	free(str);
	return (len);
}
