/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:00:54 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/03 17:05:14 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	holder;
	int	*back;
	int	halfway;
	int	i;

	i = 0;
	back = &tab[size -1];
	halfway = size / 2;
	while (i < halfway)
	{
		holder = *tab;
		*tab = *back;
		*back = holder;
		tab++;
		back--;
		i++;
	}
}
