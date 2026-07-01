/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:59:51 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 23:24:47 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	breadth;
	int	i;

	breadth = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	arr = malloc(breadth * sizeof(int));
	if (arr == NULL)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i ++;
		min ++;
	}
	return (arr);
}
