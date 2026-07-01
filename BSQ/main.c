/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:55:08 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/17 00:32:59 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	answermap(t_win win, t_map m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			if (m.question[i * m.cols + j] > 1)
				m.question[i * m.cols + j] = 1;
			j++;
		}
		i++;
	}
	i = win.i - win.z + 1;
	while (i <= win.i)
	{
		j = win.j - win.z + 1;
		while (j <= win.j)
			m.question[i * m.cols + j++] = 2;
		i++;
	}
}

void	itob(t_map m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			if (m.question[i * m.cols + j] == 0)
				write(1, &(m.obst), 1);
			else if (m.question[i * m.cols + j] == 1)
				write(1, &(m.empty), 1);
			else
				write(1, &(m.full), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	stdinpath(void)
{
	t_map	m;

	m = readmap_stdin ();
	if (m.valid == 0 || m.question == NULL)
		ft_putstr("map error\n");
	else
	{
		answermap(calc(m.question, m.rows, m.cols), m);
		itob(m);
		free(m.question);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	m;

	i = 1;
	if (argc == 1)
		stdinpath ();
	else
	{
		while (argc > i)
		{
			if (i > 1)
				write(1, "\n", 1);
			m = readmap(argv[i]);
			if (m.valid == 0 || m.question == NULL)
				ft_putstr("map error\n");
			else
			{
				answermap(calc(m.question, m.rows, m.cols), m);
				itob(m);
				free(m.question);
			}
			i ++;
		}
	}
	return (0);
}
