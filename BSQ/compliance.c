/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compliance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:25:58 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/17 17:01:42 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	checkchars(t_map m)
{
	if (!(m.empty >= ' ' && m.empty <= '~'))
		return (0);
	if (!(m.obst >= ' ' && m.obst <= '~'))
		return (0);
	if (!(m.full >= ' ' && m.full <= '~'))
		return (0);
	if (m.empty == m.obst || m.empty == m.full || m.full == m.obst)
		return (0);
	return (1);
}

int	check_row_end(char **buff, int rows_left)
{
	if (rows_left > 0)
	{
		if (**buff != '\n')
			return (0);
		(*buff)++;
	}
	else
	{
		if (**buff == '\n')
			(*buff)++;
		if (**buff != '\0')
			return (0);
	}
	return (1);
}

int	checkmap(char *buff, t_map m)
{
	int	col_count;
	int	rows_left;

	rows_left = m.rows;
	buff = buff + m.i + 1;
	if (!checkchars(m))
		return (0);
	while (rows_left > 0)
	{
		col_count = m.cols;
		while (col_count--)
		{
			if (*buff != m.empty && *buff != m.obst)
				return (0);
			buff++;
		}
		if (!check_row_end(&buff, rows_left - 1))
			return (0);
		rows_left--;
	}
	return (1);
}
