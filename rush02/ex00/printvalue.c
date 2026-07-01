/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printvalue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 06:09:36 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 21:48:24 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strings.h"

void	print_till_end(char *str)
{
	while (*str != '\n')
	{
		write(1, str, 1);
		str++;
	}
}

void	printvalue(char *dictbuf, char *val)
{
	char	*endofkey;

	endofkey = ft_strstr(dictbuf, val);
	if (endofkey == NULL)
	{
		ft_putstr("Number is not found in the dictionary");
		return ;
	}
	val = endofkey;
	while (*val == ' ')
		val ++;
	if (*val == ':')
		val ++;
	while (*val == ' ')
		val ++;
	print_till_end(val);
}
