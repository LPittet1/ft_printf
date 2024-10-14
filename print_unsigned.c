/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:28 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/14 13:47:37 by lpittet          ###   ########.fr       */
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

int	ft_putnbr_p(unsigned long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	base_len = ft_baselen(base);
	len = print_len_p(n, base_len);
	if (n >= base_len)
	{
		ft_putnbr_p(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else if (n < base_len)
		ft_putchar(base[n % base_len]);
	return (len);
}

int ft_putnbr_u(unsigned int n, char *base)
{
	int 			len;
	unsigned int	base_len;

	base_len = ft_baselen(base);
	len = print_len_u(n, base_len);
	if (n >= base_len)
	{
		ft_putnbr_u(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else if (n < base_len)
		ft_putchar(base[n % base_len]);
	return (len);
}