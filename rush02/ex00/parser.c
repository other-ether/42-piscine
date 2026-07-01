/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 19:28:57 by kitang            #+#    #+#             */
/*   Updated: 2026/06/14 23:30:17 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strings.h"
#include "sizer.h"
#include "split.h"
#include "numterm.h"

char	*skip_zero(char *nbr);

void	twodigs(char *buf, char *input)
{
	t_info	s;
	char	leftdig[3];

	s.nlen = ft_strlen(input);
	if (s.nlen == 1 || (s.nlen == 2 && (input[0] == '1' || input[1] == '0')))
		printvalue(buf, input);
	else
	{
		leftdig[0] = input[0];
		leftdig[1] = '0';
		printvalue(buf, leftdig);
		write(1, " ", 1);
		printvalue(buf, &(input[1]));
	}
}

void	threedigs(char *buf, char *input)
{
	char	digit[2];

	digit[0] = input[0];
	digit[1] = '\0';
	if (ft_strcmp(input, "100") == 0)
		printvalue(buf, "100");
	else
	{
		printvalue(buf, digit);
		write(1, " ", 1);
		printvalue(buf, "100");
	}
}

void	subparser(char *input, char *buf, int *size)
{
	t_info	s;

	s.nlen = ft_strlen(input);
	if (s.nlen == 3)
	{
		threedigs(buf, input);
		input ++;
		write(1, " ", 1);
		input = skip_zero(input);
		twodigs(buf, input);
	}
	else
		twodigs(buf, input);
	if (*size > 1)
		write(1, " ", 1);
}

void	parser(char *input, char *dictname)
{
	char	*buf;
	t_info	s;
	char	**segm;

	buf = NULL;
	s.size = 0;
	s.i = 0;
	s.nlen = ft_strlen(input);
	s.total = dict_prep(dictname, &buf);
	if (s.total < 0)
		return ;
	segm = split_threes(input, &s.size);
	while (s.size >= 1)
	{
		subparser(segm[s.i], buf, &s.size);
		numterm(buf, &s.size);
		s.i ++;
		s.size --;
	}
}
