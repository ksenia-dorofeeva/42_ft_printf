/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:00:23 by brickard          #+#    #+#             */
/*   Updated: 2021/12/20 00:08:58 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	ft_init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	return (*flags);
}

int	ft_check_flag(int i)
{
	if (i == '0' || i == '.' || i == '-' || i == '*' || i == ' ')
		return (1);
	return (0);
}

int	ft_check_type(int i)
{
	if (i == 'c' || i == 's' || i == 'p' || i == 'd'
		|| i == 'i' || i == 'u' || i == 'x' || i == 'X' || i == '%')
		return (i);
	return (0);
}

int	ft_parse_flags(const char *format, int i, t_flags *flags, va_list args)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !ft_check_type(format[i])
			&& !ft_check_flag(format[i]))
			break ;
		if (format[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (format[i] == '-')
			ft_process_minus(flags);
		if (format[i] == '*')
			ft_process_width(args, flags);
		if (ft_isdigit(format[i]))
			ft_process_width_digit(format[i], flags);
		if (format[i] == '.')
			i = ft_process_precision(format, ++i, flags, args);
		if (ft_check_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}
