/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:26:36 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/18 18:19:16 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	breadth;
	int	i;

	breadth = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(breadth * sizeof(int));
	if (arr == NULL)
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		i ++;
		min ++;
	}
	*range = arr;
	return (breadth);
}
