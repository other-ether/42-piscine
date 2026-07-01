/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:26:39 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 17:15:09 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_matrix(int matrix[4][4], int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			print_char(matrix[i][j] + '0');
			if (j < cols - 1)
				print_char(' ');
			j++;
		}
		print_char('\n');
		i++;
	}
}

void	print_solution(int solution[4][4])
{
	unsigned int	x;
	unsigned int	y;
	char			c;

	x = 0;
	y = 0;
	while (y < 4)
	{
		c = solution[x][y] + '0';
		write(1, &c, 1);
		if (x == 3)
		{
			x = 0;
			y++;
			write(1, "\n", 1);
		}
		else
		{
			write(1, " ", 1);
			x++;
		}
	}
}
