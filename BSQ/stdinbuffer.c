/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinbuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:17:38 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 22:19:16 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static int	free_chunk_list(t_map_chunk *list_head)
{
	t_map_chunk	*temporary_node;

	while (list_head != NULL)
	{
		temporary_node = list_head->next;
		free(list_head);
		list_head = temporary_node;
	}
	return (-1);
}

static void	append_chunk_node(t_map_chunk **list_head, t_map_chunk **current,
				t_map_chunk *new_node)
{
	if (*list_head == NULL)
	{
		*list_head = new_node;
		*current = new_node;
	}
	else
	{
		(*current)->next = new_node;
		*current = new_node;
	}
}

static int	read_stdin_stream(t_map_chunk **list_head)
{
	t_map_chunk	*current;
	t_map_chunk	*new;
	t_info		st;

	st.total = 0;
	current = NULL;
	while (1)
	{
		new = malloc(sizeof(t_map_chunk));
		if (!new)
			return (free_chunk_list(*list_head));
		new->next = NULL;
		st.n = read(0, new->chunk, 4096);
		if (st.n <= 0)
		{
			free(new);
			break ;
		}
		new->bytes = st.n;
		st.total += st.n;
		append_chunk_node(list_head, &current, new);
	}
	if (st.n < 0)
		return (free_chunk_list(*list_head));
	return (st.total);
}

int	map_prep_stdin(char **buf_ptr)
{
	t_map_chunk	*list_head;
	t_map_chunk	*tmp;
	t_info		st;
	int			dest_idx;
	int			chunk_i;

	list_head = NULL;
	st.total = read_stdin_stream(&list_head);
	if (st.total < 0)
		return (-1);
	*buf_ptr = malloc(st.total + 1);
	if (!*buf_ptr)
		return (free_chunk_list(list_head));
	dest_idx = 0;
	while (list_head)
	{
		chunk_i = 0;
		while (chunk_i < list_head->bytes)
			(*buf_ptr)[dest_idx++] = list_head->chunk[chunk_i++];
		tmp = list_head->next;
		free(list_head);
		list_head = tmp;
	}
	(*buf_ptr)[st.total] = '\0';
	return (st.total);
}

t_map	readmap_stdin(void)
{
	t_info	st;
	t_map	m;

	m.buff = NULL;
	m.valid = 1;
	st.total = map_prep_stdin(&(m.buff));
	if (st.total < 0 || m.buff == NULL)
		m.valid = 0;
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
