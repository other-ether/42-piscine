/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:42:16 by yichua            #+#    #+#             */
/*   Updated: 2026/06/07 17:59:23 by yichua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_safe(int matrix[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[row][i] == num || matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	init_available_numbers(int available[4])
{
	available[0] = 1;
	available[1] = 2;
	available[2] = 3;
	available[3] = 4;
}

void	get_missing_numbers(int matrix[4][4], int row, int choices[4])
{
	int	num;
	int	col;
	int	found;

	num = 1;
	while (num <= 4)
	{
		found = 0;
		col = 0;
		while (col < 4)
		{
			if (matrix[row][col] == num)
				found = 1;
			col++;
		}
		if (!found)
			choices[num - 1] = num;
		else
			choices[num - 1] = 0;
		num++;
	}
}
