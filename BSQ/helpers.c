/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:00:27 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/17 14:06:27 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi_n(const char *s, size_t n)
{
	long	res;
	int		d;
	size_t	i;

	res = 0;
	i = 0;
	while (i < n)
	{
		d = s[i] - '0';
		if (d < 0 || d > 9)
			return (-1);
		if (res > (2147483647 - d) / 10)
			return (-1);
		res = res * 10 + d;
		i++;
	}
	return ((int)res);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

/*
void	print_map(int *arr, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putnbr(arr[i * cols + j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
*/