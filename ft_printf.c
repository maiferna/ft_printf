/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:45:59 by maiferna          #+#    #+#             */
/*   Updated: 2024/10/02 09:46:45 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_handler(char character, va_list args)
{
	int	count;

	count = 0;
	if (character == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (character == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (character == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (character == 'd' || character == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (character == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (character == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
	else if (character == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
	else if (character == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += format_handler(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
