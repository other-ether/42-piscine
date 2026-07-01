/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:56:25 by yichua            #+#    #+#             */
/*   Updated: 2026/06/07 17:59:52 by yichua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_top(int matrix[4][4], int col, int val)
{
	int	row;
	int	tallest_so_far;
	int	visible_count;

	row = 0;
	tallest_so_far = 0;
	visible_count = 0;
	while (row < 4)
	{
		if (matrix[row][col] > tallest_so_far)
		{
			tallest_so_far = matrix[row][col];
			visible_count++;
		}
		row++;
	}
	return (visible_count == val);
}

int	check_bottom(int matrix[4][4], int col, int val)
{
	int	row;
	int	tallest_so_far;
	int	visible_count;

	row = 3;
	tallest_so_far = 0;
	visible_count = 0;
	while (row >= 0)
	{
		if (matrix[row][col] > tallest_so_far)
		{
			tallest_so_far = matrix[row][col];
			visible_count++;
		}
		row--;
	}
	return (visible_count == val);
}

int	check_left(int matrix[4][4], int row, int val)
{
	int	col;
	int	tallest_so_far;
	int	visible_count;

	col = 0;
	tallest_so_far = 0;
	visible_count = 0;
	while (col < 4)
	{
		if (matrix[row][col] > tallest_so_far)
		{
			tallest_so_far = matrix[row][col];
			visible_count++;
		}
		col++;
	}
	return (visible_count == val);
}

int	check_right(int matrix[4][4], int row, int val)
{
	int	col;
	int	tallest_so_far;
	int	visible_count;

	col = 3;
	tallest_so_far = 0;
	visible_count = 0;
	while (col >= 0)
	{
		if (matrix[row][col] > tallest_so_far)
		{
			tallest_so_far = matrix[row][col];
			visible_count++;
		}
		col--;
	}
	return (visible_count == val);
}

int	validate_grid(int gmatrix[4][4], int wmatrix[4][4], int row, int col)
{
	if (col == 3)
	{
		if (!check_left(wmatrix, row, gmatrix[2][row]))
		{
			return (0);
		}
		if (!check_right(wmatrix, row, gmatrix[3][row]))
		{
			return (0);
		}
	}
	if (row == 3)
	{
		if (!check_top(wmatrix, col, gmatrix[0][col]))
		{
			return (0);
		}
		if (!check_bottom(wmatrix, col, gmatrix[1][col]))
		{
			return (0);
		}
	}
	return (1);
}
