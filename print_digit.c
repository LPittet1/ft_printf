/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:52:15 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/16 14:20:10 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len(long int n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

static int	neg_check(long *n)
{
	int	var;

	var = ft_putchar('-');
	*n *= -1;
	return (var);
}

int	ft_putnbr(long n, char *base)
{
	int	len;
	int	var;

	len = print_len(n, 10);
	if (n < 0)
	{
		if (neg_check(&n) == -1)
			return (-1);
	}
	if (n >= 10)
	{
		var = ft_putnbr(n / 10, base);
		if (var == -1)
			return (-1);
		var = ft_putchar(base[n % 10]);
		if (var == -1)
			return (-1);
	}
	else if (n < 10)
	{
		var = ft_putchar(base[n % 10]);
		if (var == -1)
			return (-1);
	}
	return (len);
}
