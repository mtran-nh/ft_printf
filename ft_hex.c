/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:52:21 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/07/22 19:48:10 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (ret == -1)
		return (-1);
	sum += ret;
	return (sum);
}

int	ft_putptr(void *p)
{
	int	ret;
	int	hex;

	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	hex = ft_puthex((unsigned long)p);
	if (hex == -1)
		return (-1);
	return (ret + hex);
}

int	ft_puthex_lower(unsigned int n)
{
	int		ret;
	int		sum;
	char	*hex;

	ret = 0;
	sum = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ret = (ft_puthex_lower(n / 16));
		if (ret == -1)
			return (-1);
		sum += ret;
	}
	ret = ft_putchar(hex[n % 16]);
	if (ret == -1)
		return (-1);
	sum += ret;
	return (sum);
}

int	ft_puthex_upper(unsigned int n)
{
	int		ret;
	int		sum;
	char	*hex;

	ret = 0;
	sum = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = (ft_puthex_upper(n / 16));
		if (ret == -1)
			return (-1);
		sum += ret;
	}
	ret = ft_putchar(hex[n % 16]);
	if (ret == -1)
		return (-1);
	sum += ret;
	return (sum);
}

// int main ()
// {
// 	char *p = "20";
// 	ft_putptr(p);
// 	printf("\n");
// 	printf("%d\n", ft_putptr(p));
// }