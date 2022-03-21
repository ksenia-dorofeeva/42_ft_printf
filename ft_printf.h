/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:35:32 by brickard          #+#    #+#             */
/*   Updated: 2021/12/19 20:35:29 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list args);
int		ft_process_type(int type, va_list args);
int		ft_putchar_p(char c);
int		ft_check_type(int i);
int		ft_isdigit(int c);
int		ft_putstr(char *s);
int		ft_strlen(const char *str);
int		ft_putnbr(long long int n);
int		ft_process_x(unsigned int n);
int		ft_process_upper(unsigned int n);
int		ft_process_ptr(unsigned long n);

#endif
