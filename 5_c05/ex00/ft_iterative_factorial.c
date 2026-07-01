/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 22:33:25 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 15:18:26 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	mult;

	i = 1;
	mult = nb;
	if (nb == 0)
	{
		return (1);
	}
	while (i < mult)
	{
		nb = nb * (mult - i);
		i ++;
	}
	return (nb);
}
