/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:28 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/16 12:53:47 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

static int	print_len_p(unsigned long n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

static int	print_len_u(long n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

int	ft_putnbr_p(unsigned long n, char *base, int prefix)
{
	int		len;
	int		var;

	if (prefix == 0)
	{
		var = ft_putstr("0x");
		prefix = 1;
		if (var == -1)
			return (-1);
	}	
	len = print_len_p(n, 16) + 2;
	if (n >= 16)
	{
		ft_putnbr_p(n / 16, base, prefix);
		var = ft_putchar(base[n % 16]);
		if (var == -1)
			return (-1);
	}
	else if (n < 16)
	{
		var = ft_putchar(base[n % 16]);
		if (var == -1)
			return (-1);
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n, char *base)
{
	int				len;
	unsigned int	base_len;
	int				var;

	base_len = ft_baselen(base);
	len = print_len_u(n, base_len);
	if (n >= base_len)
	{
		var = ft_putnbr_u(n / base_len, base);
		if (var == -1)
			return (-1);
		var = ft_putchar(base[n % base_len]);
		if (var == -1)
			return (-1);
	}
	else if (n < base_len)
	{
		var = ft_putchar(base[n % base_len]);
		if (var == -1)
			return (-1);
	}
	return (len);
}
