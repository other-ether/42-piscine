/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _1Dbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:28:57 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/17 15:16:26 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static int	count_bytes(const char *mapname, int *valid)
{
	t_info	st;
	char	temp[4096];

	st.fd = open(mapname, O_RDONLY);
	st.total = 0;
	if (st.fd < 0)
	{
		*valid = 0;
		return (-1);
	}
	st.n = read(st.fd, temp, 4096);
	while (st.n > 0)
	{
		st.total += st.n;
		st.n = read(st.fd, temp, 4096);
	}
	close(st.fd);
	if (st.n < 0)
	{
		*valid = 0;
		return (-1);
	}
	return (st.total);
}

int	fill_buff(int fd, char *buff, int size)
{
	t_info	st;

	st.total = 0;
	st.n = 1;
	while (st.n > 0 && st.total < size)
	{
		st.n = read(fd, buff + st.total, size - st.total);
		if (st.n < 0)
			return (-1);
		st.total += st.n;
	}
	return (st.total);
}

int	map_prep(const char *mapname, char **buf_ptr, int *valid)
{
	t_info	st;

	st.total = count_bytes(mapname, valid);
	if (st.total < 0)
		return (-1);
	*buf_ptr = malloc(st.total + 1);
	if (*buf_ptr == NULL)
		return (-1);
	st.fd = open(mapname, O_RDONLY);
	if (st.fd < 0)
	{
		free(*buf_ptr);
		return (-1);
	}
	st.total = fill_buff(st.fd, *buf_ptr, st.total);
	close(st.fd);
	if (st.total < 0)
	{
		free(*buf_ptr);
		*buf_ptr = NULL;
		return (-1);
	}
	(*buf_ptr)[st.total] = '\0';
	return (st.total);
}
