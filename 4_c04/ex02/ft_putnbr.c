/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:39:26 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 15:59:42 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	non_poz(int neg)
{
	if (neg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (neg == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (neg < 0)
	{
		neg = neg *(-1);
		write(1, "-", 1);
		return (neg);
	}
	return (neg);
}

void	ft_output(int singledig)
{
	char	output;

	output = 48 + singledig;
	write(1, &output, 1);
}

void	ft_putnbr(int nb)
{
	int		neg_result;
	int		size;
	char	reversed[11];

	neg_result = non_poz(nb);
	if (neg_result == 0)
		return ;
	else
		nb = neg_result;
	size = 1;
	while (nb > 0)
	{
		reversed[size] = nb % 10;
		nb = nb / 10;
		size ++;
	}
	while (size > 1)
	{
		size --;
		ft_output(reversed[size]);
	}
	return ;
}
