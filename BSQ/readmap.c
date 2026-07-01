/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:25:58 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/17 15:12:24 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	has_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	firstline(char *buff, t_map *m)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (has_newline(buff) == 0)
		return (0);
	while (buff[i] && buff[i] != '\n')
		i ++;
	if (i < 4)
		return (0);
	while (j < i - 3)
	{
		if (buff[j] >= '0' && buff[j] <= '9')
			j ++;
		else
			return (0);
	}
	m->rows = ft_atoi_n(buff, j);
	if (m->rows == 0)
		return (0);
	m->i = i;
	return (1);
}

int	findcols(char *buff, t_map *m)
{
	int	j;

	j = 0;
	buff = buff + m->i + 1;
	while (*buff != '\n' && *buff != '\0')
	{
		buff ++;
		j ++;
	}
	if (j == 0)
		return (0);
	m->cols = j;
	return (j);
}

t_map	readmap(char *mapname)
{
	t_info	st;
	t_map	m;

	m.buff = NULL;
	m.valid = 1;
	st.total = map_prep(mapname, &(m.buff), &(m.valid));
	if (st.total < 0 || m.buff == NULL)
	{
		m.valid = 0;
		return (m);
	}
	if (firstline(m.buff, &m) == 0 || findcols(m.buff, &m) == 0)
		m.valid = 0;
	if (m.valid)
	{
		m.empty = m.buff[m.i - 3];
		m.obst = m.buff[m.i - 2];
		m.full = m.buff[m.i - 1];
		if (checkmap(m.buff, m) == 0)
			m.valid = 0;
	}
	if (m.valid)
		m.question = questionmap(m.buff, m, mapsize(m));
	free(m.buff);
	return (m);
}
