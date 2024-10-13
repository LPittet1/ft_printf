/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:52:15 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/13 12:53:15 by lpittet          ###   ########.fr       */
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

int	ft_putnbr_u(unsigned long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = ft_baselen(base);
	if (n > base_len)
	{
		ft_putnbr_u(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else if (n < base_len)
		ft_putchar(base[n % base_len]);
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
