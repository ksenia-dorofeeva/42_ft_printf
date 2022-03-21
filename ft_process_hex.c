/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:40:32 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 22:56:28 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned long n)
{
	char	*s;

	s = "0123456789abcdef";
	if (n > 15)
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
	}
	else
		ft_putchar_p(s[n]);
}

int	ft_process_x(unsigned int n)
{
	int	len;

	len = 0;
	ft_hex(n);
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_process_ptr(unsigned long n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	ft_hex(n);
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_hex_upper(unsigned long n)
{
	char	*s;
	int		len;

	len = 0;
	s = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_hex_upper(n / 16);
		ft_hex_upper(n % 16);
	}
	else
		ft_putchar_p(s[n]);
}

int	ft_process_upper(unsigned int n)
{
	int	len;

	len = 0;
	ft_hex_upper(n);
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}
