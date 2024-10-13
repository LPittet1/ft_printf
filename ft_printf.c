/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:02:29 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/13 12:02:05 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(int c, va_list args)
{
	int	print_len;

	print_len = 0;
	if (c == '%')
		print_len += ft_putchar(c);
	if (c == 'c')
		print_len += ft_putchar(va_arg(args, int));
	if (c == 's')
		print_len += ft_putstr(va_arg(args, char *));
	//if (c == 'p')
	//	print_len += ft_putstr("0x") + ft_putnbr_u(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'd')
		print_len += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'i')
		print_len += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		print_len += ft_putnbr_u(va_arg(args, unsigned int));
	if (c == 'x')
		print_len += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		print_len += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_len += check_format(str[i], args);
			i++;
		}
		ft_putchar(str[i]);
		i++;
		print_len++;
	}
	return (print_len);
}

#include <stdio.h>

int main()
{
	int i = -214;
	char *s = "Hello World!";
	ft_printf("petit test : %x\n", i);
	printf("petit test : %x\n", i);
}