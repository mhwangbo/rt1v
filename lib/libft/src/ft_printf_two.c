/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:03:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/14 20:06:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_send_two(va_list args, t_numbers *n, const char *format)
{
	if (n->spec == 7)
		return (ft_non_print(args, format, n));
	else if (n->spec == 8)
		return (ft_floating_o(args, format, n));
	else if (n->spec == 9)
		return (ft_floating_hex(args, format, n));
	else if (n->spec == 10)
		return (ft_floating_e(args, format, n));
	else if (n->spec == 11)
		return (ft_n_save(args, format, n));
	else if (n->spec == 12)
		return (ft_floating_g(args, format, n));
	return (-1);
}

int		ft_printf_send(va_list args, t_numbers *n, const char *format)
{
	if (n->spec == 0)
		return (ft_character(args, format, n));
	else if (n->spec == 1)
		return (ft_string(args, format, n));
	else if (n->spec == 2)
		return (ft_decimal(args, format, n));
	else if (n->spec == 3)
		return (ft_unsigned(args, format, n));
	else if (n->spec == 4)
		return (ft_pointer(args, format, n));
	else if (n->spec == 5)
		return (ft_percent(args, format, n));
	else if (n->spec == 6)
	{
		n->fd = va_arg(args, int);
		return (1);
	}
	return (ft_printf_send_two(args, n, format));
}

int		ft_vsprintf_s_two(const char *format, int i)
{
	if (format[i] == 'r')
		return (7);
	else if (format[i] == 'f' || format[i] == 'F')
		return (8);
	else if (format[i] == 'a' || format[i] == 'A')
		return (9);
	else if (format[i] == 'e' || format[i] == 'E')
		return (10);
	else if (format[i] == 'n')
		return (11);
	else if (format[i] == 'g' || format[i] == 'G')
		return (12);
	return (-1);
}

int		ft_vsprintf_s(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'C')
		return (0);
	else if (format[i] == 's' || format[i] == 'S')
		return (1);
	else if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
		return (2);
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'b')
		return (3);
	else if (format[i] == 'p')
		return (4);
	else if (format[i] == '%')
		return (5);
	else if (format[i] == 'w')
		return (6);
	return (ft_vsprintf_s_two(format, i));
}
