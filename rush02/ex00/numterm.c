/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:23:14 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 23:36:42 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printvalue.h"

void	numterm3(char *buf, int *size)
{
	if (*size == 13)
	{
		printvalue(buf, "1000000000000000000000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 12)
	{
		printvalue(buf, "1000000000000000000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 11)
	{
		printvalue(buf, "1000000000000000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 10)
	{
		printvalue(buf, "1000000000000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 9)
	{
		printvalue(buf, "1000000000000000000000000");
		write(1, " ", 1);
	}
}

void	numterm2(char *buf, int *size)
{
	if (*size == 8)
	{
		printvalue(buf, "1000000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 7)
	{
		printvalue(buf, "1000000000000000000");
		write(1, " ", 1);
	}
	else if (*size == 6)
	{
		printvalue(buf, "1000000000000000");
		write(1, " ", 1);
	}
	else
		numterm3(buf, size);
}

void	numterm(char *buf, int *size)
{
	if (*size == 2)
	{
		printvalue(buf, "1000");
		write(1, " ", 1);
	}
	else if (*size == 3)
	{
		printvalue(buf, "1000000");
		write(1, " ", 1);
	}
	else if (*size == 4)
	{
		printvalue(buf, "1000000000");
		write(1, " ", 1);
	}
	else if (*size == 5)
	{
		printvalue(buf, "1000000000000");
		write(1, " ", 1);
	}
	else
		numterm2(buf, size);
}
