/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:45:51 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 15:14:05 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	almost_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb / i)
	{
		i ++;
	}
	return (i);
}

int	ft_is_prime(int nb)
{
	int	max;
	int	i;

	max = almost_sqrt(nb);
	i = 2;
	if (nb < 2)
		return (0);
	while (i < max)
	{
		if (nb % i == 0)
			return (0);
		else
		{
			i ++;
		}
	}
	return (1);
}
