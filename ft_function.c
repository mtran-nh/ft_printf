/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:20:00 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/07/21 17:33:00 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s)
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		ret;
	int		sum;

	ret = 0;
	sum = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		ret += 1;
	}
	if (nb >= 10)
		sum = ft_putnbr(nb / 10);
	if (ft_putchar(nb % 10 + '0'))
		ret += 1;
	if (!ret)
		return (-1);
	sum += ret;
	return (sum);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	ret;
	int	sum;

	ret = 0;
	sum = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		sum += ret;
	}
	if (ft_putchar(n % 10 + '0'))
		ret += 1;
	if (!ret)
		return (-1);
	sum += ret;
	return (sum);
}

static int	ft_puthex(unsigned long n)
{
	int		ret;
	int		sum;
	char	*hex;

	ret = 0;
	sum = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ret = (ft_puthex(n / 16));
		if (ret == -1)
			return (-1);
		sum += ret;
	}
	ret = (ft_putchar(hex[n % 16]));
	if (!ret)
		return (-1);
	sum += ret;
	return (sum);
}
