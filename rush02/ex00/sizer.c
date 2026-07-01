/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 00:46:51 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 20:14:02 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strings.h"

static int	count_bytes(const char *dictname)
{
	t_info	st;
	char	temp[4096];

	st.fd = open(dictname, O_RDONLY);
	st.total = 0;
	if (st.fd < 0)
	{
		ft_putstr("Dict Error\n");
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
		ft_putstr("Dict Error\n");
		return (-1);
	}
	return (st.total);
}

int	fill_buff(int fd, char *buf)
{
	t_info	st;

	st.total = 0;
	st.n = read(fd, buf + st.total, 4096);
	while (st.n > 0)
	{
		st.total += st.n;
		st.n = read(fd, buf + st.total, 4096);
	}
	if (st.n < 0)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	return (st.total);
}

int	dict_prep(const char *dictname, char **buf_ptr)
{
	t_info	st;

	st.total = count_bytes(dictname);
	if (st.total < 0)
		return (-1);
	*buf_ptr = malloc(st.total + 1);
	if (*buf_ptr == NULL)
		return (-1);
	st.fd = open(dictname, O_RDONLY);
	if (st.fd < 0)
	{
		free(*buf_ptr);
		return (-1);
	}
	st.total = fill_buff(st.fd, *buf_ptr);
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
