/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:49:13 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 23:39:18 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr_precision(char *str, int precision)
{
	int	len;

	len = 0;
	while (str[len] && len < precision)
		ft_putchar_p(str[len++]);
	return (len);
}

static int	ft_process_str_minus(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->precision >= 0)
		len += ft_putstr_precision(str, flags->precision);
	else
		len += ft_putstr(str);
	if (flags->width > 0 && flags->precision > 0)
		len += ft_put_width(flags, (flags->width - flags->precision));
	else if (flags->width > 0)
		len += ft_put_width(flags, (flags->width - ft_strlen(str)));
	return (len);
}

int	ft_process_str(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags->precision >= 0 && flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->minus == 1)
		len += ft_process_str_minus(str, flags);
	if (flags->minus == 0)
	{
		if (flags->width > 0)
			len += ft_put_width(flags, (flags->width - ft_strlen(str)));
		if (flags->precision >= 0)
			len += ft_putstr_precision(str, flags->precision);
		else
			len += ft_putstr(str);
	}
	return (len);
}
