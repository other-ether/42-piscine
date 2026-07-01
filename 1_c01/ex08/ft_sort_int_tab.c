/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:48:27 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/03 17:05:07 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	holder;

	holder = *a;
	*a = *b;
	*b = holder;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	*temptab;
	int	status;

	i = 0;
	status = 1;
	while (status != 2)
	{
		temptab = tab;
		status = 2;
		while (i < size - 1)
		{
			if (*temptab > *(temptab + 1))
			{
				ft_swap(temptab, temptab + 1);
				status = 1;
			}
			i++;
			temptab++;
		}
		i = 0;
	}
}
