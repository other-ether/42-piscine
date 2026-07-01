/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 02:14:51 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 22:48:26 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putch(char c)
{
	write(1, &c, 1);
}

int	is_printable(char *str)
{
	if (*str < 32 || *str == 127)
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	const char		*hex;
	unsigned char	c;

	hex = "0123456789abcdef";
	while (*str != 0)
	{
		c = (unsigned char)*str;
		if (c >= 32 && c <= 126)
			putch(c);
		else
		{
			putch('\\');
			putch(hex[c / 16]);
			putch(hex[c % 16]);
		}
		str ++;
	}
}
