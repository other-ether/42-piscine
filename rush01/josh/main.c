/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 18:03:06 by yichua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	validate_grid(int gmatrix[4][4], int wmatrix[4][4], int row, int col);

int	check_top(int matrix[4][4], int col, int val);

int	check_bottom(int matrix[4][4], int col, int val);

int	check_left(int matrix[4][4], int row, int val);

int	check_right(int matrix[4][4], int row, int val);

int	is_safe(int matrix[4][4], int row, int col, int num);

void	init_available_numbers(int available[4]);

void	get_missing_numbers(int matrix[4][4], int row, int choices[4]);

void	print_invalid_params_error(void);

void	test_print_values(int *values);

void	print(char *str);

void	print_char(char c);

void	print_matrix(int matrix[4][4], int rows, int cols);

void	print_solution(int solution[4][4]);

char	try_get_values(char *str, int *values_buffer)
{
	unsigned int	i;
	unsigned int	digits;

	i = 0;
	digits = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
			values_buffer[i / 2] = str[i] - '0';
			digits++;
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	if (digits == 16)
		return (1);
	else
		return (0);
}

void	popgmatrix(int *values, int gridmatrix[4][4])
{
	int	i;
	int	k;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			gridmatrix[i][k] = values[(i * 4) + k];
			k++;
		}
		i++;
	}
}

void	minmax(int gridmatrix[4][4], int writtenmatrix[4][4])
{
	int	row;
	int	col;
	int	seq;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (gridmatrix[row][col] == 4)
			{
				seq = 0;
				while (seq < 4)
				{
					if (row == 0)
						writtenmatrix[seq][col] = seq + 1;
					else if (row == 2)
						writtenmatrix[col][seq] = seq + 1;
					seq ++;
				}
				break ;
			}
			col++;
		}
		row++;
	}
}

int	solve(int gridmatrix[4][4], int writtenmatrix[4][4], int row, int col)
{
	int	i;
	int	choices[4];

	if (row == 4)
		return (1);
	if (col == 4)
		return (solve(gridmatrix, writtenmatrix, row + 1, 0));
	if (writtenmatrix[row][col] != 0)
		return (solve(gridmatrix, writtenmatrix, row, col + 1));
	init_available_numbers(choices);
	get_missing_numbers(writtenmatrix, row, choices);
	i = 0;
	while (i < 4)
	{
		if (choices[i] != 0)
		{
			if (is_safe(writtenmatrix, row, col, choices[i]))
			{
				writtenmatrix[row][col] = choices[i];
				if (validate_grid(gridmatrix, writtenmatrix, row, col))
				{
					if (solve(gridmatrix, writtenmatrix, row, col + 1))
						return (1);
				}
				writtenmatrix[row][col] = 0;
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	values[16];
	int	gridmatrix[4][4] = {0};
	int	writtenmatrix[4][4] = {0};

	if (argc != 2)
	{
		print_invalid_params_error();
		return (1);
	}
	if (try_get_values(argv[1], values) == 0)
	{
		print_invalid_params_error();
		return (1);
	}
	popgmatrix(values, gridmatrix);
	minmax(gridmatrix, writtenmatrix);
	solve(gridmatrix, writtenmatrix, 0, 0);
	print_matrix(writtenmatrix, 4, 4);
	return (0);
}
