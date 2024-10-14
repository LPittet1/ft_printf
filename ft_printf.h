/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:59:39 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/14 16:58:57 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//printf.c
int	ft_printf(const char *str, ...);
int	check_format(int c, va_list args);

//print_alpha.c
int	ft_putchar(int c);
int	ft_putstr(char *str);

//print_digit.c
int	ft_putnbr(long int n, char *base);

//print_unsigned.c
int	ft_putnbr_p(unsigned long int n, char *base);
int	ft_putnbr_u(unsigned int n, char *base);

#endif