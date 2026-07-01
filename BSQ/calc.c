/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuchana <abuchana@42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:32:12 by abuchana          #+#    #+#             */
/*   Updated: 2026/06/15 20:32:15 by abuchana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

void	dynamic(int *map, const int rows, const int cols)
{
	int	i;
	int	j;

	i = 1;
	while (i < rows)
	{
		j = 1;
		while (j < cols)
		{
			if (map[i * cols + j] != 0)
				map[i * cols + j] = 1 + min(map[(i - 1) * cols + j],
						map[i * cols + j - 1], map[(i - 1) * cols + j - 1]);
			j++;
		}
		i++;
	}
}

t_win	find_best(int *map, const int rows, const int cols)
{
	t_win	win;
	int		i;
	int		j;

	win.i = 0;
	win.j = 0;
	win.z = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (win.z < map[i * cols + j])
			{
				win.i = i;
				win.j = j;
				win.z = map[i * cols + j];
			}
			j++;
		}
		i++;
	}
	return (win);
}

t_win	calc(int *map, const int rows, const int cols)
{
	t_win	win;

	dynamic(map, rows, cols);
	win = find_best(map, rows, cols);
	return (win);
}
