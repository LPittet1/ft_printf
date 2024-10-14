/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:52:15 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/14 17:34:17 by lpittet          ###   ########.fr       */
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

int	ft_putnbr(long int n, char *base)
{
	int	len;

	len = print_len(n, 10);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, base);
		ft_putchar(base[n % 10]);
	}
	else if (n < 10)
		ft_putchar(base[n % 10]);
	return (len);
}
