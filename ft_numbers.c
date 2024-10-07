/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:54:08 by maiferna          #+#    #+#             */
/*   Updated: 2024/10/03 09:54:19 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	int		count;
	char	*digit;

	count = 0;
	if (format == 'x')
		digit = "0123456789abcdef";
	else if (format == 'X')
		digit = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0');
		return(1);
	}
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, format);
	count += ft_putchar(digit[n % 16]);
	return (count);
}

static int	ft_ptr_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_ptr_hex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += ft_ptr_hex(ptr);
	return (count);
}
