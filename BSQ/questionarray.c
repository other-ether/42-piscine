/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questionarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 23:16:48 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 21:31:20 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	mapsize(t_map m)
{
	int	area;

	area = m.rows * m.cols;
	return (area);
}

int	*questionmap(char *buff, t_map m, int area)
{
	int	*question;
	int	k;

	question = malloc(area * sizeof(int));
	if (question == NULL)
		return (NULL);
	k = 0;
	buff = buff + m.i + 1;
	while (k < area)
	{
		if (*buff == m.empty)
			question[k++] = 1;
		else if (*buff == m.obst)
			question[k++] = 0;
		buff++;
	}
	return (question);
}
