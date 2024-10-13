/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:52:15 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/13 11:47:36 by lpittet          ###   ########.fr       */
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

static int	print_len(long int n, int base_len)
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

int	ft_putnbr_u(unsigned int n)
{
	int				temp;
	int				len;
	unsigned int	t;

	temp = 0;
	len = 0;
	t = n;
	while (t != 0)
	{
		t /= 10;
		len++;
	}
	if (n == 0)
		len = 1;
	if (n > 10)
	{
		temp = n % 10;
		ft_putnbr_u(n / 10);
		ft_putchar(temp + 48);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	return (len);
}

int	ft_putnbr_base(long int n, char *base)
{
	int			len;
	int			base_len;

	len = 0;
	base_len = ft_baselen(base);
	len = print_len(n, base_len);
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-n, base);
		len++;
	}
	else if (n > base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else if (n < base_len)
		ft_putchar(base[n % base_len]);
	return (len);
}
