/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:54:40 by brickard          #+#    #+#             */
/*   Updated: 2021/12/20 13:17:11 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_check_flag(int i);
int		ft_check_type(int i);
int		ft_parse_flags(const char *format, int i, t_flags *flags, va_list args);
int		ft_process_precision(const char *format, int start,
			t_flags *flags, va_list args);
int		ft_process_char(char c, t_flags *flags);
int		ft_put_width(t_flags *flags, int length);
int		ft_process_str(char *str, t_flags *flags);
int		ft_putstr_precision(char *str, int precision);
int		ft_process_type_b(int type, t_flags *flags, va_list args);
int		ft_process_uint(unsigned int i, t_flags *flags);
int		ft_process_int(int i, t_flags *flags);
int		ft_putchar_pf(char c, int l);
char	*ft_l_itoa(long n);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_putchar_p(char c);
int		ft_putstr(char *s);
t_flags	ft_init_flags(t_flags *flags);
t_flags	ft_process_minus(t_flags *flags);
t_flags	ft_process_width(va_list args, t_flags *flags);
t_flags	ft_process_width_digit(char c, t_flags *flags);

#endif
