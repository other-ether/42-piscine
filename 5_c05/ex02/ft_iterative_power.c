/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 23:14:46 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 15:19:03 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	while (power > 0)
	{
		result = result * nb;
		power --;
	}
	return (result);
}
